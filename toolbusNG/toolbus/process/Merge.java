package toolbus.process;

/*** Outdated ***/

import java.util.Stack;

import toolbus.Environment;
import toolbus.State;
import toolbus.StateElement;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002
 */
public class Merge extends ProcessExpression {
  
  private ProcessExpression lmexpansion;
  private ProcessExpression left;
  private ProcessExpression right;

  public Merge(ProcessExpression left, ProcessExpression right) {
    this.left = left;
    this.right = right;
    lmexpansion = new Alternative(new LeftMerge(left, right), new LeftMerge(right, left));
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
   lmexpansion.expand(P, calls);
  }

  public void compile(ProcessInstance processInstance, Environment env, State followSet) throws ToolBusException {
  	lmexpansion.compile(processInstance, env, followSet);
  }
  
  public void replaceFormals(Environment env) throws ToolBusException{
	lmexpansion.replaceFormals(env);
  }

  public ProcessExpression copy() {
    return new Merge(left, right);
  }

  public State getAtoms() {
    return lmexpansion.getAtoms();
  }
  
  /*

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

  public boolean execute() throws ToolBusException {
    int l, r;
    if(ToolBus.nextBoolean()){
      l = LEFT; r = RIGHT;
    } else {
      l = RIGHT; r = LEFT;
    }

    if (state[l].execute()) {
      state[l] = processInstance.getCurrentState();
      processInstance.setCurrentState(startState);
      return true;
    } else if (state[r].execute()) {
      state[r] = processInstance.getCurrentState();
      processInstance.setCurrentState(startState);
      return true;
    } else
      return false;
  }
*/
}
