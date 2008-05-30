package toolbus.process;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import toolbus.AtomSet;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.debug.ExecutionResult;
import aterm.ATerm;

/**
 * LeftBiasedAlternative implements the the asymmetric choice operator operator <+. It is similar
 * to + but prefers its left argument.
 * 
 * @author Arnold Lankamp
 */
public class LeftBiasedAlternative extends ProcessExpression implements StateElement{
	private final int LEFT = 0;
	private final int RIGHT = 1;
	
	private ProcessInstance processInstance;
	
	private final ProcessExpression[] expr;
	
	private final State[] state;
	private final State mergeState;
	
	private boolean leftLast = false;
	
	public LeftBiasedAlternative(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		expr = new ProcessExpression[2];
		expr[LEFT] = left;
		expr[RIGHT] = right;
		
		state = new State[2];
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
		state[LEFT] = expr[LEFT].getFirst();
		
		expr[RIGHT].compile(processInstance, calls, follows);
		state[RIGHT] = expr[RIGHT].getFirst();
		setFollow(follows);
	}
	
	protected void replaceFormals(Environment env) throws ToolBusException{
		expr[LEFT].replaceFormals(env);
		expr[RIGHT].replaceFormals(env);
	}
	
	protected ProcessExpression copy(){
		return new LeftBiasedAlternative(expr[LEFT].copy(), expr[RIGHT].copy(), tbfactory, getPosInfo());
	}
	
	public AtomSet getAtoms(){
		return expr[LEFT].getAtoms().union(expr[RIGHT].getAtoms());
	}
	
	public State getFirst(){
		return mergeState;
	}
	
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
	
	public List<ATerm> getTests(){
		return new ArrayList<ATerm>(0);
	}
	
	public boolean isEnabled(){
		return state[LEFT].isEnabled() || state[RIGHT].isEnabled();
	}
	
	public State gotoNextStateAndActivate(){
		if(leftLast) return state[LEFT].gotoNextStateAndActivate();
		
		return state[RIGHT].gotoNextStateAndActivate();
	}
	
	public State gotoNextStateAndActivate(StateElement se){
		if(state[LEFT].contains(se)) return state[LEFT].gotoNextStateAndActivate(se);
			
		return state[RIGHT].gotoNextStateAndActivate(se);
	}
	
	public void activate(){
		state[LEFT].activate();
		state[RIGHT].activate();
	}
	
	public boolean execute() throws ToolBusException{
		if(state[LEFT].execute()){
			leftLast = true;
			return true;
		}else if(state[RIGHT].execute()){
			leftLast = false;
			return true;
		}else return false;
	}
	
	public ProcessInstance[] debugExecute() throws ToolBusException{
		ExecutionResult er;
		if((er = state[LEFT].debugExecute()) != null){
			leftLast = true;
			return er.partners;
		}else if((er = state[RIGHT].debugExecute()) != null){
			leftLast = false;
			return er.partners;
		}
		
		return null;
	}
	
	public String toString(){
		return "LeftBiasedAlternative(" + state[LEFT] + "; " + state[RIGHT] + ")";
	}
}
