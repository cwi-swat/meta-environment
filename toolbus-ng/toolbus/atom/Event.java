package toolbus.atom;

import toolbus.MatchResult;
import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import aterm.ATerm;

/**
 * @author paulk, Aug 7, 2002
 */

public class Event extends ToolAtom {

	public Event(ATerm trm) {
		super(trm);
	}

	public Event() {
		super();
	}

	public void compile(ProcessInstance P, AtomSet follow)
		throws ToolBusException {
		super.compile(P, follow);
	}
	

	public boolean execute() throws ToolBusException {
		if (!isEnabled())
			return false;

		ToolInstance ti = getToolInstance();
		MatchResult mr = ti.getEventFromTool(getToolarg(), getEnv());
		if (mr.matches()) {
			mr.getLeft().update(getEnv());
			return true;
		} else
			return false;
	}

}