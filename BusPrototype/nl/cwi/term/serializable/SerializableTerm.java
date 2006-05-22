package nl.cwi.term.serializable;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Object that handles serializing and deserializing of the internal state of an
 * object.
 * 
 * @author Arnold Lankamp
 */
public class SerializableTerm implements ISerializable{
	public final static int UNDEFINED = -1;
	public final static Integer ISERIALIZABLELENGTHVALUE = new Integer(0);

	private int putIndex = -1;

	private List sizes = null;
	private Map mappings = null;

	/**
	 * Default constructor.
	 */
	public SerializableTerm(){
		super();

		putIndex = 0;

		sizes = new ArrayList();
		mappings = new HashMap();
	}

	/**
	 * Registers an object that is part of the state of the object.
	 * 
	 * @param serializableObject
	 *            The object that is part of the state of the object.
	 * @return The key associated with the serializable object.
	 */
	protected Integer register(ISerializable serializableObject){
		int index = -1;
		synchronized(sizes){
			index = sizes.size();
			sizes.add(ISERIALIZABLELENGTHVALUE);
		}

		Integer key = new Integer(index);
		mappings.put(key, serializableObject);

		return key;
	}

	/**
	 * Registers a native type that is part of the state of the object. Native
	 * types are registered as byte arrays.
	 * 
	 * @param length
	 *            The length of the byte array.
	 * @param o
	 *            The byte array, including content; or null in case the object
	 *            hasn't been builded yet.
	 * @return The key associated with the serializable object.
	 */
	protected Integer registerNativeType(int length, byte[] o){
		int index = -1;
		synchronized(sizes){
			index = sizes.size();
			sizes.add(new Integer(length));
		}

		Integer key = new Integer(index);
		mappings.put(key, o);

		return key;
	}

	/**
	 * @see ISerializable#get(int, int)
	 */
	public byte[] get(int offset, int length){
		if((offset + length) > length()) throw new IllegalArgumentException("Buffer underflow exception; (offset + length) > The size of the serialized representation of the object.");

		byte[] bytes = new byte[length];

		// Find the object and the position associated with the object
		int position = 0;
		Object o = null;
		for(int i = 0; i < sizes.size(); i++){
			Integer size = ((Integer) sizes.get(i));

			o = mappings.get(new Integer(i));

			if(position == offset){
				break;
			}

			int objectLength = 0;
			if(o instanceof ISerializable){
				objectLength = ((ISerializable) o).length();
			}else{
				objectLength = size.intValue();
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
		byte[] bytesGotten = null;
		if(o instanceof ISerializable){
			ISerializable serialiazableObject = ((ISerializable) o);
			int objectLength = serialiazableObject.length();

			if(objectLength < length){
				bytesGotten = serialiazableObject.get(startIndex, objectLength);
			}else{
				bytesGotten = serialiazableObject.get(startIndex, length);
			}
		}else{
			byte[] byteArray = (byte[]) o;
			if(byteArray.length < (startIndex + length)){
				bytesGotten = new byte[byteArray.length - startIndex];
				System.arraycopy(byteArray, startIndex, bytesGotten, 0, bytesGotten.length);
			}else{
				bytesGotten = new byte[length];
				System.arraycopy(byteArray, startIndex, bytesGotten, 0, bytesGotten.length);
			}
		}
		System.arraycopy(bytesGotten, 0, bytes, 0, bytesGotten.length);

		// If we need to read more data, do it.
		int bytesLeft = length - bytesGotten.length;
		if(bytesLeft > 0){
			byte[] additionalBytes = get(offset + bytesGotten.length, bytesLeft);
			System.arraycopy(additionalBytes, 0, bytes, bytesGotten.length, additionalBytes.length);
		}

		return bytes;
	}

	/**
	 * @see ISerializable#length()
	 */
	public int length(){
		int length = 0;
		for(int i = 0; i < sizes.size(); i++){
			Integer size = ((Integer) sizes.get(i));

			if(size.intValue() == ISERIALIZABLELENGTHVALUE.intValue()){
				ISerializable serializableObject = (ISerializable) mappings.get(new Integer(i));
				length += serializableObject.length();
			}else{
				length += size.intValue();
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
		int size = 0;
		Integer key = null;
		for(int i = 0; i < sizes.size(); i++){
			size = ((Integer) sizes.get(i)).intValue();

			key = new Integer(i);
			o = mappings.get(key);

			if(position == putIndex) break;

			int objectLength = 0;
			if(o instanceof ISerializable){
				objectLength = ((ISerializable) o).length();
			}else{
				objectLength = size;
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
			ISerializable serialiazableObject = ((ISerializable) o);

			bytesToWrite = serialiazableObject.expectingBytes();
			if(bytesToWrite > bytes.length) bytesToWrite = bytes.length;
			
			byte[] byteArray = new byte[bytesToWrite];
			System.arraycopy(bytes, 0, byteArray, 0, bytesToWrite);
			serialiazableObject.put(byteArray);

			mappings.put(key, serialiazableObject);
		}else{
			byte[] byteArray = null;
			if(o == null){
				byteArray = new byte[size];
			}else{
				byteArray = (byte[]) o;
			}

			bytesToWrite = (byteArray.length - startIndex);
			if(bytesToWrite > bytes.length) bytesToWrite = bytes.length;

			System.arraycopy(bytes, 0, byteArray, startIndex, bytesToWrite);

			mappings.put(key, byteArray);
		}
		
		if(bytesToWrite == 0) throw new RuntimeException("Bytenumber overflow");

		putIndex += bytesToWrite;

		if(bytesToWrite < bytes.length){
			byte[] additionalBytes = new byte[bytes.length - bytesToWrite];
			System.arraycopy(bytes, bytesToWrite, additionalBytes, 0, additionalBytes.length);
			put(additionalBytes);
		}
	}

	/**
	 * @see ISerializable#getContent(Integer)
	 */
	public byte[] getContent(Integer key){
		return (byte[]) mappings.get(key);
	}
}
