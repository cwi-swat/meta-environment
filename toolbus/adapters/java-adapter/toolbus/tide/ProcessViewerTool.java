
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
      patternWatchExecState = world.makePattern("[watch(exec-state)]");
      patternExecState = world.makePattern("exec-state");

      // Patterns used to track the creation/destruction of processes
      patternWatchProcessCreation = 
	world.makePattern("[watch(process-creation(process-name,aliases))]");
      patternProcessCreation = 
	world.makePattern("process-creation(<str>,<list>)");
      patternWatchProcessDestruction = 
	world.makePattern("[watch(quote(process-destruction))]");
      patternProcessDestruction = world.makePattern("process-destruction");

      // Patterns used to track the sending/receiving of messages
      patternWatchSend = world.makePattern("[watch(send(msg,peer))]");
      patternSend = world.makePattern("send(<term>,<term>)");
      patternWatchReceive = world.makePattern("[watch(receive(msg,peer))]");
      patternReceive = world.makePattern("receive(<term>,<term>)");

      // Miscellaneous patterns 
      patternSingleProcess = world.makePattern("[<int>]");
      patternString = world.makePattern("<str>");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
  }

  //}
  //{ void dapConnected(ATermAppl dap, ATermList info, ATerm procs)

  /**
    * A new dap has connected to the debugger.
    */

  /* We try to abstract as early as possible from the ToolBus
     ATerm... types. This allows us to work at a higher abstraction
     level in the other classes.
     */

  void dapConnected(ATermAppl dap, ATermList info, ATerm procs)
  {
    try {
      //System.out.println("dapConnected: " + dap.toString());

      // First, we add the new adapter
      int dapid = DebugAdapterInfo.debugAdapterId(dap);
      viewer.addDebugAdapter(dapid, info.getATerms());

      // Then we add the new processes
      ATerms proclist = ((ATermList)procs).getATerms();
      ATermPattern patTriple = world.makePattern("[<int>,<str>,<list>]");
      while(!proclist.isEmpty()) {
	ATermList triple = (ATermList)proclist.getFirst();
	proclist = proclist.getNext();
	if(!patTriple.match(triple))
	  throw new IllegalArgumentException("malformed process def: " + triple);
	int pid = ((Integer)patTriple.elementAt(0)).intValue();
	viewer.addProcess(dapid, pid, (String)patTriple.elementAt(1));
	ATerms aliases = ((ATermList)patTriple.elementAt(2)).getATerms();
	while(!aliases.isEmpty()) {
	  viewer.addAlias(dapid, pid, aliases.getFirst());
	  aliases = aliases.getNext();
	}
      }

      //{ From now on, we want to watch process creation/destruction 

      RemoteDebugAdapterInfo dp = viewer.getAdapter(dapid);
      dp.sendCreateRule("process-creation", world.makeAppl("all"),
			new ProcessCreationPort(),
			world.makeAppl("always"),
			patternWatchProcessCreation.make(),
			DebugRule.PERSISTENT);

      dp.sendCreateRule("process-destruction", world.makeAppl("all"),
			new ProcessDestructionPort(),
			world.makeAppl("always"),
			patternWatchProcessDestruction.make(),
			DebugRule.PERSISTENT);

      //}
      //{ And the exec state of its processes 

      dp.sendCreateRule("exec-state", world.makeAppl("all"),
			new ExecStatePort(DebugProcess.ES_ALL, DebugPort.WHEN_AT),
			world.makeAppl("always"), 
			patternWatchExecState.make(), DebugRule.PERSISTENT);

      //}
      //{ And the sending/receiving of messages 

      dp.sendCreateRule("send", world.makeAppl("all"),
			new SendPort(DebugPort.WHEN_AT, "<term>"),
			world.makeAppl("always"),
			patternWatchSend.make(),
			DebugRule.PERSISTENT);

      dp.sendCreateRule("receive", world.makeAppl("all"),
			new ReceivePort(DebugPort.WHEN_AT, "<term>"),
		        world.makeAppl("always"),
			patternWatchReceive.make(),
			DebugRule.PERSISTENT);

      //}
    } catch (ParseError e) { 
      throw new IllegalArgumentException("internal parse error");
    }
  }

  //}
  //{ void dapDisconnected(ATermAppl dap)

  /**
   * A debug adapter was disconnected. 
   */

  void dapDisconnected(ATermAppl dap)
  {
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    viewer.removeAdapter(dapid);
  }

  //}
  //{ void watchpoint(ATermAppl dp, ATerm proc, int r, ATerm exprs)

  /**
    * A watchpoint was triggered. This might indicate a change
    * in the list of processes.
    */

  void watchpoint(ATermAppl dap, ATerm proc, int rid, ATerm exprs)
  {
    //System.out.println("watchpoint, proc=" + proc + ", exprs=" + exprs.toString());
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    ATerms exprlist = ((ATermList)exprs).getATerms();
    while(!exprlist.isEmpty()) {
      ATerms pair = ((ATermList)exprlist.getFirst()).getATerms();
      watchpoint(dapid, proc, pair.getFirst(), pair.getNext().getFirst());
      exprlist = exprlist.getNext();
    }
  }

  /**
    * Handle an individual watchpoint expression.
    */

  private void watchpoint(int dapid, ATerm proc, ATerm expr, ATerm val)
  {
    //System.out.println("### watchpoint: " + expr + ", val=" + val);

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
      ATerm msg = (ATerm)patternReceive.elementAt(0);
      ATerm from = (ATerm)patternReceive.elementAt(1);
      viewer.receive(dapid, pid, from, msg);
      return;
    }

    //}
    //{ send

    if(patternSend.match(val)) {
      ATerm msg = (ATerm)patternSend.elementAt(0);
      ATerm to = (ATerm)patternSend.elementAt(1);
      viewer.send(dapid, pid, to, msg);
      return;
    }

    //}
    //{ process creation

    if(patternProcessCreation.match(val)) {
      String name;
      ATerms aliases;

      name = (String)patternProcessCreation.elementAt(0);
      aliases = ((ATermList)patternProcessCreation.elementAt(1)).getATerms();
      viewer.addProcess(dapid, pid, name);

      while(!aliases.isEmpty()) {
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
  //{ void connected(ATerm callsign)

  /**
   * Connection with an external process was established.
   */

  void connected(ATerm callsign)
  {
    viewer.addProcess(callsign);
  }

  //}
  //{ void disconnected(ATerm callsign)

  /**
   * Connection with an external process was destroyed.
   */

  void disconnected(ATerm callsign)
  {
    System.out.println("disconnected: " + callsign);
  }

  //}
  //{ void viewProcesses(ATermAppl dap)

  /**
    * View the process graph.
    */

  void viewProcesses(ATermAppl dap)
  {
    viewer.toFront();
  }

  //}
  //{ void newTool(String name, ATerm tool, ATerm event)

  /**
    * A new tool has registered. we need to add it to the Tool menu.
    */

  void newTool(String name, ATerm tool, ATermList tools)
  {
    int argFlags = 0;

    ATermPattern pat = null;
    try {
      pat = ATerm.the_world.makePattern("[<str>,<fun>]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }

    ATerms toollist = tools.getATerms();
    while(!toollist.isEmpty()) {
      ATerm pair = toollist.getFirst();
      if(!pat.match(pair))
	throw new IllegalArgumentException("illegal tool def: " + pair);
      viewer.addToolCmd(name, tool,
			 (String)pat.elementAt(0), (String)pat.elementAt(1));
      toollist = toollist.getNext();
    }
  }

  //}
  //{ void recAckEvent(ATerm event)

  /**
    * Handle event acknowledgements.
    */

  void recAckEvent(ATerm event)
  {
  }

  //}
  //{ void recTerminate(ATerm arg)

  /**
    * A termination request has been received.
    */

  void recTerminate(ATerm arg)
  {
    System.exit(0);
  }

  //}
}
