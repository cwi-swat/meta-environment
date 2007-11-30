package toolbus.viewer;

import toolbus.StateElement;
import toolbus.process.ProcessInstance;

/**
 * This interface specifies the events the debug toolbus can fire.
 * 
 * @author Arnold Lankamp
 */
public interface IViewer{
	
	/**
	 * Informs the viewer about what the debug toolbus is currently doing. A list of possible states
	 * can be found in toolbus.viewer.IViewerConstants
	 * 
	 * @see toolbus.viewer.IViewerConstants
	 * @param state
	 *            The state that identifies what the debug toolbus is currently doing.
	 */
	void updateState(int state);
	
	/**
	 * Fired after the successfull completion of a step.
	 * 
	 * @param processInstance
	 *            The process instance in which a state element was executed.
	 * @param executedStateElement
	 *            The state element that was executed.
	 */
	void stepExecuted(ProcessInstance processInstance, StateElement executedStateElement);
	
	/**
	 * Fired when a new process instance is started.
	 * 
	 * @param processInstance
	 *            The process instance that was started.
	 */
	void processInstanceStarted(ProcessInstance processInstance);
	
	/**
	 * Fired when a process instance is terminated.
	 * 
	 * @param processInstance
	 *            The process instance that was terminated.
	 */
	void processInstanceTerminated(ProcessInstance processInstance);
	
	/**
	 * Informs the viewer that a registered breakpoint on a process or process instance was hit. The
	 * debug toolbus will not suspend it's execution by itself; the action that will be taken is
	 * completely up to the viewer implementation. In case the execution needs to be paused this will
	 * need to be done explicitly by calling the doStop method.
	 * 
	 * @param processInstance
	 *            The process instance that matches the breakpoint.
	 */
	void processBreakPointHit(ProcessInstance processInstance);
	
	/**
	 * Informs the viewer that a registered breakpoint on a state element was hit. The debug toolbus
	 * will not suspend it's execution by itself; the action that will be taken is completely up to
	 * the viewer implementation. In case the execution needs to be paused this will need to be done
	 * explicitly by calling the doStop method.
	 * 
	 * @param stateElement
	 *            The state element on which the breakpoint was set.
	 */
	void stateElementBreakPointHit(StateElement stateElement);
	
	/**
	 * Fired when the debug toolbus starts.
	 */
	void toolbusStarting();
	
	/**
	 * Fired right before then debug toolbus shuts down.
	 */
	void toolbusTerminating();
}
