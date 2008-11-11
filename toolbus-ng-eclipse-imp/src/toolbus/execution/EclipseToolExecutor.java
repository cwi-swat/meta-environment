package toolbus.execution;

import java.util.List;

import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.execution.DefaultToolExecutor;
import toolbus.tool.execution.IToolExecutor;

public class EclipseToolExecutor implements IToolExecutor{
	private final ToolInstance toolInstance;
	private final ToolDefinition toolDefinition;
	private final ToolBus toolbus;
	
	private final List<String> searchPaths;
	
	public EclipseToolExecutor(ToolInstance toolInstance, ToolDefinition toolDefinition, ToolBus toolbus, List<String> searchPaths){
		super();
		
		this.toolInstance = toolInstance;
		this.toolDefinition = toolDefinition;
		this.toolbus = toolbus;
		
		this.searchPaths = searchPaths;
	}
	
	public void execute() throws ToolBusException{
		new DefaultToolExecutor(toolInstance, toolDefinition, toolbus).execute(); // Temp
		// TODO Implement.
	}
}
