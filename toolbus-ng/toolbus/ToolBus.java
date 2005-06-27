/**
 * @author paulk
 */

package toolbus;
import java.io.*;
import java.util.*;

import toolbus.parser.*;
import toolbus.parser.TScriptParser;
import toolbus.process.*;
import toolbus.tool.JavaTool;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;

import aterm.*;

/**
 * ToolBus implements the complete behaviour of one ToolBus.
 */

public class ToolBus {

  private static Random rand = new Random();
  private ATermFactory factory;
  private Vector processes; // process instances
  private Vector tools;     // tool instances
  private Vector procdefs;
  private Vector tooldefs;
  private TScriptParser parser;
  private PrintWriter out;

  private static String sglr = "/ufs/paulk/software/installed/bin/sglr";
  private static String parseTable = "/ufs/paulk/workspace/toolbusNG/toolbus/parser/Tscript.trm.tbl";
  private static String implodePT = "/ufs/paulk/software/installed/bin/implodePT";
  private static String workspace = "/ufs/paulk/eclipse/worlspace";
  private static boolean verbose = false;
  private static int nerrrors = 0;
  private static int nwarnings = 0;

  /**
   * Constructor with explicit PrintWriter
   */

  public ToolBus(PrintWriter out) {
    TBTerm.init();
    factory = TBTerm.factory;
    this.out = out;
    processes = new Vector();
    tools = new Vector();
    procdefs = new Vector();
    tooldefs = new Vector();
    try {
      loadProperties();
    } catch (IOException e) {
      System.err.println(e.getMessage());
    }
    parser = new TScriptParser(new ExternalParser(sglr, parseTable, implodePT));
  }

  /**
   * Constructir with implicit PrintWriter
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
    ProcessInstance P = new ProcessInstance(this, call);
    processes.add(P);
    return P;
  }
  
  public ToolInstance addToolInstance(String toolName, ATermList sig) throws ToolBusException {
  	System.err.println("addToolInstance: " + toolName + ", " + sig);
  	ToolDefinition TD = getToolDefinition(toolName);
    TD.setFunctionSignatures(sig);
    ToolInstance ti = new JavaTool(TD, tools.size());
    tools.add(ti);
    return ti;
  }
  
  public ToolInstance getToolInstance(ATerm tid){
  	ATermInt arg = (ATermInt) ((ATermAppl) tid).getArgument(0);
  	int n = arg.getInt();
  	return (ToolInstance) tools.elementAt(n);
  }

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
    for (int i = 0; i < tooldefs.size(); i++) {
      ToolDefinition TD = (ToolDefinition) tooldefs.elementAt(i);
      if (name == TD.getName())
        return TD;
    }
    throw new ToolBusException("no definition for tool " + name);
  }

  /**
   * Shutdown of this ToolBus.
   */

  public void shutdown(String msg) throws ToolBusDeathException {
    for (int i = 0; i < processes.size(); i++) {
      ProcessInstance P = (ProcessInstance) processes.elementAt(i);
      P.terminate(msg);
    }
    throw new ToolBusDeathException(msg);
  }

  /**
   * Execute all the processes.
   */

  public void execute() {
    boolean work = true;
    int n = 2000;

    try {
      while (work) {
        n--;
        work = n > 0;
        for (int i = 0; i < processes.size(); i++) {
          ProcessInstance P = (ProcessInstance) processes.elementAt(i);
          P.step();
          //if (P.isTerminated()) {
          //	processes.remove(P);
          //}
        }
      }
    } catch (ToolBusException e) {
      System.err.println(e.getMessage());
    }
    System.err.println("ToolBus halted");
  }
}
