/**
 * @author paulk, Jul 22, 2002
 */

package toolbus.process;

import java.util.Stack;

import toolbus.AtomSet;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.ToolBusInternalError;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class ProcessCall extends ProcessExpression implements StateElement {
	private String name;

	private TBTermVar nameAsVar;

	protected ATermList actuals;

	private ATermList formals;
	
	private Environment env;

	private ProcessDefinition definition;

	protected ProcessExpression PE;

	protected ProcessInstance processInstance;

	private boolean evalArgs = true;

	private State firstState;

	private boolean isStaticCall = true;
	
	private enum CallStatus {INACTIVE, ACTIVATED, ENTERING, EXECUTING, FOLLOWING, FOLLOWING2}
	
	private CallStatus status = CallStatus.INACTIVE;
	
	private Stack<String> calls;
	
	private State follows;
	
	private ATerm test;
	
	private Environment testEnv;

	//private boolean outsidePE = false;

	public ProcessCall(String name, ATermList actuals, TBTermFactory tbfactory, ATerm posInfo) {
		super(tbfactory, posInfo);
		this.name = name;
		this.actuals = actuals;
		firstState = new State();
		firstState.addElement(this);
	}

	public ProcessCall(ATerm call, TBTermFactory tbfactory, ATerm posInfo) {
		this(((ATermAppl) call).getName(), ((ATermAppl) call).getArguments(),
				tbfactory, posInfo);
	}

	public ProcessCall(String name, ATermList actuals, boolean evalArgs,
			TBTermFactory tbfactory, ATerm posInfo) {
		this(name, actuals, tbfactory, posInfo);
		this.evalArgs = evalArgs;
	}

	public void setEvalArgs(boolean b) {
		evalArgs = b;
	}

	public ProcessExpression copy() {
		return new ProcessCall(name, actuals, evalArgs, tbfactory, getPosInfo());
	}

	public void computeFirst() {
		//System.err.println("ProcessCall.computeFirst: " + firstState);
		setFirst(firstState);
	}
	
	public State getFirst() {
		//System.err.println("ProcessCall.getFirst: " + firstState);
		return firstState;
	}

	public State getFollow() {
		//System.err.println("ProcessCall.getFollow [" + name + "] " + follows);
		//return isStaticCall || initializedDynamicCall ? PE.getFollow() : new State();
		return follows;
	}
	
	public void replaceFormals(Environment e) throws ToolBusException {
		//System.err.println("ProcessCall.replaceFormals(" + name + "): " + env);
		env = e.copy();
		//env = e;
		actuals = (ATermList) tbfactory.replaceFormals(actuals,env);
	}

	public void compile(ProcessInstance P, Stack<String> calls,
			State follows) throws ToolBusException {
		processInstance = P;
		this.calls = calls;
		this.follows = follows;
		setFollow(follows);
		nameAsVar = tbfactory.mkVar(tbfactory.make(name), calls.peek(), tbfactory.StrType);

		if (env.isDeclaredAsStringVar(nameAsVar)) { // A dynamic call?
			System.err.println("Dynamic call: " + name);
			isStaticCall = false;
		} else {
			compileStaticOrDynamicCall(name);
		}
	}
	
	private void compileStaticOrDynamicCall(String name) throws ToolBusException {
		if (calls.contains(name)) {
			throw new ToolBusException("recursive call of " + name);
		}

		definition = processInstance.getToolBus().getProcessDefinition(name);
		calls.push(name);
		//System.err.println("name = " + name);
		//System.err.println("definition = " + definition);

		actuals = (ATermList) tbfactory.replaceFormals(actuals,env);
		PE = definition.getProcessExpression(actuals);
		
		//System.err.println("ProcessCall.compile(" + name + ", " + processInstance + "," + PE + ")");
		formals = definition.getFormals();
		actuals = (ATermList) tbfactory.resolveVarTypes(actuals, env);
		
		env.introduceBindings(formals, actuals, evalArgs);
		actuals = (ATermList) tbfactory.replaceFormals(actuals,env);

		//System.err.println("ProcessCall.compile(" + name + "): " + env);
		//System.err.println("actuals = " + actuals);
		PE.computeFirst();
		PE.replaceFormals(env);
		PE.compile(processInstance, calls, firstState); // follows);
		PE.getFirst().setTest(test, testEnv);
		//firstState = PE.getFirst(); //getStartState(); <====
		//env.removeBindings(formals);
		calls.pop();	
		//System.err.println(name + " expanded as:\n" + PE);
	}
	
	private void initDynamicCall() throws ToolBusException {
		ATermAppl dynprocessname = (ATermAppl) env.getValue(nameAsVar);
		String dname = dynprocessname.getName();
		compileStaticOrDynamicCall(dname);
		processInstance.addToAtomSignature(PE.getAtoms());
		//System.err.println("Dynamic process name " + name + " => " + dynprocessname);
	}
	
	public AtomSet getAtoms() {
		return isStaticCall || status != CallStatus.INACTIVE ? PE.getAtoms() : new AtomSet(); //TODO ?
	}

	public String getName() {
		return name;
	}

	public String toString() {
		return "ProcessCall(" + name + ", " + actuals + ")";
	}

	// Implementation of the StateElement interface

	public boolean contains(StateElement a) {
		//return isStaticCall || status != CallStatus.INACTIVE ? PE.getFirst().contains(a) : false ; // TODO?
		//System.err.println(this + " contains: " + a);
		//System.err.println("PE.getf = " + PE.getFirst());
		switch(status){
		case ACTIVATED:
			return PE.getFirst().contains(a);
		}
		return false;
	}

	public ProcessInstance getProcess() {
		return processInstance;
	}

	public void setTest(ATerm test, Environment env) throws ToolBusException {
		//System.err.println("ProcessCall.setTest: " + test);
		if (isStaticCall) {
			PE.getFirst().setTest(test, env);
		} else {
			this.test = test;
			this.testEnv = env; //TODO attach to actual PE!
		}	
	}

	public boolean isEnabled() {
		//System.err.println("ProcessCall.isEnabled");
		return PE.getFirst().isEnabled();
	}

	public boolean isTerminated() throws ToolBusException{
		if(status == CallStatus.FOLLOWING && follows.isTerminated()){
			return true;
		}
		return false;
	}
	
	public State gotoNextStateAndActivate() {
		return gotoNextStateAndActivate(null);
	}
	
	public State gotoNextStateAndActivate(StateElement se) {
		//System.err.println("gotoNextStateAndActivate: [" + getProcess() + "] = " + " status = " + status);
		
		switch(status){
//		case INACTIVE:
//			return firstState;
			
		case ACTIVATED:
		case ENTERING:
			//System.err.println("gotoNextStateAndActivate: start executing next state of PE:" + PE);
			State s;
			if(se == null){
				s = PE.getFirst().gotoNextStateAndActivate();
			} else {
				s = PE.getFirst().gotoNextStateAndActivate(se);
			}
			//System.err.println("gotoNextStateAndActivate: new state = " + s);
			if(s == firstState) {
				//System.err.println("WE ARE BACK");
				status = CallStatus.FOLLOWING;
				return s;
			}
			status = CallStatus.EXECUTING;
			return s;
			
		case EXECUTING:
			//	We are back at this node; whole PE has been executed
			//System.err.println("gotoNextStateAndActivate: activate follows");
			status = CallStatus.FOLLOWING;
			return firstState;
			
		case FOLLOWING:
			return firstState;
			
		case FOLLOWING2:
			status = CallStatus.INACTIVE;
			//System.err.println("gotoNextStateAndActivate, FOLLOWING2, follows = " + follows);
			follows.activate();
			return follows;
		}
		System.err.println("gotoNextStateAndActivate, fall through case " + status);
		return firstState;
	}

	public void activate() {
		//System.err.println("ProcessCall.activate: " + // [" + getProcess() + "]" + 
		//					this + 
		//			        "; isStaticCall = " + isStaticCall + "; status = " + status);
		
		switch(status){
		
		case INACTIVE: 		// Call is inactive and will be activated
			
		case ACTIVATED:		// Call was already activated but not executed, redo activation
			
			if(!isStaticCall){
				try {
					initDynamicCall();
					ProcessInstance P = getProcess();
					P.addToAtomSignature(PE.getAtoms());
					//System.err.println("ProcessCall.activate: addPartners" + PE.getAtoms());
					P.addPartnersToAllProcesses(PE.getAtoms()); //TODO: delete partners at end of call
				} catch (ToolBusException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			status = CallStatus.ACTIVATED;
			//System.err.println("first = " + PE.getFirst());
			PE.getFirst().activate();	
			return;
			
		case ENTERING:
			return;
			
		case EXECUTING:
			//System.err.println("activate: ENTERING/EXECUTING, Current call is completed! Follows = " + follows);
			status = CallStatus.FOLLOWING;
			return;
			
		case FOLLOWING:
			//System.err.println("activate: FOLLOWING");
			return;
			
		case FOLLOWING2:
			//System.err.println("activate: FOLLOWING2, follows = " + follows);
			follows.activate();
			return;
		}
		
		System.err.println("activate: fall through case " + status);
		System.err.println("ProcessCall.activate: " + // [" + getProcess() + "]" + 
							this + 
					        "; isStaticCall = " + isStaticCall + "; status = " + status);
		
	}

	public boolean execute() throws ToolBusException {
		//System.err.println("ProcessCall.execute: " + //[" + getProcess() + "]"  + 
		//					this + 
		//			       "; status = " + status + "; first = " + PE.getFirst() ); //+ "; follow = " + follows);
		boolean executed = false;
		
		switch(status){
		case ACTIVATED:
//		case EXECUTING:
			executed = PE.getFirst().execute();
			//System.err.println(this + "executed => " + executed);
			if(executed){
				status = CallStatus.ENTERING;
			}
			return executed;
		case FOLLOWING:
			status = CallStatus.FOLLOWING2;
			return true;
		}
		throw new ToolBusInternalError("ProcessCall.execute");
	}
}