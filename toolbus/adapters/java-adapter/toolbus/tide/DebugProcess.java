
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

  static public final int ES_NONE             = 0;
  static public final int ES_STOP             = 0x0001;
  static public final int ES_RUN	      = 0x0002;
  static public final int ES_SINGLE_STEP      = 0x0004;
  static public final int ES_STEP_OVER	      = 0x0008;
  static public final int ES_RUN_UNTIL_PARENT = 0x0010;
  static public final int ES_ALL	      = 0x001F;

  //}

  private int pid;
  private int dap;
  private String name = null;
  private int exec_state = ES_NONE;
  boolean high_water = false;
  private SourceArea location = null;
  int rule_id = -1;
  DebugPort port = null;
  private Hashtable aliases = new Hashtable(5);
  
  //{ static public int execStateTerm2Int(ATermRef es)

  /**
    * Transform a term representing an exec-state into an integer.
    */

  static public int execStateTerm2Int(ATermRef es)
  {
    String fun = ((ATermApplRef)es).getFun();
    if(fun.equals("stop"))
      return ES_STOP;
    if(fun.equals("run"))
      return ES_RUN;
    if(fun.equals("single-step"))
      return ES_SINGLE_STEP;
    if(fun.equals("step-over"))
      return ES_STEP_OVER;
    if(fun.equals("run-until-parent"))
      return ES_RUN_UNTIL_PARENT;
    if(fun.equals("all"))
      return ES_ALL;

    throw new IllegalArgumentException("illegal exec-state term: " + es.toString());
  }

  //}
  //{ static public ATermRef execStateInt2Term(int es)

  /**
    * Transform a term representing an exec-state into an integer.
    */

  static public ATermRef execStateInt2Term(int es)
  {
    switch(es) {
      case ES_STOP:             return new ATermApplRef("stop", null);
      case ES_RUN:              return new ATermApplRef("run", null);
      case ES_SINGLE_STEP:      return new ATermApplRef("single-step", null);
      case ES_STEP_OVER:        return new ATermApplRef("step-over", null);
      case ES_RUN_UNTIL_PARENT: return new ATermApplRef("run-until-parent", null);
      case ES_ALL:              return new ATermApplRef("all", null);
    }
    throw new IllegalArgumentException("illegal exec-state: " + es);
  }

  //}

  //{ public DebugProcess(int dapid, int pid)

  /**
   * Construct a new process. Initially, it has no name.
   */

  public DebugProcess(int dapid, int procid)
  {
    pid = procid;
    dap = dapid;
  }

  //}
  //{ public DebugProcess(int dapid, int pid, String name)

  /**
   * Construct a new process.
   */

  public DebugProcess(int dapid, int procid, String name)
  {
    pid = procid;
    dap = dapid;
    this.name = name;
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
  //{ public int getDap()

  /**
    * Retrieve the debug-adapter id of this process.
    */

  public int getDap()
  {
    return dap;
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
  //{ public String getExecStateString()

  /**
    * Retrieve a string representing the current state of execution.
    */

  public String getExecStateString()
  {
    switch(exec_state) {
      case ES_NONE:             return "none";
      case ES_STOP:             return "stopped";
      case ES_RUN:              return "running";
      case ES_SINGLE_STEP:      return "single-step";
      case ES_STEP_OVER:        return "step-over";
      case ES_RUN_UNTIL_PARENT: return "run-until-parent";
    }
    throw new IllegalArgumentException("illegal exec state");
  }

  //}
  //{ public boolean isRunning()

  /**
    * Check if this process is currently doing anything.
    */

  public boolean isRunning()
  {
    if(exec_state == ES_STOP || exec_state == ES_NONE)
      return false;
    return true;
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
  //{ public void addAlias(ATermRef alias)

  /**
    * Add an alias to this process.
    */

  public void addAlias(ATermRef alias)
  {
    aliases.put(alias,alias);
  }

  //}
  //{ public Enumeration getAliases()

  /**
    * Return a list of aliases.
    */

  public Enumeration getAliases()
  {
    return aliases.keys();
  }

  //}
  //{ public boolean isAlias(ATermRef alias)

  /**
    * Check if a term is an alias of this process.
    */

  public boolean isAlias(ATermRef alias)
  {
    return aliases.containsKey(alias);
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

