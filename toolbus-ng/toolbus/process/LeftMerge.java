package toolbus.process;

import java.util.*;

import toolbus.ToolBusException;
import toolbus.atom.*;

/**
 * @author paulk, Aug 7, 2002
 */
public class LeftMerge extends AbstractProcessExpression {
  private ProcessExpression left, right;

  public LeftMerge(ProcessExpression left, ProcessExpression right) {
    this.left = left;
    this.right = right;
  }

  public void compile(ProcessInstance PI, AtomSet followSet) throws ToolBusException {

    right.compile(PI, followSet);
    left.compile(PI, null);

    Vector leftfirst = left.getFirst().getAtomsAsVector();

    for (Iterator it = leftfirst.iterator(); it.hasNext();) {
      ((Atom) it.next()).extendFollow(right.getFirst());
    }

    setFirst(left.getFirst());
    setFollow(followSet);
  }

  public ProcessExpression copy() {
    return new LeftMerge(left, right);
  }

  public void extendFollow(AtomSet followSet) {
    //???
  }

  public AtomSet getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }
}
