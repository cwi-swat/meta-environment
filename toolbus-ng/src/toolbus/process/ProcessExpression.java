/**
 * Process operators
 */
package toolbus.process;

import java.util.Stack;
import toolbus.AtomList;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;

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
	protected final PositionInformation posInfo;
	
	public ProcessExpression(TBTermFactory tbfactory, PositionInformation posInfo){
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
	
	public PositionInformation getPosInfo(){
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
	
	abstract protected void computeFirst();
	
	abstract protected void replaceFormals(Environment env) throws ToolBusException;
	
	abstract protected void compile(ProcessInstance processInstance, Stack<String> calls, State followSet) throws ToolBusException;
	
	abstract protected ProcessExpression copy();
	
	abstract public AtomList getAtoms();
}
