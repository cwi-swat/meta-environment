
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

  private ATermPattern patternBreak;
  private ATermPattern patternWatch;

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
  //{ static public ATermRef lifeInt2Term(int lifetime)

  /**
    * Translate a lifetime integer into a term.
    */

  static public ATermRef lifeInt2Term(int lifetime)
  {
    if(lifetime == ONE_SHOT)
      return new ATermApplRef("one-shot", null);
    return new ATermApplRef("persistent", null);
  }

  //}

  //{ public DebugRule(DebugProcess[] procs, DebugPort p, ATermRef cond, ATermsRef acts, int lifetime)

  /**
   * Construct a new DebugRule object.
   */

  public DebugRule(DebugProcess[] procs, DebugPort p, ATermRef cond, 
		   ATermsRef acts, int lifetime)
  {
    processes = procs;
    port = p;
    condition = cond;
    actions = acts;
    this.lifetime = lifetime;
    id = idCount++;
    init();
  }

  //}
  //{ public DebugRule(int rid, DebugProcess[] procs, DebugPort p, ATermRef cond, ATermsRef acts, int lifetime)

  /**
   * Construct a new DebugRule object.
   */

  public DebugRule(int rid, DebugProcess[] procs, DebugPort p, ATermRef cond, 
		   ATermsRef acts, int lifetime)
  {
    processes = procs;
    port = p;
    condition = cond;
    actions = acts;
    this.lifetime = lifetime;
    id = idCount++;
    init();
  }

  //}
  //{ public void init()

  /**
    * Initialize this debug rule
    */

  public void init()
  {
    try {
      // Initialize a bunch of term patterns
      patternBreak = new ATermPattern("break");
      patternWatch = new ATermPattern("watch(<term>)");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
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

  //{ public boolean isBreakpoint()

  /**
    * Check if this debugrule represents a breakpoint.
    */

  public boolean isBreakpoint()
  {
    ATermsRef acts = actions;
    while(acts != null) {
      if(patternBreak.match(acts.getFirst()))
	return true;
      acts = acts.getNext();
    }

    return false;
  }

  //}
  //{ public boolean isWatchpoint()

  /**
    * Check if this debugrule represents a watchpoint.
    */

  public boolean isWatchpoint()
  {
    ATermsRef acts = actions;
    while(acts != null) {
      if(patternWatch.match(acts.getFirst()))
	return true;
      acts = acts.getNext();
    }

    return false;
  }

  //}

}
