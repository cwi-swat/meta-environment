package argusviewer.toolbus.sync;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


import org.apache.log4j.Logger;
import argusviewer.ExceptionReporter;
import argusviewer.view.listeners.IProcessFilterListener;
import argusviewer.view.listeners.IToolFilterListener;

import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;

/**
 * This class keeps track of and manages all filters.
 *
 * @author Tim Van Laer
 * @author Jeldert Pol
 * @author Alexander Bij
 * @author Roberto van der Linden
 */
public class FilterSync {

	private ArrayList<IProcessFilterListener> m_processListeners;
	private ArrayList<IToolFilterListener> m_toolListeners;
	private ArrayList<ProcessInstance> m_processesFilter;
	private ArrayList<ToolInstance> m_toolsFilter;

	/**
	 * Constructor for the filter synchronizer
	 */
	public FilterSync() {
		m_processListeners = new ArrayList<IProcessFilterListener>();
		m_toolListeners = new ArrayList<IToolFilterListener>();
		m_processesFilter = new ArrayList<ProcessInstance>();
		m_toolsFilter = new ArrayList<ToolInstance>();
	}

	/**
	 * Registers a listener. The listener will be informed about changes in the
	 * filter with regard to processes.
	 *
	 * @param listener A listener to be informed about changes in the filter.
	 */
	public void register(IProcessFilterListener listener) {
		m_processListeners.add(listener);
	}

	/**
	 * Registers a listener. The listener will be informed about changes in the
	 * filter with regard to tools.
	 *
	 * @param listener A listener to be informed about changes in the filter.
	 */
	public void register(IToolFilterListener listener) {
		m_toolListeners.add(listener);
	}

	/**
	 * Get the filter with visible processes.
	 *
	 * @return {@link List} with processes to be visible.
	 */
	public List<ProcessInstance> getProcessFilter() {
		return m_processesFilter;
	}

	/**
	 * Add {@link ProcessInstance} to the list of all {@link ProcessInstance}'s
	 * that are visible. An error message will be shown in the consoleview when
	 * the list already contains the {@link ProcessInstance}.
	 *
	 * @param processInstances the processInstances that must be added.
	 */
	public void addProcessInstance(List<ProcessInstance> processInstances) {
		
		for (ProcessInstance processInstance : processInstances) {
			if (!m_processesFilter.contains(processInstance)) {
				m_processesFilter.add(processInstance);
			} else {
				Logger.getLogger(FilterSync.class).debug("Could not set the ProcessInstance to visible.");
			}
		}
		
		notifyProcessListeners();
		
	}

	/**
	 * Remove {@link ProcessInstance} from the list of all
	 * {@link ProcessInstance}'s that are visible. An error message will be
	 * shown in the consoleview when the list doesn't contains the
	 * {@link ProcessInstance}.
	 *
	 * @param processInstances the toolInstances that must be added.
	 */
	public void removeProcessInstance(List<ProcessInstance> processInstances) {
		
		for (ProcessInstance processInstance : processInstances) {
			if (m_processesFilter.contains(processInstance)) {
				m_processesFilter.remove(processInstance);
			} else {
				Logger.getLogger(FilterSync.class).debug("Could not set the ProcessInstance to non-visible.");
			}
		}
		
		notifyProcessListeners();
	}

	/**
	 * Get a list of the {@link ToolInstance} that are visible.
	 *
	 * @return {@link List} with tools to be visible.
	 */
	public List<ToolInstance> getToolFilter() {
		return Collections.unmodifiableList(m_toolsFilter);
	}

	/**
	 * Add ToolInstance to the list of all ToolInstance that are visible. An
	 * error message will be shown in the consoleview when the list does
	 * contains the ToolInstance.
	 *
	 * @param toolInstance the toolInstance thats need to be added.
	 */
	public void addToolInstance(ToolInstance toolInstance) {
		if (!m_toolsFilter.contains(toolInstance)) {
			m_toolsFilter.add(toolInstance);

			notifyToolListeners();
		} else {
			ExceptionReporter.report("Could not set the ToolInstance to visible.");
		}
	}

	/**
	 * Add ToolInstance to the list of all ToolInstance that are visible. An
	 * error message will be shown in the consoleview when the list doesn't
	 * contains the ToolInstance.
	 *
	 * @param toolInstance the toolInstance thats need to be added.
	 */
	public void removeToolInstance(ToolInstance toolInstance) {
		if (m_toolsFilter.contains(toolInstance)) {
			m_toolsFilter.remove(toolInstance);

			notifyToolListeners();
		} else {
			ExceptionReporter.report("Could not set the ToolInstance to non-visible.");
		}
	}

	/**
	 * Inform {@link IProcessFilterListener}'s there is a new filter.
	 */
	private void notifyProcessListeners() {
		for (IProcessFilterListener filterListener : m_processListeners) {
			filterListener.setProcessFilter(m_processesFilter);
		}
	}

	/**
	 * Inform toolListeners there is a new filter
	 */
	private void notifyToolListeners() {
		for (IToolFilterListener listener : m_toolListeners) {
			listener.setToolFilter(m_toolsFilter);
		}
	}
}
