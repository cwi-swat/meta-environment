package toolbus.atom;
import aterm.*;
import toolbus.process.*;
import toolbus.tool.*;
import toolbus.*;
/**
 * @author paulk, Jul 31, 2002
 */
public class SndEval extends Atom {
	
	private ATerm toolvar;
	private ATerm trm;
	private ToolBus TB;
	
	public SndEval(ATerm toolvar, ATerm trm){
		super(toolvar, trm);
	}
	
	public SndEval(){
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
			throw new ToolBusException("first argument of snd-eval should be a variable");
		
		ATerm vartype = TBTerm.getVarType(toolvar);
		String toolname = ((ATermAppl) vartype).getName();

		ToolDefinition TD = TB.getToolDefinition(toolname);
		
		TD.registerOccurrence("rec-eval", TBTerm.makePattern(args, this.getEnv(), true));
		
		if(trm.getType() != ATerm.APPL)
			throw new ToolBusException("malformed second argument in snd-eval");
	}
	
	public boolean execute() throws ToolBusException
	{
		if(!isEnabled())
			return false;
		ToolInstance ti = TB.getTool(this.getEnv().getVar(toolvar));
		ti.sndTermToTool((ATermAppl) trm); // add a substitute!
		
		System.out.println("SndEval: done");
		return true;
	}

}
