package toolbus.process;
/**
 * @author paulk
 */

import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

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

  public void compile(ProcessInstance P, AtomSet follow) throws ToolBusException {
    right.compile(P, follow);
    left.compile(P, right.getFirst());
    left.extendFollow(left.getFirst());
    setFirst(left.getFirst().union(right.getFirst()));
    setFollow(follow);
  }
  
  public void extendFollow(AtomSet f) {
    //left.extendFollow(f);
    right.extendFollow(f);
    if (getFollow().size() == 0) {
      addToFollow(f);
    }
  }

  public AtomSet getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

}
