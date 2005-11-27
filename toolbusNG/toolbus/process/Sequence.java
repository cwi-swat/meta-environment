package toolbus.process;

/**
 * @author paulk
 */

import java.util.Stack;

import toolbus.Environment;
import toolbus.ToolBusException;
import toolbus.State;

public class Sequence extends ProcessExpression {
	private ProcessExpression left, right;

	public Sequence(ProcessExpression left, ProcessExpression right) {
		this.left = left;
		this.right = right;
	}

	public Sequence(ProcessExpression PE1, ProcessExpression PE2,
			ProcessExpression PE3) {
		this(PE1, new Sequence(PE2, PE3));
	}

	public Sequence(ProcessExpression PE1, ProcessExpression PE2,
			ProcessExpression PE3, ProcessExpression PE4) {
		this(PE1, PE2, new Sequence(PE3, PE4));
	}

	public Sequence(ProcessExpression PE1, ProcessExpression PE2,
			ProcessExpression PE3, ProcessExpression PE4, ProcessExpression PE5) {
		this(PE1, PE2, PE3, new Sequence(PE4, PE5));
	}

	public Sequence(ProcessExpression PE1, ProcessExpression PE2,
			ProcessExpression PE3, ProcessExpression PE4,
			ProcessExpression PE5, ProcessExpression PE6) {
		this(PE1, PE2, PE3, PE4, new Sequence(PE5, PE6));
	}

	public ProcessExpression copy() {
		return new Sequence(left.copy(), right.copy());
	}

	public String toString() {
		return "Seq(" + left.toString() + ", " + right.toString() + ")";
	}

//	public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
//		left.expand(P, calls);
//		right.expand(P, calls);
//		setFirst(left.getFirst());
//	}
	public void computeFirst(){
	  	left.computeFirst();
	  	right.computeFirst();
	  	setFirst(left.getFirst());
	  }	

	public void compile(ProcessInstance P, Stack calls, Environment env, State follow)
			throws ToolBusException {
		right.compile(P, calls, env, follow);
		left.compile(P, calls, env, right.getFirst());
		
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