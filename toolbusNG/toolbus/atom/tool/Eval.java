package toolbus.atom.tool;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolBusException;
import toolbus.UnconnectedToolException;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;
/**
 * @author paulk, Jul 31, 2002
 */
public class Eval extends Atom {
	private Ref toolId;
	private Ref request;
	private ToolInstance toolInstance;

  public Eval(ATerm toolId, ATerm request, TBTermFactory tbfactory) {
    super(tbfactory);
	this.toolId = new Ref(toolId);
	this.request = new Ref(request);
	setAtomArgs(this.toolId, this.request);
	externalNameAsReceivedByTool = "rec-eval";
  }
  
  public ProcessExpression copy(){
    Atom a = new Eval(toolId.value, request.value, tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }
  
 
  public void activate() {
	toolInstance = null;
	super.activate();
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
    if(toolInstance.canEvalDo()){
    	ATerm req = tbfactory.substitute(request.value, getEnv());
    	if(toolInstance.sndEvalToTool((ATermAppl) req)){
    		return true;
    	}
    }
    return false;
  }

}
