package toolbus.tool.classic;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;

import toolbus.ToolBus;
import toolbus.exceptions.ToolBusError;
import toolbus.exceptions.ToolBusException;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.ToolShield;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;

/**
 * A classic ToolBus tool is executed as a separate (external) Unix process and connected via
 * sockets to this ToolBus. The initial connection protocol and initial handshaking are identical
 * to those of the classic ToolBus.
 * 
 * ClassicToolShield manages all traffic comming from the ToolBus and routes
 * incoming traffic (produced by select in the ToolBus class) as well.
 */

public class ClassicToolShield extends ToolShield {
	
	private final boolean verbose = true;

	private final static int LENSPEC = 12; // ToolBus dependent parameters

	private final static int MAX_HANDSHAKE = 512; // Do not change since they correspond with

	private final static int MIN_MSG_SIZE = 128; // the C implementation

	private SocketChannel client;

	private Selector selector;

	private SelectionKey clientKey;
	
	private Process runningProcess;

	private ToolDefinition toolDef;

	private String toolname;

	private int toolCount = -1;
	private ATerm toolId;
	private ToolBus toolbus;

	private ATerm termSndVoid;
	
	private final int uninitialized = -1;
	private final int executed = 0;
	private final int sendingSignature = 1;
	private final int receivingSignatureConfirm = 2;
	private final int connected = 3;
	private final int terminated = 4;
	
	private int toolStatus = uninitialized;

	/**
	 * The constructor for ClassicToolShield. 
	 * @param toolDef the definition of this tool
	 * @param toolInstance the tool instance that created this ClassicToolShield
	 */

	public ClassicToolShield(ToolDefinition toolDef, ToolInstance toolInstance) {
		super(toolInstance);
		this.toolDef = toolDef;
		this.toolbus = toolInstance.getToolBus();
		termSndVoid = tbfactory.parse("snd-void");

		toolname = toolDef.getName();
		toolCount = toolInstance.getToolCount();
		toolId = toolInstance.getToolId();
		for (int i = 0; i < MIN_MSG_SIZE; i++) {
			sendTermFiller.put((byte) 0);
		}
		selector = toolbus.getSelector();
	}

	public void executeTool() throws ToolBusException {
		String cmd = toolDef.getCommand() + " -TB_HOST "
				+ toolbus.getLocalHost().getHostName() + " -TB_TOOL_NAME "
				+ toolname + " -TB_TOOL_ID " + toolCount + " -TB_PORT "
				+ toolbus.getWellKnownSocketPort();
		System.err.println("executeTool: " + cmd);

		try {
			ProcessBuilder PB = new ProcessBuilder(cmd.split(" "));
			PB.redirectErrorStream(true);
			
			runningProcess = PB.start();
			new StreamGobbler(runningProcess.getInputStream(), "[" + toolname + "]").start();
			//Runtime.getRuntime().exec(cmd);
		} catch (IOException e) {
			throw new ToolBusError(("while starting tool " + toolname + ": " + e.getMessage()));
		}
		toolStatus = executed;
	}

	public void connect(Object connection) throws IOException {
		if(connection instanceof SocketChannel){
			SocketChannel client = (SocketChannel) connection;
			this.client = client;
			client.configureBlocking(false);
			client.socket().setTcpNoDelay(true);
			clientKey = client.register(selector, SelectionKey.OP_READ | SelectionKey.OP_WRITE, this);
	
			info("checking input signature...");
			toolStatus = sendingSignature;
			checkToolSignature();
		} else {
			throw new IOException("connection should be a SocketChannel");
		}
	}
	
	void connectAfterSignatureConfirmation(ATerm term){
		info("connect2, receive: " + term);
		if (!term.isEqual(termSndVoid)) {
			throw new RuntimeException(
					"incorrect response after signature check: " + term);
		}
		toolStatus = connected;
		toolInstance.handleTermFromTool(tbfactory.make("snd-connect(<term>)", toolId));
	}

	public boolean isConnected() {
		return toolStatus == connected;
	}

	public void disconnect() {
		try {
			sendTerm(tbfactory.parse("rec-disconnect"));
			toolStatus = connected;
			getToolInstance().TCP_goDisConnected();
		} catch (IOException e) {
			e.printStackTrace();
			throw new RuntimeException("cannot disconnect: " + e.getMessage());
		}
	}

	public void checkToolSignature() throws IOException {
		info("checkToolSignature: input: " + toolDef.getInputSignature());
		info("checkToolSignature: output: " + toolDef.getOutputSignature());
		sendTerm(tbfactory.make("rec-do(<term>)", toolDef.getSignature()));
	}

	protected void sndRequestToTool(int operation, ATerm call) {
		AFun fun = tbfactory.makeAFun(
				ToolInstance.OperatorForTool[operation], 1, false);
		ATermAppl req = tbfactory.makeAppl(fun, call);
		//System.err.println("sndRequestToTool: " + req);
		try {
			sendTerm(req);
		} catch (IOException e) {
			System.err.println("handleRequestToTool: " + e);
			e.printStackTrace();
		}
	}

	
	/* (non-Javadoc)
	 * @see toolbus.tool.ToolShield#terminate(aterm.ATerm)
	 */
	public void terminate(ATerm msg) {
		if(toolStatus == connected && toolStatus != terminated){
			toolStatus = terminated;
			System.err.println(toolId + ": terminate(" + msg + ")");
			sndRequestToTool(ToolInstance.TERMINATE, msg);
			clientKey.cancel();
			try {
				client.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public String getToolName() {
		return toolname;
	}

	void info(String msg) {
		if (verbose) {
			System.err.println("[CLASSIC TOOLSHIELD: " + toolname + "] "
					+ msg.substring(0, Math.min(msg.length(), 100)));
		}
	}
	
	private int sendTermFill = 0;

	private ByteBuffer sendTermData;

	private ByteBuffer sendTermLengthSpec = ByteBuffer.allocate(LENSPEC);

	private ByteBuffer sendTermFiller = ByteBuffer.allocate(MIN_MSG_SIZE);

	private ByteArrayOutputStream sendByteArrayOutputStream = new ByteArrayOutputStream();

	private boolean sendTermInProgress = false;
	
	public void sendTerm(ATerm term) throws IOException {
		sendByteArrayOutputStream.reset();
		byte termAsBytes[] = term.toByteArray(sendByteArrayOutputStream);
		int sendTermBytesLeft = termAsBytes.length;

		String lenspec = "000000000000" + (sendTermBytesLeft + LENSPEC) + ":";
		int len = lenspec.length();

		sendTermLengthSpec.clear();

		for (int i = 0; i < LENSPEC; i++) {
			sendTermLengthSpec.put((byte) lenspec.charAt(len + i - LENSPEC));
		}

		if (verbose) {
			System.out.print("toolshield " + toolname + " writes term:\n");
			//System.out.print(new String(ls));
			String s = term.toString();
			for (int i = 0; i < s.length() && i < 150; i++) {
				if (s.charAt(i) != 0) {
					System.out.print(s.charAt(i));
				}
			}
			System.out.println("");
		}
		sendTermLengthSpec.flip();
		int n = 0;
		while (sendTermLengthSpec.hasRemaining()) {  //TODO wachtloop!
			n += client.write(sendTermLengthSpec);
		}
		info(n + " bytes written for sendTermLenghSpec");

		sendTermFill = MIN_MSG_SIZE - (LENSPEC + sendTermBytesLeft);

		if (sendTermData == null || sendTermData.capacity() < sendTermBytesLeft) {
			sendTermData = ByteBuffer.allocate(sendTermBytesLeft);
		} else {
			sendTermData.clear();
		}
		sendTermData.put(termAsBytes);
		sendTermData.flip();

		if (clientKey != null) {
			clientKey.interestOps(SelectionKey.OP_READ | SelectionKey.OP_WRITE);
		}

		sendTermInProgress = true;
		n = client.write(sendTermData);
		info(n + " bytes written for unparsedTerm");
		sendTerm();
	}

	public void sendTerm() throws IOException {
		if (sendTermInProgress) {
			if (sendTermData.hasRemaining()) {
				int n = client.write(sendTermData);
				info(n + " bytes written for unparsedTerm");
				return;
			}

			if (sendTermFill > 0) {
				info("padding with " + sendTermFill + " zero bytes.");

				sendTermFiller.position(0);
				sendTermFiller.limit(sendTermFill);
				while (sendTermFiller.hasRemaining()) { //TODO wachtloop!
					int n = client.write(sendTermFiller);
					info(n + " bytes written for filler");
				}
			}
			toolbus.settoolActionCompleted();
			if (clientKey != null) {
				clientKey.interestOps(SelectionKey.OP_READ);
			}
			sendTermInProgress = false;
			if(toolStatus == sendingSignature){
				toolStatus = receivingSignatureConfirm;
			}
		} else
			System.err.println("sendTerm: no data");
	}
	
	private int receiveTermBytesLeft = 0;

	private int receiveTermIndex = 0;

	private ByteBuffer receiveTermData;

	private ByteBuffer receiveTermLengthSpec = ByteBuffer.allocate(LENSPEC);
	
	public ATerm receiveTerm() throws IOException {
		if (receiveTermBytesLeft == 0) { // Start reading a new term
			info("readTerm from ... " + client.toString());
			receiveTermLengthSpec.clear();
			int index = 0;

			while (index != LENSPEC) {
				int bytes_read = client.read(receiveTermLengthSpec);  //TODO: hier zit ook een wachtloop!
				info(bytes_read + " bytes read (lenspec)");
				if (bytes_read == -1) {
					//return null
					throw new IOException("Tool connection terminated (1)");
				}
				index += bytes_read;
			}
			receiveTermLengthSpec.flip();

			receiveTermBytesLeft = 0;
			while (receiveTermLengthSpec.hasRemaining()) {
				int c = receiveTermLengthSpec.get();
				if(c != ':'){
					receiveTermBytesLeft = receiveTermBytesLeft * 10 + (c - '0');
				}
			}
			
			if (receiveTermBytesLeft < MIN_MSG_SIZE) {
				receiveTermBytesLeft = MIN_MSG_SIZE;
			}
			receiveTermBytesLeft -= LENSPEC;

			if (receiveTermData == null
					|| receiveTermData.capacity() < receiveTermBytesLeft) {
				receiveTermData = ByteBuffer.allocate(receiveTermBytesLeft);
			} else {
				receiveTermData.clear();
			}
			receiveTermIndex = 0;
		}
		int bytes_read = client.read(receiveTermData);
		info("bytes_read (data) = " + bytes_read);
		if (bytes_read == -1) {
			throw new IOException("Tool connection terminated (2)");
		}
		receiveTermIndex += bytes_read;

		if (receiveTermIndex != receiveTermBytesLeft) {
			return null;
		}
		receiveTermData.flip();
		ATerm result = tbfactory.readFromByteBuffer(receiveTermData);
		info("receiveTerm: result = " + result);
		receiveTermBytesLeft = 0;
		toolbus.settoolActionCompleted();
		if(isConnected()){
			return result;
		} else if(toolStatus == receivingSignatureConfirm){
		   	connectAfterSignatureConfirmation(result);
			return null;
		} else {
			System.err.println("receiveTerm: illegal toolStatus");
			return null;
		}
	}
}

class StreamGobbler extends Thread
{
    InputStream is;
    String type;
    
    StreamGobbler(InputStream is, String type)
    {
        this.is = is;
        this.type = type;
    }
    
    public void run()
    {
        try
        {
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr);
            String line=null;
            while ( (line = br.readLine()) != null)
                System.out.println(type + ">>> " + line);    
            } catch (IOException ioe)
              {
                ioe.printStackTrace();  
              }
    }
}

