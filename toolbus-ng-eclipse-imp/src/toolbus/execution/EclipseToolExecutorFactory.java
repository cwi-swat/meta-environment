package toolbus.execution;

import java.util.List;

import toolbus.ToolBus;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.execution.IToolExecutor;
import toolbus.tool.execution.IToolExecutorFactory;

public class EclipseToolExecutorFactory implements IToolExecutorFactory{
	private final List<String> searchPaths;
	
	public EclipseToolExecutorFactory(List<String> searchPaths){
		super();
		
		this.searchPaths = searchPaths;
	}

	public IToolExecutor getToolExecutor(ToolInstance toolInstance, ToolDefinition toolDefinition, ToolBus toolbus) {
		return new EclipseToolExecutor(toolInstance, toolDefinition, toolbus, searchPaths);
	}
}
