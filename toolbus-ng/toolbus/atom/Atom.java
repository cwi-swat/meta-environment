/**
 * @author paulk
 */

package toolbus.atom;

import java.util.*;

import toolbus.*;
import toolbus.process.*;

import aterm.*;

class Ref {
  protected ATerm value;

  public Ref(ATerm at) {
    this.value = at;
  }
}

abstract public class Atom extends AbstractProcessExpression {
  private ProcessInstance processInstance;
  // process instance to which the atom belongs
  private Environment env; // the environment of that process instance
  private ATerm test; // optional test that guards this atom
  private Ref[] atomArgs = new Ref[0];


  public Atom(){
    super();
    addToFirst(this);
  }
  public void setAtomArgs(Ref r) {
    atomArgs = new Ref[] { r };
  }

  public void setAtomArgs(Ref r1, Ref r2) {
    atomArgs = new Ref[] { r1, r2 };
  }

  public void setAtomArgs(Ref r1, Ref r2, Ref r3) {
    atomArgs = new Ref[] { r1, r2, r3 };
  }

  public void setAtomArgs(Ref[] refs) {
    atomArgs = refs;
  }


  public Environment getEnv() {
    return env;
  }
  
   public ProcessState getStartState() {
    return getFirst();
  }

  public ATerm getTest() {
    return test;
  }

  public void setTest(ATerm test) throws ToolBusException {
    this.test = TBTerm.compileVars(test, env);
  }

  public ProcessInstance getProcess() {
    return processInstance;
  }

  public ToolBus getToolBus() {
    return processInstance.getToolBus();
  }
  
   public AtomSet getAtoms() {
    return getFirst();
  }


  public String toString() {
    ATerm pid;
    if(processInstance != null){
      pid = processInstance.getProcessId();
    } else {
      pid = null;
    }
      
    String strtest = (test == null) ? "" : " if " + test;
    String res =  this.getClass().getName() + "[" + pid + "]( " ;
    String sep = "";
    for(int i = 0; i < atomArgs.length; i++){
      res = res + sep + atomArgs[i].value;
      sep = ", ";
    }
    return res + ")" + strtest;
  }
  
    public ATerm toATerm() throws ToolBusException {
    return null;
//    int nargs = args.getLength();
//
//    AFun afun = TBTerm.factory.makeAFun(this.getClass().getName(), nargs, false);
//    ATerm pat = TBTerm.makePattern(args, getEnv(), true);
//
//    return TBTerm.factory.makeAppl(afun, (ATermList) pat);
  }

 
  public boolean canCommunicate(Atom a) {
    return false;
  }

  public void addPartner(Atom a) {
    throw new ToolBusInternalError("addPartner not defined");
  }

  public AtomSet getPartners() {
    throw new ToolBusInternalError("getPartners not defined");
  }

  public boolean hasPartners() {
    //return partners.size() > 0;
    return false;
  }

  public void expand(ProcessInstance P, Stack calls) {

  }

  public void compile(ProcessInstance processInstance, AtomSet follow) throws ToolBusException {
    this.processInstance = processInstance;
    env = processInstance.getEnv();
    setFollow(follow);
    System.out.println(this.getClass().getName() + ": compiling");
    for (int i = 0; i < atomArgs.length; i++) {
      System.out.println("atomArg[" + i + "] = " + atomArgs[i]);
      ATerm arg = TBTerm.compileVars(atomArgs[i].value, env);
      atomArgs[i].value = arg;
    }
  }

 public boolean isEnabled() throws ToolBusException {
    if (test == null)
      return true;
    else {
      boolean res = TBTerm.isTrue(TBTerm.eval(test, env));
      //System.out.println(this.getProcess().getProcessId() + ": " + this + " : evaluate: " + test + " ==> " + res);
      return res;
    }
  }
  
  public boolean execute() throws ToolBusException {
    if (!isEnabled()) {
      return false;
    } else {
      return true;
    }
  }

 

}
