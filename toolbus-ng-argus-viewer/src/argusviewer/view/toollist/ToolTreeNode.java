package argusviewer.view.toollist;

import javax.swing.tree.DefaultMutableTreeNode;

import toolbus.tool.ToolInstance;

/**
 * @author Alexander Bij
 * @author Roberto van der Linden
 */
public class ToolTreeNode extends DefaultMutableTreeNode {
	private static final long serialVersionUID = 3234422961304199997L;
	
	private ToolInstance m_toolInstance;
	private boolean m_isVisible;
	private boolean m_isRemoved; // items aren't really removed anymore, instead they are set as 'removed' so the items can still be set as visible/invisible even when removed.

	/**
	 * Default Constructor, used create rootNode
	 */
	public ToolTreeNode() {
		m_isVisible = false;
		m_isRemoved = false;
	}


	/**
	 * Check if this node has a toolInstance
	 *
	 * @return true if this node has a ToolInstance
	 */
	public boolean hasToolInstance() {
		return m_toolInstance != null;
	}

	/**
	 * Constructor
	 *
	 * @param toolInstance the ToolInstance which belongs to the node.
	 */
	public ToolTreeNode(ToolInstance toolInstance) {
		this.m_toolInstance = toolInstance;
		m_isVisible = false;
		m_isRemoved = false;
	}

	/**
	 * Gets the id of the Tool or null is the node is no tool
	 *
	 * @return the id of the Tool or null is the node is no tool
	 */
	public int getId() {
		if (hasToolInstance()) {
			return m_toolInstance.getToolID();
		}
		return -1;
	}

	/**
	 * Gets the name of the Tool, or the name of the child
	 *
	 * @return the name of the tool or child
	 */
	public String getName() {
		if (hasToolInstance()) {
			return m_toolInstance.getToolName();
		} else if (getChildCount() > 0) {
			ToolTreeNode child = (ToolTreeNode) getFirstChild();
			return child.getName();
		} else {
			//Root
			return "Tools";
		}
	}
		
	/**
	 * If the node has an item, it will return the item's removed state. 
	 * If the node is a parent, it will return false if one child is still 'live'. 
	 * Else, it will return true. 
	 * 
	 * @return removed status
	 */
	public boolean isRemoved() {
		if (m_toolInstance != null) {
			return m_isRemoved;
		}
		
		for (int index = 0; index < getChildCount(); index++) {
			ToolTreeNode node = (ToolTreeNode) getChildAt(index);
			
			if (!node.isRemoved()) {
				return false;
			}
		}
		
		return true;
	}
	
	/**
	 * Remove the node
	 * 
	 */
	public void remove() {
		m_isRemoved = true;
	}

	/**
	 * Get the visibility of the Tool.
	 *
	 * @return The visibility of the Tool.
	 */
	public boolean isVisible() {
		return m_isVisible;
	}

	/**
	 * Set the visibility of the Tool.
	 *
	 * @param isVisible the visibility of the tool.
	 */
	public void setVisible(boolean isVisible) {
		this.m_isVisible = isVisible;
	}

	/**
	 * Overrights the default toString. Gets the name of the ToolInstance.
	 *
	 * @return the name of the ToolInstance.
	 */
	public String toString() {
		return getName();
	}

	/**
	 * Gets the ToolInstance of this node
	 *
	 * @return  the ToolInstance of this node
	 */
	public ToolInstance getToolInstance() {
		return m_toolInstance;
	}
}
