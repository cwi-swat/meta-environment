
package toolbus.tide;
import toolbus.aterm.*;
import toolbus.tool.*;
import java.io.*;
import java.net.*;

public class ProcessViewerTool extends ProcessViewerTif
{
  private ProcessViewer viewer;

  //{ pattern variables

  private ATermPattern patternExecState;
  private ATermPattern patternWatchExecState;

  private ATermPattern patternWatchProcessCreation;
  private ATermPattern patternProcessCreation;
  private ATermPattern patternWatchProcessDestruction;
  private ATermPattern patternProcessDestruction;

  private ATermPattern patternWatchSend;
  private ATermPattern patternSend;
  private ATermPattern patternWatchReceive;
  private ATermPattern patternReceive;

  private ATermPattern patternSingleProcess;
  private ATermPattern patternString;

  //}

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
    viewer = new ProcessViewer(this);
    try {
      // Patterns used to track the execution state of processes
      patternWatchExecState = new ATermPattern("[watch(exec-state)]");
      patternExecState = new ATermPattern("exec-state");

      // Patterns used to track the creation/destruction of processes
      patternWatchProcessCreation = 
	new ATermPattern("[watch(process-creation(process-name,aliases))]");
      patternProcessCreation = 
	new ATermPattern("process-creation(<str>,<list>)");
      patternWatchProcessDestruction = 
	new ATermPattern("[watch(quote(process-destruction))]");
      patternProcessDestruction = new ATermPattern("process-destruction");

      // Patterns used to track the sending/receiving of messages
      patternWatchSend = new ATermPattern("[watch(send(msg,peer))]");
      patternSend = new ATermPattern("send(<term>,<term>)");
      patternWatchReceive = new ATermPattern("[watch(receive(msg,peer))]");
      patternReceive = new ATermPattern("receive(<term>,<term>)");

      // Miscellaneous patterns 
      patternSingleProcess = new ATermPattern("[<int>]");
      patternString = new ATermPattern("<str>");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
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
      //System.out.println("dapConnected: " + dap.toString());

      // First, we add the new adapter
      int dapid = DebugAdapterInfo.debugAdapterId(dap);
      viewer.addDebugAdapter(dapid, info.getATerms());

      // Then we add the new processes
      ATermsRef proclist = ((ATermListRef)procs).getATerms();
      ATermPattern patTriple = new ATermPattern("[<int>,<str>,<list>]");
      while(proclist != null) {
	ATermListRef triple = (ATermListRef)proclist.getFirst();
	proclist = proclist.getNext();
	if(!patTriple.match(triple))
	  throw new IllegalArgumentException("malformed process def: " + triple);
	int pid = ((Integer)patTriple.elementAt(0)).intValue();
	viewer.addProcess(dapid, pid, (String)patTriple.elementAt(1));
	ATermsRef aliases = ((ATermListRef)patTriple.elementAt(2)).getATerms();
	while(aliases != null) {
	  viewer.addAlias(dapid, pid, aliases.getFirst());
	  aliases = aliases.getNext();
	}
      }

      //{ From now on, we want to watch process creation/destruction 

      RemoteDebugAdapterInfo dp = viewer.getAdapter(dapid);
      dp.sendCreateRule("process-creation", new ATermApplRef("all", null),
			new ProcessCreationPort(),
			new ATermApplRef("always", null),
			patternWatchProcessCreation.make(),
			DebugRule.PERSISTENT);

      dp.sendCreateRule("process-destruction", new ATermApplRef("all", null),
			new ProcessDestructionPort(),
			new ATermApplRef("always", null),
			patternWatchProcessDestruction.make(),
			DebugRule.PERSISTENT);

      //}
      //{ And the exec state of its processes 

      dp.sendCreateRule("exec-state", new ATermApplRef("all", null),
			new ExecStatePort(DebugProcess.ES_ALL, DebugPort.WHEN_AT),
			new ATermApplRef("always", null), 
			patternWatchExecState.make(), DebugRule.PERSISTENT);

      //}
      //{ And the sending/receiving of messages 

      dp.sendCreateRule("send", new ATermApplRef("all", null),
			new SendPort(DebugPort.WHEN_AT, "<term>"),
			new ATermApplRef("always", null),
			patternWatchSend.make(),
			DebugRule.PERSISTENT);

      dp.sendCreateRule("receive", new ATermApplRef("all", null),
			new ReceivePort(DebugPort.WHEN_AT, "<term>"),
			new ATermApplRef("always", null),
			patternWatchReceive.make(),
			DebugRule.PERSISTENT);

      //}
    } catch (ParseError e) { 
      throw new IllegalArgumentException("internal parse error");
    }
  }

  //}
  //{ void dapDisconnected(ATermApplRef dap)

  /**
   * A debug adapter was disconnected. 
   */

  void dapDisconnected(ATermApplRef dap)
  {
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    viewer.removeAdapter(dapid);
  }

  //}
  //{ void watchpoint(ATermApplRef dp, ATermRef proc, int r, ATermRef exprs)

  /**
    * A watchpoint was triggered. This might indicate a change
    * in the list of processes.
    */

  void watchpoint(ATermApplRef dap, ATermRef proc, int rid, ATermRef exprs)
  {
    //System.out.println("watchpoint, proc=" + proc + ", exprs=" + exprs.toString());
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    ATermsRef exprlist = ((ATermListRef)exprs).getATerms();
    while(exprlist != null) {
      ATermsRef pair = ((ATermListRef)exprlist.getFirst()).getATerms();
      watchpoint(dapid, proc, pair.getFirst(), pair.getNext().getFirst());
      exprlist = exprlist.getNext();
    }
  }

  /**
    * Handle an individual watchpoint expression.
    */

  private void watchpoint(int dapid, ATermRef proc, ATermRef expr, ATermRef val)
  {
    System.out.println("### watchpoint: " + expr + ", val=" + val);

    if(!patternSingleProcess.match(proc))
      throw new IllegalArgumentException("illegal process spec: " + proc.toString());
    int pid = ((Integer)patternSingleProcess.elementAt(0)).intValue();

    //{ execution state

    if(patternExecState.match(expr)) {
      int es = DebugProcess.execStateTerm2Int(val);
      viewer.execStateChanged(dapid, pid, es);
      return;
    }

    //}
    //{ receive

    if(patternReceive.match(val)) {
      ATermRef msg = (ATermRef)patternReceive.elementAt(0);
      ATermRef from = (ATermRef)patternReceive.elementAt(1);
      viewer.receive(dapid, pid, from, msg);
      return;
    }

    //}
    //{ send

    if(patternSend.match(val)) {
      ATermRef msg = (ATermRef)patternSend.elementAt(0);
      ATermRef to = (ATermRef)patternSend.elementAt(1);
      viewer.send(dapid, pid, to, msg);
      return;
    }

    //}
    //{ process creation

    if(patternProcessCreation.match(val)) {
      String name;
      ATermsRef aliases;

      name = (String)patternProcessCreation.elementAt(0);
      aliases = ((ATermListRef)patternProcessCreation.elementAt(1)).getATerms();
      viewer.addProcess(dapid, pid, name);

      while(aliases != null) {
	viewer.addAlias(dapid, pid, aliases.getFirst());
	aliases = aliases.getNext();
      }
      
      return;
    }

    //}
    //{ process destruction

    if(patternProcessDestruction.match(val)) {
      viewer.processDestroyed(dapid, pid);
      return;
    }

    //}

    System.err.println("PV: unknown watchpoint - " + expr + " = " + val);
  }

  //}
  //{ void connected(ATermRef callsign)

  /**
   * Connection with an external process was established.
   */

  void connected(ATermRef callsign)
  {
    viewer.addProcess(callsign);
  }

  //}
  //{ void disconnected(ATermRef callsign)

  /**
   * Connection with an external process was destroyed.
   */

  void disconnected(ATermRef callsign)
  {
    System.out.println("disconnected: " + callsign);
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
  //{ void newTool(String name, ATermRef tool, ATermRef event)

  /**
    * A new tool has registered. we need to add it to the Tool menu.
    */

  void newTool(String name, ATermRef tool, ATermListRef tools)
  {
    int argFlags = 0;

    ATermPattern pat = null;
    try {
      pat = new ATermPattern("[<str>,<fun>]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }

    ATermsRef toollist = tools.getATerms();
    while(toollist != null) {
      ATermRef pair = toollist.getFirst();
      if(!pat.match(pair))
	throw new IllegalArgumentException("illegal tool def: " + pair);
      viewer.addToolCmd(name, tool,
			 (String)pat.elementAt(0), (String)pat.elementAt(1));
      toollist = toollist.getNext();
    }
  }

  //}
  //{ void recAckEvent(ATermRef event)

  /**
    * Handle event acknowledgements.
    */

  void recAckEvent(ATermRef event)
  {
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
