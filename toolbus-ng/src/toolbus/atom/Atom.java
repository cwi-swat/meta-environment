/**
 * @author paulk
 */

package toolbus.atom;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Stack;

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

/**
 * This class represents a test associated with an atom.
 * It carries its own execution environment.
 *
 */
class Test{
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

/**
 * The class Atom forms the basic building block of Tscripts. Instances of Atom
 * are both the most primitive elements of process expressions and the elements of
 * the states to which process exprssions are being compiled.
 *
 */

abstract public class Atom extends ProcessExpression implements StateElement{
	private ProcessInstance processInstance; // process instance to which the atom belongs
	private Environment env;                 // the environment of this atom
	private List<Test> tests;              // optional tests that guard this atom
	private Ref[] atomArgs = new Ref[0];    // arguments of the atom
	private int delay = 0;                  // time delay before atom can be executed
	private int timeout = 0;                // timeout after which atom can no longer be executed
	private boolean timeExpr = false;      // the actual time expression for delay/timeout
	private int startTime;                  // when execution of this atom started
	protected String externalNameAsReceivedByTool;
/*	
	static private HashMap<String, Integer> instances = new HashMap<String, Integer>(32);
	static private HashMap<String, Integer> enabled = new HashMap<String, Integer>(32);
	static private HashMap<String, Integer> notEnabled = new HashMap<String, Integer>(32);
	static private HashMap<String, Integer> size_env = new HashMap<String, Integer>(32);
	static private HashMap<String, Integer> size_used_env = new HashMap<String, Integer>(32);
*/
	
	public Atom(TBTermFactory tbfactory, ATerm posInfo){
		super(tbfactory, posInfo);
		assert tbfactory != null;
		addToFirst(this);
		externalNameAsReceivedByTool = shortName();
		/* incr(instances);*/
	}
/*	
	protected void incr(HashMap<String, Integer> map){
		incr(map, 1);
	}
	
	protected void incr(HashMap<String, Integer> map, int d){
		String name = this.getClass().getName();
		if(map.containsKey(name)){
			int n = map.get(name).intValue();
			map.put(name, new Integer(n + d));
		}else{
			map.put(name, new Integer(d));
		}
	}
	
	public static void statistics(){
		int ninstances = 0;
		int nenabled = 0;
		int nNotEnabled = 0;
		System.err.printf("\n========================= Atom Statistics ========================\n");
		
		for(String name : instances.keySet()){
			Integer ins = instances.get(name);
			ninstances += ins.intValue();
			Integer en = enabled.get(name) == null ? new Integer(0) : enabled.get(name);
			nenabled += en.intValue();
			Integer ne = notEnabled.get(name) == null ? new Integer(0) : notEnabled.get(name);
			nNotEnabled += ne.intValue();
			System.err.printf("| %30s%8d%8d (+)%8d (-) |\n", name, ins, en, ne);
		}
		System.err.printf("| %30s%8d%8d    %8d     |\n", "TOTAL", new Integer(ninstances), new Integer(nenabled), new Integer(nNotEnabled));
		System.err.printf("==================================================================\n");
		
		for(String name : instances.keySet()){
			System.err.printf("%s, %d, %d\n", name, size_env.get(name), size_used_env.get(name));
		}
	}
*/
	
	public void setAtomArgs(Ref r){
		atomArgs = new Ref[]{r};
	}
	
	public void setAtomArgs(Ref r1, Ref r2){
		atomArgs = new Ref[]{r1, r2};
	}
	
	public void setAtomArgs(Ref r1, Ref r2, Ref r3){
		atomArgs = new Ref[]{r1, r2, r3};
	}
	
	public void setAtomArgs(Ref[] refs){
		atomArgs = refs;
	}
	
	public void addAtomArg(ATerm arg){
		int n = atomArgs.length;
		Ref[] newAtomArgs = new Ref[n + 1];
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
	
	protected void setEnv(Environment env){
		this.env = env;
	}
	
	public Environment getEnv(){
		return env;
	}
	
	public State getStartState(){
		return getFirst();
	}
	
	public void setTest(ATerm test, Environment e) throws ToolBusException{
		if(test != null){
			//System.err.println(this + "." + "setTest: env " + env.hashCode() + " => " + e.hashCode());
			ATerm rtst = tbfactory.resolveVarTypes(test, e);
			if(tests == null) tests = new ArrayList<Test>(3);
			Test t = new Test(rtst, e);
			//System.out.println("setTest: " + t);
			this.tests.add(t);
		}
	}
	
	public void addTimeExpr(ATerm t){
		try{
			List<?> matches = t.match("delay(<int>)");
			
			if(matches != null){
				Integer n = (Integer) matches.get(0);
				delay = n.intValue();
				timeExpr = true;
				System.err.println("Added delay " + delay);
				return;
			}
			
			matches = t.match("timeout(<int>)");
			
			if(matches != null){
				Integer n = (Integer) matches.get(0);
				timeout = n.intValue();
				timeExpr = true;
				System.err.println("Added timeout " + timeout);
				return;
			}
		}catch(Exception e){
			System.out.println("addTimeExpr, cannot handle: " + e);
		}
	}
	
	public ToolBus getToolBus(){
		return processInstance.getToolBus();
	}
	
	public AtomSet getAtoms(){
		return new AtomSet(this);
	}
	
	private String shortName(){
		return getClass().getSimpleName();
	}
	
	public String toString(){
		/*String pidStr = (processInstance != null) ? "[" + processInstance.getProcessName() + "/" + processInstance.getProcessId() + "]" : "";
		String args = "(";
		String sep = "";
		
		for(int i = 0; i < atomArgs.length; i++){
			args = args + sep + atomArgs[i];
			//args = args + sep + tbfactory.substitute(atomArgs[i].value, env);
			sep = ", ";
		}
		args = args + ")";
		String strtest = (tests == null) ? "" : " if " + tests;*/
		if(atomArgs.length > 0){
			StringBuilder sb = new StringBuilder();
			sb.append(shortName());
			sb.append('(');
			sb.append(atomArgs[0].value);
			int nrOfAtomArgs = atomArgs.length;
			for(int i = 1; i < nrOfAtomArgs; i++){
				sb.append(',');
				sb.append(atomArgs[i].value);
			}
			sb.append(')');
			return sb.toString();
		}
		return shortName()/* + pidStr + args + strtest*/;
	}
	
	public ATerm toATerm(){
		int nargs = atomArgs.length;
		// System.err.println("toATerm: " + externalNameAsReceivedByTool);
		
		AFun afun = tbfactory.makeAFun(externalNameAsReceivedByTool, nargs, false);
		ATerm pat[] = new ATerm[nargs];
		
		for(int i = 0; i < nargs; i++){
			pat[i] = tbfactory.makePattern(atomArgs[i].value);
		}
		return tbfactory.makeAppl(afun, pat);
	}
	
	public void computeFirst(){/* Overwritten in subclass */}
	
	public void replaceFormals(Environment e) throws ToolBusException{
		this.env = e;
		//System.err.println("Atom.replaceFormals: " + env);
		for(int i = 0; i < atomArgs.length; i++){
			//System.err.println("atomArg[" + i + "] = " + atomArgs[i] + " ; env = " + env);
			ATerm arg = tbfactory.resolveVarTypes(atomArgs[i].value, env);
			arg = tbfactory.replaceFormals(arg, env);
			//System.err.println("atomArg[" + i + "] = " + atomArgs[i].value + " => " + arg + "; env = " + env);
			atomArgs[i].value = arg;
		}
	}
	
	public void compile(ProcessInstance pi, Stack<String> calls, State follow) throws ToolBusException{
		this.processInstance = pi;
		// System.err.println("Atom.compile, prev env = " + env);
		// this.env = env.copy();
		setFollow(follow);
		// System.err.println("Compiling " + this + ";\n env = " + this.env);
		// replaceFormals(env); //TODO redundant?
	}
	
	// Implementation of the StateElement interface
	
	public boolean isEnabled() throws ToolBusException{
		// System.err.println("Atom.isEnabled: " + this.getProcess().getProcessId() + ": " + this);
		if(timeExpr){
			// System.err.println("Has a TimeExpr; delay = " + delay + "; timeout = " + timeout);
			int currentTime = (int) getToolBus().getRunTime();
			// System.err.println("startTime = " + startTime + "; currentTime = " + currentTime);
			if(delay != 0 && currentTime < startTime + delay){
				// System.err.println("currentTime < startTime + delay");
				/*incr(notEnabled);*/
				return false;
			}
			if(timeout != 0 && currentTime > startTime + timeout){
				// System.err.println("currentTime > startTime + timeout");
				/*incr(notEnabled);*/
				return false;
			}
		}
		if(tests != null){
			//System.err.println("Atom.isEnabled: " + this.getProcess().getProcessId() + ": " +  this);
			Iterator<Test> testIterator = tests.iterator();
			while(testIterator.hasNext()){
				Test t = testIterator.next();
				//System.err.print("evaluate: " + t);
				boolean res = tbfactory.isTrue(Functions.eval(t.testExpr, getProcess(), t.testEnv));
				//System.err.println(" ==> " + res);
				if(!res){
					/*incr(notEnabled);*/
					return false;
				}
			}
		}
		/*incr(enabled);*/
		return true;
	}
	
	public boolean contains(StateElement b){
		return this == b;
	}
	
	public ProcessInstance getProcess(){
		return processInstance;
	}
	
	public void addPartners(AtomSet s){/* Overwritten in subclass */}
	
	public void delPartners(AtomSet s){/* Overwritten in subclass */}
	
	public State gotoNextStateAndActivate(){
		// System.err.println(this + "getNextState ==> " + getFollow());
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
		System.err.println("Atom.getNextState2: wrong arg: " + b); // TODO exception
		return null;
	}
	
	public void activate(){
		if(timeExpr){
			startTime = (int) getToolBus().getRunTime();
			int next = (delay != 0) ? startTime + delay : startTime;
			getToolBus().setNextTime(next);
		}
		/*incr(size_env, env.size());*/
		
		/*ATermList collected = tbfactory.EmptyList;
		for(int i = 0; i < atomArgs.length; i++){
			collected = tbfactory.getVariables(atomArgs[i].value, collected);
		}*/
		
		/*incr(size_used_env, collected.getLength());*/
		
		
		// System.err.println("used_vars = " + collected);
		// System.err.println("Atom.activate: " + this);
		
	}
	
	public boolean isTerminated(){
		return false;
	}
	
	abstract public boolean execute() throws ToolBusException;
}
