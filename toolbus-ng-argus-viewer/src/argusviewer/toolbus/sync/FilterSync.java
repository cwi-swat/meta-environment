package argusviewer.toolbus.sync;

import java.util.ArrayList;
import java.util.List;

import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import argusviewer.ExceptionReporter;
import argusviewer.view.listeners.IProcessFilterListener;
import argusviewer.view.listeners.IToolFilterListener;

/**
 * This class keeps track of and manages all filters.
 *
 * @author Tim Van Laer
 * @author Jeldert Pol
 * @author Alexander Bij
 * @author Roberto van der Linden
 */
public class FilterSync{
	private final ArrayList<IProcessFilterListener> m_processListeners;
	private final ArrayList<IToolFilterListener> m_toolListeners;
	private final ArrayList<ProcessInstance> m_processesFilter;
	private final ArrayList<ToolInstance> m_toolsFilter;

	/**
	 * Constructor for the filter synchronizer
	 */
	public FilterSync(){
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
	public void register(IProcessFilterListener listener){
		synchronized(m_processListeners){
			m_processListeners.add(listener);
		}
	}

	/**
	 * Registers a listener. The listener will be informed about changes in the
	 * filter with regard to tools.
	 *
	 * @param listener A listener to be informed about changes in the filter.
	 */
	public void register(IToolFilterListener listener){
		synchronized(m_toolListeners){
			m_toolListeners.add(listener);
		}
	}

	/**
	 * Add {@link ProcessInstance} to the list of all {@link ProcessInstance}'s
	 * that are visible. An error message will be shown in the consoleview when
	 * the list already contains the {@link ProcessInstance}.
	 *
	 * @param processInstances the processInstances that must be added.
	 */
	public void addProcessInstance(List<ProcessInstance> processInstances){
		for(ProcessInstance processInstance : processInstances){
			synchronized(m_processesFilter){
				if(!m_processesFilter.contains(processInstance)){
					m_processesFilter.add(processInstance);
				}
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
	public void removeProcessInstance(List<ProcessInstance> processInstances){
		for(ProcessInstance processInstance : processInstances){
			synchronized(m_processesFilter){
				if(m_processesFilter.contains(processInstance)){
					m_processesFilter.remove(processInstance);
				}
			}
		}
		
		notifyProcessListeners();
	}

	/**
	 * Add ToolInstance to the list of all ToolInstance that are visible. An
	 * error message will be shown in the consoleview when the list does
	 * contains the ToolInstance.
	 *
	 * @param toolInstance the toolInstance thats need to be added.
	 */
	public void addToolInstance(ToolInstance toolInstance){
		synchronized(m_toolsFilter){
			if(!m_toolsFilter.contains(toolInstance)){
				m_toolsFilter.add(toolInstance);
	
				notifyToolListeners();
			}else{
				ExceptionReporter.report("Could not set the ToolInstance to visible.");
			}
		}
	}

	/**
	 * Add ToolInstance to the list of all ToolInstance that are visible. An
	 * error message will be shown in the consoleview when the list doesn't
	 * contains the ToolInstance.
	 *
	 * @param toolInstance the toolInstance thats need to be added.
	 */
	public void removeToolInstance(ToolInstance toolInstance){
		synchronized(m_toolsFilter){
			if(m_toolsFilter.contains(toolInstance)){
				m_toolsFilter.remove(toolInstance);
	
				notifyToolListeners();
			}else{
				ExceptionReporter.report("Could not set the ToolInstance to non-visible.");
			}
		}
	}

	/**
	 * Inform {@link IProcessFilterListener}'s there is a new filter.
	 */
	private void notifyProcessListeners(){
		synchronized(m_processListeners){
			for(IProcessFilterListener filterListener : m_processListeners){
				filterListener.setProcessFilter(m_processesFilter);
			}
		}
	}

	/**
	 * Inform toolListeners there is a new filter
	 */
	private void notifyToolListeners(){
		synchronized(m_toolListeners){
			for(IToolFilterListener listener : m_toolListeners){
				listener.setToolFilter(m_toolsFilter);
			}
		}
	}
}
