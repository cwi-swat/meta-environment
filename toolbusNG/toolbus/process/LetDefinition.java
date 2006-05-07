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
import aterm.ATerm;
import aterm.ATermList;

public class LetDefinition extends ProcessExpression {
  private ATermList locals;
  private ProcessExpression PEinit;
  private ProcessExpression PE;
  private Environment env;

  public LetDefinition(ATermList formals, ProcessExpression PE, TBTermFactory tbfactory, ATerm posInfo) {
	super(tbfactory, posInfo);
    this.locals = formals;
    PEinit = PE;
    this.PE = PE;  //new Sequence(PE, new EndScope(formals, tbfactory), tbfactory);
    	      
  }

  public ProcessExpression copy() {
    return new LetDefinition(locals, PEinit.copy(), tbfactory, getPosInfo());
  }
  
  public void computeFirst(){
 	 PE.computeFirst();
  }
  
  public void replaceFormals(Environment e) throws ToolBusException {
	  env = e.copy();
	  env.introduceVars(locals);
	  PE.replaceFormals(env);
	  //env.removeBindings(formals);
	  }

  public void compile(ProcessInstance P, Stack<String> calls, State follows) throws ToolBusException {
    //System.err.println("LetDef.compile: " + env);
    env.introduceVars(locals);
    PE.compile(P, calls, follows);
    env.removeBindings(locals);
    //System.err.println("LetDef resulting env: " + env);
  }

  public State getFirst() {
    return PE.getFirst();
  }
  
 // public State getStartState(){
 //   return PE.getStartState();
 // }

  public State getFollow() {
    return PE.getFollow();
  }

  public AtomSet getAtoms() {
  	return PE.getAtoms();
  }

  public String toString() {
    return "LetDefinition(" + locals + ", " + PE + ")";
  }
}
