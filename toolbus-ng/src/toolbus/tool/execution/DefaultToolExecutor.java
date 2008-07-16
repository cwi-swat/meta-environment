package toolbus.tool.execution;

import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

import toolbus.ToolBus;
import toolbus.adapter.java.AbstractJavaTool;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import aterm.ATerm;

/**
 * This tool executor implements the default behavior of an executor.
 * (Which means it just executes tools and nothing else).
 * 
 * @author Arnold Lankamp
 */
public class DefaultToolExecutor implements IToolExecutor{
	private final ToolInstance toolInstance;
	private final ToolDefinition toolDefinition;
	private final ToolBus toolbus;
	
	/**
	 * Constructor.
	 * 
	 * @param toolInstance
	 *            The tool instance to which the tool is associated.
	 * @param toolDefinition
	 *            The definition of the tool.
	 * @param toolbus
	 *            The toolbus to which the tool should connect.
	 */
	public DefaultToolExecutor(ToolInstance toolInstance, ToolDefinition toolDefinition, ToolBus toolbus){
		super();
		
		this.toolInstance = toolInstance;
		this.toolDefinition = toolDefinition;
		this.toolbus = toolbus;
	}
	
	/**
	 * @see toolbus.tool.execution.IToolExecutor#execute()
	 */
	public void execute() throws ToolBusException{
		if(toolDefinition.isDirectlyStartableJavaNGTool()){
			// Create a new classloader for the tool instance.
			ClassLoader toolClassLoader = toolDefinition.createClassLoader();
			// Load the tool's main class.
			String toolClassName = toolDefinition.getClassName();
			Class<?> toolClass;
			try{
				toolClass = toolClassLoader.loadClass(toolClassName);
			}catch(ClassNotFoundException cnfex){
				String error = "Unable to load the main class of tool: " + toolClassName;
				LoggerFactory.log(error, cnfex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error, cnfex);
			}
			
			// Instantiate the tool.
			AbstractJavaTool tool;
			try{
				Constructor<?> toolConstructor = toolClass.getConstructor();
				
				tool = (AbstractJavaTool) toolConstructor.newInstance();
				tool.connectDirectly(toolbus, toolDefinition.getName(), toolInstance.getToolID());
			}catch(InstantiationException iex){
				String error = "Unable to instantiate the tool. Classname: " + toolClass.getName();
				LoggerFactory.log(error, iex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}catch(IllegalAccessException iaex){
				String error = "The constructor of the tool we are trying to instantiate isn't public. Classname: " + toolClass.getName();
				LoggerFactory.log(error, iaex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}catch(InvocationTargetException itex){
				String error = "An exception occured during the invokation of the constructor of the tool we are trying to instantiate. Classname: " + toolClass.getName();
				LoggerFactory.log(error, itex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}catch(NoSuchMethodException nsmex){
				String error = "The tool we are trying to instantiate doesn't have a proper constructor. Classname: " + toolClass.getName();
				LoggerFactory.log(error, nsmex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}catch(SecurityException sex){
				String error = "We don't have permission to invoke the constructor of: " + toolClass.getName();
				LoggerFactory.log(error, sex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}catch(Exception ex){
				String error = "Unable to connect tool to the ToolBus directly: " + toolClass.getName();
				LoggerFactory.log(error, ex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}
		}else if(toolDefinition.getClassName() != null){
			String classpath = toolDefinition.getClassPath();
			// Use the -Xshare=off switch to conserve memory. We don't want to load the entire
			// standard library in memory every time we start a tool. We're only using a tiny
			// bit of that library. And do NOT listen to Sun, who says that it will reduce the
			// memory footprint, because it can share a part of it between all running JVMs; it
			// can only share about 50% of this memory between JVMs, so this is simply not true.
			// The last time I checked 1.5MB < (50% of 12.5MB). Thanks Sun for turning this
			// rubbish feature on by default on the client VM.
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
		}else{
			ATerm toolKey = toolInstance.getToolKey();
			
			String error = "Unable to start tool: " + toolKey + "; command or classname missing in tool definition.";
			LoggerFactory.log(error, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			throw new ToolBusException(error);
		}
	}
}
