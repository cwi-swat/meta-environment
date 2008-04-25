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

public class RecRequest extends Atom{
	private final Ref toolId;
	private final Ref request;
	private ToolInstance toolInstance;
	
	public RecRequest(ATerm toolId, ATerm request, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.request = new Ref(request);
		setAtomArgs(this.toolId, this.request);
		externalNameAsReceivedByTool = "snd-request";
	}
	
	public ProcessExpression copy(){
		Atom a = new RecRequest(toolId.value, request.value, tbfactory, getPosInfo());
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
		
		return toolInstance.getRequestFromTool(request.value, getEnv());
	}
}
