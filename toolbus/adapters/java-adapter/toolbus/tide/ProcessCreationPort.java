
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The ProcessCreationPort represents ports that are triggered
 * when a process is created.
 */

public class ProcessCreationPort extends DebugPort
{
  ATermPattern patternPort;

  //{ public ProcessCreationPort()

  /**
   * Construct a new ProcessCreationPort object.
   */

  public ProcessCreationPort()
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
      patternPort = new ATermPattern("[process-creation,at]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
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
    return patternPort.make();
  }

  //}
}
