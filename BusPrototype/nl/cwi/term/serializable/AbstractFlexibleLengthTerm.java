package nl.cwi.term.serializable;

/**
 * Represents a term with a flexible length.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractFlexibleLengthTerm extends FlexibleLengthObject{
	
	/**
	 * Default constructor.
	 */
	public AbstractFlexibleLengthTerm(){
		super();
	}
	
	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that should be stored in this serializable object.
	 */
	public AbstractFlexibleLengthTerm(String term){
		super(term);
	}
}
