.*
/**
 * @author paulk, Jul 19, 2002
 */

package toolbus;

import java.util.Enumeration;
import java.util.Hashtable;

import aterm.ATerm;
import aterm.ATermList;

/**
 * Binding implements a (variable, value) pair.
 */

class xxBinding {
	ATerm var;
	ATerm val;
	boolean isFormal = false;
	
	public Binding(ATerm var, ATerm val, boolean isFormal) {
		this.var = var;
		this.val = val;
		this.isFormal = isFormal;
	}
	public Binding(ATerm var, ATerm val) {
		this(var, val, true);
	}

	public Binding(ATerm var) {
		this(var,TBTerm.Undefined,false);
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

public class OldEnvironment {
	protected Hashtable<String,Binding> bindings;

	public Environment() {
		bindings = new Hashtable<String,Binding>(10);
	}
	
	public Environment(Hashtable<String,Binding> b){
		bindings = b;
	}
	
	public Environment copy() {
		Environment env = new Environment();
		env.bindings = (Hashtable<String,Binding>) bindings.clone();
		return env;
	}

	/**
	 * introduceVars adds a list of variables to the environment.
	 * They are initialized to Undefined.
	 * 
	 * @param vars
	 *            list of variables.
	 */

	public void introduceVars(ATermList vars) throws ToolBusInternalError {
		for( ; !vars.isEmpty(); vars = vars.getNext()){
			ATerm var = vars.getFirst();
			if (TBTerm.isVar(var)) {
				bindings.put(TBTerm.getVarName(var), new Binding(var));
			} else {
				throw new ToolBusInternalError("introduceVar illegal var: " + var);
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
		actual = TBTerm.replaceFormals(actual, this);
		if (TBTerm.isVar(actual)
				&& !Functions.compatibleTypes(TBTerm.getVarType(formal), TBTerm.getVarType(actual))) {
			throw new ToolBusException("incompatible types for " + formal
					+ " and " + actual + " in " + this);
		}

		if (TBTerm.isVar(formal)) {
			bindings.put(TBTerm.getVarName(formal), new Binding(formal, actual, isFormal));
		} else if (TBTerm.isResVar(formal)) {
			if (!TBTerm.isResVar(actual)) {
				throw new ToolBusInternalError("illegal actual: " + actual);
			}
			bindings.put(TBTerm.getVarName(formal), new Binding(formal, actual, isFormal));
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
		if(formals.getLength() != actuals.getLength()){
			throw new ToolBusInternalError("formal/actuals list have unequal length: "+ formals + " and " + actuals);
		}
		for( ; !formals.isEmpty(); formals = formals.getNext(), actuals = actuals.getNext()){
			introduceBinding(formals.getFirst(), actuals.getFirst(), isFormal);
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
		for( ; !formals.isEmpty(); formals = formals.getNext()){
			ATerm formal = formals.getFirst();
			bindings.remove(TBTerm.getVarName(formal));
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
		while(true){
			String name = TBTerm.getVarName(var);
			Binding b = bindings.get(name);
			if(b == null){
				bindings.put(name, new Binding(var, val));
				return;
			}
			String bname = TBTerm.getVarName(b.var);
			if (name == bname) {
				if(b.isFormal() && TBTerm.isResVar(b.var)){
					var = b.val;
				} else {
					b.val = val;
					b.setFormal(false);
					return;
				}
			}
		}
	}

	public ATerm getVarType(ATerm var) {
		if (!(TBTerm.isVar(var) || TBTerm.isResVar(var)))
			throw new ToolBusInternalError(
					"Environment.getVarType: illegal var " + var);
		String name = TBTerm.getVarName(var);
		Binding b = bindings.get(name);
		if(b == null){
			return TBTerm.getVarType(var);
		}
		if (TBTerm.getVarName(b.var) == name){
			return TBTerm.getVarType(b.var);
		}
		return TBTerm.getVarType(var);
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
		return bindings.get(name);
	}
	
	public boolean isDeclaredAsStringVar(String name){
		Binding b = bindings.get(name);
		if(b == null){
			return false;
		}
		return (TBTerm.getVarType(b.var) == TBTerm.StrType);
	}

	/**
	 * getValue fetches the value of a variable.
	 * 
	 * @param var
	 *            variable whose value is needed.
	 */

	public ATerm getValue(ATerm var) throws ToolBusException {
		//System.err.println("getValue(" + var + " in " + this + ")");

		while(true){
			String name = TBTerm.getVarName(var);
			Binding b = bindings.get(name);
			if(b == null){
				//return var;
				throw new ToolBusException(var + " has undefined value");
			}
			String bname = TBTerm.getVarName(b.var);
			if (name == bname) {
				if(b.isFormal() && (TBTerm.isResVar(b.val) || TBTerm.isVar(b.val))){
					var = b.val;				
				} else {
					ATerm val = b.val;
					val = TBTerm.substitute(val, this);
					return val;
				}
			}
		}
	}

	public String toString() {
		String res = "{", sep = "";
		Enumeration all = bindings.elements();
		while (all.hasMoreElements()) {
			Binding b = (Binding) all.nextElement();
			String op = b.isFormal() ? " :-> " : " : ";
			res += sep + b.var + op + b.val;
			sep = ", ";
		}
		return res + "}";
	}
}

