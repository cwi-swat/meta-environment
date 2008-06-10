/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;

import java.util.Stack;
import toolbus.AtomSet;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import aterm.ATerm;

/**
 * IfElse is the abstract syntax operator for the if-then-else-fi operator in Tscripts. It is
 * compiled away and does not exist during execution.
 */
public class IfElse extends ProcessExpression{
	private final ATerm test;
	private final ProcessExpression left;
	private final ProcessExpression right;
	private Environment env;
	
	public IfElse(ATerm test, ProcessExpression Pthen, ProcessExpression Pelse, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.test = test;
		this.left = Pthen;
		this.right = Pelse;
	}
	
	protected ProcessExpression copy(){
		return new IfElse(test, left.copy(), right.copy(), tbfactory, getPosInfo());
	}
	
	protected void computeFirst(){
		left.computeFirst();
		right.computeFirst();
		setFirst(left.getFirst().union(right.getFirst()));
	}
	
	protected void replaceFormals(Environment e) throws ToolBusException{
		env = e;
		left.replaceFormals(env);
		right.replaceFormals(env);
	}
	
	protected void compile(ProcessInstance P, Stack<String> calls, State follows) throws ToolBusException{
		left.compile(P, calls, follows);
		left.getFirst().setTest(test, env);
		right.compile(P, calls, follows);
		
		ATerm notTest = test.getFactory().make("not(<term>)", test);
		
		right.getFirst().setTest(notTest, env);
		
		setFollow(follows);
		// System.err.println("rtest = " + rtest);
		// System.err.println("notTest = " + notTest);
		// System.err.println("env = " + env);
	}
	
	public AtomSet getAtoms(){
		return left.getAtoms().union(right.getAtoms());
	}
	
	public String toString(){
		return "IfElse(" + test + ", " + left + ", " + right + ")";
	}
}
