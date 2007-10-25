package toolbus.viewer;

import java.io.IOException;
import java.util.Collections;

import aterm.ATerm;

import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.process.ProcessInstance;

public class DebugToolBus extends ToolBus{
	public final static int UNKNOWN_STATE = -1;
	public final static int STOPPING_STATE = 0;
	public final static int WAITING_STATE = 1;
	public final static int READY_STATE = 2;
	public final static int RUNNING_STATE = 3;
	public final static int STEPPING_STATE = 4;
	
	private volatile int currentState = UNKNOWN_STATE;
	
	private volatile boolean running = false;
	private final Object processLock = new Object();
	private volatile boolean workHasArrived = false;
	
	private volatile boolean doRun = false;
	private volatile boolean doStep = false;
	
	private final Viewer viewer;
	
	public DebugToolBus(String[] args, Viewer viewer){
		super(args);
		
		this.viewer = viewer;
	}
	
	public void shutdown(ATerm msg){
		super.shutdown(msg);
		
		running = false;
		
		synchronized(processLock){
			processLock.notify();
		}
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
		
		//System.err.println("ToolBus execution starts ...\n");
		System.err.println("The ToolBus server allocated port ("+portNumber+")");
		ProcessInstance P = null;
		ProcessInstanceIterator processesIterator = new ProcessInstanceIterator(processes);
		running = true;
		try{
			boolean work = false;
			workHasArrived = true; // This is just to get things started.
			
			PROCESSLOOP: do{
				synchronized(processLock){
					if(doStep){
						doStep = false; // Consume the step.
						viewer.update(P);
					}
					
					while((!workHasArrived && running) || !(doStep || doRun)){
						fireStateChange(WAITING_STATE);
						
						try{
							processLock.wait();
						}catch(InterruptedException irex){
							// Just ignore this, it's not harmfull.
						}
						
						if(shuttingDown) return; // Stop executing if a shutdown is triggered.
					}
					
					if(doStep) fireStateChange(STEPPING_STATE);
					else if(doRun) fireStateChange(RUNNING_STATE);
					else fireStateChange(UNKNOWN_STATE);
				}
				
				do{
					work = false;
					workHasArrived = false;
					
					if(processesIterator.hasNext()){
						while(processesIterator.hasNext() && (doRun || (doStep && !work))){
							if(shuttingDown){
								viewer.stop();
								return;
							}
							
							P = processesIterator.next();
							work |= P.step();
							if(P.isTerminated()){
								processesIterator.remove();
								P.terminate(tbfactory.EmptyList);
								
								if(processes.size() == 0) break PROCESSLOOP;
							}
						}
					}else{
						processesIterator.reset();
						Collections.rotate(processes, 1);
						
						if(doRun) work = true;
					}
				}while((doRun && work) || (doStep && !work));
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
			fireStateChange(READY_STATE);
			
			synchronized(processLock){
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
			
			fireStateChange(RUNNING_STATE);
			
			processLock.notify();
		}
	}
	
	public void doStop(){
		fireStateChange(STOPPING_STATE);
		
		synchronized(processLock){
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

			fireStateChange(STEPPING_STATE);
			
			processLock.notify();
		}
	}
	
	public void doTerminate(){
		synchronized(processLock){
			shutdown(TBTermFactory.getInstance().EmptyList);

			processLock.notify();
		}
	}
	
	public void fireStateChange(int state){
		if(state != currentState){
			currentState = state;
			viewer.updateState(state);
		}
	}
}
