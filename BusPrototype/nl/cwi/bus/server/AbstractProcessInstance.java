package nl.cwi.bus.server;

import nl.cwi.bus.communication.operations.PutOperation;
import nl.cwi.bus.variable.AcknowledgeableVariables;
import nl.cwi.bus.variable.FinalizableVariable;
import nl.cwi.bus.variable.Variable;
import nl.cwi.bus.variable.AcknowledgeableVariables.AcknowledgeableVariable;
import nl.cwi.util.logging.Logger;

/**
 * Represents an instance of a process
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractProcessInstance{
	/**
	 * Executes one instruction.
	 * 
	 * @param message
	 *            The message to handle.
	 * @return True if the process instance was able to handle the message;
	 *         false otherwise.
	 */
	public abstract boolean step(FinalizableVariable message);

	/**
	 * Handles the setting of variables in process instances.
	 * 
	 * @param reference
	 *            The variable that needs to be set (may be null).
	 * @param value
	 *            The value the variable should be set to (may be null).
	 * @return The new variable.
	 */
	protected synchronized FinalizableVariable setVariable(FinalizableVariable reference, FinalizableVariable value){
		if(value != null) value.incrementReferenceCount();

		if(reference != null) reference.decrementReferenceCount();

		return value;
	}

	/**
	 * Send a 'do' request to a tool.
	 * 
	 * @param toolInstance
	 *            The tool instance associated with the receiving tool.
	 * @param message
	 *            The variable containing the data that needs to be send.
	 */
	protected void sendDo(ToolInstance toolInstance, FinalizableVariable message){
		AcknowledgeableVariables acknowledgeableVariables = Bus.getInstance().getAcknowledgeableVariables();

		Variable variable = message.getVariable();
		PutOperation putOperation = new PutOperation(variable);
		long transactionID = putOperation.getTransactionID();

		AcknowledgeableVariable acknowledgeableVariable = new AcknowledgeableVariable(message, transactionID, toolInstance.getID());

		synchronized(acknowledgeableVariable){
			acknowledgeableVariables.add(acknowledgeableVariable);

			toolInstance.send(putOperation);

			try{
				// If the above send call was synchronious the notify already
				// occured and this lock will block indefinately, so check if
				// the variable is still present in the collection before
				// blocking.
				if(acknowledgeableVariables.contains(transactionID)){
					acknowledgeableVariable.wait();
				}
			}catch(InterruptedException irex){
				Logger.getInstance().log("Interrupted while waiting for an acknowlegement for transaction: - " + transactionID + ".", Logger.ERROR, irex);
			}
		}
	}

	/**
	 * Receives a note.
	 * 
	 * @param note
	 *            the note that will be received.
	 */
	public abstract void receiveNote(FinalizableVariable note);

	/**
	 * Terminates this process instance.
	 */
	public abstract void terminate();
}
