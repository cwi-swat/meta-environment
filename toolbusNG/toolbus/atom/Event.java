package toolbus.atom;

import toolbus.*;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;

import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002
 */

public class Event extends ToolAtom {

  public Event(ATerm toolarg) {
    super(toolarg);
  }
  
  public ProcessExpression copy(){
    return new Event(getToolarg());
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;

    ToolInstance ti = getToolInstance();
    MatchResult mr = ti.getEventFromTool(getToolarg(), getEnv());
    if (mr.matches()) {
      mr.getLeft().update(getEnv());
      return true;
    } else
      return false;
  }

}