/**
 * @author paulk
 */

package toolbus;

import java.io.FileNotFoundException;
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
import java.util.Random;
import toolbus.exceptions.ToolBusError;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.parser.ExternalParser;
import toolbus.parser.TScriptParser;
import toolbus.parsercup.parser;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessDefinition;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.util.collections.ConcurrentHashMap;
import toolbus.util.collections.ConcurrentHashSet;
import toolbus.util.collections.EntryHandlerConstants;
import toolbus.util.collections.ConcurrentHashSet.ReadOnlyHashSetEntryHandler;
import aterm.ATerm;
import aterm.ATermList;


/**
 * ToolBus implements the behaviour of one ToolBus.
 */
public class ToolBus{
	// The amount of time we wait for tools to terminate when the toolbus's shutdown sequence is
	// initiated.
	private final static int SHUTDOWNTIMEOUT = 5000;
	
	private final static Random rand = new Random();
	
	protected final PropertyManager propertyManager;
	
	protected volatile int portNumber;
	
	protected final TBTermFactory tbfactory;
	
	protected final List<ProcessInstance> processes; // process instances
	private int processIdCounter;
	private final ConcurrentHashMap<String, ProcessDefinition> procdefs;
	private final ConcurrentHashSet<ATerm> atomSignature; // Signature of all atoms in executing processes
												// TODO: should this not be for ALL defined processes?
	
	private final ToolInstanceManager toolInstanceManager;
	private final ConcurrentHashMap<String, ToolDefinition> tooldefs;
	
	protected final ToolBusConnectionHandler toolBusConnectionHandler;
	
	private final PrintWriter out;
	
	protected int nerrors = 0;
	private int nwarnings = 0;
	
	private long startTime;
	private long nextTime = 0;
	
	protected volatile boolean shuttingDown = false;
	
	/**
	 * Constructor with explicit PrintWriter
	 * 
	 * @throws ToolBusError
	 */
	public ToolBus(String[] args, PrintWriter out){
		super();
		
		portNumber = -1; // Undefined.
		
		toolInstanceManager = new ToolInstanceManager();
		
		tbfactory = TBTermFactory.getInstance();
		this.out = out;
		processes = new ArrayList<ProcessInstance>();
		processIdCounter = 0;
		procdefs = new ConcurrentHashMap<String, ProcessDefinition>();
		tooldefs = new ConcurrentHashMap<String, ToolDefinition>();
		atomSignature = new ConcurrentHashSet<ATerm>();
		
		propertyManager = new PropertyManager(args);
		
		toolBusConnectionHandler = new ToolBusConnectionHandler(this);
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
	
	public ToolInstanceManager getToolInstanceManager(){
		return toolInstanceManager;
	}
	
	/**
	 * Constructor with explicit StringWriter
	 * 
	 * @throws ToolBusError
	 */
	public ToolBus(String[] args, StringWriter out){
		this(args, new PrintWriter(out));
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
	
	/**
	 * Generate next random boolean.
	 */
	public static boolean nextBoolean(){
		return rand.nextBoolean();
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
	public boolean parse(){
		String filename = propertyManager.get("script.path");
		if(filename == null) throw new RuntimeException("Script name undefined.");
		
		TScriptParser parser = new TScriptParser(new ExternalParser(this), this);
		try{
			parser.parse(filename);
		}catch(ToolBusException e){
			error(filename, e.getMessage());
		}
		return nerrors == 0;
	}
	
	/**
	 * Parse a Tscript from file and add definitions to this ToolBus.
	 */
	public boolean parsecup1(HashSet<String> includedFiles, List<ATerm> toolbusProcessCalls,  String filename){
		try{
		    parser parser_obj = new parser(includedFiles, toolbusProcessCalls, filename, this);
			parser_obj.parse();
		}catch(ToolBusException e){
			error(filename, e.getMessage());
		} catch (FileNotFoundException e) {
			error(filename, e.getMessage());
			e.printStackTrace();
		} catch (Exception e) {
			error(filename, e.getMessage());
			e.printStackTrace();
		}
		return nerrors == 0;
	}
	
	public boolean parsecup(){
		String filename = propertyManager.get("script.path");
		if(filename == null) throw new RuntimeException("Script name undefined.");
		
		try{
		    parser parser_obj = new parser(filename, this);
			parser_obj.parse();
			parser_obj.generateInitialProcessCalls();
		}catch(ToolBusException e){
			error(filename, e.getMessage());
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			error(filename, e.getMessage());
			e.printStackTrace();
		} catch (Exception e) {
			error(filename, e.getMessage());
			e.printStackTrace();
		}
		return nerrors == 0;
	}
	
	/**
	 * Add a process definition.
	 */
	public void addProcessDefinition(ProcessDefinition PD) throws ToolBusError{
		String uname = PD.getUniqueName();
		//System.err.println("addProcessDefinition: " + uname);
		if(procdefs.contains(uname)) throw new ToolBusError("duplicate definition of process " + uname);
		
		procdefs.put(uname, PD);
	}
	
	/**
	 * Add a tool definition.
	 */
	public void addToolDefinition(ToolDefinition TD) throws ToolBusError{
		String name = TD.getName();
		if(tooldefs.contains(name)) throw new ToolBusError("duplicate definition of tool " + name);
		
		tooldefs.put(name, TD);
		TD.setToolBus(this);
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
	
	/**
	 * Get a process definition by name.
	 * 
	 * @param numberOfActuals
	 *            TODO
	 */
	public ProcessDefinition getProcessDefinition(String name, int numberOfActuals) throws ToolBusError{
		String uname = name + numberOfActuals;
		ProcessDefinition definition = procdefs.get(uname);
		if(definition == null) throw new ToolBusError("No definition for process " + uname); 
		
		return definition;
	}
	
	public boolean existsProcessDefinition(String name, int numberOfActuals){
		return procdefs.contains(name + numberOfActuals);
	}
	
	/**
	 * Get a tool definition by name.
	 */
	public ToolDefinition getToolDefinition(String name) throws ToolBusError{
		ToolDefinition definition = tooldefs.get(name);
		if(definition != null){
			definition.setToolSignatures(getSignature());
			return definition;
		}
		
		throw new ToolBusError("No tool definition for tool " + name);
	}
	
	public void addToSignature(ATerm asig){
		ATerm pat = tbfactory.makePattern(asig);
		atomSignature.put(pat);
	}
	
	private ATermList getSignature(){
		class AtomSignatureIterationHandler extends ReadOnlyHashSetEntryHandler<ATerm>{
			public ATermList res = tbfactory.EmptyList;

			public int handle(ATerm value){
				res = tbfactory.makeList(value, res);
				
				return EntryHandlerConstants.CONTINUE;
			}
		}
		AtomSignatureIterationHandler asih = new AtomSignatureIterationHandler();
		atomSignature.iterate(asih);
		
		return asih.res;
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
		
		toolBusConnectionHandler.stopRunning();
		
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
	
	// TODO Replace the process logic loop stuff by a full blown scheduler. This code is rather ugly and fragile.
	/**
	 * The ToolBus's main process loop.
	 * This method handles the execution of the process logic.
	 */
	public void execute(){
		if(nerrors > 0){
			System.err.println("ToolBus cannot continue execution due to errors in Tscript");
			return;
		}
		
		// Initialize and start the connection handler.
		try{
			int userSpecifiedPort = propertyManager.getUserSpecifiedPort();
			if(userSpecifiedPort == -1){
				toolBusConnectionHandler.initialize();
			}else{
				toolBusConnectionHandler.initialize(userSpecifiedPort);
			}
		}catch(IOException ioex){
			LoggerFactory.log("Unable initialize the ToolBus connection handler.", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(ioex);
		}
		portNumber = toolBusConnectionHandler.getPort();
		
		Thread tbConnectionHandler = new Thread(toolBusConnectionHandler);
		tbConnectionHandler.setName("ToolBus connection handler");
		tbConnectionHandler.start();
		
		System.out.println("The ToolBus server allocated port ("+portNumber+")");
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
						if(shuttingDown) return;
						
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
		}catch(ToolBusException e){
			error("Process " + (pi != null ? pi.getProcessName() : "?"), e.getMessage());
			e.printStackTrace();
		}
		
		// If the ToolBus is still running, shut it down.
		if(!shuttingDown) shutdown(tbfactory.make("ToolBus halted"));
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
