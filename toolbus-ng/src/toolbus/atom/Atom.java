/**
 * @author paulk
 */

package toolbus.atom;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Stack;
import toolbus.AtomList;
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
 * The class Atom forms the basic building block of Tscripts. Instances of Atom
 * are both the most primitive elements of process expressions and the elements of
 * the states to which process exprssions are being compiled.
 *
 */

abstract public class Atom extends ProcessExpression implements StateElement{
	private final static String SECS = "sec";
	private final static String MSECS = "msec";
	
	private final static Ref[] NOATOMARGS = new Ref[0];
	
	private ProcessInstance processInstance;	// process instance to which the atom belongs
	private Environment env;					// the environment of this atom
	private List<Test> tests;					// optional tests that guard this atom
	private Ref[] atomArgs = NOATOMARGS;		// arguments of the atom
	private int delay = 0;						// time delay before atom can be executed
	private int timeout = 0;					// timeout after which atom can no longer be executed
	private boolean timeExpr = false;			// the actual time expression for delay/timeout
	private long activateTime;					// when this atom was activated
	private long enabledTime;					// When this atom becomes ready for execution
	private long timeoutTime;					// When this atom becomes no longer eligable for execution
	protected String externalNameAsReceivedByTool;
	
	public Atom(TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		addToFirst(this);
		externalNameAsReceivedByTool = shortName();
	}
	
	public void destroy(){/* Intended to (optionally) be overwritten in subclasses to enable them to execute cleanup actions if needed. */}
	
	public void setAtomArgs(Ref[] refs){
		atomArgs = refs;
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
			if(tests == null) tests = new ArrayList<Test>(4);
			Test t = new Test(test, e);
			//System.out.println("setTest: " + t);
			this.tests.add(t);
		}
	}
	
	public List<ATerm> getTests(){
		if(tests != null){
			List<ATerm> testExpressions = new ArrayList<ATerm>(tests.size());
			Iterator<Test> testsIterator = tests.iterator();
			while(testsIterator.hasNext()){
				testExpressions.add(testsIterator.next().testExpr);
			}
			return testExpressions;
		}
		return new ArrayList<ATerm>(0);
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
	
	public int getDelay(){
		return delay;
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
	
	public int getTimeout(){
		return timeout;
	}
	
	public ToolBus getToolBus(){
		return processInstance.getToolBus();
	}
	
	public AtomList getAtoms(){
		return new AtomList(this);
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
	
	public ATermAppl toATerm(){
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
			ATerm arg = tbfactory.replaceFormals(atomArgs[i].value, env);
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
				boolean res = tbfactory.isTrue(Functions.eval(t.testExpr, processInstance, t.testEnv));
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
		
		// System.err.println("used_vars = " + collected);
		// System.err.println("Atom.activate: " + this);
	}
	
	/**
	 * This class holds static reference to an empty process instance array, which can be used as
	 * return value in the debugExecute method. Using this instead of a newly created array every
	 * time will reduce garbage creation. 
	 * 
	 * @author Arnold Lankamp
	 */
	private static class EmptyProcessInstanceArrayHolder{
		public final static ProcessInstance[] ZEROPARTNERS = new ProcessInstance[0];
	}
	
	public ProcessInstance[] debugExecute() throws ToolBusException{
		if(execute()) return EmptyProcessInstanceArrayHolder.ZEROPARTNERS;
		
		return null;
	}
	
	/**
	 * This class represents a test associated with an atom.
	 * It carries its own execution environment.
	 */
	private static class Test{
		public final ATerm testExpr;
		public final Environment testEnv;
		
		public Test(ATerm test, Environment env){
			testExpr = test;
			testEnv = env;
		}
		public String toString(){
			return "Test(" + testExpr + ", " + testEnv + ")";
		}
	}
}
