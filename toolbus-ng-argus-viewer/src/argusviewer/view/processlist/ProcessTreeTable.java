package argusviewer.view.processlist;

import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.HashMap;

import javax.swing.JTree;
import javax.swing.SwingConstants;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.TableColumn;
import javax.swing.tree.DefaultTreeCellRenderer;


import org.apache.log4j.Logger;

import argusviewer.toolbus.DataComm;
import argusviewer.view.processlist.data.ProcessTreeModel;
import argusviewer.view.processlist.data.ProcessTreeNode;
import argusviewer.view.processlist.data.ProcessTreeNode.BreakPointType;
import argusviewer.view.processlist.renderer.BreakPointCellRenderer;
import argusviewer.view.processlist.renderer.ProcessTreeCellRenderer;
import com.sun.java.treetable.example.JTreeTable;
import com.sun.java.treetable.example.TreeTableModel;

/**
 * The standard JTreeTable has been extended with functions to add and subtract
 * {@link toolbus.process.ProcessInstance}. The {@link ProcessTreeTable} also
 * has been given a {@link ProcessTreeTableMouseListener}.
 * 
 * A TreeTable is a combination of a Tree and a Table -- a component capable of
 * both expanding and contracting rows, as well as showing multiple columns of
 * data.
 * 
 * @author R.Schuddeboom
 * @author H.Baggelaar
 * @author Jeldert Pol
 */
public class ProcessTreeTable extends JTreeTable {
	private static final long serialVersionUID = -5311053048872523305L;
	
	private ProcessTreeModel m_model;
	private static final int MAXCOLUMNWIDTH = 50;
	private Logger m_logger = Logger.getLogger(ProcessTreeTable.class);

	/**
	 * The constructor of the ProcessTreeTable
	 * 
	 * @param dataComm
	 *            the DataComm
	 */
	public ProcessTreeTable(DataComm dataComm) {
		this(new ProcessTreeModel(dataComm));
	}

	/**
	 * Constructor. When creating a new instance of {@link JTreeTable}, the
	 * super-constructor needs to be called, with a {@link DefaultTreeModel}.
	 * This private constructor exists to hide this detail from the other
	 * classes.
	 * 
	 * @param treeModel
	 */
	private ProcessTreeTable(ProcessTreeModel treeModel) {
		super(treeModel);
		m_model = treeModel;
		m_model.setParent(this);

		alignColumns();
		setRenderers();

		/**
		 * add click event listener, nothing more. If clicked, send a clickEvent
		 * to the model.
		 */
		addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				sendClickEvent(e.getClickCount(), e.getX(), e.getY());
			}
		});

		setCellSelectionEnabled(true);
	}

	private void setRenderers() {
		setDefaultRenderer(BreakPointType.class, new BreakPointCellRenderer());

		// Right align ID column, to be consistent with other views and looks
		// better.
		DefaultTableCellRenderer tableCellRenderer = new DefaultTableCellRenderer();
		tableCellRenderer.setHorizontalAlignment(SwingConstants.RIGHT);
		getColumn(ProcessTreeModel.ID_COLUMN)
				.setCellRenderer(tableCellRenderer);

		// Add a new tree renderer that has the tree icons we want to display
		DefaultTreeCellRenderer treeRenderer = new ProcessTreeCellRenderer();
		getTree().setCellRenderer(treeRenderer);
	}

	private void alignColumns() {
		// Set max width for all columns, expect for INSTANCENAME_COLUMN. This
		// makes this column resizable.
		setMaxWidth(ProcessTreeModel.BREAKPOINT_COLUMN, MAXCOLUMNWIDTH);
		setMaxWidth(ProcessTreeModel.FILTER_COLUMN, MAXCOLUMNWIDTH);
		setMaxWidth(ProcessTreeModel.ID_COLUMN, MAXCOLUMNWIDTH);
	}

	private void setMaxWidth(int column, int width) {
		getColumn(column).setMaxWidth(width);
	}

	private TableColumn getColumn(int column) {
		return getColumnModel().getColumn(column);
	}

	/**
	 * Return the JTree
	 * 
	 * @return JTree
	 */
	public JTree getTree() {
		return (JTree) this.getDefaultRenderer(TreeTableModel.class);
	}

	/**
	 * Reloads the model, without changing which nodes are open.
	 * nodeStructureChanged, the Swing method of doing this, doesn't always
	 * work. Besides that, nodeStructureChanged closes nodes when it shouldn't
	 * 
	 */
	public void reloadModel() {
		HashMap<ProcessTreeNode, Boolean> isExpanded = new HashMap<ProcessTreeNode, Boolean>(
				tree.getRowCount());

		// save expanded state
		for (int i = 0; i < tree.getRowCount(); i++) {
			ProcessTreeNode node = getNodeAtRow(i);
			if (node != null && !node.isLeaf()) {
				isExpanded.put(node, Boolean.valueOf(tree.isExpanded(i)));
			}
		}
		m_model.reload();

		// restore expanded state
		for (int i = 0; i < tree.getRowCount(); i++) {
			ProcessTreeNode node = getNodeAtRow(i);
			if (node != null && !node.isLeaf()) {
				// if the node had no expanded state, it will not be expanded
				boolean expanded = isExpanded.get(node) != null && isExpanded.get(node).booleanValue();
				if (expanded) {
					tree.expandRow(i);
				}
			}
		}

		invalidate();
		requestFocusInWindow();
		repaint();
	}

	/**
	 * Converts a x, y point to column and row and sends it to the
	 * ProcessTreeModel.
	 * 
	 * @param count
	 *            Number of clicks
	 * @param x
	 *            The x position of the mouse cursor
	 * @param y
	 *            The y position of the mouse cursor
	 */
	public void sendClickEvent(int count, int x, int y) {
		m_logger.debug("instanceClicked");
		Point clickPoint = new Point(x, y);
		int column = columnAtPoint(clickPoint);
		int row = rowAtPoint(clickPoint);

		getTree().setSelectionRow(row);
		ProcessTreeNode node = getNodeAtRow(row);
		if (node == null) {
			return;
		}
		m_model.clickEventAt(node, column, count);
	}

	/**
	 * Gets the node at the specified row
	 * 
	 * @param row
	 *            the rowIndex
	 * @return the node at the specified row
	 */
	private ProcessTreeNode getNodeAtRow(int row) {
		return (ProcessTreeNode) getValueAt(row,
				ProcessTreeModel.INSTANCENAME_COLUMN);
	}

	/**
	 * {@inheritDoc}
	 */
	public Object getValueAt(int row, int column) {
		try {
			return super.getValueAt(row, column);
		} catch (RuntimeException e) {
			// there is a bug in the treetablemodel apparently
			return null;
		}
	}
}
