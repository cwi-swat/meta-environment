package toolbus.atom;

import aterm.*;
import toolbus.process.*;
import toolbus.tool.*;
import toolbus.*;

/**
 * @author paulk, Jul 29, 2002
 */
public class Execute extends Atom {
	private ATerm toolcall;
	private ATerm rvar;

	public Execute(ATerm tcall, ATerm rvar) {
		super(tcall, rvar);
	}
	
	public Execute() {
		super();
	}
	
	public void compile(ProcessInstance P, AtomSet follow)
	throws ToolBusException
	{
		super.compile(P, follow);
		
		ATermList args = this.getArgs();
		toolcall = args.getFirst();
		rvar = args.getLast();
		if(toolcall.getType() != ATerm.APPL)
			throw new ToolBusException("malformed first argument in execute");
		if(!TBTerm.isResVar(rvar))
			throw new ToolBusException("second argument of execute should be a result variable");
	}

	public boolean execute()
	throws ToolBusException
	{
      if (super.execute()) {
		String toolname = ((ATermAppl) toolcall).getName();
		ATermList cargs = ((ATermAppl) toolcall).getArguments();
		ATermList evargs = (ATermList) TBTerm.eval(cargs, this.getEnv());

		ToolBus TB = this.getProcess().getToolBus();
				
		ToolDefinition TD = TB.getToolDefinition(toolname);
		
		ToolInstance TI = TD.instantiate(TB, evargs);
		
		TB.addTool(TI);
		
		this.getEnv().putVar(rvar, TI.getToolId());
		
		System.out.println("end of Execute");
		
		return true;
      } else {
        return false;
      }
		
	}

}
	
	