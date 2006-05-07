package toolbus.process;

import java.util.Stack;

import toolbus.AtomSet;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import aterm.ATerm;

/**
 * ProcesssExpression defines the overall behaviour of process expressions.
 * 
 */

abstract public class ProcessExpression {
	
	protected TBTermFactory tbfactory;
	
	private State first;

	private State follow;
	
	protected ATerm posInfo = null;

	public ProcessExpression(TBTermFactory tbfactory, ATerm posInfo) {
		this.tbfactory = tbfactory;
		this.posInfo = posInfo;
		assert tbfactory != null;
		first = new State();
	}

	public State getFirst() {
		return first;
	}

	protected void setFirst(State first) {
		this.first = first;
	}
	
	public ATerm getPosInfo(){
		return posInfo;
	}

//	public State getStartState() {
//		return first;
//	}

	protected void addToFirst(StateElement a) {
		first.addElement(a);
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
	
	abstract public void computeFirst();
	
    abstract public void replaceFormals(Environment env) throws ToolBusException;

	abstract public void compile(ProcessInstance processInstance, Stack<String> calls, State followSet)
			throws ToolBusException;

	abstract public ProcessExpression copy();

	abstract public AtomSet getAtoms();
}