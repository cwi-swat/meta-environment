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
 * @author paulk, Aug 1, 2002
 */
public class RecVal extends Atom{
	private final Ref toolId;
	private final Ref result;
	
	public RecVal(ATerm toolId, ATerm result, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.result = new Ref(result);
		setAtomArgs(this.toolId, this.result);
	}
	
	public ProcessExpression copy(){
		Atom a = new RecVal(this.toolId.value, this.result.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		ATerm tid = getEnv().getValue((TBTermVar) toolId.value);
		if(tid == tbfactory.Undefined) return false;
		
		ToolInstance toolInstance = getToolBus().getToolInstanceManager().get(tid);
		if(toolInstance == null) return false;
		
		if(toolInstance.getValueFromTool(result.value, getEnv())){
			//LoggerFactory.log(this.getProcess().getProcessName(), "RecVal " + res, IToolBusLoggerConstants.TOOLCOM);
			// LoggerFactory.log(this.getProcess().getProcessName(), "RecVal " + res,
			// IToolBusLoggerConstants.TOOLCOM);
			// LoggerFactory.log(this.getProcess().getProcessName(), "RecVal " + getEnv(),
			// IToolBusLoggerConstants.TOOLCOM);
			
			return true;
			}
		return false;
	}
}
