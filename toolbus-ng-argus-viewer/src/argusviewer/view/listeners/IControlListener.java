package argusviewer.view.listeners;

import toolbus.StateElement;
import toolbus.process.ProcessInstance;

/**
 * Listener for Toolbus Control settings
 * 
 * @author Tim Van Laer
 */
public interface IControlListener{
	/**
	 * one step is executed:
	 * 
	 * @param tick
	 *            The tick number that is increased every step that is executed
	 *            by the toolbus. (the first tick has value 0)
	 * @param processInstance
	 *            The process instance in which the step is executed.
	 * @param executedStateElement
	 *            The state element that has been executed.
	 * @param partners
	 *            An array of processInstances that are related to the state
	 *            element in case it is used for communication among processes.
	 */
	void stepExecuted(int tick, ProcessInstance processInstance,
			StateElement executedStateElement, ProcessInstance[] partners);
}
