/**
 * @author paulk, Jul 19, 2002
 */

package toolbus;

import aterm.ATerm;
import aterm.ATermList;

/**
 * Binding implement lists of (variable, value) pairs.
 */

class Binding {
	ATerm var;
	ATerm val;
	Binding next;
	boolean isFormal = false;

	public Binding(ATerm var, Binding bnd) {
		this.var = var;
		this.val = TBTerm.Undefined;
		this.next = bnd;
	}
	
	public Binding(ATerm var, ATerm val, Binding bnd) {
		this.var = var;
		this.val = val;
		this.next = bnd;
		this.isFormal = true;
	}
	
	public Binding(ATerm var, ATerm val, boolean isFormal, Binding bnd) {
		this.var = var;
		this.val = val;
		this.next = bnd;
		this.isFormal = isFormal;
	}
	
	public boolean isFormal(){
		return isFormal;
	}
	
	public void setFormal(boolean b){
		isFormal = b;
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
	
	public Environment(Binding b){
		bindings = b;
	}
	
	public Environment copy() {
		Environment env = new Environment();
		env.bindings = bindings;
		return env;
	}

	/**
	 * introduceVars adds a list of variables to the environment.
	 * They are initialized to Undefined
	 * 
	 * @param vars
	 *            list of variables.
	 */

	public void introduceVars(ATermList vars) throws ToolBusInternalError {
		for (int i = 0; i < vars.getLength(); i++) {
			ATerm var = vars.elementAt(i);
			if (TBTerm.isVar(var)) {
				bindings = new Binding(var, bindings);
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
	public void introduceBinding(ATerm formal, ATerm actual, boolean isFormal) throws ToolBusException {
		actual = TBTerm.replaceFormals(actual, this); //TODO
		if (TBTerm.isVar(actual)
				&& !Functions.compatibleTypes(TBTerm.getVarType(formal), TBTerm.getVarType(actual))) {
			throw new ToolBusException("incompatible types for " + formal
					+ " and " + actual + " in " + this);
		}
		//actual = TBTerm.substitute(actual,this);      //TODO
		if (TBTerm.isVar(formal)) {
			bindings = new Binding(formal, actual, isFormal, bindings);
		} else if (TBTerm.isResVar(formal)) {
			if (!TBTerm.isResVar(actual)) {
				throw new ToolBusInternalError("illegal actual: " + actual);
			}
			bindings = new Binding(formal, actual, isFormal, bindings);
		} else {
			throw new ToolBusInternalError("illegal formal: " + formal);
		}
	}
	
	public void introduceBinding(ATerm formal, ATerm actual) throws ToolBusException {
		introduceBinding(formal, actual, false);
	}
	
	/**
	 * introduceBindings adds new (formal.actual) bindings
	 * 
	 * @param formals
	 *            list of formal parameters.
	 * @param actual
	 *            list of actual parameters.
	 */

	public void introduceBindings(ATermList formals, ATermList actuals, boolean isFormal)
			throws ToolBusException {
		//System.err.println("introduceBindings: " + formals + " => " + actuals);
		for (int i = 0; i < formals.getLength(); i++) {
			introduceBinding(formals.elementAt(i), actuals.elementAt(i), isFormal);
		}
		//System.err.println(this);
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
				if(b.isFormal() && TBTerm.isResVar(b.var)){
					name = TBTerm.getVarName(b.val);
				} else {
					b.val = val;
					b.setFormal(false);
					return;
				}
			}
		}
		System.err.println("**** not found ****");
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

	public Binding getBinding(ATerm var) throws ToolBusException {
		//System.err.println("getBinding(" + var + " in " + this + ")");
		String name = TBTerm.getVarName(var);
		for (Binding b = bindings; b != null; b = b.next) {
			String bname = TBTerm.getVarName(b.var);
			if (name == bname) {
				return b;
			}
		}
		return null;
	}

	/**
	 * getValue fetches the value of a variable.
	 * 
	 * @param var
	 *            variable whose value is needed.
	 */

	public ATerm getValue(ATerm var) throws ToolBusException {
		//System.err.println("getValue(" + var + " in " + this + ")");
		String name = TBTerm.getVarName(var);
		for (Binding b = bindings; b != null; b = b.next) {
			String bname = TBTerm.getVarName(b.var);
			//System.err.println("comparing " + name + " and " + bname);
			if (name == bname) {
				if(b.isFormal() && (TBTerm.isResVar(b.val) || TBTerm.isVar(b.val))){
					name = TBTerm.getVarName(b.val);
					//System.err.println("name becomes: " + name);
				} else {
					ATerm val = b.val;
					val = TBTerm.substitute(val, this);
					/**
					if(b.isFormal()){
						System.err.println("further evaluate: " + val);
						ATerm oval = val;
						val = Functions.eval(val, null, new Environment(b.next));  // TODO: empty PI
						//val = TBTerm.substitute(val, this);
						System.err.println("further evaluate: " + oval + " => " + val);
					}
					**/
					//if(val == null){
					//	//val = TBTerm.Undefined;
					//	val = var;
					//}
					//if (val == null){
					//     Exception e = new ToolBusException(var + " has undefined value");
					//     e.printStackTrace();
					//	throw new ToolBusException(var + " has undefined value");
					//}
					//System.err.println("getValue " + var + " yields " +  val);
					return val;
				}
			}
		}
		System.err.println("getValue yields " +  var);
		return var;
	}

	public String toString() {
		String res = "{", sep = "";
		for (Binding b = bindings; b != null; b = b.next) {
			String op = b.isFormal() ? " :-> " : " : ";
			res += sep + b.var + op + b.val;
			sep = ", ";
		}
		return res + "}";
	}
}

