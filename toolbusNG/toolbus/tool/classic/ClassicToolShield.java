package toolbus.tool.classic;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;

import toolbus.TBTerm;
import toolbus.ToolBus;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.ToolShield;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;

/**
 * A classic ToolBus tool is executed as a separate (external) Unix process and connected via
 * sockets to this ToolBus. The initial connection protocol and initial handshaking are identical
 * to those of the classic ToolBus.
 * 
 * ClassicToolShield manages all traffic comming from the ToolBus and routes
 * incoming traffic (produced by select in the ToolBus class) as well.
 */

public class ClassicToolShield extends ToolShield {
	private boolean verbose = false;
	
	private final static int LENSPEC = 12;          // ToolBus dependent parameters
	private final static int MAX_HANDSHAKE = 512;   // Do not change since they correspond with
	private final static int MIN_MSG_SIZE = 128;	   // the C implementation

//	private Object lockObject;
	protected ATermFactory factory;

	private SocketChannel client;
	private static Selector selector;
	
	private ToolDefinition toolDef;
	private String toolname;

	private int toolid = -1;

	private ATerm termSndVoid;
	private boolean connected;
	
	private int receiveTermBytesLeft = 0;
	private int receiveTermIndex = 0;
	private ByteBuffer receiveTermData;
	private ByteBuffer receiveTermLengthSpec = ByteBuffer.allocate(LENSPEC);
	
	private int sendTermFill = 0;
	private ByteBuffer sendTermData;
	private ByteBuffer sendTermLengthSpec = ByteBuffer.allocate(LENSPEC);
	
	/**
	   * The constructor for ClassicToolShield. 
	   * @param toolDef the definition of this tool
	   * @param toolInstance the tool instance that created this ClassicToolShield
	   */

	public ClassicToolShield(ToolDefinition toolDef, ToolInstance toolInstance, boolean alreadyExecuting) {
		super(toolInstance);
		this.toolDef = toolDef;
		this.factory = TBTerm.factory;
//		this.lockObject = this;
		termSndVoid = factory.parse("snd-void");

		toolname = toolDef.getName();
		toolid = toolInstance.getToolCount();
		selector = ToolBus.getSelector();
		if(!alreadyExecuting){
			executeTool();
		}
	}
		
	void executeTool(){
		String cmd = toolDef.getCommand() + 
					" -TB_HOST "      + ToolBus.getLocalHost().getHostName() +
					" -TB_TOOL_NAME " + toolname +
					" -TB_TOOL_ID "   + toolid +
					" -TB_PORT "      + ToolBus.getWellKnownSocketPort()
					;
		System.err.println("executeTool:" + cmd);
			
		try {
			Runtime.getRuntime().exec(cmd);
		} catch (IOException e) {
			System.err.println(e);
		}
	}
	
	public void connect(SocketChannel client) throws IOException {
		this.client = client;
		info("checking input signature...");
		checkToolSignature();
		ATerm term = receiveTerm();
		info("receive: " + term);
		if(!term.isEqual(termSndVoid)){
			throw new RuntimeException("incorrect response after signature check: " + term);
		}
		connected = true;
		getToolInstance().TCP_goConnected();
		client.configureBlocking(false);
		SelectionKey clientKey = client.register(selector, SelectionKey.OP_READ | SelectionKey.OP_WRITE);
		clientKey.attach(this);
	}
	
	public synchronized boolean isConnected() {
		return connected;
	}

	public void disconnect() {
		try {
			sendTerm(factory.parse("rec-disconnect"));
			connected = false;
			getToolInstance().TCP_goDisConnected();
		}
		catch (IOException e) {
			throw new RuntimeException("cannot disconnect: " + e.getMessage());
		}
	}
	
	public void checkToolSignature() throws IOException {
		info("checkToolSignature: input: " + toolDef.getInputSignature());
		info("checkToolSignature: output: " + toolDef.getOutputSignature());
		sendTerm(factory.make("rec-do(signature(<term>,<term>))", toolDef
				.getInputSignature(), toolDef.getOutputSignature()));
	}
	
	protected void handleRequestToTool(Integer operation, ATerm call) {
		AFun fun = TBTerm.factory.makeAFun(ToolInstance.OperatorForTool[operation.intValue()], 1, false);
		ATermAppl req = TBTerm.factory.makeAppl(fun, call);
		try {
			sendTerm(req);
		} catch (IOException e) {
			System.err.println(e);
		}
	}
	
	/* (non-Javadoc)
	 * @see toolbus.tool.ToolShield#terminate(java.lang.String)
	 */
	public void terminate(ATerm msg) {
		handleRequestToTool(ToolInstance.TERMINATE, msg);
	}

/*	public void setLockObject(Object obj) {
		lockObject = obj;
	}

	public Object getLockObject() {
		return lockObject;
	}*/
	
	public String getToolName(){
		return toolname;
	}
	
	public void setVerbose(boolean on) {
		verbose = on;
	}

	public boolean getVerbose() {
		return verbose;
	}

	void info(String msg) {
		if (verbose) {
			System.err.println("[CLASSIC TOOLSHIELD: " + toolname + "] " + msg.substring(0,Math.min(msg.length(),100)));
		}
	}

	public synchronized void sendTerm(ATerm term) throws IOException {
		//synchronized (getLockObject()) {
			byte termAsBytes[] = term.toByteArray();
			int size = termAsBytes.length;
			
			String lenspec = "000000000000" + (size + LENSPEC) + ":";
			int len = lenspec.length();
			//byte[] ls = new byte[LENSPEC];
			
			sendTermLengthSpec.clear();

			for (int i = 0; i < LENSPEC; i++) {
				sendTermLengthSpec.put((byte)lenspec.charAt(len + i - LENSPEC));
			}

			if (verbose) {
				System.out.print("toolshield " + toolname + " writes term:\n");
				//System.out.print(new String(ls));
				String s = term.toString();
				for(int i = 0; i < s.length() && i < 100; i++){
					if(s.charAt(i) != 0) {
						System.out.print(s.charAt(i));
					}
				}
				System.out.println("");
			}
			sendTermLengthSpec.flip();
			//int n = client.write(ByteBuffer.wrap(ls));
			int n = 0;
			while(sendTermLengthSpec.hasRemaining()){
				n += client.write(sendTermLengthSpec);
			}
			info(n + " bytes written for sendTermLenghSpec");
			
			sendTermData = ByteBuffer.wrap(termAsBytes);
			sendTermFill = MIN_MSG_SIZE - (LENSPEC + size);
			
			n = client.write(sendTermData);
			info(n + " bytes written for unparsedTerm");
			sendTerm();
		//}
	}
	
	public synchronized void sendTerm() throws IOException {
		if(sendTermData != null){
			if(sendTermData.hasRemaining()){
				int n = client.write(sendTermData);
				info(n + " bytes written for unparsedTerm");
				return;
			}
	
			if(sendTermFill > 0){
				info("padding with " + sendTermFill + " zero bytes.");
				byte filler[] = new byte[sendTermFill];
				for (int i = 0; i < sendTermFill; i++) {
					filler[i] = 0;
				}
				ByteBuffer bfiller = ByteBuffer.wrap(filler);
				while(bfiller.hasRemaining()){
					int n = client.write(bfiller);
					info(n + " bytes written for filler");
				}
			}
			sendTermData = null;
		}
	}

	public synchronized ATerm receiveTerm() throws IOException {
		if(receiveTermBytesLeft == 0){  // Start reading a new term
			info("readTerm from ... " + client.toString());
			receiveTermLengthSpec.clear();
			int index = 0;
			
			while (index != LENSPEC) {
				int bytes_read = client.read(receiveTermLengthSpec);
				info(bytes_read + " bytes read");
				if (bytes_read == -1) {
					throw new IOException("Tool connection terminated (1)");
				}
				index += bytes_read;
			}
			receiveTermLengthSpec.flip();
			
			info("limit = " + receiveTermLengthSpec.limit());
			StringBuffer lspec = new StringBuffer(LENSPEC);
			while(receiveTermLengthSpec.hasRemaining()){
				lspec.append((char) receiveTermLengthSpec.get());
			}
	
			receiveTermBytesLeft = Integer.parseInt(lspec.substring(0, LENSPEC - 1));
			if (receiveTermBytesLeft < MIN_MSG_SIZE) {
				receiveTermBytesLeft = MIN_MSG_SIZE;
			}
			receiveTermBytesLeft -= LENSPEC;
	
			if(receiveTermData == null || receiveTermData.capacity() < receiveTermBytesLeft){
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
		
		if(receiveTermIndex != receiveTermBytesLeft){
			return null;
		}
		receiveTermData.flip();
		ATerm result = factory.readFromByteBuffer(receiveTermData);
		receiveTermBytesLeft = 0;
		return result;
	}
}