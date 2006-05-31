package nl.cwi.term.serializable;

import nl.cwi.util.serializable.FlexibleLengthObject;
import nl.cwi.util.serializable.SerializableObject;

/**
 * Represents a term with a flexible length.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractTerm extends SerializableObject{
	private FlexibleLengthObject term = null;

	/**
	 * Default constructor.
	 */
	public AbstractTerm(){
		super();

		term = new FlexibleLengthObject();
		
		init();
	}

	/**
	 * Constructor.
	 * 
	 * @param value
	 *            The value of the term that should be stored in this serializable object.
	 */
	public AbstractTerm(String value){
		super();

		this.term = new FlexibleLengthObject(value);
		
		init();
	}
	
	/**
	 * Initializes this term.
	 */
	private void init(){
		register(term);
	}

	/**
	 * Checks if this term is null or not.
	 * 
	 * @return True if it is; false otherwise.
	 */
	public boolean isNull(){
		return term.isNull();
	}

	/**
	 * Returns the content of this term.
	 * 
	 * @return The requested value, represented as byte array.
	 */
	public byte[] getContent(){
		return term.getContent();
	}

	/**
	 * Returns the type of the term.
	 * 
	 * @return The type of the term.
	 */
	public abstract String getType();

	/**
	 * Returns the signature of the term.
	 * 
	 * @return The signature of the term.
	 */
	public abstract String getSignature();

	/**
	 * Checks if the term matches the given signature.
	 * 
	 * @param signature
	 *            The signature that will be matched on.
	 * @return True if the term matches the signature; false otherwise.
	 */
	public abstract boolean match(String signature);
}
