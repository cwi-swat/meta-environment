
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The ExecStatePort represents ports that are triggered when the
 * execution state of a process changes.
 */

public class ExecStatePort extends DebugPort
{
  private int exec_state;
  private ATermPattern patternPort;

  //{ public ExecStatePort(int es, int when)

  /**
   * Construct a new ExecStatePort object.
   */

  public ExecStatePort(int es, int when)
  {
    super(EXEC_STATE, when);
    exec_state = es;
    init();
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
      patternPort = new ATermPattern("[exec-state,<term>,<term>]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
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
  //{ public ATermRef getExecStateTerm()

  /**
   * Retrieve the exec state of this port.
   */

  public ATermRef getExecStateTerm()
  {
    return DebugProcess.execStateInt2Term(exec_state);
  }

  //}
  //{ public ATermRef onthewire()

  /**
    * Build a term representing this debug port that can be send 
    * over the ToolBus.
    */

  public ATermRef onthewire()
  {
    return patternPort.make(getWhenTerm(), getExecStateTerm());
  }

  //}
}
