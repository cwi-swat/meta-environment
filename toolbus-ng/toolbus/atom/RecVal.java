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
    return new RecVal(getToolarg());
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ToolInstance ti = getToolInstance();
    if (ti.getValueFromTool(getToolarg(), getEnv())){
      return nextState();
    } else
      return false;
  }

}