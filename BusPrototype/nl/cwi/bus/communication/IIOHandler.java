package nl.cwi.bus.communication;

import nl.cwi.bus.communication.operations.AbstractOperation;


/**
 * Implementations of this interface handles the sending and receiving of
 * messages between a tool and a toolinstance
 * 
 * @author Arnold Lankamp
 */
public interface IIOHandler{
	/**
	 * Receives a operation and forwards it to the toolinstance
	 * 
	 * @param operation
	 *            The operation that was received
	 */
	void receive(AbstractOperation operation);

	/**
	 * Sends a operation to the tool
	 * 
	 * @param operation
	 *            the operation that will be send
	 */
	void send(AbstractOperation operation);
	
	/**
	 * Notifies this ioHandler that it will not receive any more data.
	 */
	void terminate();
}
