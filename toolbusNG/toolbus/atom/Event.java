package toolbus.atom;

import toolbus.TBTerm;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002
 */

public class Event extends Atom {
	private Ref toolId;
	private Ref result;
	
  public Event(ATerm toolId, ATerm result) {
  	super();
	this.toolId = new Ref(toolId);
	this.result = new Ref(result);
	setAtomArgs(this.toolId, this.result);
  }
  
  public ProcessExpression copy(){
    return new Event(this.toolId.value, this.result.value);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ATerm tid = TBTerm.substitute(toolId.value, getEnv());
    ToolInstance ti = getToolBus().getToolInstance(tid);
 
    if (ti.getEventFromTool(result.value, getEnv())){
      return true;
    } else
      return false;
  }

}