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
import aterm.ATermList;

public class LetDefinition extends ProcessExpression{
	private final ATermList locals;
	private final ProcessExpression PEinit;
	private final ProcessExpression PE;
	private Environment env;
	
	public LetDefinition(ATermList locals, ProcessExpression PE, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.locals = locals;
		PEinit = PE;
		this.PE = PE;
	}
	
	protected ProcessExpression copy(){
		return new LetDefinition(locals, PEinit.copy(), tbfactory, getPosInfo());
	}
	
	protected void computeFirst(){
		PE.computeFirst();
	}
	
	protected void replaceFormals(Environment e) throws ToolBusException{
		env = e.copy();
		env.introduceVars(locals);
		PE.replaceFormals(env);
		// env.removeBindings(formals);
	}
	
	protected void compile(ProcessInstance P, Stack<String> calls, State follows) throws ToolBusException{
		// System.err.println("LetDef.compile: " + env);
		env.introduceVars(locals);
		PE.compile(P, calls, follows);
		env.removeBindings(locals);
		// System.err.println("LetDef resulting env: " + env);
	}
	
	public State getFirst(){
		return PE.getFirst();
	}
	
	public State getFollow(){
		return PE.getFollow();
	}
	
	public AtomSet getAtoms(){
		return PE.getAtoms();
	}
	
	public String toString(){
		return "LetDefinition(" + locals + ", " + PE + ")";
	}
}
