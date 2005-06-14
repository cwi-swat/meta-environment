/**
 * @author paulk, Jul 19, 2002
 */

package toolbus;
import java.util.Vector;

import aterm.*;

/**
 * Environments maintain a relation between variables and their values.
 * The lifecyle of an environment consists of two phases: compile time and execution time.
 * 
 * During compile time (i.e. during compilation of a process definition) a vector (declVec) is maintained
 * of all current variables. Each vector entry contains a var or rvar term corresponding to a variable.
 * The variable maxVar indicates the last addressable variable. The situation is thus:
 * 
 *   var    var    var  ...    var     ...  var
 *    0      1      2   ...  maxVar-1  ...  declVar.size()-1
 *   \---------------------------/
 *     visible in current scope
 *   \---------------------------------------/
 *     all variables declared in some scope
 * 
 * Methods are:
 * - introduceVars
 * - introduceBindings
 * - removeVars
 * - getVarIndex
 * - getVarType
 * 
 * During compilation, resolveVars uses the environment to replace all variable indices by their
 * actual value. During execution time, operations on variables amount to a simple indexing
 * operation.
 * 
 * The switch to execution time is made by setExecuting. It sets the vector to null (to detect 
 * uninitialized variables) and then the following methods are available:
 * - assignVar
 * - getValue
 * 
 */

public class Environment {
  private int maxVar;
  private Vector declVec;

  private boolean executing;

  public Environment() {
    maxVar = 0;
    declVec = new Vector();
    executing = false;
  }

  /**
   * Compile time methods
   */
  
  /**
   * introduceVars adds a list of variables to the environment.
   * @param vars list of variables; each variables gets a new index assigned.
   */
  
 
public void introduceVars(ATermList vars) throws ToolBusException {
    if (executing) {
      throw new ToolBusInternalError("introduceVars during execution");
    }
    for (int i = 0; i < vars.getLength(); i++) {
      ATerm var = vars.elementAt(i);
      if (TBTerm.isVar(var)) {
        declVec.addElement(TBTerm.setVarIndexAndType(var, maxVar, TBTerm.getVarType(var)));
        maxVar++;
      } else {
        throw new ToolBusInternalError("introduceVars illegal var: " + var);
      }
    }
  }
  
  /**
   * introduceBindings adds new variables for the case of formal/actual correspondence
   * in process calls. Special care is taken for result variables. A *formal* result
   * variable gets the same index as the *actual* result variable. Both thus effectively
   * share the same value.
   * @param formals list of formal parameters.
   * @param actuals list of actual values.
   */

  public void introduceBindings(ATermList formals, ATermList actuals) throws ToolBusException {
    if (executing) {
      throw new ToolBusInternalError("introduceBindings during execution");
    }
    for (int i = 0; i < formals.getLength(); i++) {
      ATerm formal = formals.elementAt(i);
      if (TBTerm.isVar(formal)) {
        declVec.addElement(TBTerm.setVarIndexAndType(formal, maxVar, TBTerm.getVarType(formal)));
        maxVar++;
      } else if (TBTerm.isResVar(formal)) {
        ATerm actual = actuals.elementAt(i);
        if (!TBTerm.isResVar(actual)) {
          throw new ToolBusInternalError("illegal actual: " + actual);
        }
        if (TBTerm.getVarType(formal) != TBTerm.getVarType(actual)) {
          throw new ToolBusException("incompatible types for " + formal + " and " + actual);
        }
        int index = getVarIndex(actual);
        declVec.addElement(TBTerm.setVarIndexAndType(formal, index, TBTerm.getVarType(formal)));
        maxVar++;
      } else {
        throw new ToolBusInternalError("illegal formal: " + formal);
      }
    }
  }
  /**
   * removeVars deletes variables introduced by introduceVars and introduceBindings.
   * Note that maxVar is decreased and that declVec[0], ... declVec[maxVar-1] become the
   * visible variables.
   * @param delta number of variables to be removed.
   */

  public void removeVars(int delta) {
    if (executing) {
      throw new ToolBusInternalError("removeVars during execution");
    }
    maxVar -= delta;
  }
  
  /**
   * getVarIndex returns the index allocated for given variable
   * @param var the variable whose index is required
   */

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
  
  /**
   * getVarType return the declared type of a given variable.
   * @param var the variable whoe type is required
   */

  public ATerm getVarType(ATerm var) {
    if (executing) {
      throw new ToolBusInternalError("getVarType during execution");
    }
    if (!(TBTerm.isVar(var) || TBTerm.isResVar(var)))
      throw new ToolBusInternalError("Environment.getVarType: illegal var " + var);
    String name = TBTerm.getVarName(var);
    for (int i = maxVar - 1; i >= 0; i--)
      if (TBTerm.getVarName((ATerm) declVec.elementAt(i)) == name)
        return TBTerm.getVarType((ATerm) declVec.elementAt(i));
    throw new ToolBusInternalError("Environment.getVarIndex: undeclared var " + var);
  }
  
  /**
   * setExecuting switches to execution mode.
   */

  public void setExecuting() {
    if (executing) {
      throw new ToolBusInternalError("setExecuting during execution");
    }
    executing = true;
    declVec.trimToSize();
    for (int i = 0; i < declVec.size(); i++)
      declVec.setElementAt(null, i);
  }
  
  /**
   * Execution time methods
   */
  
  /**
   * assignVar assigns a value to a variable.
   * @param var variable
   * @param val value to be assigned to variable
   */

  public void assignVar(ATerm var, ATerm val) {
    //System.out.println("putVar(" + var + ", " + val +")");
    declVec.setElementAt(val, TBTerm.getVarIndex(var));
  }
  
  /**
   * getValue fetches the value of a variable.
   * @param var variable
   */

  public ATerm getValue(ATerm var) throws ToolBusException {

    ATerm val = (ATerm) declVec.elementAt(TBTerm.getVarIndex(var));
    //System.err.println("getVar(" + var + "): " + val);
    if (val == null)
      throw new ToolBusException(var + " has undefined value");
    return val;
  }

  public String toString() {
  	String res = "{" + maxVar + "|", sep = "";
    for (int i = 0; i < declVec.size(); i++){
        res += sep + i + ":" + declVec.elementAt(i).toString();
        sep = ", ";
    }
    return res + "}";
  }
}
