package nl.cwi.util.serializable;

import java.util.ArrayList;
import java.util.List;

/**
 * Object that handles serializing and deserializing of the internal state of an
 * object.
 * 
 * @author Arnold Lankamp
 */
public class SerializableObject implements ISerializable{
	public final static int UNDEFINED = -1;

	private SerializableObject parent = null;

	private int putIndex = -1;

	private List order = null;

	/**
	 * Default constructor.
	 */
	public SerializableObject(){
		super();

		putIndex = 0;

		order = new ArrayList();
	}

	/**
	 * Sets the parent of this serializable object.
	 * 
	 * @param parent
	 *            The parent of this serializable object.
	 */
	private void setParent(SerializableObject parent){
		this.parent = parent;
	}

	/**
	 * Returns the parent of this serializable object.
	 * 
	 * @return The parent of this serializable object.
	 */
	protected SerializableObject getParent(){
		return parent;
	}

	/**
	 * Replaces the first occurence of the old object by the new object.
	 * 
	 * @param oldObject
	 *            The object that needs to be replaced.
	 * @param newObject
	 *            The object to replace it with.
	 */
	protected void replace(SerializableObject oldObject, SerializableObject newObject){
		synchronized(order){
			for(int i = 0; i < order.size(); i++){
				Object o = order.get(i);
				if(o == oldObject){
					order.set(i, newObject);
					break;
				}
			}
		}
	}

	/**
	 * Registers an object that is part of the state of the object.
	 * 
	 * @param serializableObject
	 *            The object that is part of the state of the object.
	 */
	protected void register(SerializableObject serializableObject){
		synchronized(order){
			serializableObject.setParent(this);
			order.add(serializableObject);
		}
	}

	/**
	 * Deregisters the given object (it will remove it's first occurence in case
	 * it has been added multiple times). NOTE: This method should not be called
	 * during the serialization or deserialization of this object, it might
	 * cause corruption.
	 * 
	 * @param serializableObject
	 *            The object that should be deregistered.
	 */
	protected void deregister(SerializableObject serializableObject){
		synchronized(order){
			order.remove(serializableObject);
		}
	}

	/**
	 * Returns an array containing all the child nodes of this serializable
	 * object.
	 * 
	 * @return An array containing all the child nodes of this serializable
	 *         object.
	 */
	protected SerializableObject[] getChildren(){
		List childrenCollection = new ArrayList();
		for(int i = 0; i < order.size(); i++){
			Object o = order.get(i);
			if(o instanceof SerializableObject){
				childrenCollection.add(o);
			}
		}
		Object[] objs = childrenCollection.toArray();
		SerializableObject[] children = new SerializableObject[objs.length];
		System.arraycopy(objs, 0, children, 0, children.length);

		return children;
	}

	/**
	 * Registers a native type that is part of the state of the object. Native
	 * types are registered as byte arrays.
	 * 
	 * @param o
	 *            The byte array, including content. May not be null.
	 */
	protected void registerNativeType(byte[] o){
		synchronized(order){
			order.add(o);
		}
	}

	/**
	 * @see ISerializable#get(int, int)
	 */
	public byte[] get(int offset, int length){
		if((offset + length) > length()) throw new IllegalArgumentException("Buffer underflow exception; "+(offset + length)+" (offset + length) > The size of the serialized representation of the object.");
	
		byte[] bytes = new byte[length];

		fill(offset, length, bytes, 0);

		return bytes;
	}

	/**
	 * Fills the given bytes array with content.
	 * 
	 * @param offset
	 *            The point at with to start serializing.
	 * @param length
	 *            The number of bytes to serialize.
	 * @param target
	 *            The byte array to put the bytes in.
	 * @param index
	 *            The index we are currently at in the byte array.
	 * @return The number of bytes that was written into the array.
	 */
	private int fill(int offset, int length, byte[] target, int index){
		// Find the object and the position associated with the object
		int position = 0;
		Object o = null;
		for(int i = 0; i < order.size(); i++){
			o = order.get(i);

			if(position == offset){
				break;
			}

			int objectLength = 0;
			if(o instanceof ISerializable){
				objectLength = ((ISerializable) o).length();
			}else{
				objectLength = ((byte[]) o).length;
			}

			int newPosition = position + objectLength;
			if(newPosition > offset){
				break;
			}
			position = newPosition;
		}

		// Determine where to start reading in the object
		int startIndex = offset - position;

		// Get the data from the object
		int gotten = 0;
		if(o instanceof SerializableObject){
			SerializableObject serialiazableObject = ((SerializableObject) o);
			int objectLength = serialiazableObject.length();

			if((startIndex + length) < objectLength){
				gotten = serialiazableObject.fill(startIndex, length, target, index);
			}else{
				gotten = serialiazableObject.fill(startIndex, serialiazableObject.length() - startIndex, target, index);
			}
		}else{
			byte[] byteArray = (byte[]) o;
			byte[] bytesGotten = null;
			if(byteArray.length < (startIndex + length)){
				bytesGotten = new byte[byteArray.length - startIndex];
				System.arraycopy(byteArray, startIndex, bytesGotten, 0, bytesGotten.length);
			}else{
				bytesGotten = new byte[length];
				System.arraycopy(byteArray, startIndex, bytesGotten, 0, bytesGotten.length);
			}
			System.arraycopy(bytesGotten, 0, target, index, bytesGotten.length);
			gotten = bytesGotten.length;
		}

		int newIndex = index + gotten;

		// If we need to read more data, do it.
		int bytesLeft = length - gotten;
		if(bytesLeft > 0){
			gotten += fill(offset + gotten, bytesLeft, target, newIndex);
		}

		return gotten;
	}

	/**
	 * @see ISerializable#length()
	 */
	public int length(){
		int length = 0;
		for(int i = 0; i < order.size(); i++){
			Object o = order.get(i);

			if(o instanceof SerializableObject){
				SerializableObject serializableObject = (SerializableObject) o;
				length += serializableObject.length();
			}else{
				int size = ((byte[]) o).length;
				length += size;
			}
		}

		return length;
	}

	/**
	 * @see ISerializable#expectingBytes()
	 */
	public int expectingBytes(){
		return (length() - putIndex);
	}

	/**
	 * @see ISerializable#isValid()
	 */
	public boolean isValid(){
		return (putIndex == length());
	}

	/**
	 * @see ISerializable#put(byte[])
	 */
	public synchronized void put(byte[] bytes){
		// Refuse to do something useless.
		if(bytes.length == 0) return;

		// Find the object and the position associated with the object.
		int position = 0;
		Object o = null;
		for(int i = 0; i < order.size(); i++){
			o = order.get(i);

			if(position == putIndex) break;

			int objectLength = 0;
			if(o instanceof ISerializable){
				objectLength = ((ISerializable) o).length();
			}else{
				objectLength = ((byte[]) o).length;
			}

			int newPosition = position + objectLength;
			if(newPosition > putIndex) break;
			position = newPosition;
		}

		// Determine where to start reading in the object.
		int startIndex = putIndex - position;

		// Write the bytes.
		int bytesToWrite = 0;
		if(o instanceof ISerializable){
			SerializableObject serialiazableObject = ((SerializableObject) o);

			bytesToWrite = serialiazableObject.expectingBytes();
			if(bytesToWrite > bytes.length) bytesToWrite = bytes.length;

			byte[] byteArray = new byte[bytesToWrite];
			System.arraycopy(bytes, 0, byteArray, 0, bytesToWrite);
			serialiazableObject.put(byteArray);
		}else{
			byte[] byteArray = (byte[]) o;

			bytesToWrite = (byteArray.length - startIndex);
			if(bytesToWrite > bytes.length) bytesToWrite = bytes.length;

			System.arraycopy(bytes, 0, byteArray, startIndex, bytesToWrite);
		}

		putIndex += bytesToWrite;

		update();

		if(bytesToWrite == 0) throw new RuntimeException("Bytenumber overflow");

		if(bytesToWrite < bytes.length){
			byte[] additionalBytes = new byte[bytes.length - bytesToWrite];
			System.arraycopy(bytes, bytesToWrite, additionalBytes, 0, additionalBytes.length);
			put(additionalBytes);
		}
	}

	/**
	 * Checks if the given bytes array has been build or not.
	 * 
	 * @param bytes
	 *            The byte array for which we need to check if it's build/
	 * @return True if the byte array has been build; false otherwise.
	 */
	protected boolean isBuild(byte[] bytes){
		boolean build = false;

		int position = 0;
		for(int i = 0; i < order.size(); i++){
			Object o = order.get(i);

			int objectLength = 0;
			if(o instanceof ISerializable){
				objectLength = ((ISerializable) o).length();
			}else{
				objectLength = ((byte[]) o).length;
			}

			position += objectLength;

			if(bytes == o){
				if(position <= putIndex){
					build = true;
				}else{
					build = false;
				}
			}
		}

		return build;
	}

	/**
	 * Updated this serialized object. This method is called after new data has
	 * been added through a call to the put method. This method may be
	 * overridden in a subclass, but should always call super.update().
	 */
	protected void update(){
	// Intentionally left blank; this is intented by design.
	}
}
