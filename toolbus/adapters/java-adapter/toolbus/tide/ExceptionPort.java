
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The exception port represents ports that are triggered when something
 * goes wrong.
 */

public class ExceptionPort extends DebugPort
{
  private String exception;

  //{ public ExceptionPort(String excep, int when)

  /**
   * Construct a new ExceptionPort object.
   */

  public ExceptionPort(String excep, int when)
  {
    super(EXCEPTION, when);
    exception = excep;
  }

  //}
  //{ public String getException()

  /**
   * Retrieve the exception of this port.
   */

  public String getException()
  {
    return exception;
  }

  //}
}
