/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import java.util.*;

import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

import aterm.ATerm;

public class IfElse extends AbstractProcessExpression {
  private ATerm test;
  private ProcessExpression left;
  private ProcessExpression right;

  public IfElse(ATerm test, ProcessExpression Pthen, ProcessExpression Pelse) {
    this.test = test;
    this.left = Pthen;
    this.right = Pelse;
  }

  public ProcessExpression copy() {
    return new IfElse(test, left.copy(), right.copy());
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    left.expand(P, calls);
    right.expand(P, calls);
    setFirst(left.getFirst().union(right.getFirst()));
  }

  public void compile(ProcessInstance P, AtomSet follows) throws ToolBusException {
    left.compile(P, follows);
    left.getFirst().setTest(test);
    right.compile(P, follows);

    ATerm notTest = test.getFactory().make("not(<term>)", test);

    right.getFirst().setTest(notTest);

    setFollow(left.getFollow().union(right.getFollow()));
    //System.out.println("first = " + first);
    //System.out.println("follow = "+ follow);
  }

  public AtomSet getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

  public void execute() {
  }

  public String toString() {
    return "IfElse(" + test + ", " + left + ", " + right + ")";
  }
}
