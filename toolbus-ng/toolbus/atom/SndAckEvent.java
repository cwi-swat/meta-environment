package toolbus.atom;

import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import aterm.ATerm;
/**
 * @author paulk, Jul 31, 2002
 */
public class SndAckEvent extends ToolAtom {

	public SndAckEvent(ATerm toolvar, ATerm trm) {
		super(toolvar, trm);
	}

	public SndAckEvent() {
		super();
	}

	public void compile(ProcessInstance P, AtomSet follow)
		throws ToolBusException {
		super.compile(P, follow, "snd-ack-event", "rec-ack-event");
	}

	public boolean execute() throws ToolBusException {
		if (!isEnabled())
			return false;
		ToolInstance ti = getTB().getTool(getEnv().getVar(getToolvar()));

		ti.sndEvalToTool(getSubstitutedArg());
		return true;
	}

}
