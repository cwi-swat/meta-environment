/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import java.util.*;

import toolbus.*;
import toolbus.atom.AtomSet;

import aterm.ATermList;

public class LetDefinition implements ProcessExpression {
  private ATermList formals;
  private ProcessExpression PE;

  public LetDefinition(ATermList formals, ProcessExpression PE) {
    this.formals = formals;
    this.PE = PE;
    //System.out.println("LetDefinition: " + PE);
  }

  public ProcessExpression copy() {
    return new LetDefinition(formals, PE.copy());
  }
  
  public void expand(ProcessInstance P,  Stack calls) throws ToolBusException {
    PE.expand(P, calls);
   }

  public void compile(ProcessInstance P, AtomSet follows) throws ToolBusException {
    Environment env = P.getEnv();
    env.add(formals);
    PE.compile(P, follows);
    env.delete(formals.getLength());
  }

  public AtomSet getFirst() {
    return PE.getFirst();
  }

  public AtomSet getFollow() {
    return PE.getFollow();
  }

  public void extendFollow(AtomSet f) {
    PE.extendFollow(f);
  }

  public AtomSet getAtoms() {
    return PE.getAtoms();
  }

  public String toString() {
    return "LetDefinition(" + formals + ", " + PE + ")";
  }
}
