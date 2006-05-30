package nl.cwi.term.serializable;

import nl.cwi.util.serializable.FlexibleLengthObject;

/**
 * Represents a term with a flexible length.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractTerm extends FlexibleLengthObject{

	/**
	 * Default constructor.
	 */
	public AbstractTerm(){
		super();
	}

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that should be stored in this serializable object.
	 */
	public AbstractTerm(String term){
		super(term);
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
