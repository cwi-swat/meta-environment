/**
 * @author paulk
 */

package toolbus;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.lang.management.ManagementFactory;
import java.lang.management.MemoryMXBean;
import java.lang.management.ThreadInfo;
import java.lang.management.ThreadMXBean;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;

import toolbus.atom.Atom;
import toolbus.commandline.CommandLine;
import toolbus.exceptions.NoSuchProcessDefinitionException;
import toolbus.exceptions.ToolBusError;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.matching.MatchStore;
import toolbus.parsercup.parser;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessDefinition;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.execution.DefaultToolExecutorFactory;
import toolbus.tool.execution.IToolExecutorFactory;
import toolbus.util.collections.ConcurrentHashMap;
import toolbus.util.collections.ConcurrentHashMap.ReadOnlyHashMapEntryHandler;
import aterm.ATerm;

/**
 * ToolBus implements the behaviour of one ToolBus.
 */
public class ToolBus{
	// The amount of time we wait for tools to terminate when the toolbus's shutdown sequence is
	// initiated.
	private final static int SHUTDOWNTIMEOUT = 5000;
	
	protected final PropertyManager propertyManager;
	
	protected volatile int portNumber;
	
	protected final TBTermFactory tbfactory;
	
	protected final List<ProcessInstance> processes;
	private int processIdCounter;
	private final ConcurrentHashMap<String, ProcessDefinition> procdefs;
	
	protected final MatchStore matchStore;
	
	private final ConcurrentHashMap<String, ToolDefinition> tooldefs;
	private final ToolInstanceManager toolInstanceManager;
	private volatile IToolExecutorFactory toolExecutorFactory;
	
	protected volatile SocketConnectionHandler connectionHandler;
	private final DirectConnectionHandler directConnectionHandler;
	
	private final PrintWriter out;
	
	protected int nerrors = 0;
	private int nwarnings = 0;
	
	private long startTime;
	private long nextTime = 0;
	
	protected volatile boolean shuttingDown = false;
	
	private volatile String[] scriptsNames = null; // For debugging only.
	
	private final Object shutdownLock = new Object();
	
	/**
	 * Constructor with explicit PrintWriter
	 * 
	 * @throws ToolBusError
	 */
	public ToolBus(String[] args, PrintWriter out){
		super();
		
		portNumber = -1; // Undefined.
		
		toolInstanceManager = new ToolInstanceManager();
		toolExecutorFactory = new DefaultToolExecutorFactory();
		
		tbfactory = TBTermFactory.getInstance();
		this.out = out;
		processes = new ArrayList<ProcessInstance>();
		processIdCounter = 0;
		procdefs = new ConcurrentHashMap<String, ProcessDefinition>();
		tooldefs = new ConcurrentHashMap<String, ToolDefinition>();
		
		matchStore = new MatchStore(tbfactory);
		
		propertyManager = new PropertyManager(args);
		
		directConnectionHandler = new DirectConnectionHandler(this);
		
		startTime = System.currentTimeMillis();
	}
	
	/**
	 * Constructor with implicit PrintWriter
	 * 
	 * @throws ToolBusError
	 */
	public ToolBus(String[] args){
		this(args, new PrintWriter(System.out));
	}
	
	public MatchStore getMatchStore(){
		return matchStore;
	}
	
	
	/**
	 * Constructor with explicit StringWriter
	 * 
	 * @throws ToolBusError
	 */
	public ToolBus(String[] args, StringWriter out){
		this(args, new PrintWriter(out));
	}
	
	public ToolInstanceManager getToolInstanceManager(){
		return toolInstanceManager;
	}
	
	public void setToolExecutorFactory(IToolExecutorFactory toolExecutorFactory){
		this.toolExecutorFactory = toolExecutorFactory;
	}
	
	public IToolExecutorFactory getToolExecutorFactory(){
		return toolExecutorFactory;
	}
	
	public DirectConnectionHandler getDirectConnectionHandler(){
		return directConnectionHandler;
	}
	
	/**
	 * Getters and setters for global properties
	 */
	
	public String getProperty(String p){
		String r = propertyManager.get(p);
		// System.err.println("get(" + p + ") => " + r);
		return r;
	}
	
	public String getProperty(String p, String def){
		String r = propertyManager.get(p, def);
		// System.err.println("get(" + p + ", " + def + ") => " + r);
		return r;
	}
	
	public void setProperty(String key, String val){
		propertyManager.set(key, val);
	}
	
	/**
	 * Networking functions
	 */
	
	static String getHostName(){
		String hostname = "";
		try{
			hostname = java.net.InetAddress.getLocalHost().getHostName();
			int dotPosition = hostname.indexOf('.');
			if(dotPosition != -1){
				hostname = hostname.substring(0, dotPosition);
			}
		}catch(java.net.UnknownHostException e){
			// Ignore, unable to resolve hostname
		}
		return hostname;
	}
	
	public int getPort(){
		return portNumber;
	}
	
	/**
	 * Get the ATermFactory used.
	 */
	public TBTermFactory getTBTermFactory(){
		return tbfactory;
	}
	
	/**
	 * Get the current list of processes.
	 */
	public List<ProcessInstance> getProcesses(){
		return processes;
	}
	
	/**
	 * Get current PrintWriter.
	 */
	public PrintWriter getPrintWriter(){
		return out;
	}
	
	public void error(String src, String msg){
		System.err.println(src + ": " + msg);
		nerrors++;
	}
	
	public void warning(String src, String msg){
		System.err.println(src + ": " + msg + " (warning)");
		nwarnings++;
	}
	
	public void clearErrorsAndWarnings(){
		nerrors = nwarnings = 0;
	}
	
	public long getRunTime(){
		return System.currentTimeMillis() - startTime;
	}
	
	/**
	 * Notifies the ToolBus that an atom with a delay on it, which could not be executed, has just been touched.
	 * 
	 * @param next
	 *            The relative time in milliseconds that needs to elapse before the atom can be executed.
	 */
	public void setNextTime(long next){
		//System.err.println("setNextTime: " + next);
		long currentTime = getRunTime();
		if((next < nextTime && next > currentTime) || nextTime < currentTime){
			nextTime = next;
		}
		//System.err.println("setNextTime: set to " + nextTime);
	}
	
	/**
	 * Parse a Tscript from file and add definitions to this ToolBus.
	 */
	public boolean parsecup1(HashSet<String> includedFiles, List<ATerm> toolbusProcessCalls, String filename){
		try{
		    parser parser_obj = new parser(includedFiles, toolbusProcessCalls, filename, new FileReader(filename), this);
			parser_obj.parse();
		}catch(ToolBusException e){ // TODO do not catch exceptions here
			error(filename, e.getMessage());
		}catch (FileNotFoundException e){
			error(filename, e.getMessage());
		}catch (Exception e){
			error(filename, e.getMessage());
		}
		return nerrors == 0;
	}
	
	public boolean parsecup(){
		String filename = propertyManager.get("script.path");
		if(filename == null) throw new RuntimeException("Script name undefined.");
		
		try{
		    parser parser_obj = new parser(this, filename);
			parser_obj.parse();
			
			// Initialize the signatures.
			final List<Atom> atomSignature = new ArrayList<Atom>();
			procdefs.iterate(new ReadOnlyHashMapEntryHandler<String, ProcessDefinition>(){
				public int handle(String key, ProcessDefinition value){
					ProcessExpression originalProcessExpression = value.getOriginalProcessExpression();
					AtomSet atoms = originalProcessExpression.getAtoms();
					Iterator<Atom> atomSetIterator = atoms.iterator();
					while(atomSetIterator.hasNext()){
						Atom a = atomSetIterator.next();
						atomSignature.add(a);
					}
					
					return CONTINUE;
				}
			});
			
			matchStore.initialize(atomSignature);
			
			calculateToolSignatures(atomSignature);
			
			parser_obj.generateInitialProcessCalls();
			
			// Keep track of the names of all the scripts for debugging purposes.
			scriptsNames = parser_obj.scriptsNames();
		}catch(ToolBusException te){
			error(filename, te.getMessage());
			te.printStackTrace();
		}catch(FileNotFoundException fnfex){
			error(filename, fnfex.getMessage());
			fnfex.printStackTrace();
		}catch(RuntimeException rex){
			throw rex;
		}catch(Exception ex){
			error(filename, ex.getMessage());
			ex.printStackTrace();
		}
		return nerrors == 0;
	}
	
	/**
	 * Add a process definition.
	 */
	public void addProcessDefinition(ProcessDefinition PD) throws ToolBusError{
		String name = PD.getName();
		//System.err.println("addProcessDefinition: " + name);
		if(procdefs.contains(name)) throw new ToolBusError("duplicate definition of process " + name);
		
		procdefs.put(name, PD);
	}
	
	/**
	 * Add a tool definition.
	 */
	public void addToolDefinition(ToolDefinition TD) throws ToolBusError{
		String name = TD.getName();
		if(tooldefs.contains(name)) throw new ToolBusError("duplicate definition of tool " + name);
		
		tooldefs.put(name, TD);
	}
	
	/**
	 * Get a tool definition by name.
	 */
	public ToolDefinition getToolDefinition(String name) throws ToolBusError{
		ToolDefinition definition = tooldefs.get(name);
		if(definition == null) throw new ToolBusError("No tool definition for tool " + name);
		
		return definition;
	}
	
	public List<ToolDefinition> getToolDefinitions(){
		final List<ToolDefinition> toolDefinitions = new ArrayList<ToolDefinition>();
		
		tooldefs.iterate(new ReadOnlyHashMapEntryHandler<String, ToolDefinition>(){
			public int handle(String key, ToolDefinition value){
				toolDefinitions.add(value);
				
				return CONTINUE;
			}
		});
		
		return toolDefinitions;
	}
	
	private void calculateToolSignatures(final List<Atom> atomSignature){
		tooldefs.iterate(new ReadOnlyHashMapEntryHandler<String, ToolDefinition>(){
			public int handle(String key, ToolDefinition value){
				value.calculateToolSignature(atomSignature);
				
				return CONTINUE;
			}
		});
	}
	
	/**
	 * Add a process (as ProcessCall); previous two will become obsolete.
	 */
	public ProcessInstance addProcess(ProcessCall call) throws ToolBusException{
		ProcessInstance pi;
		synchronized(processes){
			pi = new ProcessInstance(this, call, processIdCounter++);
			processes.add(pi);
		}
		return pi;
	}
	
	public List<ProcessDefinition> getProcessDefinitions(){
		final List<ProcessDefinition> processDefinitions = new ArrayList<ProcessDefinition>();
		
		procdefs.iterate(new ReadOnlyHashMapEntryHandler<String, ProcessDefinition>(){
			public int handle(String key, ProcessDefinition value){
				processDefinitions.add(value);
				
				return CONTINUE;
			}
		});
		
		return processDefinitions;
	}
	
	/**
	 * Get a process definition by name.
	 * 
	 * @param numberOfActuals
	 *            TODO
	 */
	public ProcessDefinition getProcessDefinition(String name, int numberOfActuals) throws ToolBusError{
		ProcessDefinition definition = procdefs.get(name);
		if(definition == null) throw new NoSuchProcessDefinitionException(name, numberOfActuals); 
		
		return definition;
	}
	
	public String[] getIncludedScripts(){
		return scriptsNames;
	}
	
	// TODO Fix the concurrency problems in here.
	/**
	 * Dumps the current state of all the processes in the ToolBus and the state of all the tools to stderr.
	 */
	public void showStatus(){
		if(workHasArrived == true || workHasArrived == false){ // Volatile read; triggers some cache coherency actions, so we see a reasonably up to date version of the data we're trying to dump (this variable is written to very often by the process logic thread; which is the one we want to sync with).
			System.err.println("--- ToolBus status: " + processes.size() + " processes; " + toolInstanceManager.numberOfConnectedTools() + " tools ----");
			Iterator<ProcessInstance> processesIterator = new ProcessInstanceIterator(processes);
			while(processesIterator.hasNext()){
				ProcessInstance P = processesIterator.next();
				System.err.println(P.showStatus());
			}
			toolInstanceManager.showStatus();
			System.err.println("------------------------");
		}
	}
	
	private volatile boolean running = false;
	private final Object processLock = new Object();
	private volatile boolean workHasArrived = false;
	
	/**
	 * Shutdown of this ToolBus.
	 */
	public void shutdown(ATerm msg){
		shuttingDown = true;
		System.err.println("Shutting down ToolBus: " + msg);
		
		Iterator<ProcessInstance> processIterator = new ProcessInstanceIterator(processes);
		while(processIterator.hasNext()){
			ProcessInstance pi = processIterator.next();
			pi.terminate(msg);
		}
		
		toolInstanceManager.shutDown(msg);
		
		// Wait for the connected tools to terminate.
		long startShutdownTime = System.currentTimeMillis();
		long endShutdownTime = startShutdownTime + SHUTDOWNTIMEOUT;
		do{
			Thread.yield();
			
			if(System.currentTimeMillis() > endShutdownTime){
				LoggerFactory.log("Shutdown timeout expired while waiting for the termination of the connected tools.", ILogger.WARNING, IToolBusLoggerConstants.TOOLINSTANCE);
				
				System.err.println("Tools that didn't shutdown gracefully: ");
				toolInstanceManager.showStatus();
				
				LoggerFactory.log("Killing executed tools.", ILogger.WARNING, IToolBusLoggerConstants.TOOLINSTANCE);
				toolInstanceManager.killExecutedToolsNow();
				break;
			}
		}while(toolInstanceManager.numberOfConnectedTools() > 0);
		
		connectionHandler.stopRunning();
		
		synchronized(processLock){
			running = false;
			processLock.notify();
		}
	}
	
	/**
	 * Gathers performance statistics and writes them to the console.
	 */
	public void dumpPerformanceStats(){
		// Memory stuff
		MemoryMXBean mmxb = ManagementFactory.getMemoryMXBean();
		long heapMemoryUsage = mmxb.getHeapMemoryUsage().getUsed();
		long nonHeapMemoryUsage = mmxb.getNonHeapMemoryUsage().getUsed();
		
		System.err.println("Memory usage: heap = " + (heapMemoryUsage / 1024) + "KB, non-heap = " + (nonHeapMemoryUsage / 1024) + "KB");
		
		// Thread stuff
		ThreadMXBean tmxb = ManagementFactory.getThreadMXBean();
		
		long[] threadIds = tmxb.getAllThreadIds();
		int nrOfThreads = threadIds.length;
		for(int i = 0; i < nrOfThreads; i++){
			ThreadInfo ti = tmxb.getThreadInfo(threadIds[i]);
			if(ti != null){
				String threadName = ti.getThreadName();
				long userTime = tmxb.getThreadUserTime(threadIds[i]);
				long systemTime = tmxb.getThreadCpuTime(threadIds[i]) - userTime;
				
				if((userTime + systemTime) > 0) System.err.println(threadName + " : user time = " + (userTime / 1000000) + ", system time = " + (systemTime / 1000000));
			}
		}
	}
	
	// TODO Fix the concurrency problems in here.
	/**
	 * Prints all unhandled messages and queued notes to stderr.
	 */
	public void dumpUnhandledMessages(){
		if(workHasArrived == true || workHasArrived == false){ // Volatile read; triggers some cache coherency actions, so we see a reasonably up to date version of the data we're trying to dump (this variable is written to very often by the process logic thread; which is the one we want to sync with).
			boolean anythingUnhandled = false;
			ProcessInstanceIterator processInstanceIterator = new ProcessInstanceIterator(processes);
			try{
				while(processInstanceIterator.hasNext()){
					ProcessInstance pi = processInstanceIterator.next();
					List<ATerm> unhandledNotes = pi.getNoteQueue();
					List<StateElement> unhandledMessage = pi.getCurrentState().getUnhandledMessages();
					
					if((unhandledNotes.size() + unhandledMessage.size()) > 0){
						anythingUnhandled = true;
						
						System.err.println(pi.getProcessName()+"("+pi.getProcessId()+"):");
						
						try{
							System.err.println(unhandledNotes);
						}catch(RuntimeException rex){
							// Ignore this so we can go on.
						}
						
						try{
							System.err.println(unhandledMessage);
						}catch(RuntimeException rex){
							// Ignore this so we can go on.
						}
					}
				}
			}catch(RuntimeException rex){
				// This will probably never happen, but it's necessary none the less.
			}
			
			if(!anythingUnhandled){
				System.err.println("No unhandled messages.");
			}
		}
	}
	
	public void prepare(){
		if(nerrors > 0){
			System.err.println("ToolBus cannot continue execution due to errors in Tscript");
			return;
		}
		
		if(propertyManager.withConsole()) CommandLine.createCommandLine(this, System.in, false);
		
		// Initialize and start the connection handler.
		connectionHandler = new SocketConnectionHandler(this);
		
		try{
			int userSpecifiedPort = propertyManager.getUserSpecifiedPort();
			if(userSpecifiedPort == -1){
				connectionHandler.initialize();
			}else{
				connectionHandler.initialize(userSpecifiedPort);
			}
		}catch(IOException ioex){
			LoggerFactory.log("Unable initialize the ToolBus connection handler.", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(ioex);
		}
		portNumber = connectionHandler.getPort();
		
		Thread tbConnectionHandler = new Thread(connectionHandler);
		tbConnectionHandler.setName("ToolBus connection handler");
		tbConnectionHandler.start();
		
		System.out.println("The ToolBus server allocated port ("+portNumber+")");
	}
	
	// TODO Replace the process logic loop stuff by a full blown scheduler. This code is rather ugly and fragile.
	/**
	 * The ToolBus's main process loop.
	 * This method handles the execution of the process logic.
	 */
	public void execute(){
		ProcessInstance pi = null;
		ProcessInstanceIterator processesIterator = new ProcessInstanceIterator(processes);
		running = true;
		try{
			PROCESSLOOP: do{
				long currentNextTime = nextTime;
				boolean work;
				do{
					workHasArrived = false;
					work = false;
					
					while(processesIterator.hasNext()){
						if(shuttingDown) break PROCESSLOOP;
						
						pi = processesIterator.next();
						work |= pi.step();
						if(pi.isTerminated()){
							processesIterator.remove();
							pi.terminate(tbfactory.EmptyList);
							
							// Shut down the ToolBus when there are no more running processes left.
							if(processes.size() == 0) break PROCESSLOOP;
						}
					}
					
					Collections.rotate(processes, 1);
					
					processesIterator.reset();
				}while(work);
				
				synchronized(processLock){
					// If we got nothing left to do and we are still running, wait for work to
					// arrive.
					while(!workHasArrived && running){
						try{
							long blockTime = nextTime - getRunTime(); // Recalculate the delay before sleeping.
							if(blockTime > 0){
								processLock.wait(blockTime);
								workHasArrived = true;
							}else if(currentNextTime != nextTime){ // If the nextTime changed and the blockTime is zero or less, don't block as there might be work to do.
								workHasArrived = true;
							}else{
								processLock.wait();
							}
						}catch(InterruptedException irex){
							// Just ignore this, it's not harmfull.
						}
					}
				}
			}while(running);
		}catch(ToolBusException ex){
			error("ToolBus exception occured in process " + (pi != null ? pi.getProcessName() : "?"), ex.getMessage());
			ex.printStackTrace();
		}catch(RuntimeException rex){
			error("ToolBus exception occured in process " + (pi != null ? pi.getProcessName() : "?"), rex.getMessage());
			rex.printStackTrace();
		}
		
		// If the ToolBus is still running, shut it down.
		if(!shuttingDown) shutdown(tbfactory.make("ToolBus halted"));
		
		synchronized(shutdownLock){
			shutdownLock.notifyAll();
		}
	}
	
	/**
	 * Notifies the ToolBus that work has arrived.
	 * This will wake the ToolBus's process loop up if it's currently sleeping.
	 * 
	 * @param toolInstance
	 *            The tool instance associated with the tool that send us data.
	 * @param operation
	 *            The operation associated with the package that arrived.
	 */
	public void workArrived(ToolInstance toolInstance, byte operation){
		// Only notify when needed.
		if(!workHasArrived){
			workHasArrived = true;
			synchronized(processLock){
				processLock.notify();
			}
		}
	}
	
	public void waitTillShutdown(){
		synchronized(shutdownLock){
			while(!shuttingDown && running){
				try{
					shutdownLock.wait();
				}catch(InterruptedException irex){
					// Ignore this exception.
				}
			}
		}
	}
	
	/**
	 * Custom iterator class.
	 * This is souly needed, so we aren't being bothered by the 'fail-fast eventhough it's completely pointless, since it's the currently iterating thread that modified something and not a concurrently running one, in which case I'm probably unable to detect it anyway' behaviour.
	 * 
	 * @author Arnold Lankamp
	 */
	protected static class ProcessInstanceIterator implements Iterator<ProcessInstance>{
		private final List<ProcessInstance> list;
		private int index;
		
		public ProcessInstanceIterator(List<ProcessInstance> list){
			this.list = list;
			this.index = 0;
		}
		
		public boolean hasNext(){
			synchronized(list){
				return (list.size() > index);
			}
		}
		
		public ProcessInstance next(){
			synchronized(list){
				return list.get(index++);
			}
		}
		
		// You can only call this once per iteration!
		public void remove(){
			synchronized(list){
				list.remove(--index);
			}
		}
		
		public void reset(){
			index = 0;
		}
	}
}
