package nl.cwi.bus.communication;

import nl.cwi.bus.communication.operations.AbstractOperation;

/**
 * Facilitates a means of direct communication between the tool and the toolbus
 * 
 * @author Arnold Lankamp
 */
public class DirectIOHandler implements IIOHandler{
	private IIOHandler ioHandler = null;
	private IDataHandler dataHandler = null;

	/**
	 * Default constructor.
	 */
	public DirectIOHandler(){
		super();
	}

	/**
	 * Associates a dataHandler with this ioHandler.
	 * 
	 * @param dataHandler
	 *            The dataHandler that handles the incoming data
	 */
	public void setDataHandler(IDataHandler dataHandler){
		this.dataHandler = dataHandler;
	}

	/**
	 * Sets the counterpart of this ioHandler.
	 * 
	 * @param ioHandler
	 *            The counterpart of this ioHandler.
	 */
	public void setIOHandler(IIOHandler ioHandler){

		this.ioHandler = ioHandler;
	}

	/**
	 * Receives a message and forwards it to the datahandler
	 * 
	 * @see IIOHandler#receive(AbstractOperation)
	 * @param operation
	 *            The operation that was received.
	 */
	public void receive(AbstractOperation operation){
		if(operation.equals(AbstractOperation.END)){
			terminate();
		}else{
			dataHandler.receive(operation);
		}
	}

	/**
	 * Sends a message to the tool
	 * 
	 * @see IIOHandler#send(AbstractOperation)
	 * @param operation
	 *            The operation that will be send
	 */
	public void send(AbstractOperation operation){
		ioHandler.receive(operation);
	}

	/**
	 * Notifies this ioHandler that it is no longer required.
	 * 
	 * @see IIOHandler#terminate()
	 */
	public void terminate(){
		dataHandler.terminate();
	}
}
