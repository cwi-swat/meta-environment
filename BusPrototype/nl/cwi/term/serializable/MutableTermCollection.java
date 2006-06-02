package nl.cwi.term.serializable;

import java.util.ArrayList;
import java.util.List;

import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.serializable.SerializableObject;

/**
 * Represents a mutable collection of terms. NOTE: This collection should not be
 * modified during (de-)serialization.
 * 
 * @author Arnold Lankamp
 */
public class MutableTermCollection extends SerializableObject{
	private byte[] size = null;
	private List terms = null;

	/**
	 * Constructor.
	 * 
	 * @param construct
	 *            True if this object should be constructed; false if it should
	 *            be build using a byte stream.
	 */
	public MutableTermCollection(boolean construct){
		super();

		size = new byte[NativeTypeBuilder.INTBYTES];
		if(construct) terms = new ArrayList();

		registerNativeType(size.length, size);
	}

	/**
	 * Updates the size field of this collection.
	 */
	private void updateSize(){
		byte[] newSize = NativeTypeBuilder.makeBytesFromInt(terms.size());
		System.arraycopy(newSize, 0, size, 0, size.length);
	}

	/**
	 * Finds the corresponding TermConverter for this term.
	 * 
	 * @param term
	 *            The term for which the converter must be find.
	 * @return The converter that was found; null if it isn't present.
	 */
	private TermConverter findConverter(AbstractTerm term){
		TermConverter termConverter = null;
		for(int i = 0; i < terms.size(); i++){
			TermConverter tc = ((TermConverter) terms.get(i));
			if(tc.getTerm() == term){
				termConverter = tc;
				break;
			}
		}
		return termConverter;
	}

	/**
	 * Adds the given serializable object to this collection.
	 * 
	 * @param abstractTerm
	 *            The term that should be added.
	 */
	public void add(AbstractTerm abstractTerm){
		TermConverter termConverter = new TermConverter(abstractTerm);
		synchronized(terms){
			terms.add(termConverter);

			register(termConverter);

			updateSize();
		}
	}

	/**
	 * Returns the size of this collection.
	 * 
	 * @return The size of this collection.
	 */
	public int size(){
		return terms.size();
	}

	/**
	 * Returns the term associated with the given index.
	 * 
	 * @param index
	 *            The index of the term.
	 * @return The term that was found.
	 */
	public AbstractTerm getValue(int index){
		TermConverter termConverter = null;
		Object o = terms.get(index);
		if(o != null) termConverter = ((TermConverter) o);
		
		return termConverter.getTerm();
	}

	/**
	 * Removes the given term from this collection.
	 * 
	 * @param abstractTerm
	 *            The term that should be removed.
	 */
	public void remove(AbstractTerm abstractTerm){
		TermConverter termConverter = findConverter(abstractTerm);
		if(termConverter != null){
			synchronized(terms){
				terms.remove(termConverter);

				deregister(termConverter);

				updateSize();
			}
		}
	}

	/**
	 * @see SerializableObject#update()
	 */
	public void update(){
		if(terms == null && isBuild(size)){
			int listSize = NativeTypeBuilder.makeInt(size);
			terms = new ArrayList();
			for(int i = 0; i < listSize; i++){
				TermConverter tc = new TermConverter();
				terms.add(tc);
				register(tc);
			}
		}
	}
}
