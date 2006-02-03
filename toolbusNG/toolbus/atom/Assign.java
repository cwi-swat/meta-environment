/**
 * @author paulk, Jul 20, 2002
 */
package toolbus.atom;

import java.util.Stack;

import toolbus.*;
import toolbus.process.*;

import aterm.ATerm;

public class Assign extends Atom {
  private Ref var;
  private Ref exp;

  public Assign(ATerm v, ATerm e, TBTermFactory tbfactory) {
    super(tbfactory);
    var = new Ref(v);
    exp = new Ref(e);
    setAtomArgs(var, exp);
  }
  
  public ProcessExpression copy(){
    Atom a = new Assign(var.value,  exp.value, tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }
  
  public void replaceFormals(Environment env) throws ToolBusException {
  	//System.err.println("Assign.replaceformals: " + var.value + "; " + exp.value);
  	var.value = tbfactory.resolveVars(var.value, env);
 	//System.err.println("Assign.replaceformals: " + var.value);
  	var.value = tbfactory.replaceAssignableVar((TBTermVar)var.value, env);
    exp.value = tbfactory.resolveVars(exp.value, env);
    exp.value = tbfactory.replaceFormals(exp.value, env);
	//System.err.println("Assign.replaceformals:  => " + var.value + "; " + exp.value);
 }


  public void compile(ProcessInstance P, Stack calls, Environment env, State follow) throws ToolBusException {
    super.compile(P, calls, env, follow);
    //System.err.println("Assign.compile: " + this + " env =" + getEnv());
    if (!tbfactory.isAnyVar(var.value))
      throw new ToolBusException("left-hand side of := should be a variable");
    ATerm vartype = ((TBTermVar)var.value).getVarType();
    
    //System.err.println(this + "; var = " + var +"; vartype = " + vartype);
    
    //System.err.println("Assign: " + env);
    ATerm exptype = Functions.checkType(exp.value, env, false);
    //System.err.println(this + "; exp = " + exp.value + "; exptype = " + exptype);

    if (!Functions.compatibleTypes(vartype, exptype) )// lhs = term!
      throw new ToolBusException(" wrong types in assignment: " + vartype + " := " + exptype);
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    ProcessInstance p = this.getProcess();
    Environment env = getEnv();
    //System.err.println("Atom.execute: "+ this);
    //System.err.println("Assign: " + this);
    //System.err.println("Assign: " + env);

    ATerm newval = Functions.eval(exp.value, p, env);
    
    //System.err.println("Assign.execute: " + exp.value + "; " + newval);
    env.assignVar((TBTermVar)var.value, newval);
    //System.err.println("Assign: " + env);
    //System.err.println("Assign: " + getFollow());
    return true;
  }
}
