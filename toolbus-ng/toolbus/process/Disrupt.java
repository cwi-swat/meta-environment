package toolbus.process;

import java.util.*;
import java.util.Vector;

import toolbus.Environment;
import toolbus.ToolBusException;
import toolbus.atom.*;
import toolbus.State;

public class Disrupt extends ProcessExpression {
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

  public void compile(ProcessInstance P, Environment env, State follow) throws ToolBusException {
    left.compile(P, env, follow);
    right.compile(P, env, follow);
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
  
  public void replaceFormals(Environment env) throws ToolBusException{
	left.replaceFormals(env);
	right.replaceFormals(env);
  }

  public State getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }
}
