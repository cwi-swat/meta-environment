package toolbus.process;

import java.util.*;
import java.util.Vector;

import toolbus.ToolBusException;
import toolbus.atom.*;

public class Disrupt extends AbstractProcessExpression {
  private ProcessExpression left, right;

  public Disrupt(ProcessExpression left, ProcessExpression right) {
    this.left = left;
    this.right = right;
  }

  public ProcessExpression copy() {
    return new Disrupt(left, right);
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    left.expand(P, calls);
    right.expand(P, calls);
    setFirst(left.getFirst().union(right.getFirst()));
  }

  public void compile(ProcessInstance P, State follow) throws ToolBusException {
    left.compile(P, follow);
    right.compile(P, follow);

    State rightFirst = right.getFirst();

    setFollow(follow);

    Vector atoms = left.getAtoms().getElementsAsVector();
    for (int i = 0; i < atoms.size(); i++) {
      Atom at = (Atom) atoms.get(i);
      if (at.getFollow().size() != 0) {
        at.addToFollow(rightFirst);
      }
    }
  }

  public State getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

}
