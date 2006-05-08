/**
 * @author paulk
 */

package toolbus.atom;

import java.util.HashMap;
import java.util.List;
import java.util.Stack;
import java.util.Vector;

import toolbus.AtomSet;
import toolbus.Functions;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermList;

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
  protected Environment env;                 // the environment of this atom
  private Vector<Test> tests;             // optional tests that guard this atom
  private Ref[] atomArgs = new Ref[0];
  private int delay = 0;
  private int timeout = 0;
  private boolean timeExpr = false;
  private int startTime;
  protected String externalNameAsReceivedByTool;
  
  static private HashMap<String,Integer> instances = new HashMap<String,Integer>(40);
  static private HashMap<String,Integer> enabled = new HashMap<String,Integer>(40);
  static private HashMap<String,Integer> notEnabled = new HashMap<String,Integer>(40);
  static private HashMap<String,Integer> npartners = new HashMap<String,Integer>(40);
  static private HashMap<String,Integer> size_env = new HashMap<String,Integer>(40);
  static private HashMap<String,Integer> size_used_env = new HashMap<String,Integer>(40);

  public Atom(TBTermFactory tbfactory, ATerm posInfo) {
    super(tbfactory, posInfo);
    assert tbfactory != null;
    addToFirst(this);
    externalNameAsReceivedByTool = shortName();
    incr(instances);
  }
  
  protected void incr(HashMap<String,Integer> map){
	 incr(map, 1);
  }
  
  protected void incr(HashMap<String,Integer> map, int d){
	  String name = this.getClass().getName();
	  if(map.containsKey(name)){
		  int n = map.get(name);
		  map.put(name,n+d);
	  } else {
		  map.put(name,d);
	  }
  }
  
  public static void statistics(){
	  int ninstances = 0;
	  int nenabled = 0;
	  int nNotEnabled = 0;
	  System.err.printf("\n========================= Atom Statistics ========================\n");
 
	  for(String name : instances.keySet()){
		  int ins = instances.get(name); ninstances += ins;
		  int en = enabled.get(name) == null ? 0 : enabled.get(name); nenabled += en;
		  int ne = notEnabled.get(name) == null ? 0 : notEnabled.get(name); nNotEnabled += ne;
		  System.err.printf("| %30s%8d%8d (+)%8d (-) |\n", name, ins, en, ne);		  			  
	  }
	  System.err.printf("| %30s%8d%8d    %8d     |\n", "TOTAL", ninstances, nenabled, nNotEnabled);
	  System.err.printf("==================================================================\n");
	  
	  for(String name : instances.keySet()){
		  System.err.printf("%s, %d, %d\n", name, size_env.get(name), size_used_env.get(name));
	  }
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

  public void setTest(ATerm test, Environment e) throws ToolBusException {
  	if(test != null){
  		//env = e.copy();  //TODO OK?
  		env = e;
	    ATerm rtst = tbfactory.resolveVarTypes(test, env);
	    if (tests == null)
	    	tests = new Vector<Test>(3);
	    Test t = new Test(rtst, env);
	    //System.out.println("setTest: " + t);
	    this.tests.addElement(t);
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

  public AtomSet getAtoms() {
    return new AtomSet(this);
  }

  private String shortName() {
    String s = this.getClass().getName();
    int i = s.lastIndexOf(".");
    return s.substring(i + 1);
  }
  
  private String externalNameReceivedByTool() {
  	return shortName();
  }

  public String toString() {
    String pidStr = (processInstance != null) ? "[" + processInstance.getProcessId() + "]" : "";
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
    //System.err.println("toATerm: " + externalNameAsReceivedByTool);
    
    
    AFun afun = tbfactory.makeAFun(externalNameAsReceivedByTool, nargs, false);
    ATerm pat[] = new ATerm[nargs];

    for (int i = 0; i < nargs; i++) {
      pat[i] = tbfactory.makePattern(atomArgs[i].value, true);
    }
    return tbfactory.makeAppl(afun, pat);
  }

 // public void expand(ProcessInstance P, Stack calls) {}
  
  public void computeFirst() {}
  
  public void replaceFormals(Environment e) throws ToolBusException{
		 //this.env = e.copy();
	  this.env = e;
		 //System.err.println("Atom.replaceFormals: " + env);
	  	 for (int i = 0; i < atomArgs.length; i++) {
	        //System.err.println("atomArg[" + i + "] = " + atomArgs[i] + " ; env = " + env);
	        ATerm arg = tbfactory.resolveVarTypes(atomArgs[i].value, env);
	        arg = tbfactory.replaceFormals(arg, env);
	        //System.err.println("atomArg[" + i + "] = " + atomArgs[i].value + " => " + arg + "; env = " + env);
	        atomArgs[i].value = arg;
	      }
	  }

  public void compile(ProcessInstance processInstance, Stack<String> calls, State follow) throws ToolBusException {
      //this.env = env.copy();
	  this.env = env;
	  this.processInstance = processInstance;
  	//this.env = env.copy();
  	//System.err.println("Atom.compile, prev env = " + env);
  	//this.env = env.copy();
    setFollow(follow);
    //System.err.println("Compiling " + this + ";\n env = " + this.env);
    //replaceFormals(env);  //TODO redundant?
  }

  // Implementation of the StateElement interface
  
  public boolean isEnabled() throws ToolBusException {
   	//System.err.println("Atom.isEnabled: " + this.getProcess().getProcessId() + ": " + this);
	if(timeExpr){
  		//System.err.println("Has a TimeExpr; delay = " + delay + "; timeout = " + timeout);
  		int currentTime = (int) getToolBus().getRunTime();
  	    //System.err.println("startTime = " + startTime + "; currentTime = " + currentTime);
  		if(delay != 0 && currentTime < startTime + delay){
  			//System.err.println("currentTime < startTime + delay");
  			incr(notEnabled);
  			return false;
  		}
  		if(timeout != 0 && currentTime > startTime + timeout){
  			//System.err.println("currentTime > startTime + timeout");
  			incr(notEnabled);
  			return false;
  		}
  	}
    if (tests != null){
    	//System.err.println("Atom.isEnabled: " + this.getProcess().getProcessId() + ": " + this);
    	for(int i = 0; i < tests.size(); i++){
    		Test t = tests.elementAt(i);
    		//System.err.println("evaluate: " + t);
    		boolean res = tbfactory.isTrue(Functions.eval(t.testExpr, getProcess(), t.testEnv));
    		//System.err.println("==> " + res);
    		if(!res){
    			incr(notEnabled);
    			return false;
    		}
    	}
    }
    incr(enabled);
    return true;
  }

  public boolean contains(StateElement b) {
    return this == b;
  }

  public ProcessInstance getProcess() {
    return processInstance;
  }
  
  public void addPartners(AtomSet s) throws ToolBusException{
  }
  
  public void delPartners(AtomSet s) throws ToolBusException{
  }

  public State gotoNextStateAndActivate(){
  	//System.err.println(this + "getNextState ==> " + getFollow());
  	State s = getFollow();
  	s.activate();
  	return s;
  }
  
  public State gotoNextStateAndActivate(StateElement b){
  	if(this.equals(b)){
  		State s = getFollow();
  		s.activate();
  		return s;
  	}
  	System.err.println("Atom.getNextState2: wrong arg: " + b);  //TODO exception
  	return null;
  }
  
  public void activate(){
  	if(timeExpr){
  		startTime = (int) getToolBus().getRunTime();
  		int next = (delay != 0) ? startTime + delay : startTime;
  		getToolBus().setNextTime(next);
  	}
  	incr(size_env, env.size());
 
  	ATermList collected = tbfactory.EmptyList;
 	 for (int i = 0; i < atomArgs.length; i++) {
 		    collected = tbfactory.getVariables(atomArgs[i].value, collected);
	      }
  	
  	incr(size_used_env, collected.getLength());
  	
  	//System.err.println("used_vars = " + collected);
  	//System.err.println("Atom.activate: " + this);
  	
  }

  abstract public boolean execute() throws ToolBusException;
}
