package toolbus.process;
/**
 * @author paulk
 */

import java.util.*;

import toolbus.ToolBusException;
import toolbus.atom.State;

public class Iteration extends AbstractProcessExpression {
  private ProcessExpression left, right;

  public Iteration(ProcessExpression left, ProcessExpression right) {
    this.left = left;
    this.right = right;
  }

  public ProcessExpression copy() {
    return new Iteration(left.copy(), right.copy());
  }

  public String toString() {
    return "Iter(" + left.toString() + ", " + right.toString() + ")";
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    left.expand(P, calls);
    right.expand(P, calls);
    setFirst(left.getFirst().union(right.getFirst()));
  }

  public void compile(ProcessInstance P, State follow) throws ToolBusException {

    left.compile(P, getFirst());
    right.compile(P, follow);

    setFollow(follow);
  }

  public State getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

}
