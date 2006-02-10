package toolbus.process;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Vector;

import toolbus.Environment;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import aterm.ATerm;
import aterm.ATermList;

/**
 * @author paulk, Jul 23, 2002
 */
public class ProcessInstance {
	
  private final boolean verbose = false;
	 
  static int processCount = 0;
  static State empty = new State();
  private ProcessDefinition definition;
  private ProcessExpression call;
  private String processName;
  private int processId;
  private State elements;
  private State currentState;
  private ToolBus toolbus;
 // private ToolInstance toolInstance;
  private TBTermVar transactionIdVar;
  private TBTermFactory tbfactory;
  private LinkedList<ATerm> subscriptions;
  private LinkedList<ATerm> notes;
  private boolean running = true;

  public ProcessInstance(ToolBus TB, ProcessCall call, int processId) throws ToolBusException {
    toolbus = TB;
    tbfactory = TB.getTBTermFactory();
    this.call = call;
    this.processId = processId;
    subscriptions = new LinkedList<ATerm>();
    notes = new LinkedList<ATerm>();
    call.setEvalArgs(false);
    processName = call.getName();

    definition = TB.getProcessDefinition(processName);

    Environment env = new Environment(tbfactory);
    
    transactionIdVar = tbfactory.TransactionIdVar;
    env.introduceBinding(transactionIdVar, tbfactory.newTransactionId());

    call.computeFirst();
    call.compile(this, new Stack(), env, empty);
    currentState = call.getStartState();
    currentState.activate();
 
    elements = call.getAtoms();

    for (ProcessInstance P : TB.getProcesses()) {
    	if(P != this){
    		P.findMsgPartners(elements);
    	}
    }
    addAtomSignature();
    if (false) {
      System.err.println(processId + ": " + call);
      System.err.println(processId + ": atoms: =" + elements);
      System.err.println(processId + ": prefix = " + currentState);
      for (Iterator it = elements.getElementsAsVector().iterator(); it.hasNext();) {
        Atom a = (Atom) it.next();
        System.err.println(processId + ": " + a + " --> " + a.getFollow());
        //System.err.println("env = " + a.getEnv());
      }
    }
  }

  public ProcessInstance(ToolBus TB, String name, ATermList actuals, int processId) throws ToolBusException {
    this(TB, new ProcessCall(name, actuals, false, TB.getTBTermFactory()), processId);
  }
  
  public TBTermFactory getTBTermFactory(){
	  return tbfactory;
  }
  
  void info(String msg) {
	if (verbose) {
		System.err.println("[ProcessInstance " + processName + "] " + msg);
	}
}

  private void addAtomSignature() throws ToolBusException {
    Vector<StateElement> atoms = call.getAtoms().getElementsAsVector();
    for (int i = 0; i < atoms.size(); i++) {
      ATerm pat = ((Atom) atoms.get(i)).toATerm();
      toolbus.addToSignature(pat);
    }
  }
  
  public ToolBus getToolBus() {
    return toolbus;
  }
  
  public long getRunTime() {
  	return toolbus.getRunTime();
  }

  public int getProcessId() {
    return processId;
  }
  
  public String getProcessName() {
    return processName;
  }

  public void terminate(ATerm msg) {
  	running = false;
  }

  public void findMsgPartners(State a) {
	elements.findMsgPartners(a);
  }
  
  /*
   * Note manipulation
   */
  
  public void subscribe(ATerm pat){
  	subscriptions.add(pat);
  }
  
  public void unsubscribe(ATerm pat){
  	subscriptions.remove(pat);
 	//info("unsubscribe: after:" + subscriptions);
  }
  
  public boolean getNoteFromQueue(ATerm pat, Environment env) throws ToolBusException{
	for(ATerm note : notes){
  		if(tbfactory.match(note, env, pat, env)){
  			notes.remove();
  			return true;
  		}
  	}
  	return false;
  }
  
  public boolean noNoteInQueue(ATerm pat, Environment env) throws ToolBusException{
	for(ATerm note : notes){
  		if(tbfactory.match(note, env, pat, env)){
  			// TODO: What do we do with changes in env???
  			return false;
  		}
  	}
  	return true;
  }
  
  public boolean putNoteInQueue(ATerm note) throws ToolBusException{
  	for(ATerm sub : subscriptions){
  		if(tbfactory.mightMatch(sub, note)){
  			notes.addLast(note);
  			return true;
  		}
  	}
  	return false;
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
  
  public boolean nextState(){
  	currentState = currentState.getNextState();
  	return true;
  }
  
  public boolean nextState(StateElement a){
  	currentState = currentState.getNextState(a);
  	return true;
  }

  public boolean step() throws ToolBusException {
    //System.err.println("step: " + this);
  	if(running && currentState.execute()){
  		return nextState();
  	}
  	return false;
  }

  public boolean isTerminated() {
	if(!running || currentState.size() == 0){
		return true;
	}
	return false;
  }

  public String toString() {
    return "ProcessInstance(" + definition.getName() + ", " + processId + ", " + currentState + ")";
  }
}
