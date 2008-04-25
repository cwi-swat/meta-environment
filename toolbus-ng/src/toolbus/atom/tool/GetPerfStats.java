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

public class GetPerfStats extends Atom{
	private final Ref toolId;
	private ToolInstance toolInstance;
	
	public GetPerfStats(ATerm toolId, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		setAtomArgs(new Ref[]{this.toolId});
		externalNameAsReceivedByTool = "snd-perf-stats";
	}
	
	public ProcessExpression copy(){
		Atom a = new GetPerfStats(toolId.value, tbfactory, getPosInfo());
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
		
		if(toolInstance.tryDoEval()){
			toolInstance.sendPerformanceStatsRequest(tbfactory.makeList());
			//LoggerFactory.log(this.getProcess().getProcessName(), "Sending performace statistics request to tool: " + toolInstance.getToolKey(), IToolBusLoggerConstants.TOOLCOM);
			return true;
		}
		return false;
	}
}
