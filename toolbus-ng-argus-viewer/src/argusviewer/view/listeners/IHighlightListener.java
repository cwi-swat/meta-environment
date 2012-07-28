package argusviewer.view.listeners;

import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

/**
 * Listener for highlight settings.
 * 
 * @author J. van den Bos
 * @author T. Van Laer
 */
public interface IHighlightListener{
	/**
	 * The view is highlighting a process instance.
	 * 
	 * @param processInstance
	 *            The highlighted process instance.
	 */
	void setHighlight(ProcessInstance processInstance);

	/**
	 * The view is highlighting a tool instance.
	 * 
	 * @param toolInstance
	 *            The highlighted tool instance.
	 */
	void setHighlight(ToolInstance toolInstance);

	/**
	 * The view is highlighting a process.
	 * 
	 * @param processName
	 *            The name of a highlighted process.
	 */
	void setHighlightByProcessName(String processName);

	/**
	 * The view is highlighting a tool.
	 * 
	 * @param toolName
	 *            The name of the highlighted tool.
	 */
	void setHighlightByToolName(String toolName);
}
