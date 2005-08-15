package toolbus;

import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;
import aterm.*;

public interface StateElement {

  public boolean contains(StateElement a);
  public void setTest(ATerm test, Environment env) throws ToolBusException;
  public boolean isEnabled() throws ToolBusException;
  public ProcessInstance getProcess();
  public boolean execute() throws ToolBusException;
  public State getNextState();
  public State getNextState(StateElement se);
}
