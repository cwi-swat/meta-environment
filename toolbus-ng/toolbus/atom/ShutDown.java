package toolbus.atom;

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
    	getToolBus().shutdown(getArgs().getFirst().toString());
    	return true;
    } else {
      return false;
    }
  }
}
