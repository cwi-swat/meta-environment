package nl.cwi.util;

/**
 * This class provides generation of unique identifiers (with integer as type).
 * NOTE: This class is not synchronized and only generates unique identifiers for every induvidual instance.
 * If truely unique numbers are required you should use the IDGeneration class instead.
 * 
 * @author Arnold Lankamp
 */
public class LowIDGenerator{
	private int previousID = -1;

	/**
	 * Defualt constructor.
	 */
	public LowIDGenerator(){
		super();
		
		previousID = 0;
	}
	
	/**
	 * Generates a unique identifier.
	 * @return A unique identifier.
	 */
	public int generate(){
		return ++previousID;
	}
}
