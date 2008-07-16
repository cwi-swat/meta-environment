package toolbus.exceptions;

/**
 * @author paulk, Jul 29, 2002 ToolBusException: thrown when a user-related error-condition occurs.
 */
public class ToolBusException extends Exception{
	private static final long serialVersionUID = 385761684682558825L;

	/**
	 * Constructor for ToolBusRunTimeException.
	 * 
	 * @param arg0
	 */
	public ToolBusException(String message){
		super(message);
	}
	
	public ToolBusException(String message, Throwable t){
		super(message, t);
	}
}
