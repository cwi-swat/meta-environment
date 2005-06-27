/*
 * Created on Jun 27, 2005
 */
package toolbus.process;

import java.util.Stack;

import toolbus.Environment;
import toolbus.State;
import toolbus.ToolBusException;

/**
 * @author paulk
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class LeftMerge extends ProcessExpression {
	private ProcessExpression left;
	private ProcessExpression right;
	private ProcessExpression lmexpansion;
	
	LeftMerge(ProcessExpression left, ProcessExpression right){
		this.left = left;
		this.right = right;
	}
	
	public ProcessExpression copy() {
		return new LeftMerge(left, right);
	}

	public void expand(ProcessInstance processInstance, Stack calls)
			throws ToolBusException {
		left.expand(processInstance, calls);
		right.expand(processInstance, calls);
	}

	public void replaceFormals(Environment env) throws ToolBusException {
		left.replaceFormals(env);
		right.replaceFormals(env);
	}
	
	public State getAtoms(){
		return left.getAtoms().union(right.getAtoms());
	}

	public void compile(ProcessInstance processInstance, Environment env, State followSet) throws ToolBusException {
		/*
	  	lmexpansion.compile(processInstance, env, followSet);
	  	*/
	}
}
