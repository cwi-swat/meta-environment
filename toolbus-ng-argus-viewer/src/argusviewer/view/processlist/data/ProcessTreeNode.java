package argusviewer.view.processlist.data;

import java.util.List;
import java.util.Map;

import javax.swing.tree.DefaultMutableTreeNode;

import toolbus.process.ProcessInstance;
import argusviewer.toolbus.DataComm;

/**
 * The ProcessTreeNode is a JTree Data Model that is used by the JTreeTable
 * component. The ProcessTreeNode creates a tree model based on the
 * ProcessListItems added to it. When a ProcessTreeListItem is added, the Tree
 * Model is updated. Similar ProcessListItems are grouped in one single Tree
 * node.
 * 
 * Basically, it is a node in the table. A node can contain multiple nodes. Eg,
 * a process in the table is a node. A folder containing multiple processes is
 * also a node.
 * 
 * @author H.Baggelaar
 * @author R.Schuddeboom
 * @author Jeldert Pol
 */
public class ProcessTreeNode extends DefaultMutableTreeNode{
	private static final long serialVersionUID = -1647785404014342231L;

	/**
	 * The different BreakPointTypes for the treenodes
	 */
	public static enum BreakPointType {NONE, PROCESS, LINE, BOTH}

	private volatile ProcessTreeListItem m_item;
	private volatile boolean m_hasSourceCodeBreakpoint = false;
	
	/**
	 * The constructor creates a process tree. By default it has no breakpoint,
	 * and is visible.
	 */
	public ProcessTreeNode(){
		super();
	}

	/**
	 * Add a new {@link ProcessTreeListItem} to the children of the tree.
	 * 
	 * @param item
	 *            a new ProcessTreeListItem
	 */
	private void addChild(ProcessTreeListItem item){
		ProcessTreeNode child = new ProcessTreeNode();
		child.setItem(item);
		
		item.setFilterAndPropagate(this.isVisible());		
		add(child);
	}

	/**
	 * Returns the {@link ProcessTreeNode} containing the item with the same ID.
	 * Returns null if the tree isn't found.
	 * 
	 * @param instanceID
	 *            The ID of the {@link ProcessTreeNode} to get.
	 * @return A {@link ProcessTreeNode} matching the instanceID, or null.
	 */
	public ProcessTreeNode getTree(int instanceID){
		if(m_item != null && m_item.getProcessInstanceID() == instanceID){
			return this;
		}

		for(int i = 0; i < getChildCount(); i++){
			ProcessTreeNode child = (ProcessTreeNode) getChildAt(i);
			ProcessTreeNode search = child.getTree(instanceID);
			if(search != null){
				return search;
			}
		}

		return null;
	}

	/**
	 * Get the first ProcessTree with an item which matches the given
	 * instanceName.
	 * 
	 * @param instanceName
	 *            The name of the {@link ProcessTreeNode} to get.
	 * @return A {@link ProcessTreeNode} matching the instanceID, or null.
	 */
	public ProcessTreeNode getTree(String instanceName){
		if(m_item != null && m_item.getProcessInstanceName().equals(instanceName)){
			return this;
		}

		for(int i = 0; i < getChildCount(); i++){
			ProcessTreeNode child = (ProcessTreeNode) getChildAt(i);
			ProcessTreeNode search = child.getTree(instanceName);
			if(search != null){
				return search;
			}
		}

		return null;
	}

	/**
	 * Set the ProcessTreeListItem of the current treenode
	 * 
	 * @param item
	 *            ProcessTreeListItem
	 */
	private void setItem(ProcessTreeListItem item){
		m_item = item;
	}

	/**
	 * Method for checking what kind of Child to add to the tree. If the root
	 * calls this function, the item will be added either as a leaf or, if a
	 * node with a similar name exists, to that node. If another tree node calls
	 * this function, the item will be added as a leaf.
	 * 
	 * @param item
	 *            the ProcessTreeListItem that will be added to the Tree
	 */
	private ProcessTreeNode addProcessListItem(ProcessTreeListItem item){
		ProcessTreeNode tree = getTree(item.getProcessInstanceName());
		if (tree == null) {
			addChild(item);
			return this;
		}

		ProcessTreeNode parent = (ProcessTreeNode) tree.getParent();
		ProcessTreeNode root = (ProcessTreeNode) getRoot();

		if(parent == root){
			tree.addChild(tree.getItem());
			tree.setItem(null);
			tree.addChild(item);
			return tree;
		}
		parent.addChild(item);
		return parent;
	}

	/**
	 * Method for checking what kind of Child to remove from the tree. If the
	 * root calls this function, the item will be removed either as a leaf or,
	 * if a node with a similar name exists, from that node. If another tree
	 * node calls this function, the item will be removed as a leaf. If this is
	 * the case and the child count drops to 1, the node will be replaced by its
	 * last leaf child.
	 * 
	 * @param processInstance
	 *            the ProcessTreeNode that will be removed from the tree
	 */
	private ProcessTreeNode removeProcessInstance(ProcessInstance processInstance){
		ProcessTreeNode tree = getTree(processInstance.getProcessId());
		if(tree == null) return null;

		tree.getItem().remove();
		return tree;
		/*
		 * ProcessTreeNode parent = (ProcessTreeNode) tree.getParent();
		 * ProcessTreeNode root = (ProcessTreeNode) getRoot();
		 * 
		 * parent.remove(tree);
		 * 
		 * if (parent != root && parent.getChildCount() == 1) { ProcessTreeNode
		 * lastChild = (ProcessTreeNode) parent.getChildAt(0);
		 * parent.setItem(lastChild.getItem()); parent.removeAllChildren(); }
		 * 
		 * return parent;
		 */
	}

	/**
	 * This method returns the Name of the TreeNode depending on its item or the
	 * items of its children. If this item is the root, it just returns
	 * "Processes".
	 * 
	 * @return the name of the TreeNode
	 */
	public String toString(){
		if(isRoot()){
			return "Processes";
		}
		return getProcessName();
	}

	/**
	 * Return the ProcessName of this node. If this node has children, it
	 * returns the name of the first child. Else it returs "error".
	 * 
	 * @return The Process name
	 */
	public String getProcessName(){
		if(m_item != null){
			return m_item.getProcessInstanceName();
		}
		return ((ProcessTreeNode) getChildAt(0)).getProcessName();
	}

	/**
	 * Get the BreakPointType from the treenode
	 * 
	 * @return the BreakPointType
	 */
	public BreakPointType getBreakPointType(){		
		if(this.isRoot()){
			return BreakPointType.NONE;
		}
		
		if(m_hasSourceCodeBreakpoint && hasProcessBreakpoint()){
			return BreakPointType.BOTH;
		}else if (m_hasSourceCodeBreakpoint){
			return BreakPointType.LINE;
		}else if (hasProcessBreakpoint()){
			return BreakPointType.PROCESS;
		}
		return BreakPointType.NONE;
	}

	/**
	 * Returns is this node is visible. If the node is a group of processes the
	 * visibility is determined by it's children. If all children are visible
	 * this one is as well, otherwise it's not.
	 * 
	 * @return isVisible
	 */
	public boolean isVisible(){
		if(m_item != null){
			return m_item.hasFilter();
		}else if (getChildCount() > 0){
			// If all children of process group are visible this one is as well.
			for(int index = 0; index < getChildCount(); index++){
				ProcessTreeNode node = (ProcessTreeNode) getChildAt(index);
				if (!node.isVisible()){
					return false;
				}
			}
			return true;
		}
		
		return false;
	}

	/**
	 * Get own ProcessTreeListItem
	 * 
	 * @return ProcessTreeListItem
	 */
	public ProcessTreeListItem getItem(){
		return m_item;
	}

	/**
	 * Get the ID from the treenode Returns ID only if item is a leaf
	 * 
	 * @return ID from the treenode
	 */
	public String getID(){
		if(isLeaf()){
			return String.valueOf(m_item.getProcessInstanceID());
		}
		return "";
	}

	/**
	 * Add a {@link ProcessInstance} to this {@link ProcessTreeNode}.
	 * 
	 * @param processInstance
	 *            The {@link ProcessInstance} to be added.
	 * @param dataComm the DataComm instance to be used
	 * @return A {@link ProcessTreeNode}, containing the added
	 *         {@link ProcessInstance}.
	 */
	public ProcessTreeNode add(ProcessInstance processInstance, DataComm dataComm){
		ProcessTreeListItem item = new ProcessTreeListItem(processInstance, dataComm);
		return addProcessListItem(item);
	}

	/**
	 * Remove a {@link ProcessInstance} from this {@link ProcessTreeNode}.
	 * 
	 * @param processInstance
	 *            The {@link ProcessInstance} to be removed.
	 * @return The removed {@link ProcessTreeNode}.
	 */
	public ProcessTreeNode remove(ProcessInstance processInstance) {
		return removeProcessInstance(processInstance);
	}

	/**
	 * If the node has an item, it will return the item's removed state. If the
	 * node is a parent, it will return false if one child is still 'live'.
	 * Else, it will return true.
	 * 
	 * @return removed status
	 */
	public boolean isRemoved(){
		if(getItem() != null){
			return getItem().isRemoved();
		}

		for(int index = 0; index < getChildCount(); index++){
			ProcessTreeNode node = (ProcessTreeNode) getChildAt(index);
			if(!node.isRemoved()){
				return false;
			}
		}

		return true;
	}

	/**
	 * Returns whether or not the source code has a breakpoint in it.
	 * 
	 * @return true when the source has a breakpoint, false otherwise
	 */
	public boolean hasSourceCodeBreakpoint(){
		return m_hasSourceCodeBreakpoint;
	}

	/**
	 * Sets the whether or not the source has a breakpoint
	 * 
	 * @param hasSourceCodeBreakpoint a boolean that sets whether or not the source has a breakpoint
	 */
	public void setSourceCodeBreakpoint(boolean hasSourceCodeBreakpoint){
		this.m_hasSourceCodeBreakpoint = hasSourceCodeBreakpoint;
	}
	
	/**
	 * Returns whether or not the process instance has a breakpoint
	 * 
	 * @return True when the process has a breakpoint, false otherwise
	 */
	public boolean hasProcessBreakpoint(){
		if(m_item != null && m_item.hasBreakPoint()) return true;
		
		if(getChildCount() > 0 && !isRoot()){
			for(int i = 0; i < getChildCount(); i++){
				ProcessTreeNode myChild = (ProcessTreeNode) getChildAt(i);
				if(myChild.getItem().hasBreakPoint()){
					return true;
				}
			}
		}
		
		return false;
	}
	
	/**
	 * Sets whether or not the process has a breakpoint
	 * 
	 * @param value true when the process has a breakpoint
	 */
	public void setProcessBreakpoint(boolean value){
		if(m_item != null){
			m_item.setBreakPoint(value);
		}else if(getChildCount() > 0 && !isRoot()){
			for(int i = 0; i < getChildCount(); i++){
				ProcessTreeNode myChild = (ProcessTreeNode) getChildAt(i);
				myChild.setProcessBreakpoint(value);
			}
		}
			
	}

	/**
	 * Sets whether or not the node is visible
	 * 
	 * @param value true when it is visible
	 * @param filteredInstances the instances the value applies to
	 */
	public void setVisible(boolean value, List<ProcessInstance> filteredInstances){
		if(m_item != null){
			m_item.setFilter(value);
			filteredInstances.add(m_item.getProcessInstance());
		}else if(getChildCount() > 0){
			for(int i = 0; i < getChildCount(); i++){
				ProcessTreeNode myChild = (ProcessTreeNode) getChildAt(i);
				myChild.setVisible(value, filteredInstances);
			}
		}			
	}

	/**
	 * Sets the source code breakpoint status on the process group node.
	 * 
	 * @param processes a map of processes with source code breakpoints
	 */
	public void syncSourceCodeBreakpoints(Map<String, Integer> processes){
		for(int i = 0; i < this.getChildCount(); i++){
			ProcessTreeNode rootChild = (ProcessTreeNode) this.getChildAt(i);
			int numBreakpoints = processes.get(rootChild.toString()) != null ? processes.get(rootChild.toString()).intValue() : 0;
			if(numBreakpoints > 0){
				rootChild.setSourceCodeBreakpoint(true);
			}else{
				rootChild.setSourceCodeBreakpoint(false);
			}
		} 
	}
}

