package toolbus;

/**
 * @author paulk, Jul 29, 2002
 */
/**
 * @author paulk, Jul 28, 2002
 */
public class ToolBusInternalError extends Error {


	public ToolBusInternalError() {
		super();
	}

	public ToolBusInternalError(String arg0) {
		super("ToolBus: " + arg0);
	}

}
