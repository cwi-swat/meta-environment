
package toolbus.tide;
import toolbus.aterm.*;
import toolbus.tool.*;
import java.io.*;
import java.net.*;

public class ProcessViewerTool extends ProcessViewerTif
{
  private ProcessViewer viewer;

  //{ public static void main(String[] args)

  /**
   * Start the process-viewer tool and find the ToolBus.
   */

  public static void main(String[] args)
       throws UnknownHostException, IOException, ToolException
  {
    ProcessViewerTool tool = new ProcessViewerTool(args);
    tool.connect();
    tool.run();
  }

  //}

  //{ public ProcessViewerTool(String[] args)

  /**
   * Construct a new ProcessViewerTool object.
   */

  public ProcessViewerTool(String[] args)
    throws UnknownHostException
  {
    super(args);
    viewer = new ProcessViewer();
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
    System.out.println("watchpoint, proc=" + proc + ", exprs=" + exprs.toString());
  }

  //}
  //{ void dapConnected(ATermApplRef dap, ATermListRef info, ATermRef procs)

  /**
    * A new dap has connected to the debugger.
    */

  /* We try to abstract as early as possible from the ToolBus
     ATerm... types. This allows us to work at a higher abstraction
     level in the other classes.
     */

  void dapConnected(ATermApplRef dap, ATermListRef info, ATermRef procs)
  {
    try {
      System.out.println("dapConnected: " + dap.toString());

      // First, we add the new adapter
      int dapid = DebugAdapterInfo.debugAdapterId(dap);
      viewer.addDebugAdapter(dapid, info.getATerms());

      // Then we add the new processes
      ATermsRef proclist = ((ATermListRef)procs).getATerms();
      ATermPattern patPair = new ATermPattern("[<int>,<str>]");
      while(proclist != null) {
	ATermListRef pair = (ATermListRef)proclist.getFirst();
	proclist = proclist.getNext();
	if(!patPair.match(pair))
	  throw new IllegalArgumentException("malformed process def: " + pair.toString());
	
	viewer.addProcess(dapid, ((Integer)patPair.elementAt(0)).intValue(),
			  (String)patPair.elementAt(1));
      }
    } catch (ParseError e) { 
      throw new IllegalArgumentException("internal parse error");
    }
  }

  //}

  //{ void viewProcesses(ATermApplRef dap)

  /**
    * View the process graph.
    */

  void viewProcesses(ATermApplRef dap)
  {
    viewer.toFront();
  }

  //}

  //{ void recTerminate(ATermRef arg)

  /**
    * A termination request has been received.
    */

  void recTerminate(ATermRef arg)
  {
    System.exit(0);
  }

  //}
}
