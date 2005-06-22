/**
 * @author paulk
 */

package toolbus.atom;

import java.util.*;

import toolbus.*;
import toolbus.process.*;

import aterm.*;

class Test {
	ATerm testExpr;
	Environment testEnv;
	
	public Test(ATerm test, Environment env){
		testExpr = test;
		testEnv = env;
	}
	public String toString(){
		return "Test(" + testExpr + ", " + testEnv + ")";
	}
}

abstract public class Atom extends ProcessExpression implements StateElement {
  private ProcessInstance processInstance; // process instance to which the atom belongs
  private Environment env;                 // the environment of this atom
  private Vector tests;                    // optional tests that guard this atom
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

  public void setTest(ATerm test, Environment env) throws ToolBusException {
  	if(test != null){
  		env = env.copy();
	    ATerm rtst = TBTerm.resolveVars(test, env);
	    if (tests == null)
	    	tests = new Vector(3);
	    Test t = new Test(rtst, env);
	    //System.out.println("setTest: " + t);
	    this.tests.add(t);
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

    String strtest = (tests == null) ? "" : " if " + tests;

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

  public void compile(ProcessInstance processInstance, Environment env, State follow) throws ToolBusException {
  	this.processInstance = processInstance;
  	this.env = env.copy();
    setFollow(follow);
    System.err.println("Compiling " + this + ";\n env = " + env);
    replaceFormals(env);
  }
  
  public void replaceFormals(Environment env) throws ToolBusException{
  	 for (int i = 0; i < atomArgs.length; i++) {
        //ystem.err.println("atomArg[" + i + "] = " + atomArgs[i] + " ; env = " + env);
        ATerm arg = TBTerm.resolveVars(atomArgs[i].value, env);
        atomArgs[i].value = arg;
      }
  }

  public boolean isEnabled() throws ToolBusException {
    if (tests != null){
    	//System.err.println("isEnabled: " + this.getProcess().getProcessId() + ": " + this);
    	for(int i = 0; i < tests.size(); i++){
    		Test t = (Test) tests.elementAt(i);
    		//System.err.println("evaluate: " + t);
    		boolean res = TBTerm.isTrue(FunctionDescriptors.eval(t.testExpr, getProcess(), t.testEnv));
    		//System.err.println("==> " + res);
    		if(!res)
    			return false;
    	}
    }
    return true;
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
