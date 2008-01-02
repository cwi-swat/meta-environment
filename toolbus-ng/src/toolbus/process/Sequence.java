package toolbus.process;

/**
 * @author paulk
 */

import java.util.Stack;
import toolbus.AtomSet;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;

public class Sequence extends ProcessExpression{
	private final ProcessExpression left;
	private final ProcessExpression right;
	
	public Sequence(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.left = left;
		this.right = right;
	}
	
	protected ProcessExpression copy(){
		return new Sequence(left.copy(), right.copy(), tbfactory, getPosInfo());
	}
	
	public String toString(){
		return "Seq(" + left.toString() + ", " + right.toString() + ")";
	}
	
	protected void computeFirst(){
		left.computeFirst();
		right.computeFirst();
		setFirst(left.getFirst());
	}
	
	protected void compile(ProcessInstance P, Stack<String> calls, State follow) throws ToolBusException{
		right.compile(P, calls, follow);
		left.compile(P, calls, right.getFirst());
		
		setFollow(follow);
	}
	
	protected void replaceFormals(Environment env) throws ToolBusException{
		left.replaceFormals(env);
		right.replaceFormals(env);
	}
	
	public AtomSet getAtoms(){
		return left.getAtoms().union(right.getAtoms());
	}
}
