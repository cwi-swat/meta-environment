
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The SendPort represents ports that are triggered when 
 * a message was send by a process.
 */

public class SendPort extends DebugPort
{
  private int exec_state;
  private ATerm port;

  //{ public SendPort(int when, String pattern)

  /**
   * Construct a new SendPort object.
   */

  public SendPort(int when, String pattern)
  {
    super(SEND, when);
    try {      
      port = ATerm.the_world.makeSimple("[send,"+getWhenString()+","+pattern+"]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("parse error in pattern");
    }
  }

  //}
  //{ public SendPort(int when, ATerm pattern)

  /**
   * Construct a new SendPort object.
   */ 

  public SendPort(int when, ATerm pattern)
  {
    super(SEND, when);
    try {
      ATermPattern pat = ATerm.the_world.makePattern("[send,"+getWhenString()+",<term>]");
      port = pat.make(pattern);
    } catch (ParseError e) {
      throw new IllegalArgumentException("parse error in pattern");
    }
  }

  //}
  //{ public ATerm onthewire()

  /**
    * Build a term representing this debug port that can be send 
    * over the ToolBus.
    */

  public ATerm onthewire()
  {
    return port;
  }

  //}
}




