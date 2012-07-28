package nl.cwi.bus.communication.operations;

import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.serializable.SerializableObject;

/**
 * Respresents a serializable operation.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractOperation extends SerializableObject{
	/**
	 * Operation id for sending variables.
	 */
	public final static String PUT = "put";
	/**
	 * Operation id for requesting variables.
	 */
	public final static String GET = "get";
	/**
	 * Operation id for conferming the reception of a via GET requested
	 * variable.
	 */
	public final static String ACK = "ack";
	/**
	 * Operation id for acknowledging the finalization of the variable at the
	 * toolbus level (so the 'source tool' can delete it whenever it feels like
	 * it).
	 */
	public final static String FIN = "fin";
	/**
	 * Operation id for termination of a connection.
	 */
	public final static String END = "end";
	/**
	 * Operation id for sending bus registration data to a tool.
	 */
	public final static String REG = "reg";
	
	/**
	 * Represtens the size of the field at the start of the messages that
	 * specifies the length of the message. A length of 4 bytes is enough because the
	 * maximum length of a string is 2GB
	 */
	public final static int LENGTHBYTES = NativeTypeBuilder.INTBYTES;
	
	/**
	 * Represents the size of the operation field.
	 */
	public final static int OPFIELDLENGTH = 3;
	
	/**
	 * Default constructor.
	 */
	public AbstractOperation(){
		super();
	}

	/**
	 * Returns the type of operation.
	 * 
	 * @return The type of operation.
	 */
	public abstract String getOperation();
	
	/**
	 * Creates an empty operation of the given type.
	 * The type must be valid (reg/put/get/ack/fin/end).
	 * @param operationID The identifier of the operation that needs to be created.
	 * @return The created (empty) operation.
	 */
	public static AbstractOperation createEmptyOperation(String operationID){
		AbstractOperation operation = null;
		if(operationID == REG){
			operation = new RegOperation();
		}else if(operationID == PUT){
			operation = new PutOperation();
		}else if(operationID == GET){
			operation = new GetOperation();
		}else if(operationID == ACK){
			operation = new AckOperation();
		}else if(operationID == FIN){
			operation = new FinOperation();
		}else if(operationID == END){
			operation = new EndOperation();
		}
		return operation;
	}
}
