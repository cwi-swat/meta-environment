package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * @author paulk, Jul 31, 2002
 */
public class Eval extends Atom{
	private final Ref toolId;
	private final Ref request;
	private ToolInstance toolInstance;
	
	public Eval(ATerm toolId, ATerm request, TBTermFactory tbfactory, ATerm posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.request = new Ref(request);
		setAtomArgs(this.toolId, this.request);
		externalNameAsReceivedByTool = "rec-eval";
	}
	
	public ProcessExpression copy(){
		Atom a = new Eval(toolId.value, request.value, tbfactory, getPosInfo());
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
			if(tid == tbfactory.Undefined) return false;
			
			toolInstance = getToolBus().getToolInstanceManager().get(tid);
			if(toolInstance == null) return false;
		}
		
		if(toolInstance.tryDoEval()){
			ATerm req = tbfactory.substitute(request.value, getEnv());
			toolInstance.sendEval(req);
			//LoggerFactory.log(this.getProcess().getProcessName(), "Eval " + request.value, IToolBusLoggerConstants.TOOLCOM);
			return true;
		}
		return false;
	}
}
