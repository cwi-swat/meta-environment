
package toolbus.tide;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import toolbus.aterm.*;
import toolbus.tool.*;

public class WatchpointViewerTool extends WatchpointViewerTif
{
	private Hashtable viewerTable;
	private Hashtable adapterTable;

	//{ static public void main(String[] args)

	/**
	 * The 'main' method creates a watchpoint-viewer tool, connects
	 * it to the ToolBus, and runs it.
	 */

	static public void main(String[] args)
	throws java.io.IOException, java.net.UnknownHostException, ToolException
	{
		WatchpointViewerTool tool = new WatchpointViewerTool(args);
		tool.connect();
		tool.run();
	}

	//}
	//{ public WatchpointViewerTool(String[] args)

	/**
	 * Construct a new WatchpointViewerTool
	 */

	public WatchpointViewerTool(String[] args)
	throws java.net.UnknownHostException
	{
		super(args);
		viewerTable = new Hashtable();
		adapterTable = new Hashtable();
	}

	//}

	//{ void dapConnected(ATermAppl dap, ATermList info, ATerm procs)

	/**
	 * A debug-adapter has connected to the system. We need to
	 * maintain information about it (and its processes), so
	 * the user can open viewers on it.
	 */

	void dapConnected(ATermAppl dap, ATermList info, ATerm procs)
	{
		// No viewers yet for this adapter,
		// so add an empty vector in the viewerTable
		int dapid = DebugAdapterInfo.debugAdapterId(dap);
		viewerTable.put(new Integer(dapid), new Vector());

		// Create a new RemoteDebugAdapterInfo object,
		// and store it in the adapterTable
		RemoteDebugAdapterInfo dapInfo =
			new RemoteDebugAdapterInfo(dapid, info.getATerms(), this);
		adapterTable.put(new Integer(dapid), dapInfo);

		// The processes are stored in the RemoteDebugAdapterInfo object.
		ATerms proclist = ((ATermList)procs).getATerms();
		ATermPattern patTriple = null;

		try
		{
			patTriple = new ATermPattern("[<int>,<str>,<list>]");
		}
		catch (ParseError e)
		{
			throw new IllegalArgumentException("internal parse error");
		}

		while(!proclist.isEmpty())
		{
			ATermList triple = (ATermList)proclist.getFirst();
			proclist = proclist.getNext();
			if(!patTriple.match(triple))
				throw new IllegalArgumentException(
					"malformed process def: " + triple);
			int pid = ((Integer)patTriple.elementAt(0)).intValue();
			String name = (String)patTriple.elementAt(1);
			DebugProcess process = new DebugProcess(dapid, pid, name);
			dapInfo.addProcess(process);
		}
	}

	//}
	//{ void dapDisconnected(ATermAppl dap)

	/**
	 * Handle debug adapter disconnection.
	 */

	void dapDisconnected(ATermAppl dap)
	{
		int dapid = DebugAdapterInfo.debugAdapterId(dap);
		adapterTable.remove(new Integer(dapid));
	}

	//}

	//{ void ruleCreated(dap, proc, int rid, port, cond, acts, life)

	/**
	 * Handle rule creation.
	 */

	void ruleCreated(ATermAppl dap, ATerm proc, int rid, ATerm port, 
			 ATerm cond, ATerm acts, ATerm life)
	{
		Integer dapid = new Integer(DebugAdapterInfo.debugAdapterId(dap));
		RemoteDebugAdapterInfo dapInfo = 
			(RemoteDebugAdapterInfo) adapterTable.get(dapid);
		DebugProcess[] procs = dapInfo.getProcessArray(proc);
		DebugPort dbgport = DebugPort.newPort(port);
		int lifetime = DebugRule.lifeTerm2Int(life);
		DebugRule rule = new DebugRule(rid, procs, dbgport, cond,
					 ((ATermList)acts).getATerms(), lifetime);
		dapInfo.addRule(rule);
	}

	//}
	//{ void ruleModified(dap, proc, rid, port, cond, acts, life)

	/**
	 * Handle rule modification.
	 */

	void ruleModified(ATermAppl dap, ATerm proc, int rid, ATerm port,
				ATerm cond, ATerm acts, ATerm life)
	{
		Integer dapid = new Integer(DebugAdapterInfo.debugAdapterId(dap));
		RemoteDebugAdapterInfo dapInfo = 
			(RemoteDebugAdapterInfo)adapterTable.get(dapid);
		DebugProcess[] procs = dapInfo.getProcessArray(proc);
		DebugPort dbgport = DebugPort.newPort(port);
		int lifetime = DebugRule.lifeTerm2Int(life);
		DebugRule rule = new DebugRule(rid, procs, dbgport, cond,
					 ((ATermList)acts).getATerms(), lifetime);
		dapInfo.removeRule(rid);

		// Add the new break/watchpoint
		dapInfo.addRule(rule);
	}

	//}
	//{ void ruleDestroyed(ATermAppl dap, ATerm proc, int rid)

	/**
	 * Handle rule destruction.
	 */

	void ruleDestroyed(ATermAppl dap, ATerm proc, int rid)
	{
		Integer dapid = new Integer(DebugAdapterInfo.debugAdapterId(dap));
		RemoteDebugAdapterInfo dapInfo = 
			(RemoteDebugAdapterInfo)adapterTable.get(dapid);
		dapInfo.removeRule(rid);
	}

	//}
	//{ void watchpoint(ATermAppl dap, ATerm proc, int ATermList exprs)

	/**
	 * Handle watchpoint triggering.
	 */

	void watchpoint(ATermAppl dap, ATerm proc, int rid,
					ATermList exprs)
	{
		System.out.println("WATCHPOINT::"+exprs.toString());
	}

	//}

	//{ void recAckEvent(ATerm evt)

	/**
	 * Handle event acknowledgements.
	 */

	void recAckEvent(ATerm evt)
	{
		
	}

	//}	
	//{ void recTerminate(ATerm arg)

	/**
	 * Handle a termination request.
	 */

	void recTerminate(ATerm arg)
	{
		System.exit(0);
	}

	//}

	//{ void createWatchpoint(ATermAppl dap)

	/**
	 * The user wants to create a watchpoint.
	 */

	void createWatchpoint(ATermAppl dap)
	{
		System.out.println("Create watchpoint received!");
	}

	//}
	//{ void createWatchpoint(ATermAppl dap, ATerm procs)

	/**
	 * The user wants to create a watchpoint.
	 */

	void createWatchpoint(ATermAppl dap, ATerm procs)
	{
		try
		{
			createWatchpoint(dap, procs,
				ATermParser.makeSimple("[exec-state,at,stop]"));
		}
		catch (ParseError e)
		{
			throw new IllegalArgumentException("internal parse error");
		}
	}

	//}
	//{ void askWatchpoint(ATermAppl dap, ATerm procs, ATerm port, ATerm type)
	void askWatchpoint(ATermAppl dap, ATerm procs, ATerm port,
		ATerm type)
	{
	}

	//}
	//{ void createWatchpoint(ATermAppl dap, ATerm procs, ATerm port)

	/**
	 * The user wants to create a watchpoint.
	 */

	void createWatchpoint(ATermAppl dap, ATerm procs, ATerm port)
	{
		System.out.println("Create watchpoint received!");
		Integer dapid = new Integer(DebugAdapterInfo.debugAdapterId(dap));
		RemoteDebugAdapterInfo dapInfo = 
			(RemoteDebugAdapterInfo)adapterTable.get(dapid);
		DebugPort dbgport = DebugPort.newPort(port);
		//Dialog dialog = new WatchpointDialog(dapInfo, procs, dbgport);
		Dialog dialog = new WatchpointDialog(dapInfo, procs);
		dialog.show();
	}

	//}
}

/**
 * A WatchpointDialog asks the user which watchpoint he wants to create.
 * TB: exec-actions(Acts?)
 *
 *     dapInfo.sendCreateRule("cpe",
 *        patternSingleProcess.make(new Integer(pid)),
 *        new ExecStatePort(DebugProcess.ES_STOP, DebugPort.WHEN_AT),
 *        termTrue, termWatchCpe, DebugRule.PERSISTENT);
 */

class WatchpointDialog extends Dialog implements ActionListener
{
	private	Label			text_label;
	private	TextField		text_entry;
	private ATermPattern	patternSingleProcess;
	private ATermPattern	patternWatchVar;
	private	ATerm		termAlways;
	private	ATerm		procs;

	private RemoteDebugAdapterInfo dapInfo;

	public WatchpointDialog(RemoteDebugAdapterInfo dapInfo, ATerm procs)
	{
		super(new Frame(), "Watchpoint Dialog");

		this.procs = procs;
		this.dapInfo = dapInfo;

		try
		{
			patternSingleProcess = new ATermPattern("[<int>]");
			patternWatchVar = new ATermPattern("[watch(var(<str>))]");
			termAlways = ATermParser.makeSimple("always");
		}
		catch (ParseError e)
		{
			throw new IllegalArgumentException("internal parse error");
		}

		setLayout(new GridLayout(0, 2, 5, 5));

		text_label = new Label("Variable name", Label.RIGHT);
		text_label.setFont(new Font("Sans Serif", Font.BOLD, 12));
		add(text_label);

		text_entry = new TextField(10);
		text_entry.setFont(new Font("Sans Serif", Font.PLAIN, 12));
		text_entry.addActionListener(this);

		add(text_entry);

		pack();
		show();

		int pid = ((ATermInt)procs).getInt();
	}

	public void actionPerformed(ActionEvent e)
	{
		if (e.getSource().equals(text_entry))
		{
			int pid = ((ATermInt)procs).getInt();
			dapInfo.sendCreateRule(
				"var",
				patternSingleProcess.make(new Integer(pid)),
				new ExecStatePort(DebugProcess.ES_STOP, DebugPort.WHEN_AT),
				termAlways,
				patternWatchVar.make(text_entry.getText()),
				DebugRule.PERSISTENT);
		}
	}
}
