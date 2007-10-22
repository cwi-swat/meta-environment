package toolbus.communication;

import aterm.ATerm;

/**
 * IOHandlers facilitate the transfer of terms from and to the ToolBus and tools.
 * 
 * @author Arnold Lankamp
 */
public interface IIOHandler{

	/**
	 * Sends a term to the remote location.
	 * 
	 * @param operation
	 *            The operation associated with the term we need to send.
	 * @param aTerm
	 *            The term that needs to be send.
	 */
	void send(byte operation, ATerm aTerm);

	/**
	 * Receives a term from the remote location.
	 * 
	 * @param operation
	 *            The operation associated with the term we received.
	 * @param aTerm
	 *            The term that was received.
	 */
	void receive(byte operation, ATerm aTerm);

	/**
	 * Requests the termination of this ioHandler.
	 */
	void terminate();

	/**
	 * Shuts down this ioHandler and it's associated datahandler. IMPORTANT: This method should not
	 * be called from outside the ioHandler. Manual invokation will lead to undefined behaviour.
	 */
	void shutDown();
	
	/**
	 * Notifies the I/O handler that an exception has occured so it can take the nessacary steps.
	 */
	void exceptionOccured();
}
