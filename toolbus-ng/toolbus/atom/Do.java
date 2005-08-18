package toolbus.atom;

import toolbus.TBTerm;
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
  }
  
  public ProcessExpression copy(){
    return new Do(toolId.value, request.value);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    System.err.println("DO.execute: " + this);
    System.err.println("DO.execute: env = " + getEnv());
    ATerm tid = TBTerm.substitute(toolId.value, getEnv());
    ATerm req = TBTerm.substitute(request.value, getEnv());
    ToolInstance ti = getToolBus().getToolInstance(tid);
    if(ti.sndDoToTool((ATermAppl) req)){
    	return true;
    } else {
    	return false;
    }
  }

}
