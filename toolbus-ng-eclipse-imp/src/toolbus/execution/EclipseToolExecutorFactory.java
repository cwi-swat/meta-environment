package toolbus.execution;

import toolbus.ToolBus;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.execution.DefaultToolExecutor;
import toolbus.tool.execution.IToolExecutor;
import toolbus.tool.execution.IToolExecutorFactory;

public class EclipseToolExecutorFactory implements IToolExecutorFactory{

	public IToolExecutor getToolExecutor(ToolInstance toolInstance, ToolDefinition toolDefinition, ToolBus toolbus) {
		return new DefaultToolExecutor(toolInstance, toolDefinition, toolbus);
		//return new BinaryEclipseToolExecutor(toolInstance, toolDefinition, toolbus);
	}
}
