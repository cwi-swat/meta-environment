package toolbus.atom;

import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;

import aterm.ATerm;

/**
 * @author paulk, Jul 26, 2002
 */
public class ShutDown extends Atom {
  private Ref arg;

  public ShutDown(ATerm trm) {
    arg = new Ref(trm);
    setAtomArgs(arg);
  }

  public ProcessExpression copy() {
    return new ShutDown(arg.value);
  }

  public boolean execute() throws ToolBusException {
    if (isEnabled()) {
      getToolBus().shutdown(arg.value.toString());
      return true;
    } else {
      return false;
    }
  }
}
