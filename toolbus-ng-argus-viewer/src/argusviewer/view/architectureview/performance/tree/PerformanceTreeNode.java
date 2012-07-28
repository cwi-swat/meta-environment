package argusviewer.view.architectureview.performance.tree;

import java.text.NumberFormat;

import javax.swing.tree.DefaultMutableTreeNode;

import argusviewer.view.architectureview.performance.ThreadInfo;
import argusviewer.view.architectureview.performance.ToolPerformanceInfo;

/**
 * The {@link PerformanceTreeNode} is a JTree Data Model that is used by the
 * JTreeTable component. The {@link PerformanceTreeNode} creates a tree model
 * based on the {@link ToolPerformanceInfo} added to it. When a
 * {@link ToolPerformanceInfo} is added, the Tree Model is updated. Similar
 * {@link ToolPerformanceInfo} are grouped in one single Tree node.
 * 
 * Basically, it is a node in the table. A node can contain multiple nodes. Eg,
 * a tool in the table is a node. A folder containing multiple tools is also a
 * node.
 * 
 * @author Jeldert Pol
 */
public class PerformanceTreeNode extends DefaultMutableTreeNode{
	private static final long serialVersionUID = -3321070191695703729L;
	
	private volatile ToolPerformanceInfo m_toolPerformanceInfo;

	/**
	 * The constructor creates a {@link PerformanceTreeNode}, with no
	 * {@link ToolPerformanceInfo} attached.
	 */
	public PerformanceTreeNode(){
		super();
		
		m_toolPerformanceInfo = null;
	}

	/**
	 * The constructor creates a {@link PerformanceTreeNode}, with a
	 * {@link ToolPerformanceInfo} attached.
	 * 
	 * @param toolPerformanceInfo
	 *            The {@link ToolPerformanceInfo} to attach to this
	 *            {@link PerformanceTreeNode}.
	 */
	public PerformanceTreeNode(ToolPerformanceInfo toolPerformanceInfo){
		setToolPerformanceInfo(toolPerformanceInfo);
	}

	/**
	 * Adds a {@link ToolPerformanceInfo} to this node. Should only be called if
	 * name of tool is the same.
	 * 
	 * @param toolPerformanceInfo
	 *            the {@link ToolPerformanceInfo} to add.
	 */
	public void add(ToolPerformanceInfo toolPerformanceInfo){
		/**
		 * The following situations are possible:
		 * - Toolname exists
		 * -- Not a group
		 * --- Update on basis of ID
		 * --- Create group
		 * -- Is a group
		 * --- Update on basis of ID
		 * --- Add to group
		 */

		// No threads, Not a group
		if (getChildCount() == 0 || getChildAt(0) instanceof PerformanceTreeNodeThread){
			// Update if same
			if(getToolId().equals(String.valueOf(toolPerformanceInfo.getToolId()))){
				setToolPerformanceInfo(toolPerformanceInfo);
			}else{
				// Create group
				ToolPerformanceInfo temp = m_toolPerformanceInfo;
				setToolPerformanceInfo(null);
				removeAllChildren();
				PerformanceTreeNode newThis = new PerformanceTreeNode(temp);
				PerformanceTreeNode newNode = new PerformanceTreeNode(toolPerformanceInfo);
				add(newThis);
				add(newNode);
			}
		}else{
			boolean found = false;
			// Update if same
			for(int i = 0; i < getChildCount(); i++){
				PerformanceTreeNode child = (PerformanceTreeNode) getChildAt(i);
				if(child.getToolId().equals(String.valueOf(toolPerformanceInfo.getToolId()))){
					found = true;
					child.setToolPerformanceInfo(toolPerformanceInfo);
					break;
				}
			}
			if(!found){
				// Add to group
				add(new PerformanceTreeNode(toolPerformanceInfo));
			}
		}
	}

	/**
	 * Returns wheter this {@link PerformanceTreeNode} has
	 * {@link ToolPerformanceInfo} attached to it.
	 * 
	 * @return true is {@link ToolPerformanceInfo} is attached, false otherwise.
	 */
	public boolean hasToolPerformanceInfo(){
		return m_toolPerformanceInfo != null;
	}

	/**
	 * Gets the id of the Tool or null is the node is no tool.
	 * 
	 * @return the id of the Tool or null is the node is no tool.
	 */
	public String getToolId(){
		if(hasToolPerformanceInfo()){
			return String.valueOf(m_toolPerformanceInfo.getToolId());
		}
		return null;
	}

	/**
	 * Gets the name of the Tool, or the name of the child.
	 * 
	 * @return the name of the tool or child.
	 */
	public String getToolName(){
		if(hasToolPerformanceInfo()){
			return m_toolPerformanceInfo.getToolName();
		}
		if(getChildCount() > 0){
			PerformanceTreeNode child = (PerformanceTreeNode) getFirstChild();
			return child.getToolName();
		}
		// ever possible?;
		return null;
	}

	/**
	 * Gets the memory heap usage of the Tool, or the total of it's children if
	 * the node is no tool. If it has no children it return 0.
	 * 
	 * Before returning it formats the memory usage to a more readble format.
	 * 
	 * @return the memory heap usage of the Tool.
	 */
	public String getToolMemoryHeapUsage(){
		return formatMemory(getToolMemoryHeapUsageRaw());
	}
	
	/**
	 * Gets the memory heap usage of the Tool, or the total of it's children if
	 * the node is no tool. If it has no children it return 0.
	 * 
	 * @return the memory heap usage of the Tool.
	 */
	private int getToolMemoryHeapUsageRaw(){
		if(hasToolPerformanceInfo()){
			return m_toolPerformanceInfo.getToolMemoryHeapUsage();
		}else if(getChildCount() > 0){
			int total = 0;
			for(int index = 0; index < getChildCount(); index++){
				PerformanceTreeNode child = (PerformanceTreeNode) getChildAt(index);
				total += child.getToolMemoryHeapUsageRaw();
			}
			return total;
		}
		
		return 0;
	}
	
	/**
	 * Convert the memory usage from KiloBytes to a readable format. E.g.,
	 * 123456789 to "123,456,789 K". It used the default locale for the
	 * conversation.
	 * 
	 * @param memory
	 *            The amount of memory usage in KiloBytes.
	 * @return readable representation of memory usage.
	 */
	private static String formatMemory(int memory) {
		String formatted = NumberFormat.getNumberInstance().format(memory);
		formatted = formatted + " K";
		return formatted;
	}

	// Not used at the moment
	// /**
	// * Gets the memory non heap usage of the Tool, or the total of it's
	// children
	// * if the node is no tool.
	// *
	// * @return the memory non heap usage of the Tool, or the total of it's
	// * children if the node is no tool.
	// */
	// public Integer getToolMemoryNonHeapUsage() {
	// if (hasToolPerformanceInfo()) {
	// return m_toolPerformanceInfo.getToolMemoryNonHeapUsage();
	// } else if (getChildCount() > 0) {
	// int total = 0;
	// for (int index = 0; index < getChildCount(); index++) {
	// PerformanceTreeNode child = (PerformanceTreeNode) getChildAt(index);
	// total += child.getToolMemoryNonHeapUsage();
	// }
	// return total;
	// } else {
	// return 0;
	// }
	// }

	/**
	 * Gets the processor time of the Tool, or the total of its children. The
	 * system time and user time added is the processor time.
	 * 
	 * @return the processor time of the Tool.
	 */
	public int getProcessorTime() {
		int processorTime = 0;
		if(hasToolPerformanceInfo()){
			for(ThreadInfo threadInfo : m_toolPerformanceInfo.getThreads().values()){
				processorTime += threadInfo.getThreadSystemTime();
				processorTime += threadInfo.getThreadUserTime();
			}
		}else{
			for(int index = 0; index < getChildCount(); index++){
				PerformanceTreeNode child = (PerformanceTreeNode) getChildAt(index);
				processorTime += child.getProcessorTime();
			}
		}
		return processorTime;
	}

	/**
	 * This method returns the name of the Tool depending on its item or the
	 * items of its children. If this item is the root, it returns the ToolType.
	 * 
	 * @return the name of the {@link PerformanceTreeNode}
	 */
	public String toString(){
		if(isRoot()){
			return "Tools";
		}
		return getToolName();
	}

	/**
	 * Sets the {@link ToolPerformanceInfo} attached to this
	 * {@link PerformanceTreeNode}. Also updates {@link ThreadInfo}.
	 * 
	 * @param toolPerformanceInfo
	 *            the {@link ToolPerformanceInfo} to attach.
	 */
	public void setToolPerformanceInfo(ToolPerformanceInfo toolPerformanceInfo){
		m_toolPerformanceInfo = toolPerformanceInfo;
		if(hasToolPerformanceInfo()){
			updateThreads();
		}
	}

	/**
	 * Updates the {@link ThreadInfo} from this node.
	 */
	private void updateThreads(){
		removeAllChildren();

		for(ThreadInfo threadInfo : m_toolPerformanceInfo.getThreads().values()){
			PerformanceTreeNodeThread thread = new PerformanceTreeNodeThread(threadInfo);
			add(thread);
//			PerformanceTreeNode newChild = new PerformanceTreeNode();
//			this.add(newChild);
		}
	}
}
