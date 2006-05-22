package nl.cwi.term;

public class StringTerm extends Term{
	public final static String TYPE = "string";
	
	private String content = null;

	/**
	 * Constructor.
	 * @param content The content of the string contained in this term.
	 */
	public StringTerm(String content){
		super(TYPE);
		
		this.content = content;
	}
	
	/**
	 * Returns the string contained in this term.
	 * @return The string contained in this term.
	 */
	public String getContent(){
		return content;
	}
	
	/**
	 * Returns the signature of this term.
	 * 
	 * @see Term#getSignature()
	 * @return The signature of this term.
	 */
	public String getSignature(){
		StringBuilder signatureBuilder = new StringBuilder();
		
		signatureBuilder.append(getType());
		signatureBuilder.append(OPENTOKEN);
		signatureBuilder.append(CLOSETOKEN);

		return signatureBuilder.toString();
	}
	
	/**
	 * Converts this term to a string.
	 * 
	 * @see Term#serialize()
	 * @return The serialized term.
	 */
	public String serialize(){
		StringBuilder signatureBuilder = new StringBuilder();
		
		signatureBuilder.append(getType());
		signatureBuilder.append(OPENTOKEN);
		signatureBuilder.append(content);
		signatureBuilder.append(CLOSETOKEN);

		return signatureBuilder.toString();
	}
	
	/**
	 * Parses the given serialized term and transforms it into a Term object.
	 * @param serializedTerm The serialized term that needs to be parsed.
	 * @return The created term object.
	 */
	public static Term parse(String serializedTerm){
		int openTokenIndex = serializedTerm.indexOf(OPENTOKEN);
		int closeTokenIndex = serializedTerm.lastIndexOf(CLOSETOKEN);
		
		String content = serializedTerm.substring(openTokenIndex + OPENTOKEN.length(), closeTokenIndex);
		
		return new StringTerm(content);
	}
}
