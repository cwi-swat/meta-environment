package toolbus.atom;

import aterm.*;
import toolbus.*;
import toolbus.process.*;
import toolbus.tool.*;

/**
 * @author paulk, Aug 7, 2002
 */

public class RecEvent extends ToolAtom {

	public RecEvent(ATerm toolvar, ATerm trm) {
		super(toolvar, trm);
	}

	public RecEvent() {
		super();
	}

	public void compile(ProcessInstance P, AtomSet follow)
		throws ToolBusException {
		super.compile(P, follow, "rec-event", "snd-event");
	}

	public boolean execute() throws ToolBusException {
		if (!isEnabled())
			return false;
		ToolInstance ti = getTB().getTool(getEnv().getVar(getToolvar()));
		MatchResult mr = ti.getEvent(getToolarg(), getEnv());
		if (mr.matches()) {
			mr.getLeft().update(getEnv());
			return true;
		} else
			return false;
	}

}