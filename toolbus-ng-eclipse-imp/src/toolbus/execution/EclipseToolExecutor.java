package toolbus.execution;

import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.execution.IToolExecutor;

public class EclipseToolExecutor implements IToolExecutor{
	private final ToolInstance toolInstance;
	private final ToolDefinition toolDefinition;
	private final ToolBus toolbus;
	
	public EclipseToolExecutor(ToolInstance toolInstance, ToolDefinition toolDefinition, ToolBus toolbus){
		super();
		
		this.toolInstance = toolInstance;
		this.toolDefinition = toolDefinition;
		this.toolbus = toolbus;
	}
	
	public void execute() throws ToolBusException{
		// TODO Implement.
	}
}
