package toolbus;

import aterm.ATerm;
import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;

public interface StateElement {

  public boolean contains(StateElement a);
  public void setTest(ATerm test) throws ToolBusException;
  public ProcessInstance getProcess();
  public boolean execute() throws ToolBusException;
}
