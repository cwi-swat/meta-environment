package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;

/**
 * Represents an eval.
 * 
 * @author Arnold Lankamp
 */
public class Eval extends AbstractTransmission{
	private final static String SIGNATUREOPENTOKEN = "eval(";
	private final static String SIGNATURECLOSETOKEN = ")";
	private final static String TYPE = "eval";

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
