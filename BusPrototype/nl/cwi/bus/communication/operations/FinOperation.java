package nl.cwi.bus.communication.operations;

import nl.cwi.util.NativeTypeBuilder;

/**
 * Represents a ack operation.
 * 
 * @author Arnold Lankamp
 */
public class FinOperation extends AbstractOperation{
	private final static String OPERATION = AbstractOperation.FIN;
	
	private byte[] variableIDBytes = null;
	
	/**
	 * Default constructor.
	 */
	public FinOperation(){
		super();
		
		variableIDBytes = new byte[NativeTypeBuilder.LONGBYTES];
		
		init();
	}
	
	/**
	 * Constructor.
	 * 
	 * @param variableID
	 *            The for the 'source tool' unique variable identifier.
	 */
	public FinOperation(long variableID){
		super();

		variableIDBytes = NativeTypeBuilder.makeBytesFromLong(variableID);
		
		init();
	}
	
	/**
	 * Initializes this operation.
	 */
	private void init(){
		registerNativeType(variableIDBytes.length, variableIDBytes);
	}

	/**
	 * Returns the type of operation.
	 * 
	 * @see AbstractOperation#getOperation()
	 * @return The type of operation.
	 */
	public String getOperation(){
		return OPERATION;
	}

	/**
	 * Returns the id of the variable.
	 * 
	 * @return The id of the variable.
	 */
	public long getVariableID(){
		return NativeTypeBuilder.makeLong(variableIDBytes);
	}
}
