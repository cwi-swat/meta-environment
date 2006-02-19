/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import toolbus.Functions;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.atom.EndScope;
import toolbus.exceptions.ToolBusError;
import aterm.ATerm;
import aterm.ATermList;


/**
 * ProcessDefinition describes the name, formal parameters and body of a
 * defined process.
 */
public class ProcessDefinition {

  private String name;
  private ATermList formals;
  private ProcessExpression PE;
  private TBTermFactory tbfactory;

  public ProcessDefinition(String name, ATermList formals, ProcessExpression PE, TBTermFactory tbfactory) {
    this.name = name;
    this.formals = formals;
    this.PE = PE;
    this.tbfactory = tbfactory;
  }

  public String getName() {
    return name;
  }

  public ATermList getFormals() {
  	return formals;
  }

  public ProcessExpression getProcessExpression(ATermList actuals) throws ToolBusError {
	  //System.err.println("formals = " + formals + "; actuals = " + actuals);
    if (actuals.getLength() != formals.getLength()) {
      throw new ToolBusError("process " + name + ": mismatch between formals " + formals + " and actuals " + actuals);
    }
    for (int i = 0; i < actuals.getLength(); i++) {
      TBTermVar formal = (TBTermVar) formals.getChildAt(i);
      ATerm actual = (ATerm) actuals.getChildAt(i);
      if (tbfactory.isResultVar(formal) && !tbfactory.isResultVar(actual)) {
        throw new ToolBusError("process " + name + ": mismatch between formal " + formal + " and actual " + actual);
      }
      if(!Functions.compatibleTypes(formal,actual))
    	  throw new ToolBusError("argument #" + (i+1) + " of process " + name + " should have type " + formal.getVarType()
    			                  + " instead of " + actual);
    };
    ProcessExpression PE1 = PE.copy();
    return PE1;
  }

  public String toString() {
    return "ProcessDefinition(" + name + ", " + formals + ", " + PE + ")";
  }
}
