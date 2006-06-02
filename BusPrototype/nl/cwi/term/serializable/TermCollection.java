package nl.cwi.term.serializable;

import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.serializable.SerializableObject;

/**
 * Represents a immutable collection of terms.
 * 
 * @author Arnold Lankamp
 */
public class TermCollection extends SerializableObject{
	private byte[] size = null;
	private TermConverter[] termConverters = null;

	/**
	 * Default contructor.
	 */
	public TermCollection(){
		super();
		
		this.size = new byte[NativeTypeBuilder.INTBYTES];
		
		registerNativeType(size.length, size);
	}
	
	/**
	 * Constructor.
	 * @param termConverters An array of termconverters containing references to the terms contained in this collection.
	 */
	public TermCollection(TermConverter[] termConverters){
		super();
		
		this.size = NativeTypeBuilder.makeBytesFromInt(termConverters.length);
		this.termConverters = termConverters;
		
		registerNativeType(size.length, size);
		for(int i = 0; i < termConverters.length; i++){
			register(termConverters[i]);
		}
	}
	
	public int size(){
		return termConverters.length;
	}
	
	public TermConverter getValue(int index){
		return termConverters[index];
	}
	
	/**
	 * @see SerializableObject#update()
	 */
	public void update(){
		if(termConverters == null && isBuild(size)){
			termConverters = new TermConverter[NativeTypeBuilder.makeInt(size)];
			for(int i = 0; i < termConverters.length; i++){
				termConverters[i] = new TermConverter();
				register(termConverters[i]);
			}
		}
		
		super.update();
	}
}
