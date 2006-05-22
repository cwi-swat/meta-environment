package nl.cwi.term;

/**
 * Term representation of an integer.
 * 
 * @author Arnold Lankamp
 */
public class IntTerm extends Term{
	public final static String TYPE = "int";

	private int value = -1;

	/**
	 * Constructor.
	 * @param value The value of the integer contained in this term.
	 */
	public IntTerm(int value){
		super(TYPE);

		this.value = value;
	}

	/**
	 * Returns the value of the integer contained in this term.
	 * @return The value of the integer.
	 */
	public int getValue(){
		return value;
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
		signatureBuilder.append(value);
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
		
		String valueSubString = serializedTerm.substring(openTokenIndex + OPENTOKEN.length(), closeTokenIndex);
		int value = Integer.parseInt(valueSubString);
		
		return new IntTerm(value);
	}
}
