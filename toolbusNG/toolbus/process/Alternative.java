package toolbus.process;

/**
 * @author paulk
 */

import java.util.*;

import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

public class Alternative extends AbstractProcessExpression {
  private ProcessExpression left, right;

  public Alternative(ProcessExpression left, ProcessExpression right) {
    this.left = left;
    this.right = right;
  }

  public ProcessExpression copy() {
    return new Alternative(left.copy(), right.copy());
  }

  public String toString() {
    return "Alt(" + left.toString() + ", " + right.toString() + ")";
  }
  
  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    left.expand(P, calls);
    right.expand(P, calls);
    setFirst(left.getFirst().union(right.getFirst()));
   }

  public void compile(ProcessInstance P, AtomSet follow) throws ToolBusException {
    left.compile(P, follow);
    right.compile(P, follow);
    setFollow(follow);
  }

  public AtomSet getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

}
