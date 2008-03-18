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
public class Event extends Atom{
	private final Ref toolId;
	private final Ref result;
	private ToolInstance toolInstance;
	
	public Event(ATerm toolId, ATerm result, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.result = new Ref(result);
		setAtomArgs(this.toolId, this.result);
		externalNameAsReceivedByTool = "snd-event";
	}
	
	public ProcessExpression copy(){
		Atom a = new Event(toolId.value, result.value, tbfactory, getPosInfo());
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
		
		if(toolInstance.getEventFromTool(result.value, getEnv())){
			//LoggerFactory.log(this.getProcess().getProcessName(), "Event " + result.value, IToolBusLoggerConstants.TOOLCOM);
			return true;
		}
		return false;
	}
}
