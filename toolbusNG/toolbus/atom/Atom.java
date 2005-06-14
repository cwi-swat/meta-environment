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

abstract public class Atom extends AbstractProcessExpression implements StateElement {
  private ProcessInstance processInstance;
  // process instance to which the atom belongs
  private Environment env; // the environment of that process instance
  private ATerm test; // optional test that guards this atom
  private Ref[] atomArgs = new Ref[0];

  public Atom() {
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
  
  public void addAtomArg(ATerm arg){
    int n = atomArgs.length;
    Ref[] newAtomArgs = new Ref[n+1];
    for(int i = 0; i < n; i++){
      newAtomArgs[i] = atomArgs[i];
    }
    newAtomArgs[n] = new Ref(arg);
    atomArgs = newAtomArgs;
  }
  
  public ATerm getAtomArgValue(int i){
    return atomArgs[i].value;
  }

  public Environment getEnv() {
    return env;
  }

  public State getStartState() {
    return getFirst();
  }

  public ATerm getTest() {
    return test;
  }

  public void setTest(ATerm test) throws ToolBusException {
  	if(test != null){
	    //ATerm rtst = TBTerm.resolveVars(test, processInstance.getEnv());
	    if (this.test == null) {
	      this.test = test;
	    } else {
	      this.test = TBTerm.factory.make("and(<term>,<term>)", test, this.test);
	    }
  	}
  }

  public ToolBus getToolBus() {
    return processInstance.getToolBus();
  }

  public State getAtoms() {
    return getFirst();
  }

  private String shortName() {
    String s = this.getClass().getName();
    int i = s.lastIndexOf(".");
    return s.substring(i + 1);
  }

  public String toString() {
    String pidStr;
    if (processInstance != null) {
      pidStr = "[" + processInstance.getProcessId().toString() + "]";
    } else {
      pidStr = "";
    }

    String args = "(";
    String sep = "";
    for (int i = 0; i < atomArgs.length; i++) {
      args = args + sep + atomArgs[i].value;
      sep = ", ";
    }
    args = args + ")";

    String strtest = (test == null) ? "" : " if " + test;

    return shortName() + pidStr + args + strtest;
  }

  public ATerm toATerm() throws ToolBusException {
    int nargs = atomArgs.length;

    AFun afun = TBTerm.factory.makeAFun(shortName(), nargs, false);
    ATermList pat = TBTerm.factory.makeList();

    for (int i = 0; i < nargs; i++) {
      pat = pat.append(TBTerm.makePattern(atomArgs[i].value, getEnv(), true));
    }

    return TBTerm.factory.makeAppl(afun, pat);
  }

  public void expand(ProcessInstance P, Stack calls) {

  }

  public void compile(ProcessInstance processInstance, State follow) throws ToolBusException {
    this.processInstance = processInstance;
    env = processInstance.getEnv();
    setFollow(follow);
    //System.err.println(this.getClass().getName() + ": compiling");
    /*
    for (int i = 0; i < atomArgs.length; i++) {
      //System.err.println("atomArg[" + i + "] = " + atomArgs[i]);
      ATerm arg = TBTerm.resolveVars(atomArgs[i].value, env);
      atomArgs[i].value = arg;
    }
    */
  }

  public boolean isEnabled() throws ToolBusException {
    if (test == null)
      return true;
    else {
      boolean res = TBTerm.isTrue(FunctionDescriptors.eval(test, getProcess()));
      //System.err.println(this.getProcess().getProcessId() + ": " + this + " : evaluate: " + test + " ==> " + res);
      return res;
    }
  }

  // Implementation of the StateElement interface

  public boolean contains(StateElement b) {
    return this.equals(b);
  }

  public ProcessInstance getProcess() {
    return processInstance;
  }

  public boolean nextState() {
    State s = getFollow();
    processInstance.setCurrentState(s);
    return true;
  }

  public boolean execute() throws ToolBusException {
    if (!isEnabled()) {
      return false;
    } else {

      return nextState();
    }
  }

}
