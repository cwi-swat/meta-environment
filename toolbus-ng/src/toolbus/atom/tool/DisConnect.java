/*
 * Created on Oct 6, 2005
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

/**
 * @author paulk
 */
public class DisConnect extends Atom{
	private final Ref toolId;
	
	public DisConnect(ATerm toolId, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		setAtomArgs(this.toolId);
	}
	
	public ProcessExpression copy(){
		Atom a = new DisConnect(toolId.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		
		return a;
	}
	
	/**
	 * @see toolbus.StateElement#execute()
	 */
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		ATerm tid = getEnv().getValue((TBTermVar) toolId.value);
		if(tid == tbfactory.Undefined) return false;
		
		ToolInstance toolInstance = getToolBus().getToolInstanceManager().get(tid);
		if(toolInstance == null) return false;
		
		// If the connection is already lost don't try to terminate the connection, since it will fail.
		if(toolInstance.isKilled() || toolInstance.isUnreachable()){
			toolInstance.shutDown();
			return true;
		}
		
		if(toolInstance.isDisconnected()){
			toolInstance.shutDown();
			toolInstance.terminate();
			//LoggerFactory.log(this.getProcess().getProcessName(), "DisConnect " + toolId.value, IToolBusLoggerConstants.TOOLCOM);
			return true;
		}
		
		return false;
	}
}
