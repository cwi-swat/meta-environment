package toolbus.process;

import java.util.*;

import toolbus.*;
import toolbus.atom.*;
import toolbus.tool.*;
import toolbus.tool.ToolInstance;

import aterm.*;

/**
 * @author paulk, Jul 23, 2002
 */
public class ProcessInstance {
  static int processCount = 0;
  private static int ninstances = 0;
  static State empty = new State();
  private ProcessDefinition definition;
  private ProcessExpression call;
  private String processName;
  private ATerm processId;
  private State elements;
  private State currentState;
  private Environment env;
  private ToolBus toolbus;
  private ToolInstance toolInstance;
  private String toolName;

  public ProcessInstance(ToolBus TB, ProcessCall call, String toolName) throws ToolBusException {
    toolbus = TB;
    this.call = call;
    this.toolName = toolName;
    processName = call.getName();

    definition = TB.getProcessDefinition(processName);

    env = new Environment();
    
    AFun afun = TBTerm.factory.makeAFun(processName, 1, false);
    processId = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(processCount++));
    
    ATerm tid = TBTerm.TransactionIdVar;
    
    env.introduceVars(TBTerm.factory.makeList(tid));

    call.expand(this, new Stack());
    call.compile(this, empty);
    currentState = call.getStartState();
    tid = TBTerm.resolveVars(tid, env);
    env.setExecuting();
    env.assignVar(tid, processId);

    Vector procs = TB.getProcesses();
    elements = call.getAtoms();
    for (int i = 0; i < procs.size(); i++) {
      ((ProcessInstance) procs.elementAt(i)).findPartners(elements);
    }

    toolInstance = createToolInstance();

    if (ToolBus.isVerbose()) {
      System.err.println(processId + ": " + call);
      System.err.println(processId + ": atoms: =" + elements);
      System.err.println(processId + ": prefix = " + currentState);
      for (Iterator it = elements.getElementsAsVector().iterator(); it.hasNext();) {
        Atom a = (Atom) it.next();
        System.err.println(processId + ": " + a + " --> " + a.getFollow());
      }
    }
  }

  public ProcessInstance(ToolBus TB, ProcessCall call) throws ToolBusException {
    this(TB, call, null);
  }

  public ProcessInstance(ToolBus TB, String name, ATermList actuals) throws ToolBusException {
    this(TB, new ProcessCall(name, actuals), null);
  }

  public ProcessInstance(ToolBus TB, String name, ATermList actuals, String toolName) throws ToolBusException {
    this(TB, new ProcessCall(name, actuals), toolName);
  }

  private ATermList makeSig() throws ToolBusException {
    ATermList sig = (ATermList) TBTerm.factory.make("[]");
    Vector atoms = call.getAtoms().getElementsAsVector();
    for (int i = 0; i < atoms.size(); i++) {
      ATerm pat = ((Atom) atoms.get(i)).toATerm();
      sig = TBTerm.factory.makeList(pat, sig);
    }
    return sig;
  }

  public ToolInstance createToolInstance() throws ToolBusException {
    if (toolName == null)
      return null;
    else {
      AFun afun = TBTerm.factory.makeAFun(processName, 1, false);
      ATermAppl tid = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(ninstances));
      ninstances++;
      return new JavaTool(toolName, tid, makeSig());
    }
  }

  public Environment getEnv() {
    return env;
  }

  public ToolBus getToolBus() {
    return toolbus;
  }

  public ATerm getProcessId() {
    return processId;
  }

  public ToolInstance getToolInstance() {
    return toolInstance;
  }

  public void terminate(String msg) {
    if (toolInstance != null) {
      toolInstance.terminate(msg);
    }
  }

  public void findPartners(State a) {
    elements.findPartners(a);
  }

  public State getProcessState() {
    return currentState;
  }

  public boolean contains(StateElement a) {
    return currentState.contains(a);
  }

  public State getCurrentState() {
    return currentState;
  }
  public void setCurrentState(State s) {
    currentState = s;
  }

  public boolean step() throws ToolBusException {
    //System.err.println(this);
    return currentState.execute();
  }

  public boolean isTerminated() {
    return (elements.size() == 0);
  }

  public String toString() {
    return "ProcessInstance(" + definition.getName() + ", " + processId + ", " + currentState + ")";
  }
}
