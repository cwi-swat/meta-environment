package toolbus.atom;

import toolbus.*;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import aterm.*;

/**
 * @author paulk, Aug 7, 2002
 */
abstract class ToolAtom extends Atom {
  private Ref toolarg;
  private ToolBus TB;

  public ToolAtom(ATerm trm) {
    toolarg = new Ref(trm);
    setAtomArgs(toolarg);
  }
  
  public ToolBus getTB() {
    return TB;
  }

  public ATerm getToolarg() {
    return toolarg.value;
  }

  public ToolInstance getToolInstance() throws ToolBusException {
    ToolInstance ti = getProcess().getToolInstance();
    if (ti == null) {
      throw new ToolBusException("null tool instance");
    } else {
      return ti;
    }
  }

  public ATermAppl getSubstitutedArg() throws ToolBusException {
    ATerm trm = TBTerm.substitute(toolarg.value, getEnv());
    if (trm.getType() != ATerm.APPL) {
      throw new ToolBusException("tool argument " + trm + " should be an application");
    } else
      return (ATermAppl) trm;
  }

  public void compile(ProcessInstance P, AtomSet follow) throws ToolBusException {
    super.compile(P, follow);

    TB = getProcess().getToolBus();

    if (toolarg.value.getType() != ATerm.APPL)
      throw new ToolBusException("malformed second argument");
  }

}
