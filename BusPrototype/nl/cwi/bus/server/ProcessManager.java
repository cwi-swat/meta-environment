package nl.cwi.bus.server;

import java.util.ArrayList;
import java.util.List;

import nl.cwi.bus.variable.FinalizableVariable;
import nl.cwi.util.logging.Logger;

/**
 * Contains the list of all the running processes
 * 
 * @author Arnold Lankamp
 */
public class ProcessManager{
	private List processes = null;

	/**
	 * Default constructor
	 */
	public ProcessManager(){
		super();

		processes = new ArrayList();
	}

	/**
	 * Registers a process
	 * 
	 * @param processInstance
	 *            The process instance to register
	 */
	public void register(AbstractProcessInstance processInstance){
		processes.add(processInstance);
	}

	/**
	 * Deregisters a process and terminates it. The termination should ensure
	 * that the reference count is savely decremented after it has become
	 * unreachable.
	 * 
	 * @param processInstance
	 *            The process instance to deregister
	 */
	public void deregister(AbstractProcessInstance processInstance){
		processes.remove(processInstance);

		// Terminate the process
		processInstance.terminate();
	}

	/**
	 * Executes the registered processes
	 */
	public void execute(){
		MessageQueue messageQueue = Bus.getInstance().getMessageQueue();
		FinalizableVariable variable = messageQueue.getFirst();

		if(variable != null){
			try{
				boolean handled = false;
				for(int i = 0; i < processes.size(); i++){
					AbstractProcessInstance processInstance = (AbstractProcessInstance) processes.get(i);
					
					handled = processInstance.step(variable);
					if(handled) break;
				}
				
				if(!handled){
					Logger.getInstance().log("Received a message with a signature that can't be handled by any process instance (at the moment): "+variable.getVariable().getSignature()+". This message will be requeued.", Logger.WARNING);
					messageQueue.add(variable);
				}
			}catch(RuntimeException rex){
				Logger.getInstance().log("A RuntimeException occurred while executing the process instances", Logger.ERROR, rex);
			}
		}

		variable.decrementReferenceCount();
	}
}
