package toolbus.process;

/**
 * @author paulk
 */

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

  public void compile(ProcessInstance P, AtomSet follow) throws ToolBusException {
    left.compile(P, follow);
    right.compile(P, follow);
    setFirst(left.getFirst().union(right.getFirst()));
    setFollow(follow);
  }
  
  public void extendFollow(AtomSet f) {
    left.extendFollow(f);
    right.extendFollow(f);
    if (getFollow().size() == 0) {
      addToFollow(f);
    }
  }

  public AtomSet getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

}
