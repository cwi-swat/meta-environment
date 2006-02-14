/**
 * @author paulk, Jul 24, 2002
 */
package toolbus.atom;

import java.util.Stack;

import toolbus.Environment;
import toolbus.Functions;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class Create extends Atom {
  private Ref pcall;
  private Ref rvar;

  public Create(ATerm c, ATerm v, TBTermFactory tbfactory) {
    super(tbfactory);
    pcall = new Ref(c);
    rvar = new Ref(v);
    setAtomArgs(pcall, rvar);
  }
  
  public ProcessExpression copy(){
    Atom a = new Create(pcall.value, rvar.value, tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }

  public void compile(ProcessInstance P, Stack<String> calls, Environment env, State follow) throws ToolBusException {
    super.compile(P, calls, env, follow);
 
    if (pcall.value.getType() != ATerm.APPL)
      throw new ToolBusException("malformed first argument in create");
    if (!tbfactory.isResVar(rvar.value))
      throw new ToolBusException("second argument of create should be a result variable");
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled())
      return false;
    String name = ((ATermAppl) pcall.value).getName();
    ATermList cargs = ((ATermAppl) pcall.value).getArguments();
    ATermList evargs = (ATermList) Functions.eval(cargs, getProcess(), getEnv());

    ToolBus TB = getProcess().getToolBus();

    ProcessInstance P = TB.addProcess(name, evargs);

    getEnv().assignVar((TBTermVar)rvar.value, tbfactory.makeInt(P.getProcessId()));
    //System.err.println("Create.execute: process " +  P.getProcessId() + " added");
    return true;

  }
}
