
package toolbus.tide;
import toolbus.aterm.*;
import java.util.*;

/**
 * The class DebugProcess keeps track of a process controlled
 * by a debug adapter.
 */

class DebugProcess
{
  //{ exec state constants

  static public int ES_NONE             = 0;
  static public int ES_STOP             = 0x0001;
  static public int ES_RUN		= 0x0002;
  static public int ES_SINGLE_STEP	= 0x0004;
  static public int ES_STEP_OVER	= 0x0008;
  static public int ES_RUN_UNTIL_PARENT	= 0x0010;
  static public int ES_HIGH_WATER	= 0x0020;
  static public int ES_ALL		= 0x003F;

  //}

  private int pid;
  private String name = null;
  private int exec_state = ES_NONE;
  boolean high_water = false;
  private SourceArea location = null;
  int rule_id = -1;
  DebugPort port = null;
  
  //{ public DebugProcess(int pid)

  /**
   * Construct a new process. Initially, it has no name.
   */

  public DebugProcess(int procid)
  {
    pid = procid;
  }

  //}
  //{ public int getPid()

  /**
   * Retrieve the process-id of this process.
   */

  public int getPid()
  {
    return pid;
  }

  //}
  //{ public void setName(String name)

  /**
   * Change the name of a process.
   */

  public void setName(String n)
  {
    name = n;
  }

  //}
  //{ public String getName()

  /**
   * Retrieve the name of a process.
   */

  public String getName()
  {
    return name;
  }

  //}
  //{ public void setExecState(int es)

  /**
   * Change the execution state of a process.
   */

  public void setExecState(int es)
  {
    exec_state = es;
  }

  //}
  //{ public int getExecState()

  /**
   * Retrieve the execution state of a process.
   */

  int getExecState()
  {
    return exec_state;
  }

  //}
  //{ public void setLocation(SourceArea loc)

  /**
   * Change the current source location.
   */

  public void setLocation(SourceArea loc)
  {
    location = loc;
  }

  //}
  //{ public SourceArea getLocation()

  /**
   * Retrieve the current location.
   */

  public SourceArea getLocation()
  {
    return location;
  }

  //}
  //{ public void setRuleId(int rid)

  /**
   * Change the current rule id.
   */

  public void setRuleId(int rid)
  {
    rule_id = rid;
  }

  //}
  //{ public int getRuleId()

  /**
   * Retrieve the current rule id.
   */

  public int getRuleId()
  {
    return rule_id;
  }

  //}
  //{ public void setPort(DebugPort p)

  /**
   * Change the current port.
   */

  public void setPort(DebugPort p)
  {
    port = p;
  }

  //}
  //{ public DebugPort getPort()

  /**
   * Retrieve the current port.
   */

  public DebugPort getPort()
  {
    return port;
  }

  //}

  //{ public String toString()

  /**
   * Return the string representation of a process (i.e. INIT(0))
   */

  public String toString()
  {
    return name + "(" + pid + ")";
  }
  
  //}
}

