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

public class Sequence extends ProcessExpression {
	private ProcessExpression left, right;

	public Sequence(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, ATerm posInfo) {
		super(tbfactory, posInfo);
		this.left = left;
		this.right = right;
	}

	public ProcessExpression copy() {
		return new Sequence(left.copy(), right.copy(), tbfactory, getPosInfo());
	}

	public String toString() {
		return "Seq(" + left.toString() + ", " + right.toString() + ")";
	}

	public void computeFirst(){
	  	left.computeFirst();
	  	right.computeFirst();
	  	setFirst(left.getFirst());
	  }	

	public void compile(ProcessInstance P, Stack<String> calls, State follow)
			throws ToolBusException {
		right.compile(P, calls, follow);
		left.compile(P, calls, right.getFirst());
		
		setFollow(follow);
	}

	public void replaceFormals(Environment env) throws ToolBusException {
		left.replaceFormals(env);
		right.replaceFormals(env);
	}

	public State getAtoms() {
		return left.getAtoms().union(right.getAtoms());
	}
}