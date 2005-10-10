package toolbus.atom;

import toolbus.TBTerm;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * @author paulk, Jul 31, 2002
 */
public class AckEvent extends Atom {
	private Ref toolId;
	private Ref event;

  public AckEvent(ATerm toolId, ATerm event) {
 	super();
	this.toolId = new Ref(toolId);
	this.event = new Ref(event);
	setAtomArgs(this.toolId, this.event);
	externalNameAsReceivedByTool = "rec-ack-event";
  }
  
  public ProcessExpression copy(){
    Atom a = new AckEvent(this.toolId.value, this.event.value);
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ATerm tid = TBTerm.substitute(toolId.value, getEnv());
    ATerm ev = TBTerm.substitute(event.value, getEnv());
    ToolInstance ti = getToolBus().getToolInstance(tid);
    return ti.sndAckToTool(ev);
  }
}
