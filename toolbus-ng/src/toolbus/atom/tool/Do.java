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

/**
 * @author paulk, Aug 7, 2002
 */
public class Do extends Atom{
	private final Ref toolId;
	private final Ref request;
	
	public Do(ATerm toolId, ATerm request, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.request = new Ref(request);
		setAtomArgs(this.toolId, this.request);
		externalNameAsReceivedByTool = "rec-do";
	}
	
	public ProcessExpression copy(){
		Atom a = new Do(toolId.value, request.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		ATerm tid = getEnv().getValue((TBTermVar) toolId.value);
		if(tid == tbfactory.Undefined) return false;
		
		ToolInstance toolInstance = getToolBus().getToolInstanceManager().get(tid);
		if(toolInstance == null) return false;
		
		if(toolInstance.tryDoEval()){
			ATerm req = tbfactory.substitute(request.value, getEnv());
			if(req == null) throw new ToolBusException("Illegal do request pattern: "+request.value+".");
			
			toolInstance.sendDo(req);
			//LoggerFactory.log(this.getProcess().getProcessName(), "Do " + request.value, IToolBusLoggerConstants.TOOLCOM);
			return true;
		}
		return false;
	}
}
