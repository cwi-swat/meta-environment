package toolbus.process.debug;

import toolbus.StateElement;
import toolbus.process.ProcessInstance;

public class ExecutionResult{
	public final StateElement stateElement;
	public final ProcessInstance[] partners;
	
	public ExecutionResult(StateElement stateElement, ProcessInstance[] partners){
		super();
		
		this.stateElement = stateElement;
		this.partners = partners;
	}
}
