
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
  //{ public ExecStatePort(ATermRef es, int when)

  /**
    * Construct a new ExecStatePort object given its term representation.
    */

  public ExecStatePort(ATermRef es, int when)
  {
    super(EXEC_STATE, when);
    exec_state = DebugProcess.execStateTerm2Int(es);
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
