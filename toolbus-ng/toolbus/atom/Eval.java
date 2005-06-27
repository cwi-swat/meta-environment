package toolbus.atom;
import toolbus.TBTerm;
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
  }
  
  public ProcessExpression copy(){
    return new Eval(toolId.value, request.value);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    //System.err.println("Eval: " + getEnv());
    ATerm tid = TBTerm.substitute(toolId.value, getEnv());
    ATerm req = TBTerm.substitute(request.value, getEnv());
    //System.err.println("Eval: " + tid + ", " + req);
    ToolInstance ti = getToolBus().getToolInstance(tid);
    ti.sndEvalToTool((ATermAppl) req);
    return nextState();
  }

}
