/*
 * Created on Jun 26, 2005
 *
 */
package toolbus.atom.tool;

import java.util.Stack;

import toolbus.Functions;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolBus;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
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

	public Execute(ATerm tool, ATerm rvar, TBTermFactory tbfactory){
		super(tbfactory);
		this.tool = new Ref(tool);
		this.rvar = new Ref(rvar);
		setAtomArgs(this.tool, this.rvar);
	}
	public ProcessExpression copy() {
		Atom a = new Execute(tool.value, rvar.value, tbfactory);
		a.copyAtomAttributes(this);
		return a;
	}
	
	public void compile(ProcessInstance P, Stack<String> calls, Environment env, State follow) throws ToolBusException {
	    super.compile(P, calls, env, follow);
	 
	    if (tool.value.getType() != ATerm.APPL)
	      throw new ToolBusException("malformed first argument in execute");
	    if (!tbfactory.isResultVar(rvar.value))
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
	
	    getEnv().assignVar((TBTermVar)rvar.value, TI.getToolId());
	    
	    //System.err.println("Execute.execute: " + getEnv());
	    return true;
	  }
}
