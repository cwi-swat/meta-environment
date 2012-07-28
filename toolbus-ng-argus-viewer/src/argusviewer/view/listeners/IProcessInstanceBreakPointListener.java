package argusviewer.view.listeners;

import toolbus.process.ProcessInstance;

/**
 * Listener for breakpoint adds and removes on process instances.
 * 
 * @author J. van den Bos
 * @author T. van Laer
 */
public interface IProcessInstanceBreakPointListener{
	/**
	 * A breakpoint is added in the t-script of the processInstance.
	 * 
	 * @param processInstance
	 *            The t-script of this process has a new breakpoint.
	 */
	void addBreakpoint(ProcessInstance processInstance);

	/**
	 * A breakpoint is removed in the t-script of the processInstance.
	 * 
	 * @param processInstance
	 *            The t-script of this process has its breakpoint removed.
	 */
	void removeBreakpoint(ProcessInstance processInstance);
}
