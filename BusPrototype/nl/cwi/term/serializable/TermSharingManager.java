package nl.cwi.term.serializable;

import java.util.HashMap;
import java.util.Map;

import nl.cwi.util.serializable.SerializableObject;

/**
 * This class supplies functionality for (de-)serializing objects.
 * 
 * @author Arnold Lankamp
 */
public class TermSharingManager extends SerializableObject{
	private static ThreadLocal sharedObjects = new ThreadLocal();

	private AbstractTerm rootNode = null;
	private Map shared = null;

	/**
	 * Constructor.
	 * 
	 * @param rootNode
	 *            The rootNode of the term.
	 */
	public TermSharingManager(AbstractTerm rootNode){
		super();

		this.rootNode = rootNode;

		shared = new HashMap();
	}

	/**
	 * Returns the shared objects map we are currently working with.
	 * 
	 * @return The shared objects map we are currently working with.
	 */
	public static Map getShared(){
		return (Map) sharedObjects.get();
	}

	/**
	 * Sets the current shared objects map.
	 * 
	 * @param shared
	 *            The shared objects map that should be used.
	 */
	private static void setShared(Map shared){
		sharedObjects.set(shared);
	}

	/**
	 * Inserts a serializable object into the pool of shared objects.
	 * 
	 * @param term
	 *            The term object that should be added to the shared objects
	 *            pool.
	 * @return The identifier of the shared object.
	 */
	public static Long insertIntoShared(AbstractTerm term){
		Map shared = getShared();
		
		Long key = null;
		if(!shared.containsValue(term)){
			key = new Long(shared.size());
			shared.put(key, term);
		}
		return key;
	}

	/**
	 * @param key
	 *            The key associated with the shared object we want to retrieve.
	 * @return The object we wanted to retrieve.
	 */
	public static SerializableObject getSharedObject(long key){
		Map shared = getShared();
		
		Object object = shared.get(new Long(key));
		AbstractTerm term = null;
		if(object != null) term = (AbstractTerm) object;

		return term;
	}

	/**
	 * Inserts the array of bytes into the given array of bytes.
	 * 
	 * @param bytes
	 *            The bytes that need to be inserted.
	 */
	public synchronized void put(byte[] bytes){
		setShared(shared);
		rootNode.put(bytes);
	}
}
