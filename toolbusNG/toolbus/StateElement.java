package toolbus;

import toolbus.process.ProcessInstance;
import aterm.ATerm;

public interface StateElement {

  public boolean contains(StateElement a);
  public void setTest(ATerm test, Environment env) throws ToolBusException;
  public boolean isEnabled() throws ToolBusException;
  public void addPartners(State s);
  public void delPartners(State s);
  public ProcessInstance getProcess();
  public boolean execute() throws ToolBusException;
  public State getNextState();
  public State getNextState(StateElement se);
  public void activate();
}
