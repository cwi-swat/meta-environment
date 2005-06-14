/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import java.util.*;

import toolbus.TBTerm;
import toolbus.ToolBusException;
import toolbus.State;

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

  public void compile(ProcessInstance P, State follows) throws ToolBusException {
    left.compile(P, follows);
    //ATerm rtest = TBTerm.resolveVars(test, P.getEnv());
    left.getFirst().setTest(test);
    right.compile(P, follows);

    ATerm notTest = test.getFactory().make("not(<term>)", test);

    right.getFirst().setTest(notTest);

    setFollow(left.getFollow().union(right.getFollow()));
    //System.err.println("first = " + first);
    //System.err.println("follow = "+ follow);
  }

  public State getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

  public String toString() {
    return "IfElse(" + test + ", " + left + ", " + right + ")";
  }
}
