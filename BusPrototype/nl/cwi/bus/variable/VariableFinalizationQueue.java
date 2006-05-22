package nl.cwi.bus.variable;

import java.util.ArrayList;
import java.util.List;

import nl.cwi.bus.communication.operations.FinOperation;
import nl.cwi.bus.server.Bus;
import nl.cwi.bus.server.ToolInstance;
import nl.cwi.bus.server.ToolManager;
import nl.cwi.util.logging.Logger;

/**
 * This queue contains all the variables who where garbage collected recently
 * and are awaiting a finalization message to be send to the source tool. It is
 * nessacary to do this in a seperate thread because we do not want the garbage
 * collector to block the execution of this application untill it is finally
 * finished executing all the finalizers.
 * 
 * @author Arnold Lankamp
 */
public class VariableFinalizationQueue extends Thread{
	private final Object lock = new Object();

	private boolean running = false;

	private List finalizedVariables = null;

	/**
	 * Default constructor.
	 */
	public VariableFinalizationQueue(){
		super();

		finalizedVariables = new ArrayList();
	}

	/**
	 * Adds a variable to this finalization queue.
	 * 
	 * @param variable
	 *            the variable whos finalizer was called.
	 */
	public void add(Variable variable){
		finalizedVariables.add(variable);
	}

	/**
	 * Returns the lock this finalizationqueue is waiting for.
	 * 
	 * @return The lock this finalizationqueue is waiting for.
	 */
	public Object getLock(){
		return lock;
	}

	/**
	 * Main loop of this thread. It waits for a notification from the garbage
	 * collector; when it receives one it will start to send FIN messages for
	 * all the collected variables.
	 */
	public void run(){
		running = true;
		while(running){
			synchronized(lock){
				try{
					lock.wait();
				}catch(InterruptedException irex){
					Logger.getInstance().log("Interrupted while waiting for lock.", Logger.WARNING, irex);
				}
			}
			
			ToolManager toolManager = Bus.getInstance().getTools();
			for(int i = finalizedVariables.size() -1; i >= 0; i--){
				Variable variable = (Variable) finalizedVariables.get(i);
				long variableID = variable.getVariableID();

				ToolInstance toolInstance = toolManager.getToolInstance(variable.getSourceToolID());
				toolInstance.send(new FinOperation(variableID));
				
				finalizedVariables.remove(i);
			}
		}
	}

	/**
	 * Stops this thread.
	 */
	public void stopRunning(){
		running = false;
		synchronized(lock){
			lock.notify();
		}
	}
	
	
}
