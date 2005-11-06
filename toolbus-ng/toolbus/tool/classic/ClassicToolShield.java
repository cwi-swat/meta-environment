package toolbus.tool.classic;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

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
 * Inside this ToolBus the tool is represented by two threads:
 * - ToolInputHandler that handles input coming from the external tool
 * - ClassicToolShield that manages all traffic comming from the ToolBus and routes
 *   incoming traffic (produced by ToolInputHandler) as well.
 */

/**
 * ToolInputHandler is executed as a separate thread and listens
 * for incoming terms from the tool.
 */

class ToolInputHandler extends Thread {
	ClassicToolShield toolShield;
	ToolInstance toolInstance;
	boolean running = false;
	
	ToolInputHandler(ClassicToolShield ts, ToolInstance ti){
		toolShield = ts;
		toolInstance = ti;
	}
	
	void setRunning(boolean on){
		running = on;
	}
	
	public void run(){
		int errorCount = 0;
		running = true;
		while(running){
			try {
				ATerm t = toolShield.readTerm();
				toolInstance.handleTermFromTool(t);
			} catch(IOException e){
				if(running){
					System.err.println("ToolInputHandler: " + e);
					errorCount++;
					if(errorCount > 5){
						e.printStackTrace();
						//throw new ToolBusException("no connection with tool");
						int n = 2/0;
					}	
				}
			}
		}
	}
}

public class ClassicToolShield extends ToolShield {
	private final static int LENSPEC = 12;          // ToolBus dependent parameters
	private final static int MAX_HANDSHAKE = 512;   // Do not change since they correspond with
	private final static int MIN_MSG_SIZE = 128;	// the C implementation

	private Object lockObject;
	protected ATermFactory factory;
	private boolean verbose = false;
	private InputStream inputStream;
	private OutputStream outputStream;
	private ToolInputHandler toolInputHandler;

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

		//address = ToolBus.getLocalHost();
		toolname = toolDef.getName();
		toolid = toolInstance.getToolCount();
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
	
	public void connect(InputStream in, OutputStream out) throws IOException {
		inputStream = in;
		outputStream = out;
		info("checking input signature...");
		checkToolSignature();
		ATerm term = readTerm();
		info("receive: " + term);
		if(!term.isEqual(termSndVoid)){
			throw new RuntimeException("incorrect response after signature check: " + term);
		}
		connected = true;
		getToolInstance().TCP_goConnected();
		toolInputHandler = new ToolInputHandler(this, getToolInstance());
		toolInputHandler.start();
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
		sendTerm(factory.make("rec-do(signature(<term>,<term>))", toolDef
				.getInputSignature(), toolDef.getOutputSignature()));
	}
	
	public void sndRequestToTool(Integer operation, ATerm call) {
		//System.err.println("sndRequestToTool(" + operation + ", " + call + ")");
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
	public void terminate(String msg) {
		toolInputHandler.setRunning(false);
		sndRequestToTool(ToolInstance.TERMINATE, TBTerm.factory.make("<str>", msg));
	}
	
	public void setLockObject(Object obj) {
		lockObject = obj;
	}

	public Object getLockObject() {
		return lockObject;
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
				System.out.println(term);
			}
			outputStream.write(ls);
			term.writeToTextFile(outputStream);
			if (LENSPEC + size < MIN_MSG_SIZE) {
				info("padding with " + (MIN_MSG_SIZE - (LENSPEC + size)) + " zero bytes.");
			}
			for (int i = LENSPEC + size; i < MIN_MSG_SIZE; i++) {
				outputStream.write(0);
			}
			outputStream.flush();
		}
	}
	
	public ATerm readTerm() throws IOException {
		return readTerm(inputStream, factory, getLockObject());
	}

	public static ATerm readTerm(InputStream inputStream, ATermFactory factory, Object lock) throws IOException {
		ATerm result;
		byte[] lspecBuf = new byte[LENSPEC];
		int index;

		index = 0;
		while (index != LENSPEC) {
			int bytes_read = inputStream.read(lspecBuf, index, LENSPEC - index);
			if (bytes_read <= 0) {
				throw new IOException("Tool connection terminated");
			}
			index += bytes_read;
		}

		String lspec = new String(lspecBuf);

		int bytesLeft = Integer.parseInt(lspec.substring(0, LENSPEC - 1));
		if (bytesLeft < MIN_MSG_SIZE) {
			bytesLeft = MIN_MSG_SIZE;
		}
		bytesLeft -= LENSPEC;

		byte[] data = new byte[bytesLeft];
		index = 0;
		while (index != bytesLeft) {
			int bytes_read = inputStream.read(data, index, bytesLeft - index);
			if (bytes_read <= 0) {
				throw new IOException("Tool connection terminated");
			}
			index += bytes_read;
		}

		String stringdata = new String(data);

		//info("data read (" + bytesLeft + " bytes): '" + stringdata + "'");

		result = factory.parse(stringdata);

		return result;
	}
	
	public void initRun() {
		System.err.println("ClassicToolShield.initRun for " + toolname);
		setRunning(true);
	}
}