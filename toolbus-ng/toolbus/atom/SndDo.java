package toolbus.atom;

import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002
 */
public class SndDo extends ToolAtom {

	public SndDo(ATerm toolvar, ATerm toolarg) {
		super(toolvar, toolarg);
	}
	
	public SndDo() {
		super();
	}

	public void compile(ProcessInstance P, AtomSet follow)
	throws ToolBusException
	{
		super.compile(P, follow, "snd-do", "rec-do");
	}
	
	public boolean execute() throws ToolBusException
	{
		if(!isEnabled())
			return false;
		ToolInstance ti = getTB().getTool(getEnv().getVar(getToolvar()));
		ti.sndDoToTool(getSubstitutedArg());
		return true;
	}

}
