/**
 * @author paulk
 */

package toolbus;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.InetAddress;
import java.nio.channels.Selector;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Random;
import java.util.Vector;

import toolbus.parser.ExternalParser;
import toolbus.parser.TScriptParser;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessDefinition;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermInt;
import aterm.ATermList;

/**
 * ToolBus implements the behaviour of one ToolBus.
 */

public class ToolBus {

	private static final boolean verbose = false;

	private static Random rand = new Random();
	
	private TBTermFactory tbfactory;
	
	private IOManager iomanager;

	private LinkedList<ProcessInstance> processes; // process instances
	
	private ListIterator<ProcessInstance> processesIterator; // process instances

	private Vector<ToolInstance> tools; // tool instances
	
	private Iterator<ToolInstance> toolsIterator;

	private HashMap<String,ProcessDefinition> procdefs;

	private HashMap<String,ToolDefinition> tooldefs;

	private HashSet<ATerm> atomSignature; // signature of all atoms in executing processes

	// TODO: should this not be for ALL defined processes? 
	private TScriptParser parser;

	private PrintWriter out;

	private static int nerrrors = 0;

	private static int nwarnings = 0;

	private LinkedList<ToolInstance> connectedTools;
	
	private long startTime;

	private long currentTime;

	private long nextTime = 0;

	private boolean shutdownDone = false;

	private boolean toolActionCompleted = false;

	/**
	 * Constructor with explicit PrintWriter
	 */

	public ToolBus(PrintWriter out) {
		tbfactory = new TBTermFactory();
		this.out = out;
		processes = new LinkedList<ProcessInstance>();
		processesIterator = null;
		tools = new Vector<ToolInstance>();
		toolsIterator = null;
		connectedTools = new LinkedList<ToolInstance>();
		procdefs = new HashMap<String,ProcessDefinition>();
		tooldefs = new HashMap<String,ToolDefinition>();
		atomSignature = new HashSet<ATerm>();
		
		PropertyManager.loadProperties();
		
		parser = new TScriptParser(
					new ExternalParser(
							get("sglr.path"), 
							get("parsetable.path"), 
							get("implodePT.path")), 
					this);
		iomanager = new IOManager(this);
		startTime = System.currentTimeMillis();
	}

	/**
	 * Constructor with implicit PrintWriter
	 */

	public ToolBus() {
		this(new PrintWriter(System.out));
	}

	/**
	 * Constructor with explicit StringWriter
	 */

	public ToolBus(StringWriter out) {
		this(new PrintWriter(out));
	}

	void info(String msg) {
		if (verbose) {
			System.err.println("[TOOLBUS] "
					+ msg.substring(0, Math.min(msg.length(), 100)));
		}
	}
	
	public String get(String p){
		String r = PropertyManager.get(p);
		System.err.println("get(" + p + ") => " + r);
		return r;
	}
	
	public String get(String p, String def){
		String r = PropertyManager.get(p,def);
		System.err.println("get(" + p + ", " + def + ") => " + r);
		return r;
	}

	
	public void wakeup(){
		iomanager.wakeup();
	}

	
	synchronized public void addConnectedTool(ToolInstance ti){
		connectedTools.addLast(ti);
	}

	synchronized public ToolInstance getConnectedTool(String toolname) {
	    info("getConnectedTool: " + toolname + " length = " + connectedTools.size());
	    ListIterator<ToolInstance> cti = connectedTools.listIterator();
		while(cti.hasNext()){
			ToolInstance ti = cti.next();
			 info("getConnectedTool: considering: " + ti.getToolName() + "; " + ti.getToolId());
			if (ti.getToolName().equals(toolname)) {
				cti.remove();
				info("getConnectedTool: " + toolname + " ==> " + ti);
				return ti;
			}
		}
		info("getConnectedTool: " + toolname + " ==> null");
		return null;
	}
	
	synchronized public ToolInstance getConnectedToolById(String toolname, ATerm tid) {
	    info("getConnectedToolById: " + toolname + ", tid = " + tid + " length = " + connectedTools.size());
	    ListIterator<ToolInstance> cti = connectedTools.listIterator();
		while(cti.hasNext()){
			ToolInstance ti = cti.next();
			 info("getConnectedTool: considering: " + ti.getToolName() + "; " + ti.getToolId());
			if (ti.getToolName().equals(toolname) && ti.getToolId() == tid) {
				cti.remove();
				info("getConnectedToolById: " + toolname + " ==> " + ti + "(" + ti.getToolId() + ")");
				return ti;
			}
		}
		info("getConnectedToolById: " + toolname + " ==> null");
		return null;
	}

	/**
	 * 
	 * Networking functions
	 */

	static String getHostName() {
		String hostname = "";
		try {
			hostname = java.net.InetAddress.getLocalHost().getHostName();
			int dotPosition = hostname.indexOf('.');
			if (dotPosition != -1) {
				hostname = hostname.substring(0, dotPosition);
			}
		} catch (java.net.UnknownHostException e) {
			// ignore, unable to resolve hostname
		}
		return hostname;
	}

	public int getWellKnownSocketPort() {
		return iomanager.getWellKnownSocketPort();
	}

	public InetAddress getLocalHost() {
		return iomanager.getLocalHost();
	}

	public Selector getSelector() {
		return iomanager.getSelector();
	}

	/**
	 * Get the ATermFactory used.
	 */

	public TBTermFactory getTBTermFactory() {
		return tbfactory;
	}

	/**
	 *  Get the current vector of processes.
	 */

	public LinkedList<ProcessInstance> getProcesses() {
		return processes;
	}

	/**
	 * Get current PrintWriter.
	 */

	public PrintWriter getPrintWriter() {
		return out;
	}

	public static void error(String src, String msg) {
		System.err.println("ToolBus (" + src + "): " + msg);
		nerrrors++;
	}

	public static void warning(String src, String msg) {
		System.err.println("ToolBus (" + src + "): " + msg + " (warning)");
		nwarnings++;
	}

	/**
	 * Generate next random boolean.
	 */

	public static boolean nextBoolean() {
		return rand.nextBoolean();
	}

	public long getRunTime() {
		return System.currentTimeMillis() - startTime;
	}

	public void setNextTime(long next) {
		System.err.println("setNextTime: " + next);
		if (nextTime <= currentTime) {
			nextTime = next;
		} else if (next < nextTime) {
			nextTime = next;
		}
		System.err.println("setNextTime: set to " + next);
	}

	/**
	 * Parse a Tscript from file and add definitions to this ToolBus.
	 */

	public void parse(String filename) throws ToolBusException {
		parser.parse(filename);
	}

	/**
	 * Add a process definition.
	 */

	public void addProcessDefinition(ProcessDefinition PD)
			throws ToolBusException {
		String name = PD.getName();
		if(procdefs.containsKey(name)){
			throw new ToolBusException("duplicate definition of process " + name);
		}
		procdefs.put(name,PD);
	}

	/**
	 * Add a tool definition.
	 */

	public void addToolDefinition(ToolDefinition TD) throws ToolBusException {
		String name = TD.getName();
		if(tooldefs.containsKey(name)){
			throw new ToolBusException("duplicate definition of tool " + name);
		} else {
			tooldefs.put(name, TD);
			TD.setToolBus(this);
		}
	}

	/**
	 * Add a process (with actuals).
	 */

	synchronized public ProcessInstance addProcess(String name, ATermList actuals)
			throws ToolBusException {
		ProcessInstance P = new ProcessInstance(this, name, actuals, processes.size());
		if(processesIterator != null){
			processesIterator.add(P);
		} else {
		 processes.add(P);
		}
		return P;
	}

	/**
	 * Add a process (without actuals).
	 */

	synchronized public ProcessInstance addProcess(String name) throws ToolBusException {
		return addProcess(name, tbfactory.EmptyList);
	}

	/**
	 * Add a process (as ProcessCall); previous two will become obsolete.
	 */

	synchronized public ProcessInstance addProcess(ProcessCall call) throws ToolBusException {
		ProcessInstance P = new ProcessInstance(this, call, processes.size());
		processes.add(P);
		return P;
	}

	/** addToolInstance adds a new tool instance
	 * 
	 * @param toolName name of the tool
	 * @return the tool instance
	 * @throws ToolBusException
	 */

	synchronized public ToolInstance addToolInstance(String toolName) throws ToolBusException {
		ATermList sig = getSignature();
		//System.err.println("addToolInstance: " + toolName + ", " + sig);
		ToolDefinition TD = getToolDefinition(toolName);
		TD.setToolSignatures(sig);
		ToolInstance ti = new ToolInstance(TD, this, tools.size(), tbfactory);
		tools.addElement(ti);
		ti.executeTool();
		return ti;
	}

	synchronized public ToolInstance getToolInstance(ATerm tid) throws UnconnectedToolException {
		ATermInt arg = (ATermInt) ((ATermAppl) tid).getArgument(0);
		return getToolInstance(arg.getInt());
	}

	synchronized public ToolInstance getToolInstance(int n)throws UnconnectedToolException {
		if(n >= tools.size()){
			throw new UnconnectedToolException("tool: " + n);
		} else {
			return tools.elementAt(n);
		}
	}

    synchronized public void removeToolInstance(ToolInstance ti){
    	if(toolsIterator == null){
    		tools.remove(ti);
    	} else {
    		//TODO: this may generate orphan tool instances
    	}
    }

	/**
	 * Get a process definition by name.
	 */

	public ProcessDefinition getProcessDefinition(String name)
			throws ToolBusException {
		if(procdefs.containsKey(name)){
			return procdefs.get(name);
		} else {
			throw new ToolBusException("no definition for process " + name);
		}
	}

	/**
	 * Get a tool definition by name.
	 */

	public ToolDefinition getToolDefinition(String name)
			throws ToolBusException {
		//System.err.println("getToolDefinition: " + name);
		if(tooldefs.containsKey(name)){
			return tooldefs.get(name);
		}
		throw new ToolBusException("no definition for tool " + name);
	}

	public void addToSignature(ATerm asig) {
		try {
			ATerm pat = tbfactory.makePattern(asig,true);
			atomSignature.add(pat);
			//System.err.println("asig = " + asig);
			//System.err.println("pat  = " + pat);
		} catch (ToolBusException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private ATermList getSignature() {
		ATermList res = tbfactory.EmptyList;
		Iterator it = atomSignature.iterator();
		while (it.hasNext()) {
			res = tbfactory.makeList((ATerm) it.next(), res);
		}
		return res;
	}

	public void settoolActionCompleted() {
		toolActionCompleted = true;
	}

	/**
	 * Shutdown of this ToolBus.
	 */

	synchronized public void shutdown(ATerm msg) {

		for (ProcessInstance pi : processes) {
			pi.terminate(msg);
		}
		
		toolsIterator = tools.iterator();
		while(toolsIterator.hasNext()){
			ToolInstance ti = toolsIterator.next();
			ti.terminate(msg);
			toolsIterator.remove();
		}
		iomanager.closeConnections();
		System.err.println(msg);
		shutdownDone = true;
	}

	/**
	 * Execute all the processes in this ToolBus.
	 */

	public void execute() {
		int passes = 0;
		int noWorkPasses = 0;
		int toolinputPasses = 0;

		try {
			boolean work = true;
			while (true) {
				currentTime = getRunTime();
				while (work) {
					passes++;
					work = false;
					
					Collections.rotate(processes, 1);
					processesIterator = processes.listIterator();
			
					while(processesIterator.hasNext()){
						ProcessInstance P = processesIterator.next();
						work |= P.step();
						if (P.isTerminated()) {
							System.err.println(P.getProcessName() + " terminated, total = " + processes.size());
							processesIterator.remove();
						}
						if(shutdownDone){
							return;
						}
					}
					if (!work)
						noWorkPasses++;
					processesIterator = null;
				}

				if (passes % 100 == 0) {
					System.err.println("TOOLBUS.execute STATISTICS");
					System.err.println("# of passes over script: " + passes);
					System.err.println("# of no work passes over script: "
							+ noWorkPasses);
					System.err.println("# of tool input passes: "
							+ toolinputPasses);
				}

				if (processes.size() > 0) {
					long timeout = nextTime - currentTime;
					work = false;
					while(!work){
						work = toolActionCompleted = false;
						iomanager.handleInputFromTools(timeout > 0 ? timeout : 10000);
						work = toolActionCompleted || timeout > 0;
						toolinputPasses += 1;
					}
				} else {
					shutdown(tbfactory.make("ToolBus Halted"));
					return;
				}
			}
		} catch (ToolBusException e) {
			System.err.println("Exception in ToolBus.execute");
			System.err.println(e.getMessage());
			e.printStackTrace();
		}
		shutdown(tbfactory.make("ToolBus halted"));
	}
}
