package argusviewer.view.architectureview.performance.tree;

import javax.swing.tree.DefaultTreeModel;


import argusviewer.view.architectureview.performance.ToolPerformanceInfo;
import com.sun.java.treetable.example.TreeTableModel;

/**
 * This is the model which describes the structure in which the data for the
 * {@link PerformanceTreeTable} will be represented.
 * 
 * @author Jeldert Pol
 */
@SuppressWarnings("serial")
public class PerformanceTreeModel extends DefaultTreeModel implements
		TreeTableModel {
	private static final int HUNDRED = 100;

	private final String[] m_columnNames = { "Tool", "ID", "Processor Time",
			"in ms", "Memory Heap" };
	private final Class< ? >[] m_columnTypes = { TreeTableModel.class,
			String.class, Integer.class, Integer.class, String.class };

	public static final int TOOL_COLUMN = 0;
	public static final int ID_COLUMN = 1;
	public static final int PROCESSOR_PERCENTAGE_COLUMN = 2;
	public static final int PROCESSOR_TIME_COLUMN = 3;
	public static final int MEMORY_HEAP_COLUMN = 4;

	/**
	 * Constructor for the {@link PerformanceTreeModel}.
	 */
	public PerformanceTreeModel() {
		super(new PerformanceTreeNode());
	}

	/**
	 * {@inheritDoc}
	 */
	public Class< ? > getColumnClass(int column) {
		return m_columnTypes[column];
	}

	/**
	 * {@inheritDoc}
	 */
	public int getColumnCount() {
		return m_columnNames.length;
	}

	/**
	 * {@inheritDoc}
	 */
	public String getColumnName(int column) {
		return m_columnNames[column];
	}

	/**
	 * Return the value of a given column in a node
	 * 
	 * @param node
	 *            A {@link PerformanceTreeNode}, which value is to be
	 *            requested.
	 * @param column
	 *            The column index, determing the kind of value to return.
	 * @return The value of the column of the given node.
	 */
	public Object getValueAt(Object node, int column) {
		PerformanceTreeNode performanceTreeNode = (PerformanceTreeNode) node;

		switch (column) {
		case TOOL_COLUMN:
			return performanceTreeNode;
		case ID_COLUMN:
			return performanceTreeNode.getToolId();
		case PROCESSOR_PERCENTAGE_COLUMN:
			return processorPercentage(performanceTreeNode.getProcessorTime());
		case PROCESSOR_TIME_COLUMN:
			return performanceTreeNode.getProcessorTime();
		case MEMORY_HEAP_COLUMN:
			return performanceTreeNode.getToolMemoryHeapUsage();
		default:
			throw new RuntimeException(
					"PerformanceTreeModel: invalid column requested.");
		}
	}

	/**
	 * Returns the percentage of processor use of a tool, compared to all the
	 * tools. Example: Tool1 used 500ms, tool2 4500ms. This method returns 10
	 * for tool1 and 90 for tool2.
	 * 
	 * @param toolTime
	 *            the processor time of the tool the percentage is requested
	 *            for.
	 * @return the percentage of processor time, compared to all the tools.
	 */
	private Integer processorPercentage(Integer toolTime) {
		PerformanceTreeNode root = getPerformanceTree();
		int total = 0;
		for (int index = 0; index < root.getChildCount(); index++) {
			PerformanceTreeNode child = (PerformanceTreeNode) root
					.getChildAt(index);
			total += child.getProcessorTime();
		}

		Float percentage = 0f;
		if (total > 0) {
			percentage = (float) toolTime / total;
			percentage *= HUNDRED;
		}
		return percentage.intValue();
	}

	/**
	 * Set CellEditable to false, except for the tool column.
	 * 
	 * @param node
	 *            The node on which to perform
	 * @param column
	 *            Which column
	 * @return boolean true if cell is editable, false otherwise.
	 */
	public boolean isCellEditable(Object node, int column) {
		// Tool column must be editable, for a folder to be expandable by mouse
		return (column == TOOL_COLUMN);
	}

	/**
	 * {@inheritDoc}
	 */
	public void setValueAt(Object arg0, Object arg1, int arg2) {
		// Nothing to do
	}

	/**
	 * Get the whole {@link PerformanceTreeNode}.
	 * 
	 * @return PerformanceTreeNode
	 */
	public PerformanceTreeNode getPerformanceTree() {
		return (PerformanceTreeNode) getRoot();
	}

	/**
	 * Create a {@link PerformanceTreeNode} from a {@link ToolPerformanceInfo}
	 * and add this node as a child to the rootNode. If the toolname is the same
	 * it will be grouped.
	 * 
	 * @param toolPerformanceInfo
	 *            the ToolInstance
	 */
	public void add(ToolPerformanceInfo toolPerformanceInfo) {
		PerformanceTreeNode root = getPerformanceTree();

		boolean found = false;
		for (int i = 0; i < root.getChildCount(); i++) {
			PerformanceTreeNode node = (PerformanceTreeNode) root.getChildAt(i);
			// Check if toolname exists.
			if (node.getToolName().equals(toolPerformanceInfo.getToolName())) {
				// Name same, add to group.
				found = true;
				node.add(toolPerformanceInfo);
			}
		}

		// Toolname not found, add to root
		if (!found) {
			getPerformanceTree().add(
					new PerformanceTreeNode(toolPerformanceInfo));
		}

		nodeStructureChanged(getPerformanceTree());
	}

	/**
	 * Tell the model to focus on the tool (or group of tools) with the given
	 * name. This will select the tool. If it is a group it will also expand it.
	 * 
	 * @param toolName
	 *            name of tool to focus on.
	 * @return the row matching toolName.
	 */
	public int setFocus(String toolName) {
		PerformanceTreeNode root = getPerformanceTree();
		for (int index = 0; index < root.getChildCount(); index++) {
			PerformanceTreeNode child = (PerformanceTreeNode) root
					.getChildAt(index);
			if (child.getToolName().equals(toolName)) {
				return index;
			}
		}
		return -1;
	}

	/**
	 * Ask whether the row should be expanded when it is automaticly selected.
	 * If the row is a tool it returns false, if it is a group of tools it
	 * return true.
	 * 
	 * @param row the row where the focus is set on
	 * @return true if it should be expanded, false otherwise.
	 */
	public boolean expandOnFocus(int row) {
		if (row < getPerformanceTree().getChildCount()) {
			PerformanceTreeNode child = (PerformanceTreeNode) getPerformanceTree().getChildAt(row);
			if (child.getChildCount() > 0) {
				return !(child.getChildAt(0) instanceof PerformanceTreeNodeThread);
			}
			return false;
		} else {
			assert false;
			return false;
		}
	}
}
