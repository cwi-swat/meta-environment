package toolbus.atom;
import toolbus.*;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;

import aterm.ATerm;

/**
 * @author paulk, Aug 1, 2002
 */

public class RecVal extends ToolAtom {

  public RecVal(ATerm toolarg) {
    super(toolarg);
  }
  
  public ProcessExpression copy(){
    return new RecVal(getToolTerm());
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ToolInstance ti = getToolInstance();
    if (ti.getValueFromTool(getSubstitutedId(), getToolTerm(), getEnv())){
      return nextState();
    } else
      return false;
  }

}