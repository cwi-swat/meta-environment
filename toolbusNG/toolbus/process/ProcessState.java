package toolbus.process;

import toolbus.ToolBusException;
import toolbus.atom.Atom;

public interface ProcessState {

  public boolean contains(Atom a);
  public ProcessState nextState(Atom a);
  public boolean execute() throws ToolBusException;
}
