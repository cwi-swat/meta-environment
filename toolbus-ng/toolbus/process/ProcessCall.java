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

	private boolean executing = false;

	private boolean isStaticCall = true;
	
	private boolean activated = false;
	
	private Stack<String> calls;
	
	private State follows;
	
	private ATerm test;
	
	private Environment testEnv;

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
		return isStaticCall || activated ? PE.getAtoms() : new AtomSet(); //TODO ?
	}

	public String getName() {
		return name;
	}

	public String toString() {
		return "ProcessCall(" + name + ", " + actuals + ")";
	}

	// Implementation of the StateElement interface

	public boolean contains(StateElement a) {
		return isStaticCall || activated ? PE.getFirst().contains(a) : false ; // TODO?
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
		System.err.println("ProcessCall.isEnabled");
		return PE.getFirst().isEnabled();
	}

	public State gotoNextStateAndActivate() {
		if(!(activated || executing)){
			follows.activate();
			return follows;
		} 
		executing = true;
		return PE.getFirst().gotoNextStateAndActivate();
	}

	public State gotoNextStateAndActivate(StateElement se) {
		if(!(activated || executing)){
			follows.activate();
			return follows;
		} 
		executing = true;
		return PE.getFirst().gotoNextStateAndActivate(se);
	}

	public void activate() {
		//System.err.println("ProcessCall.activate: [" + getProcess().getProcessId() + "]" + this);
		//System.err.println("isStaticCall = " + isStaticCall + "; activated = " + activated + "; executing = " + executing);
		if(activated && !executing){
			return;
		}
		if(activated && executing){
			// execution of the PE is completed
			//System.err.println("activated && executing, current call is completed! Follows = " + follows);
			follows.activate();
			return;
		}
		//System.err.println("ProcessCall.activate: [" + getProcess().getProcessId() + "]" + this);
		//System.err.println("isStaticCall = " + isStaticCall + "; activated = " + activated);
		if(!isStaticCall){
			try {
				initDynamicCall();
				ProcessInstance P = getProcess();
				P.addToAtomSignature(PE.getAtoms());
				//System.err.println("ProcessCall.activate: addPartners" + PE.getAtoms());
				P.addPartnersToAllProcesses(PE.getAtoms());
			} catch (ToolBusException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		PE.getFirst().activate();	
		activated = true;
		executing = false;
	}

	public boolean execute() throws ToolBusException {
		//System.err.println("ProcessCall.execute: [" + getProcess().getProcessId() + "]"  + this);
		//System.err.println("activated = " + activated + "; executing = " + executing + "; first = " + PE.getFirst());
		if(activated && !executing){
			if(PE.getFirst().size() == 0){
				//System.err.println("case size = 0");
				executing = true;
				return true;
			}
			//System.err.println("case size != 0");
			executing = PE.getFirst().execute();
			//System.err.println("executing => " + executing);
			return executing;
		}
		//System.err.println("execute: moving on to: " + follows);
		activated = executing = false;
		return true;
	}
}