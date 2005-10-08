package toolbus.atom;

import toolbus.TBTerm;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermList;

/**
 * @author paulk, Aug 7, 2002
 */

public class Event extends Atom {
	private Ref toolId;
	private Ref result;
	
  public Event(ATerm toolId, ATermList result) {
  	super();
	this.toolId = new Ref(toolId);
	this.result = new Ref(result);
	setAtomArgs(this.toolId, this.result);
  }
  
  public ProcessExpression copy(){
    Atom a = new Event(this.toolId.value, (ATermList) this.result.value);
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ATerm tid = TBTerm.substitute(toolId.value, getEnv());
    ToolInstance ti = getToolBus().getToolInstance(tid);
 
    if (ti.getEventFromTool((ATermList)result.value, getEnv())){
      return true;
    } else
      return false;
  }

}