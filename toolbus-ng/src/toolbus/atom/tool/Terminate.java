/*
 * Created on Jul 7, 2005 @author paulk
 */
package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

public class Terminate extends Atom{
	private final Ref toolId;
	private final Ref request;
	private ToolInstance toolInstance;
	
	public Terminate(ATerm toolId, ATerm request, TBTermFactory tbfactory, PositionInformation posInfo){
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
	
	public void activate(){
		toolInstance = null;
		super.activate();
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		if(toolInstance == null){
			ATerm tid = getEnv().getValue((TBTermVar) toolId.value);
			toolInstance = getToolBus().getToolInstanceManager().get(tid);
			if(toolInstance == null) return false;
		}
		
		ATerm req = tbfactory.fullSubstitute(request.value, getEnv());
		if(req == null) throw new ToolBusException("Illegal terminate request pattern: "+request.value+".");
		
		toolInstance.sendTerminate(req);
		//LoggerFactory.log(this.getProcess().getProcessName(), "Terminate " + request.value, IToolBusLoggerConstants.TOOLCOM);
		return true;
	}
}
