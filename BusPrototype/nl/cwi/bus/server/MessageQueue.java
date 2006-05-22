package nl.cwi.bus.server;

import java.util.ArrayList;
import java.util.List;

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
	
	/**
	 * Default constructor.
	 */
	public MessageQueue(){
		super();
		
		messages = new ArrayList();
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
}
