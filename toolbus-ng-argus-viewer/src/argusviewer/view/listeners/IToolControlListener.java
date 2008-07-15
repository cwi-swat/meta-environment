package argusviewer.view.listeners;

import toolbus.tool.ToolInstance;

/**
 * Listener for Tool-related control notifications.
 * 
 * @author J. van den Bos
 * @author T. Van Laer
 */
public interface IToolControlListener {

	/**
	 * Tool instance is added on the toolbus
	 * 
	 * @param toolInstance
	 *            the new tool instance
	 */
	void addToolInstance(ToolInstance toolInstance);

	/**
	 * Tool instance is removed on the toolbus
	 * 
	 * @param toolInstance
	 *            the removed tool instance
	 */
	void removeToolInstance(ToolInstance toolInstance);
}
