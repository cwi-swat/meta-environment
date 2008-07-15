package argusviewer.view.listeners;

import toolbus.StateElement;
import toolbus.process.ProcessInstance;

/**
 * Interface for receiving notification of breakpoint hits.
 * 
 * @author J. van den Bos
 * @author T. Van Laer
 */
public interface IBreakPointHitListener {
	/**
	 * The toolbus has reached a set breakpoint.
	 * 
	 * @param processInstance
	 *            The current processInstance with the breakpoint.
	 */
	void hitBreakpoint(ProcessInstance processInstance);

	/**
	 * The toolbus has reached a set breakpoint.
	 * 
	 * @param stateElement
	 *            The current stateElement with the breakpoint.
	 */
	void hitBreakpoint(StateElement stateElement);
}
