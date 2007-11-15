package toolbus.viewer;

import java.io.IOException;
import java.util.Collections;

import aterm.ATerm;
import aterm.ATermList;

import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessInstance;
import toolbus.util.collections.ConcurrentHashSet;

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
	
	private long nextTime;
	
	public DebugToolBus(String[] args, IViewer viewer){
		super(args);
		
		this.viewer = viewer;
		
		processInstanceBreakPoints = new ConcurrentHashSet<Integer>();
		processBreakPoints = new ConcurrentHashSet<String>();
		
		nextTime = 0;
	}
	
	public ProcessInstance addProcess(String name, ATermList actuals) throws ToolBusException{
		ProcessInstance pi = super.addProcess(name, actuals);
		viewer.processInstanceAdded(pi);
		return pi;
	}
	
	public ProcessInstance addProcess(ProcessCall call) throws ToolBusException{
		ProcessInstance pi = super.addProcess(call);
		viewer.processInstanceAdded(pi);
		return pi;
	}
	
	public void shutdown(ATerm msg){
		super.shutdown(msg);
		
		running = false;
		
		synchronized(processLock){
			processLock.notify();
		}
	}
	
	public void setNextTime(long next){
		//System.err.println("setNextTime: " + next);
		long currentTime = getRunTime();
		if(nextTime < currentTime || (next < nextTime && next > currentTime)){
			nextTime = next;
		}
		//System.err.println("setNextTime: set to " + nextTime);
	}
	
	public void execute(){
		if(nerrors > 0){
			System.err.println("ToolBus cannot continue execution due to errors in Tscript");
			return;
		}
		
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
		
		System.out.println("The ToolBus server allocated port ("+portNumber+")");
		ProcessInstance P = null;
		ProcessInstanceIterator processesIterator = new ProcessInstanceIterator(processes);
		running = true;
		try{
			boolean work = false;
			boolean reset = false;
			long currentNextTime = 0;
			workHasArrived = true; // This is just to get things started.
			
			PROCESSLOOP: do{
				synchronized(processLock){
					if(doStep){
						doStep = false; // Consume the step.
						viewer.update(P);
					}
					
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
						}else if(currentNextTime != nextTime){ // if the nextTime changed and the blockTime is zero or less, don't block as there might be work to do.
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
					
					if(doStep) fireStateChange(IViewerConstants.STEPPING_STATE);
					else if(doRun) fireStateChange(IViewerConstants.RUNNING_STATE);
					else fireStateChange(IViewerConstants.UNKNOWN_STATE);
				}
				
				WORKLOOP : do{
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
							viewer.stop();
							return;
						}
						
						P = processesIterator.next();
						boolean stepSuccessFull = P.step();
						
						String processName = P.getProcessName();
						int processId = P.getProcessId();
						if(stepSuccessFull && (processInstanceBreakPoints.contains(new Integer(processId)) || processBreakPoints.contains(processName))){
							viewer.breakPointHit(processId);
						}
						
						if(P.isTerminated()){
							processesIterator.remove();
							P.terminate(tbfactory.EmptyList);
							
							viewer.processInstanceTerminated(P);
							
							if(processes.size() == 0) break PROCESSLOOP;
						}
						work |= stepSuccessFull;
						if(stepSuccessFull) break WORKLOOP;
					}
				}while((doRun && (work || !reset)) || (doStep && !work));
				workHasArrived |= work; // If we did something, set this to ensure we can release the lock when needed.
			}while(running);
		}catch(ToolBusException e){
			error("Process " + (P != null ? P.getProcessName() : "?"), e.getMessage());
			e.printStackTrace();
		}
		
		if(!shuttingDown) shutdown(tbfactory.make("ToolBus halted"));
		viewer.stop();
	}
	
	public void workArrived(){
		if(!workHasArrived){
			synchronized(processLock){
				fireStateChange(IViewerConstants.READY_STATE);
				
				workHasArrived = true;
				
				processLock.notify();
			}
		}
	}
	
	public void doRun(){
		synchronized(processLock){
			workHasArrived = true; // This should not be needed; it's just here to ensure we will escape the wait loop.
			
			doStep = false;
			doRun = true;
			
			fireStateChange(IViewerConstants.RUNNING_STATE);
			
			processLock.notify();
		}
	}
	
	public void doStop(){
		synchronized(processLock){
			fireStateChange(IViewerConstants.STOPPING_STATE);
			
			doRun = false;
			doStep = false;
			
			processLock.notify(); // This causes the state to be updated properly.
		}
	}
	
	public void doStep(){
		synchronized(processLock){
			workHasArrived = true; // This should not be needed; it's just here to ensure we will escape the wait loop.
			
			doRun = false;
			doStep = true;

			fireStateChange(IViewerConstants.STEPPING_STATE);
			
			processLock.notify();
		}
	}
	
	public void doTerminate(){
		synchronized(processLock){
			shutdown(TBTermFactory.getInstance().EmptyList);

			processLock.notify();
		}
	}
	
	private void fireStateChange(int state){
		if(state != currentState){
			currentState = state;
			viewer.updateState(state);
		}
	}
	
	public void addProcessInstanceBreakPoint(int processId){
		processInstanceBreakPoints.put(new Integer(processId));
	}
	
	public void removeProcessInstanceBreakPoint(int processId){
		processInstanceBreakPoints.remove(new Integer(processId));
	}
	
	public void addProcessBreakPoint(String processName){
		processBreakPoints.put(processName);
	}
	
	public void removeProcessBreakPoint(String processName){
		processBreakPoints.remove(processName);
	}
}
