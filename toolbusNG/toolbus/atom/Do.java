package toolbus.atom;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;

/**
 * @author paulk, Aug 7, 2002
 */
public class Do extends Atom {
	private Ref toolId;
	private Ref request;
  
  public  Do(ATerm toolId, ATerm request){
    super();
	this.toolId = new Ref(toolId);
	this.request = new Ref(request);
	setAtomArgs(this.toolId, this.request);
	externalNameAsReceivedByTool = "rec-do";
  }
  
  public ProcessExpression copy(){
    Atom a = new Do(toolId.value, request.value);
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    //System.err.println("DO.execute: " + this);
    //System.err.println("DO.execute: env = " + getEnv());
    ATerm tid = TBTermFactory.substitute(toolId.value, getEnv());
    ATerm req = TBTermFactory.substitute(request.value, getEnv());
    //System.err.println("req = " + req);
    ToolInstance ti = getToolBus().getToolInstance(tid);
    if(ti.sndDoToTool((ATermAppl) req)){
    	return true;
    } else {
    	return false;
    }
  }

}
