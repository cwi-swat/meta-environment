package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;

/**
 * Represents an event.
 * 
 * @author Arnold Lankamp
 */
public class Event extends AbstractTerm{
	private final static String TYPE = "EVENT";

	/**
	 * Default constructor.
	 */
	public Event(){
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
