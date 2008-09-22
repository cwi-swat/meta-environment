package argusviewer.view.toollist;

import java.awt.Component;
import java.awt.Point;
import java.util.HashMap;

import javax.swing.ImageIcon;
import javax.swing.JTree;
import javax.swing.tree.DefaultTreeCellRenderer;

import com.sun.java.treetable.example.JTreeTable;

/**
 * Table with information about the Tools of a ToolBus script.
 *
 * @author Alexander Bij
 * @author Roberto van der Linden
 */
public class ToolTreeTable extends JTreeTable {
	private static final long serialVersionUID = 2789153921245474573L;
	
	private ToolListController m_toolListController;
	private ToolTreeModel m_model;
	
	/**
	 * Constructor which calls super with toolTreeModel
	 *
	 * @param toolTreeModel toolTreeModel
	 * @param toolListController toolListController
	 */
	public ToolTreeTable(ToolTreeModel toolTreeModel, ToolListController toolListController) {
		super(toolTreeModel);
		m_toolListController = toolListController;
		m_model = toolTreeModel;

		addMouseListener(new ToolTreeMouseListener(this));
		setCellSelectionEnabled(true);
		setIcons();
	}

	private void setIcons() {
		DefaultTreeCellRenderer renderer = new ToolTreeCellRenderer();
		tree.setCellRenderer(renderer);
	}

	/**
	 * Calls the methods invalidate() and repaint() to refresh the table
	 */
	public void refresh() {
		invalidate();
		repaint();
	}


	/**
	 * Converts a x, y point to column and row and sends it to the
	 * ProcessTreeModel.
	 *
	 * @param clickCount the number of clicks
	 * @param x the x position of the mouse cursor
	 * @param y the y position of the mouse cursor
	 */
	public void sendClickEvent(int clickCount, int x, int y) {
		Point clickPoint = new Point(x, y);
		int column = columnAtPoint(clickPoint);
		int row = rowAtPoint(clickPoint);

		// -1 is no row selected
		if (getSelectedRow() != -1) {
			ToolTreeNode node = (ToolTreeNode) getValueAt(row, ToolTreeModel.TOOL_COLUMN);
			m_toolListController.sendClickEvent(clickCount, column, node);
		}
	}

	/**
	 * Set the ToolListController
	 *
	 * @param toolListController toolListController
	 */
	public void setToolListController(ToolListController toolListController) {
		this.m_toolListController = toolListController;
	}

	/**
	 * Reloads the model, without changing which nodes are open. 
	 * nodeStructureChanged, the Swing method of doing this, doesn't always work. 
	 * Besides that, nodeStructureChanged closes nodes when it shouldn't
	 * 
	 */
	public void reloadModel() {
		HashMap<ToolTreeNode, Boolean> isExpanded = new HashMap<ToolTreeNode, Boolean>(tree.getRowCount());
		
		//save expanded state
		for (int i = 0; i < tree.getRowCount(); i++) {
			ToolTreeNode node = getNodeAtRow(i);
			if (node != null && !node.isLeaf()) {
				isExpanded.put(node, Boolean.valueOf(tree.isExpanded(i)));
			}
		}
		m_model.reload();
	
		//restore expanded state
		for (int i = 0; i < tree.getRowCount(); i++) {
			ToolTreeNode node = getNodeAtRow(i);
			if (node != null && !node.isLeaf()) {
				//if the node had no expanded state, it will not be expanded
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
	 * Gets the node at the specified row
	 * 
	 * @param row the rowIndex
	 * @return the node at the specified row
	 */
	private ToolTreeNode getNodeAtRow(int row) {
		return (ToolTreeNode) getValueAt(row, ToolTreeModel.TOOL_COLUMN);
	}
}

/**
 * Draws a Tool Tree Cell
 * @author Hidde Baggelaar
 *
 */
class ToolTreeCellRenderer extends DefaultTreeCellRenderer  {
	private static final long serialVersionUID = -3084040025754474656L;
	
	private static final ImageIcon GROUP_ICON = new ImageIcon("resources/icons/group.png");
	private static final ImageIcon TOOL_ICON = new ImageIcon("resources/icons/tool.png");
	
	/**
	 * Creates a ProcessTreeCellRenderer
	 */
	public ToolTreeCellRenderer() {
		setLeafIcon(TOOL_ICON);
		setOpenIcon(GROUP_ICON);
		setClosedIcon(GROUP_ICON);
	}
	
	/**
	 * {@inheritDoc}
	 */
	public Component getTreeCellRendererComponent(JTree tree, Object value,
			boolean selected, boolean expanded, boolean leaf, int row,
			boolean hasFocus) {
		Component temp =  super.getTreeCellRendererComponent(tree, value,
				selected, expanded, leaf, row,
				hasFocus);
			
		ToolTreeNode node = (ToolTreeNode) value;
		
		if (node.isRemoved()) { 
			temp.setEnabled(false);
		} else {
			temp.setEnabled(true);
		}
			
		return temp;
	}
}
