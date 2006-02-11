/*
 * Created on Jul 7, 2005
 * @author paulk
 *
 */
package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;


public class Terminate extends Atom {
	private Ref toolId;
	private Ref request;
	
	public Terminate(ATerm toolId, ATerm request, TBTermFactory tbfactory){
		super(tbfactory);
		this.toolId = new Ref(toolId);
		this.request = new Ref(request);
		setAtomArgs(this.toolId);
		externalNameAsReceivedByTool = "rec-terminate";
	}

	/**
	 * @see toolbus.process.ProcessExpression#copy()
	 */
	public ProcessExpression copy() {
		 Atom a = new Terminate(toolId.value, request.value, tbfactory);
		 a.copyAtomAttributes(this);
		 return a;
	}
	
	
	 public boolean execute() throws ToolBusException {
	    if (!isEnabled())
	      return false;
	    ATerm tid = tbfactory.substitute(toolId.value, getEnv());
	    ATerm req = tbfactory.substitute(request.value, getEnv());
	    ToolInstance ti = getToolBus().getToolInstance(tid);
	    ti.terminate(req);
	    return true;
	  }
}
