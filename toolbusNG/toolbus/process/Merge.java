package toolbus.process;

import java.util.Stack;

import toolbus.ToolBusException;
import toolbus.atom.*;
import toolbus.atom.AtomSet;

/**
 * @author paulk, Aug 7, 2002
 */
public class Merge implements ProcessExpression, ProcessState {
  private ProcessExpression expansion;
  private ProcessExpression left;
  private ProcessExpression right;

  private AtomSet first;
  private AtomSet follow;

  private ProcessState leftState;
  private ProcessState rightState;
  private boolean side = true;

  public Merge(ProcessExpression left, ProcessExpression right) {
    this.left = left;
    this.right = right;
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    left.expand(P, calls);
    right.expand(P, calls);
    first = left.getFirst().union(right.getFirst());
  }

  public void compile(ProcessInstance processInstance, AtomSet followSet) throws ToolBusException {
    left.compile(processInstance, followSet);
    right.compile(processInstance, followSet);
    this.follow = followSet;
    leftState = left.getFirst();
    rightState = right.getFirst();
  }

  public ProcessExpression copy() {
    return new Merge(left, right);
  }

  public AtomSet getFirst() {
    return first;
  }
  
  public ProcessState getStartState(){
    return this;
  }

  public AtomSet getFollow() {
    return follow;
  }

  public AtomSet getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

  // The ProcesState interface

  public boolean contains(Atom a) {
    return leftState.contains(a) || rightState.contains(a);
  }

  public ProcessState nextState(Atom a) {
    if (leftState.contains(a)) {
      leftState = leftState.nextState(a);
      return this;
    } else if (rightState.contains(a)) {
      rightState = rightState.nextState(a);
      return this;
    } else {
      System.out.println("*** Merge.nextState: " + a + " not in prefix");
      return null;
    }
  }

  public boolean execute() throws ToolBusException {
    if (side) {
      side = !side;
      if (leftState.execute()) {
        return true;
      } else if (rightState.execute()) {
        return true;
      } else
        return false;
    } else {
      side = !side;
      if (rightState.execute()) {
        return true;
      } else if (leftState.execute()) {
        return true;
      } else
        return false;
    }
  }

}
