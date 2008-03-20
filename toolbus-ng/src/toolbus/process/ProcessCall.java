/**
 * @author paulk, Jul 22, 2002
 */

package toolbus.process;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import toolbus.AtomSet;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.atom.Tau;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.debug.ExecutionResult;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

/**
 * ProcessCall implements a call to a process P(f1, f2, ...). There are two main cases: (1) A static
 * process call: the current environment does not contain a declaration for a string variable P and
 * the name of the process is P. Its declaration is taken and the call is replaced statically by the
 * corresponding process expression. (2) A dynamic process call: the current environment *does*
 * contain a declaration for a string variable P and the name of the process is the *string value*
 * of that variable. The declaration correspodning to that value is taken and the call is replaced
 * dynamically by the corresponding process expression. In the dynamic case, each the call is
 * encountered during execution it the may thus be expanded into a different process expression. Due
 * to the possibility of dynamic calls, a process call is a StateElement and exists during
 * execution.
 */
public class ProcessCall extends ProcessExpression implements StateElement{
	private String name;
	
	private TBTermVar nameAsVar;
	
	protected final ATermList originalActuals;
	protected ATermList actuals;
	
	private ATermList formals;
	
	private Environment env;
	
	private ProcessDefinition definition = null; 	// May remain null for dynamic calls to non-existing processes
	
	protected ProcessExpression PE;
	
	protected ProcessInstance processInstance;
	
	private boolean evalArgs = true;
	
	private final State firstState;
	
	private boolean executing = false;
	
	private boolean isStaticCall = true;
	
	private boolean activated = false;
	
	private Stack<String> calls;
	
	private ATerm test;
	private Environment testEnv;
	
	public ProcessCall(String name, ATermList actuals, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.name = name;
		this.originalActuals = actuals;
		this.actuals = actuals;
		
		firstState = new State();
		firstState.addElement(this);
	}
	
	public ProcessCall(ATerm call, TBTermFactory tbfactory, PositionInformation posInfo){
		this(((ATermAppl) call).getName(), ((ATermAppl) call).getArguments(), tbfactory, posInfo);
	}
	
	public ProcessCall(String name, ATermList actuals, boolean evalArgs, TBTermFactory tbfactory, PositionInformation posInfo){
		this(name, actuals, tbfactory, posInfo);
		this.evalArgs = evalArgs;
	}
	
	public void setEvalArgs(boolean b){
		evalArgs = b;
	}
	
	protected ProcessExpression copy(){
		return new ProcessCall(name, actuals, evalArgs, tbfactory, getPosInfo());
	}
	
	protected void computeFirst(){
		// System.err.println("ProcessCall.computeFirst: " + firstState);
		setFirst(firstState);
	}
	
	public State getFirst(){
		// System.err.println("ProcessCall.getFirst: " + firstState);
		return firstState;
	}
	
	protected void replaceFormals(Environment e) throws ToolBusException{
		//System.err.println("ProcessCall.replaceFormals(" + name + "): " + env);
		env = e.copy();
		
		// env = e;
		actuals = (ATermList) tbfactory.replaceFormals(originalActuals, env);
	}
	
	protected void compile(ProcessInstance P, Stack<String> calls, State follows) throws ToolBusException{
		processInstance = P;
		this.calls = calls;
		setFollow(follows);
		nameAsVar = tbfactory.mkVar(tbfactory.make(name), calls.peek(), tbfactory.StrType);
		
		if(env.isDeclaredAsStringVar(nameAsVar)){ // Is this a dynamic call?
			isStaticCall = false;
			definition = null;
			// System.err.println("compile: dynamic call of " + name);
		}else{
			compileStaticOrDynamicCall();
		}
	}
	
	private void compileStaticOrDynamicCall() throws ToolBusException{
		if(calls.contains(name)){
			throw new ToolBusException("recursive call of " + name);
		}
		
		definition = processInstance.getToolBus().getProcessDefinition(name, originalActuals.getLength());
		
		calls.push(name);
		// System.err.println("name = " + name);
		// System.err.println("definition = " + definition);
		
		actuals = (ATermList) tbfactory.replaceFormals(originalActuals, env);
		PE = definition.getProcessExpression(actuals);
		
		// System.err.println("ProcessCall.compile(" + name + ", " + processInstance + "," + PE + ")");
		formals = definition.getFormals();
		actuals = (ATermList) tbfactory.resolveVarTypes(actuals, env);
		
		env.introduceBindings(formals, actuals, evalArgs);
		actuals = (ATermList) tbfactory.replaceFormals(actuals, env);
		
		// System.err.println("ProcessCall.compile(" + name + "): " + env);
		// System.err.println("actuals = " + actuals);
		PE.computeFirst();
		PE.replaceFormals(env);
		PE.compile(processInstance, calls, firstState); // follows);
		PE.getFirst().setTest(test, testEnv);
		// firstState = PE.getFirst(); //getStartState(); <====
		// env.removeBindings(formals);
		calls.pop();
		// System.err.println(name + " expanded as:\n" + PE);
	}
	
	private void initDynamicCall() throws ToolBusException{
		ATermAppl dynprocessname = (ATermAppl) env.getValue(nameAsVar);
		name = dynprocessname.getName();
		compileStaticOrDynamicCall();
		//System.err.println("Dynamic process name " + name + " => " + dynprocessname);
		AtomSet callElements = PE.getAtoms();
		processInstance.addElements(callElements);
		processInstance.addPartnersToAllProcesses(callElements);
	}
	
	private void finishCall(){
		activated = executing = false;
		if(!isStaticCall){
			definition = null;
			AtomSet callElements = PE.getAtoms();
			processInstance.delElements(callElements);
			processInstance.delPartnersFromAllProcesses(callElements);
		}
	}
	
	public AtomSet getAtoms(){
		AtomSet r;
		if((isStaticCall || ((definition != null) && activated)) && PE != null){
			r = PE.getAtoms();
		}else{
			r = new AtomSet();
		}
		// System.err.println(name + ".getAtoms => " + r);
		return r;
	}
	
	public String getName(){
		return name;
	}
	
	public String toString(){
		return "ProcessCall(" + name + ", " + originalActuals + ")";
	}
	
	
	// Implementation of the StateElement interface
	
	public boolean contains(StateElement a){
		// if(!isStaticCall){ System.err.println(name + ": contains " + a); }
		
		return isStaticCall || ((definition != null) && activated) ? PE.getFirst().contains(a) : false;
	}
	
	public ProcessInstance getProcess(){
		return processInstance;
	}
	
	public void setTest(ATerm test, Environment env) throws ToolBusException{
		// System.err.println("ProcessCall.setTest: " + test);
		if(isStaticCall){
			PE.getFirst().setTest(test, env);
		}else{
			this.test = test;
			this.testEnv = env; // TODO attach to actual PE!
		}
	}
	
	public List<ATerm> getTests(){
		List<ATerm> testExpressions = new ArrayList<ATerm>(1);
		if(test != null) testExpressions.add(test);
		return testExpressions;
	}
	
	public boolean isEnabled(){
		//System.err.println("ProcessCall.isEnabled");
		/*if(activated && (isStaticCall || definition != null)){
			return PE.getFirst().isEnabled();
		}
		return false;*/
		
		// TODO The above code doesn't work for some reason (the 'first state' doesn't always get activated (I think it has to do with the Merge atom)).
		
		return (activated && (isStaticCall || definition != null));
	}
	
	public State gotoNextStateAndActivate(){
		if(!(activated || executing)){
			State follow = getFollow();
			follow.activate();
			return follow;
		}
		executing = true;
		return PE.getFirst().gotoNextStateAndActivate();
	}
	
	public State gotoNextStateAndActivate(StateElement se){
		if(!(activated || executing)){
			State follow = getFollow();
			follow.activate();
			return follow;
		}
		executing = true;
		return PE.getFirst().gotoNextStateAndActivate(se);
	}
	
	public void activate(){
		// System.err.println("ProcessCall.activate: " + this);
		// System.err.println("isStaticCall = " + isStaticCall + "; activated = " + activated + "; executing = " + executing);
		if(activated && executing) return;
		
		// System.err.println("ProcessCall.activate: [" + name + "]" + this);
		// System.err.println("isStaticCall = " + isStaticCall + "; activated = " + activated);
		if(!isStaticCall){
			try{
				initDynamicCall();
			}catch(ToolBusException e){
				System.err.println(e.getMessage());
				activated = false;
				return;
			}
		}
		// System.err.println("ProcessCall: activate first set of PE");
		activated = true;
		PE.getFirst().activate();
	}
	
	public boolean execute() throws ToolBusException{
		// System.err.println("ProcessCall.execute: [" + getProcess().getProcessName() + "]" + this);
		// System.err.println("activated = " + activated + "; executing = " + executing + "; first = " + PE.getFirst());
		if(isEnabled()){
			if(!executing){
				if(definition == null){
					return false;
				}
				if(PE.getFirst().size() == 0){
					// System.err.println("case size = 0");
					executing = true;
					// System.err.println("ProcessCall [" + getProcess().getProcessName() + "] enter");
					return true;
				}
				// System.err.println("case size != 0");
				executing = PE.getFirst().execute();
				// System.err.println("executing => " + executing);
				// if(executing)System.err.println("ProcessCall [" + getProcess().getProcessName() + "] enter");
				return executing;
			}
			// System.err.println("execute: moving on to: " + follows);
			// System.err.println("ProcessCall [" + getProcess().getProcessName() + "] leave");
			finishCall();
			return true;
		}
		return false;
	}
	
	public ProcessInstance[] debugExecute() throws ToolBusException{
		if(isEnabled()){
			if(!executing){
				if(definition == null){
					return null;
				}
				if(PE.getFirst().size() == 0){
					executing = true;
					return new ProcessInstance[0];
				}
				ExecutionResult er = PE.getFirst().debugExecute();
				if(er != null){
					executing = true;
					return er.partners;
				}
				executing = false;
				return null;
			}
			finishCall();
			return new ProcessInstance[0];
		}
		return null;
	}
	
	/**
	 * Returns the last, by this process call, executed state element.
	 * (This method is used for debugging only).
	 * @return The last, by this process call, executed state element; may be null if this process call isn't currently executing.
	 */
	public StateElement getExecutedStateElement(){
		if(!(activated || executing)) return new Tau(tbfactory, null); // Pretend nothing happened if the call was just completed.
		
		StateElement executedStateElement = PE.getFirst().getLastExecutedStateElement();
		while(executedStateElement instanceof ProcessCall){
			executedStateElement = ((ProcessCall) executedStateElement).getExecutedStateElement();
		}
		return executedStateElement;
	}
}
