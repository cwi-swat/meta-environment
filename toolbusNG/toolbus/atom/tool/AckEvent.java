package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.UnconnectedToolException;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * @author paulk, Jul 31, 2002
 */
public class AckEvent extends Atom {
	private Ref toolId;
	private Ref event;
	private ToolInstance toolInstance;

  public AckEvent(ATerm toolId, ATerm event, TBTermFactory tbfactory) {
 	super(tbfactory);
	this.toolId = new Ref(toolId);
	this.event = new Ref(event);
	setAtomArgs(this.toolId, this.event);
	externalNameAsReceivedByTool = "rec-ack-event";
  }
  
  public ProcessExpression copy(){
    Atom a = new AckEvent(this.toolId.value, this.event.value, tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    if(toolInstance == null){
    	ATerm tid = tbfactory.substitute(toolId.value, getEnv());
    	if(tid == tbfactory.Undefined)
			return false;
    	try { 
		   toolInstance = getToolBus().getToolInstance(tid);
    	} catch(UnconnectedToolException e){
    		return false;
    	}
    }
   	ATerm ev = tbfactory.substitute(event.value, getEnv());
	return toolInstance.sndAckToTool(ev);
  }
}
