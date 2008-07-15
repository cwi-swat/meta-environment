package argusviewer.view.listeners;

import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

/**
 * Listener for focus settings.
 * 
 * @author T. Van Laer
 * @author J. van den Bos
 */
public interface IFocusListener {

	/**
	 * The view is actively working with a process.
	 * 
	 * @param processInstance
	 *            The current active process.
	 */
	void setFocus(ProcessInstance processInstance);

	/**
	 * The view is actively working with a tool instance.
	 * 
	 * @param toolInstance
	 *            The current active tool instance.
	 */
	void setFocus(ToolInstance toolInstance);
}
