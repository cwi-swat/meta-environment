/**
 * @author paulk, Jul 20, 2002
 */
package toolbus.atom;

import toolbus.*;
import toolbus.process.*;
import toolbus.process.ProcessInstance;

import aterm.ATerm;

public class Assign extends Atom {
  private Ref var;
  private Ref exp;

  public Assign(ATerm v, ATerm e) {
    super();
    var = new Ref(v);
    exp = new Ref(e);
    setAtomArgs(var, exp);
  }
  
  public ProcessExpression copy(){
    return new Assign(var.value,  exp.value);
  }

  public void compile(ProcessInstance P, State follow) throws ToolBusException {
    super.compile(P, follow);

    if (!TBTerm.isVar(var.value))
      throw new ToolBusException("left-hand side of := should be a variable");
    ATerm vartype = TBTerm.getVarType(var.value);

    ATerm exptype = FunctionDescriptors.checkType(exp.value, this.getEnv());

    if (!TBTerm.assignCompatible(vartype, exptype) )// lhs = term!
      throw new ToolBusException(" wrong types in assignment: " + vartype + " := " + exptype);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    Environment e = this.getEnv();
    ProcessInstance p = this.getProcess();

    ATerm newval = FunctionDescriptors.eval(exp.value, p);
    
    //System.err.println(exp.value + "   " + newval);
    e.assignVar(var.value, newval);
    return nextState();
  }
}
