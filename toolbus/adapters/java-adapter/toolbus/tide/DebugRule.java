
package toolbus.tide;
import toolbus.aterm.*;

/**
 * DebugRule objects represents rules consisting of a port,
 * a condition, a list of event actions, and a lifetime,
 * and of course the list of processes for which this rule applies.
 */

public class DebugRule
{
  static public int ONE_SHOT   = 0;
  static public int PERSISTENT = 1;
  static int idCount = 0;

  private int id;
  private DebugPort port;
  private ATermRef condition;
  private ATermsRef actions;
  private int lifetime;
  private DebugProcess[] processes;

  //{ static public int lifeTerm2Int(ATermRef lifetime)

  /**
    * Translate a lifetime term into an integer.
    */

  static public int lifeTerm2Int(ATermRef lifetime)
  {
    if(((ATermApplRef)lifetime).getFun().equals("one-shot"))
      return ONE_SHOT;
    return PERSISTENT;
  }

  //}

  //{ public DebugRule(DebugProcess[] procs, DebugPort p, ATermRef cond, ATermsRef acts, int lifetime)

  /**
   * Construct a new DebugRule object.
   */

  public DebugRule(DebugProcess[] procs, DebugPort p, ATermRef cond, ATermsRef acts, int lifetime)
  {
    processes = procs;
    port = p;
    condition = cond;
    actions = acts;
    this.lifetime = lifetime;
    id = idCount++;
  }

  //}
  //{ public int getId()

  /**
   * Retrieve the rule id of this rule.
   */

  public int getId()
  {
    return id;
  }

  //}

  //{ public DebugPort getPort()

  /**
   * Retrieve the port of this rule.
   */

  public DebugPort getPort()
  {
    return port;
  }

  //}
  //{ public DebugProcess[] getProcesses()

  /**
    * Return the processes for which this rule applies.
    */

  public DebugProcess[] getProcesses()
  {
    return processes;
  }

  //}
}
