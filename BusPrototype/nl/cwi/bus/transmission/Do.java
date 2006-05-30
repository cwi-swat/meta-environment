package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;

/**
 * Represents a do.
 * 
 * @author Arnold Lankamp
 */
public class Do extends AbstractTransmission{
	private final static String SIGNATUREOPENTOKEN = "do(";
	private final static String SIGNATURECLOSETOKEN = ")";
	private final static String TYPE = "do";

	/**
	 * Default constructor.
	 */
	public Do(){
		super();
	}

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that needs to be send in a do request.
	 */
	public Do(AbstractTerm term){
		super(term);
	}

	/**
	 * @see AbstractTerm#getType()
	 */
	public String getType(){
		return TYPE;
	}

	/**
	 * @see AbstractTerm#getSignature()
	 */
	public String getSignature(){
		return createSignature(SIGNATUREOPENTOKEN, SIGNATURECLOSETOKEN);
	}
}
