/*
 * Created on Jun 26, 2005
 */
package toolbus.atom.tool;

import java.util.Stack;

import toolbus.Functions;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolBus;
import toolbus.ToolInstanceManager;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;

/**
 * Execute a tool
 */
public class Execute extends Atom{
	private final Ref tool;
	private final Ref rvar;
	
	public Execute(ATerm tool, ATerm rvar, TBTermFactory tbfactory, ATerm posInfo){
		super(tbfactory, posInfo);
		this.tool = new Ref(tool);
		this.rvar = new Ref(rvar);
		setAtomArgs(this.tool, this.rvar);
	}
	public ProcessExpression copy(){
		Atom a = new Execute(tool.value, rvar.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		
		return a;
	}
	
	public void compile(ProcessInstance P, Stack<String> calls, State follow) throws ToolBusException{
		super.compile(P, calls, follow);
		
		if(tool.value.getType() != ATerm.APPL) throw new ToolBusException("malformed first argument in execute");
		if(!tbfactory.isResultVar(rvar.value)) throw new ToolBusException("second argument of execute should be a result variable");
		if(!Functions.compatibleTypes(tool.value, rvar.value)) throw new ToolBusException("arguments of execute should have the same (tool) type");
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		String name = ((ATermAppl) tool.value).getName();
		ToolBus toolbus = getProcess().getToolBus();
		ToolInstance toolInstance = new ToolInstance(toolbus.getToolDefinition(name), toolbus);
		ToolInstanceManager toolInstanceManager = toolbus.getToolInstanceManager();
		toolInstanceManager.addPendingTool(toolInstance);
		
		getEnv().assignVar((TBTermVar) rvar.value, toolInstance.getToolKey());
		toolInstance.executeTool();
		//LoggerFactory.log(this.getProcess().getProcessName(), "Execute " + tool.value, IToolBusLoggerConstants.TOOLCOM);
		return true;
	}
}
