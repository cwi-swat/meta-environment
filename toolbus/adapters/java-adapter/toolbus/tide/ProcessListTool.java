
package toolbus.tide;
import toolbus.aterm.*;
import toolbus.tool.*;
import java.net.*;

class ProcessListTool extends ProcessListTif
{
  //{ public ProcessListTool(String[] args)

  /**
   * Construct a new ProcessListTool object.
   */

  public ProcessListTool(String[] args)
    throws UnknownHostException
  {
    super(args);
  }

  //}

  //{ void dapDisconnected(ATermApplRef dap)

  /**
   * A debug adapter was disconnected. 
   */

  void dapDisconnected(ATermApplRef dap)
  {
  }

  //}
  //{ void watchpoint(ATermApplRef dp, ATermRef proc, int r, ATermRef exprs)

  /**
    * A watchpoint was triggered. This might indicate a change
    * in the list of processes.
    */

  void watchpoint(ATermApplRef dap, ATermRef proc, int rid, ATermRef exprs)
  {
  }

  //}
  //{ void dapConnected(ATermApplRef dap, ATermListRef info, ATermRef procs)

  /**
    * A new dap has connected to the debugger.
    */

  void dapConnected(ATermApplRef dap, ATermListRef info, ATermRef procs)
  {
    System.out.println("dapConnected: " + dap.toString());
  }

  //}

  //{ void listProcesses(ATermApplRef dap)

  /**
    * List the processes of a certain debug adapter.
    */

  void listProcesses(ATermApplRef dap)
  {
  }

  //}

  //{ void recTerminate(ATermRef arg)

  /**
    * A termination request has been received.
    */

  void recTerminate(ATermRef arg)
  {
  }

  //}
}
