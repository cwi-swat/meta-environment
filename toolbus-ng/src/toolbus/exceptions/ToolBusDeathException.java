package toolbus.exceptions;

/**
 * @author paulk, Aug 7, 2002 ToolBusDeathException is thrown when ToolBus execution halts.
 */
public class ToolBusDeathException extends ToolBusException{
	private static final long serialVersionUID = 7293249066412537574L;
	
	public ToolBusDeathException(String arg0){
		super("Factal error during ToolBus execution: " + arg0);
	}
}
