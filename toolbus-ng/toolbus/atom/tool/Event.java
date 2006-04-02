package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.UnconnectedToolException;
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
	
  public Event(ATerm toolId, ATermList result, TBTermFactory tbfactory, ATerm posInfo) {
  	super(tbfactory, posInfo);
	this.toolId = new Ref(toolId);
	this.result = new Ref(result);
	setAtomArgs(this.toolId, this.result);
	externalNameAsReceivedByTool = "snd-event";
  }
  
  public ProcessExpression copy(){
    Atom a = new Event(this.toolId.value, (ATermList) this.result.value, tbfactory, getPosInfo());
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    if(toolInstance == null){
		ATerm tid = getEnv().getValue((TBTermVar)toolId.value);
		if(tid == tbfactory.Undefined)
			return false;
		try { 
			toolInstance = getToolBus().getToolInstance(tid);
		} catch(UnconnectedToolException e){
			return false;
		}
    }
 
    if (toolInstance.getEventFromTool((ATermList)result.value, getEnv())){
      return true;
    } else
      return false;
    }

}