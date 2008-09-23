package argusviewer.view.toollist;

import java.util.Enumeration;
import java.util.List;
import argusviewer.toolbus.DataComm;
import argusviewer.toolbus.sync.ControlSync;
import argusviewer.toolbus.sync.FilterSync;
import argusviewer.toolbus.sync.FocusSync;
import argusviewer.view.listeners.IToolControlListener;

import toolbus.tool.ToolInstance;

/**
 * Responsible for all eventhandling of ToolListPlugin
 *
 * @author Alexander Bij
 * @author Roberto van der Linden
 */
public class ToolListController implements IToolControlListener {
	private final DataComm m_dataComm;
	
	private final ToolTreeModel m_toolTreeModel;
	private final ToolListView m_toolListView;
	
	private volatile FilterSync m_filterSync;
	private volatile FocusSync m_focusSync;

	/**
	 * Constructor for ToolListController.
	 * Registers all necessary syncs.
	 *
	 * @param dataComm	 DataComm is needed for the interaction.
	 * @param toolListView the ToolListView
	 */
	public ToolListController(DataComm dataComm, ToolListView toolListView) {
		m_toolListView = toolListView;
		m_dataComm = dataComm;
		
		ToolTreeNode rootNode = new ToolTreeNode();

		setFilterSync(dataComm.getFilterSync());
		setFocusSync(dataComm.getFocusSync());
		ControlSync controlSync = dataComm.getControlSync();

		controlSync.register(this);

		List<ToolInstance> tools = dataComm.getControlSync().getTools();
		rootNode = loadTools(rootNode, tools);

		m_toolTreeModel = new ToolTreeModel(rootNode);
		m_toolListView.createTable(m_toolTreeModel, this);
	}

	/**
	 * Adds all tools to the rootNode.
	 *
	 * @param rootNode the rootNode of the tree
	 * @param tools	a list of ToolInstances
	 * @return rootNode with all tools as children
	 */
	protected ToolTreeNode loadTools(ToolTreeNode rootNode, List<ToolInstance> tools) {
		for (ToolInstance instance : tools) {
			ToolTreeNode node = new ToolTreeNode(instance);
			rootNode.add(node);
		}

		return rootNode;
	}

	/**
	 * The VisibleFilter of this node is Changed.
	 * add/remove from Filter of m_filterSync,
	 * Same for the children of node, if it has any.
	 *
	 * @param node The Node that has changed Visability
	 */
	protected void changedNodeFilter(ToolTreeNode node) {
		// If has a toolinstance (no children), add/remove this Node from filter
		if (node.hasToolInstance()) {
			if (node.isVisible()) {
				m_filterSync.addToolInstance(node.getToolInstance());
			} else {
				m_filterSync.removeToolInstance(node.getToolInstance());
			}
			// Else add/remove Children to filter.
		} else {
			Enumeration< ? > children = node.children();
			while (children.hasMoreElements()) {
				ToolTreeNode child = (ToolTreeNode) children.nextElement();
				if (child.hasToolInstance()) {
					if (child.isVisible()) {
						m_filterSync.addToolInstance(child.getToolInstance());
					} else {
						m_filterSync.removeToolInstance(child.getToolInstance());
					}
				}
			}
		}
		m_toolListView.refresh();
	}

	/**
	 * Check whick column is clicked and passes the node further
	 *
	 * @param clickCount the amount of mouse clicks
	 * @param column	 the column on which the click is executed
	 * @param node	   the node on which the click is executed
	 */
	public void sendClickEvent(int clickCount, int column, ToolTreeNode node) {
		switch (column) {
			case ToolTreeModel.VISIBLE_COLUMN:
					changedNodeFilter(node);
				break;
			case ToolTreeModel.TOOL_COLUMN:
				if (clickCount == 1) {
					m_focusSync.setHighlight(node.getToolInstance());
				}
				if (clickCount == 2) {
					m_focusSync.setFocus(node.getToolInstance());
				}
				break;
			default:
				// No need to do anything
				break;
		}
	}

	//-------------------------------------------------------------------------------
	// Methods implements from IControlListener
	//-------------------------------------------------------------------------------

	/**
	 * {@inheritDoc}
	 */
	public void addToolInstance(ToolInstance toolInstance) {
		m_toolTreeModel.addToolInstance(toolInstance, m_dataComm);
		m_toolListView.refresh();
	}

	/**
	 * {@inheritDoc}
	 */
	public void removeToolInstance(ToolInstance toolInstance) {
		m_toolTreeModel.removeToolInstance(toolInstance);
		m_toolListView.refresh();
	}
	
	/**
	 * Sets the filterSync.
	 *
	 * @param filterSync the new filterSync to set.
	 */
	protected void setFilterSync(FilterSync filterSync) {
		this.m_filterSync = filterSync;
	}

	/**
	 * Set the focusSync
	 *
	 * @param focusSync the new focusSync to set.
	 */
	protected void setFocusSync(FocusSync focusSync) {
		this.m_focusSync = focusSync;
	}

}
