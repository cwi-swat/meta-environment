/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

import aterm.ATerm;

public class IfElse extends AbstractProcessExpression {
  private ATerm test;
  private ProcessExpression Pthen;
  private ProcessExpression Pelse;

  public IfElse(ATerm test, ProcessExpression Pthen, ProcessExpression Pelse) {
    this.test = test;
    this.Pthen = Pthen;
    this.Pelse = Pelse;
  }

  public ProcessExpression copy() {
    return new IfElse(test, Pthen.copy(), Pelse.copy());
  }

  public void compile(ProcessInstance P, AtomSet follows) throws ToolBusException {
    Pthen.compile(P, follows);
    Pthen.getFirst().setTest(test);
    Pelse.compile(P, follows);

    ATerm notTest = test.getFactory().make("not(<term>)", test);

    Pelse.getFirst().setTest(notTest);

    setFirst(Pthen.getFirst().union(Pelse.getFirst()));
    setFollow(Pthen.getFollow().union(Pelse.getFollow()));
    //System.out.println("first = " + first);
    //System.out.println("follow = "+ follow);
  }

  public void extendFollow(AtomSet f) {
    //System.out.println("extendFollow(" + f + ")");
    Pthen.extendFollow(f);
    Pelse.extendFollow(f);
    if (getFollow().size() == 0) {
      addToFollow(f);
    }
  }

  public AtomSet getAtoms() {
    return Pthen.getAtoms().union(Pelse.getAtoms());
  }

  public void execute() {
  }

  public String toString() {
    return "IfElse(" + test + ", " + Pthen + ", " + Pelse + ")";
  }
}
