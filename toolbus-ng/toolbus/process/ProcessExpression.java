package toolbus.process;
/**
 * @author paulk, Jul 23, 2002
 */
import java.util.Stack;

import toolbus.ToolBusException;
import toolbus.atom.State;

public interface ProcessExpression {
  public void expand(ProcessInstance processInstance, Stack calls) throws ToolBusException;
  public void compile(ProcessInstance processInstance, State followSet) throws ToolBusException;
  public ProcessExpression copy();
  public State getFirst();
  public State getFollow();
  public State getAtoms();
  public State getStartState();
}
