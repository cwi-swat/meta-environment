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
    // ToolInstance ti = getTB().getTool(getEnv().getVar(getToolvar()));
    ToolInstance ti = getToolInstance();
    MatchResult mr = ti.getValueFromTool(getToolarg(), getEnv());
    if (mr.matches()) {
      mr.getLeft().update(getEnv());
      return nextState();
    } else
      return false;
  }

}