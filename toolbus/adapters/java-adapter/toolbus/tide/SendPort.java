
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The SendPort represents ports that are triggered when 
 * a message was send by a process.
 */

public class SendPort extends DebugPort
{
  private int exec_state;
  private ATermRef port;

  //{ public SendPort(int when, String pattern)

  /**
   * Construct a new SendPort object.
   */

  public SendPort(int when, String pattern)
  {
    super(SEND, when);
    try {      
      port = ATermParser.makeSimple("[send,"+getWhenString()+","+pattern+"]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("parse error in pattern");
    }
  }

  //}
  //{ public SendPort(int when, ATermRef pattern)

  /**
   * Construct a new SendPort object.
   */ 

  public SendPort(int when, ATermRef pattern)
  {
    super(SEND, when);
    try {
      ATermPattern pat = new ATermPattern("[send,"+getWhenString()+",<term>]");
      port = pat.make(pattern);
    } catch (ParseError e) {
      throw new IllegalArgumentException("parse error in pattern");
    }
  }

  //}
  //{ public ATermRef onthewire()

  /**
    * Build a term representing this debug port that can be send 
    * over the ToolBus.
    */

  public ATermRef onthewire()
  {
    return port;
  }

  //}
}




