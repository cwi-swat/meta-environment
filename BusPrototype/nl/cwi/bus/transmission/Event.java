package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;

/**
 * Represents an event.
 * 
 * @author Arnold Lankamp
 */
public class Event extends AbstractTransmission{
	private final static String SIGNATUREOPENTOKEN = "event(";
	private final static String SIGNATURECLOSETOKEN = ")";
	private final static String TYPE = "event";

	/**
	 * Default constructor.
	 */
	public Event(){
		super();
	}

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that needs to be send in this event.
	 */
	public Event(AbstractTerm term){
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
