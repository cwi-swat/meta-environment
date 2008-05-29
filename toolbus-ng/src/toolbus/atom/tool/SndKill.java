/*
 * Created on Jul 7, 2005 @author paulk
 */
package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

public class SndKill extends Atom{
	private final Ref toolId;
	private final Ref message;
	private ToolInstance toolInstance;
	
	public SndKill(ATerm toolId, ATerm value, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		this.message = new Ref(value);
		setAtomArgs(this.toolId);
		externalNameAsReceivedByTool = "snd-kill";
	}
	
	/**
	 * @see toolbus.process.ProcessExpression#copy()
	 */
	public ProcessExpression copy(){
		Atom a = new SndKill(toolId.value, message.value, tbfactory, getPosInfo());
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
		
		if(toolInstance.isExecutedTool()){
			toolInstance.kill();
		}else{
			LoggerFactory.log("Unable to kill tool with id: "+getEnv().getValue((TBTermVar) toolId.value)+", since it it's not a remotely executed tool.", ILogger.ERROR, IToolBusLoggerConstants.TOOLCOM);
		}
		//LoggerFactory.log(getProcess().getProcessName(), "Send kill: "+message.value, IToolBusLoggerConstants.TOOLCOM);
		return true;
	}
}
