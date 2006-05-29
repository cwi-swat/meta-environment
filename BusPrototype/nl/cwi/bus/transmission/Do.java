package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;

/**
 * Represents a do.
 * 
 * @author Arnold Lankamp
 */
public class Do extends AbstractTerm{
	private final static String TYPE = "DO";

	/**
	 * Default constructor.
	 */
	public Do(){
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
		
		//Temp
		return null;
	}
	
	/**
	 * @see AbstractTerm#getType()
	 */
	public String getType(){
		return TYPE;
	}
}
