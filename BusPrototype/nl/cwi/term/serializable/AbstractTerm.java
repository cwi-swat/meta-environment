package nl.cwi.term.serializable;

import nl.cwi.util.IDGenerator;
import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.serializable.FlexibleLengthObject;
import nl.cwi.util.serializable.SerializableObject;

/**
 * Represents a term.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractTerm extends SerializableObject{
	public final static String SIGNATUREOPEN = "(";
	public final static String SIGNATURECLOSE = ")";
	public final static String SIGNATURESEPARATOR = ",";

	private byte[] identifier = null;
	private FlexibleLengthObject term = null;

	/**
	 * Default constructor.
	 */
	public AbstractTerm(){
		super();

		identifier = new byte[NativeTypeBuilder.LONGBYTES];
		term = new FlexibleLengthObject();

		init();
	}

	/**
	 * Constructor.
	 * 
	 * @param value
	 *            The value of the term that should be stored in this
	 *            serializable object.
	 */
	public AbstractTerm(String value){
		super();

		identifier = NativeTypeBuilder.makeBytesFromLong(IDGenerator.generate());
		term = new FlexibleLengthObject(value);

		init();
	}

	/**
	 * Initializes this term.
	 */
	private void init(){
		registerNativeType(identifier);
		register(term);
	}

	/**
	 * Returns the identifier of this term (unique in every tree).
	 * 
	 * @return The identifier of this term.
	 */
	public long getID(){
		return NativeTypeBuilder.makeLong(identifier);
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
