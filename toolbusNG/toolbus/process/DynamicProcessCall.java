/*
 * Created on Nov 27, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package toolbus.process;

import java.util.Stack;

import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import aterm.ATerm;
import aterm.ATermList;

/**
 * @author paulk
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class DynamicProcessCall extends ProcessCall implements StateElement {
	
	private ATerm name;
	private Environment env;
	private State firstState;
	private State follows;
	private boolean uninitialized = true;
	
	public DynamicProcessCall(ATerm name, ATermList actuals, TBTermFactory tbfactory) {
		super("", actuals, tbfactory, null);
		this.name = name;
		super.actuals = actuals;
		firstState = new State();
		firstState.addElement(this);
	}
	
	public ProcessExpression copy() {
		return new DynamicProcessCall(name, super.actuals, tbfactory);
	}

	public void expand(ProcessInstance P, Stack calls) throws ToolBusException {
		super.processInstance = P;
	}
	
	public void compile(ProcessInstance P, Stack<String> calls, State follows)
	throws ToolBusException {
		this.env = env;
		this.follows = follows;
	}
	
	public void replaceFormals(Environment env) throws ToolBusException{
		//System.err.println("ProcessCall.replaceFormals(" + name + "): " + env);
		//PE.replaceFormals(env);
	}
	
	public State getFirst() {
		return firstState;
	}
	
	public State getStartState() {
		return super.PE.getStartState();
	}

	public State getFollow() {
		return super.PE.getFollow();
	}

	public State getAtoms() {
		return super.PE.getAtoms();
	}
	
	private void initDynamicCall(){
		if(uninitialized){
			uninitialized = false;
		//	try {
		//		super.expand(processInstance, new Stack());
		//		super.compile(processInstance,null,env, follows);
		//	} catch (ToolBusException e) {
		//		// TODO Auto-generated catch block
		//		e.printStackTrace();
		//	}		
		}
	}

	 // Implementation of the StateElement interface

	  public boolean contains(StateElement a) {
	  	initDynamicCall();
	  	return super.getFirst().contains(a);
	  }

	  public ProcessInstance getProcess() {
	    return processInstance;
	  }
	  
	  public void setTest(ATerm test, Environment env) throws ToolBusException {
	  	
	  }
	  
	  public boolean isEnabled(){
	  	return super.getFirst().isEnabled();
	  }
	  
	  public State getNextState(){
	  	return super.getFirst().getNextState();
	  }
	  
	  public State getNextState(StateElement se) {
	  	return super.getFirst().getNextState(se);
	  }
	  
	  public void activate(){
	  	super.getFirst().activate();
	  }
	 
	  public boolean execute() throws ToolBusException {
	  	return super.getFirst().execute();
	  }
	  
	  public String toString(){
	  	return "DynamicProcessCall(" + name + ")";
	  }


	
}
