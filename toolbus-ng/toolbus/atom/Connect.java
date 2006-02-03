/*
 * Created on Oct 6, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package toolbus.atom;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;

/**
 * @author paulk
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class Connect extends Atom {
	private Ref toolId;
	
	public  Connect(ATerm toolId, TBTermFactory tbfactory){
	    super(tbfactory);
		this.toolId = new Ref(toolId);
		setAtomArgs(this.toolId);
	  }
	  
	  public ProcessExpression copy(){
	    Atom a = new Connect(toolId.value, tbfactory);
	    a.copyAtomAttributes(this);
	    return a;
	  }

	/* (non-Javadoc)
	 * @see toolbus.StateElement#execute()
	 */
	public boolean execute() throws ToolBusException {
		if (!isEnabled())
		      return false;
		//System.err.println("Connect.execute called; toolname = " + ((ATermAppl) TBTerm.getVarType(toolId.value)).getName());
		ToolInstance ti = getToolBus().getConnectedTool(((ATermAppl) ((TBTermVar)toolId.value).getVarType()).getName());
		if(ti == null){
			return false;
		} else {
			ATerm toolid = ti.getToolId();
			getEnv().assignVar((TBTermVar)toolId.value, toolid);
			//System.err.println("Connect.execute assigns: " + toolid);
			return true;
		}
	}

}
