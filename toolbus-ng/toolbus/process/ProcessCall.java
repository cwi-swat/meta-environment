
/**
 * @author paulk, Jul 22, 2002
 */

package toolbus.process;
import java.util.Stack;

import toolbus.*;
import toolbus.atom.AtomSet;

import aterm.ATermList;

public class ProcessCall implements ProcessExpression {
  private String name;
  private ATermList args;
  private ProcessDefinition definition;
  private ProcessExpression PE;

  public ProcessCall(String name, ATermList args) {
    this.name = name;
    this.args = args;
    System.out.println("ProcessCall(\"" + name + "\", " + args + ")");
  }

  public ProcessExpression copy() {
    return new ProcessCall(name, args);
  }

  public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
    System.out.println("expand(" + P + "," + calls + ")");
    if (calls.contains(name)) {
      throw new ToolBusException("recursive call of " + name);
    }
    ToolBus TB = P.getToolBus();
    calls.push(name);
    definition = TB.getProcessDefinition(name);
    PE = definition.expand(P, calls, args);
    calls.pop();
  }

  public void compile(ProcessInstance P, AtomSet follows) throws ToolBusException {
    Environment env = P.getEnv();
    definition.enterScope(env);
    PE.compile(P, follows);
    definition.leaveScope(env);
  }

  public AtomSet getFirst() {
    return PE.getFirst();
  }
  
  public ProcessState getStartState(){
    return PE.getStartState();
  }

  public AtomSet getFollow() {
    return PE.getFollow();
  }

  public AtomSet getAtoms() {
    return PE.getAtoms();
  }

  public String toString() {
    return "ProcessCall(" + name + ", " + args + ")";
  }
}
