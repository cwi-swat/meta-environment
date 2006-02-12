/*
 * Created on Jul 7, 2005
 * @author paulk
 *
 */
package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.UnconnectedToolException;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;


public class Terminate extends Atom {
	private Ref toolId;
	private Ref request;
	private ToolInstance toolInstance;
	
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

	    if(toolInstance == null){
		    ATerm tid = tbfactory.substitute(toolId.value, getEnv());
		    if(tid == tbfactory.Undefined)
				return false;
		    try {     
		    	toolInstance = getToolBus().getToolInstance(tid);
		    } catch(UnconnectedToolException e){
				return false;
			}
	    }
	    ATerm req = tbfactory.substitute(request.value, getEnv());
	    toolInstance.terminate(req);
	    return true;
	  }
}
