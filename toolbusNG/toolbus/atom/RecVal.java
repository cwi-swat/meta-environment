package toolbus.atom;
import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * @author paulk, Aug 1, 2002
 */

public class RecVal extends Atom {
	private Ref toolId;
	private Ref result;

  public RecVal(ATerm toolId, ATerm result) {
    super();
	this.toolId = new Ref(toolId);
	this.result = new Ref(result);
	setAtomArgs(this.toolId, this.result);
  }
  
  public ProcessExpression copy(){
    Atom a = new RecVal(this.toolId.value, this.result.value);
    a.copyAtomAttributes(this);
    return a;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ATerm tid = TBTermFactory.substitute(toolId.value, getEnv());
    ToolInstance ti = getToolBus().getToolInstance(tid);
    ATerm res = TBTermFactory.substitute(result.value, getEnv());
    if (ti.getValueFromTool(res, getEnv())){
    	//System.err.println("RecValue.execute succeeded");	
      return true;
    } else
      return false;
  }

}