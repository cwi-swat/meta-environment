/**
 * @author paulk, Jul 24, 2002
 */
package toolbus.atom;

import toolbus.*;
import toolbus.process.*;

import aterm.*;

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
    return new Create(pcall.value, rvar.value);
  }

  public void compile(ProcessInstance P, State follow) throws ToolBusException {
    super.compile(P, follow);
 
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
    ATermList evargs = (ATermList) TBTerm.eval(cargs, getProcess());

    ToolBus TB = getProcess().getToolBus();

    ProcessInstance P = TB.addProcess(name, evargs);

    getEnv().putVar(rvar.value, P.getProcessId());
    return nextState();

  }
}
