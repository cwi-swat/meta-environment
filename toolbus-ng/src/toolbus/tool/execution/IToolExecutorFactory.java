package toolbus.tool.execution;

import toolbus.ToolBus;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;

/**
 * Interface all tool executor factories much implement.
 * 
 * @author Arnold Lankamp
 */
public interface IToolExecutorFactory{
	
	/**
	 * Constructs a tool executor.
	 * 
	 * @param toolInstance
	 *            The tool instance to which the tool is associated.
	 * @param toolDefinition
	 *            The definition of the tool.
	 * @param toolbus
	 *            The toolbus to which the tool should connect.
	 *            
	 * @return The constructed tool executor.
	 */
	public IToolExecutor getToolExecutor(ToolInstance toolInstance, ToolDefinition toolDefinition, ToolBus toolbus);
}
