package toolbus.process;

import java.util.Iterator;
import java.util.Vector;

import toolbus.ToolBusException;
import toolbus.atom.Atom;
import toolbus.atom.AtomSet;

/**
 * @author paulk, Aug 7, 2002
 */
public class LeftMerge implements ProcessExpression {
	private ProcessExpression left, right;
	private AtomSet first, follow;
	
	public LeftMerge(ProcessExpression left, ProcessExpression right) {
		this.left = left;
		this.right = right;
	}

	public void compile(ProcessInstance PI, AtomSet followSet)
		throws ToolBusException {
			
		right.compile(PI, followSet);
		left.compile(PI, null);
		
		Vector leftfirst = left.getFirst().getAtoms();

		for(Iterator it = leftfirst.iterator(); it.hasNext(); ){
			((Atom) it.next()).extendFollow(right.getFirst());
		}
			
		this.first = left.getFirst();
		this.follow = followSet;
	}

	public ProcessExpression copy() {
		return new LeftMerge(left, right);
	}

	public void extendFollow(AtomSet followSet) {
		//???
	}

	public AtomSet getFirst() {
		return first;
	}

	public AtomSet getFollow() {
		return follow;
	}

	public AtomSet getAtoms(){
		return left.getAtoms().union(right.getAtoms());
	}
}
