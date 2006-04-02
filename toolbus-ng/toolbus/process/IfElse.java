/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import java.util.Stack;

import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import aterm.ATerm;

public class IfElse extends ProcessExpression {
  private ATerm test;
  private ProcessExpression left;
  private ProcessExpression right;
  private Environment env;

  public IfElse(ATerm test, ProcessExpression Pthen, ProcessExpression Pelse, TBTermFactory tbfactory, ATerm posInfo) {
	super(tbfactory, posInfo);
    this.test = test;
    this.left = Pthen;
    this.right = Pelse;
  }

  public ProcessExpression copy() {
    return new IfElse(test, left.copy(), right.copy(), tbfactory, getPosInfo());
  }
  
  public void computeFirst() {
		left.computeFirst();
		right.computeFirst();
		setFirst(left.getFirst().union(right.getFirst()));
	}

	public void replaceFormals(Environment e) throws ToolBusException {
		env = e;
		left.replaceFormals(env);
		right.replaceFormals(env);
	}

  public void compile(ProcessInstance P, Stack<String> calls, State follows) throws ToolBusException {
    left.compile(P, calls, follows);
    ATerm rtest = P.getTBTermFactory().resolveVarTypes(test, env);
    left.getFirst().setTest(rtest, env);
    right.compile(P, calls, follows);

    ATerm notTest = rtest.getFactory().make("not(<term>)", rtest);

    right.getFirst().setTest(notTest, env);

    setFollow(left.getFollow().union(right.getFollow()));
    //System.err.println("rtest = " + rtest);
    //System.err.println("notTest = " + notTest);
    //System.err.println("env = " + env);
  }

  public State getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

  public String toString() {
    return "IfElse(" + test + ", " + left + ", " + right + ")";
  }
}
