package nl.cwi.term.serializable;

import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.serializable.SerializableObject;

/**
 * Represents a immutable collection of terms.
 * 
 * @author Arnold Lankamp
 */
public class ImmutableTermCollection extends SerializableObject{
	private byte[] size = null;
	private TermConverter[] termConverters = null;

	/**
	 * Default contructor.
	 */
	public ImmutableTermCollection(){
		super();

		this.size = new byte[NativeTypeBuilder.INTBYTES];

		registerNativeType(size);
	}

	/**
	 * Constructor.
	 * 
	 * @param terms
	 *            An array containing the terms that should be stored in this
	 *            collection.
	 */
	public ImmutableTermCollection(AbstractTerm[] terms){
		super();

		this.size = NativeTypeBuilder.makeBytesFromInt(terms.length);
		this.termConverters = new TermConverter[terms.length];

		registerNativeType(size);
		for(int i = 0; i < termConverters.length; i++){
			termConverters[i] = new TermConverter(terms[i]);
			register(termConverters[i]);
		}
	}

	/**
	 * Returns the size of the collection
	 * 
	 * @return The size of the collection
	 */
	public int size(){
		return termConverters.length;
	}

	/**
	 * Returns the term associated with the given index in this collection.
	 * 
	 * @param index
	 *            The index associated with the term.
	 * @return The term.
	 */
	public AbstractTerm getValue(int index){
		return termConverters[index].getTerm();
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
	}
}
