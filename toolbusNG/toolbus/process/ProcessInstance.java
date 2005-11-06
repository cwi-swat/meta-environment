package toolbus.process;

import java.util.Iterator;
import java.util.Stack;
import java.util.Vector;

import toolbus.Environment;
import toolbus.Functions;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTerm;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermList;

/**
 * @author paulk, Jul 23, 2002
 */
public class ProcessInstance {
  static int processCount = 0;
  static State empty = new State();
  private ProcessDefinition definition;
  private ProcessExpression call;
  private String processName;
  private ATerm processId;
  private State elements;
  private State currentState;
  private ToolBus toolbus;
 // private ToolInstance toolInstance;
  private ATerm transactionIdVar;
  private ATermList subscriptions = TBTerm.factory.makeList();
  private ATermList notes = TBTerm.factory.makeList();
  private boolean running = true;
  private boolean verbose = false;

  public ProcessInstance(ToolBus TB, ProcessCall call) throws ToolBusException {
    toolbus = TB;
    this.call = call;
    processName = call.getName();

    definition = TB.getProcessDefinition(processName);

    Environment env = new Environment();
    
    AFun afun = TBTerm.factory.makeAFun("pi-" + processName, 1, false);
    processId = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(processCount++));
    transactionIdVar = TBTerm.TransactionIdVar;
    env.introduceBinding(transactionIdVar, TBTerm.newTransactionId());

    call.expand(this, new Stack());
    //System.err.println("ProcessInstance: " + env);
    call.compile(this, env, empty);
    currentState = call.getStartState();
    currentState.activate();
 
    Vector procs = TB.getProcesses();
    elements = call.getAtoms();
    for (int i = 0; i < procs.size(); i++) {
      ((ProcessInstance) procs.elementAt(i)).findPartners(elements);
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
    this(TB, new ProcessCall(name, actuals));
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

  public ATerm getProcessId() {
    return processId;
  }
  
  public String getProcessName() {
    return processName;
  }

  public void terminate(String msg) {
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
  	subscriptions = TBTerm.factory.makeList(pat, subscriptions);
  	info("subscribe: after: " + subscriptions);
  }
  
  public void unsubscribe(ATerm pat){
  	subscriptions =  (ATermList) TBTerm.delete(subscriptions, pat);
 	info("unsubscribe: after:" + subscriptions);
  }
  
  public boolean getNoteFromQueue(ATerm pat, Environment env) throws ToolBusException{
  	info("getNoteFromQueue: " + pat);
	info("getNoteFromQueue: subs  " + subscriptions);
 	info("getNoteFromQueue: notes " + notes);
  	for(ATermList nts = notes; !nts.isEmpty();nts = nts.getNext()){
  		ATerm nt = nts.getFirst();
  		info("trying: " + nt);
  		if(TBTerm.match(nt, env, pat, env)){
  			notes = (ATermList) TBTerm.delete(notes, nt);
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
  		if(TBTerm.match(nt, env, pat, env)){
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
  		if(TBTerm.mightMatch(sub, note)){
  			notes = TBTerm.factory.makeList(note, notes);
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
    return !running || (elements.size() == 0);
  }

  public String toString() {
    return "ProcessInstance(" + definition.getName() + ", " + processId + ", " + currentState + ")";
  }
}
