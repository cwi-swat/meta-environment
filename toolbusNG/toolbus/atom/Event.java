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
    return new Event(getToolTerm());
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;

    ToolInstance ti = getToolInstance();
    if (ti.getEventFromTool(getId(), getToolTerm(), getEnv())){
      //mr.getLeft().update(getEnv());
      return nextState();
    } else
      return false;
  }

}