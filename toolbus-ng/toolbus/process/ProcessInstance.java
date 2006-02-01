package toolbus.process;

import java.util.Iterator;
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
  private ATermList subscriptions = TBTermFactory.makeList();
  private ATermList notes = TBTermFactory.makeList();
  private boolean running = true;
 

  public ProcessInstance(ToolBus TB, ProcessCall call, int processId) throws ToolBusException {
    toolbus = TB;
    this.call = call;
    call.setEvalArgs(false);
    processName = call.getName();

    definition = TB.getProcessDefinition(processName);

    Environment env = new Environment();
    
    //AFun afun = TBTerm.factory.makeAFun("pi-" + processName, 1, false);
    //processId = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(processCount++));
    transactionIdVar = TBTermFactory.TransactionIdVar;
    env.introduceBinding(transactionIdVar, TBTermFactory.newTransactionId());

    //call.expand(this, new Stack());
    call.computeFirst();
    //System.err.println("ProcessInstance: " + env);
    call.compile(this, new Stack(), env, empty);
    currentState = call.getStartState();
    currentState.activate();
 
    elements = call.getAtoms();

    for (ProcessInstance P : TB.getProcesses()) {
        P.findPartners(elements);
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

  public ProcessInstance(ToolBus TB, String name, ATermList actuals) throws ToolBusException {
    this(TB, new ProcessCall(name, actuals, false), 0);
  }
  
  void info(String msg) {
	if (verbose) {
		System.err.println("[ProcessInstance " + processName + "] " + msg);
	}
}

  private void addAtomSignature() throws ToolBusException {
    Vector atoms = call.getAtoms().getElementsAsVector();
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
  

  public void findPartners(State a) {
    elements.findPartners(a);
  }
  
  /*
   * Note manipulation
   */
  
  public void subscribe(ATerm pat){
	info("subscribe: pat: " + pat);
 	info("subscribe: before: " + subscriptions);
  	subscriptions = TBTermFactory.makeList(pat, subscriptions);
  	info("subscribe: after: " + subscriptions);
  }
  
  public void unsubscribe(ATerm pat){
  	subscriptions =  (ATermList) TBTermFactory.delete(subscriptions, pat);
 	info("unsubscribe: after:" + subscriptions);
  }
  
  public boolean getNoteFromQueue(ATerm pat, Environment env) throws ToolBusException{
  	info("getNoteFromQueue: " + pat);
	info("getNoteFromQueue: subs  " + subscriptions);
 	info("getNoteFromQueue: notes " + notes);
  	for(ATermList nts = notes; !nts.isEmpty();nts = nts.getNext()){
  		ATerm nt = nts.getFirst();
  		info("trying: " + nt);
  		if(TBTermFactory.match(nt, env, pat, env)){
  			notes = (ATermList) TBTermFactory.delete(notes, nt);
  			info("getNoteFromQueue: " + nt);
  			return true;
  		}
  	}
  	return false;
  }
  
  public boolean noNoteInQueue(ATerm pat, Environment env) throws ToolBusException{
  	info("noNoteInQueue: " + pat);
	info("noNoteInQueue: subs  " + subscriptions);
 	info("noNoteInQueue: notes " + notes);
  	for(ATermList nts = notes; !nts.isEmpty();nts = nts.getNext()){
  		ATerm nt = nts.getFirst();
  		info("trying: " + nt);
  		if(TBTermFactory.match(nt, env, pat, env)){
  			// TODO: What do we do with changes in env???
  			info("noNoteInQueue: " + nt);
  			return false;
  		}
  	}
  	return true;
  }
  
  public boolean putNoteInQueue(ATerm note) throws ToolBusException{
 	info("putNoteInQueue: " + note);
 	info("putNoteInQueue: subs  " + subscriptions);
 	info("putNoteInQueue: notes " + notes);
  	for(ATermList subs = subscriptions; !subs.isEmpty();subs = subs.getNext()){
  		ATerm sub = subs.getFirst();
 		info("trying: " + sub);
  		if(TBTermFactory.mightMatch(sub, note)){
  			notes = TBTermFactory.makeList(note, notes);
  			info("putNoteInQueue: success " + notes);
  			return true;
  		}
  	}
  	info("putNoteInQueue: failure " + notes);
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
