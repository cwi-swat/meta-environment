/**
 * @author paulk, Jul 24, 2002
 */
package toolbus.atom;

import toolbus.*;
import toolbus.process.ProcessInstance;

import aterm.*;

public class Create extends Atom {
	private ATerm pcall;
	private ATerm rvar;
	
	public Create(ATerm pcall, ATerm rvar)
	{
		super(pcall, rvar);
	}
	
	public Create()
	{
		super();
	}
	
	public void compile(ProcessInstance P, AtomSet follow)
	throws ToolBusException
	{
		super.compile(P, follow);
		
		ATermList args = getArgs();
		pcall = args.getFirst();
		rvar = args.getLast();
		if(pcall.getType() != ATerm.APPL)
			throw new ToolBusException("malformed first argument in create");
		if(!TBTerm.isResVar(rvar))
			throw new ToolBusException("second argument of create should be a result variable");
	}
	
	public boolean execute()
	throws ToolBusException
	{
		if(!isEnabled())
				return false;
		String name = ((ATermAppl) pcall).getName();
		ATermList cargs = ((ATermAppl) pcall).getArguments();
		ATermList evargs = (ATermList) TBTerm.eval(cargs, this.getEnv());
	
		ToolBus TB = getProcess().getToolBus();
	
		ProcessInstance P = TB.addProcess(name, evargs);
	
		getEnv().putVar(rvar, P.getProcessId());
		return true;

	}
}
