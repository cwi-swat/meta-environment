
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The exception port represents ports that are triggered when something
 * goes wrong.
 */

public class ExceptionPort extends DebugPort
{
  private String exception;
  private ATermPattern patternPort;

  //{ public ExceptionPort(String excep, int when)

  /**
   * Construct a new ExceptionPort object.
   */

  public ExceptionPort(String excep, int when)
  {
    super(EXCEPTION, when);
    exception = excep;
    init();
  }

  //}
  //{ public ExceptionPort(ATerm excep, int when)

  /**
    * Construct a new ExceptionPort object given its term representation.
    */
  
  public ExceptionPort(ATerm excep, int when)
  {
    super(EXCEPTION, when);
    exception = ((ATermAppl)excep).getFun();
    init();
  }

  //}
  //{ private void init()

  /**
    * Build any patterns needed.
    */

  private void init()
  {
    try {
      patternPort = ATerm.the_world.makePattern("[exception,<term>,<str>]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
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
  //{ public ATerm onthewire()

  /**
    * Build a term representing this debug port that can be send 
    * over the ToolBus.
    */

  public ATerm onthewire()
  {
    return patternPort.make(getWhenTerm(), exception);
  }

  //}
}
