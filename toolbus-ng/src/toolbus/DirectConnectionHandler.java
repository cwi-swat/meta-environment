package toolbus;

import toolbus.adapter.ToolBridge;
import toolbus.communication.DirectIOHandler;
import toolbus.exceptions.ToolBusError;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import aterm.AFun;
import aterm.ATerm;

public class DirectConnectionHandler{
	private final ToolBus toolbus;
	
	public DirectConnectionHandler(ToolBus toolbus){
		super();
		
		this.toolbus = toolbus;
	}
	
	public void dock(ToolBridge toolBridge) throws ToolBusError{
		String toolName = toolBridge.getToolName();
		
		ToolDefinition toolDef = toolbus.getToolDefinition(toolName);
		if(toolDef == null){
			String error = "No tool definition found for tool with name: " + toolName;
			LoggerFactory.log(error, ILogger.WARNING, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(error);
		}
		
		if(!toolBridge.checkSignature(toolDef.getSignature())){
			String error = "The tool, with name: "+toolName+", did not provide the expected interface.";
			LoggerFactory.log(error, ILogger.WARNING, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(error);
		}
		
		ToolInstanceManager toolInstanceManager = toolbus.getToolInstanceManager();
		
		TBTermFactory tbfactory = toolbus.getTBTermFactory();
		AFun afun = tbfactory.makeAFun(toolDef.getName(), 1, false);
		ATerm toolKey = tbfactory.makeAppl(afun, tbfactory.makeInt(toolBridge.getToolID()));

		ToolInstance toolInstance = toolInstanceManager.getPendingTool(toolKey);
		
		// If we didn't request the tool with the given id to execute, it's connecting on it's own
		// initiative.
		if(toolInstance == null){
			toolInstance = new ToolInstance(toolDef, toolbus);
			toolInstanceManager.addDynamiclyConnectedTool(toolInstance);

			LoggerFactory.log("Tool: " + toolInstance.getToolKey() + ", connected at its own initiative.", ILogger.INFO, IToolBusLoggerConstants.COMMUNICATION);
		}
		
		// Connect the tool bridge with the tool instance.
		DirectIOHandler toolDirectIOHandler = new DirectIOHandler(toolBridge);
		toolBridge.setIOHandler(toolDirectIOHandler);
		
		DirectIOHandler toolBusDirectIOHandler = new DirectIOHandler(toolInstance);
		toolInstance.setIOHandler(toolBusDirectIOHandler);
		
		toolDirectIOHandler.setDirectIOHandler(toolBusDirectIOHandler);
		toolBusDirectIOHandler.setDirectIOHandler(toolDirectIOHandler);
	}
}
