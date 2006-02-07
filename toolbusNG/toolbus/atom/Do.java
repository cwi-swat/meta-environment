package toolbus.atom;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
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
	private ToolInstance toolInstance;
  
  public  Do(ATerm toolId, ATerm request, TBTermFactory tbfactory){
    super(tbfactory);
	this.toolId = new Ref(toolId);
	this.request = new Ref(request);
	setAtomArgs(this.toolId, this.request);
	externalNameAsReceivedByTool = "rec-do";
  }
  
  public ProcessExpression copy(){
    Atom a = new Do(toolId.value, request.value, tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }
  
  public void activate(){
	  toolInstance = null;
	  super.activate();
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
 
   if(toolInstance == null){
    	ATerm tid = getEnv().getValue((TBTermVar)toolId.value);
    	toolInstance = getToolBus().getToolInstance(tid);
    }
    if(toolInstance.canEvalDo()){
    	ATerm req = tbfactory.substitute(request.value, getEnv());
    	if(toolInstance.sndDoToTool((ATermAppl) req)){
    		return true;
    	}
    }
    return false;
  }

}
