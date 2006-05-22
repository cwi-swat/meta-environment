package nl.cwi.term.serializable;

import nl.cwi.util.NativeTypeBuilder;

/**
 * Represents a term with a flexible length.
 * 
 * @author Arnold Lankamp
 */
public class FlexibleLengthTerm extends SerializableTerm{
	private byte[] isEmpty = null;
	private byte[] lengthField = null;
	private byte[] term = null;

	private Integer key = null;

	private int emptyPutIndex = -1;
	private int lengthPutIndex = -1;
	private int putIndex = -1;

	/**
	 * Default constructor.
	 */
	public FlexibleLengthTerm(){
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
	 * @param term
	 *            The term that should be stored in this serializable object.
	 */
	public FlexibleLengthTerm(String term){
		super();

		if(term != null){
			setState(term.getBytes());
		}else{
			setState(null);
		}
	}

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that should be stored in this serializable object.
	 */
	public FlexibleLengthTerm(byte[] term){
		super();

		setState(term);
	}
	
	private void setState(byte[] term){
		this.term = term;
		
		int termLength = 0;
		
		if(term != null){
			termLength = term.length;
		}
		
		isEmpty = new byte[]{NativeTypeBuilder.makeBytesFromBoolean(termLength == 0)};
		lengthField = NativeTypeBuilder.makeBytesFromInt(termLength);
		
		init();
		key = registerNativeType(termLength, term);

		emptyPutIndex = isEmpty.length;
		lengthPutIndex = lengthField.length;
		putIndex = termLength;
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
	 * @see SerializableTerm#put(byte[])
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
				term = new byte[NativeTypeBuilder.makeInt(lengthField)];
				key = registerNativeType(term.length, term);
			}
		}

		if(index < bytes.length){
			System.arraycopy(bytes, index, term, putIndex, bytes.length - index);

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
	 * @return True if this term contains an empty string; false otherwise.
	 */
	public boolean isEmpty(){
		return NativeTypeBuilder.makeBoolean(isEmpty);
	}
}
