package nl.cwi.bus.communication.operations;

/**
 * Represents a termination message.
 * 
 * @author Arnold Lankamp
 */
public class EndOperation extends AbstractOperation{
	private final static String OPERATION = AbstractOperation.END;
	
	/**
	 * Default constructor.
	 */
	public EndOperation(){
		super();
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
