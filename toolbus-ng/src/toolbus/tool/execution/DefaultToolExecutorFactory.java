package toolbus.tool.execution;

import toolbus.ToolBus;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;

/**
 * This is the default tool executor factory.
 * 
 * @author Arnold Lankamp
 */
public class DefaultToolExecutorFactory implements IToolExecutorFactory{

	/**
	 * Default constructor.
	 */
	public DefaultToolExecutorFactory(){
		super();
	}
	
	/**
	 * @see toolbus.tool.execution.IToolExecutorFactory#getToolExecutor(ToolInstance, ToolDefinition, ToolBus)
	 */
	public IToolExecutor getToolExecutor(ToolInstance toolInstance, ToolDefinition toolDefinition, ToolBus toolbus){
		return new DefaultToolExecutor(toolInstance, toolDefinition, toolbus);
	}
}
