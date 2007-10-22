package toolbus.communication;

import aterm.ATerm;

/**
 * DataHandlers proces the data and supply the data for ioHandlers.
 * 
 * @author Arnold Lankamp
 */
public interface IDataHandler{

	/**
	 * Associates an ioHandler with the data handler. Every data handler needs one to operate and it
	 * must NOT be changed during it's operation.
	 * 
	 * @param ioHandler
	 *            The I/O handler we need to associate with the data handler.
	 */
	void setIOHandler(IIOHandler ioHandler);

	/**
	 * Forwards a term to the associated ioHandler.
	 * 
	 * @param operation
	 *            The operation associated with the term we need to send.
	 * @param aTerm
	 *            The term that needs to be transmitted.
	 */
	void send(byte operation, ATerm aTerm);

	/**
	 * Receives a term from the associated ioHandler.
	 * 
	 * @param operation
	 *            The operation associate with the term we received.
	 * @param aTerm
	 *            The term that was received.
	 */
	void receive(byte operation, ATerm aTerm);

	/**
	 * Requests the termination of this dataHandler.
	 */
	void terminate();

	/**
	 * Shuts down this dataHandler. IMPORTANT: this method may only be called by the associated
	 * ioHandler. Manual invokation will lead to undefined behaviour.
	 */
	void shutDown();
	
	/**
	 * Notifies the data handler that an exception has occured so it can take the nessacary steps.
	 */
	void exceptionOccured();
}
