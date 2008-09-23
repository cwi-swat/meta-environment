package argusviewer.view.processlist.data;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import javax.swing.tree.DefaultTreeModel;

import toolbus.process.ProcessInstance;
import argusviewer.toolbus.DataComm;
import argusviewer.view.listeners.IFileBreakPointListener;
import argusviewer.view.listeners.IProcessFilterListener;
import argusviewer.view.listeners.IProcessInstanceControlListener;
import argusviewer.view.processlist.ProcessTreeTable;
import argusviewer.view.processlist.data.ProcessTreeNode.BreakPointType;

import com.sun.java.treetable.example.TreeTableModel;

/**
 * This is the model which describes the structure in which the data for the
 * {@link ProcessTreeTable} will be represented.
 * 
 * @author R.Schuddeboom
 * @author H.Baggelaar
 * @author Jeldert Pol
 */
public class ProcessTreeModel extends DefaultTreeModel implements TreeTableModel, IProcessInstanceControlListener, IFileBreakPointListener, IProcessFilterListener  {
	private static final long serialVersionUID = -5813021647911033239L;
	
	/**
	 * column information, names and types
	 */
	private static final String[] COLUMN_NAMES = { "Break", "Visible", "ProcessName", "ID" };
	private static final Class< ? >[] COLUMN_TYPES = { BreakPointType.class, Boolean.class, TreeTableModel.class, String.class };
		
	public static final int BREAKPOINT_COLUMN = 0;
	public static final int FILTER_COLUMN = 1;
	public static final int INSTANCENAME_COLUMN = 2;
	public static final int ID_COLUMN = 3;
	
	private final DataComm m_dataComm; 
	
	private ProcessTreeTable m_table;


    /**
	 * The constructor for the ProcessTreeModel
	 * @param dataComm the DataComm
	 */
	public ProcessTreeModel(DataComm dataComm) {
		super(new ProcessTreeNode());
		
		m_dataComm = dataComm;		
		m_dataComm.getBreakPointSync().register(this);
		m_dataComm.getControlSync().register(this);
		m_dataComm.getFilterSync().register(this);
		
		getProcesses();
	}
	
	/**
	 * Sets the parent of the model, so the model can request the parent to repaint
	 * 
	 * @param parent the parent
	 */
	public void setParent(ProcessTreeTable parent) {
		m_table = parent;
	}


	/**
	 * The Following methods come from the TreeTableNode interface
	 * 
	 * @return the number of columns
	 */
	public int getColumnCount() {
		return COLUMN_NAMES.length;
	}

	/**
	 * @param column
	 *            the column index
	 * @return the name of the column
	 */
	public String getColumnName(int column) {
		return COLUMN_NAMES[column];
	}

	/**
	 * @param column
	 *            the column index
	 * @return the type of the column
	 */
	public Class<?> getColumnClass(int column) {
		return COLUMN_TYPES[column];
	}

	/**
	 * Return the value of a given column in a node
	 * 
	 * @param node
	 *            A {@link ProcessTreeNode}, which value is to be requested.
	 * @param column
	 *            The column index, determing the kind of value to return.
	 * @return The value of the column of the given node.
	 */
	public Object getValueAt(Object node, int column) {
		// "Break", "Visible", "ProcesName", "ID"
		ProcessTreeNode tree = (ProcessTreeNode) node;
		
		switch (column) {
		case BREAKPOINT_COLUMN:
			return tree.getBreakPointType();
		case FILTER_COLUMN:
			return Boolean.valueOf(tree.isVisible());
		case INSTANCENAME_COLUMN:
			return tree;
		case ID_COLUMN:
			return tree.getID();
		default:
			throw new RuntimeException("ProcessTreeModel: invalid column requested.");
		}
		
	}

	/**
	 * Set the CellEditable always to false
	 * 
	 * @param node
	 *            The node on which to perform
	 * @param column
	 *            Which column
	 * @return boolean
	 */
	public boolean isCellEditable(Object node, int column) {
		// Tree column must be editable, for a folder to be expandable by mouse
		return (column == INSTANCENAME_COLUMN);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setValueAt(Object arg0, Object arg1, int arg2) {
		//function not used to set values, but has to be implemented because of the interface
	}

	/**
	 * Get the whole ProcessTreeNode
	 * 
	 * @return ProcessTreeNode
	 */
	public ProcessTreeNode getProcessTree() {
		return (ProcessTreeNode) getRoot();
	}

	/**
	 * Get a {@link ProcessTreeNode} by entering the ID of a
	 * {@link ProcessInstance}.
	 * 
	 * @param processID
	 *            ProcessID
	 * @return ProcessTreeNode
	 */
	private ProcessTreeNode getProcessTree(int processID) {
		return getProcessTree().getTree(processID);
	}

	/**
	 * Apply a visibility filter to the processes.
	 * 
	 * @param processInstances
	 *            {@link ProcessInstance}'s the filter is applied to.
	 */
	public void setProcessFilter(List<ProcessInstance> processInstances) {
		clearFilter(getProcessTree());
		for (ProcessInstance processInstance : processInstances) {
			setProcessFilter(processInstance, true);
		}
	}

	/**
	 * Clear the visibility filter for node, and all it's children.
	 * 
	 * @param node
	 *            The node to clear. All children will also be cleared.
	 */
	private void clearFilter(ProcessTreeNode node) {
		setFilter(node, false);
	}

	/**
	 * Set the visibility filter for node, and all it's children.
	 * 
	 * @param node
	 *            The node to clear. All children will also be cleared.
	 * @param visible
	 *            Indicates the visibility of the process.
	 */
	private void setFilter(ProcessTreeNode node, boolean visible) {		
		ProcessTreeListItem item = node.getItem();

		if (item != null) {
			// Processinstance
			item.setFilter(visible);
		} else {
			// Processgroup, clear all children
			for (int i = 0; i < node.getChildCount(); i++) {
				setFilter((ProcessTreeNode) node.getChildAt(i), visible);
			}
		}
	}

	/**
	 * Sets the visibility filter on a process.
	 * 
	 * @param processInstance
	 *            The process the filter applies to.
	 * @param filter
	 *            True when visible, false when invisible.
	 */
	private void setProcessFilter(ProcessInstance processInstance,
			boolean filter) {
		ProcessTreeNode node = getProcessTree().getTree(
				processInstance.getProcessId());
		if (node == null) {
			return;
		}
		
		ProcessTreeListItem item = node.getItem();

		if (item != null) {
			item.setFilter(filter);
		}
	}

	/**
	 * Adds a process breakpoint
	 * 
	 * @param processInstance the instance to set the breakpoint on
	 */
	public void addProcessBreakpoint(ProcessInstance processInstance) {
		ProcessTreeNode tree = getProcessTree(processInstance.getProcessId());
		tree.getItem().setBreakPoint(true);
		nodeChanged(tree);
	}

	/**
	 * Removes a process breakpoint
	 * 
	 * @param processInstance the instance to remove the breakpoint from
	 */
	public void removeProcessBreakpoint(ProcessInstance processInstance) {
		ProcessTreeNode tree = getProcessTree(processInstance.getProcessId());
		tree.getItem().setBreakPoint(false);
		nodeChanged(tree);
	}
	
	/**
	 * nodeStructureChanged doesn't always work. The table has a better model reloading algorithm.
	 */
	private void reloadModel(ProcessTreeNode node) {
		//nodeStructureChanged(node);
		if (m_table != null) {
			m_table.reloadModel();
		}		
	}

	/**
	 * Tell the modem there was a click event at the specified node and column
	 * 
	 * @param node the node
	 * @param column the column
	 * @param clickCount the clickCount
	 */
	public void clickEventAt(ProcessTreeNode node, int column, int clickCount) {
		
		if (clickCount == 1) {
			switch (column) {
			case BREAKPOINT_COLUMN:
				breakProcess(node);
				break;
			case FILTER_COLUMN:
				filterProcess(node);
				break;
			case INSTANCENAME_COLUMN:
				if (node.getItem() != null) {
					m_dataComm.getFocusSync().setHighlight(node.getItem().getProcessInstance());
				}
				break;
			default:
				// No need to do anything
				break;
			}
		} else if (clickCount == 2 && column == INSTANCENAME_COLUMN) {
			if (node.getItem() != null) {
				m_dataComm.getFocusSync().setFocus(node.getItem().getProcessInstance());
			}
		}
	}
	
	private void breakProcess(ProcessTreeNode node) {
        boolean isBreaking = node.hasProcessBreakpoint();
        node.setProcessBreakpoint(!isBreaking);
		reloadModel(node);
	}

	private void filterProcess(ProcessTreeNode node) {
		boolean isVisible = node.isVisible();
		boolean visible = !isVisible;
		ArrayList<ProcessInstance> filteredInstances = new ArrayList<ProcessInstance>(node.getChildCount() + 1);
		node.setVisible(visible, filteredInstances);
		if (visible) {
			m_dataComm.getFilterSync().addProcessInstance(filteredInstances);
		} else {
			m_dataComm.getFilterSync().removeProcessInstance(filteredInstances);
		}
		reloadModel(node);
	}

	/**
	 * Add current processes from {@link DataComm} to the table.
	 */
	private void getProcesses() {
		List<ProcessInstance> list = m_dataComm.getControlSync().getProcesses();
		for (ProcessInstance processInstance : list) {
			addProcessInstance(processInstance);
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void addBreakpoint(String fileName, int lineNumber) {
		Map<String, Integer> processes = m_dataComm.getBreakPointSync().getSourceCodeBreakpoints();
		synchronized(processes){
			this.getProcessTree().syncSourceCodeBreakpoints(processes);
		}
		this.reloadModel(null);
	}

	/**
	 * {@inheritDoc}
	 */
	public void removeBreakpoint(String fileName, int lineNumber){
		Map<String, Integer> processes = m_dataComm.getBreakPointSync().getSourceCodeBreakpoints();
		synchronized(processes){
			this.getProcessTree().syncSourceCodeBreakpoints(processes);
		}
		this.reloadModel(null);
	}

	/**
	 * Add a {@link ProcessInstance} to the {@link ProcessTreeNode}.
	 * 
	 * @param processInstance
	 *            {@link ProcessInstance} to be added.
	 */
	public void addProcessInstance(ProcessInstance processInstance) {
		/*ProcessTreeNode newNode = */getProcessTree().add(processInstance, m_dataComm);
		reloadModel(getProcessTree());
	}
	

	/**
	 * Remove a {@link ProcessInstance} from the {@link ProcessTreeNode}.
	 * 
	 * @param processInstance
	 *            {@link ProcessInstance} to be removed.
	 */
	public void removeProcessInstance(ProcessInstance processInstance) {
		ProcessTreeNode parentOfRemovedNode = getProcessTree().remove(processInstance);
		reloadModel(parentOfRemovedNode);		
	}

}

