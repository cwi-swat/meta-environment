package toolbus.viewer;

import toolbus.StateElement;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * This is a convenience class for implementing viewer event listeners.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractViewerAdapter implements IViewer, IPerformanceMonitor{
	
	/**
	 * Default constructor.
	 */
	public AbstractViewerAdapter(){
		super();
	}

	/**
	 * @see IViewer#processBreakPointHit(ProcessInstance)
	 */
	public void processBreakPointHit(ProcessInstance processInstance){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IViewer#processInstanceStarted(ProcessInstance)
	 */
	public void processInstanceStarted(ProcessInstance processInstance){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IViewer#processInstanceTerminated(ProcessInstance)
	 */
	public void processInstanceTerminated(ProcessInstance processInstance){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IViewer#sourceBreakPointHit(StateElement)
	 */
	public void sourceBreakPointHit(StateElement stateElement){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IViewer#stateElementBreakPointHit(StateElement)
	 */
	public void stateElementBreakPointHit(StateElement stateElement){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IViewer#stepExecuted(ProcessInstance, StateElement, ProcessInstance[])
	 */
	public void stepExecuted(ProcessInstance processInstance, StateElement executedStateElement, ProcessInstance[] partners){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IViewer#toolbusStarting()
	 */
	public void toolbusStarting(){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IViewer#toolbusTerminating()
	 */
	public void toolbusTerminating(){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IViewer#updateState(int)
	 */
	public void updateState(int state){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IPerformanceMonitor#performanceStatsArrived(ToolInstance, ATerm)
	 */
	public void performanceStatsArrived(ToolInstance toolInstance, ATerm term){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IPerformanceMonitor#toolConnected(ToolInstance)
	 */
	public void toolConnected(ToolInstance toolInstance){
		// Intentionally left empty; overwrite in subclass.
	}

	/**
	 * @see IPerformanceMonitor#toolConnectionClosed(ToolInstance)
	 */
	public void toolConnectionClosed(ToolInstance toolInstance){
		// Intentionally left empty; overwrite in subclass.
	}
}
