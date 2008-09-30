package argusviewer.view.architectureview.performance.tree;

import argusviewer.view.architectureview.performance.ThreadInfo;

/**
 * The {@link PerformanceTreeNodeThread} is a JTree Data Model that is used by the
 * JTreeTable component. The {@link PerformanceTreeNodeThread} creates a tree model
 * based on the {@link ThreadInfo} added to it.
 * 
 * Basically, it is a node in the table. A node can contain multiple nodes. Eg,
 * a tool in the table is a node.
 * 
 * @author Jeldert Pol
 */
public class PerformanceTreeNodeThread extends PerformanceTreeNode{
	private static final long serialVersionUID = 5262837229886674693L;
	
	private final ThreadInfo threadInfo;

	/**
	 * The constructor creates a {@link PerformanceTreeNodeThread}, with a
	 * {@link ThreadInfo} attached.
	 * 
	 * @param threadInfo
	 *            The {@link ThreadInfo} to attach to this
	 *            {@link PerformanceTreeNodeThread}.
	 */
	public PerformanceTreeNodeThread(ThreadInfo threadInfo){
		this.threadInfo = threadInfo;
	}

	/**
	 * Gets the id of the Tool or null is the node is no tool.
	 * 
	 * @return the id of the Tool or null is the node is no tool.
	 */
	public String getToolId(){
		return "";
	}

	/**
	 * Gets the name of the Tool, or the name of the child.
	 * 
	 * @return the name of the tool or child.
	 */
	public String getToolName(){
		return threadInfo.getThreadName();
	}

	/**
	 * Gets the memory heap usage of the Tool, or the total of it's children if
	 * the node is no tool. If it has no children it return 0.
	 * 
	 * @return the memory heap usage of the Tool.
	 */
	public String getToolMemoryHeapUsage(){
		return "";
	}

	/**
	 * Gets the processor time of the Tool, or the total of its children. The
	 * system time and user time added is the processor time.
	 * 
	 * @return the processor time of the Tool.
	 */
	public int getProcessorTime(){
		return threadInfo.getThreadSystemTime() + threadInfo.getThreadUserTime();
	}

	/**
	 * This method returns the name of the Tool depending on its item or the
	 * items of its children. If this item is the root, it returns the ToolType.
	 * 
	 * @return the name of the {@link PerformanceTreeNodeThread}
	 */
	public String toString(){
		return getToolName();
	}
}
