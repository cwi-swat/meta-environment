package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;

/**
 * Represents an event.
 * 
 * @author Arnold Lankamp
 */
public class Event extends AbstractTransmission{
	public final static String TYPE = "event";
	
	private final static String SIGNATUREOPENTOKEN = "event"+SIGNATUREOPEN;
	private final static String SIGNATURECLOSETOKEN = SIGNATURECLOSE;

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
