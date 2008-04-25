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

public class RecPerfStats extends Atom{
	private final Ref toolId;
	private final Ref result;
	private ToolInstance toolInstance;
	
	public RecPerfStats(ATerm toolId, ATerm result, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.result = new Ref(result);
		setAtomArgs(this.toolId, this.result);
		
		externalNameAsReceivedByTool = "rec-perf-stats";
	}
	
	public ProcessExpression copy(){
		Atom a = new RecPerfStats(this.toolId.value, this.result.value, tbfactory, getPosInfo());
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
		
		if(toolInstance.getPerformanceStats(result.value, getEnv())) return true;
		
		return false;
	}
}
