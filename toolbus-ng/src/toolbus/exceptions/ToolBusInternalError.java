package toolbus.exceptions;

/**
 * @author paulk, Jul 29, 2002 ToolBusInternalError is thrown when an (internal) system-related
 *         error occurs that "cannot happen".
 */
public class ToolBusInternalError extends Error{
	private static final long serialVersionUID = 4764978742884396840L;

	public ToolBusInternalError(String arg0){
		super("ToolBus Internal Error: " + arg0);
	}
}
