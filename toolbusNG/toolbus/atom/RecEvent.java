package toolbus.atom;

import aterm.*;
import toolbus.*;
import toolbus.process.*;
import toolbus.tool.*;

/**
 * @author paulk, Aug 7, 2002
 */

public class RecEvent extends Atom {
	
	private ATerm toolvar;
	private ATerm trm;
	private ToolBus TB;
	
	public RecEvent(ATerm toolvar, ATerm trm){
		super(toolvar, trm);
	}
	
	public RecEvent(){
		super();
	}
	
	public void compile(ProcessInstance P, AtomSet follow)
	throws ToolBusException
	{
		super.compile(P, follow);
		
		ATermList args = this.getArgs();
		toolvar = args.getFirst();
		TB = this.getProcess().getToolBus();
		trm = args.getLast();
		if(!TBTerm.isVar(toolvar))
			throw new ToolBusException("first argument of rec-event should be a variable");
		
		ATerm vartype = TBTerm.getVarType(toolvar);
		String toolname = ((ATermAppl) vartype).getName();

		ToolDefinition TD = TB.getToolDefinition(toolname);
		
		TD.registerOccurrence("snd-event", TBTerm.makePattern(args, this.getEnv(), true));
	}
	
	public boolean execute() throws ToolBusException
	{
		if(!isEnabled())
			return false;
		ToolInstance ti = TB.getTool(this.getEnv().getVar(toolvar));
		MatchResult mr = ti.getEvent(this.trm, getEnv());
		if(mr.matches()){
			mr.getLeft().update(getEnv());
			return true;
		} else
			return false;
	}

}