package nl.cwi.bus.communication.operations;

import nl.cwi.util.NativeTypeBuilder;


public class RegOperation extends AbstractOperation{
	private final static String OPERATION = AbstractOperation.REG;
	
	private byte[] toolIDBytes = null;
	
	/**
	 * Default constructor.
	 */
	public RegOperation(){
		super();
		
		toolIDBytes = new byte[NativeTypeBuilder.LONGBYTES];
		
		init();
	}

	/**
	 * Constructor.
	 * 
	 * @param toolID
	 *            The tool id.
	 */
	public RegOperation(long toolID){
		super();

		toolIDBytes = NativeTypeBuilder.makeBytesFromLong(toolID);
		
		init();
	}
	
	/**
	 * Initializes this operation.
	 */
	private void init(){
		registerNativeType(toolIDBytes.length, toolIDBytes);
	}

	/**
	 * Returns the tool id.
	 * 
	 * @return the tool id.
	 */
	public long getToolID(){
		return NativeTypeBuilder.makeLong(toolIDBytes);
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
}
