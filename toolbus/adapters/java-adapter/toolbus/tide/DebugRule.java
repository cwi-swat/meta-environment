
package toolbus.tide;
import toolbus.aterm.*;

/**
 * DebugRule objects represents rules consisting of a port,
 * a condition, a list of event actions, and a lifetime.
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

  //{ public DebugRule(DebugPort p, ATermRef cond, ATermsRef acts, int lifetime)

  /**
   * Construct a new DebugRule object.
   */

  public DebugRule(DebugPort p, ATermRef cond, ATermsRef acts, int lifetime)
  {
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
}
