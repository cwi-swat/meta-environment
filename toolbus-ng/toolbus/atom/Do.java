package toolbus.atom;

import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002
 */
public class Do extends ToolAtom {

  public Do(ATerm toolarg) {
    super(toolarg);
  }

  public Do() {
    super();
  }

  public void compile(ProcessInstance P, AtomSet follow) throws ToolBusException {
    super.compile(P, follow);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;

    ToolInstance ti = getToolInstance();
    ti.sndDoToTool(getSubstitutedArg());
    return true;
  }

}
