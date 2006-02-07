package toolbus.tool.classic;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;

import toolbus.ToolBus;
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
	private final boolean verbose = false;

	private final static int LENSPEC = 12; // ToolBus dependent parameters

	private final static int MAX_HANDSHAKE = 512; // Do not change since they correspond with

	private final static int MIN_MSG_SIZE = 128; // the C implementation

	private SocketChannel client;

	private Selector selector;

	private SelectionKey clientKey;

	private ToolDefinition toolDef;

	private String toolname;

	private int toolid = -1;

	private ATerm termSndVoid;
	
	private final int uninitialized = -1;
	private final int sendingSignature = 0;
	private final int receivingSignatureConfirm = 1;
	private final int connected = 2;
	
	private int toolStatus = uninitialized;

	/**
	 * The constructor for ClassicToolShield. 
	 * @param toolDef the definition of this tool
	 * @param toolInstance the tool instance that created this ClassicToolShield
	 */

	public ClassicToolShield(ToolDefinition toolDef, ToolInstance toolInstance) {
		super(toolInstance);
		this.toolDef = toolDef;
		termSndVoid = tbfactory.parse("snd-void");

		toolname = toolDef.getName();
		toolid = toolInstance.getToolCount();
		for (int i = 0; i < MIN_MSG_SIZE; i++) {
			sendTermFiller.put((byte) 0);
		}
		selector = ToolBus.getSelector();
	}

	public void executeTool() {
		String cmd = toolDef.getCommand() + " -TB_HOST "
				+ ToolBus.getLocalHost().getHostName() + " -TB_TOOL_NAME "
				+ toolname + " -TB_TOOL_ID " + toolid + " -TB_PORT "
				+ ToolBus.getWellKnownSocketPort();
		System.err.println("executeTool:" + cmd);

		try {
			Runtime.getRuntime().exec(cmd);
		} catch (IOException e) {
			System.err.println("executeTool " + toolname + ": " + e);
		}
	}

	public void connect(Object connection) throws IOException {
		if(connection instanceof SocketChannel){
			SocketChannel client = (SocketChannel) connection;
			this.client = client;
			client.configureBlocking(false);
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
		getToolInstance().TCP_goConnected();
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

	protected void sndRequestToTool(Integer operation, ATerm call) {
		AFun fun = tbfactory.makeAFun(
				ToolInstance.OperatorForTool[operation.intValue()], 1, false);
		ATermAppl req = tbfactory.makeAppl(fun, call);
		//System.err.println("handleRequestToTool: " + req);
		try {
			sendTerm(req);
		} catch (IOException e) {
			System.err.println("handleRequestToTool: " + e);
			e.printStackTrace();
		}
	}

	/* (non-Javadoc)
	 * @see toolbus.tool.ToolShield#terminate(java.lang.String)
	 */
	public void terminate(ATerm msg) {
		sndRequestToTool(ToolInstance.TERMINATE, msg);
		clientKey.cancel();
		try {
			client.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
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
			for (int i = 0; i < s.length() && i < 100; i++) {
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
			ToolBus.settoolActionCompleted();
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
				info(bytes_read + " bytes read");
				if (bytes_read == -1) {
					return null;
					//throw new IOException("Tool connection terminated (1)");
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
		info("bytes_read = " + bytes_read);
		if (bytes_read == -1) {
			throw new IOException("Tool connection terminated (2)");
		}
		receiveTermIndex += bytes_read;

		if (receiveTermIndex != receiveTermBytesLeft) {
			return null;
		}
		receiveTermData.flip();
		ATerm result = tbfactory.readFromByteBuffer(receiveTermData);
		receiveTermBytesLeft = 0;
		ToolBus.settoolActionCompleted();
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