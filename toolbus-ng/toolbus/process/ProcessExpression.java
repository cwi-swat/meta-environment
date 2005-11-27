package toolbus.process;

import java.util.Stack;

import toolbus.*;

/**
 * ProcesssExpression defines the overall behaviour of process expressions.
 * 
 */

abstract public class ProcessExpression {
	private State first;

	private State follow;

	public ProcessExpression() {
		first = new State();
	}

	public State getFirst() {
		return first;
	}

	protected void setFirst(State first) {
		//System.err.println("setFirst: " + first);
		this.first = first;
	}

	public State getStartState() {
		return first;
	}

	protected void addToFirst(StateElement a) {
		first.add(a);
	}

	public State getFollow() {
		return follow;
	}

	protected void setFollow(State follow) {
		this.follow = follow;
	}

	protected void addToFollow(State set) {
		follow = follow.union(set);
	}

//	abstract public void expand(ProcessInstance processInstance, Stack calls)
//			throws ToolBusException;
	
	abstract public void computeFirst();

	abstract public void compile(ProcessInstance processInstance, Stack calls, Environment env, State followSet)
			throws ToolBusException;
	
	abstract public void replaceFormals(Environment env) throws ToolBusException;

	abstract public ProcessExpression copy();

	abstract public State getAtoms();
}