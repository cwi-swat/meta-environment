
package toolbus.tide;
import toolbus.aterm.*;
import java.util.*;

/**
 * The class DebugAdapterInfo keeps track of the current state
 * of a remote debug adapter.
 */

public class DebugAdapterInfo
{
  static protected int MAX_ADAPTERS = 128;
  static protected int MAX_RULES = 256;

  static DebugAdapterInfo[] adapters = new DebugAdapterInfo[MAX_ADAPTERS];

  ATermsRef info;
  int id;
  Vector[] ports;
  DebugRule[] rules;
  Hashtable processes;

  //{ static public DebugAdapterInfo getAdapter(int id)

  /**
   * Retrieve an adapter given its id.
   */

  static public DebugAdapterInfo getAdapter(int id)
  {
    return adapters[id];
  }

  //}
  //{ static public DebugAdapterInfo getAdapter(ATermRef dap)

  /**
   * Retrieve an adapter given its id as a term.
   */

  static public DebugAdapterInfo getAdapter(ATermRef dap)
  {
    return getAdapter(debugAdapterId(dap));
  }

  //}
  //{ static protected int debugAdapterId(ATermRef dap)

  /**
   * Analyze a term of the form "debug-adapter(<int>)", and return the
   * integer argument (which is the id of a debug adapter).
   */

  static protected int debugAdapterId(ATermRef dap)
  {
    ATermPattern P = null;
    try {
      P = new ATermPattern("debug-adapter(<int>)");
    } catch (ParseError e) { }
    if(!P.match(dap))
      throw new IllegalArgumentException("no debug-adapter id: " + dap.toString());
    return ((Integer)P.elementAt(0)).intValue();
  }

  //}

  //{ public DebugAdapterInfo(int ident, ATermsRef inf)

  /**
   * Construct a new DebugAdapterInfo object.
   */

  public DebugAdapterInfo(int ident, ATermsRef inf)
  {
    info = inf;
    id = ident;

    // Insert the adapter in the global adapter table.
    adapters[id] = this;

    // Create the table that contains all rules divided by type.
    ports = new Vector[DebugPort.NR_PORT_TYPES];
    for(int i=0; i<DebugPort.NR_PORT_TYPES; i++)
      ports[i] = new Vector();

    // Create the array that contains all rules indexed by rule id
    rules = new DebugRule[MAX_RULES];

    // Create the hashtable containing all the processes
    processes = new Hashtable();
  }

  //}

  //{ protected void remove()

  /**
   * Remove this object from the global adapter table.
   */

  public void remove()
  {
    adapters[id] = null;
  }

  //}
  //{ int getId()

  /**
   * Retrieve the id of this adapter. The id is an integer that uniquely
   * identifies a debug adapter.
   */

  int getId()
  {
    return id;
  }

  //}

  //{ public void addRule(Rule rule)

  /**
   * Add a rule to this debug adapter.
   */

  public void addRule(DebugRule rule)
  {
    if(rules[rule.getId()] != null)
      throw new ArrayIndexOutOfBoundsException("rule replacement not allowed: " +
				      rule.getId() + " = " + rule.toString());
    rules[rule.getId()] = rule;
    ports[rule.getPort().getType()].addElement(rule);
  }

  //}
  //{ public DebugRule getRule(int ruleId)

  /**
   * Retrieve a rule given its rule id
   */

  public DebugRule getRule(int ruleId)
  {
    return rules[ruleId];
  }

  //}
  //{ public Vector getPortRules(int portType)

  /**
   * Retrieve all rules of a certain port type.
   */

  public Vector getPortRules(int portType)
  {
    return ports[portType];
  }

  //}
  //{ public void removeRule(int ruleId)

  /**
   * Remove a rule given its rule id.
   */

  public void removeRule(int ruleId)
  {
    DebugRule rule = rules[ruleId];
    rules[ruleId] = null;
    Vector port = ports[rule.getPort().getType()];
    port.removeElement(rule);
  }

  //}

  //{ public void addProcess(DebugProcess process)

  /**
   * Add a new process to this debug adapter.
   */

  public void addProcess(DebugProcess process)
  {
    if(processes.get(new Integer(process.getPid())) != null)
      throw new ArrayIndexOutOfBoundsException("process replacement not allowed: " +
				      process.getPid() + " = " + process.toString());
    processes.put(new Integer(process.getPid()), process);
  }

  //}
  //{ public DebugProcess getProcess(int pid)

  /**
   * Retrieve a process given its process id
   */

  public DebugProcess getProcess(int pid)
  {
    return (DebugProcess)processes.get(new Integer(pid));
  }

  //}
  //{ public void removeProcess(int pid)

  /**
   * Remove a process given its process id.
   */

  public void removeProcess(int pid)
  {
    processes.remove(new Integer(pid));
  }

  //}
}
