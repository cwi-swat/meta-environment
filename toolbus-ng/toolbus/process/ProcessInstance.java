package toolbus.process;

import java.util.*;

import toolbus.*;
import toolbus.atom.*;
import toolbus.tool.ToolInstance;

import aterm.*;

/**
 * @author paulk, Jul 23, 2002
 */
public class ProcessInstance {
  static int processCount = 0;
  static State empty = new State();
  private ProcessDefinition definition;
  private ATerm processId;
  private State elements;
  private State currentState;
  private Environment env;
  private ToolBus toolbus;
  private ToolInstance toolinstance;

  public ProcessInstance(ToolBus TB, ProcessCall call) throws ToolBusException {
    String name = call.getName();
    toolbus = TB;
    definition = TB.getProcessDefinition(name);

    env = new Environment();
    AFun afun = TBTerm.factory.makeAFun(name, 1, false);
    processId = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(processCount++));

    call.expand(this, new Stack());
    call.compile(this, empty);
    currentState = call.getStartState();
    env.setExecuting();

    Vector procs = TB.getProcesses();
    elements = call.getAtoms();
    for (int i = 0; i < procs.size(); i++) {
      ((ProcessInstance) procs.elementAt(i)).findPartners(elements);
    }

    toolinstance = definition.createToolInstance();

    if(ToolBus.isVerbose()) {
      System.out.println(processId + ": " + call);
      System.out.println(processId + ": atoms: =" + elements);
      System.out.println(processId + ": prefix = " + currentState);
      for (Iterator it = elements.getElementsAsVector().iterator(); it.hasNext();) {
        Atom a = (Atom) it.next();
        System.out.println(processId + ": " + a + " --> " + a.getFollow());
      }
    }
  }

  public ProcessInstance(ToolBus TB, String name, ATermList actuals) throws ToolBusException {
    this(TB, new ProcessCall(name, actuals));
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
    return toolinstance;
  }

  public void terminate(String msg) {
    if (toolinstance != null) {
      toolinstance.terminate(msg);
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

  //  public void nestState(StateElement a) {
  //    if (!currentState.contains(a))
  //      System.out.println("*** ProcessInstance.follow: " + a + " not in prefix " + currentState);
  //    currentState = currentState.nextState(a);
  //    //System.out.println("proc " + processId + ": follow(" + a + ") -> " + prefix);
  //  }

  public State getCurrentState() {
    return currentState;
  }
  public void setCurrentState(State s) {
    currentState = s;
  }

  public boolean step() throws ToolBusException {
    //System.out.println(this);
    return currentState.execute();
  }

  public boolean isTerminated() {
    return (elements.size() == 0);
  }

  public String toString() {
    return "ProcessInstance(" + definition.getName() + ", " + processId + ", " + currentState + ")";
  }
}
