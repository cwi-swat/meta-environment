package argusviewer.view.listeners;

import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * Listener for performance-related control notifications.
 * 
 * @author J. van den Bos
 * @author T. Van Laer
 */
public interface IPerformanceControlListener{
	/**
	 * a certain tool is updated:
	 * 
	 * @param toolInstance the tool that is updated.
     * @param aTerm the performance stats
	 */
	void updatePerformance(ToolInstance toolInstance, ATerm aTerm);
}
