package toolbus.process;
/**
 * @author paulk, Jul 23, 2002
 */
import java.util.Stack;

import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

public interface ProcessExpression {
  public void expand(ProcessInstance processInstance, Stack calls) throws ToolBusException;
  public void compile(ProcessInstance processInstance, AtomSet followSet) throws ToolBusException;
  public ProcessExpression copy();
  public AtomSet getFirst();
  public AtomSet getFollow();
  public AtomSet getAtoms();
  public ProcessState getStartState();
}
