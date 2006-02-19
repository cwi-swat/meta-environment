/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import java.util.Stack;

import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.atom.EndScope;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import aterm.ATermList;

public class LetDefinition extends ProcessExpression {
  private ATermList formals;
  private ProcessExpression PEinit;
  private ProcessExpression PE;

  public LetDefinition(ATermList formals, ProcessExpression PE, TBTermFactory tbfactory) {
	super(tbfactory);
    this.formals = formals;
    PEinit = PE;
    this.PE = PE;  //new Sequence(PE, new EndScope(formals, tbfactory), tbfactory);
    	      
  }

  public ProcessExpression copy() {
    return new LetDefinition(formals, PEinit.copy(), tbfactory);
  }
  
  public void computeFirst(){
 	 PE.computeFirst();
  }
  
  public void replaceFormals(Environment env) throws ToolBusException {
	    env.introduceVars(formals);
		PE.replaceFormals(env);
		env.removeBindings(formals);
	  }

  public void compile(ProcessInstance P, Stack<String> calls, Environment env, State follows) throws ToolBusException {
    env = env.copy();
    //System.err.println("LetDef.compile: " + env);
    env.introduceVars(formals);
    PE.compile(P, calls, env, follows);
    env.removeBindings(formals);
    //System.err.println("LetDef resulting env: " + env);
  }

  public State getFirst() {
    return PE.getFirst();
  }
  
  public State getStartState(){
    return PE.getStartState();
  }

  public State getFollow() {
    return PE.getFollow();
  }

  public State getAtoms() {
  	return PE.getAtoms();
  }

  public String toString() {
    return "LetDefinition(" + formals + ", " + PE + ")";
  }
}
