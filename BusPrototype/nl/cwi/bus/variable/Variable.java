package nl.cwi.bus.variable;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;

import nl.cwi.bus.client.InterToolDataHandler;
import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.bus.communication.SelectorCreator;
import nl.cwi.bus.communication.SocketIOHandler;
import nl.cwi.bus.communication.operations.AbstractOperation;
import nl.cwi.bus.communication.operations.EndOperation;
import nl.cwi.bus.communication.operations.GetOperation;
import nl.cwi.bus.config.Config;
import nl.cwi.term.serializable.SerializableStringTerm;
import nl.cwi.util.IDGenerator;
import nl.cwi.util.logging.Logger;

/**
 * Represents a variable which can be transmitted between processes a tools. The
 * variable contains either a reference to the value of the variable or the
 * value itself; this is completely transparent for the 'user' of this object.
 * In case this object is a reference it will retreive and cache the value when
 * the getData() method is called.
 * 
 * @author Arnold Lankamp
 */
public class Variable{
	private final static int THRESHOLD = Config.getThreshold();

	private long variableID = -1;
	private String signature = null;

	private SerializableStringTerm data = null;

	private InetSocketAddress sourceToolAdress = null;
	private long sourceToolID = -1;

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term.
	 * @param sourceToolAdress
	 *            The adress of the tool containing the value.
	 * @param sourceToolID
	 *            The id of the tool containing the value.
	 */
	public Variable(SerializableStringTerm term, InetSocketAddress sourceToolAdress, long sourceToolID){
		super();

		variableID = IDGenerator.generate();

		signature = term.getSignature();

		this.data = term;

		this.sourceToolAdress = sourceToolAdress;
		this.sourceToolID = sourceToolID;
	}

	/**
	 * Constructor.
	 * 
	 * @param variableID
	 *            The id of the variable.
	 * @param signature
	 *            The signature of the data.
	 * @param data
	 *            The data (might be null).
	 * @param sourceToolAdress
	 *            The address of the tool containing the value of the variable.
	 * @param sourceToolID
	 *            The id of the tool.
	 */
	public Variable(long variableID, String signature, SerializableStringTerm data, InetSocketAddress sourceToolAdress, long sourceToolID){
		super();

		this.variableID = variableID;
		this.signature = signature;

		this.data = data;

		this.sourceToolAdress = sourceToolAdress;
		this.sourceToolID = sourceToolID;
	}

	/**
	 * Returns true if the size of the data acceeds the threshold.
	 * 
	 * @return True if the size of the data acceeds the threshold; returns false
	 *         otherwise.
	 */
	public boolean acceedsThreshold(){
		return (data == null || data.length() > THRESHOLD);
	}

	/**
	 * Returns the variable id. This id is unique for the creating tool.
	 * 
	 * @return The variable id
	 */
	public long getVariableID(){
		return variableID;
	}

	/**
	 * Returns the adress of the tool that is in possesion of the value of this
	 * variable.
	 * 
	 * @return The adress of the tool that is in possesion of the value of this
	 *         variable.
	 */
	public InetSocketAddress getSourceToolAdress(){
		return sourceToolAdress;
	}

	/**
	 * Returns the (ATerm) signature of the data
	 * 
	 * @return The signature
	 */
	public String getSignature(){
		return signature;
	}

	/**
	 * Returns the id of the tool that contains the data
	 * 
	 * @return The id of the 'source tool'
	 */
	public long getSourceToolID(){
		return sourceToolID;
	}
	
	/**
	 * Checks if this variable is a value or not.
	 * @return True if this variable is a value; false if it is a reference.
	 */
	public boolean isValue(){
		return data.hasContent();
	}

	/**
	 * Returns the data this variable contains. If the data is not present it
	 * will be retreived. This method should not be called from inside the
	 * toolbus!
	 * 
	 * @return The data this variable contains.
	 */
	public SerializableStringTerm getData(){
		if(!data.hasContent()) retrieve();

		return data;
	}

	/**
	 * Retrieves the data from the 'source tool' (if not done so already). This
	 * method must not be called from inside the toolbus! This to prevent
	 * retrieving values (because this is unwanted behavior).
	 */
	private synchronized void retrieve(){
		if(!data.hasContent()){
			// Initialize
			SocketChannel socketChannel = null;
			try{
				socketChannel = SocketChannel.open();
				socketChannel.connect(sourceToolAdress);
				socketChannel.configureBlocking(false);
			}catch(IOException ioex){
				Logger.getInstance().log("An IOException occured while setting up a connection", Logger.ERROR, ioex);
			}

			SelectorCreator selectorCreator = ToolRegistery.getInstance().getSelectorCreator();
			SocketIOHandler ioHandler = new SocketIOHandler(selectorCreator, socketChannel);
			ioHandler.setDataHandler(new InterToolDataHandler(ioHandler));

			Selector selector = selectorCreator.getSelector();
			Object selectionPreventionLock = selectorCreator.getSelectionPreventionLock();
			try{
				synchronized(selectionPreventionLock){
					selector.wakeup();
					synchronized(selector){
						socketChannel.register(selector, SelectionKey.OP_READ, ioHandler);
					}
				}
			}catch(IOException ioex){
				Logger.getInstance().log("An IOException occured during the registration for op_read.", Logger.ERROR, ioex);
			}

			RequestedVariableHandler requestedVariables = ToolRegistery.getInstance().getRequestedVariableHandler();

			requestedVariables.add(this);
			// Send get
			AbstractOperation getOperation = GetOperation.create(this);
			ioHandler.send(getOperation);

			VariableKey variableKey = createKey();

			requestedVariables.waitForReplacement(variableKey);

			// Disconnect
			ioHandler.send(new EndOperation());

			Variable variable = requestedVariables.get(variableKey);
			data = variable.getData();

			requestedVariables.remove(variableKey);
		}
	}

	/**
	 * Creates a key for this variable.
	 * 
	 * @return A key for this variable.
	 */
	public VariableKey createKey(){
		return new VariableKey(variableID, sourceToolID);
	}

	/**
	 * Structure that is used as key to uniquely identify the variables.
	 * 
	 * @author Arnold Lankamp
	 */
	public static class VariableKey{
		private long variableID = -1;
		private long sourceToolID = -1;

		private VariableKey(long variableID, long sourceToolID){
			super();

			this.variableID = variableID;
			this.sourceToolID = sourceToolID;
		}

		/**
		 * Custom equals method (because the semantics of all implementations of
		 * java.util.Map that seem to be broken / not complying with the
		 * documentation of JDK 1.5).
		 * 
		 * @param variableKey
		 *            The object to perform the equalization comparison on.
		 * @return True if the content of the given object is equal to the
		 *         content of this object.
		 */
		public boolean equals(VariableKey variableKey){
			boolean equals = false;
			if(variableKey.sourceToolID == sourceToolID && variableKey.variableID == variableID) equals = true;

			return equals;
		}
	}
}
