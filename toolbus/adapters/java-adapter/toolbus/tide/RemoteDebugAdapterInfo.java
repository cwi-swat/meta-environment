package toolbus.tide;
import java.util.*;
import toolbus.aterm.*;
import toolbus.tool.*;

/**
  * The class RemoteDebugAdapterInfo keeps track of the current state
  * of a remote debug adapter.
  */

public class RemoteDebugAdapterInfo extends DebugAdapterInfo
{
  // The ToolBus tool that holds the ToolBus connection
  Tool tool;

  // Process groups
  Vector groups;

  // Some useful patterns
  ATermPattern patternExecActions;
  ATermPattern patternCreateRule;
  ATermPattern patternAskWatchpointVar;
  ATermPattern patternAskWatchpointExpr;

  //{ public RemoteDebugAdapterInfo(ATerm dap, ATerms inf, Tool tool)

  /**
    * Construct a new RemoteDebugAdapterInfo object.
    */

  public RemoteDebugAdapterInfo(ATerm dap, ATerms inf, Tool tool)
  {
    super(dap, inf);
    this.tool = tool;
    init();
  }

  //}
  //{ public RemoteDebugAdapterInfo(int ident, ATerms inf, Tool tool)

  /**
    * Construct a new RemoteDebugAdapterInfo object.
    */

  public RemoteDebugAdapterInfo(int ident, ATerms inf, Tool tool)
  {
    super(ident, inf);
    this.tool = tool;
    init();
  }

  //}
  //{ private void init()

  /**
    * Initialize the term patterns.
    */

  private void init()
  {
    try {
      patternExecActions = 
	new ATermPattern("exec-actions(debug-adapter(<int>),<term>,<term>)");
      patternCreateRule = new ATermPattern("create-rule(<str>," +
		   "debug-adapter(<int>),<term>,<term>,<term>,<term>,<term>)");
      patternAskWatchpointVar = 
	new ATermPattern("ask-watchpoint(debug-adapter(<int>),<term>,<term>,var)");
      patternAskWatchpointExpr = 
	new ATermPattern("ask-watchpoint(debug-adapter(<int>),<term>,<term>,expr)");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
    groups = new Vector();
    groups.addElement(DebugProcessGroup.newGroupAll(this));
    groups.addElement(DebugProcessGroup.newGroupNone(this));
  }

  //}

  //{ public void sendExecuteActions(ATerm procs, ATerm actions)

  /**
    * Send a list of actions to the remote debug adapter for execution.
    */

  public void sendExecuteActions(ATerm procs, ATerm actions)
  {
    System.out.println("sendExecuteActions: " + actions + " to:" + procs);
    try {
      tool.post((ATermAppl)patternExecActions.make(new Integer(getId()), 
						      procs, actions));
    } catch (ToolException e) {
      System.err.println("ToolBus connection failure, giving up!");
      System.exit(1);
    }
  }

  //}
  //{ public void sendCreateRule(String type, ATerm procs, DebugPort port,

  /**
    * Send a create-rule request.
    */

  public void sendCreateRule(String type, ATerm procs, DebugPort port, 
			     ATerm cond, ATerm acts, int lifetime)
  {
    try {
      ATerm term = patternCreateRule.make(type, new Integer(getId()), 
					  procs, port.onthewire(),cond,acts, 
					  DebugRule.lifeInt2Term(lifetime));
      System.out.println("send create rule " + term.toString());
      tool.post((ATermAppl)term);
    } catch (ToolException e) {
      System.err.println("ToolBus connection failure, giving up!");
      System.exit(1);
    }
    
  }

  //}
  //{ public void askWatchpoint(ATerm procs, DebugPort port)

  /**
   * Send a message to the watchpoint viewer in order to create a watchpoint.
   */

  public void askWatchpoint(ATerm procs, DebugPort port, boolean var)
  {
    try {
      ATerm term;
      if(var)
	term = patternAskWatchpointVar.make(new Integer(getId()),
					    procs, port.onthewire());
      else
	term = patternAskWatchpointExpr.make(new Integer(getId()),
					     procs, port.onthewire());
      tool.post((ATermAppl)term);
    } catch (ToolException e) {
      System.err.println("ToolBus connection failure, giving up!");
      System.exit(1);
    }
  }

  //}

  //{ public Enumeration getGroups()

  /**
   * Get all the process groups of this adapter.
   */

  public Enumeration getGroups()
  {
    return groups.elements();
  }

  //}
}

