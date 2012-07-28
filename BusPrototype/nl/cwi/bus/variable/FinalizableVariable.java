package nl.cwi.bus.variable;

import nl.cwi.bus.server.Bus;

/**
 * Container for variables that need to send a notification to the 'source tool'
 * upon collection.
 * 
 * @author Arnold Lankamp
 */
public class FinalizableVariable{
	private Variable variable = null;
	
	private int referenceCount = -1;

	/**
	 * Constructor.
	 * 
	 * @param variable
	 *            The variable that needs to send a notification to the 'source
	 *            tool' upon collection.
	 */
	public FinalizableVariable(Variable variable){
		super();

		this.variable = variable;
		
		referenceCount = 0;
	}

	/**
	 * Returns the variable contained in this object.
	 * 
	 * @return The variable contained in this object.
	 */
	public Variable getVariable(){
		return variable;
	}
	
	/**
	 * Increments the reference count on this variable.
	 */
	public void incrementReferenceCount(){
		referenceCount++;
	}
	
	/**
	 * Decrements the reference count on this variable.
	 */
	public void decrementReferenceCount(){
		referenceCount--;
		
		if(referenceCount == 0){
			finalizeVariable();
		}
	}

	/**
	 * Prepares this variable for collection.
	 */
	public void finalizeVariable(){
		VariableFinalizationQueue variableFinalizationQueue = Bus.getInstance().getVariableFinalizationQueue();
		variableFinalizationQueue.add(variable);
		
		Object lock = variableFinalizationQueue.getLock();
		synchronized(lock){
			lock.notify();
		}
	}
}
