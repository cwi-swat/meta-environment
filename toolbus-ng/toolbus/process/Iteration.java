package toolbus.process;
/**
 * @author paulk
 */

import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

public class Iteration implements ProcessExpression {
	private ProcessExpression left, right;
	private AtomSet first, follow;
	
	public Iteration(ProcessExpression left, ProcessExpression right){
		this.left = left;
		this.right = right;
	}
	
	public ProcessExpression copy(){
		return new Iteration(left.copy(), right.copy());
	}
	
	public String toString(){
		return "Iter(" + left.toString() + ", " + right.toString() + ")";
	}
	
	public void compile(ProcessInstance P, AtomSet follow)
	throws ToolBusException
	{	
		right.compile(P, follow);
		left.compile(P, right.getFirst());
		left.extendFollow(left.getFirst());
		this.first = left.getFirst().union(right.getFirst());
		this.follow = follow;
	}
	public AtomSet getFirst(){
		return first;
	}
	public AtomSet getFollow(){
		return follow;
	}
	
	public void extendFollow(AtomSet f){
		//left.extendFollow(f);
		right.extendFollow(f);
		if(follow.size() == 0)
			follow = follow.union(f);
	}
	
	public AtomSet getAtoms(){
		return left.getAtoms().union(right.getAtoms());
	}
	
}
