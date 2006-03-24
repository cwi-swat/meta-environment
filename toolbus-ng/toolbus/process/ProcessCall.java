/**
 * @author paulk, Jul 22, 2002
 */

package toolbus.process;

import java.util.Stack;

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

	private TBTermVar nameAsVar;;

	protected ATermList actuals;

	private ATermList formals;
	
	private Environment env;

	private ProcessDefinition definition;

	protected ProcessExpression PE;

	protected ProcessInstance processInstance;

	private boolean evalArgs = true;

	private State firstState;

	private boolean initializedDynamicCall = false;

	private boolean isStaticCall = true;
	
	private Stack<String> calls;
	
	private State follows;

	public ProcessCall(String name, ATermList actuals, TBTermFactory tbfactory) {
		super(tbfactory);
		this.name = name;
		this.actuals = actuals;
		firstState = new State();
		firstState.addElement(this);
	}

	public ProcessCall(ATerm call, TBTermFactory tbfactory) {
		this(((ATermAppl) call).getName(), ((ATermAppl) call).getArguments(),
				tbfactory);
	}

	public ProcessCall(String name, ATermList actuals, boolean evalArgs,
			TBTermFactory tbfactory) {
		this(name, actuals, tbfactory);
		this.evalArgs = evalArgs;
	}

	public void setEvalArgs(boolean b) {
		evalArgs = b;
	}

	public ProcessExpression copy() {
		return new ProcessCall(name, actuals, evalArgs, tbfactory);
	}

	public void computeFirst() {
		System.err.println("ProcessCall.computeFirst: " + firstState);
		setFirst(firstState);
	}
	
	public void replaceFormals(Environment e) throws ToolBusException {
		System.err.println("ProcessCall.replaceFormals(" + name + "): " + env);
		env = e.copy();
		//env = e;
		actuals = (ATermList) tbfactory.replaceFormals(actuals,env);
	}

	public void compile(ProcessInstance P, Stack<String> calls,
			State follows) throws ToolBusException {
		System.err.println("compile");
		processInstance = P;
		this.calls = calls;
		this.follows = follows;
		nameAsVar = tbfactory.mkVar(tbfactory.make(name), calls.peek(), tbfactory.StrType);

		if (env.isDeclaredAsStringVar(nameAsVar)) { // A dynamic call?
			System.err.println("yes dynamic!");
			isStaticCall = false;
		} else {
			if (calls.contains(name)) {
				throw new ToolBusException("recursive call of " + name);
			}

			definition = P.getToolBus().getProcessDefinition(name);
			calls.push(name);

			actuals = (ATermList) tbfactory.replaceFormals(actuals,env);
			PE = definition.getProcessExpression(actuals);
			
			//System.err.println("ProcessCall.compile(" + name + ", " + P + "," + PE + ")");
			setFollow(follows);
			formals = definition.getFormals();
			actuals = (ATermList) tbfactory.resolveVarTypes(actuals, env);
			
			env.introduceBindings(formals, actuals, evalArgs);
			actuals = (ATermList) tbfactory.replaceFormals(actuals,env);

			//System.err.println("ProcessCall.compile(" + name + "): " + env);
			//System.err.println("actuals = " + actuals);
			PE.computeFirst();
			PE.replaceFormals(env);
			PE.compile(P, calls, follows);
			firstState = PE.getFirst(); //getStartState();
			//env.removeBindings(formals);
			calls.pop();	
			//System.err.println(name + " expanded as:\n" + PE);
		}
	}
	
	private void initDynamicCall() throws ToolBusException {
		ATermAppl dynprocessname = (ATermAppl) env.getValue(nameAsVar);
		String dname = dynprocessname.getName();
		
		if (calls.contains(dname)) {
			throw new ToolBusException("recursive (dynamic) call of " + dname);
		}

		definition = processInstance.getToolBus().getProcessDefinition(dname);
		calls.push(dname);
		System.err.println("dname = " + dname);
		System.err.println("definition = " + definition);

		actuals = (ATermList) tbfactory.replaceFormals(actuals,env);
		PE = definition.getProcessExpression(actuals);
		
		System.err.println("ProcessCall.compile(" + dname + ", " + processInstance + "," + PE + ")");
		setFollow(follows);
		formals = definition.getFormals();
		actuals = (ATermList) tbfactory.resolveVarTypes(actuals, env);
		
		env.introduceBindings(formals, actuals, evalArgs);
		actuals = (ATermList) tbfactory.replaceFormals(actuals,env);

		//System.err.println("ProcessCall.compile(" + name + "): " + env);
		//System.err.println("actuals = " + actuals);
		PE.computeFirst();
		PE.replaceFormals(env);
		PE.compile(processInstance, calls, follows);
		firstState = PE.getFirst(); //getStartState();
		//env.removeBindings(formals);
		calls.pop();	
		System.err.println(name + " expanded as:\n" + PE);
		initializedDynamicCall = true;
	}

	public State getFirst() {
		System.err.println("ProcessCall.getFirst: " + firstState);
		return firstState; //PE.getFirst();
	}

	public State getFollow() {
		return isStaticCall || initializedDynamicCall ? PE.getFollow() : new State();
	}

	public State getAtoms() {
		return isStaticCall || initializedDynamicCall ? PE.getAtoms() : new State();
	}

	public String getName() {
		return name;
	}

	public String toString() {
		return "ProcessCall(" + name + ", " + actuals + ")";
	}

	// Implementation of the StateElement interface

	public boolean contains(StateElement a) {
		return getFirst().contains(a);
	}

	public ProcessInstance getProcess() {
		return processInstance;
	}

	public void setTest(ATerm test, Environment env) throws ToolBusException {
		//System.err.println("ProcessCall.setTest" + test);
		firstState.setTest(test, env);
	}

	public boolean isEnabled() {
		return getFirst().isEnabled();
	}

	public State getNextState() {
		if (isStaticCall) {
			return getFirst().getNextState();
		} else {
			return firstState.getNextState();
		}
	}

	public State getNextState(StateElement se) {
		if (isStaticCall) {
			return getFirst().getNextState(se);
		} else {
			return firstState.getNextState(se);
		}
	}

	public void addPartners(State s) throws ToolBusException {
	}

	public void delPartners(State s) throws ToolBusException {
	}

	public void addNotePartners(State s) {
	}

	public void delNotePartners(State s) {

	}

	public void activate() {
		if(!isStaticCall && !initializedDynamicCall){
			try {
				initDynamicCall();
			} catch (ToolBusException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		firstState = PE.getFirst();
		firstState.activate();	
	}

	public boolean execute() throws ToolBusException {
		System.err.println("ProcessCall.execute");
		return PE.getFirst().execute();
	}
}