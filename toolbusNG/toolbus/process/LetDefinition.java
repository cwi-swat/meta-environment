/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import java.util.*;

import toolbus.*;
import toolbus.atom.State;

import aterm.ATermList;

public class LetDefinition implements ProcessExpression {
  private ATermList formals;
  private ProcessExpression PE;

  public LetDefinition(ATermList formals, ProcessExpression PE) {
    this.formals = formals;
    this.PE = PE;
    //System.err.println("LetDefinition: " + PE);
  }

  public ProcessExpression copy() {
    return new LetDefinition(formals, PE.copy());
  }
  
  public void expand(ProcessInstance P,  Stack calls) throws ToolBusException {
    PE.expand(P, calls);
   }

  public void compile(ProcessInstance P, State follows) throws ToolBusException {
    Environment env = P.getEnv();
    env.introduceVars(formals);
    PE.compile(P, follows);
    env.removeVars(formals.getLength());
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
