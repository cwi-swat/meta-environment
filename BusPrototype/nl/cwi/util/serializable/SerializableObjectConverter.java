package nl.cwi.util.serializable;

import java.util.HashMap;
import java.util.Map;

/**
 * This class supplies functionality for (de-)serializing objects.
 * 
 * @author Arnold Lankamp
 */
public class SerializableObjectConverter extends SerializableObject{
	private ThreadLocal sharedObjects = new ThreadLocal();

	/**
	 * Constructor.
	 */
	public SerializableObjectConverter(){
		super();

		resetShared();
	}

	/**
	 * Creates a new map made for containing references to shared objects.
	 * 
	 * @return A new map made for containing references to shared objects.
	 */
	private Map createShared(){
		return new HashMap();
	}

	/**
	 * Returns the shared objects map we are currently working with.
	 * 
	 * @return The shared objects map we are currently working with.
	 */
	public Map getShared(){
		return (Map) sharedObjects.get();
	}

	/**
	 * Sets the current shared objects map.
	 * 
	 * @param shared
	 *            The shared objects map that should be used.
	 */
	private void setShared(Map shared){
		sharedObjects.set(shared);
	}

	/**
	 * Resets the shared objects map.
	 */
	public void resetShared(){
		setShared(createShared());
	}

	/**
	 * Inserts a serializable object into the pool of shared objects.
	 * 
	 * @param serializableObject
	 *            The serialized object that should be added to the shared
	 *            objects pool.
	 * @return The identifier of the shared object.
	 */
	public Integer insertIntoShared(SerializableObject serializableObject){
		Map shared = getShared();

		Integer key = null;
		if(!shared.containsValue(serializableObject)){
			key = new Integer(shared.size());
			shared.put(key, serializableObject);
		}
		return key;
	}

	/**
	 * @param key
	 *            The key associated with the shared object we want to retrieve.
	 * @return The object we wanted to retrieve.
	 */
	public SerializableObject getSharedObject(Integer key){
		Map shared = getShared();
		
		Object object = shared.get(key);
		SerializableObject serializableObject = null;
		if(object != null) serializableObject = (SerializableObject) object;
		
		return serializableObject;
	}

	/**
	 * Inserts the array of bytes into the given array of bytes.
	 * 
	 * @param rootNode
	 *            The serialized object to insert the bytes into.
	 * @param shared
	 *            The map containing the shared objects.
	 * @param bytes
	 *            The bytes that need to be inserted.
	 */
	public synchronized void put(SerializableObject rootNode, Map shared, byte[] bytes){
		setShared(shared);
		rootNode.put(bytes);
	}

	/**
	 * Nested class with as purpose to ensure lazy non-synchronized
	 * initialization of this class.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class InstanceKeeper{
		public final static SerializableObjectConverter instance = new SerializableObjectConverter();
	}

	/**
	 * Returns a reference to the instance of this singleton.
	 * 
	 * @return A reference to the instance of this singleton.
	 */
	public static SerializableObjectConverter getInstance(){
		return InstanceKeeper.instance;
	}
}
