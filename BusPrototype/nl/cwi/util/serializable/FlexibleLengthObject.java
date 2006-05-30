package nl.cwi.util.serializable;

import nl.cwi.util.NativeTypeBuilder;

/**
 * Represents an object with a flexible length.
 * 
 * @author Arnold Lankamp
 */
public class FlexibleLengthObject extends SerializableObject{
	// This empty field is a flag that can be set to false if we are
	// transferring a NULL object instead of an empty one.
	private byte[] isEmpty = null;
	private byte[] lengthField = null;
	private byte[] object = null;

	private Integer key = null;

	private int emptyPutIndex = -1;
	private int lengthPutIndex = -1;
	private int putIndex = -1;

	/**
	 * Default constructor.
	 */
	public FlexibleLengthObject(){
		super();

		isEmpty = new byte[NativeTypeBuilder.BOOLBITS];
		lengthField = new byte[NativeTypeBuilder.INTBYTES];

		init();

		emptyPutIndex = 0;
		lengthPutIndex = 0;
		putIndex = 0;
	}

	/**
	 * Constructor.
	 * 
	 * @param object
	 *            The object that should be stored in this serializable object.
	 */
	public FlexibleLengthObject(String object){
		super();

		if(object != null){
			setState(object.getBytes());
		}else{
			setState(null);
		}
	}

	/**
	 * Constructor.
	 * 
	 * @param object
	 *            The object that should be stored in this serializable object.
	 */
	public FlexibleLengthObject(byte[] object){
		super();

		setState(object);
	}

	private void setState(byte[] object){
		this.object = object;

		int objectLength = 0;

		if(object != null){
			objectLength = object.length;
		}

		isEmpty = new byte[] {NativeTypeBuilder.makeBytesFromBoolean(objectLength == 0)};
		lengthField = NativeTypeBuilder.makeBytesFromInt(objectLength);

		init();
		key = registerNativeType(objectLength, object);

		emptyPutIndex = isEmpty.length;
		lengthPutIndex = lengthField.length;
		putIndex = objectLength;
	}

	/**
	 * Initialized this term.
	 */
	private void init(){
		registerNativeType(NativeTypeBuilder.BOOLEAN, isEmpty);
		registerNativeType(lengthField.length, lengthField);
	}

	/**
	 * @see ISerializable#isValid()
	 */
	public boolean isValid(){
		return (emptyPutIndex + putIndex + lengthPutIndex) == length();
	}

	/**
	 * @see ISerializable#length()
	 */
	public int length(){
		int length = NativeTypeBuilder.INTBYTES + NativeTypeBuilder.BOOLBITS;
		if(lengthPutIndex == NativeTypeBuilder.INTBYTES){
			length += NativeTypeBuilder.makeInt(lengthField);
		}
		return length;
	}

	/**
	 * @see ISerializable#expectingBytes()
	 */
	public int expectingBytes(){
		int expecting = 0;

		if(emptyPutIndex != NativeTypeBuilder.BOOLBITS){
			expecting = (length() - emptyPutIndex);
		}else if(lengthPutIndex != NativeTypeBuilder.INTBYTES){
			expecting = (length() - lengthPutIndex);
		}else{
			expecting = (length() - putIndex - lengthPutIndex - emptyPutIndex);
		}

		return expecting;
	}

	/**
	 * @see SerializableObject#put(byte[])
	 */
	public synchronized void put(byte[] bytes){
		int index = 0;
		if(emptyPutIndex < isEmpty.length){
			int nrOfBytesToWrite = isEmpty.length - emptyPutIndex;
			if(nrOfBytesToWrite > bytes.length) nrOfBytesToWrite = bytes.length;

			System.arraycopy(bytes, index, isEmpty, emptyPutIndex, nrOfBytesToWrite);
			index += nrOfBytesToWrite;

			emptyPutIndex += nrOfBytesToWrite;
		}

		if(lengthPutIndex < lengthField.length && index < bytes.length){
			int nrOfBytesToWrite = lengthField.length - lengthPutIndex;
			if(nrOfBytesToWrite > (bytes.length - index)) nrOfBytesToWrite = (bytes.length - index);

			System.arraycopy(bytes, index, lengthField, lengthPutIndex, nrOfBytesToWrite);
			index += nrOfBytesToWrite;

			lengthPutIndex += nrOfBytesToWrite;

			if(lengthPutIndex == NativeTypeBuilder.INTBYTES){
				object = new byte[NativeTypeBuilder.makeInt(lengthField)];
				key = registerNativeType(object.length, object);
			}
		}

		if(index < bytes.length){
			System.arraycopy(bytes, index, object, putIndex, bytes.length - index);

			putIndex += (bytes.length - index);
		}
	}

	/**
	 * Returns the key associated with the registered flexible length term.
	 * 
	 * @return The key associated with the registered flexible length term (may
	 *         be null / uninitalized).
	 */
	public Integer getKey(){
		return key;
	}

	/**
	 * Checks if this term is empty or not.
	 * 
	 * @return True if this term contains an empty string; false otherwise.
	 */
	public boolean isEmpty(){
		return NativeTypeBuilder.makeBoolean(isEmpty);
	}

	/**
	 * Checks if this term has content.
	 * 
	 * @return True if it does; false if it is 'null'.
	 */
	public boolean hasContent(){
		return (!isEmpty());
	}
}
