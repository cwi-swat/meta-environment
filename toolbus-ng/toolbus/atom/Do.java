package toolbus.atom;

import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;

import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002
 */
public class Do extends ToolAtom {
  
  public  Do(ATerm trm){
    super(trm);
  }
  
  public ProcessExpression copy(){
    return new Do(getToolarg());
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;

    ToolInstance ti = getToolInstance();
    ti.sndDoToTool(getSubstitutedArg());
    return nextState();
  }

}
