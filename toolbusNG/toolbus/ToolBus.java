/**
 * @author paulk
 */

package toolbus;
import java.io.*;
import java.util.*;

import toolbus.parser.*;
import toolbus.parser.TscriptParser;
import toolbus.process.*;

import aterm.*;

/**
 * ToolBus implements the complete behaviour of one ToolBus.
 */

public class ToolBus {

  private static Random rand = new Random();
  private ATermFactory factory;
  private Vector processes;
  private Vector procdefs;
  private TscriptParser parser;
  private PrintWriter out;

  private static String sglr = "/home/paulk/bin/sglr";
  private static String parseTable = "/home/paulk/eclipse/workspace/toolbusNG/toolbus/parser/Tscript.trm.tbl";
  private static String implodePT = "/home/paulk/bin/implodePT";
  private static boolean verbose = false;
  
  /**
   * Constructor with explicit PrintWriter
   */

  public ToolBus(PrintWriter out) {
    TBTerm.init();
    factory = TBTerm.factory;
    this.out = out;
    processes = new Vector();
    procdefs = new Vector();
    try {
      loadProperties();
    } catch (IOException e) {
      System.err.println(e.getMessage());
    }
    parser = new TscriptParser(new ExternalParser(sglr, parseTable, implodePT));
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
  
  /**
   * Get the name of the property file to be used
   */

  private static String getPropertyFile() {
    String stdName = "toolbus.props";
    String user = System.getProperty("user.name");
    File f;
    String fname;
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
   * Get current PrintWriter.
   */

  public PrintWriter getPrintWriter() {
    return out;
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
   * Add a process (with actuals) and attached tool name.
   */

  public ProcessInstance addProcess(String name, ATermList actuals, String toolname) throws ToolBusException {
    ProcessInstance P = new ProcessInstance(this, name, actuals, toolname);
    processes.add(P);
    return P;
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
  
  public ProcessInstance addProcess(ProcessCall call, String toolName) throws ToolBusException {
    ProcessInstance P = new ProcessInstance(this, call, toolName);
    processes.add(P);
    return P;
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
