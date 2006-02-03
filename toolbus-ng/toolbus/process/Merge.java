package toolbus.process;

import java.util.Stack;

import toolbus.Environment;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002
 * 
 * Merge implements the parallell composition operator ||
 * It maintains its two arguments and randomly selects in which argument the next atom will be executed.
 * When both arguments are exhausted, execution continues with the followSet of the merge.
 */
public class Merge extends ProcessExpression implements StateElement {
  private final int  LEFT = 0;
  private final int RIGHT = 1;
  private ProcessExpression[] expr = new ProcessExpression[2];
  private ProcessInstance processInstance;

  private State[] state = new State[2];
  private State[] initialState = new State[2];
  private State mergeState;
  private boolean leftLast = false;

  public Merge(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory) {
	super(tbfactory);
    expr[LEFT] = left;
    expr[RIGHT] = right;
    mergeState = new State();
    mergeState.add(this);
  }
  
  public void computeFirst(){
 	 expr[LEFT].computeFirst();
 	 expr[RIGHT].computeFirst();
 }
  
  public void compile(ProcessInstance processInstance, Stack calls, Environment env, State followSet) throws ToolBusException {
  	this.processInstance = processInstance;
  	expr[LEFT].compile(processInstance, calls, env, followSet);
  	initialState[LEFT] = state[LEFT] = expr[LEFT].getFirst();
 
  	expr[RIGHT].compile(processInstance, calls, env, followSet);
 	initialState[RIGHT] = state[RIGHT] = expr[RIGHT].getFirst();
 	setFollow(followSet);
  }
  
  public void replaceFormals(Environment env) throws ToolBusException{
	expr[LEFT].replaceFormals(env);
	expr[RIGHT].replaceFormals(env);
  }

  public ProcessExpression copy() {
    return new Merge(expr[LEFT].copy(), expr[RIGHT].copy(), tbfactory);
  }

  public State getAtoms() {
    return expr[LEFT].getAtoms().union(expr[RIGHT].getAtoms());
  }
  
  public State getFirst(){
  	return mergeState;
  }

  // Implementation of the StateElement interface

  public boolean contains(StateElement a) {
    return state[LEFT].contains(a) || state[RIGHT].contains(a);
  }

  public ProcessInstance getProcess() {
    return processInstance;
  }
  
  public void setTest(ATerm test, Environment env) throws ToolBusException {
  	state[LEFT].setTest(test, env);
  	state[RIGHT].setTest(test, env);
  }
  
  public boolean isEnabled(){
  	return state[LEFT].isEnabled() || state[RIGHT].isEnabled();
  }
  
  private void initState(){
  	state[LEFT] = initialState[LEFT];
  	state[RIGHT] = initialState[RIGHT];
  }
  
  public State getNextState(){
  	State follow = getFollow();
  	
	//System.err.println("Merge.getNextState: " + leftLast + " ; follow = " + follow);
	//System.err.println("state[LEFT] =" +  state[LEFT]);
	//System.err.println("state[RIGHT] =" +  state[RIGHT]);
	
	if(state[LEFT] == follow || state[RIGHT] == follow){
		int x = 3/0;
	}
  	
  	if(leftLast){
  		State ns = state[LEFT].getNextState();
  		if(ns == follow){
  		   State r = state[RIGHT];
  		   //System.err.println("state[LEFT] == follow");
 		   //System.err.println("returning " + r);
 		   initState();
  		   return r;
  		} else {
  			//System.err.println("returning " + mergeState);
  			state[LEFT] = ns;
  			return mergeState;
  		}
  	} else {
		State ns = state[RIGHT].getNextState();
  		if(ns == follow){
  			State l = state[LEFT];
  		   //System.err.println("state[RIGHT] == follow");
 		   //System.err.println("returning " + l);
 		   initState();
  		   return l;
  		} else {
  			//System.err.println("returning " + mergeState);
  			state[RIGHT] = ns;
  			return mergeState;
  		}
  	}
  }
  
  public State getNextState(StateElement se) {
 	State follow = getFollow();
 	
 	//System.err.println("Merge.getNextState2: " + leftLast + "; " + se + " ; follow = " + follow);
	//System.err.println("state[LEFT] =" +  state[LEFT]);
	//System.err.println("state[RIGHT] =" +  state[RIGHT]);
 	
    if(state[LEFT].contains(se)){
  		State ns = state[LEFT].getNextState(se);
  		if(ns == follow){
  			State r = state[RIGHT];
  		   //System.err.println("state[LEFT] == follow");
 		   //System.err.println("returning " + r);
 		   initState();
  		   return r;
  		} else {
  			//System.err.println("returning " + mergeState);
  			state[LEFT] = ns;
  			return mergeState;
  		}
    	
    } else if(state[RIGHT].contains(se)){
    	State ns = state[RIGHT].getNextState(se);
  		if(ns == follow){
  			State l = state[LEFT];
  		   //System.err.println("state[RIGHT] == follow");
 		   //System.err.println("returning " + l);
 		   initState();
  		   return l;
  		} else {
  			//System.err.println("returning " + mergeState);
  			state[RIGHT] = ns;
  			return mergeState;
  		}
    } else {
    	System.err.println("Merge.getNextState2 wrong!");
    	return null;
    }
  }
  
  public void activate(){
  	state[LEFT].activate();
  	state[RIGHT].activate();
  }
 
  public boolean execute() throws ToolBusException {
  	int l, r;
    if(ToolBus.nextBoolean()){
    	l = LEFT; r = RIGHT;
    } else {
    	l = RIGHT; r = LEFT;
    }

    if (state[l].execute()) {
    	leftLast = (l == LEFT);
        return true;
    } else if (state[r].execute()) {  
    	leftLast = (r == LEFT);
        return true;
    } else
        return false;
  }
  
  public String toString(){
  	return "Merge(" + state[LEFT] + "; " + state[RIGHT] + ")";
  }


}
