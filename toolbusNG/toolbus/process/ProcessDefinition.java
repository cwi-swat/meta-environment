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

  public ProcessDefinition(String name, ATermList formals, ProcessExpression PE) {
    this.name = name;
    this.formals = formals;
    this.PE = PE;
  }

  public ProcessDefinition(String name, ProcessExpression PE) {
    this(name, (ATermList) TBTermFactory.make("[]"), PE);
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
      if (TBTermFactory.isResVar(formal) && !TBTermFactory.isResVar(actual)) {
        throw new ToolBusException(name + ": mismatch " + formal + " and " + actual);
      }
    };
    ProcessExpression PE1 = new Sequence(PE.copy(), new EndScope(formals));
    //PE1.expand(P, calls);
    //System.err.println("ProcessDef.expand => " + PE1);
    return PE1;
  }

  public String toString() {
    return "ProcessDefinition(" + name + ", " + formals + ", " + PE + ")";
  }
}
