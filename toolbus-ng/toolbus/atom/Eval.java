package toolbus.atom;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;

import aterm.ATerm;
/**
 * @author paulk, Jul 31, 2002
 */
public class Eval extends ToolAtom {

  public Eval(ATerm toolarg) {
    super(toolarg);
  }
  
  public ProcessExpression copy(){
    return new Eval(getToolTerm());
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ToolInstance ti = getToolInstance();
    ti.sndEvalToTool(getSubstitutedId(), getSubstitutedCall());
    return nextState();
  }

}
