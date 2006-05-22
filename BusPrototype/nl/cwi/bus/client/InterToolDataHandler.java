package nl.cwi.bus.client;

import nl.cwi.bus.communication.IIOHandler;
import nl.cwi.bus.communication.IToolDataHandler;
import nl.cwi.bus.communication.operations.AbstractOperation;
import nl.cwi.bus.communication.operations.GetOperation;
import nl.cwi.bus.communication.operations.PutOperation;
import nl.cwi.bus.variable.RequestedVariableHandler;
import nl.cwi.bus.variable.Variable;
import nl.cwi.bus.variable.VariableHandler;
import nl.cwi.util.logging.Logger;

/**
 * Handles the incoming requests form other tools.
 * 
 * @author Arnold Lankamp
 */
public class InterToolDataHandler implements IToolDataHandler{
	private IIOHandler ioHandler = null;

	/**
	 * Constructor
	 * 
	 * @param ioHandler
	 *            The ioHandler that will be used for communication.
	 */
	public InterToolDataHandler(IIOHandler ioHandler){
		super();

		this.ioHandler = ioHandler;
	}

	/**
	 * Sends a message a tool.
	 * 
	 * @param operation
	 *            The operation to send.
	 */
	public void send(AbstractOperation operation){
		ioHandler.send(operation);
	}

	/**
	 * Receives a request from a tool and handles it.
	 * 
	 * @param operation
	 *            The request to handle.
	 */
	public void receive(AbstractOperation operation){
		String operationID = operation.getOperation().intern();

		if(operationID == AbstractOperation.PUT){
			RequestedVariableHandler requestedVariables = ToolRegistery.getInstance().getRequestedVariableHandler();
			PutOperation putOperation = (PutOperation) operation;
			Variable variable = putOperation.createVariable();
			
			requestedVariables.replace(variable);
		}else if(operationID == AbstractOperation.GET){
			GetOperation getOperation = (GetOperation) operation;
			long variableID = getOperation.getVariableID();
			
			VariableHandler variableHandler = ToolRegistery.getInstance().getVariableHandler();
			Variable variable = variableHandler.get(variableID);

			AbstractOperation putOperation = PutOperation.create(variable);
			send(putOperation);
		}else{
			Logger.getInstance().log("Unknown operationID: " + operationID, Logger.ERROR);
		}
	}

	/**
	 * Notifies this datahandler that there will be no more incoming requests.
	 */
	public void terminate(){
	// Do nothing, when a termination request is received this object will
	// become subject to collection shortly thereafter.
	}
}
