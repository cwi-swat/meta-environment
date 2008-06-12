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
import toolbus.exceptions.NoSuchProcessDefinitionException;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.ToolBusExecutionException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.debug.ExecutionResult;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class DynamicProcessCall extends ProcessExpression implements StateElement{
	private String name;
	
	private TBTermVar nameAsVar;
	
	protected final ATermList originalActuals;
	protected ATermList actuals;
	
	private ATermList formals;
	
	private Environment env;
	
	private ProcessDefinition definition = null; // May remain null for dynamic calls to non-existing processes
	
	protected ProcessExpression PE;
	
	protected ProcessInstance processInstance;
	
	private final State firstState;
	
	private boolean executing = false;
	
	private boolean activated = false;
	
	private Stack<String> calls;
	
	private ATerm test;
	private Environment testEnv;
	
	public DynamicProcessCall(String name, ATermList actuals, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.name = name;
		this.originalActuals = actuals;
		this.actuals = actuals;
		
		firstState = new State();
		firstState.addElement(this);
	}
	
	protected ProcessExpression copy(){
		return new DynamicProcessCall(name, actuals, tbfactory, getPosInfo());
	}
	
	protected void computeFirst(){
		// System.err.println("ProcessCall.computeFirst: " + firstState);
		setFirst(firstState);
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
		
		definition = null;
	}
	
	private void compileStaticOrDynamicCall() throws ToolBusException{
		if(calls.contains(name)){
			throw new ToolBusExecutionException("Recursive call of "+name, getPosInfo());
		}
		
		definition = processInstance.getToolBus().getProcessDefinition(name, originalActuals.getLength());
		
		// System.err.println("name = " + name);
		// System.err.println("definition = " + definition);
		
		actuals = (ATermList) tbfactory.replaceFormals(originalActuals, env);
		PE = definition.getProcessExpression(actuals);
		
		// System.err.println("ProcessCall.compile(" + name + ", " + processInstance + "," + PE + ")");
		formals = definition.getFormals();
		
		env.introduceBindings(formals, actuals, true);
		actuals = (ATermList) tbfactory.replaceFormals(actuals, env);
		
		// System.err.println("ProcessCall.compile(" + name + "): " + env);
		// System.err.println("actuals = " + actuals);
		PE.computeFirst();
		PE.replaceFormals(env);
		
		calls.push(name);
		PE.compile(processInstance, calls, firstState);
		calls.pop();
		
		PE.getFirst().setTest(test, testEnv);
		// env.removeBindings(formals);
		// System.err.println(name + " expanded as:\n" + PE);
	}
	
	private void initDynamicCall() throws ToolBusException{
		ATermAppl dynprocessname = (ATermAppl) env.getValue(nameAsVar);
		name = dynprocessname.getName();
		compileStaticOrDynamicCall();
		//System.err.println("Dynamic process name " + name + " => " + dynprocessname);
	}
	
	private void finishCall(){
		activated = executing = false;
		definition = null;
		AtomSet callElements = PE.getAtoms();
		PE = null;
		processInstance.deregisterCommunicationAtoms(callElements);
	}
	
	public AtomSet getAtoms(){
		AtomSet r;
		if(PE != null){
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
		return "DynamicProcessCall(" + name + ", " + originalActuals + ")";
	}
	
	
	// Implementation of the StateElement interface
	
	public boolean contains(StateElement a){
		// if(!isStaticCall){ System.err.println(name + ": contains " + a); }
		
		return ((definition != null) && activated) ? PE.getFirst().contains(a) : false;
	}
	
	public ProcessInstance getProcess(){
		return processInstance;
	}
	
	public void setTest(ATerm test, Environment env) throws ToolBusException{
		this.test = test;
		this.testEnv = env;
	}
	
	public List<ATerm> getTests(){
		List<ATerm> testExpressions = new ArrayList<ATerm>(1);
		if(test != null) testExpressions.add(test);
		return testExpressions;
	}
	
	public boolean isEnabled(){
		return (activated && definition != null);
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
		if(activated && executing) return;
		
		try{
			initDynamicCall();
		}catch(NoSuchProcessDefinitionException nspdex){
			// Ignore this and emulate Delta.
			activated = false;
			return;			
		}catch(ToolBusException e){
			e.printStackTrace();
			activated = false;
			return;
		}
		
		activated = true;
		PE.getFirst().activate();
	}
	
	public boolean execute() throws ToolBusException{
		if(isEnabled()){
			if(!executing){
				if(PE.getFirst().size() == 0){
					// System.err.println("case size = 0");
					executing = true;
					return true;
				}
				executing = PE.getFirst().execute();
				return executing;
			}
			finishCall();
			return true;
		}
		return false;
	}
	
	public ProcessInstance[] debugExecute() throws ToolBusException{
		if(isEnabled()){
			if(!executing){
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
		if(!executing) return new Tau(tbfactory, null); // Pretend nothing happened if the call was just completed.
		
		StateElement executedStateElement = PE.getFirst().getLastExecutedStateElement();
		while(executedStateElement instanceof ProcessCall){
			executedStateElement = ((ProcessCall) executedStateElement).getExecutedStateElement();
		}
		return executedStateElement;
	}
}
