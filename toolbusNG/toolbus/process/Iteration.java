package toolbus.process;
/**
 * @author paulk
 */

import java.util.Stack;

import aterm.ATerm;

import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;

public class Iteration extends ProcessExpression {
  private ProcessExpression left, right;

  public Iteration(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, ATerm posInfo) {
	super(tbfactory, posInfo);
    this.left = left;
    this.right = right;
  }

  public ProcessExpression copy() {
    return new Iteration(left.copy(), right.copy(), tbfactory, getPosInfo());
  }

  public String toString() {
    return "Iter(" + left.toString() + ", " + right.toString() + ")";
  }

 // public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
  //  left.expand(P, calls);
 //   right.expand(P, calls);
  //  setFirst(left.getFirst().union(right.getFirst()));
 // }
  
  public void computeFirst(){
 	 left.computeFirst();
 	 right.computeFirst();
 	 setFirst(left.getFirst().union(right.getFirst()));
 }

  public void compile(ProcessInstance P, Stack<String> calls, State follow) throws ToolBusException {
    left.compile(P, calls, getFirst());
    right.compile(P, calls, follow);
 
    setFollow(follow);
  }
  
  public void replaceFormals(Environment env) throws ToolBusException{
	left.replaceFormals(env);
	right.replaceFormals(env);
  }

  public State getAtoms() {
    return left.getAtoms().union(right.getAtoms());
  }

}
