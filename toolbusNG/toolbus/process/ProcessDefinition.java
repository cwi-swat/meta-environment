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
  private ATermList nonResultFormals;
  private ProcessExpression PE;
  private String toolname;

  public ProcessDefinition(String name, ATermList formals, ProcessExpression PE, String toolname) {
    this.name = name;
    this.formals = formals;
    this.PE = PE;
    this.toolname = toolname;

    //System.out.println("procdef " + name + " " + formals + " " + PE);
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
  
  public void enterScope(Environment env){
     env.add(nonResultFormals);
  }
  
  public void leaveScope(Environment env){
       env.delete(nonResultFormals.getLength());
  }
  
  public ProcessExpression expand(ProcessInstance P, Stack calls, ATermList actuals) throws ToolBusException {

    if (actuals.getLength() != formals.getLength())
      System.out.println("*** " + name + ": mismatch " + formals + " and " + actuals);

    //		System.out.println("formals = " + formals);
    //		System.out.println("actuals = " + actuals);

    int nargs = actuals.getLength();
    Environment env = P.getEnv();
    ATermList actuals1 = (ATermList) TBTerm.compileVars(actuals, env);
    //		System.out.println("actuals1 = " + actuals1);

    ProcessExpression assigns = null;

    nonResultFormals = formals.getFactory().makeList();

    for (int i = 0; i < nargs; i++) {
      ATerm formal = formals.elementAt(i);
      if (TBTerm.isResVar(formal))
        formal = TBTerm.compileVars(TBTerm.changeResVarIntoVar(formal), env);
      else
        nonResultFormals = nonResultFormals.append(formal);

      ProcessExpression asg = new Assign(formal, actuals1.elementAt(i));
      if (i == 0)
        assigns = asg;
      else
        assigns = new Sequence(asg, assigns);
    }
    //		System.out.println("formals1 = " + formals1);
    //		System.out.println("assigns = " + assigns);
    ProcessExpression PE1 = (assigns == null) ? PE.copy(): new Sequence(assigns, PE.copy());
    //		System.out.println("PE1 = " + PE1);
    //		System.out.println("env = " + env);
    PE1.expand(P, calls);
    return PE1;
  }

  public String toString() {
    return "ProcessDefinition(" + name + ", " + formals + ", " + PE + ")";
  }

  private ATermList makeSig() throws ToolBusException {
    ATermList sig = (ATermList) TBTerm.factory.make("[]");
    Vector atoms = PE.getAtoms().getAtomsAsVector();
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
