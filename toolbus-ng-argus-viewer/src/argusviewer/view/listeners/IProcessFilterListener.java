package argusviewer.view.listeners;

import java.util.List;

import toolbus.process.ProcessInstance;

/**
 * Listener for process filter settings.
 * 
 * @author T. Van Laer
 * @author J. Pol
 * @author J. van den Bos
 */
public interface IProcessFilterListener{
	/**
	 * A filter has been set. The processes in the list should be visible. All
	 * other processes should be hidden.
	 * 
	 * @param filteredProcesses
	 *            List of processes that should be visible.
	 */
	void setProcessFilter(List<ProcessInstance> filteredProcesses);
}
