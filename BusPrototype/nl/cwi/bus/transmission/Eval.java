package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;

/**
 * Represents an eval.
 * 
 * @author Arnold Lankamp
 */
public class Eval extends AbstractTerm{
	private final static String TYPE = "EVAL";

	/**
	 * Default constructor.
	 */
	public Eval(){
		super();
	}

	/**
	 * @see AbstractTerm#match(String)
	 */
	public boolean match(String signature){

		// temp
		return false;
	}

	/**
	 * @see AbstractTerm#getSignature()
	 */
	public String getSignature(){

		// Temp
		return null;
	}

	/**
	 * @see AbstractTerm#getType()
	 */
	public String getType(){
		return TYPE;
	}
}
