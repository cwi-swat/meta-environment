/**
 * @author paulk, Jul 22, 2002
 */

package toolbus.process;

import java.util.Stack;

import toolbus.*;
import toolbus.State;

import aterm.*;
import aterm.ATermList;

public class ProcessCall extends ProcessExpression {
	private String name;

	private ATermList actuals;

	private ATermList formals;

	private ProcessDefinition definition;

	private ProcessExpression PE;

	private ProcessInstance processInstance;

//	private State startState;

	//private ATerm test;

	public ProcessCall(String name, ATermList actuals) {
		this.name = name;
		this.actuals = actuals;
//		startState = new State();
//		startState.add(this);
	}

	public ProcessCall(ATerm call) {
		this(((ATermAppl) call).getName(), ((ATermAppl) call).getArguments());
	}

	public ProcessExpression copy() {
		return new ProcessCall(name, actuals);
	}

	public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
		//System.err.println("ProcessCall.expand(" + name + ", " + P + "," +
		// calls + ")");
		if (calls.contains(name)) {
			throw new ToolBusException("recursive call of " + name);
		}
		processInstance = P;
		definition = P.getToolBus().getProcessDefinition(name);
		calls.push(name);
		PE = definition.expand(P, calls, actuals);
		calls.pop();
	}

	public void compile(ProcessInstance P, Environment env, State follows)
			throws ToolBusException {
		//System.err.println("ProcessCall.compile(" + name + ", " + P + "," +
		// follows + ")");
		setFollow(follows);
		env = env.copy();
		formals = definition.getFormals();
		actuals = (ATermList) TBTerm.resolveVars(actuals, env);
		env.introduceBindings(formals, actuals);
		PE.replaceFormals(env);
		PE.compile(P, env, follows);
		env.removeBindings(formals);
	}
	
	public void replaceFormals(Environment env) throws ToolBusException{
		PE.replaceFormals(env);
	}

	public State getFirst() {
		return PE.getStartState();
	}

	public State getStartState() {
		return PE.getStartState();
	}

	public State getFollow() {
		return PE.getFollow();
	}

	public State getAtoms() {
		return PE.getAtoms();
	}

	public String getName() {
		return name;
	}

	public String toString() {
		return "ProcessCall(" + name + ", " + actuals + ")";
	}
}