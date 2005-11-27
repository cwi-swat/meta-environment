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
    super();
    arg = new Ref(trm);
    setAtomArgs(arg);
  }

  public ProcessExpression copy() {
    Atom a = new ShutDown(arg.value);
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (isEnabled()) {
      getToolBus().shutdown(arg.value);
      return true;
    } else {
      return false;
    }
  }
}
