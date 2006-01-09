package toolbus.tool.classic;

import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
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
 * Inside this ToolBus the tool is represented by one thread:
 * - ClassicToolShield that manages all traffic comming from the ToolBus and routes
 *   incoming traffic (produced by select in the ToolBus class) as well.
 */

public class ClassicToolShield extends ToolShield {
	private boolean verbose = true;
	
	private final static int LENSPEC = 12;          // ToolBus dependent parameters
	private final static int MAX_HANDSHAKE = 512;   // Do not change since they correspond with
	private final static int MIN_MSG_SIZE = 128;	   // the C implementation

	private Object lockObject;
	protected ATermFactory factory;

	private SocketChannel client;
	private static Selector selector;
	
	private ToolDefinition toolDef;
	private String toolname;

	private int toolid = -1;

	private ATerm termSndVoid;
	private boolean connected;
	
	/**
	   * The constructor for ClassicToolShield. 
	   * @param toolDef the definition of this tool
	   * @param toolInstance the tool instance that created this ClassicToolShield
	   */

	public ClassicToolShield(ToolDefinition toolDef, ToolInstance toolInstance, boolean alreadyExecuting) {
		super(toolInstance);
		this.toolDef = toolDef;
		this.factory = TBTerm.factory;
		this.lockObject = this;
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
		ATerm term = readTerm();
		info("receive: " + term);
		if(!term.isEqual(termSndVoid)){
			throw new RuntimeException("incorrect response after signature check: " + term);
		}
		connected = true;
		getToolInstance().TCP_goConnected();
		client.configureBlocking(false);
		SelectionKey clientKey = client.register(selector, SelectionKey.OP_READ);
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
	
	public void sndRequestToTool(Integer operation, ATerm call) {
		info("sndRequestToTool(" + operation + ", " + call + ")");
		addRequestToTool(new Object[] {operation, call, null});
	}
	
	/*
	 * (non-Javadoc)
	 * 
	 * @see toolbus.tool.ToolShield#handleRequestForTool()
	 */
	protected void handleRequestToTool() {
		Object request[] = getNextRequestForTool();
		Integer operation = (Integer) request[0];
		ATerm call = (ATerm) request[1];
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
	//	toolInputHandler.setRunning(false);
		sndRequestToTool(ToolInstance.TERMINATE, msg);
	}
	
	public void setLockObject(Object obj) {
		lockObject = obj;
	}

	public Object getLockObject() {
		return lockObject;
	}
	
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
			System.err.println("[CLASSIC TOOLSHIELD: " + toolname + "] " + msg);
		}
	}

	public void sendTerm(ATerm term) throws IOException {
		synchronized (getLockObject()) {
			String unparsedTerm = term.toString();
			int size = unparsedTerm.length();
			String lenspec = "000000000000" + (size + LENSPEC) + ":";
			int len = lenspec.length();
			byte[] ls = new byte[LENSPEC];

			for (int i = 0; i < LENSPEC; i++) {
				ls[i] = (byte) lenspec.charAt(len + i - LENSPEC);
			}

			if (verbose) {
				System.out.print("toolshield " + toolname + " writes term:\n");
				System.out.print(new String(ls));
				String s = term.toString();
				for(int i = 0; i < s.length() && i < 100; i++){
					if(s.charAt(i) != 0) {
						System.out.print(s.charAt(i));
					}
				}
				System.out.println("");
			}
			int n = client.write(ByteBuffer.wrap(ls));
			info(n + " bytes written for ls");
			//term.writeToTextFile(Channels.newOutputStream(client));
			n = client.write(ByteBuffer.wrap(unparsedTerm.getBytes()));
			info(n + " bytes written for term");
			if (LENSPEC + size < MIN_MSG_SIZE) {
				info("padding with " + (MIN_MSG_SIZE - (LENSPEC + size)) + " zero bytes.");
			}
			int fill = MIN_MSG_SIZE - (LENSPEC + size);
			if(fill > 0){
				byte filler[] = new byte[fill];
				for (int i = 0; i < fill; i++) {
				//	client.put((byte)0);
					filler[i] = 0;
				}
				n = client.write(ByteBuffer.wrap(filler));
	
				info(n + " bytes written for filler");
			}
			//outputStream.flush();
		}
	}

	public ATerm readTerm() throws IOException {
		ATerm result;
		ByteBuffer lspecBuf = ByteBuffer.allocate(LENSPEC);
		int index;
		
		info("readTerm from ... " + client.toString());

		index = 0;
		while (index != LENSPEC) {
			int bytes_read = client.read(lspecBuf);
			info(bytes_read + " bytes read");
			if (bytes_read <= 0) {
				throw new IOException("Tool connection terminated (1)");
			}
			index += bytes_read;
		}
		lspecBuf.flip();
		String s = "";
		while(lspecBuf.hasRemaining()){
			s = s + (char) lspecBuf.get();
		}
		info("read: <" + s + ">");
		

		String lspec = s;

		int bytesLeft = Integer.parseInt(lspec.substring(0, LENSPEC - 1));
		if (bytesLeft < MIN_MSG_SIZE) {
			bytesLeft = MIN_MSG_SIZE;
		}
		bytesLeft -= LENSPEC;

		ByteBuffer data = ByteBuffer.allocate(bytesLeft);
		index = 0;
		while (index != bytesLeft) {
			int bytes_read = client.read(data);
			if (bytes_read <= 0) {
				throw new IOException("Tool connection terminated (2)");
			}
			index += bytes_read;
		}
		
		data.flip();
		s = "";
		while(data.hasRemaining()){
			s = s + (char) data.get();
		}
		info("read: <" + s + ">");

		//String stringdata = new String(data,"UTF8");
		//System.err.println("data size = " + data.length + "; string size = " + stringdata.length());
		//
		//StringBuffer sb = new StringBuffer(data.length);				

		//for(int i = 0; i < data.length; i++){
		//	sb.append((char)data[i]);
		//}
		String stringdata = s ; //new String(data,0);
		
		//System.out.print("data read (" + bytesLeft + " bytes) ");
		//for(int i = 0; i < 100 & i < data.length; i++){
		//	if(data[i] != 0)
		//		System.out.print(stringdata.charAt(i));
		//	else
		//		System.out.print("Z");
		//	}
		//System.out.println("");
		
		result = factory.parse(stringdata);

		return result;
	}
	
	public void initRun() {
		System.err.println("ClassicToolShield.initRun for " + toolname);
		setRunning(true);
	}
}