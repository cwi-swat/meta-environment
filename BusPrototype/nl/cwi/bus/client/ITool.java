package nl.cwi.bus.client;

/**
 * The main class of the tool should implement this interface. It will enable
 * the invocation of methods on the tool.
 * 
 * @author Arnold Lankamp
 */
public interface ITool{
	
	/**
	 * Called when a tool is requested to shut down.
	 */
	void terminate();
}
