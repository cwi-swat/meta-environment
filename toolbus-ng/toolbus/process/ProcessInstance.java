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
  static State empty = new State();
  private ProcessDefinition definition;
  private ProcessExpression call;
  private String processName;
  private ATerm processId;
  private State elements;
  private State currentState;
  private ToolBus toolbus;
  private ToolInstance toolInstance;
  private ATerm transactionIdVar;
  private ATermList subscriptions = TBTerm.factory.makeList();
  private ATermList notes = TBTerm.factory.makeList();

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
 
    Vector procs = TB.getProcesses();
    elements = call.getAtoms();
    for (int i = 0; i < procs.size(); i++) {
      ((ProcessInstance) procs.elementAt(i)).findPartners(elements);
    }

    if (ToolBus.isVerbose()) {
      System.err.println(processId + ": " + call);
      System.err.println(processId + ": atoms: =" + elements);
      System.err.println(processId + ": prefix = " + currentState);
      for (Iterator it = elements.getElementsAsVector().iterator(); it.hasNext();) {
        Atom a = (Atom) it.next();
        System.err.println(processId + ": " + a + " --> " + a.getFollow());
        System.err.println("env = " + a.getEnv());
      }
    }
    //System.err.println("ProcessInstance (leaving): " + env);
  }

  public ProcessInstance(ToolBus TB, String name, ATermList actuals) throws ToolBusException {
    this(TB, new ProcessCall(name, actuals));
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
/*
  public ToolInstance createToolInstance(String toolName) throws ToolBusException {
  	ToolDefinition TD = toolbus.getToolDefinition(toolName);
    TD.setFunctionSignatures(makeSig());
    toolInstance = new JavaTool(TD);
    return toolInstance;
  }
  */

  public ToolBus getToolBus() {
    return toolbus;
  }

  public ATerm getProcessId() {
    return processId;
  }
  
  public String getProcessName() {
    return processName;
  }

  public ToolInstance getToolInstance() {
    return toolInstance;
  }

  public void terminate(String msg) {
    if (toolInstance != null) {
      try {
      	System.err.println("terminate should be fixed");
      //toolInstance.terminate(env.getValue(transactionIdVar), msg);
      	throw new ToolBusException("Fix terminate");
      } catch (ToolBusException e) {
        throw new ToolBusInternalError("no transactionId in process");
      }
    }
  }

  public void findPartners(State a) {
    elements.findPartners(a);
  }
  /*
   * Note manipulation
   */
  
  public void subscribe(ATerm pat){
	//System.err.println("subscribe: pat: " + pat);
 	//System.err.println("subscribe: before: " + subscriptions);
  	subscriptions = TBTerm.factory.makeList(pat, subscriptions);
  	//System.err.println("subscribe: after: " + subscriptions);
  }
  
  public void unsubscribe(ATerm pat){
  	subscriptions =  (ATermList) TBTerm.delete((ATerm) subscriptions, pat);
 	//System.err.println("unsubscribe: after:" + subscriptions);
  }
  
  public boolean getNoteFromQueue(ATerm pat, Environment env) throws ToolBusException{
  	//System.err.println("getNoteFromQueue: " + pat);
	//System.err.println("getNoteFromQueue: subs  " + subscriptions);
 	//System.err.println("getNoteFromQueue: notes " + notes);
  	for(ATermList nts = notes; !nts.isEmpty();nts = nts.getNext()){
  		ATerm nt = nts.getFirst();
  		//System.err.println("trying: " + nt);
  		if(TBTerm.match(nt, env, pat, env)){
  			notes = (ATermList) TBTerm.delete((ATerm) notes, nt);
  			//System.err.println("getNoteFromQueue: " + nt);
  			return true;
  		}
  	}
  	return false;
  }
  
  public boolean noNoteInQueue(ATerm pat, Environment env) throws ToolBusException{
  	//System.err.println("noNoteInQueue: " + pat);
	//System.err.println("noNoteInQueue: subs  " + subscriptions);
 	//System.err.println("noNoteInQueue: notes " + notes);
  	for(ATermList nts = notes; !nts.isEmpty();nts = nts.getNext()){
  		ATerm nt = nts.getFirst();
  		//System.err.println("trying: " + nt);
  		if(TBTerm.match(nt, env, pat, env)){
  			// What do we do with changes in env???
  			//System.err.println("noNoteInQueue: " + nt);
  			return false;
  		}
  	}
  	return true;
  }
  
  public boolean putNoteInQueue(ATerm note) throws ToolBusException{
 	//System.err.println("putNoteInQueue: " + note);
 	//System.err.println("putNoteInQueue: subs  " + subscriptions);
 	//System.err.println("putNoteInQueue: notes " + notes);
  	for(ATermList subs = subscriptions; !subs.isEmpty();subs = subs.getNext()){
  		ATerm sub = subs.getFirst();
 		//System.err.println("trying: " + sub);
  		if(Functions.compatibleTypes(sub, note)){
  			notes = TBTerm.factory.makeList(note, notes);
  			//System.err.println("putNoteInQueue: success " + notes);
  			return true;
  		}
  	}
  	//System.err.println("putNoteInQueue: failure " + notes);
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
