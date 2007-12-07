package toolbus.viewer;

import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * Listener that can be notified of the arrival of performance statistics messages.
 * 
 * @author Arnold Lankamp
 */
public interface IPerformanceMonitor{
	
	/**
	 * Fired when a tool connects.
	 * 
	 * @param toolInstance
	 *            The tool instance associated with the tool that connected.
	 */
	void toolConnected(ToolInstance toolInstance);
	
	/**
	 * Fired when a connection with a tool is terminated.
	 * 
	 * @param toolInstance
	 *            The tool instance associated with the tool that is no longer connected.
	 */
	void toolConnectionClosed(ToolInstance toolInstance);
	
	/**
	 * Fired when the performance statistics that were requested by the debug ToolBus arrived.
	 * 
	 * @param toolInstance
	 *            The tool instance the performance statistics are associated with.
	 * @param aTerm
	 *            The term that contains the performance statistics data.
	 */
	void performanceStatsArrived(ToolInstance toolInstance, ATerm aTerm);
}
