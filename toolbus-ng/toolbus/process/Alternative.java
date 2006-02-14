package toolbus.process;

/**
 * @author paulk
 */

import java.util.Stack;

import toolbus.Environment;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.ToolBusException;

public class Alternative extends ProcessExpression {
  private ProcessExpression left, right;

  public Alternative(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory) {
	super(tbfactory);
    this.left = left;
    this.right = right;
  }

  public ProcessExpression copy() {
    return new Alternative(left.copy(), right.copy(), tbfactory);
  }

  public String toString() {
    return "Alt(" + left.toString() + ", " + right.toString() + ")";
  }
  
 // public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
 //   left.expand(P, calls);
 //   right.expand(P, calls);
 //   setFirst(left.getFirst().union(right.getFirst()));
 //  }
  
  public void computeFirst(){
  	 left.computeFirst();
  	 right.computeFirst();
  	 setFirst(left.getFirst().union(right.getFirst()));
  }

  public void compile(ProcessInstance P, Stack<String> calls, Environment env, State follow) throws ToolBusException {
    left.compile(P, calls, env, follow);
    right.compile(P, calls, env, follow);
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
