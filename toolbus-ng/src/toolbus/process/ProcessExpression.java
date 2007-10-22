/**
 * Process operators
 */
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
 * ProcesssExpression represents abstract syntax operators for operators in process expressions of
 * Tscripts. Specific operators like Sequence and Alternative are subclasses of ProcessExpression.
 */
abstract public class ProcessExpression{
	/**
	 * The term factory to be used.
	 */
	protected final TBTermFactory tbfactory;
	
	/**
	 * The first (entry) state for the automaton that implements this process expression.
	 */
	private State first;
	
	/**
	 * The state that follows (= connected to the exit of) the automaton that implements this
	 * process expression.
	 */
	private State follow;
	
	/**
	 * Position information (i.e., source code location) of this process expression.
	 */
	protected final ATerm posInfo;
	
	public ProcessExpression(TBTermFactory tbfactory, ATerm posInfo){
		this.tbfactory = tbfactory;
		this.posInfo = posInfo;
		
		first = new State();
	}
	
	public State getFirst(){
		return first;
	}
	
	protected void setFirst(State first){
		this.first = first;
	}
	
	public ATerm getPosInfo(){
		return posInfo;
	}
	
	protected void addToFirst(StateElement a){
		first.addElement(a);
	}
	
	public State getFollow(){
		return follow;
	}
	
	protected void setFollow(State follow){
		this.follow = follow;
	}
	
	protected void addToFollow(State set){
		follow = follow.union(set);
	}
	
	abstract public void computeFirst();
	
	abstract public void replaceFormals(Environment env) throws ToolBusException;
	
	abstract public void compile(ProcessInstance processInstance, Stack<String> calls, State followSet) throws ToolBusException;
	
	abstract public ProcessExpression copy();
	
	abstract public AtomSet getAtoms();
}
