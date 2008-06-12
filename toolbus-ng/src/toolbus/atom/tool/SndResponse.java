package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.ToolBusExecutionException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

public class SndResponse extends Atom{
	private final Ref toolId;
	private final Ref response;
	private ToolInstance toolInstance;
	
	public SndResponse(ATerm toolId, ATerm response, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.response = new Ref(response);
		setAtomArgs(new Ref[]{this.toolId, this.response});
		externalNameAsReceivedByTool = "rec-response";
	}
	
	public ProcessExpression copy(){
		Atom a = new SndResponse(toolId.value, response.value, tbfactory, getPosInfo());
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
		
		ATerm responseTerm = tbfactory.fullSubstitute(response.value, getEnv());
		if(responseTerm == null) throw new ToolBusExecutionException("Illegal response term pattern: "+responseTerm+".", getPosInfo());
		
		toolInstance.sendResponse(responseTerm);
		
		return true;
	}
}
