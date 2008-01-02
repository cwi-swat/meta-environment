package toolbus.process;

import java.util.Stack;
import toolbus.AtomSet;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import aterm.ATerm;

/**
 * @author paulk, May 30, 2007 RightBiasedAlternative implements the the asymmetric choice operator
 *         operator +>. It is similar to + but prefers its right argument.
 */
public class RightBiasedAlternative extends ProcessExpression implements StateElement{
	private final int LEFT = 0;
	private final int RIGHT = 1;
	
	private ProcessInstance processInstance;
	
	private final ProcessExpression[] expr;
	
	private final State[] state;
	private final State[] initialState;
	private final State mergeState;
	
	private boolean rightLast = false;
	
	public RightBiasedAlternative(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		expr = new ProcessExpression[2];
		expr[LEFT] = left;
		expr[RIGHT] = right;
		
		state = new State[2];
		initialState = new State[2];
		mergeState = new State();
		mergeState.addElement(this);
	}
	
	protected void computeFirst(){
		expr[LEFT].computeFirst();
		expr[RIGHT].computeFirst();
	}
	
	protected void compile(ProcessInstance processInstance, Stack<String> calls, State follows) throws ToolBusException{
		this.processInstance = processInstance;
		
		expr[LEFT].compile(processInstance, calls, follows);
		initialState[LEFT] = state[LEFT] = expr[LEFT].getFirst();
		
		expr[RIGHT].compile(processInstance, calls, follows);
		initialState[RIGHT] = state[RIGHT] = expr[RIGHT].getFirst();
		setFollow(follows);
	}
	
	protected void replaceFormals(Environment env) throws ToolBusException{
		expr[LEFT].replaceFormals(env);
		expr[RIGHT].replaceFormals(env);
	}
	
	protected ProcessExpression copy(){
		return new RightBiasedAlternative(expr[LEFT].copy(), expr[RIGHT].copy(), tbfactory, getPosInfo());
	}
	
	public AtomSet getAtoms(){
		return expr[LEFT].getAtoms().union(expr[RIGHT].getAtoms());
	}
	
	public State getFirst(){
		return mergeState;
	}
	
	// Implementation of the StateElement interface
	
	public boolean contains(StateElement a){
		return state[LEFT].contains(a) || state[RIGHT].contains(a);
	}
	
	public ProcessInstance getProcess(){
		return processInstance;
	}
	
	public void setTest(ATerm test, Environment env) throws ToolBusException{
		state[LEFT].setTest(test, env);
		state[RIGHT].setTest(test, env);
	}
	
	public boolean isEnabled(){
		return state[LEFT].isEnabled() || state[RIGHT].isEnabled();
	}
	
	public State gotoNextStateAndActivate(){
		// System.err.println("RightBiasedAlternative.getNextState: " +
		// leftLast + " ; follow = " + follow);
		// System.err.println("state[LEFT] =" + state[LEFT]);
		// System.err.println("state[RIGHT] =" + state[RIGHT]);
		
		if(rightLast){
			return state[RIGHT].gotoNextStateAndActivate();
		}
		return state[LEFT].gotoNextStateAndActivate();
	}
	
	public State gotoNextStateAndActivate(StateElement se){
		// System.err.println("RightBiasedAlternative.getNextState2: " +
		// leftLast + "; " + se + " ; follow = " + follow);
		// System.err.println("state[LEFT] =" + state[LEFT]);
		// System.err.println("state[RIGHT] =" + state[RIGHT]);
		
		if(state[RIGHT].contains(se)){
			return state[RIGHT].gotoNextStateAndActivate(se);
		}
		return state[LEFT].gotoNextStateAndActivate(se);
		
	}
	
	public void activate(){
		state[LEFT].activate();
		state[RIGHT].activate();
	}
	
	public boolean execute() throws ToolBusException{
		if(state[RIGHT].execute()){
			rightLast = true;
			return true;
		}else if(state[LEFT].execute()){
			rightLast = false;
			return true;
		}else return false;
	}
	
	public String toString(){
		return "RightBiasedAlternative(" + state[LEFT] + "; " + state[RIGHT] + ")";
	}
}
