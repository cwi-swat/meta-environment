package toolbus.atom;

import toolbus.*;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

import aterm.*;

/**
 * @author paulk, Aug 7, 2002
 */
abstract class ToolAtom extends Atom {
  private Ref toolTerm;
  private Ref id;
  private ToolBus TB;
  private ATermList matchPattern;

  public ToolAtom(ATerm trm) {
    super();
    this.toolTerm = new Ref(trm);
    this.id = new Ref(this instanceof Event ? TBTerm.TransactionIdResVar : TBTerm.TransactionIdVar);
    setAtomArgs(this.toolTerm, this.id);
  }

  public ToolBus getTB() {
    return TB;
  }

  public ATerm getToolTerm() {
    return toolTerm.value;
  }

  public ATerm getId() {
    return id.value;
  }

  public ToolInstance getToolInstance() throws ToolBusException {
    ToolInstance ti = getProcess().getToolInstance();
    if (ti == null) {
      throw new ToolBusException("null tool instance");
    } else {
      return ti;
    }
  }
  
  public ATermList getMatchPattern(){
    return matchPattern;
  }

  public ATermAppl getSubstitutedCall() throws ToolBusException {
    ATerm trm = TBTerm.substitute(toolTerm.value, getEnv());
    if (trm.getType() != ATerm.APPL) {
      throw new ToolBusInternalError("application expected");
    } else
      return (ATermAppl) trm;
  }
  
  public ATerm getSubstitutedId() throws ToolBusException {
    return TBTerm.substitute(id.value, getEnv());
  }
  
  public void compile(ProcessInstance P, State follow) throws ToolBusException {
    super.compile(P, follow);

    TB = getProcess().getToolBus();
    ATermFactory factory = TB.getFactory();

    if (toolTerm.value.getType() != ATerm.APPL)
      throw new ToolBusException("argument should be an application: " + toolTerm.value);
    if (!(TBTerm.isVar(id.value) || TBTerm.isResVar(id.value))) {
      throw new ToolBusException("argument should be a variable " + toolTerm.value);
    }
    matchPattern = factory.makeList(toolTerm.value, factory.makeList(id.value));
  }

}
