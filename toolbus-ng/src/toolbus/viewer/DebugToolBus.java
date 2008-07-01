package toolbus.viewer;

import java.io.IOException;
import java.lang.management.ManagementFactory;
import java.lang.management.MemoryMXBean;
import java.lang.management.ThreadInfo;
import java.lang.management.ThreadMXBean;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import toolbus.SocketConnectionHandler;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessInstance;
import toolbus.process.debug.ExecutionResult;
import toolbus.tool.ToolInstance;
import toolbus.util.collections.ConcurrentHashSet;
import aterm.ATerm;
import aterm.ATermList;

/**
 * A specialized version of the ToolBus, which executes the process logic in debug mode. Viewer
 * implementations need to use this ToolBus instead of the regular one.
 * 
 * @author Arnold Lankamp
 */
public class DebugToolBus extends ToolBus{
	private volatile int currentState = IViewerConstants.UNKNOWN_STATE;
	
	private volatile boolean running = false;
	private final Object processLock = new Object();
	private volatile boolean workHasArrived = false;
	
	private volatile boolean doRun = false;
	private volatile boolean doStep = false;
	
	private volatile boolean breakWhileStepping;
	
	private final IViewer viewer;
	
	private final ConcurrentHashSet<Integer> processInstanceBreakPoints;
	private final ConcurrentHashSet<String> processBreakPoints;
	private final ConcurrentHashSet<StateElement> stateElementBreakPoints;
	private final Map<String, List<Integer>> sourceCodeBreakPoints;
	
	private final PerformanceInformationHandler performanceInformationRetriever;
	
	private long nextTime;
	
	/**
	 * Constructor.
	 * 
	 * @param args
	 *            The arguments the ToolBus need to start (like include path and main script name).
	 * @param viewer
	 *            The viewer that is attached to this ToolBus.
	 * @param performanceMonitor
	 *            The tool performance monitor to use (optional argument; pass null in case
	 *            monitoring is not required).
	 */
	public DebugToolBus(String[] args, IViewer viewer, IPerformanceMonitor performanceMonitor){
		super(args);
		
		this.viewer = viewer;
		
		this.performanceInformationRetriever = (performanceMonitor != null) ? new PerformanceInformationHandler(performanceMonitor): null;
		
		processInstanceBreakPoints = new ConcurrentHashSet<Integer>();
		processBreakPoints = new ConcurrentHashSet<String>();
		stateElementBreakPoints = new ConcurrentHashSet<StateElement>();
		sourceCodeBreakPoints = new HashMap<String, List<Integer>>();
		
		nextTime = 0;
		
		breakWhileStepping = true;
	}
	
	/**
	 * @see toolbus.ToolBus#addProcess(ProcessCall)
	 */
	public ProcessInstance addProcess(ProcessCall call) throws ToolBusException{
		ProcessInstance pi = super.addProcess(call);
		viewer.processInstanceStarted(pi);
		return pi;
	}
	
	/**
	 * Terminates the ToolBus.
	 * 
	 * @see toolbus.ToolBus#shutdown(ATerm)
	 */
	public void shutdown(ATerm msg){
		viewer.toolbusTerminating();
		
		super.shutdown(msg);
		
		running = false;
		
		synchronized(processLock){
			processLock.notify();
		}
	}
	
	/**
	 * @see toolbus.ToolBus#setNextTime(long)
	 */
	public void setNextTime(long next){
		//System.err.println("setNextTime: " + next);
		long currentTime = getRunTime();
		if(nextTime < currentTime || (next < nextTime && next > currentTime)){
			nextTime = next;
		}
		//System.err.println("setNextTime: set to " + nextTime);
	}
	
	public void prepare(){
		if(nerrors > 0){
			System.err.println("ToolBus cannot continue execution due to errors in Tscript");
			return;
		}
		
		viewer.toolbusStarting();

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
		
		System.out.println("The ToolBus server allocated port (" + portNumber + ")");
	}
	
	/**
	 * The main process loop of the ToolBus.
	 * 
	 * @see toolbus.ToolBus#execute()
	 */
	public void execute(){
		ProcessInstance pi = null;
		ProcessInstanceIterator processesIterator = new ProcessInstanceIterator(processes);
		running = true;
		try{
			boolean work = false;
			boolean reset = false;
			long currentNextTime = 0;
			workHasArrived = true; // This is just to get things started.
			
			PROCESSLOOP: do{
				synchronized(processLock){
					while((!workHasArrived && running) || !(doStep || doRun)){
						fireStateChange(IViewerConstants.WAITING_STATE);
						
						long blockTime = nextTime - getRunTime(); // Recalculate the delay before sleeping.
						if(blockTime > 0){
							try{
								processLock.wait(blockTime);
							}catch(InterruptedException irex){
								// Just ignore this, it's not harmfull.
							}
							workHasArrived = true;
						}else if(currentNextTime != nextTime){ // If the nextTime changed and the blockTime is zero or less, don't block as there might be work to do.
							workHasArrived = true;
							currentNextTime = nextTime;
						}else{
							try{
								processLock.wait();
							}catch(InterruptedException irex){
								// Just ignore this, it's not harmfull.
							}
							
							if(performanceInformationRetriever != null) performanceInformationRetriever.handleRetrievedData(); // Handle the arrived performance stats before continueing to execute the process logic.
						}
						
						if(shuttingDown) return; // Stop executing if a shutdown is triggered.
					}
					currentNextTime = nextTime;
					
					if(doStep) fireStateChange(IViewerConstants.STEPPING_STATE);
					else if(doRun) fireStateChange(IViewerConstants.RUNNING_STATE);
					else fireStateChange(IViewerConstants.UNKNOWN_STATE);
				}
				
				WORKLOOP: do{
					work = false;
					workHasArrived = false;
					
					if(!processesIterator.hasNext()){
						processesIterator.reset();
						Collections.rotate(processes, 1);
						
						reset = true;
					}else{
						reset = false; // We might start iterating in the middle of the collections, so ensure we do at least a full one if we're running.
					}
					
					while(processesIterator.hasNext() && (doRun || doStep)){
						if(shuttingDown){
							return;
						}
						
						pi = processesIterator.next();
						ExecutionResult executionResult = pi.debugStep();
						boolean stepSuccessFull = (executionResult != null);
						boolean wasStep = doStep;
						
						if(wasStep && stepSuccessFull){
							doStep = false; // Consume the step.
						}
						
						String processName = pi.getProcessName();
						int processId = pi.getProcessId();
						if(!wasStep || breakWhileStepping){
							if(stepSuccessFull){
								if(processInstanceBreakPoints.contains(new Integer(processId)) || processBreakPoints.contains(processName)){
									viewer.processBreakPointHit(pi);
								}
								StateElement executedStateElement = executionResult.stateElement; // Ignore the Eclipse warning here, since it's bogus.
								if(stateElementBreakPoints.contains(executedStateElement)){
									viewer.stateElementBreakPointHit(executedStateElement);
								}
								PositionInformation posInfo = executedStateElement.getPosInfo();
								if(posInfo != null){
									String filename = posInfo.getFileName();
									List<Integer> lineNumbers = sourceCodeBreakPoints.get(filename);
									if(lineNumbers != null){
										int beginLineNumber = posInfo.getBeginLine();
										int endLineNumber = posInfo.getEndLine();
										
										Iterator<Integer> lineNumberIterator = lineNumbers.iterator();
										synchronized(lineNumbers){
											while(lineNumberIterator.hasNext()){
												int lineNumber = lineNumberIterator.next().intValue();
												if(lineNumber >= beginLineNumber && lineNumber <= endLineNumber){
													viewer.sourceBreakPointHit(executedStateElement);
													break;
												}
											}
										}
									}
								}
							}
						}
						
						if(pi.isTerminated()){
							processesIterator.remove();
							pi.terminate(tbfactory.EmptyList);
							
							viewer.processInstanceTerminated(pi);
							
							if(processes.size() == 0) break PROCESSLOOP;
						}
						work |= stepSuccessFull;
						
						if(stepSuccessFull){
							if(wasStep){
								viewer.stepExecuted(pi, executionResult.stateElement, executionResult.partners); // Ignore the Eclipse warning here, since it's bogus.
								break WORKLOOP;
							}
						}
					}
					
					if(performanceInformationRetriever != null) performanceInformationRetriever.handleRetrievedData(); // Handle the arrived performance stats before continueing the process.
				}while((doRun && (work || !reset)) || (doStep && !reset));
				workHasArrived |= work; // If we did something, set this to ensure we can release the lock when needed.
			}while(running);
		}catch(ToolBusException e){
			error("Process " + (pi != null ? pi.getProcessName() : "?"), e.getMessage());
			e.printStackTrace();
		}
		
		if(!shuttingDown) shutdown(tbfactory.make("ToolBus halted"));
	}
	
	/**
	 * @see toolbus.ToolBus#workArrived()
	 */
	public void workArrived(ToolInstance toolInstance, byte operation){
		if(performanceInformationRetriever != null){
			performanceInformationRetriever.toolCommunicationTriggered(toolInstance, operation);
		}
		
		if(!workHasArrived){
			synchronized(processLock){
				fireStateChange(IViewerConstants.READY_STATE);
				
				workHasArrived = true;
				
				processLock.notify();
			}
		}
	}
	
	/**
	 * Gathers performance statistics related to JVM the current ToolBus is running in.
	 * 
	 * @return Performance statictics.
	 */
	public ATerm getToolBusPerformanceStats(){
		// Type stuff (for standard compliance only).
		ATerm toolData = tbfactory.makeAppl(tbfactory.makeAFun("unsupported-operation", 0, false));
		
		// Memory stuff
		MemoryMXBean mmxb = ManagementFactory.getMemoryMXBean();
		long heapMemoryUsage = mmxb.getHeapMemoryUsage().getUsed();
		long nonHeapMemoryUsage = mmxb.getNonHeapMemoryUsage().getUsed();
		
		ATerm heapUsage = tbfactory.makeAppl(tbfactory.makeAFun("heap-usage", 1, false), tbfactory.makeInt(((int) (heapMemoryUsage / 1024))));
		ATerm nonHeapUsage = tbfactory.makeAppl(tbfactory.makeAFun("non-heap-usage", 1, false), tbfactory.makeInt(((int) (nonHeapMemoryUsage / 1024))));
		
		ATerm memory = tbfactory.makeAppl(tbfactory.makeAFun("memory-usage", 2, false), heapUsage, nonHeapUsage);
		
		// Thread stuff
		ThreadMXBean tmxb = ManagementFactory.getThreadMXBean();
		
		ATerm threads;
		
		long[] threadIds = tmxb.getAllThreadIds();
		int nrOfThreads = threadIds.length;
		try{
			ATermList threadsList = tbfactory.makeList();
			for(int i = 0; i < nrOfThreads; i++){
				ThreadInfo ti = tmxb.getThreadInfo(threadIds[i]);
				if(ti != null){
					String threadName = ti.getThreadName();
					long userTime = tmxb.getThreadUserTime(threadIds[i]);
					long systemTime = tmxb.getThreadCpuTime(threadIds[i]) - userTime;
					
					if((userTime + systemTime) <= 0) continue;
					
					ATerm userTimeTerm = tbfactory.makeAppl(tbfactory.makeAFun("user-time", 1, false), tbfactory.makeInt(((int) (userTime / 1000000))));
					ATerm systemTimeTerm = tbfactory.makeAppl(tbfactory.makeAFun("system-time", 1, false), tbfactory.makeInt(((int) (systemTime / 1000000))));
					ATerm thread = tbfactory.makeAppl(tbfactory.makeAFun(threadName, 2, false), userTimeTerm, systemTimeTerm);
					
					threadsList = tbfactory.makeList(thread, threadsList);
				}
			}
			
			threads = tbfactory.makeAppl(tbfactory.makeAFun("threads", 1, false), threadsList);
		}catch(UnsupportedOperationException uoex){
			threads = tbfactory.make("threads(unsupported-operation)");
			LoggerFactory.log("Thread time profiling is not supported by this JVM.", ILogger.ERROR, IToolBusLoggerConstants.EXECUTE);
		}
		
		return tbfactory.makeAppl(tbfactory.makeAFun("performance-stats", 3, false), toolData, memory, threads);
	}
	
	/**
	 * Notifies the debug toolbus that it should execute normally.
	 */
	public void doRun(){
		synchronized(processLock){
			workHasArrived = true; // This should not be needed; it's just here to ensure we will escape the wait loop.
			
			doStep = false;
			doRun = true;
			
			fireStateChange(IViewerConstants.RUNNING_STATE);
			
			processLock.notify();
		}
	}
	
	/**
	 * Notifies the debug toolbus that it should suspend its execution.
	 */
	public void doStop(){
		synchronized(processLock){
			fireStateChange(IViewerConstants.STOPPING_STATE);
			
			doRun = false;
			doStep = false;
			
			processLock.notify(); // This causes the state to be updated properly.
		}
	}
	
	/**
	 * Notifies the debug toolbus that it should execute one step.
	 */
	public void doStep(){
		synchronized(processLock){
			workHasArrived = true; // This should not be needed; it's just here to ensure we will escape the wait loop.
			
			doRun = false;
			doStep = true;
			
			fireStateChange(IViewerConstants.STEPPING_STATE);
			
			processLock.notify();
		}
	}
	
	/**
	 * Requests the termination of the ToolBus.
	 */
	public void doTerminate(){
		shutdown(TBTermFactory.getInstance().EmptyList);
	}
	
	/**
	 * Sends a notification to the attached Viewer that the ToolBus's state changed.
	 * 
	 * @param state
	 *            The state we changed to.
	 */
	private void fireStateChange(int state){
		if(state != currentState){
			currentState = state;
			viewer.updateState(state);
		}
	}
	
	/**
	 * Tells the debug toolbus whether or not it should fire 'breakPointHit' events while stepping.
	 * This parameter is set to true by default.
	 * 
	 * @param breakWhileStepping
	 *            The flag that indicates whether or not to break on breakpoints while stepping.
	 */
	public void setBreakWhileStepping(boolean breakWhileStepping){
		this.breakWhileStepping = breakWhileStepping;
	}
	
	/**
	 * Adds a breakpoint for the process instance with the given id. When the debug toolbus executes
	 * a state element in the associated process instance, the attached Viewer will be notified.
	 * 
	 * @param processId
	 *            The id of the process instance we want to add a breakpoint for.
	 */
	public void addProcessInstanceBreakPoint(int processId){
		processInstanceBreakPoints.put(new Integer(processId));
	}
	
	/**
	 * Removes the breakpoint on the process instance with the given id (if present).
	 * 
	 * @param processId
	 *            The id of the process instance we want to remove the breakpoint for.
	 */
	public void removeProcessInstanceBreakPoint(int processId){
		processInstanceBreakPoints.remove(new Integer(processId));
	}
	
	/**
	 * Adds a breakpoint for all the process instances whos type is identified by the given name.
	 * When the debug toolbus executes a state element in one of those process instances, the
	 * attached Viewer will be notified.
	 * 
	 * @param processName
	 *            The name that identifies the type of process instances we want to add breakpoints
	 *            for.
	 */
	public void addProcessBreakPoint(String processName){
		processBreakPoints.put(processName);
	}
	
	/**
	 * Removes the breakpoints for the process instances whos type is identified by the given name
	 * (if present).
	 * 
	 * @param processName
	 *            The name that identifies the type of process instance we want to remove the
	 *            breakpoints for.
	 */
	public void removeProcessBreakPoint(String processName){
		processBreakPoints.remove(processName);
	}
	
	/**
	 * Adds a breakpoint on the given state element. When the debug toolbus executes the given state
	 * element, the attached Viewer will be notified.
	 * 
	 * @param stateElement
	 *            The state element we want to add a breakpoint for.
	 */
	public void addStateElementBreakPoint(StateElement stateElement){
		stateElementBreakPoints.put(stateElement);
	}
	
	/**
	 * Removes the breakpoint from the given state element (if present).
	 * 
	 * @param stateElement
	 *            The state element we want to remove the breakpoint from.
	 */
	public void removeStateElementBreakPoint(StateElement stateElement){
		stateElementBreakPoints.remove(stateElement);
	}
	
	/**
	 * Adds a breakpoint on the given sourcecode coordinates. When the debug toolbus executes a
	 * state element which's position information matches the sourcecode coordiates, the attached
	 * Viewer will be notified.
	 * 
	 * @param filename
	 *            The name of the sourcefile
	 * @param lineNumber
	 *            The line number to add the breakpoint on. Note that sourcecode line numbers start
	 *            counting at 0.
	 */
	public void addSourceCodeBreakPoint(String filename, int lineNumber){
		synchronized(sourceCodeBreakPoints){
			List<Integer> lineNumbers = sourceCodeBreakPoints.get(filename);
			if(lineNumbers == null){
				lineNumbers = new LinkedList<Integer>();
				sourceCodeBreakPoints.put(filename, lineNumbers);
			}
			synchronized(lineNumbers){
				lineNumbers.add(Integer.valueOf(lineNumber));
			}
		}
	}
	
	/**
	 * Removes the breakpoint from the given source code coordinates (if present).
	 * 
	 * @param filename
	 *            The name of the sourcefile
	 * @param lineNumber
	 *            The line number to remove the breakpoint for.
	 */
	public void removeSourceCodeBreakPoint(String filename, int lineNumber){
		synchronized(sourceCodeBreakPoints){
			List<Integer> lineNumbers = sourceCodeBreakPoints.get(filename);
			synchronized(lineNumbers){
				lineNumbers.remove(Integer.valueOf(lineNumber));
			}
			if(lineNumbers.isEmpty()){
				sourceCodeBreakPoints.remove(filename);
			}
		}
	}
	
	/**
	 * Initiates the monitoring of the tool associated with the given tool key (in case performance
	 * monitoring is enabled for this debug ToolBus).
	 * 
	 * @param toolKey
	 *            The tool key associated with the tool we want to monitor.
	 */
	public void startMonitoringTool(ATerm toolKey){
		performanceInformationRetriever.startMonitoringTool(toolKey);
	}
	
	/**
	 * Stops monitoring the tool associated with the given tool key.
	 * 
	 * @param toolKey
	 *            The tool key associated with the tool which we want to stop monitoring.
	 */
	public void stopMonitoringTool(ATerm toolKey){
		performanceInformationRetriever.startMonitoringTool(toolKey);
	}
	
	/**
	 * Initiates the monitoring of the given tool type (in case performance monitoring is enabled
	 * for this debug ToolBus).
	 * 
	 * @param toolName
	 *            The tool type of tool we want to monitor.
	 */
	public void startMonitorToolType(String toolName){
		performanceInformationRetriever.startMonitorToolType(toolName);
	}
	
	/**
	 * Stops monitoring tools of the given type.
	 * 
	 * @param toolName
	 *            The type of tool which we want to stop monitoring.
	 */
	public void stopMonitoringToolType(String toolName){
		performanceInformationRetriever.stopMonitoringToolType(toolName);
	}
}
