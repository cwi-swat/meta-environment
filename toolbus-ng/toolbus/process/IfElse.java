/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import java.util.*;

import toolbus.Environment;
import toolbus.TBTerm;
import toolbus.ToolBusException;
import toolbus.State;

import aterm.ATerm;

public class IfElse extends ProcessExpression {
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

  public void compile(ProcessInstance P, Environment env, State follows) throws ToolBusException {
    left.compile(P, env, follows);
    ATerm rtest = TBTerm.resolveVars(test, env);
    left.getFirst().setTest(rtest, env);
    right.compile(P, env, follows);

    ATerm notTest = rtest.getFactory().make("not(<term>)", rtest);

    right.getFirst().setTest(notTest, env);

    setFollow(left.getFollow().union(right.getFollow()));
    //System.err.println("first = " + first);
    //System.err.println("follow = "+ follow);
  }
  
  public void replaceFormals(Environment env) throws ToolBusException{
	left.replaceFormals(env);
	right.replaceFormals(env);
  }

  public State getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

  public String toString() {
    return "IfElse(" + test + ", " + left + ", " + right + ")";
  }
}
