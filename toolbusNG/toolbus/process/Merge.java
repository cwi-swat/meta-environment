package toolbus.process;

import java.util.Stack;

import toolbus.*;
import toolbus.atom.State;

/**
 * @author paulk, Aug 7, 2002
 */
public class Merge implements ProcessExpression, StateElement {
  
  private ProcessExpression expansion;
  private ProcessExpression left;
  private ProcessExpression right;

  private State first;
  private State follow;

  private State state[];
  private static final int LEFT = 0;
  private static final int RIGHT = 1;
 
  private State startState;
  private ProcessInstance processInstance;

  public Merge(ProcessExpression left, ProcessExpression right) {
    this.left = left;
    this.right = right;
    startState = new State();
    startState.add(this);
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    processInstance = P;
    left.expand(P, calls);
    right.expand(P, calls);
    first = left.getFirst().union(right.getFirst());
  }

  public void compile(ProcessInstance processInstance, State followSet) throws ToolBusException {
    left.compile(processInstance, followSet);
    right.compile(processInstance, followSet);
    this.follow = followSet;
    state = new State[] { left.getFirst(), right.getFirst()};
  }

  public ProcessExpression copy() {
    return new Merge(left, right);
  }

  public State getFirst() {
    return first;
  }

  public State getStartState() {
    return startState;
  }

  public State getFollow() {
    return follow;
  }

  public State getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

  // Implementation of the StateElement interface

  public boolean contains(StateElement a) {
    return state[LEFT].contains(a) || state[RIGHT].contains(a);
  }

  public ProcessInstance getProcess() {
    return processInstance;
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

}
