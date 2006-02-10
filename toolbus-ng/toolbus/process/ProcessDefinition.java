/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.atom.EndScope;
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

  public ProcessExpression getProcessExpression(ATermList actuals) throws ToolBusException {
    if (actuals.getLength() != formals.getLength()) {
      throw new ToolBusException(name + ": mismatch " + formals + " and " + actuals);
    }
    for (int i = 0; i < actuals.getLength(); i++) {
      ATerm formal = (ATerm) formals.getChildAt(i);
      ATerm actual = (ATerm) actuals.getChildAt(i);
      if (tbfactory.isResVar(formal) && !tbfactory.isResVar(actual)) {
        throw new ToolBusException(name + ": mismatch " + formal + " and " + actual);
      }
    };
    ProcessExpression PE1 = new Sequence(PE.copy(), new EndScope(formals, tbfactory), tbfactory);
    return PE1;
  }

  public String toString() {
    return "ProcessDefinition(" + name + ", " + formals + ", " + PE + ")";
  }
}
