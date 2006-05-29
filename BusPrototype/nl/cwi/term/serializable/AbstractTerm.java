package nl.cwi.term.serializable;

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
	
	public abstract String getType();
	
	public abstract String getSignature();
}
