package toolbus.tide;
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

  // Some useful patterns
  ATermPattern patternExecActions;
  ATermPattern patternCreateRule;

  //{ public RemoteDebugAdapterInfo(ATermRef dap, ATermsRef inf, Tool tool)

  /**
    * Construct a new RemoteDebugAdapterInfo object.
    */

  public RemoteDebugAdapterInfo(ATermRef dap, ATermsRef inf, Tool tool)
  {
    super(dap, inf);
    this.tool = tool;
    init();
  }

  //}
  //{ public RemoteDebugAdapterInfo(int ident, ATermsRef inf, Tool tool)

  /**
    * Construct a new RemoteDebugAdapterInfo object.
    */

  public RemoteDebugAdapterInfo(int ident, ATermsRef inf, Tool tool)
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
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
  }

  //}

  //{ public void sendExecuteActions(ATermRef procs, ATermRef actions)

  /**
    * Send a list of actions to the remote debug adapter for execution.
    */

  public void sendExecuteActions(ATermRef procs, ATermRef actions)
  {
    try {
      System.out.println("send actions " + actions.toString() + " to " + procs.toString());
      tool.post((ATermApplRef)patternExecActions.make(new Integer(getId()), 
						      procs, actions));
    } catch (ToolException e) {
      System.err.println("ToolBus connection failure, giving up!");
      System.exit(1);
    }
  }

  //}
  //{ public void sendCreateRule(String type, ATermRef procs, DebugPort port,

  /**
    * Send a create-rule request.
    */

  public void sendCreateRule(String type, ATermRef procs, DebugPort port, 
			     ATermRef cond, ATermRef acts, int lifetime)
  {
  }

  //}
}
