package nl.cwi.term.serializable;

import nl.cwi.util.serializable.FlexibleLengthObject;

/**
 * Represents a term with a flexible length.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractTerm extends FlexibleLengthObject{
	private FlexibleLengthObject typeField = null;

	/**
	 * Default constructor.
	 */
	public AbstractTerm(){
		super();

		typeField = new FlexibleLengthObject();

		init();
	}

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that should be stored in this serializable object.
	 * @param type
	 *            The type of the term.
	 */
	public AbstractTerm(String term, String type){
		super(term);

		typeField = new FlexibleLengthObject(type);

		init();
	}

	private void init(){
		register(typeField);
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
