package toolbus.process;

import java.util.Stack;

import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

/**
 * @author paulk, Aug 7, 2002
 */
public class Merge implements ProcessExpression {
  ProcessExpression expansion;
  ProcessExpression left;
  ProcessExpression right;

  public Merge(ProcessExpression left, ProcessExpression right) {
    this.left = left;
    this.right = right;
    expansion = new Alternative(new LeftMerge(left, right), new LeftMerge(right, left));
  }

 public void expand(ProcessInstance P,  Stack calls) throws ToolBusException {
    left.expand(P, calls);
    right.expand(P, calls);
   }
 
  public void compile(ProcessInstance processInstance, AtomSet followSet) throws ToolBusException {
    expansion.compile(processInstance, followSet);
  }

  public ProcessExpression copy() {
    return new Merge(left, right);
  }

  public AtomSet getFirst() {
    return expansion.getFirst();
  }

  public AtomSet getFollow() {
    return expansion.getFollow();
  }

//  public void extendFollow(AtomSet followSet) {
//    expansion.extendFollow(followSet);
//  }

  public AtomSet getAtoms() {
    return expansion.getAtoms();
  }

}
