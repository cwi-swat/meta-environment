
package toolbus.tide;
import java.util.*;
import toolbus.aterm.*;

//{ abstract public class DebugProcessGroup

abstract public class DebugProcessGroup
{
  protected static final int NONE = 0;
  protected static final int SINGLE = 1;
  protected static final int ALL = 2;
  protected static final int LIST = 3;

  private static int anonGroupCount = 0;
  private static ATermPattern patternNone = null;
  private static ATermPattern patternOne = null;
  private static ATermPattern patternAll = null;
  private static ATermPattern patternList = null;

  protected RemoteDebugAdapterInfo dap;
  private int type;

  //{ static public DebugProcessGroup newGroup(dap, ATerm procs)

  /**
   * Create a new debug process group given a term process spec.
   */

  static public DebugProcessGroup newGroup(RemoteDebugAdapterInfo dap, ATerm procs)
  {
    if(patternNone == null) {
      try {
	patternNone = new ATermPattern("[]");
	patternOne = new ATermPattern("[<int>]");
	patternAll = new ATermPattern("all");
	patternList = new ATermPattern("<list>");
      } catch (ParseError e) {
	throw new IllegalArgumentException("internal parse error");
      }
    }
    if(patternNone.match(procs))
      return new DebugProcessGroupNone(dap);
    if(patternOne.match(procs))
      return new DebugProcessGroupOne(dap, ((Integer)patternOne.elementAt(0)).intValue());
    if(patternAll.match(procs))
      return new DebugProcessGroupAll(dap);
    if(patternList.match(procs)) {
      String name = "anon-" + anonGroupCount++;
      return new DebugProcessGroupList(dap, name, 
	     ((ATermList)patternList.elementAt(0)).getATerms());
    }
    throw new IllegalArgumentException("illegal process spec: " + procs);
  }

  //}
  //{ static public DebugProcessGroup newGroupAll(dap)

  /**
   * Create a new process group representing all processes in a adapter.
   */

  static public DebugProcessGroup newGroupAll(RemoteDebugAdapterInfo dap)
  {
    return new DebugProcessGroupAll(dap);
  }

  //}
  //{ static public DebugProcessGroup newGroupNone(dap)

  /**
   * Create a new process group representing the empty process group.
   */

  static public DebugProcessGroup newGroupNone(RemoteDebugAdapterInfo dap)
  {
    return new DebugProcessGroupNone(dap);
  }

  //}
  //{ static public DebugProcessGroup newGroupOne(dap, int pid)

  /**
   * Create a new process group representing a single process.
   */

  static public DebugProcessGroup newGroupOne(RemoteDebugAdapterInfo dap, int pid)
  {
    return new DebugProcessGroupOne(dap, pid);
  }

  //}
  //{ static public DebugProcessGroup newGroupList(dap, ATerms procs)

  /**
   * Create a new process group representing a single process.
   */

  static public DebugProcessGroup newGroupList(RemoteDebugAdapterInfo dap, 
					       String name, ATerms procs)
  {
    return new DebugProcessGroupList(dap, name, procs);
  }

  //}

  public DebugProcessGroup(RemoteDebugAdapterInfo dap, int type) {
    this.dap = dap;
    this.type = type;
  }

  abstract String getName();
  abstract boolean contains(int pid);
}

//}

//{ class DebugProcessGroupAll extends DebugProcessGroup

class DebugProcessGroupAll extends DebugProcessGroup
{
  public DebugProcessGroupAll(RemoteDebugAdapterInfo dap)
  {
    super(dap, ALL);
  }

  public String getName() {
    return "all";
  }

  public boolean contains(int pid) {
    return true;
  }
}

//}
//{ class DebugProcessGroupNone extends DebugProcessGroup

class DebugProcessGroupNone extends DebugProcessGroup
{
  public DebugProcessGroupNone(RemoteDebugAdapterInfo dap)
  {
    super(dap, NONE);
  }
  public String getName()
  {
    return "none";
  }
  public boolean contains(int pid) {
    return false;
  }
}

//}
//{ class DebugProcessGroupOne extends DebugProcessGroup

class DebugProcessGroupOne extends DebugProcessGroup
{
  private int pid;

  public DebugProcessGroupOne(RemoteDebugAdapterInfo dap, int pid)
  {
    super(dap, NONE);
    this.pid = pid;
  }
  public String getName()
  {
    return dap.getProcess(pid).toString();
  }
  public boolean contains(int pid) {
    if(this.pid == pid)
      return true;
    return false;
  }
}

//}
//{ class DebugProcessGroupList extends DebugProcessGroup

class DebugProcessGroupList extends DebugProcessGroup
{
  ATerms procs;
  String name;

  public DebugProcessGroupList(RemoteDebugAdapterInfo dap, String name, ATerms procs)
  {
    super(dap, NONE);
    this.procs = procs;
    this.name = name;
  }
  public String getName()
  {
    return name;
  }
  public boolean contains(int pid) {
    while(!procs.isEmpty()) {
      ATermInt proc = (ATermInt)procs.getFirst();
      if(proc.getInt() == pid)
	return true;
      procs = procs.getNext();
    }
    return false;
  }
}

//}


