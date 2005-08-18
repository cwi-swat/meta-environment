package toolbus.atom;

import java.util.Stack;

import toolbus.Environment;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATermList;

public class EndScope extends Atom {
	private Ref refformals;

	public EndScope(ATermList formals) {
		super();
		refformals = new Ref(formals);
		setAtomArgs(this.refformals);
	}

	public ProcessExpression copy() {
		return new EndScope((ATermList) refformals.value);
	}

	public boolean execute() throws ToolBusException {
		if (isEnabled()) {
			Environment env = getEnv();
			env.removeBindings(((ATermList) refformals.value));
			return true;
		} else
			return false;
	}
}