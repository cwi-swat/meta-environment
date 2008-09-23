package argusviewer.view.architectureview.performance.tree;

import javax.swing.JTree;
import javax.swing.SwingConstants;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.tree.DefaultTreeCellRenderer;

import argusviewer.view.architectureview.performance.ToolPerformanceInfo;

import com.sun.java.treetable.example.JTreeTable;
import com.sun.java.treetable.example.TreeTableModel;

/**
 * The PerformanceTreeTable shows the performance of the Tools connected to the
 * ToolBus.
 * 
 * A TreeTable is a combination of a Tree and a Table -- a component capable of
 * both expanding and contracting rows, as well as showing multiple columns of
 * data.
 * 
 * @author Jeldert Pol
 */
public class PerformanceTreeTable extends JTreeTable {
	private static final long serialVersionUID = 2898389345356146073L;
	
	private final PerformanceTreeModel model;

	/**
	 * Constructor for {@link PerformanceTreeTable}.
	 */
	public PerformanceTreeTable() {
		this(new PerformanceTreeModel());
	}

	private PerformanceTreeTable(PerformanceTreeModel treeTableModel) {
		super(treeTableModel);
		this.model = treeTableModel;

		DefaultTreeCellRenderer toolPerformanceRenderer = new ToolPerformanceRenderer();
		this.getTree().setCellRenderer(toolPerformanceRenderer);

		// Processor renderer
		getColumnModel().getColumn(PerformanceTreeModel.PROCESSOR_PERCENTAGE_COLUMN).setCellRenderer(new ProcessorRenderer());

		// Left align processor ms column
		DefaultTableCellRenderer leftAlignRenderer = new DefaultTableCellRenderer();
		leftAlignRenderer.setHorizontalAlignment(SwingConstants.LEFT);
		getColumnModel().getColumn(PerformanceTreeModel.PROCESSOR_TIME_COLUMN).setCellRenderer(leftAlignRenderer);

		// Right align memory columns, to be consistent with other views and
		// looks better.
		DefaultTableCellRenderer rightAlignRenderer = new DefaultTableCellRenderer();
		rightAlignRenderer.setHorizontalAlignment(SwingConstants.RIGHT);
		getColumnModel().getColumn(PerformanceTreeModel.ID_COLUMN).setCellRenderer(rightAlignRenderer);
		getColumnModel().getColumn(PerformanceTreeModel.MEMORY_HEAP_COLUMN).setCellRenderer(rightAlignRenderer);

		tree.setRootVisible(false);
		setCellSelectionEnabled(true);
		this.setDoubleBuffered(true);
	}

	/**
	 * Return the JTree
	 * 
	 * @return JTree
	 */
	private JTree getTree() {
		return (JTree) this.getDefaultRenderer(TreeTableModel.class);
	}

	/**
	 * Add a {@link ToolPerformanceInfo} to the {@link PerformanceTreeModel}.
	 * 
	 * @param toolPerformanceInfo
	 *            ToolPerformanceInfo
	 */
	public void add(ToolPerformanceInfo toolPerformanceInfo) {
		model.add(toolPerformanceInfo);
		refresh();
	}

	/**
	 * Tell the table to focus on the tool (or group of tools) with the given
	 * name. This will select the tool. If it is a group it will also expand it.
	 * 
	 * @param toolName
	 *            name of tool to focus on.
	 */
	public void setFocus(String toolName) {
		int row = model.setFocus(toolName);
		if(row >= 0){
			changeSelection(row, PerformanceTreeModel.TOOL_COLUMN, false, false);
			if(model.expandOnFocus(row)){
				tree.expandRow(row);
			}
		}else{
			clearSelection();
		}
	}

	/**
	 * Resync the model and repaint
	 */
	public void refresh(){
		invalidate();
		repaint();
	}
}
