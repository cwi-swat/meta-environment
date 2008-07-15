package argusviewer.view.toollist;

import java.util.Enumeration;

import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeNode;


import org.apache.log4j.Logger;
import org.junit.Assert;

import toolbus.tool.ToolInstance;

import argusviewer.toolbus.DataComm;
import argusviewer.util.ToolbusUtil;
import com.sun.java.treetable.example.TreeTableModel;

/**
 * Model for ToolTreeTable.
 * 
 * @author Alexander Bij
 * @author Roberto van der Linden
 */
@SuppressWarnings("serial")
public class ToolTreeModel extends DefaultTreeModel implements TreeTableModel {

	private final String[] m_columns = { "Visible", "Tool Name", "ID" };
	private final Class< ? >[] m_classTypes = { Boolean.class,
			TreeTableModel.class, Integer.class };

	protected static final int VISIBLE_COLUMN = 0;
	protected static final int TOOL_COLUMN = 1;
	protected static final int ID_COLUMN = 2;

	private Logger m_logger = Logger.getLogger(ToolTreeModel.class);
	private ToolTreeTable m_table;
	/**
	 * Constructor
	 * 
	 * @param root
	 *            the TreeNode which represents the rootnode
	 */
	public ToolTreeModel(TreeNode root) {
		super(root);
	}
	
	/**
	 * Sets the parent of the tree table
	 * @param table the new parent
	 */
	public void setParent(ToolTreeTable table) {
		this.m_table = table;
	}

	/**
	 * Get the index of columns.
	 * 
	 * @return The index of columns
	 */
	public int getColumnCount() {
		return m_columns.length;
	}

	/**
	 * Get the name of the specified column.
	 * 
	 * @param column
	 *            the index of the specified column.
	 * @return The name of the column
	 */
	public String getColumnName(int column) {
		return m_columns[column];
	}

	/**
	 * Get the class of the specified column.
	 * 
	 * @param column
	 *            the index of the specified column.
	 * @return The class of the column
	 */
	public Class< ? > getColumnClass(int column) {
		return m_classTypes[column];
	}

	/**
	 * Get the value at the specified column and node.
	 * 
	 * @param o
	 *            The ToolTreeNode to get the object from.
	 * @param column
	 *            the index of the specified column.
	 * @return The object of the cell of the specified column/node
	 */
	public Object getValueAt(Object o, int column) {
		ToolTreeNode node = (ToolTreeNode) o;
		switch (column) {
		case VISIBLE_COLUMN:
			return node.isVisible();
		case TOOL_COLUMN:
			return node;
		case ID_COLUMN:
			return node.getId();
		default:
			// not existing column
			return null;
		}
	}

	/**
	 * Returns true if column type is Visible , else returns false because cells
	 * are not editable.
	 * 
	 * @param o
	 *            The ToolTreeNode to get the object from.
	 * @param column
	 *            the index of the specified column.
	 * @return false true if column type is Visible , else returns false because
	 *         cells are not editable.
	 */
	public boolean isCellEditable(Object o, int column) {
		return column == VISIBLE_COLUMN || column == TOOL_COLUMN;
	}

	/**
	 * Sets a new value to Visible column. Values on other columns could not be
	 * set.
	 * 
	 * @param node
	 *            The node to set the value at.
	 * @param newValue
	 *            The new value for the node
	 * @param column
	 *            the index of the specified column.
	 */
	public void setValueAt(Object newValue, Object node, int column) {
		// FilterListener should be set.
		if (column == VISIBLE_COLUMN && newValue instanceof Boolean) {
			ToolTreeNode treeNode = (ToolTreeNode) node;
			Boolean isVisible = (Boolean) newValue;
			treeNode.setVisible(isVisible);

			/**
			 * Set first and second level children to the same visibility state
			 * Should be recursive, but the whole code isn't set up to be recursive. 
			 * Used a second while loop instead.
			 */
			Enumeration< ? > children = treeNode.children();
			while (children.hasMoreElements()) {
				ToolTreeNode child = (ToolTreeNode) children.nextElement();
				child.setVisible(isVisible);
				
				
				Enumeration< ? > childrenofChild = child.children();
				while (childrenofChild.hasMoreElements()) {
					ToolTreeNode childofChild = (ToolTreeNode) childrenofChild.nextElement();
					childofChild.setVisible(isVisible);
					
				}
			}

		} else {
			m_logger.debug("Could not set Value for Visible column");
		}
	}

	/**
	 * Create a ToolTreeNode from a ToolInstance and add this node as a child to
	 * the rootNode.
	 * 
	 * @param toolInstance
	 *            the ToolInstance
	 * @param dataComm an instance of the DataComm
	 */
	public void addToolInstance(ToolInstance toolInstance, DataComm dataComm) {
		boolean isAdded = false;
		ToolTreeNode root = (ToolTreeNode) getRoot();

		String toolName = toolInstance.getToolName();

		Enumeration< ? > children = root.children();

		while (children.hasMoreElements()) {
			ToolTreeNode node = (ToolTreeNode) children.nextElement();
			if (node.getName().equals(toolName)) {
				addOrCreateParent(root, node, toolInstance, dataComm);
				isAdded = true;
				break;
			}
		}
		if (!isAdded) {
			ToolTreeNode newChild = new ToolTreeNode(toolInstance);
			root.add(newChild);
			if (root.isVisible()) {
				dataComm.getFilterSync().addToolInstance(toolInstance);
				newChild.setVisible(true);
			}
		}

		if (m_table != null) {
			m_table.reloadModel();
		}
	}

	/**
	 * Adds the new ToolInstance as a new_node to sameNameNode. If sameNameNode
	 * has a ToolInstance a commonParent node is added for both new_node and
	 * sameNameNode.
	 * 
	 * @param root
	 *            The root node, to add new commonParent node.
	 * @param sameNameNode
	 *            Node with same name as ToolInstance.
	 * @param toolInstance
	 *            ToolInstance to add.
	 * @param dataComm an instance of the DataComm
	 */
	protected void addOrCreateParent(DefaultMutableTreeNode root,
			ToolTreeNode sameNameNode, ToolInstance toolInstance,
			DataComm dataComm) {
		ToolTreeNode newNode = new ToolTreeNode(toolInstance);

		if (!sameNameNode.hasToolInstance()) {
			sameNameNode.add(newNode);
			if (sameNameNode.isVisible()) {
				dataComm.getFilterSync().addToolInstance(toolInstance);
				newNode.setVisible(true);
			}

		} else {
			sameNameNode.removeFromParent();

			ToolTreeNode newParent = new ToolTreeNode();
			newParent.add(sameNameNode);
			sameNameNode.setParent(newParent);

			newParent.add(newNode);
			if (newParent.isVisible()) {
				dataComm.getFilterSync().addToolInstance(toolInstance);
				newNode.setVisible(true);
			}

			root.add(newParent);
		}
	}

	/**
	 * Remove a ToolTreeNode based on the ToolInstance
	 * 
	 * @param toolInstance
	 *            the ToolInstance that needs to be removed
	 */
	public void removeToolInstance(ToolInstance toolInstance) {
		ToolTreeNode root = (ToolTreeNode) getRoot();
		int toolInstanceId = ToolbusUtil.getToolIdFromKey(toolInstance
				.getToolKey());

		ToolTreeNode node = findToolTreeNodeByToolInstanceId(root,
				toolInstanceId);
		Assert
				.assertNotNull(
						"The node found by the ToolInstanceId should not be Null",
						node);

		node.remove();
		
		if (m_table != null) {
			m_table.reloadModel();
		}
		/*
		 * DefaultMutableTreeNode parent = (DefaultMutableTreeNode)
		 * node.getParent(); node.removeFromParent(); if (parent.getChildCount() ==
		 * 1) { DefaultMutableTreeNode child = (DefaultMutableTreeNode)
		 * parent.getChildAt(0); root.add(child); child.setParent(root);
		 * parent.removeFromParent(); }
		 * 
		 * nodeStructureChanged(root);
		 */
	}

	/**
	 * Find the ToolTreeNode by ToolInstance Id.
	 * 
	 * @param parent
	 *            the rootNode
	 * @param toolInstanceId
	 *            the id of the ToolInstance thats needs to be found
	 * @return the ToolInstance with the specified toolInstanceId
	 */
	public ToolTreeNode findToolTreeNodeByToolInstanceId(ToolTreeNode parent,
			int toolInstanceId) {
		if (parent.getId() != null && parent.getId() == toolInstanceId) {
			return parent;
		} else {
			Enumeration< ? > children = parent.children();
			ToolTreeNode foundNode = null;
			while (children.hasMoreElements() && foundNode == null) {
				ToolTreeNode child = (ToolTreeNode) children.nextElement();
				foundNode = findToolTreeNodeByToolInstanceId(child,
						toolInstanceId);
			}
			return foundNode;
		}
	}	
}
