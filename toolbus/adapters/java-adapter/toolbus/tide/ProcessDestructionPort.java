
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The ProcessDestructionPort represents ports that are triggered
 * when a process is destroyed.
 */

public class ProcessDestructionPort extends DebugPort
{
  ATermPattern patternPort;

  //{ public ProcessDestructionPort()

  /**
   * Construct a new ProcessDestructionPort object.
   */

  public ProcessDestructionPort()
  {
    super(EXEC_STATE, WHEN_AT);
    init();
  }

  //}
  //{ private void init()

  /**
    * Build needed patterns.
    */

  private void init()
  {
    try {
      patternPort = ATerm.the_world.makePattern("[process-destruction,at]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
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
    return patternPort.make();
  }

  //}
}
