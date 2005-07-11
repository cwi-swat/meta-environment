/*
 * Created on Jul 7, 2005
 *
 */
package toolbus.atom;

import toolbus.TBTerm;
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
public class Terminate extends Atom {
	private Ref toolId;
	private Ref request;
	
	public Terminate(ATerm toolId, ATerm request){
		this.toolId = new Ref(toolId);
		this.request = new Ref(request);
		setAtomArgs(this.toolId);
	}

	/**
	 * @see toolbus.process.ProcessExpression#copy()
	 */
	public ProcessExpression copy() {
		 return new Terminate(toolId.value, request.value);
	}
	 public boolean execute() throws ToolBusException {
	    if (!isEnabled())
	      return false;
	    ATerm tid = TBTerm.substitute(toolId.value, getEnv());
	    ATerm req = TBTerm.substitute(request.value, getEnv());
	    ToolInstance ti = getToolBus().getToolInstance(tid);
	    ti.terminate((ATermAppl) req);
	    return nextState();
	  }
}
