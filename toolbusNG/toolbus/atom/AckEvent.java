package toolbus.atom;

import toolbus.ToolBusException;
import toolbus.process.*;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import aterm.ATerm;
/**
 * @author paulk, Jul 31, 2002
 */
public class AckEvent extends ToolAtom {

  public AckEvent(ATerm toolTerm) {
    super(toolTerm);
  }
  
  public ProcessExpression copy(){
    return new AckEvent(getToolTerm());
  }

  public void compile(ProcessInstance P, State follow) throws ToolBusException {
    super.compile(P, follow);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;

    ToolInstance ti = getToolInstance();

    ti.sndAckToTool(getSubstitutedId(), getSubstitutedCall());
    return nextState();
  }
}
