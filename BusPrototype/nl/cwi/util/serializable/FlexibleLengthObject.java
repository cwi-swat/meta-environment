package nl.cwi.util.serializable;

import nl.cwi.util.NativeTypeBuilder;

/**
 * Represents an object with a flexible length.
 * 
 * @author Arnold Lankamp
 */
public final class FlexibleLengthObject extends SerializableObject{
	// This empty field is a flag that can be set to true if we are
	// transferring a NULL object.
	private byte[] isNull = null;
	private byte[] lengthField = null;
	private byte[] object = null;

	/**
	 * Default constructor.
	 */
	public FlexibleLengthObject(){
		super();

		isNull = new byte[NativeTypeBuilder.BOOLBITS];
		lengthField = new byte[NativeTypeBuilder.INTBYTES];

		init();
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
		int objectLength = 0;
		if(object != null){
			objectLength = object.length;
		}

		isNull = new byte[]{NativeTypeBuilder.makeBytesFromBoolean(object == null)};
		lengthField = NativeTypeBuilder.makeBytesFromInt(objectLength);

		init();
		
		if(object != null){
			this.object = object;
		}else{
			this.object = new byte[0];
		}
		registerNativeType(this.object.length, this.object);
	}

	/**
	 * Initialized this term.
	 */
	private void init(){
		registerNativeType(isNull.length, isNull);
		registerNativeType(lengthField.length, lengthField);
	}

	/**
	 * Updates this term.
	 */
	protected void update(){
		if(object == null && isBuild(lengthField)){
			object = new byte[NativeTypeBuilder.makeInt(lengthField)];
			registerNativeType(object.length, object);
		}
	}

	/**
	 * Returns The content of this object represented as byte array.
	 * @return The content of this object represented as byte array.
	 */
	public byte[] getContent(){
		return object;
	}

	/**
	 * Checks if this term is null or not.
	 * 
	 * @return True if it is; false otherwise.
	 */
	public boolean isNull(){
		return NativeTypeBuilder.makeBoolean(isNull);
	}
	
	/**
	 * @see ISerializable#isValid()
	 */
	public boolean isValid(){
		return (super.isValid() && object != null);
	}
}
