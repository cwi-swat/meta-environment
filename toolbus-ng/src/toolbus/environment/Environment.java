/**
 * @author paulk, Jul 19, 2002
 */

package toolbus.environment;

import java.util.List;

import toolbus.Functions;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.exceptions.ToolBusError;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.ToolBusInternalError;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

/**
 * Environments maintain a relation between variables and their values.
 */
public class Environment{
	private final TBTermFactory tbfactory;
	private Bindings bindings;
	
	public Environment(TBTermFactory tbfactory){
		bindings = new ListBindings();
		this.tbfactory = tbfactory;
	}
	
	public Environment copy(){
		Environment env = new Environment(tbfactory);
		env.bindings = bindings.clone();
		
		return env;
	}
	
	public TBTermFactory getTBTermFactory(){
		return tbfactory;
	}
	
	public int size(){
		return bindings.size();
	}
	
	/**
	 * introduceVars adds a list of variables to the environment. They are initialized to Undefined.
	 * 
	 * @param vs
	 *            list of variables.
	 */
	public void introduceVars(ATermList vs) throws ToolBusInternalError{
		ATermList vars = vs;
		
		// System.err.println(this.hashCode() + " introduceVars: " + vars);
		while(!vars.isEmpty()){
			ATerm t = vars.getFirst();
			if(tbfactory.isVar(t)){
				TBTermVar var = (TBTermVar) t;
				bindings.put(var.getVarName(), new Binding(var, tbfactory.Undefined));
			}else{
				throw new ToolBusInternalError("introduceVar illegal var: " + t);
			}
			
			vars = vars.getNext();
		}
		// System.err.println(this.hashCode() + " introduceVars yields:" + this);
	}
	
	/**
	 * introduceBinding adds a new variable for the case of formal/actual correspondence in process
	 * calls. Special care is taken for result variables.
	 * 
	 * @param formalVar
	 *            A formal parameter.
	 * @param actual
	 *            An actual value.
	 * @param isFormal
	 *            Indicate if the variable is a formal.
	 */
	public void introduceBinding(TBTermVar formalVar, ATerm actual, boolean isFormal) throws ToolBusException{
		// System.err.println(this.hashCode() + " introduceBinding: " + formalVar + ", " + actual);
		ATerm a = tbfactory.replaceFormals(actual, this);
		// System.err.println("actual: " + actual);
		if(tbfactory.isAnyVar(a)){
			TBTermVar actualVar = (TBTermVar) a;
			if(!Functions.compatibleTypes(formalVar.getVarType(), actualVar.getVarType())){
				throw new ToolBusError("incompatible types for " + formalVar + " and " + actualVar + " in " + this);
			}
		}
		if(formalVar.isResultVar() && !tbfactory.isResultVar(a)) throw new ToolBusInternalError("actual: " + a + " should be a result variable");
		
		bindings.put(formalVar.getVarName(), new Binding(formalVar, a, isFormal));
		// System.err.println("introduceBinding => " + this);
	}
	
	public void introduceBinding(TBTermVar formalVar, ATerm actual) throws ToolBusException{
		introduceBinding(formalVar, actual, false);
	}
	
	/**
	 * introduceBindings adds new (formal.actual) bindings
	 * 
	 * @param formals
	 *            list of formal parameters.
	 * @param actual
	 *            list of actual parameters.
	 * @param isFormal
	 *            Indicate if the variables are formals.
	 */
	public void introduceBindings(ATermList formals, ATermList actual, boolean isFormal) throws ToolBusException{
		ATermList f = formals;
		ATermList a = actual;
		
		if(f.getLength() != a.getLength()){
			throw new ToolBusInternalError("formal/actuals list have unequal length: " + f + " and " + a);
		}
		for(; !f.isEmpty(); f = f.getNext(), a = a.getNext()){
			ATerm first = f.getFirst();
			if(!tbfactory.isAnyVar(first)){
				throw new ToolBusInternalError("illegal formal: " + first);
			}
			introduceBinding((TBTermVar) first, a.getFirst(), isFormal);
		}
	}
	
	/**
	 * removeBindings deletes variables introduced by introduceVars and introduceBindings.
	 * 
	 * @param formals
	 *            variables to be removed.
	 */
	public void removeBindings(ATermList formals){
		ATermList f = formals;
		// System.err.println(this.hashCode() + "/" + bindings.hashCode() + " removeBindings: " +
		// formals);
		for(; !f.isEmpty(); f = f.getNext()){
			ATerm first = f.getFirst();
			if(!tbfactory.isAnyVar(first)){
				throw new ToolBusInternalError("illegal formal: " + first);
			}
			TBTermVar formalVar = (TBTermVar) first;
			bindings.remove(formalVar.getVarName());
		}
		// System.err.println(this.hashCode() + "/" + bindings.hashCode() + " removeBindings yields:
		// " + this);
	}
	
	/**
	 * assignVar assigns a value to a variable.
	 * 
	 * @param v
	 *            variable
	 * @param val
	 *            value to be assigned to variable
	 */
	public void assignVar(TBTermVar v, ATerm val){
		TBTermVar var = v;
		
		// System.err.println("assignVar(" + var + ", " + val + ")");
		while(true){
			String name = var.getVarName();
			Binding b = bindings.get(name);
			if(b == null){
				bindings.put(name, new Binding(var, val));
				return;
			}
			String bname = b.var.getVarName();
			if(name.equals(bname)){
				// System.err.println(name + " equals " + bname);
				if(b.isFormal() && b.var.isResultVar()){
					var = (TBTermVar) b.val; // TODO checkit
				}else{
					b.val = val;
					b.setFormal(false);
					return;
				}
			}
		}
	}
	
	public ATerm getVarType(TBTermVar var) throws ToolBusError{
		// System.err.println("getVarType(" + var + ");" + this);
		String name = var.getVarName();
		Binding b = bindings.get(name);
		
		ATerm res;
		if(b == null){
			// System.err.println("getVarType (b == null) => " + var.getVarType());
			res = var.getVarType();
		}else if(b.var.getVarName().equals(name)){
			// System.err.println("getVarType (equals) => " + b.var.getVarType());
			res = b.var.getVarType();
		}else{
			// System.err.println("getVarType => " + var.getVarType());
			res = var.getVarType();
		}
		
		if((res.getType() == ATerm.APPL) && ((ATermAppl) res).getName() == "none"){
			throw new ToolBusError("Undeclared variable " + var.getExternalVarName());
		}
		return res;
	}
	
	/**
	 * getValue fetches the value of a variable.
	 * 
	 * @param var
	 *            variable whole value is needed.
	 */
	public Binding getBinding(TBTermVar var){
		// System.err.println("getBinding(" + var + " in " + this + ")");
		String name = var.getVarName();
		return bindings.get(name);
	}
	
	public List<Binding> getBindingsAsList(){
		return bindings.getBindingsAsList();
	}
	
	public boolean isDeclaredAsStringVar(TBTermVar var){
		String name = var.getVarName();
		Binding b = bindings.get(name);
		// System.err.println("isDeclaredAsStringVar: " + var + "; " + b + "; " + this);
		if(b == null){
			return false;
		}
		return (b.var.getVarType() == tbfactory.StrType);
	}
	
	/**
	 * getValue fetches the value of a variable.
	 * 
	 * @param v
	 *            variable whose value is needed.
	 */
	public ATerm getValue(TBTermVar v){
		TBTermVar var = v;
		// System.err.println(this.hashCode() + " getValue(" + var + " in " + this + ")");
		
		while(true){
			String name = var.getVarName();
			Binding b = bindings.get(name);
			if(b == null){
				throw new RuntimeException("variable " + var.getExternalVarName() + " has undefined value");
			}
			if(b.isFormal() && (tbfactory.isAnyVar(b.val))){
				var = (TBTermVar) b.val;
			}else{
				return b.val;
			}
		}
	}
	
	public void setAssignable(TBTermVar var){
		Binding b = getBinding(var);
		if(b != null){
			b.setAssignable(true);
		}else{
			throw new ToolBusInternalError("setAssignable: variable " + var.getExternalVarName() + " does not exist!");
		}
	}
	
	public ATerm replaceFormal(TBTermVar v) throws ToolBusException{
		TBTermVar var = v;
		
		// System.err.println("replaceFormal(" + v + "); " + this);
		var = var.setVarType(getVarType(var));
		Binding b = getBinding(var);
		// System.err.println(b);
		if(b == null || b.val == tbfactory.Undefined){
			return var;
			/* throw new ToolBusError("Undeclared variable " + v.getExternalVarName()); */
		}
		if(!b.isFormal()){
			// System.err.println("local var:. replaceFormals(" + v + ") => " + v);
			return var;
		}
		
		if(b.isAssignable() || tbfactory.isResultVar(b.val)){
			// System.err.println("2. replaceFormal(" + v + ") => " + v);
			return var;
		}
		if(tbfactory.isVar(b.val)){ // TODO: OK?
			ATerm tmp = tbfactory.replaceFormals(b.val, this);
			// System.err.println("3. replaceFormal(" + v + ") => " + tmp);
			return tmp;
		}else if(tbfactory.isResultVar(b.val)){ // TODO: OK?
			ATerm tmp = tbfactory.replaceFormals(b.val, this);
			// System.err.println("3. replaceFormal(" + v + ") => " + tmp);
			return tmp;
		}else{
			// System.err.println("4. replaceFormal(" + v + ") => " + b.val);
			return b.val;
		}
		
		// System.err.println("5. replaceFormal(" + v + ") => " + v);
		/* return v; */
	}
	
	public String toString(){
		return this.hashCode() + ":" + bindings.toString();
	}
}
