package toolbus;

/**
 * @author paulk, Jul 29, 2002
 * 
 * ToolBusException: thrown when a user-related error-condition occurs.
 */
public class ToolBusException extends Exception {

  /**
   * Constructor for ToolBusRunTimeException.
   */
  public ToolBusException() {
    super();
  }

  /**
   * Constructor for ToolBusRunTimeException.
   * @param arg0
   */
  public ToolBusException(String arg0) {
    super(arg0);
  }

}
