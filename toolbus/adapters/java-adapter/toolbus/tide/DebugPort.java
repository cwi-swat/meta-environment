
package toolbus.tide;
import toolbus.aterm.*;

/**
 * DebugPort objects represent the ports at which execution can be halted.
 */

abstract public class DebugPort
{
  //{ Port types

  static public int EXEC_STATE            = 0;
  static public int ALWAYS                = 1;
  static public int LOCATION              = 2;
  static public int CALL                  = 3;
  static public int RETRY                 = 4;
  static public int FAIL                  = 5;
  static public int SUCCEED		  = 6;
  static public int EXCEPTION	          = 7;
  static public int VARIABLE	          = 8;
  static public int SEND		  = 9;
  static public int RECEIVE		  = 10;
  static public int PROCESS_CREATION      = 11;
  static public int PROCESS_DESTRUCTION   = 12;
  static public int NR_PORT_TYPES	  = 13;

  //}
  //{ When constants

  public static int WHEN_AT     = 0;
  public static int WHEN_BEFORE = 1;
  public static int WHEN_AFTER  = 2;

  //}

  private int type;
  private int when;

  //{ public DebugPort(int type, int when)

  /**
   * Construct a new debug port.
   * @argument type The type of the port (i.e. DebugPort.LOCATION)
   * @argument when When is this port activated? (BEFORE, AFTER, or AT the type)
   */

  public DebugPort(int type, int when)
  {
    this.type = type;
    this.when = when;
  }

  //}
  //{ int getType()

  /**
   * Retrieve the type of this port.
   */

  int getType()
  {
    return type;
  }

  //}
  //{ int getWhen()
  
  /**
   * Retrieve the activation moment of this port.
   */

  int getWhen()
  {
    return when;
  }

  //}
}


