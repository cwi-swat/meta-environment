
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The ExecStatePort represents ports that are triggered when the
 * execution state of a process changes.
 */

public class ExecStatePort extends DebugPort
{
  private int exec_state;

  //{ public ExecStatePort(int es, int when)

  /**
   * Construct a new ExecStatePort object.
   */

  public ExecStatePort(int es, int when)
  {
    super(EXEC_STATE, when);
    exec_state = es;
  }

  //}
  //{ public int getExecState()

  /**
   * Retrieve the exec state of this port.
   */

  public int getExecState()
  {
    return exec_state;
  }

  //}
}
