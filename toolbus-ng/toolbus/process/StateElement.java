package toolbus.process;

import toolbus.ToolBusException;

public interface StateElement {

  public boolean contains(StateElement a);
  public ProcessInstance getProcess();
  //public boolean nextState();
  public boolean execute() throws ToolBusException;
}
