package toolbus;

/**
 * @author paulk, Aug 7, 2002
 * 
 * ToolBusDeathException is thrown when ToolBus execution halts.
 */
public class ToolBusDeathException extends ToolBusException {

  /**
   * Constructor for ToolBusDeathException.
   */
  public ToolBusDeathException() {
    super();
  }

  /**
   * Constructor for ToolBusDeathException.
   * @param arg0
   */
  public ToolBusDeathException(String arg0) {
    super(arg0);
  }

}
