package toolbus;

/**
 * @author paulk, Aug 7, 2002
 * 
 * ToolBusDeathException is thrown when ToolBus execution halts.
 */
public class ToolBusDeathException extends ToolBusException {

  public ToolBusDeathException(String arg0) {
    super("Factal error during ToolBus execution: " + arg0);
  }

}
