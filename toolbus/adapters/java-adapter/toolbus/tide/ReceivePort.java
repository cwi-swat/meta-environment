
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The ReceivePort represents ports that are triggered when 
 * a message was Receive by a process.
 */

public class ReceivePort extends DebugPort
{
  private int exec_state;
  private ATermRef port;

  //{ public ReceivePort(int when, String pattern)

  /**
   * Construct a new ReceivePort object.
   */

  public ReceivePort(int when, String pattern)
  {
    super(RECEIVE, when);
    try {
      port = ATermParser.makeSimple("[receive,"+getWhenString()+","+pattern+"]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("parse error in pattern");
    }
  }

  //}
  //{ public ReceivePort(int when, ATermRef pattern)

  /**
   * Construct a new ReceivePort object.
   */ 

  public ReceivePort(int when, ATermRef pattern)
  {
    super(RECEIVE, when);
    try {
      ATermPattern pat = new ATermPattern("[receive,"+getWhenString()+",<term>]");
      port = pat.make(pattern);
    } catch (ParseError e) {
      throw new IllegalArgumentException("parse error in pattern");
    }
  }

  //}
  //{ public ATermRef onthewire()

  /**
    * Build a term representing this debug port that can be Receive 
    * over the ToolBus.
    */

  public ATermRef onthewire()
  {
    return port;
  }

  //}
}
