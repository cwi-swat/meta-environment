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

/**
 * @author paulk, Aug 1, 2002
 */

public class RecVal extends Atom {
	private Ref toolId;
	private Ref result;
	private ToolInstance toolInstance;

  public RecVal(ATerm toolId, ATerm result, TBTermFactory tbfactory) {
    super(tbfactory);
	this.toolId = new Ref(toolId);
	this.result = new Ref(result);
	setAtomArgs(this.toolId, this.result);
  }
  
  public ProcessExpression copy(){
    Atom a = new RecVal(this.toolId.value, this.result.value, tbfactory);
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
		if(tid == tbfactory.Undefined)
			return false;
		try { 
			toolInstance = getToolBus().getToolInstance(tid);
		} catch(UnconnectedToolException e){
			return false;
		}	
    }
    if(toolInstance.canValue()){
    	ATerm res = tbfactory.substitute(result.value, getEnv());
    	if (toolInstance.getValueFromTool(res, getEnv())){
    		//System.err.println("RecValue.execute succeeded");	
    		return true;
    	}
    }
    return false;
  }

}