package toolbus.atom;

import toolbus.TBTerm;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolDefinition;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

/**
 * @author paulk, Aug 7, 2002
 */
public class ToolAtom extends Atom {
	private ATerm toolvar;
	private ATerm toolarg;
	private ToolBus TB;

	public ToolAtom() {
		super();
	}

	public ToolAtom(ATermList args) {
		super(args);
	}

	public ToolAtom(ATerm toolvar, ATerm toolarg) {
		super(toolvar, toolarg);
	}

	public ToolBus getTB() {
		return TB;
	}

	public ATerm getToolarg() {
		return toolarg;
	}

	public ATerm getToolvar() {
		return toolvar;
	}

	public ATermAppl getSubstitutedArg() throws ToolBusException {
		ATerm trm = TBTerm.substitute(toolarg, getEnv());
		if (trm.getType() != ATerm.APPL) {
			throw new ToolBusException(
				"tool argument " + trm + " should be an application");
		} else
			return (ATermAppl) trm;
	}

	public void compile(
		ProcessInstance P,
		AtomSet follow,
		String name,
		String complName)
		throws ToolBusException {
		super.compile(P, follow);

		ATermList args = getArgs();
		toolvar = args.getFirst();
		TB = getProcess().getToolBus();
		toolarg = args.getLast();
		if (!TBTerm.isVar(toolvar))
			throw new ToolBusException(
				"first argument of " + name + " should be a variable");

		ATerm vartype = TBTerm.getVarType(toolvar);
		String toolname = ((ATermAppl) vartype).getName();

		ToolDefinition TD = TB.getToolDefinition(toolname);

		TD.registerOccurrence(
			complName,
			TBTerm.makePattern(args, getEnv(), true));

		if (toolarg.getType() != ATerm.APPL)
			throw new ToolBusException("malformed second argument in " + name);
	}

}
