package toolbus.process;

/**
 * @author paulk
 */

import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

public class Alternative implements ProcessExpression {
  private ProcessExpression left, right;
  private AtomSet first, follow;

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
    this.first = left.getFirst().union(right.getFirst());
    this.follow = follow;
  }
  public AtomSet getFirst() {
    return first;
  }
  public AtomSet getFollow() {
    return follow;
  }

  public void extendFollow(AtomSet f) {
    left.extendFollow(f);
    right.extendFollow(f);
    if (follow.size() == 0)
      this.follow = follow.union(f);
  }

  public AtomSet getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }
}
