package toolbus.viewer;

import java.io.IOException;
import java.util.Collections;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessInstance;
import toolbus.util.collections.ConcurrentHashSet;
import aterm.ATerm;

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
	
	private final IViewer viewer;
	
	private final ConcurrentHashSet<Integer> processInstanceBreakPoints;
	private final ConcurrentHashSet<String> processBreakPoints;
	private final ConcurrentHashSet<StateElement> stateElementBreakPoints;
	
	private long nextTime;
	
	/**
	 * Constructor.
	 * 
	 * @param args
	 *            The arguments the ToolBus need to start (like include path and main script name).
	 * @param viewer
	 *            The viewer that is attached to this ToolBus.
	 */
	public DebugToolBus(String[] args, IViewer viewer){
		super(args);
		
		this.viewer = viewer;
		
		processInstanceBreakPoints = new ConcurrentHashSet<Integer>();
		processBreakPoints = new ConcurrentHashSet<String>();
		stateElementBreakPoints = new ConcurrentHashSet<StateElement>();
		
		nextTime = 0;
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
		// System.err.println("setNextTime: " + next);
		long currentTime = getRunTime();
		if(nextTime < currentTime || (next < nextTime && next > currentTime)){
			nextTime = next;
		}
		// System.err.println("setNextTime: set to " + nextTime);
	}
	
	/**
	 * The main process loop of the ToolBus.
	 * 
	 * @see toolbus.ToolBus#execute()
	 */
	public void execute(){
		if(nerrors > 0){
			System.err.println("ToolBus cannot continue execution due to errors in Tscript");
			return;
		}
		
		viewer.toolbusStarting();
		
		try{
			toolBusConnectionHandler.initialize();
		}catch(IOException ioex){
			LoggerFactory.log("Unable initialize the ToolBus connection handler.", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(ioex);
		}
		portNumber = toolBusConnectionHandler.getPort();
		
		Thread tbConnectionHandler = new Thread(toolBusConnectionHandler);
		tbConnectionHandler.setName("ToolBus connection handler");
		tbConnectionHandler.start();
		
		System.out.println("The ToolBus server allocated port (" + portNumber + ")");
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
						
						long blockTime = nextTime - getRunTime(); // Recalculate the delay before
																	// sleeping.
						if(blockTime > 0){
							try{
								processLock.wait(blockTime);
							}catch(InterruptedException irex){
								// Just ignore this, it's not harmfull.
							}
							workHasArrived = true;
						}else if(currentNextTime != nextTime){ // if the nextTime changed and the
																// blockTime is zero or less, don't
																// block as there might be work to
																// do.
							workHasArrived = true;
							currentNextTime = nextTime;
						}else{
							try{
								processLock.wait();
							}catch(InterruptedException irex){
								// Just ignore this, it's not harmfull.
							}
						}
						
						if(shuttingDown) return; // Stop executing if a shutdown is triggered.
					}
					currentNextTime = nextTime;
					
					if(doStep)
						fireStateChange(IViewerConstants.STEPPING_STATE);
					else if(doRun)
						fireStateChange(IViewerConstants.RUNNING_STATE);
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
						reset = false; // We might start iterating in the middle of the
										// collections, so ensure we do at least a full one if we're
										// running.
					}
					
					while(processesIterator.hasNext() && (doRun || doStep)){
						if(shuttingDown){
							return;
						}
						
						pi = processesIterator.next();
						StateElement executedStateElement = pi.debugStep();
						boolean stepSuccessFull = (executedStateElement != null);
						
						String processName = pi.getProcessName();
						int processId = pi.getProcessId();
						if(!doStep){
							if(stepSuccessFull){
								if(processInstanceBreakPoints.contains(new Integer(processId)) || processBreakPoints.contains(processName)){
									viewer.processBreakPointHit(pi);
								}
								if(stateElementBreakPoints.contains(executedStateElement)){
									viewer.stateElementBreakPointHit(executedStateElement);
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
							if(doStep){
								doStep = false; // Consume the step.
								viewer.stepExecuted(pi, executedStateElement);
								break WORKLOOP;
							}
						}
					}
				}while((doRun && (work || !reset)) || (doStep && !reset));
				workHasArrived |= work; // If we did something, set this to ensure we can release
										// the lock when needed.
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
	public void workArrived(){
		if(!workHasArrived){
			synchronized(processLock){
				fireStateChange(IViewerConstants.READY_STATE);
				
				workHasArrived = true;
				
				processLock.notify();
			}
		}
	}
	
	/**
	 * Notifies the debug toolbus that it should execute normally.
	 */
	public void doRun(){
		synchronized(processLock){
			workHasArrived = true; // This should not be needed; it's just here to ensure we will
									// escape the wait loop.
			
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
			workHasArrived = true; // This should not be needed; it's just here to ensure we will
									// escape the wait loop.
			
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
		synchronized(processLock){
			shutdown(TBTermFactory.getInstance().EmptyList);
			
			processLock.notify();
		}
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
}
