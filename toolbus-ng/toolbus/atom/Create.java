/**
 * @author paulk, Jul 24, 2002
 */
package toolbus.atom;

import toolbus.Environment;
import toolbus.Functions;
import toolbus.State;
import toolbus.TBTerm;
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

  public Create(ATerm c, ATerm v) {
    super();
    pcall = new Ref(c);
    rvar = new Ref(v);
    setAtomArgs(pcall, rvar);
  }
  
  public ProcessExpression copy(){
    Atom a = new Create(pcall.value, rvar.value);
    a.copyAtomAttributes(this);
    return a;
  }

  public void compile(ProcessInstance P, Environment env, State follow) throws ToolBusException {
    super.compile(P, env, follow);
 
    if (pcall.value.getType() != ATerm.APPL)
      throw new ToolBusException("malformed first argument in create");
    if (!TBTerm.isResVar(rvar.value))
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

    getEnv().assignVar(rvar.value, TBTerm.factory.makeInt(P.getProcessId()));
    //System.err.println("Create.execute: process " +  P.getProcessId() + " added");
    return true;

  }
}
