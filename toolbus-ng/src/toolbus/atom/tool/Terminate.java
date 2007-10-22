/*
 * Created on Jul 7, 2005 @author paulk
 */
package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

public class Terminate extends Atom{
	private final Ref toolId;
	private final Ref request;
	
	public Terminate(ATerm toolId, ATerm request, TBTermFactory tbfactory, ATerm posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.request = new Ref(request);
		setAtomArgs(this.toolId);
		externalNameAsReceivedByTool = "rec-terminate";
	}
	
	/**
	 * @see toolbus.process.ProcessExpression#copy()
	 */
	public ProcessExpression copy(){
		Atom a = new Terminate(toolId.value, request.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		ATerm tid = tbfactory.substitute(toolId.value, getEnv());
		if(tid == tbfactory.Undefined) return false;
		
		ToolInstance toolInstance = getToolBus().getToolInstanceManager().get(tid);
		if(toolInstance == null) return false;
		
		ATerm req = tbfactory.substitute(request.value, getEnv());
		toolInstance.sendTerminate(req);
		//LoggerFactory.log(this.getProcess().getProcessName(), "Terminate " + request.value, IToolBusLoggerConstants.TOOLCOM);
		return true;
	}
}
