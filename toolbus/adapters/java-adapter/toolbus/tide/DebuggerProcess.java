package toolbus.tide;

import java.util.*;

public class DebuggerProcess extends DebugProcess
{
  private Vector alwaysRules;

  //{ public DebuggerProcess(int pid)

  /**
   * Construct a new process. Initially, it has no name.
   */

  public DebuggerProcess(int procid)
  {
    super(0, procid);
    alwaysRules = new Vector();
  }

  //}
  //{ public DebuggerProcess(int pid, String name)

  /**
   * Construct a new process.
   */

  public DebuggerProcess(int procid, String name)
  {
    super(0, procid, name);
    alwaysRules = new Vector();
  }

  //}
  //{ public void addAlwaysRule(DebugRule rule)

  /**
    * Add an always rule
    */

  public void addAlwaysRule(DebugRule rule)
  {
    alwaysRules.addElement(rule);
  }

  //}
  //{ public void removeAlwaysRule(DebugRule rule)

  /**
    * Remove an always rule
    */

  public void removeAlwaysRule(DebugRule rule)
  {
    alwaysRules.removeElement(rule);
  }

  //}
  //{ public Vector getAlwaysRules()

  /**
    * Retrieve a list of always rules
    */

  public Vector getAlwaysRules()
  {
    return alwaysRules;
  }

  //}

}
