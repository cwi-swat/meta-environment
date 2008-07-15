package argusviewer.view.listeners;

import java.util.List;

import toolbus.tool.ToolInstance;

/**
 * Listener for tool filter settings.
 * 
 * @author T. Van Laer
 * @author J. Pol
 * @author J. van den Bos
 */
public interface IToolFilterListener {

    /**
	 * A filter has been set. The Tool in the list should be visible. All
	 * other processes should be hidden.
	 *
	 * @param filteredTools
	 *            List of Tools that should be visible.
	 */
	void setToolFilter(List<ToolInstance> filteredTools);
}
