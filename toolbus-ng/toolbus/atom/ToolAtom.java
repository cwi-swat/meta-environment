package toolbus.atom;

import toolbus.TBTerm;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

/**
 * @author paulk, Aug 7, 2002
 */
public class ToolAtom extends Atom {
	private ATerm toolarg;
	private ToolBus TB;

	public ToolAtom() {
		super();
	}

	public ToolAtom(ATermList args) {
		super(args);
	}

	public ToolAtom(ATerm toolarg) {
		super(toolarg);
	}

	public ToolBus getTB() {
		return TB;
	}

	public ATerm getToolarg() {
		return toolarg;
	}

	public ToolInstance getToolInstance() throws ToolBusException {
		ToolInstance ti = getProcess().getToolInstance();
		if (ti == null) {
			throw new ToolBusException("null tool instance");
		} else {
			return ti;
		}
	}

	public ATermAppl getSubstitutedArg() throws ToolBusException {
		ATerm trm = TBTerm.substitute(toolarg, getEnv());
		if (trm.getType() != ATerm.APPL) {
			throw new ToolBusException(
				"tool argument " + trm + " should be an application");
		} else
			return (ATermAppl) trm;
	}



	public void compile(ProcessInstance P, AtomSet follow)
		throws ToolBusException {
		super.compile(P, follow);

		ATermList args = getArgs();
		TB = getProcess().getToolBus();
		toolarg = args.getLast();

		if (toolarg.getType() != ATerm.APPL)
			throw new ToolBusException("malformed second argument");
	}

}
