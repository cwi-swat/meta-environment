package toolbus.process;

/**
 * @author paulk
 */
import java.util.Stack;
import toolbus.AtomList;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;

/**
 * Iteration implements the process expression P1 * P2. The current implementation does not handle
 * the following case correctly: if Test1 then P1 * if Test2 then A . B . C fi else ... fi Problem:
 * Test1 will be attached to A, but the first iteration of P1 may have modified local variables in
 * such a way that Test1 has become false. We solve this in TscriptParser by prefixing every
 * iteration with an extra tau so the test is always executed in an unmodified environment. So the
 * above example becomes: if Test1 then tau. P1 * if Test2 then A . B . C fi else ... fi and Test1
 * will be attached to tau (and is guaranteed to be still true when this branch is taken).
 */
public class Iteration extends ProcessExpression{
	private final ProcessExpression left;
	private final ProcessExpression right;
	
	public Iteration(ProcessExpression left, ProcessExpression right, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.left = left;
		this.right = right;
	}
	
	protected ProcessExpression copy(){
		return new Iteration(left.copy(), right.copy(), tbfactory, getPosInfo());
	}
	
	public String toString(){
		return "Iter(" + left.toString() + ", " + right.toString() + ")";
	}
	
	protected void computeFirst(){
		left.computeFirst();
		right.computeFirst();
		setFirst(left.getFirst().union(right.getFirst()));
	}
	
	protected void compile(ProcessInstance P, Stack<String> calls, State follow) throws ToolBusException{
		left.compile(P, calls, getFirst());
		right.compile(P, calls, follow);
		setFollow(follow);
	}
	
	protected void replaceFormals(Environment env) throws ToolBusException{
		left.replaceFormals(env);
		right.replaceFormals(env);
	}
	
	public AtomList getAtoms(){
		return left.getAtoms().union(right.getAtoms());
	}
}
