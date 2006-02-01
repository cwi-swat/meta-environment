package toolbus.atom;
import toolbus.TBTermFactory;
import toolbus.ToolBusException;
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

  public Eval(ATerm toolId, ATerm request) {
    super();
	this.toolId = new Ref(toolId);
	this.request = new Ref(request);
	setAtomArgs(this.toolId, this.request);
	externalNameAsReceivedByTool = "rec-eval";
  }
  
  public ProcessExpression copy(){
    Atom a = new Eval(toolId.value, request.value);
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    //System.err.println("Eval: " + getEnv());
    ATerm tid = TBTermFactory.substitute(toolId.value, getEnv());
    ATerm req = TBTermFactory.substitute(request.value, getEnv());
    //System.err.println("Eval: " + tid + ", " + req);
    ToolInstance ti = getToolBus().getToolInstance(tid);
    if(ti.sndEvalToTool((ATermAppl) req)) {
    	return true;
    } else {
    	return false;
    }
  }

}
