package toolbus.exceptions;

/**
 * @author paulk, Jul 29, 2002 ToolBusException: thrown when a user-related error-condition occurs.
 */
public class ToolBusException extends Exception{
	private static final long serialVersionUID = -8339093187884828122L;
	
	/**
	 * Constructor for ToolBusRunTimeException.
	 * 
	 * @param arg0
	 */
	public ToolBusException(String arg0){
		super(arg0);
	}
	
	public ToolBusException(Throwable t){
		super(t);
	}
}
