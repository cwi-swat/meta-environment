package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;

/**
 * Represents an eval.
 * 
 * @author Arnold Lankamp
 */
public class Eval extends AbstractTransmission{
	public final static String TYPE = "eval";
	
	private final static String SIGNATUREOPENTOKEN = "eval"+SIGNATUREOPEN;
	private final static String SIGNATURECLOSETOKEN = SIGNATURECLOSE;

	/**
	 * Default constructor.
	 */
	public Eval(){
		super();
	}

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that needs to be send in a eval request.
	 */
	public Eval(AbstractTerm term){
		super(term);
	}

	/**
	 * @see AbstractTerm#getSignature()
	 */
	public String getSignature(){
		return createSignature(SIGNATUREOPENTOKEN, SIGNATURECLOSETOKEN);
	}

	/**
	 * @see AbstractTerm#getType()
	 */
	public String getType(){
		return TYPE;
	}
}
