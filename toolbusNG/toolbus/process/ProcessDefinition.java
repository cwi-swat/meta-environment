/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import java.util.*;
import java.util.Vector;

import toolbus.*;
import toolbus.atom.*;
import toolbus.tool.*;

import aterm.*;

public class ProcessDefinition {
  private static int ninstances = 0;
  private String name;
  private ATermList formals;
  private ProcessExpression PE;
  private String toolname;

  public ProcessDefinition(String name, ATermList formals, ProcessExpression PE, String toolname) {
    this.name = name;
    this.formals = formals;
    this.PE = PE;
    this.toolname = toolname;

    //System.err.println("procdef " + name + " " + formals + " " + PE);
  }

  public ProcessDefinition(String name, ATermList formals, ProcessExpression PE) {
    this(name, formals, PE, null);
  }

  public ProcessDefinition(String name, ProcessExpression PE) {
    this(name, (ATermList) TBTerm.factory.make("[]"), PE, null);
  }

  public String getName() {
    return name;
  }

  public void enterScope(Environment env, ATermList actuals) throws ToolBusException {
    env.add(formals, actuals);
  }

  public void leaveScope(Environment env) {
    env.delete(formals.getLength());
  }

  public ATermList getCompiledFormals(Environment env) throws ToolBusException {
    return (ATermList) TBTerm.resolveVars(formals, env);
  }

  public ProcessExpression expand(ProcessInstance P, Stack calls, ATermList actuals) throws ToolBusException {
    if (actuals.getLength() != formals.getLength()) {
      throw new ToolBusException(name + ": mismatch " + formals + " and " + actuals);
    }
    for (int i = 0; i < actuals.getLength(); i++) {
      ATerm formal = (ATerm) formals.getChildAt(i);
      ATerm actual = (ATerm) formals.getChildAt(i);
      if (TBTerm.isResVar(formal) && !TBTerm.isResVar(actual)) {
        throw new ToolBusException(name + ": mismatch " + formal + " and " + actual);
      }
    };
    ProcessExpression PE1 = PE.copy();
    PE1.expand(P, calls);
    return PE1;
  }

 
    public String toString() {
      return "ProcessDefinition(" + name + ", " + formals + ", " + PE + ")";
    }

  private ATermList makeSig() throws ToolBusException {
    ATermList sig = (ATermList) TBTerm.factory.make("[]");
    Vector atoms = PE.getAtoms().getElementsAsVector();
    for (int i = 0; i < atoms.size(); i++) {
      ATerm pat = ((Atom) atoms.get(i)).toATerm();
      sig = TBTerm.factory.makeList(pat, sig);
    }
    return sig;
  }

  public ToolInstance createToolInstance() throws ToolBusException {
    if (toolname == null)
      return null;
    else {
      AFun afun = TBTerm.factory.makeAFun(name, 1, false);
      ATermAppl tid = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(ninstances));
      ninstances++;
      return new JavaTool(toolname, tid, makeSig());
    }
  }
}
