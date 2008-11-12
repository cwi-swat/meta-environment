package toolbus.execution;

import java.io.File;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;

import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import toolbus.tool.execution.IToolExecutor;
import toolbus.tool.execution.StreamHandler;
import aterm.ATerm;

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
		if(toolDefinition.getClassName() != null){
			String classpath = toolDefinition.getClassPath();
			String[] command = new String[]{"java", "-Xshare:off", "-cp", classpath, toolDefinition.getClassName(), "-TB_TOOL_NAME", toolDefinition.getName(), "-TB_TOOL_ID", Integer.toString(toolInstance.getToolID()), "-TB_HOST", "localhost", "-TB_PORT", "" + toolbus.getPort()};
			
			ProcessBuilder pb = new ProcessBuilder(command);
			pb.redirectErrorStream(true);
			
			ATerm toolKey = toolInstance.getToolKey();
			
			try{
				Process process = pb.start();
				StreamHandler streamHandler = new StreamHandler(process, toolKey.toString());
				toolInstance.setStreamHandler(streamHandler);
				Thread streamHandlerThread = new Thread(streamHandler);
				streamHandlerThread.setName("Stream handler");
				streamHandlerThread.setDaemon(true);
				streamHandlerThread.start();
			}catch(IOException ioex){
				String error = "Unable to start remote tool: " + toolKey;
				LoggerFactory.log(error, ioex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}
		}else if(toolDefinition.getCommand() != null){
			String[] toolCommand = toolDefinition.getCommand().split(" ");
			int commandLength = toolCommand.length;
			String[] command = new String[commandLength + 8];
			System.arraycopy(toolCommand, 0, command, 0, commandLength);
			command[commandLength] = "-TB_TOOL_NAME";
			command[commandLength + 1] = toolDefinition.getName();
			command[commandLength + 2] = "-TB_TOOL_ID";
			command[commandLength + 3] = Integer.toString(toolInstance.getToolID());
			command[commandLength + 4] = "-TB_HOST";
			command[commandLength + 5] = "localhost";
			command[commandLength + 6] = "-TB_PORT";
			command[commandLength + 7] = Integer.toString(toolbus.getPort());
			
			ProcessBuilder pb = createProcessBuilder(command);
			pb.redirectErrorStream(true);
			
			ATerm toolKey = toolInstance.getToolKey();
			
			try{
				Process process = pb.start();
				StreamHandler streamHandler = new StreamHandler(process, toolKey.toString());
				toolInstance.setStreamHandler(streamHandler);
				Thread streamHandlerThread = new Thread(streamHandler);
				streamHandlerThread.setName("Stream handler");
				streamHandlerThread.setDaemon(true);
				streamHandlerThread.start();
			}catch(IOException ioex){
				String error = "Unable to start remote tool: " + toolKey;
				LoggerFactory.log(error, ioex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}
		}else{
			ATerm toolKey = toolInstance.getToolKey();
			
			String error = "Unable to start tool: " + toolKey + "; command or classname missing in tool definition.";
			LoggerFactory.log(error, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			throw new ToolBusException(error);
		}
	}
	
	private ProcessBuilder createProcessBuilder(String[] command){
		String executable = command[0];
		
		if(new File(executable).exists()) return new ProcessBuilder(command);
		
		Iterator<String> searchPathIterator = searchPaths.iterator();
		while(searchPathIterator.hasNext()){
			String path = searchPathIterator.next();
			String possbileLocation = path+File.separatorChar+executable;
			if(new File(path+File.separatorChar+executable).exists()){
				command[0] = possbileLocation;
				ProcessBuilder processBuilder = new ProcessBuilder(command);
				processBuilder.directory(new File(path));
				
				return processBuilder;
			}
		}
		
		return new ProcessBuilder(command); // Fallback; used when path to the executable is not absolute or in the search path (it could be in the environment).
	}
}
