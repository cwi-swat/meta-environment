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
import aterm.pure.PureFactory;

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

  public ToolBus() {
    this(new PrintWriter(System.out));
  }

  public ToolBus(StringWriter out) {
    this(new PrintWriter(out));
  }

  public static String getPropertyFile() {
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

  public static void loadProperties() throws IOException {
    Properties props = new Properties();
    String pname = getPropertyFile();
    if (pname != null) {
      props.load(ClassLoader.getSystemResourceAsStream(pname));
      sglr = props.getProperty("sglr.path", sglr);
      parseTable = props.getProperty("parsetable.path", parseTable);
      implodePT = props.getProperty("implodePT.path", implodePT);
    }
  }

  public ATermFactory getFactory() {
    return factory;
  }

  public Vector getProcesses() {
    return processes;
  }

  public static void setVerbose(boolean b) {
    verbose = b;
  }

  public static boolean isVerbose() {
    return verbose;
  }

  public PrintWriter getPrintWriter() {
    return out;
  }

  public static int nextInt(int n) {
    return rand.nextInt(n);
  }

  public static boolean nextBoolean() {
    return rand.nextBoolean();
  }

  public void parse(String filename) throws ToolBusException {
    parser.parse(this, filename);
  }

  public void addProcessDefinition(ProcessDefinition PD) throws ToolBusException {
    String name = PD.getName();
    for (int i = 0; i < procdefs.size(); i++) {
      ProcessDefinition PD2 = (ProcessDefinition) procdefs.elementAt(i);
      if (name == PD2.getName())
        throw new ToolBusException("duplicate definition of process " + name);
    }
    procdefs.add(PD);
  }

  public ProcessInstance addProcess(String name, ATermList actuals) throws ToolBusException {
    ProcessInstance P = new ProcessInstance(this, name, actuals);
    processes.add(P);
    return P;
  }

  public ProcessInstance addProcess(String name) throws ToolBusException {
    return addProcess(name, (ATermList) factory.make("[]"));
  }

  public ProcessInstance addProcess(ProcessCall call) throws ToolBusException {
    ProcessInstance P = new ProcessInstance(this, call);
    processes.add(P);
    return P;
  }

  public ProcessDefinition getProcessDefinition(String name) throws ToolBusException {
    for (int i = 0; i < procdefs.size(); i++) {
      ProcessDefinition PD = (ProcessDefinition) procdefs.elementAt(i);
      if (name == PD.getName())
        return PD;
    }
    throw new ToolBusException("no definition for process " + name);
  }

  public void shutdown(String msg) throws ToolBusDeathException {
    for (int i = 0; i < processes.size(); i++) {
      ProcessInstance P = (ProcessInstance) processes.elementAt(i);
      P.terminate(msg);
    }
    throw new ToolBusDeathException(msg);
  }

  public void execute() {
    boolean work = true;
    int n = 200;

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
