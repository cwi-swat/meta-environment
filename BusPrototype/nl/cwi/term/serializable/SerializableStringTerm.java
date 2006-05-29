package nl.cwi.term.serializable;


/**
 * Represents a serializable string term.
 * 
 * @author Arnold Lankamp
 */
public class SerializableStringTerm extends AbstractFlexibleLengthTerm{
	private final static String SIGNATURE = "string()";
	private final static String TYPE = "string";

	/**
	 * Default constructor.
	 */
	public SerializableStringTerm(){
		super();
	}
	
	/**
	 * Constructor.
	 * @param content The content of this term (String).
	 */
	public SerializableStringTerm(String content){
		super(content);
	}
	
	/**
	 * Returns the content of this serializable string term.
	 * @return The content of this serializable string term.
	 */
	public String getContent(){
		String content = new String(getContent(getKey()));
		//If there is no content, set it to null.
		if(!hasContent()) content = null;
		
		return content;
	}
	
	/**
	 * Checks if this term has content.
	 * @return True if it does; false if it is 'null'.
	 */
	public boolean hasContent(){
		return (!isEmpty());
	}
	
	/**
	 * Returns the signature of this term.
	 * @return The signature of this term.
	 */
	public String getSignature(){
		return SIGNATURE;
	}
	
	/**
	 * Returns the type of this term.
	 * @return The type of this term.
	 */
	public String getType(){
		return TYPE;
	}
	
	/**
	 * Checks if this term matches the given signature.
	 * 
	 * @param signature
	 *            The signature that will be matched on.
	 * @return True if this term matches the signature; false otherwise.
	 */
	public boolean match(String signature){
		return signature.equals(getSignature());
	}
}
