package nl.cwi.bus.server;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import nl.cwi.bus.variable.FinalizableVariable;
import nl.cwi.util.logging.Logger;

/**
 * A queue containing all (to the toolbus or internally) send messages.
 * 
 * @author Arnold Lankamp
 */
public class MessageQueue{
	private final Object lock = new Object();
	
	private List messages = null;
	
	private Map subscriptions = null;
	
	/**
	 * Default constructor.
	 */
	public MessageQueue(){
		super();
		
		messages = new ArrayList();
		
		subscriptions = new HashMap();
	}
	
	/**
	 * Adds a message, in the form of a variable, to this queue.
	 * @param message The variable to add.
	 */
	public synchronized void add(FinalizableVariable message){
		synchronized(lock){
			messages.add(message);
			lock.notify();
		}
	}
	
	/**
	 * Checks if this collection is empty.
	 * @return True if this collection is empty; false otherwise.
	 */
	public boolean isEmpty(){
		return (messages.size() == 0);
	}
	
	/**
	 * Returns the first message from this collection and deletes it. Returns null if this collection is empty.
	 * @return The first message from this collection; null if this collection is empty.
	 */
	public FinalizableVariable getFirst(){
		FinalizableVariable variable = null;
		synchronized(lock){
			if(isEmpty()){
				try{
					lock.wait();
				}catch(InterruptedException irex){
					Logger.getInstance().log("Interrupted While waiting for lock in MessageQueue.getFirst()", Logger.ERROR, irex);
					throw new RuntimeException(irex);
				}
			}
			
			variable = (FinalizableVariable)messages.get(0);
			messages.remove(0);
		}
		
		return variable;
	}
	
	/**
	 * Subscribes the process instance for notes with the given signature.
	 * @param processInstance The process instance that needs to be subscribed.
	 * @param signature The signature of the note.
	 */
	public void subscribe(AbstractProcessInstance processInstance, String signature){
		synchronized(subscriptions){
			List registeredProcessInstances = null;
			if(subscriptions.containsKey(signature)){
				registeredProcessInstances = (List)subscriptions.get(signature);
				
				registeredProcessInstances.add(processInstance);
			}else{
				registeredProcessInstances = new ArrayList();
				
				registeredProcessInstances.add(processInstance);
				subscriptions.put(signature, registeredProcessInstances);
			}
		}
	}
	
	/**
	 * Unsubscribes the process instance for notes with the given signature.
	 * @param processInstance The process instance that needs to be unsubscribed.
	 * @param signature The signature of the note.
	 */
	public void unsubscribe(AbstractProcessInstance processInstance, String signature){
		synchronized(subscriptions){
			List registeredProcessInstances = (List)subscriptions.get(signature);
			if(registeredProcessInstances != null){
				registeredProcessInstances.remove(processInstance);
			}
		}
	}
	
	/**
	 * Broadcasts the given note to all the subscribed process instances.
	 * @param note The note that needs to be broadcast.
	 */
	public void sendNote(FinalizableVariable note){
		String signature = note.getVariable().getSignature();
		
		if(subscriptions.containsKey(signature)){
			List registeredProcessInstances = (List)subscriptions.get(signature);
			for(int i = 0; i < registeredProcessInstances.size(); i++){
				AbstractProcessInstance processInstance = (AbstractProcessInstance)registeredProcessInstances.get(i);
				processInstance.receiveNote(note);
			}
		}
	}
}
