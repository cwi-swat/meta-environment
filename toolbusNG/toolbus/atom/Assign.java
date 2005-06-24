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

  public void compile(ProcessInstance P, Environment env, State follow) throws ToolBusException {
    super.compile(P, env, follow);
    //System.err.println("Assign.compile: env =" + getEnv());
    if (!TBTerm.isVar(var.value))
      throw new ToolBusException("left-hand side of := should be a variable");
    ATerm vartype = TBTerm.getVarType(var.value);
    
    //System.err.println(this + "; var = " + var +"; vartype = " + vartype);
    
    //System.err.println("Assign: " + env);
    ATerm exptype = FunctionDescriptors.checkType(exp.value, env, false);

    if (!FunctionDescriptors.compatibleType(vartype, exptype) )// lhs = term!
      throw new ToolBusException(" wrong types in assignment: " + vartype + " := " + exptype);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ProcessInstance p = this.getProcess();
    Environment env = getEnv();
    //System.err.println("Assign: " + env);

    ATerm newval = FunctionDescriptors.eval(exp.value, p, env);
    
    //System.err.println("Assign: " + exp.value + "   " + newval);
    env.assignVar(var.value, newval);
    //System.err.println("Assign: " + env);
    //System.err.println("Assign: " + getFollow());
    return nextState();
  }
}
