package nl.cwi.bus.server;

import nl.cwi.bus.communication.IDataHandler;
import nl.cwi.bus.communication.IIOHandler;
import nl.cwi.bus.communication.IToolDataHandler;
import nl.cwi.bus.communication.operations.AbstractOperation;
import nl.cwi.bus.communication.operations.AckOperation;
import nl.cwi.bus.communication.operations.PutOperation;
import nl.cwi.bus.communication.operations.RegOperation;
import nl.cwi.bus.server.test.TestProcess;
import nl.cwi.bus.variable.AcknowledgeableVariables;
import nl.cwi.bus.variable.FinalizableVariable;
import nl.cwi.util.IDGenerator;

/**
 * Represents an instance of a tool.
 * 
 * @author Arnold Lankamp
 */
public class ToolInstance implements IToolDataHandler{
	private AbstractProcessInstance processInstance = null;
	private IIOHandler ioHandler = null;
	private long id = -1;

	/**
	 * Constructor.
	 * 
	 * @param ioHandler
	 *            Handles io between the tool and this toolinstance.
	 */
	public ToolInstance(IIOHandler ioHandler){
		super();

		this.ioHandler = ioHandler;

		id = IDGenerator.generate();

		// Send the registration data to the tool.
		RegOperation regOperation = new RegOperation(id);
		send(regOperation);

		Bus.getInstance().getTools().register(this);

		// Temp for testing only
		processInstance = new TestProcess(this);
		ProcessManager processManager = Bus.getInstance().getProcesses();
		processManager.register(processInstance);
	}

	/**
	 * Returns the id of this tool.
	 * 
	 * @return the id of this tool.
	 */
	public long getID(){
		return id;
	}

	/**
	 * Send the given operation to the tool.
	 * 
	 * @see IDataHandler#send(AbstractOperation)
	 * @param operation
	 *            The operation to send
	 */
	public void send(AbstractOperation operation){
		ioHandler.send(operation);
	}

	/**
	 * Receives a message from the tool.
	 * 
	 * @see IDataHandler#receive(AbstractOperation)
	 * @param operation
	 *            The received operation
	 */
	public void receive(AbstractOperation operation){
		String operationID = operation.getOperation().intern();

		if(operationID == AbstractOperation.PUT){
			PutOperation putOperation = (PutOperation) operation;

			MessageQueue messageQueue = Bus.getInstance().getMessageQueue();
			FinalizableVariable variable = new FinalizableVariable(putOperation.createVariable());
			variable.incrementReferenceCount();
			messageQueue.add(variable);

			// End temp
		}else if(operationID == AbstractOperation.ACK){
			AckOperation ackOperation = (AckOperation) operation;
			long tranactionID = ackOperation.getTransactionID();

			AcknowledgeableVariables acknowledgeableVariables = Bus.getInstance().getAcknowledgeableVariables();
			acknowledgeableVariables.notifyAndRemove(tranactionID);
		}
	}

	/**
	 * Reinstalls the ioHandler for the tool
	 */
	public void reconnect(){
		// TODO
	}

	/**
	 * Called when the the associated tool has become disconnected.
	 */
	public void disconnected(){
		// TODO
	}

	/**
	 * Terminates this toolinstance (Happens when a tool or the bus is
	 * terminated).
	 * 
	 * @see IDataHandler#terminate()
	 */
	public void terminate(){
		Bus bus = Bus.getInstance();
		bus.getTools().deregister(this);

		bus.getProcesses().deregister(processInstance);

		bus.getAcknowledgeableVariables().invalidateAcks(id);
	}
}
