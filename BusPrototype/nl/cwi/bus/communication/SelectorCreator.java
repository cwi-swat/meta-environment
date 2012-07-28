package nl.cwi.bus.communication;

import java.io.IOException;
import java.nio.channels.Selector;

import nl.cwi.util.logging.Logger;

/**
 * Container for the selector including the lock I need because of Suns crappy
 * design. This class will initialize one selector upon creation. This selector
 * can be used in conjunction with the associated lock, also contained in this
 * object.
 * 
 * @author Arnold Lankamp
 */
public class SelectorCreator{
	private Selector selector = null;
	private Object selectionPreventionLock = new Object();

	/**
	 * Default constructor
	 */
	public SelectorCreator(){
		super();

		try{
			selector = Selector.open();
		}catch(IOException ioex){
			Logger.getInstance().log("An IOException occured while initializing the selector.", Logger.ERROR, ioex);
		}
	}

	/**
	 * Returns the selector.
	 * 
	 * @return The selector.
	 */
	public Selector getSelector(){
		return selector;
	}

	/**
	 * Returns a lock on which can be synchronated. The result of synchronating
	 * on this lock is that it will prevent from a select() to occur up untill
	 * it is released. This may be nessacary in combination with wakeup +
	 * register (because Suns design for the selector is retarded).
	 * 
	 * @return The selection prevention lock.
	 */
	public Object getSelectionPreventionLock(){
		return selectionPreventionLock;
	}
}
