/**
 * @author paulk, Jul 19, 2002
 */

package toolbus;

import aterm.*;

/**
 * Environments maintain a relation between variables and their values.
 */

public class Environment {
  ATerm var;
  ATerm val;
  Environment next;

  public Environment(ATerm var, ATerm val, Environment env) {
    this.var = var;
    this.val = val;
    this.next = env;
  }

  /**
   * introduceVars adds a list of variables to the environment.
   * @param vars list of variables.
   */
  
 
  public Environment introduceVars(ATermList vars) throws ToolBusException {
  	Environment env = this;
    for (int i = 0; i < vars.getLength(); i++) {
      ATerm var = vars.elementAt(i);
      if (TBTerm.isVar(var)) {
        env = new Environment(var, null, env);
      } else {
        throw new ToolBusInternalError("introduceVars illegal var: " + var);
      }
    }
    return env;
  }
  
  /**
   * introduceBindings adds new variables for the case of formal/actual correspondence
   * in process calls. Special care is taken for result variables. A *formal* result
   * variable gets the same index as the *actual* result variable. Both thus effectively
   * share the same value.
   * @param formals list of formal parameters.
   * @param actuals list of actual values.
   */

  public Environment introduceBindings(ATermList formals, ATermList actuals) throws ToolBusException {
  	Environment env = this;
    for (int i = 0; i < formals.getLength(); i++) {
      ATerm formal = formals.elementAt(i);
      ATerm actual = actuals.elementAt(i);
      if (TBTerm.isVar(actual) && (TBTerm.getVarType(formal) != TBTerm.getVarType(actual))){
        throw new ToolBusException("incompatible types for " + formal + " and " + actual);
      }
      if (TBTerm.isVar(formal)) {
        env = new Environment(formal, null, env);
      } else if (TBTerm.isResVar(formal)) {
        if (!TBTerm.isResVar(actual)) {
          throw new ToolBusInternalError("illegal actual: " + actual);
        }
        env = new Environment(formal, null, env);
      } else {
        throw new ToolBusInternalError("illegal formal: " + formal);
      }
    }
    return env;
  }
  /**
   * removeVars deletes variables introduced by introduceVars and introduceBindings.
   * Note that maxVar is decreased and that declVec[0], ... declVec[maxVar-1] become the
   * visible variables.
   * @param delta number of variables to be removed.
   */

  public Environment removeVars(int delta) {
  	Environment env = this;
    for(int i = 0; i < delta; i++){
    	env = env.next;
    }
    return env;
  }
  
  /**
   * getVarIndex returns the index allocated for given variable
   * @param var the variable whose index is required
   */
/*
  public int getVarIndex(ATerm var) throws ToolBusException {
  	//System.err.println("getVarIndex(" + var + ")");
    if (executing) {
      throw new ToolBusInternalError("getVarindex during execution");
    }
    if (!(TBTerm.isVar(var) || TBTerm.isResVar(var)))
      throw new ToolBusInternalError("Environment.getVarIndex: illegal var " + var);
    String name = TBTerm.getVarName(var);
    for (int i = maxVar - 1; i >= 0; i--) {
      ATerm entry = (ATerm) declVec.elementAt(i);
      //System.err.println("entry = " + entry);
      if (TBTerm.getVarName(entry) == name) {
      	//System.err.println("entry = " + entry);
        if (TBTerm.isResVar(entry)) {
          return TBTerm.getVarIndex(entry);
        } else {
          return i;
        }
      }
    }
    throw new ToolBusException("undeclared variable " + name);
  }
*/
  /**
   * getVarType return the declared type of a given variable.
   * @param var the variable whoe type is required
   */

  /*
  public ATerm getVarType(ATerm var) {
    if (!(TBTerm.isVar(var) || TBTerm.isResVar(var)))
      throw new ToolBusInternalError("Environment.getVarType: illegal var " + var);
    String name = TBTerm.getVarName(var);
    for (int i = maxVar - 1; i >= 0; i--)
      if (TBTerm.getVarName((ATerm) declVec.elementAt(i)) == name)
        return TBTerm.getVarType((ATerm) declVec.elementAt(i));
    throw new ToolBusInternalError("Environment.getVarIndex: undeclared var " + var);
  }
  */
  
  /**
   * assignVar assigns a value to a variable.
   * @param var variable
   * @param val value to be assigned to variable
   */

  public void assignVar(ATerm var, ATerm val) {
    System.out.println("assignVar(" + var + ", " + val +")");
	for (Environment env = this; env != null; env = env.next) {
    	if(var == env.var){
    		env.val = val;
    		return;
    	}
    }
    // not found?
  }
  
  /**
   * getValue fetches the value of a variable.
   * @param var variable
   */

  public ATerm getValue(ATerm var) throws ToolBusException {
	for (Environment env = this; env != null; env = env.next) {
		if (var == env.var) {
			ATerm val = env.val;
			if (val == null)
				throw new ToolBusException(var + " has undefined value");
			System.err.println("getValue(" + var + "): " + val);
			return val;
		}
	}
	return var;
	}

  public String toString() {
  	String res = "{", sep = "";
	for (Environment env = this; env != null; env = env.next) {
        res += sep + env.var + " : " + env.val;
        sep = ", ";
    }
    return res + "}";
  }
}
