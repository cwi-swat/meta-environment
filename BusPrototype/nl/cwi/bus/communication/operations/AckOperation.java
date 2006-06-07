package nl.cwi.bus.communication.operations;

import nl.cwi.util.NativeTypeBuilder;

public class AckOperation extends AbstractOperation{
	private final static String OPERATION = AbstractOperation.ACK;
	
	private byte[] transactionID = null;
	
	/**
	 * Default constructor.
	 */
	public AckOperation(){
		super();
		
		transactionID = new byte[NativeTypeBuilder.LONGBYTES];
		
		init();
	}

	/**
	 * Constructor.
	 * 
	 * @param transactionID
	 *            The id of the transaction that needs to be acknowledged.
	 */
	public AckOperation(long transactionID){
		super();

		this.transactionID = NativeTypeBuilder.makeBytesFromLong(transactionID);
		
		init();
	}
	
	/**
	 * Initializes this operation.
	 */
	private void init(){
		registerNativeType(transactionID);
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
	 * Returns the transaction identifier.
	 * @return The transaction identifier.
	 */
	public long getTransactionID(){
		return NativeTypeBuilder.makeLong(transactionID);
	}
}
