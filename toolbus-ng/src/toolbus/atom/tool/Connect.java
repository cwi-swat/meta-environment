/*
 * Created on Oct 6, 2005
 */
package toolbus.atom.tool;

import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolInstanceManager;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;

/**
 * @author paulk
 */
public class Connect extends Atom{
	private final Ref toolId;
	private final boolean followsExecute;
	
	public Connect(ATerm toolId, TBTermFactory tbfactory, ATerm posInfo, boolean followsExecute){
		super(tbfactory, posInfo);
		
		this.toolId = new Ref(toolId);
		setAtomArgs(this.toolId);
		
		this.followsExecute = followsExecute;
	}
	
	public ProcessExpression copy(){
		Atom a = new Connect(toolId.value, tbfactory, getPosInfo(), followsExecute);
		a.copyAtomAttributes(this);
		
		return a;
	}
	
	/**
	 * @see toolbus.StateElement#execute()
	 */
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		// System.err.println("Connect.execute called; toolname = " + toolId.value);
		ATerm tid = getEnv().getValue((TBTermVar) toolId.value);
		
		String toolname = ((ATermAppl) ((TBTermVar) toolId.value).getVarType()).getName();
		ToolInstanceManager toolInstanceManager = getToolBus().getToolInstanceManager();
		
		ToolInstance ti;
		if(followsExecute){
			ti = toolInstanceManager.activatePendingTool(tid);
		}else{
			ti = toolInstanceManager.activateDynamiclyConnectedTool(toolname);
		}
		if(ti == null) return false;
		
		// System.err.println(getProcess().getProcessName() + ": id = " + id);
		
		ATerm toolid = ti.getToolKey();
		getEnv().assignVar((TBTermVar) toolId.value, toolid);
		// System.err.println("Connect.execute (" + id + ") assigns: " + toolid);
		//LoggerFactory.log(this.getProcess().getProcessName(), "Connect " + toolid, IToolBusLoggerConstants.TOOLCOM);
		return true;
	}
	
}
