package toolbus.atom;

import toolbus.ToolBusDeathException;
import toolbus.ToolBusException;

import aterm.ATerm;

/**
 * @author paulk, Jul 26, 2002
 */
public class ShutDown extends Atom {

  public ShutDown(ATerm trm) {
    super(trm);
  }

  public ShutDown() {
    super();
  }

  public boolean execute() throws ToolBusException {
    if (isEnabled()) {
      throw new ToolBusDeathException(getArgs().getFirst().toString());
    } else {
      return false;
    }
  }
}
