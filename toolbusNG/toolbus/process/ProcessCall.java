
/**
 * @author paulk, Jul 22, 2002
 */

package toolbus.process;
import java.util.Stack;

import toolbus.*;
import toolbus.State;

import aterm.*;
import aterm.ATermList;

public class ProcessCall extends AbstractProcessExpression implements StateElement {
  private String name;
  private ATermList actuals;
  private ATermList formals;
  private ProcessDefinition definition;
  private ProcessExpression PE;
  private ProcessInstance processInstance;
  private State startState;
  private ATerm test;

  public ProcessCall(String name, ATermList actuals) {
    this.name = name;
    this.actuals = actuals;
    startState = new State();
    startState.add(this);
    //System.err.println("ProcessCall(\"" + name + "\", " + actuals + ")");
  }
  public ProcessCall(ATerm call) {
    this(((ATermAppl) call).getName(), ((ATermAppl) call).getArguments());
  }

  public ProcessExpression copy() {
    //System.err.println("ProcessCall.copy: " + name);
    return new ProcessCall(name, actuals);
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    //System.err.println("ProcessCall.expand(" + name + ", " + P + "," + calls + ")");
    if (calls.contains(name)) {
      throw new ToolBusException("recursive call of " + name);
    }
    processInstance = P;
    ToolBus TB = P.getToolBus();
    calls.push(name);
    definition = TB.getProcessDefinition(name);
    PE = definition.expand(P, calls, actuals);
    calls.pop();
  }

  public void compile(ProcessInstance P, State follows) throws ToolBusException {
    //System.err.println("ProcessCall.compile(" + name + ", " + P + "," + follows + ")");
    Environment env = P.getEnv();
    actuals = (ATermList) TBTerm.resolveVars(actuals, env);
    //System.err.println("actuals = " + actuals);
    //System.err.println("definiton = " + definition);
    definition.enterScope(env, actuals);
    formals = definition.getCompiledFormals(env);
    PE.compile(P, follows);
    definition.leaveScope(env);
    //System.err.println("ProcessCall.compile:PE = " + PE);
  }

  public State getFirst() {
    return startState;
  }

  public State getStartState() {
    return startState;
  }

  public State getFollow() {
    return PE.getFollow();
  }

  public State getAtoms() {
    return PE.getAtoms();
  }
  
  public String getName(){
    return name;
  }

  public String toString() {
    return "ProcessCall(" + name + ", " + actuals + ")";
  }

  // The StateElement interface

  public boolean canCommunicate(StateElement a) {
    return false;
  }

  public void addPartner(StateElement a) {
  }

  public ProcessInstance getProcess() {
    return processInstance;
  }
  public boolean contains(StateElement b) {
    //System.err.println(this +" contains " + b);
    return startState.contains(b);
  }

  public boolean nextState() {
    State s = PE.getStartState();
    processInstance.setCurrentState(s);
    return true;
  }
  public void setTest(ATerm test) throws ToolBusException {
  	if(test != null){
	    ATerm rtst = TBTerm.resolveVars(test, processInstance.getEnv());
	    if (this.test == null) {
	      this.test = rtst;
	    } else {
	      this.test = TBTerm.factory.make("and(<term>,<term>)", rtst, this.test);
	    }
  	}
  }

  public boolean isEnabled() throws ToolBusException {
    if (test == null)
      return true;
    else {
      boolean res = TBTerm.isTrue(FunctionDescriptors.eval(test, getProcess()));
      //System.err.println(this.getProcess().getProcessId() + ": " + this + " : evaluate: " + test + " ==> " + res);
      return res;
    }
  }

  public boolean execute() throws ToolBusException {
    //System.err.println("ProcessCall.execute(" + name + ") formals = " + formals + "; actuals = " + actuals);
  	if(!isEnabled()){
  		return false;
  	}
    Environment env = processInstance.getEnv();
    ATermList formals1 = formals;
    ATermList actuals1 = actuals;
    for (int i = 0; i < formals.getLength(); i++) {
      ATerm formal = formals1.getFirst();
      formals1 = formals1.getNext();
      ATerm actual = actuals1.getFirst();
      actuals1 = actuals1.getNext();
      if (!TBTerm.isResVar(formal)) {
        env.assignVar(formal, TBTerm.substitute(actual, env));
        //System.err.println(formal + " gets value " + env.getVar(formal));
      }
    }
    startState = PE.getStartState();
    startState.setTest(test);
    processInstance.setCurrentState(startState);
    return startState.execute();
  }

}
