package toolbus.process;

import java.util.Stack;
import toolbus.AtomSet;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;

/**
 * Disrupt is the abstract syntax operator for the disrupt operator (>>) in Tscripts. It is compiled
 * away and does not exist during execution.
 */
public class Disrupt extends ProcessExpression{
	private ProcessExpression left;
	private ProcessExpression right;
	
	public Disrupt(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.left = left;
		this.right = right;
	}
	
	public ProcessExpression copy(){
		return new Disrupt(left, right, tbfactory, getPosInfo());
	}
	
	public void computeFirst(){
		left.computeFirst();
		right.computeFirst();
		setFirst(left.getFirst().union(right.getFirst()));
	}
	
	public void replaceFormals(Environment env) throws ToolBusException{
		left.replaceFormals(env);
		right.replaceFormals(env);
	}
	
	public void compile(ProcessInstance P, Stack<String> calls, State follow) throws ToolBusException{
		left.compile(P, calls, follow);
		right.compile(P, calls, follow);
		State rightFirst = right.getFirst();
		setFollow(follow);
		
		for(Atom at : left.getAtoms().getSet())
			if(at.getFollow().size() != 0){
				at.addToFollow(rightFirst);
			}
	}
	
	public AtomSet getAtoms(){
		return left.getAtoms().union(right.getAtoms());
	}
}
