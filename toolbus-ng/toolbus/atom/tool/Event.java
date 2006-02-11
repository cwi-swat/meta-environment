package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
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
	private ToolInstance toolInstance;
	
  public Event(ATerm toolId, ATermList result, TBTermFactory tbfactory) {
  	super(tbfactory);
	this.toolId = new Ref(toolId);
	this.result = new Ref(result);
	setAtomArgs(this.toolId, this.result);
	externalNameAsReceivedByTool = "snd-event";
  }
  
  public ProcessExpression copy(){
    Atom a = new Event(this.toolId.value, (ATermList) this.result.value, tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    if(toolInstance == null){
		ATerm tid = getEnv().getValue((TBTermVar)toolId.value);
		toolInstance = getToolBus().getToolInstance(tid);
    }
 
    if (toolInstance.getEventFromTool((ATermList)result.value, getEnv())){
      return true;
    } else
      return false;
    }

}