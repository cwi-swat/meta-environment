/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import aterm.*;
import toolbus.*;
import toolbus.atom.*;

public class LetDefinition implements ProcessExpression {
	private ATermList formals;
	private ProcessExpression PE;

	public LetDefinition(ATermList formals, ProcessExpression PE) {
		this.formals = formals;
		this.PE = PE;
		//System.out.println("LetDefinition: " + PE);
	}
	
	public ProcessExpression copy(){
		return new LetDefinition(formals, PE.copy());
	}

	/**
	 * @see ProcessExpression#compile(AtomSet)
	 */
	public void compile(ProcessInstance P, AtomSet follows)
	throws ToolBusException
	 {
		Environment env = P.getEnv();
		env.add(formals);
		PE.compile(P, follows);
		env.delete(formals.getLength());
	}

	/**
	 * @see ProcessExpression#getFirst()
	 */
	public AtomSet getFirst() {
		return PE.getFirst();
	}

	/**
	 * @see ProcessExpression#getFollow()
	 */
	public AtomSet getFollow() {
		return PE.getFollow();
	}
	
	public void extendFollow(AtomSet f){
		PE.extendFollow(f);
	}

	/**
	 * @see ProcessExpression#getAtoms()
	 */
	public AtomSet getAtoms() {
		return PE.getAtoms();
	}

	public String toString() {
		return "LetDefinition(" + formals + ", " + PE + ")";
	}
}
