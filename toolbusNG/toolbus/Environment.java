/**
 * @author paulk, Jul 19, 2002
 */

package toolbus;

import aterm.*;

/**
 * Bindings implement lists of (variable, value) pairs.
 */

class Binding {
	ATerm var;

	ATerm val;

	Binding next;

	public Binding(ATerm var, ATerm val, Binding bnd) {
		this.var = var;
		this.val = val;
		this.next = bnd;
	}
}

/**
 * Environments maintain a relation between variables and their values.
 */

public class Environment {
	protected Binding bindings;

	public Environment() {
		bindings = null;
	}
	
	public Environment copy() {
		Environment env = new Environment();
		env.bindings = bindings;
		return env;
	}

	/**
	 * introduceVars adds a list of variables to the environment.
	 * 
	 * @param vars
	 *            list of variables.
	 */

	public void introduceVars(ATermList vars) throws ToolBusException {
		for (int i = 0; i < vars.getLength(); i++) {
			ATerm var = vars.elementAt(i);
			if (TBTerm.isVar(var)) {
				bindings = new Binding(var, null, bindings);
			} else {
				throw new ToolBusInternalError("introduceVar illegal var: "
						+ var);
			}
		}
		//System.err.println("introduceVars(" + vars + ") yields:\n" + this);
	}

	/**
	 * introduceBinding adds new variables for the case of formal/actual
	 * correspondence in process calls. Special care is taken for result
	 * variables.
	 * 
	 * @param formals
	 *            list of formal parameters.
	 * @param actuals
	 *            list of actual values.
	 */
	public void introduceBinding(ATerm formal, ATerm actual) throws ToolBusException {
		if (TBTerm.isVar(actual)
				&& !FunctionDescriptors.compatibleType(TBTerm.getVarType(formal), TBTerm.getVarType(actual))) {
			throw new ToolBusException("incompatible types for " + formal
					+ " and " + actual);
		}
		if (TBTerm.isVar(formal)) {
			bindings = new Binding(formal, actual, bindings);
		} else if (TBTerm.isResVar(formal)) {
			if (!TBTerm.isResVar(actual)) {
				throw new ToolBusInternalError("illegal actual: " + actual);
			}
			bindings = new Binding(formal, actual, bindings);
		} else {
			throw new ToolBusInternalError("illegal formal: " + formal);
		}
	}
	
	/**
	 * introduceBindings adds new (formal.actual) bindings
	 * 
	 * @param formals
	 *            list of formal parameters.
	 * @param actual
	 *            list of actual parameters.
	 */

	public void introduceBindings(ATermList formals, ATermList actuals)
			throws ToolBusException {
		for (int i = 0; i < formals.getLength(); i++) {
			introduceBinding(formals.elementAt(i), actuals.elementAt(i));
		}
	}

	/**
	 * removeBindings deletes variables introduced by introduceVars and
	 * introduceBindings.
	 * 
	 * @param formals
	 *            variables to be removed.
	 */

	public void removeBindings(ATermList formals) {
		for (int i = 0; i < formals.getLength(); i++) {
			if (bindings != null)
				bindings = bindings.next;
		}
	}

	/**
	 * assignVar assigns a value to a variable.
	 * 
	 * @param var
	 *            variable
	 * @param val
	 *            value to be assigned to variable
	 */

	public void assignVar(ATerm var, ATerm val) {
		//System.err.println("assignVar(" + var + ", " + val + ")");
		String name = TBTerm.getVarName(var);
		for (Binding b = bindings; b != null; b = b.next) {
			String bname = TBTerm.getVarName(b.var);
			//System.err.println(name + " == " + bname);
			if (name == bname) {
				//System.err.println("yes, checking " + b.val);
				if(b.val != null && TBTerm.isResVar(b.val)){
					name = TBTerm.getVarName(b.val);
				} else {
					b.val = val;
					return;
				}
			}
		}
		//System.err.println("not found");
		bindings = new Binding(var, val, bindings);
	}

	public ATerm getVarType(ATerm var) {
		if (!(TBTerm.isVar(var) || TBTerm.isResVar(var)))
			throw new ToolBusInternalError(
					"Environment.getVarType: illegal var " + var);
		String name = TBTerm.getVarName(var);
		for (Binding b = bindings; b != null; b = b.next)
			if (TBTerm.getVarName(b.var) == name)
				return TBTerm.getVarType(b.var);
		return TBTerm.getVarType(var);
		//throw new ToolBusInternalError(
		//		"Environment.getVarType: undeclared var " + var);
	}

	/**
	 * getValue fetches the value of a variable.
	 * 
	 * @param var
	 *            variable whole value is needed.
	 */

	public ATerm getValue(ATerm var) throws ToolBusException {
		//System.err.println("getValue(" + var + " in " + this + ")");
		String name = TBTerm.getVarName(var);
		for (Binding b = bindings; b != null; b = b.next) {
			String bname = TBTerm.getVarName(b.var);
			//System.err.println("comparing " + name + " and " + bname);
			if (name == bname) {
				if(b.val != null && (TBTerm.isResVar(b.val) || TBTerm.isVar(b.val))){
					name = TBTerm.getVarName(b.val);
					//System.err.println("name becomes: " + name);
				} else {
					ATerm val = b.val;
					if (val == null)
						throw new ToolBusException(var + " has undefined value");
					//System.err.println("yields " +  val);
					return val;
				}
			}
		}
		//System.err.println("yields " +  var);
		return var;
	}

	public String toString() {
		String res = "{", sep = "";
		for (Binding b = bindings; b != null; b = b.next) {
			res += sep + b.var + " : " + b.val;
			sep = ", ";
		}
		return res + "}";
	}
}

