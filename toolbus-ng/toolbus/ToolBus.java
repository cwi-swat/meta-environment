 /**
 * @author paulk
 */

package toolbus;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Properties;
import java.util.Random;
import java.util.Set;
import java.util.Vector;

import toolbus.parser.ExternalParser;
import toolbus.parser.TScriptParser;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessDefinition;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.classic.ClassicToolShield;
import toolbus.tool.classic.ToolConnector;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermInt;
import aterm.ATermList;

/**
 * ToolBus implements the behaviour of one ToolBus.
 */

public class ToolBus {
	
  private static boolean verbose = true;

  private static Random rand = new Random();
  private ATermFactory factory;
  private Vector processes; // process instances
  private Vector tools;     // tool instances
  private Vector procdefs;
  private Vector tooldefs;
  private HashSet atomSignature; 	// signature of all atoms in executing processes
  									// TODO: should this not be for ALL defined processes? 
  private TScriptParser parser;
  private PrintWriter out;

  private static String sglr = "/ufs/paulk/software/installed/bin/sglr";
  private static String parseTable = "/ufs/paulk/workspace/toolbusNG/toolbus/parser/Tscript.trm.tbl";
  private static String implodePT = "/ufs/paulk/software/installed/bin/implodePT";
  private static String workspace = "/ufs/paulk/eclipse/worlspace";
 
  private static int nerrrors = 0;
  private static int nwarnings = 0;
  
  private static int WellKnownSocketPort = 8999;
  private ServerSocketChannel WellKnownSocketChannel;
  private ServerSocket WellKnownSocket;
  private static InetAddress localHost;
  private static Selector selector;
  
  private final static int MAX_HANDSHAKE = 512;   // Do not change since they correspond with
  private final static int MIN_MSG_SIZE = 128;	// the C implementation
  private ToolBus toolbus;
  private String toolname;
 
  private int toolid = -1;
  private Vector connectedTools;
  private SocketChannel client;
  private ByteBuffer handshake ;
  
  private long startTime;
  private long currentTime;
  private long nextTime = 0;
  
  private boolean shutdownDone = false;

  /**
   * Constructor with explicit PrintWriter
   */

  public ToolBus(PrintWriter out) {
    TBTerm.init();
    factory = TBTerm.factory;
    this.out = out;
    processes = new Vector();
    tools = new Vector();
    connectedTools = new Vector();
    procdefs = new Vector();
    tooldefs = new Vector();
    atomSignature = new HashSet();
    try {
      loadProperties();
    } catch (IOException e) {
      System.err.println(e.getMessage());
    }
    parser = new TScriptParser(new ExternalParser(sglr, parseTable, implodePT));
    
    try {
    	localHost = InetAddress.getLocalHost();
    	info("Creating WellKnownSocket: " + WellKnownSocketPort + " " + localHost);
    	WellKnownSocketChannel = ServerSocketChannel.open();
    	//WellKnownSocket = new ServerSocket(WellKnownSocketPort, 1, localHost);
    	WellKnownSocket = WellKnownSocketChannel.socket();
    	WellKnownSocket.bind(new InetSocketAddress(WellKnownSocketPort));
    	WellKnownSocketChannel.configureBlocking(false);
    	selector = Selector.open();
    	WellKnownSocketChannel.register(selector, SelectionKey.OP_ACCEPT);
	    handshake = ByteBuffer.allocate(MAX_HANDSHAKE);

    } catch(IOException e){
    	e.printStackTrace();
    }
  
    info("WellKnownSocket created: " + WellKnownSocket);
    startTime = System.currentTimeMillis();
 
  }

  /**
   * Constructor with implicit PrintWriter
   */

  public ToolBus() {
    this(new PrintWriter(System.out));
  }

  /**
   * Constructor with explicit StringWriter
   */

  public ToolBus(StringWriter out) {
    this(new PrintWriter(out));
  }
  
  void info(String msg) {
	if (verbose) {
		System.err.println("[TOOLBUS] " + msg);
	}
}
  
  private void handleInputFromTools(long timeout){
  	try {
  		selector.select(timeout);
  	} catch(IOException e){
    	e.printStackTrace();
    }
  	Set readyKeys = selector.selectedKeys();
  	Iterator iterator = readyKeys.iterator();
  	while(iterator.hasNext()){
  		SelectionKey key = (SelectionKey) iterator.next();
  		iterator.remove();
  		//info("key " + key);
  		
  		try{	
	  		if(key.isAcceptable()){
	  			//info("case acceptable");
	  			ServerSocketChannel server = (ServerSocketChannel) key.channel();
	  			client = server.accept();
	  			client.configureBlocking(true);
	  			shakeHands();
	  			
	  		} else if(key.isReadable()){
	  			//info("case readable");
	  			client = (SocketChannel) key.channel();
	  			ClassicToolShield ts = (ClassicToolShield) key.attachment();
	  			ATerm term = ts.readTerm();
	  			ts.getToolInstance().handleTermFromTool(term);
	  		} else {
	  			System.err.println("NO INPUT POSSIBLE in handleInputFromTools");
	  		}
  		} catch (IOException e){
  			key.cancel();
  			try {
  				key.channel().close();
  			} catch (IOException ce) {}
  		}
  		
  	}
  }
  
	private void shakeHands() throws IOException {
		//	String host = address.getHostName();
		//	info("host = " + host);
		//	if (host == null) {
		//		String pair = address.toString();
		//		host = pair.substring(0, pair.indexOf('/'));
		//		info("local host = " + host);
		//	}
			
			//byte[] handshake = new byte[MAX_HANDSHAKE];
		    //ByteBuffer handshake = ByteBuffer.allocate(MAX_HANDSHAKE);
		
			handshake.clear();
			int nr = client.read(handshake);
			
			info(nr + " bytes read from client");
			handshake.flip();
			String s = "";
			while(handshake.hasRemaining()){
				s = s + (char) handshake.get();
			}
			info("read: <" + s + ">");
			
			String toolHand = s.toLowerCase().trim();
			info("input: <" + toolHand + ">");
			String elems[] = toolHand.split(" ");

			toolname = elems[0];
			info("toolname = " + toolname);
			String host = elems[1];
			info("host = " + host);
			
			info("elems[2] = " + elems[2]);
			
			int lastd = -1;
			for(int i = 0; i < elems[2].length(); i++){
				if((i == 0) && (elems[2].charAt(0) == '-')){
					lastd = i;
				} else if(!Character.isDigit(elems[2].charAt(i))){
					break;
				}
				lastd = i;
			}
			toolid = Integer.parseInt(elems[2].substring(0,lastd+1));
			info("toolid = " + toolid);
			
			if(toolid >= 0){
				writeInt(toolid);
				ToolInstance ti = getToolInstance(toolid);
				ti.connect(client);
			} else {
				try {
					ToolInstance ti = toolbus.addToolInstance(toolname, true);
					toolid = ti.getToolCount();
					writeInt(toolid);
					info("shakeHands: created ti");
					connectedTools.add(ti);
					info("shakeHands: added to list");
					//for(int i = 0; i < connectedTools.size(); i++){
					//	ToolInstance ti1 = (ToolInstance) connectedTools.elementAt(i);
					//	info("shakeHands: considering: " + ti1.getToolName());
					//}
					
					ti.connect(client);
				} catch (Exception e) {
					// TODO: handle exception
				}
			}
		}
		
		public ToolInstance getConnectedTool(String toolname){
			//info("getConnectedTool: " + toolname);
			for(int i = 0; i < connectedTools.size(); i++){
				ToolInstance ti = (ToolInstance) connectedTools.elementAt(i);
				//info("getConnectedTool: considering: " + ti.getToolName());
				if(ti.getToolName().equals(toolname)){
					connectedTools.removeElementAt(i);
					//info("getConnectedTool: " + toolname + " ==> " + ti);
					return ti;
				}
			}
			//info("getConnectedTool: " + toolname + " ==> null");
			return null;
		}
		
		private void writeInt(int n) throws IOException {
			//byte[] buffer = new byte[MAX_HANDSHAKE];
			handshake.clear();
			String s = toolname + " " + Integer.toString(n);

			byte bs[] = s.getBytes();
			info("writeInt: " + s + "; length = " + bs.length);
			for (int i = 0; i < MAX_HANDSHAKE; i++) {
				if(i < bs.length){
					handshake.put(bs[i]);
				} else {
					handshake.put((byte)0);
				}
			}
			handshake.flip();
			int k = client.write(handshake);
			info("writeInt(" + n + ") writes " + k + "  bytes");
		}
  
  /**
   * 
   * Networking functions
   */

  private static String getHostName() {
    String hostname = "";
    try {
      hostname = java.net.InetAddress.getLocalHost().getHostName();
      int dotPosition = hostname.indexOf('.');
      if (dotPosition != -1) {
        hostname = hostname.substring(0, dotPosition);
      }
    } catch (java.net.UnknownHostException e) {
      // ignore, unable to resolve hostname
    }
    return hostname;
  }
  
  public ServerSocket getWellKnownSocket(){
  	return this.WellKnownSocket;
  }
  
  public static int  getWellKnownSocketPort(){
  	return WellKnownSocketPort;
  }
  
  public static InetAddress getLocalHost(){
  	return localHost;
  }
  
  public static Selector getSelector(){
	  return selector;
  }

  /**
   * Get the name of the property file to be used
   */

  private static String getPropertyFile() {
    String stdName = "toolbus.props";
    String user = System.getProperty("user.name");
    
    String hostname = getHostName();

    File f;
    String fname;
    fname = user + "@" + hostname + "-" + stdName;
    f = new File(fname);
    if (f.exists()) {
      return fname;
    }

    fname = user + "-" + stdName;
    f = new File(fname);
    if (f.exists()) {
      return fname;
    }
    fname = stdName;
    f = new File(fname);
    if (f.exists()) {
      return fname;
    }
    return null;
  }

  /**
   * Load properties from property file; use defaults if absent
   */

  private static void loadProperties() throws IOException {
    Properties props = new Properties();
    String pname = getPropertyFile();
    if (pname != null) {
      props.load(ClassLoader.getSystemResourceAsStream(pname));
      sglr = props.getProperty("sglr.path", sglr);
      parseTable = props.getProperty("parsetable.path", parseTable);
      implodePT = props.getProperty("implodePT.path", implodePT);
      workspace = props.getProperty("workspace.path", workspace);
    }
  }

  /**
   * Get the ATermFactory used.
   */

  public ATermFactory getFactory() {
    return factory;
  }

  /**
   *  Get the current vector of processes.
   */

  public Vector getProcesses() {
    return processes;
  }

  /**
   * Set verbose mode.
   */

  public static void setVerbose(boolean b) {
    verbose = b;
  }

  /**
   * Get verbose mode
   */

  public static boolean isVerbose() {
    return verbose;
  }
  
  /**
   * Get workspace
   */
  
  public static String getWorkspace(){
  	return workspace;
  }

  /**
   * Get current PrintWriter.
   */

  public PrintWriter getPrintWriter() {
  	return out;
  }
  
  public static void error(String src, String msg) {
  	System.err.println("ToolBus (" + src + "): " + msg);
  	nerrrors++;
  }
  
  public static void warning(String src, String msg) {
  	System.err.println("ToolBus (" + src + "): " + msg + " (warning)");
  	nwarnings++;
  }

  /**
   * Generate next random integer.
   */

  public static int nextInt(int n) {
    return rand.nextInt(n);
  }

  /**
   * Generate next random boolean.
   */

  public static boolean nextBoolean() {
    return rand.nextBoolean();
  }
  
  public long getRunTime(){
  	return System.currentTimeMillis() - startTime;
  }
  
  public void setNextTime(long next){
  	System.err.println("setNextTime: " + next);
  	if(nextTime <= currentTime){
  		nextTime = next;
  	} else if(next < nextTime){
  		nextTime = next;
  	}
 	System.err.println("setNextTime: set to " + next);
  }

  /**
   * Parse a Tscript from file and add definitions to this ToolBus.
   */

  public void parse(String filename) throws ToolBusException {
    parser.parse(this, filename);
  }

  /**
   * Add a process definition.
   */

  public void addProcessDefinition(ProcessDefinition PD) throws ToolBusException {
    String name = PD.getName();
    for (int i = 0; i < procdefs.size(); i++) {
      ProcessDefinition PD2 = (ProcessDefinition) procdefs.elementAt(i);
      if (name == PD2.getName())
        throw new ToolBusException("duplicate definition of process " + name);
    }
    procdefs.add(PD);
  }
  
  /**
   * Add a tool definition.
   */

  public void addToolDefinition(ToolDefinition TD) throws ToolBusException {
    String name = TD.getName();
    for (int i = 0; i < tooldefs.size(); i++) {
      ToolDefinition TD2 = (ToolDefinition) tooldefs.elementAt(i);
      if (name == TD2.getName())
        throw new ToolBusException("duplicate definition of tool " + name);
    }
    tooldefs.add(TD);
  }

  /**
   * Add a process (with actuals).
   */

  public ProcessInstance addProcess(String name, ATermList actuals) throws ToolBusException {
    ProcessInstance P = new ProcessInstance(this, name, actuals);
    processes.add(P);
    return P;
  }

  /**
   * Add a process (without actuals).
   */

  public ProcessInstance addProcess(String name) throws ToolBusException {
    return addProcess(name, (ATermList) factory.make("[]"));
  }

  /**
   * Add a process (as ProcessCall); previous two will become obsolete.
   */

  public ProcessInstance addProcess(ProcessCall call) throws ToolBusException {
    ProcessInstance P = new ProcessInstance(this, call, processes.size());
    processes.add(P);
    return P;
  }
  
  /** addToolInstance adds a new tool instance
   * 
   * @param toolName name of the tool
   * @param sig signature of tool atoms
   * @return the tool instance
   * @throws ToolBusException
   */
  
  synchronized public ToolInstance addToolInstance(String toolName, boolean alreadyExecuting) throws ToolBusException {
  	ATermList sig = getSignature();
  	//System.err.println("addToolInstance: " + toolName + ", " + sig);
  	ToolDefinition TD = getToolDefinition(toolName);
    TD.setToolSignatures(sig);
    ToolInstance ti = new ToolInstance(TD, this, tools.size(), alreadyExecuting);
    tools.add(ti);
    return ti;
  }
  
  synchronized public ToolInstance getToolInstance(ATerm tid){
  	ATermInt arg = (ATermInt) ((ATermAppl) tid).getArgument(0);
  	int n = arg.getInt();
  	return (ToolInstance) tools.elementAt(n);
  }
  
  synchronized public ToolInstance getToolInstance(int n){
  	return (ToolInstance) tools.elementAt(n);
  }
  
  //public ToolInstance getConnectedTool(String toolname){
  //	return toolConnector.getConnectedTool(toolname);
 // }

  /**
   * Get a process definition by name.
   */

  public ProcessDefinition getProcessDefinition(String name) throws ToolBusException {
    for (int i = 0; i < procdefs.size(); i++) {
      ProcessDefinition PD = (ProcessDefinition) procdefs.elementAt(i);
      if (name == PD.getName())
        return PD;
    }
    throw new ToolBusException("no definition for process " + name);
  }
  
  /**
   * Get a tool definition by name.
   */

  public ToolDefinition getToolDefinition(String name) throws ToolBusException {
  	//System.err.println("getToolDefinition: " + name);
    for (int i = 0; i < tooldefs.size(); i++) {
 
      ToolDefinition TD = (ToolDefinition) tooldefs.elementAt(i);
   	  //System.err.println("getToolDefinition: " + i + " : " + TD.getName());
      if (name.equals(TD.getName())){
      	//System.err.println("getToolDefinition: " + TD);
        return TD;
      }
    }
    throw new ToolBusException("no definition for tool " + name);
  }
  
  public void addToSignature(ATerm asig){
  	atomSignature.add(asig);
  }
  
  private ATermList getSignature(){
  	ATermList res = factory.makeList();
    Iterator it = atomSignature.iterator();
    while(it.hasNext()){
    	res = factory.makeList((ATerm) it.next(), res);
    }
    return res;
  }

  /**
   * Shutdown of this ToolBus.
   */

  public void shutdown(ATerm msg){
    for (int i = 0; i < processes.size(); i++) {
    	System.err.println("shutdown process " + i);
      ProcessInstance pi = (ProcessInstance) processes.elementAt(i);
      pi.terminate(msg);
    }
    for(int i = 0; i < tools.size(); i++){
       	//System.err.println("shutdown tool " + i);
    	ToolInstance ti = (ToolInstance) tools.elementAt(i);
    	ti.terminate(msg);
    }
	System.err.println(msg);
    try {
    	WellKnownSocket.close();
    	WellKnownSocketChannel.close();
    	selector.close();
    } catch(IOException e){
    	System.err.println(e);
    }
    shutdownDone = true;
    //throw new ToolBusException("");
  }

  /**
   * Execute all the processes in this ToolBus.
   */

  public void execute() {
    boolean work = true;

    try {
      while (work) {
      	work = false;
      	currentTime = getRunTime();
        for (int i = 0; i < processes.size(); i++) {
          //System.out.print("$");
          ProcessInstance P = (ProcessInstance) processes.elementAt(i);
          work  |= P.step();
          //if (P.isTerminated()) {
          //	processes.remove(P);
          //}
        }
        if(!shutdownDone){
	        long timeout = Math.max(nextTime - currentTime, 200);
	        if(work){
	        	handleInputFromTools(20);
	        } else {
	        	handleInputFromTools(timeout);
	        }
	
	        if(tools.size() > 0 || nextTime > currentTime)
	    		work = true;
        } else {
        	return;
        }
      }
    } catch (ToolBusException e) {
      System.err.println(e.getMessage());
      e.printStackTrace();
    }
    shutdown(factory.make("ToolBus halted"));
  }
}
