
package toolbus.tide;
import toolbus.aterm.*;
import java.util.*;

/**
 * The class DebugAdapterInfo keeps track of the current state
 * of a debug adapter.
 */

public class DebugAdapterInfo
{
  static protected int MAX_RULES = 256;

  int id;
  Vector[] ports;
  DebugRule[] rules;
  Hashtable processes;
  Hashtable info;

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
    // Enter the information in the info hashtable
    try {
      info = new Hashtable();
      ATermPattern patPair = new ATermPattern("[<appl>,<term>]");
      while(inf != null) {
	if(!patPair.match(inf.getFirst()))
	  throw new IllegalArgumentException("malformed information list: " 
					     + inf.getFirst().toString());
	String cat = ((ATermApplRef)patPair.elementAt(0)).getFun();
	ATermRef val  = (ATermRef)patPair.elementAt(1);
	System.out.println(cat + ": " + val.toString());
	info.put(cat, val);
	inf = inf.getNext();
      }
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }

    id = ident;

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
  //{ public DebugAdapterInfo(ATermRef dap, ATermsRef inf)

  /**
   * Construct a new DebugAdapterInfo object given the term
   * representation of its id and information list.
   */

  public DebugAdapterInfo(ATermRef dap, ATermsRef inf)
  {
    this(debugAdapterId(dap), inf);
  }

  //}

  //{ DebugProcess[] getProcessArray(ATermRef procs)

  /**
    * Build an array of processes consisting of the process-id's
    * found in procs.
    */

  DebugProcess[] getProcessArray(ATermRef procs)
  {
    DebugProcess[] result;

    switch(procs.getType()) {
      case ATerm.APPL:
	// must be 'all'
	result = null;
	//result = new DebugProcess[processes.size()];
	//Enumeration e = processes.elements();
	//for(int i=0; e.hasMoreElements(); i++)
	//result[i] = (DebugProcess)e.nextElement();
	break;

      case ATerm.LIST:
	// A list of process-ids
	ATermsRef cur = ((ATermListRef)procs).getATerms();
	result = new DebugProcess[cur.length()];
	try {
	  ATermPattern pat = new ATermPattern("<int>");
	  for(int i=0; cur != null; i++) {
	    pat.match(cur.getFirst());
	    result[i] = (DebugProcess)processes.get(pat.elementAt(0));
	    cur = cur.getNext();
	  }
	  break;
	} catch (ParseError except) {
	  System.err.println("internal parse error in getProcessArray");
	  System.exit(1);
	}

      default: throw new IllegalArgumentException("illegal process list: " +
						  procs.toString());
    }
    return result;
  }

  //}
  //{ public int getId()

  /**
   * Retrieve the id of this adapter. The id is an integer that uniquely
   * identifies a debug adapter.
   */

  public int getId()
  {
    return id;
  }

  //}

  //{ public ATermRef getInfo(String category)

  /**
   * Retrieve information about a specific category.
   */

  public ATermRef getInfo(String category)
  {
    return (ATermRef)info.get(category);
  }

  //}
  //{ public String getName()

  /**
   * Get the name of this debug-adapter. The name can be
   * found in the information table.
   */

  public String getName()
  {
    ATermApplRef name = (ATermApplRef)info.get("name");
    return name.getFun();
  }

  //}
  //{ public String getType()

  /**
   * Get the name of this debug-adapter. The name can be
   * found in the information table.
   */

  public String getType()
  {
    ATermApplRef type = (ATermApplRef)info.get("type");
    return type.getFun();
  }

  //}
  //{ public Enumeration getSourcePaths()

  /**
    * Get source search paths of this adapter.
    */

  public Enumeration getSourcePaths()
  {
    Vector vector = new Vector();
    ATermsRef paths = ((ATermListRef)getInfo("search-paths")).getATerms();
    while(paths != null) {
      ATermsRef pair = ((ATermListRef)paths.getFirst()).getATerms();
      ATermApplRef kind = (ATermApplRef)pair.getFirst();
      if(kind.getFun().equals("source")) {
	paths = ((ATermListRef)pair.getNext().getFirst()).getATerms();
	while(paths != null) {
	  ATermApplRef path = (ATermApplRef)paths.getFirst();
	  vector.addElement(path.getFun());
	  paths = paths.getNext();
	}
	return vector.elements();
      }
      paths = paths.getNext();
    }
    // Return an empty enumeration.
    return vector.elements();
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
  //{ public Enumeration getProcesses()

  /**
    * Return the list of all processes.
    */

  public Enumeration getProcesses()
  {
    return processes.elements();
  }

  //}
}

