package nl.cwi.util;

/**
 * Unique id generator
 * 
 * @author Arnold Lankamp
 */
public class IDGenerator{
	private static long previousID = -1;
	
	/**
	 * Default constructor
	 */
	public IDGenerator(){
		super();
	}
	
	/**
	 * Returns a unique id.
	 * This id is based on the current time in milliseconds
	 * @return a unique id
	 */
	public static synchronized long generate(){
		long id = System.currentTimeMillis();
		
		while(previousID == id){
			id = System.currentTimeMillis();
			
			//Don't want to consume all cpu cycles during < 1 ms
			Thread.yield();
		}
		previousID = id;
		
		return id;
	}
}
