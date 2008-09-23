package argusviewer.view.processlist.data;

import java.util.ArrayList;
import argusviewer.toolbus.DataComm;
import argusviewer.view.listeners.IProcessInstanceBreakPointListener;

import toolbus.process.ProcessInstance;

/**
 * This is the most basic part of the Process List View. This item represents
 * one process.
 * 
 * @author R.Schuddeboom
 * @author H.Baggelaar
 * @author Jeldert Pol
 */
public class ProcessTreeListItem implements IProcessInstanceBreakPointListener {
	private final ProcessInstance m_processInstance;
	private final DataComm m_dataComm;

	private volatile boolean m_breakPoint;
	private volatile boolean m_filter;
	private volatile boolean m_removed; // items aren't really removed anymore, instead they are set as 'removed' so the items can still be set as visible/invisible even when removed.
	
	/**
	 * Constructor. Initiates itself, setting breakpoint to false, and filter to false.
	 * 
	 * @param processInstance
	 *            The ProcessInstance of this item.
	 * @param dataComm The DataComm instance that will be used
	 */
	public ProcessTreeListItem(ProcessInstance processInstance, DataComm dataComm) {
		this(processInstance, dataComm, false, false);
	}

	/**
	 * Constructor. Initiates itself, setting breakpoint and filter to the given
	 * value.
	 * 
	 * @param processInstance
	 *            The ProcessInstance of this item.
	 * @param dataComm 
	 * @param breakPoint
	 *            Indicates if a breakpoint is set on this instance.
	 * @param filter
	 *            Indicates if a filter is set on this instance.
	 */
	private ProcessTreeListItem(ProcessInstance processInstance,
			DataComm dataComm, boolean breakPoint, boolean filter) {
		m_processInstance = processInstance;
		m_breakPoint = breakPoint;
		m_filter = filter;
		m_removed = false;
		m_dataComm = dataComm;
		m_dataComm.getBreakPointSync().register(this);
	}

	/**
	 * Returns the {@link ProcessInstance} of this item.
	 * 
	 * @return the {@link ProcessInstance} of this item.
	 */
	public ProcessInstance getProcessInstance() {
		return m_processInstance;
	}

	/**
	 * Returns the name of the {@link ProcessInstance}.
	 * 
	 * @return the name of the {@link ProcessInstance}.
	 */
	public String getProcessInstanceName() {
		return m_processInstance.getProcessName();
	}

	/**
	 * Returns the ID of the {@link ProcessInstance} of this item.
	 * 
	 * @return the ID of the {@link ProcessInstance} of this item.
	 */
	public int getProcessInstanceID() {
		return m_processInstance.getProcessId();
	}

	/**
	 * Returns if the current item has a breakpoint set.
	 * 
	 * @return if the current item has a breakpoint set.
	 */
	public boolean hasBreakPoint() {
		return m_breakPoint;
	}

	/**
	 * Sets the breakpoint on this item.
	 * 
	 * @param breakPoint
	 *            indicates if a breakpoint is set or not.
	 */
	public void setBreakPoint(boolean breakPoint) {
		if (m_breakPoint != breakPoint) {
			if (breakPoint) {
				m_dataComm.getBreakPointSync().addBreakpoint(m_processInstance);
			} else {
				m_dataComm.getBreakPointSync().removeBreakpoint(m_processInstance);
			}
		}
		//m_breakPoint = breakPoint;
	}

	/**
	 * Returns if the current item has a filter set.
	 * 
	 * @return if the current item has a filter set.
	 */
	public boolean hasFilter() {
		return m_filter;
	}

	/**
	 * Sets the filter on this item.
	 * 
	 * @param filter
	 *            indicates if a filter is set or not.
	 */
	public void setFilter(boolean filter) {		
		m_filter = filter;
	}
	
	/**
	 * Checks if the item has been removed
	 * @return the removed status
	 */
	public boolean isRemoved() {
		return m_removed;
	}
	
	/**
	 * remove the item
	 */
	public void remove() {
		m_removed = true;
	}

	/**
	 * {@inheritDoc}
	 */
	public void addBreakpoint(ProcessInstance processInstance) {
		if (m_processInstance == processInstance) {
			m_breakPoint = true;
		}		
	}

	/**
	 * {@inheritDoc}
	 */
	public void removeBreakpoint(ProcessInstance processInstance) {
		if (m_processInstance == processInstance) {
			m_breakPoint = false;
		}	
	}

	/**
	 * Propagates the current item's state to the FilterSync.
	 * 
	 * @param visible true if visible, false otherwise
	 */
	public void setFilterAndPropagate(boolean visible) {
		ArrayList<ProcessInstance> list = new ArrayList<ProcessInstance>(1);
		list.add(m_processInstance);
		m_filter = visible;
		if (visible) {
			m_dataComm.getFilterSync().addProcessInstance(list);
		} else {
			m_dataComm.getFilterSync().removeProcessInstance(list);
		}
	}
}
