
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

  void watchpoint(ATermApplRef a0, ATermRef t1, int i2, ATermRef t3)
  {
  }

  void dapConnected(ATermApplRef a0, ATermListRef l1, ATermRef t2)
  {
  }

  void listProcesses(ATermApplRef a0)
  {
  }

  void recTerminate(ATermRef t0)
  {
  }
}
