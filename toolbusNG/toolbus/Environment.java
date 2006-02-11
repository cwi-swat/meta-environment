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

class Binding {
	TBTermVar var;
	ATerm val;
	boolean formal = false;
	boolean assignable = false;
	
	public Binding(TBTermVar var, ATerm val, boolean isFormal) {
		this.var = var;
		this.val = val;
		this.formal = isFormal;
	}
	public Binding(TBTermVar var, ATerm val) {
		this(var, val, true);
	}
	
	public boolean isFormal(){
		return formal;
	}
	
	public void setFormal(boolean b){
		formal = b;
	}
	
	public boolean isAssignable(){
		return assignable;
	}
	
	public void setAssignable(boolean b){
		 assignable = b;
	}
}

/**
 * Environments maintain a relation between variables and their values.
 */

public class Environment {
	protected Hashtable<String,Binding> bindings;
	private TBTermFactory tbfactory;

	public Environment(TBTermFactory tbfactory) {
		bindings = new Hashtable<String,Binding>(10);
		this.tbfactory = tbfactory;
	}
	
//	public Environment(Hashtable<String,Binding> b){
//		bindings = b;
//	}
	
	public Environment copy() {
		Environment env = new Environment(tbfactory);
		env.bindings = (Hashtable<String,Binding>) bindings.clone();
		return env;
	}
	
	public TBTermFactory getTBTermFactory(){
		return tbfactory;
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
			ATerm t = vars.getFirst();
			if (tbfactory.isAnyVar(t)) {
				TBTermVar var = (TBTermVar) t;
				bindings.put(var.getVarName(), new Binding(var,tbfactory.Undefined));
			} else {
				throw new ToolBusInternalError("introduceVar illegal var: " + t);
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
	public void introduceBinding(TBTermVar formalVar, ATerm actual, boolean isFormal) throws ToolBusException {
		//System.err.println("introduceBinding: " + formalVar + ", " + actual);
		actual = tbfactory.replaceFormals(actual, this);
		//System.err.println("actual: " + actual);
		if (tbfactory.isAnyVar(actual)){
			TBTermVar actualVar = (TBTermVar) actual;
		    if(!Functions.compatibleTypes(formalVar.getVarType(), actualVar.getVarType())) {
		    	throw new ToolBusException("incompatible types for " + formalVar
					+ " and " + actualVar + " in " + this);
		    }
		}
		if(formalVar.isResultVar() && !tbfactory.isResVar(actual)) {
				throw new ToolBusInternalError("illegal actual: " + actual);
		} else {
			bindings.put(formalVar.getVarName(), new Binding(formalVar, actual, isFormal));
		    //System.err.println("introduceBinding => " + this);
		} 
	}
	
	public void introduceBinding(TBTermVar formalVar, ATerm actual) throws ToolBusException {
		introduceBinding(formalVar, actual, false);
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
			ATerm first = formals.getFirst();
			if(!tbfactory.isAnyVar(first)){
				throw new ToolBusInternalError("illegal formal: " + first);
			}
			introduceBinding((TBTermVar)first, actuals.getFirst(), isFormal);
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
			ATerm first = formals.getFirst();
			if(!tbfactory.isAnyVar(first)){
				throw new ToolBusInternalError("illegal formal: " + first);
			}
			TBTermVar formalVar = (TBTermVar) first;
			bindings.remove(formalVar.getVarName());
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

	public void assignVar(TBTermVar var, ATerm val) {
		//System.err.println("assignVar(" + var + ", " + val + ")");
		while(true){
			String name = var.getVarName();
			Binding b = bindings.get(name);
			if(b == null){
				bindings.put(name, new Binding(var, val));
				return;
			}
			String bname = b.var.getVarName();
			if (name.equals(bname)) {
				//System.err.println(name + " equals " + bname);
				if(b.isFormal() && b.var.isResultVar()){
					var = (TBTermVar) b.val; //TODO checkit
				} else {
					b.val = val;
					b.setFormal(false);
					return;
				}
			}
		}
	}

	public ATerm getVarType(TBTermVar var) {
		//System.err.println("getVarType(" + var + ");" + this);
		String name = var.getVarName();
		Binding b = bindings.get(name);
	//	System.err.println("keys = " + bindings.keySet());
	//	for(String s : bindings.keySet()){
	//		System.err.println(name + "; " + s + " => " + name.equals(s));
	//	
	//	}
		if(b == null){
			//System.err.println("getVarType (b == null) => " + var.getVarType());
			return var.getVarType();
		}
		if (b.var.getVarName().equals(name)){
			//System.err.println("getVarType (equals) => " + b.var.getVarType());
			return b.var.getVarType();
		}
		//System.err.println("getVarType => " + var.getVarType());
		return var.getVarType();
	}
	
	/**
	 * getValue fetches the value of a variable.
	 * 
	 * @param var
	 *            variable whole value is needed.
	 */

	public Binding getBinding(TBTermVar var) throws ToolBusException {
		//System.err.println("getBinding(" + var + " in " + this + ")");
		String name = var.getVarName();
		return bindings.get(name);
	}
	
	public boolean isDeclaredAsStringVar(String name){
		Binding b = bindings.get(name);
		if(b == null){
			return false;
		}
		return (b.var.getVarType() == tbfactory.StrType);
	}

	/**
	 * getValue fetches the value of a variable.
	 * 
	 * @param var
	 *            variable whose value is needed.
	 */

	public ATerm getValue(TBTermVar var) throws ToolBusException {
		//System.err.println("getValue(" + var + " in " + this + ")");

		while(true){
			String name = var.getVarName();
			Binding b = bindings.get(name);
			if(b == null){
				return var;
				//throw new ToolBusException(var + " has undefined value");
			}
			String bname = b.var.getVarName();
			if (name.equals(bname)) {
				if(b.isFormal() && (tbfactory.isAnyVar(b.val))){
					var = (TBTermVar)b.val;				
				} else {
					ATerm val = b.val;
					val = tbfactory.substitute(val, this);
					return val;
				}
			}
		}
	}
	
	public void setAssignable (TBTermVar var) throws ToolBusException {
		Binding b = getBinding(var);
		b.setAssignable(true);
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

