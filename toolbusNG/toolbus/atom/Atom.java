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
  private int delay = 0;
  private int timeout = 0;
  private boolean timeExpr = false;
  private int startTime;

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
  
  public void copyAtomAttributes(Atom a){
  	delay = a.delay;
  	timeout = a.timeout;
  	timeExpr = a.timeExpr;
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

  public void addTimeExpr(ATerm t) {
  	
  	try {
	List matches = t.match("delay(<int>)");
	
	if (matches != null) {
		Integer n = (Integer) matches.get(0);
		delay = n.intValue();
		timeExpr = true;
		System.err.println("Added delay " + delay);
		return;
	}
	
	matches = t.match("timeout(<int>)");
	
	if (matches != null) {
		Integer n = (Integer) matches.get(0);
		timeout = n.intValue();
		timeExpr = true;
		System.err.println("Added timeout " + timeout);
		return;
	}
  	} catch (Exception e) {
  	   System.out.println("addTimeExpr, cannot handle: " + e);
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
    String pidStr = (processInstance != null) ? "[" + processInstance.getProcessId().toString() + "]" : "";
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

  public void expand(ProcessInstance P, Stack calls) {}

  public void compile(ProcessInstance processInstance, Environment env, State follow) throws ToolBusException {
  	this.processInstance = processInstance;
  	this.env = env.copy();
    setFollow(follow);
    System.err.println("Compiling " + this + ";\n env = " + env);
    replaceFormals(env);
  }
  
  public void replaceFormals(Environment env) throws ToolBusException{
  	 for (int i = 0; i < atomArgs.length; i++) {
        //System.err.println("atomArg[" + i + "] = " + atomArgs[i] + " ; env = " + env);
        ATerm arg = TBTerm.resolveVars(atomArgs[i].value, env);
        atomArgs[i].value = arg;
      }
  }

  // Implementation of the StateElement interface
  
  public boolean isEnabled() throws ToolBusException {
   	System.err.println("Atom.isEnabled: " + this.getProcess().getProcessId() + ": " + this);
	if(timeExpr){
  		System.err.println("Has a TimeExpr; delay = " + delay + "; timeout = " + timeout);
  		int currentTime = (int) getToolBus().getRunTime();
  	    System.err.println("startTime = " + startTime + "; currentTime = " + currentTime);
  		if(delay != 0 && currentTime < startTime + delay){
  			System.err.println("currentTime < startTime + delay");
  			return false;
  		}
  		if(timeout != 0 && currentTime > startTime + timeout){
  			System.err.println("currentTime > startTime + timeout");
  			return false;
  		}
  	}
    if (tests != null){
    	//System.err.println("Atom.isEnabled: " + this.getProcess().getProcessId() + ": " + this);
    	for(int i = 0; i < tests.size(); i++){
    		Test t = (Test) tests.elementAt(i);
    		//System.err.println("evaluate: " + t);
    		boolean res = TBTerm.isTrue(Functions.eval(t.testExpr, getProcess(), t.testEnv));
    		//System.err.println("==> " + res);
    		if(!res)
    			return false;
    	}
    }
    return true;
  }

  public boolean contains(StateElement b) {
    return this.equals(b);
  }

  public ProcessInstance getProcess() {
    return processInstance;
  }

  public State getNextState(){
  	//System.err.println(this + "getNextState ==> " + getFollow());
  	State s = getFollow();
  	s.activate();
  	return s;
  }
  
  public State getNextState(StateElement b){
  	if(this.equals(b)){
  		return getFollow();
  	}
  	System.err.println("Atom.getNextState2: wrong arg: " + b);
  	return null;
  }
  
  public void activate(){
  	System.err.println("activate");
  	if(timeExpr){
  		startTime = (int) getToolBus().getRunTime();
  		int next = (delay != 0) ? startTime + delay : startTime;
  		getToolBus().setNextTime(next);
  	}
  }

  abstract public boolean execute() throws ToolBusException;
}
