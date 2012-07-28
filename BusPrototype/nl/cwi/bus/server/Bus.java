package nl.cwi.bus.server;

import java.util.Iterator;

import nl.cwi.bus.communication.operations.EndOperation;
import nl.cwi.bus.server.communication.MultiplexingServer;
import nl.cwi.bus.variable.AcknowledgeableVariables;
import nl.cwi.bus.variable.VariableFinalizationQueue;
import nl.cwi.util.logging.Logger;

/**
 * Main class of the bus architecture
 * 
 * @author Arnold Lankamp
 */
public class Bus extends Thread{
	private MultiplexingServer multiplexingServer = null;
	
	private VariableFinalizationQueue variableFinalizationQueue = null;
	private AcknowledgeableVariables acknowledgeableVariable = null;
	
	private MessageQueue messageQueue = null;

	private ProcessManager processManager = null;
	private ToolManager toolManager = null;

	private boolean running = false;

	/**
	 * Default constructor
	 */
	private Bus(){
		super();

		processManager = new ProcessManager();
		toolManager = new ToolManager();

		init();
	}

	/**
	 * Initializes the bus. (Starts the server communication)
	 */
	private void init(){
		// Start the multiplexing server so the tools can connect
		multiplexingServer = new MultiplexingServer();

		variableFinalizationQueue = new VariableFinalizationQueue();
		variableFinalizationQueue.start();
		
		acknowledgeableVariable = new AcknowledgeableVariables();
		
		messageQueue = new MessageQueue();
	}

	/**
	 * Returns the variable finalization queue.
	 * 
	 * @return The variable finalization queue.
	 */
	public VariableFinalizationQueue getVariableFinalizationQueue(){
		return variableFinalizationQueue;
	}
	
	/**
	 * Returns the collection of acknowledgeable variables.
	 * @return The collection of acknowledgeable variables.
	 */
	public AcknowledgeableVariables getAcknowledgeableVariables(){
		return acknowledgeableVariable;
	}
	
	/**
	 * Returns the messageQueue.
	 * @return The messageQueue.
	 */
	public MessageQueue getMessageQueue(){
		return messageQueue;
	}

	/**
	 * Returns a reference to the process manager
	 * 
	 * @return never null
	 */
	public ProcessManager getProcesses(){
		return processManager;
	}

	/**
	 * Returns a reference to the tool manager
	 * 
	 * @return never null
	 */
	public ToolManager getTools(){
		return toolManager;
	}

	/**
	 * The main loop of the coordiantion system
	 */
	public void run(){
		running = true;
		while(running){
			processManager.execute();
			Thread.yield();
		}
	}

	/**
	 * This nested class is to enforce lazy non-synchronized initialization of
	 * the instance of the bus.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class InstanceKeeper{
		private final static Bus instance = new Bus();
	}

	/**
	 * Returns a reference to the instance of the bus
	 * 
	 * @return a reference to the instance of the bus
	 */
	public static Bus getInstance(){
		return InstanceKeeper.instance;
	}

	/**
	 * Terminates the bus.
	 */
	public void terminate(){
		// Notify the connected tools of the shutdown.
		Iterator toolInstanceIterator = toolManager.getIterator();
		while(toolInstanceIterator.hasNext()){
			ToolInstance toolInstance = ((ToolInstance) toolInstanceIterator.next());
			toolInstanceIterator.remove();

			toolInstance.send(new EndOperation());
		}

		// Stop the bus.
		running = false;

		// Stop object finalization.
		variableFinalizationQueue.stopRunning();

		// Stop the communication channels.
		multiplexingServer.stopRunning();
	}

	/**
	 * Entrypoint
	 * 
	 * @param args
	 */
	public static void main(String[] args){
		Logger.getInstance().log("Bus is starting", Logger.INFO);
		Bus bus = Bus.getInstance();
		bus.start();
	}
}
