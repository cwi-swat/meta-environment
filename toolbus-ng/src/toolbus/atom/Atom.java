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
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermInt;
import aterm.ATermList;

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
	private final static String SECS = "sec";
	private final static String MSECS = "msec";
	
	private ProcessInstance processInstance;	// process instance to which the atom belongs
	private Environment env;					// the environment of this atom
	private List<Test> tests;					// optional tests that guard this atom
	private Ref[] atomArgs = new Ref[0];		// arguments of the atom
	private int delay = 0;						// time delay before atom can be executed
	private int timeout = 0;					// timeout after which atom can no longer be executed
	private boolean timeExpr = false;			// the actual time expression for delay/timeout
	private long activateTime;					// when this atom was activated
	private long enabledTime;					// When this atom becomes ready for execution
	private long timeoutTime;					// When this atom becomes no longer eligable for execution
	protected String externalNameAsReceivedByTool;
/*	
	static private HashMap<String, Integer> instances = new HashMap<String, Integer>(32);
	static private HashMap<String, Integer> enabled = new HashMap<String, Integer>(32);
	static private HashMap<String, Integer> notEnabled = new HashMap<String, Integer>(32);
	static private HashMap<String, Integer> size_env = new HashMap<String, Integer>(32);
	static private HashMap<String, Integer> size_used_env = new HashMap<String, Integer>(32);
*/
	
	public Atom(TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
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
	
	public void setDelay(ATerm delay){
		if(delay instanceof ATermAppl){
			ATermAppl timeExpression = (ATermAppl) delay;
			AFun timeFun = timeExpression.getAFun();
			if(timeFun.getArity() == 1){
				String order = timeFun.getName();
				ATerm argument = timeExpression.getArgument(0);
				if(argument instanceof ATermInt){
					ATermInt time = (ATermInt) argument;
					if(order == SECS){
						this.delay = time.getInt() * 1000;
						timeExpr = true;
						return;
					}else if(order == MSECS){
						this.delay = time.getInt();
						timeExpr = true;
						return;
					}
				}
			}
		}
		// If the function didn't return before this point the argument wasn't formatted properly.
		throw new RuntimeException("Not a time expression: "+delay);
	}
	
	public void setAbsoluteDelay(ATermList delay){
		// TODO Implement as soon as we know how to do it properly.
		throw new UnsupportedOperationException("Absolute delays are currently unsupported.");
	} 
	
	public void setTimeout(ATerm timeout){
		if(timeout instanceof ATermAppl){
			ATermAppl timeExpression = (ATermAppl) timeout;
			AFun timeFun = timeExpression.getAFun();
			if(timeFun.getArity() == 1){
				String order = timeFun.getName();
				ATerm argument = timeExpression.getArgument(0);
				if(argument instanceof ATermInt){
					ATermInt time = (ATermInt) argument;
					if(order == SECS){
						this.timeout = time.getInt() * 1000;
						timeExpr = true;
						return;
					}else if(order == MSECS){
						this.timeout = time.getInt();
						timeExpr = true;
						return;
					}
				}
			}
		}
		// If the function didn't return before this point the argument wasn't formatted properly.
		throw new RuntimeException("Not a time expression: "+delay);
	}
	
	public void setAbsoluteTimeout(ATermList timeout){
		// TODO Implement as soon as we know how to do it properly.
		throw new UnsupportedOperationException("Absolute timeouts are currently unsupported.");
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
			long currentTime = getToolBus().getRunTime();
			// System.err.println("startTime = " + startTime + "; currentTime = " + currentTime);
			if(currentTime < enabledTime){
				getToolBus().setNextTime(enabledTime);
				// System.err.println("currentTime < startTime + delay");
				/*incr(notEnabled);*/
				return false;
			}
			if(timeout != 0 && currentTime > timeoutTime){
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
		activateTime = getToolBus().getRunTime();
		enabledTime = activateTime + delay;
		timeoutTime = activateTime + timeout;
		
		/*incr(size_env, env.size());*/
		
		/*ATermList collected = tbfactory.EmptyList;
		for(int i = 0; i < atomArgs.length; i++){
			collected = tbfactory.getVariables(atomArgs[i].value, collected);
		}*/
		
		/*incr(size_used_env, collected.getLength());*/
		
		// System.err.println("used_vars = " + collected);
		// System.err.println("Atom.activate: " + this);
	}
}
