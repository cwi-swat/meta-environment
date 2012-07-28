package nl.cwi.term;


/**
 * Represents a term.<br />
 * A term can contain the following elements:<br />
 * -More terms.<br />
 * -Annotations in the form of terms.<br />
 * 
 * @author Arnold Lankamp
 */
public abstract class Term{
	protected final static String OPENTOKEN = "(";
	protected final static String CLOSETOKEN = ")";
	protected final static String SEPERATORTOKEN = ",";
	
	private String type = null;

	/**
	 * Constructor.
	 * 
	 * @param type
	 *            The name of the term.
	 */
	public Term(String type){
		super();

		this.type = type;
	}

	/**
	 * Returns the type of this term.
	 * 
	 * @return The type of this term.
	 */
	public String getType(){
		return type;
	}

	/**
	 * Returns the signature of this term.
	 * 
	 * @return The signature of this term.
	 */
	public abstract String getSignature();

	/**
	 * Matches this term against a signature. Returns true when they match;
	 * false otherwise.
	 * 
	 * @param signature
	 *            The signature that will be matched on.
	 * @return True if this term matches the signature.
	 */
	public boolean match(String signature){
		return signature.equals(getSignature());
	}
	
	/**
	 * Converts this term to a string.
	 * 
	 * @return The serialized term.
	 */
	public abstract String serialize();

	/**
	 * Parses the given serialized term and transforms it into a Term object.
	 * @param serializedTerm The serialized term that needs to be parsed.
	 * @return The created term object.
	 */
	public static Term parse(String serializedTerm){
		int firstOpenTokenIndex = serializedTerm.indexOf(OPENTOKEN);
		
		String type = serializedTerm.substring(0, firstOpenTokenIndex);
		
		Term term = null;
		if(type.equals(ListTerm.TYPE)){
			term = ListTerm.parse(serializedTerm);
		}else if(type.equals(IntTerm.TYPE)){
			term = IntTerm.parse(serializedTerm);
		}else if(type.equals(StringTerm.TYPE)){
			term = StringTerm.parse(serializedTerm);
		}else{
			throw new RuntimeException("Unkown term type: "+type);
		}
		
		return term;
	}
}
