/*
 * Created on Jun 26, 2005
 *
 */
package toolbus.atom;

import toolbus.Environment;
import toolbus.Functions;
import toolbus.State;
import toolbus.TBTerm;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;

/**
 * Execute a tool
 */
public class Execute extends Atom {
	private Ref tool;
	private Ref rvar;

	public Execute(ATerm tool, ATerm rvar){
		super();
		this.tool = new Ref(tool);
		this.rvar = new Ref(rvar);
		setAtomArgs(this.tool, this.rvar);
	}
	public ProcessExpression copy() {
		Atom a = new Execute(tool.value, rvar.value);
		a.copyAtomAttributes(this);
		return a;
	}
	
	public void compile(ProcessInstance P, Environment env, State follow) throws ToolBusException {
	    super.compile(P, env, follow);
	 
	    if (tool.value.getType() != ATerm.APPL)
	      throw new ToolBusException("malformed first argument in execute");
	    if (!TBTerm.isResVar(rvar.value))
	      throw new ToolBusException("second argument of execute should be a result variable");
	    if(!Functions.compatibleTypes(tool.value, rvar.value))
	      throw new ToolBusException("arguments of execute should have the same (tool) type");
	  }
	
	public boolean execute() throws ToolBusException {
	    if (!isEnabled())
	      return false;
	    String name = ((ATermAppl) tool.value).getName();
	    ToolBus TB = getProcess().getToolBus();
	    ToolInstance TI = TB.addToolInstance(name);
	    getEnv().assignVar(rvar.value, TI.getToolId());
	    System.err.println("Execute.execute: " + getEnv());
	    return true;
	  }
}
