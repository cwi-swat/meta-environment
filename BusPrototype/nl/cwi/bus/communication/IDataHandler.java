package nl.cwi.bus.communication;

import nl.cwi.bus.communication.operations.AbstractOperation;


/**
 * Handles data that was send of received from an IOHandler
 * 
 * @author Arnold Lankamp
 */
public interface IDataHandler{

	/**
	 * Send the given message to the tool
	 * 
	 * @param operation
	 *            The message to send
	 */
	void send(AbstractOperation operation);

	/**
	 * Receives a message from the tool
	 * 
	 * @param message
	 *            The received message
	 */
	void receive(AbstractOperation message);

	/**
	 * Notifies this dataHandler that there will be no furter communication and
	 * requests it to shut down.
	 */
	void terminate();
}
