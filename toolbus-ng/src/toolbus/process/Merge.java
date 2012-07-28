package toolbus.process;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Stack;
import toolbus.AtomList;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.debug.ExecutionResult;
import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002 Merge implements the parallell composition operator || It maintains
 *         its two arguments and randomly selects in which argument the next atom will be executed.
 *         When both arguments are exhausted, execution continues with the followSet of the merge.
 */
public class Merge extends ProcessExpression implements StateElement{
	private final static Random rand = new Random();
	
	private final int LEFT = 0;
	private final int RIGHT = 1;
	
	private ProcessInstance processInstance;
	
	private final ProcessExpression[] expr;
	
	private final State[] state;
	private final State[] initialState;
	private final State mergeState;
	
	private boolean leftLast = false;
	
	public Merge(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		state = new State[2];
		initialState = new State[2];
		
		expr = new ProcessExpression[2];
		expr[LEFT] = left;
		expr[RIGHT] = right;
		
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
		return new Merge(expr[LEFT].copy(), expr[RIGHT].copy(), tbfactory, getPosInfo());
	}
	
	public AtomList getAtoms(){
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
	
	public List<ATerm> getTests(){
		return new ArrayList<ATerm>(0);
	}
	
	public boolean isEnabled(){
		return state[LEFT].isEnabled() || state[RIGHT].isEnabled();
	}
	
	private void initState(){
		state[LEFT] = initialState[LEFT];
		state[RIGHT] = initialState[RIGHT];
	}
	
	public State gotoNextStateAndActivate(){
		State follow = getFollow();
		
		// System.err.println("Merge.getNextState: " + leftLast + " ; follow = " + follow);
		// System.err.println("state[LEFT] =" + state[LEFT]);
		// System.err.println("state[RIGHT] =" + state[RIGHT]);
		
		if(state[LEFT] == follow || state[RIGHT] == follow){
			// TODO put the line below in comment since it will throw an exception and X isn't used.
			// int x = 3 / 0;
		}
		
		if(leftLast){
			State ns = state[LEFT].gotoNextStateAndActivate();
			if(ns == follow){
				State r = state[RIGHT];
				// System.err.println("state[LEFT] == follow");
				// System.err.println("returning " + r);
				initState();
				return r;
			}
			// System.err.println("returning " + mergeState);
			state[LEFT] = ns;
			return mergeState;
			
		}
		
		State ns = state[RIGHT].gotoNextStateAndActivate();
		if(ns == follow){
			State l = state[LEFT];
			// System.err.println("state[RIGHT] == follow");
			// System.err.println("returning " + l);
			initState();
			return l;
		}
		
		// System.err.println("returning " + mergeState);
		state[RIGHT] = ns;
		return mergeState;
	}
	
	public State gotoNextStateAndActivate(StateElement se){
		State follow = getFollow();
		
		// System.err.println("Merge.getNextState2: " + leftLast + "; " + se + " ; follow = " +
		// follow);
		// System.err.println("state[LEFT] =" + state[LEFT]);
		// System.err.println("state[RIGHT] =" + state[RIGHT]);
		
		if(state[LEFT].contains(se)){
			State ns = state[LEFT].gotoNextStateAndActivate(se);
			if(ns == follow){
				State r = state[RIGHT];
				// System.err.println("state[LEFT] == follow");
				// System.err.println("returning " + r);
				initState();
				return r;
			}
			
			// System.err.println("returning " + mergeState);
			state[LEFT] = ns;
			return mergeState;
		}else if(state[RIGHT].contains(se)){
			State ns = state[RIGHT].gotoNextStateAndActivate(se);
			if(ns == follow){
				State l = state[LEFT];
				// System.err.println("state[RIGHT] == follow");
				// System.err.println("returning " + l);
				initState();
				return l;
			}
			
			// System.err.println("returning " + mergeState);
			state[RIGHT] = ns;
			return mergeState;
		}else{
			System.err.println("Merge.getNextState2 wrong!");
			return null;
		}
	}
	
	public void activate(){
		state[LEFT].activate();
		state[RIGHT].activate();
	}
	
	/**
	 * Generate next random boolean.
	 */
	public static boolean nextBoolean(){
		return rand.nextBoolean();
	}
	
	public boolean execute() throws ToolBusException{
		int l, r;
		if(nextBoolean()){
			l = LEFT;
			r = RIGHT;
		}else{
			l = RIGHT;
			r = LEFT;
		}
		
		if(state[l].execute()){
			leftLast = (l == LEFT);
			return true;
		}else if(state[r].execute()){
			leftLast = (r == LEFT);
			return true;
		}else return false;
	}
	
	public ProcessInstance[] debugExecute() throws ToolBusException{
		int l, r;
		if(nextBoolean()){
			l = LEFT;
			r = RIGHT;
		}else{
			l = RIGHT;
			r = LEFT;
		}
		
		ExecutionResult er; 
		if((er = state[l].debugExecute()) != null){
			leftLast = (l == LEFT);
			return er.partners;
		}else if((er = state[r].debugExecute()) != null){
			leftLast = (r == LEFT);
			return er.partners;
		}
		
		return null;
	}
	
	public String toString(){
		return "Merge(" + state[LEFT] + "; " + state[RIGHT] + ")";
	}
	
	/*public void addPartners(AtomSet s) throws ToolBusException{
		state[LEFT].addPartners(s);
		state[RIGHT].addPartners(s);
	}*/
	
	/*public void delPartners(AtomSet s) throws ToolBusException{
		state[LEFT].delPartners(s);
		state[RIGHT].delPartners(s);
	}*/
}
