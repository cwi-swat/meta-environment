package toolbus.communication;

import aterm.ATerm;

/**
 * This class enables direct communication (through java method calls) between a client and a
 * server, under the condition that they are running the the same VM. This class does nothing fancy,
 * it just passes messages between the data handler and its I/O handler counter part.
 * 
 * @author Arnold Lankamp
 */
public class DirectIOHandler implements IIOHandler{
	private final IDataHandler dataHandler;
	private volatile DirectIOHandler directIOHandler = null;

	/**
	 * Constructor.
	 * 
	 * @param dataHandler
	 *            The data handler this I/O handler is associated with.
	 */
	public DirectIOHandler(IDataHandler dataHandler){
		super();

		this.dataHandler = dataHandler;
	}

	/**
	 * Links this I/O handler with its counter part.
	 * 
	 * @param directIOHandler
	 *            The counter part of this I/O handler.
	 */
	public void setDirectIOHandler(DirectIOHandler directIOHandler){
		this.directIOHandler = directIOHandler;
	}

	/**
	 * @see IIOHandler#receive(byte, ATerm)
	 */
	public void receive(byte operation, ATerm aTerm){
		dataHandler.receive(operation, aTerm);
	}

	/**
	 * @see IIOHandler#send(byte, ATerm)
	 */
	public void send(byte operation, ATerm aTerm){
		directIOHandler.receive(operation, aTerm);
	}

	/**
	 * @see IIOHandler#terminate()
	 */
	public void terminate(){
		directIOHandler.shutDown();
	}

	/**
	 * @see IIOHandler#shutDown()
	 */
	public void shutDown(){
		dataHandler.shutDown();
	}
	
	/**
	 * @see IIOHandler#exceptionOccured()
	 */
	public void exceptionOccured(){
		dataHandler.exceptionOccured();
	}
}
