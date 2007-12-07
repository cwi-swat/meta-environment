package toolbus.tool;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import toolbus.IOperations;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.ToolInstanceManager;
import toolbus.adapter.AbstractTool;
import toolbus.adapter.ToolBridge;
import toolbus.adapter.java.AbstractJavaTool;
import toolbus.communication.DirectClientIOHandler;
import toolbus.communication.DirectServerIOHandler;
import toolbus.communication.IDataHandler;
import toolbus.communication.IIOHandler;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;

public class ToolInstance implements IDataHandler, IOperations{
	private final ToolDefinition toolDef;
	private final ToolBus toolbus;
	private final TBTermFactory tbfactory;
	
	private volatile IIOHandler ioHandler = null;
	
	private volatile StreamHandler streamHandler = null;
	
	private static int toolNr = 0;
	
	private final ATermAppl toolKey;
	private final int toolID;
	
	private final List<ATerm> valuesFromTool;
	private final List<ATerm> eventsFromTool;
	
	private final List<ATerm> performanceStats;
	
	private volatile ATerm lastDebugPerformanceStats = null;
	
	/**
	 * Construct a ToolInstance.
	 * 
	 * @param toolDef
	 *            definition of the tool.
	 * @param toolbus
	 *            A reference to the toolbus associated with this tool instance.
	 */
	public ToolInstance(ToolDefinition toolDef, ToolBus toolbus){
		super();
		
		this.toolDef = toolDef;
		this.toolbus = toolbus;
		this.tbfactory = toolbus.getTBTermFactory();
		
		synchronized(getClass()){
			this.toolID = toolNr++;
		}
		
		AFun afun = tbfactory.makeAFun(toolDef.getName(), 1, false);
		toolKey = tbfactory.makeAppl(afun, tbfactory.makeInt(toolID));
		
		valuesFromTool = new LinkedList<ATerm>();
		eventsFromTool = new LinkedList<ATerm>();
		
		performanceStats = new LinkedList<ATerm>();
	}
	
	public void executeTool() throws ToolBusException{
		if(toolDef.isDirectlyStartableJavaNGTool()){
			// Create a new classloader for the tool instance.
			ClassLoader toolClassLoader = toolDef.createClassLoader();
			// Load the tool's main class.
			String toolClassName = toolDef.getClassName();
			Class<?> toolClass;
			try{
				toolClass = toolClassLoader.loadClass(toolClassName);
			}catch(ClassNotFoundException cnfex){
				LoggerFactory.log("Unable to load the main class of tool: " + toolClassName, cnfex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(cnfex);
			}
			
			// Instantiate the tool.
			AbstractJavaTool tool;
			try{
				Constructor<?> toolConstructor = toolClass.getConstructor(new Class[]{String[].class});
				
				Object[] args = new Object[]{new String[]{"-TYPE", AbstractTool.DIRECTTOOL, "-TB_TOOL_NAME", toolDef.getName(), "-TB_TOOL_ID", Integer.toString(toolID)}};
				tool = (AbstractJavaTool) toolConstructor.newInstance(args);
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
			}
			
			ToolBridge toolBridge = tool.getToolBridge();
			
			// Check if the tool provides the given signature.
			if(!toolBridge.checkSignature(getSignature())){
				String error = "Tool: " + toolDef.getName() + " did not provide the expected signature.";
				LoggerFactory.log(error, ILogger.WARNING, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}
			
			// Link the handlers.
			DirectClientIOHandler toolDirectIOHandler = new DirectClientIOHandler(toolBridge);
			toolBridge.setIOHandler(toolDirectIOHandler);
			
			DirectServerIOHandler toolBusDirectIOHandler = new DirectServerIOHandler(this, toolClassLoader);
			setIOHandler(toolBusDirectIOHandler);
			
			toolDirectIOHandler.setServerDirectIOHandler(toolBusDirectIOHandler);
			toolBusDirectIOHandler.setClientDirectIOHandler(toolDirectIOHandler);
			
			// We're connected (a direct tool will not send a connect message).
			goConnected();
			
			// Notify the ToolBus that something happend (we connected).
			toolbus.workArrived(this, CONNECT);
		}else if(toolDef.getClassName() != null){
			String classpath = System.getProperty("java.class.path");
			// Use the -Xshare=off switch to conserve memory. We don't want to load the entire
			// standard library in memory every time we start a tool. We're only using a tiny
			// bit of that library. And do NOT listen to Sun, who says that it will reduce the
			// memory footprint, because it can share a part of it between all running JVMs; it
			// can only share about 50% of this memory between JVMs, so this is simply not true.
			// The last time I checked 1.5MB < (50% of 12.5MB). Thanks Sun for turning this
			// rubbish feature on by default on the client VM.
			String[] command = new String[]{"java", "-Xshare:off", "-cp", classpath, toolDef.getClassName(), "-TYPE", AbstractTool.REMOTETOOL, "-TB_TOOL_NAME", toolDef.getName(), "-TB_TOOL_ID", Integer.toString(toolID), "-TB_HOST", "localhost", "-TB_PORT", "" + toolbus.getPort()};
			
			ProcessBuilder pb = new ProcessBuilder(command);
			pb.redirectErrorStream(true);
			
			try{
				Process process = pb.start();
				streamHandler = new StreamHandler(process, toolKey.toString());
				Thread streamHandlerThread = new Thread(streamHandler);
				streamHandlerThread.setName("Stream handler");
				streamHandlerThread.setDaemon(true);
				streamHandlerThread.start();
			}catch(IOException ioex){
				String error = "Unable to start remote tool: " + toolKey;
				LoggerFactory.log(error, ioex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new ToolBusException(error);
			}
		}else if(toolDef.getCommand() != null){
			String[] toolCommand = toolDef.getCommand().split(" ");
			int commandLength = toolCommand.length;
			String[] command = new String[commandLength + 10];
			System.arraycopy(toolCommand, 0, command, 0, commandLength);
			command[commandLength] = "-TYPE";
			command[commandLength + 1] = AbstractTool.REMOTETOOL;
			command[commandLength + 2] = "-TB_TOOL_NAME";
			command[commandLength + 3] = toolDef.getName();
			command[commandLength + 4] = "-TB_TOOL_ID";
			command[commandLength + 5] = Integer.toString(toolID);
			command[commandLength + 6] = "-TB_HOST";
			command[commandLength + 7] = "localhost";
			command[commandLength + 8] = "-TB_PORT";
			command[commandLength + 9] = "" + toolbus.getPort();
			
			ProcessBuilder pb = new ProcessBuilder(command);
			pb.redirectErrorStream(true);
			
			try{
				Process process = pb.start();
				streamHandler = new StreamHandler(process, toolKey.toString());
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
			String error = "Unable to start tool: " + toolKey + "; command or classname missing in tool definition.";
			LoggerFactory.log(error, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			throw new ToolBusException(error);
		}
	}
	
	public ATermAppl getToolKey(){
		return toolKey;
	}
	
	public String getToolName(){
		return toolKey.getName();
	}
	
	public ATerm getSignature(){
		return toolDef.getSignature();
	}
	
	public void setIOHandler(IIOHandler ioHandler){
		this.ioHandler = ioHandler;
	}
	
	public void receive(byte operation, ATerm aTerm){
		switch(operation){
			case EVENT:
				synchronized(eventsFromTool){
					eventsFromTool.add(aTerm);
				}
				break;
			case ACKDO:
				goReady();
				break;
			case VALUE:
				goReady();
				synchronized(valuesFromTool){
					valuesFromTool.add(aTerm);
				}
				break;
			case DISCONNECT:
				goDisconnected();
				break;
			case CONNECT:
				goConnected();
				break;
			case PERFORMANCESTATS:
				goReady();
				performanceStats.add(aTerm);
				break;
			case DEBUGPERFORMANCESTATS:
				goReady();
				lastDebugPerformanceStats = aTerm;
				break;
			default:
				LoggerFactory.log("Message with unknown operation received from Tool: " + operation, ILogger.WARNING, IToolBusLoggerConstants.TOOLINSTANCE);
		}
		
		// Notify the ToolBus of the arrival of a message.
		toolbus.workArrived(this, operation);
	}
	
	public void sendAckEvent(ATerm aTerm){
		send(ACKEVENT, aTerm);
	}
	
	public void sendDo(ATerm aTerm){
		send(DO, aTerm);
	}
	
	public void sendEval(ATerm aTerm){
		send(EVAL, aTerm);
	}
	
	public void sendTerminate(ATerm aTerm){
		send(TERMINATE, aTerm);
	}
	
	public void sendPerformanceStatsRequest(ATerm aTerm){
		send(PERFORMANCESTATS, aTerm);
	}
	
	public void sendDebugPerformanceStatsRequest(){
		send(DEBUGPERFORMANCESTATS, toolbus.getTBTermFactory().makeList());
	}
	
	public void send(byte operation, ATerm aTerm){
		ioHandler.send(operation, aTerm);
	}
	
	public void terminate(){
		ioHandler.terminate();
	}
	
	public void shutDown(){
		boolean connected = isConnected();
		
		goTerminated();
		
		ToolInstanceManager tim = toolbus.getToolInstanceManager();
		if(connected){ // If the tool is connected we only need to check in one collection.
			tim.remove(toolKey);
		}else{
			tim.remove(toolKey);
			tim.removePendingTool(toolKey);
			tim.removeDynamiclyConnectedTool(this);
		}
		
		toolbus.workArrived(this, IOperations.END);
	}
	
	public boolean isExecutedTool(){
		return (streamHandler != null);
	}
	
	public void kill(){
		boolean connected = isConnected();
		
		goKilled();
		
		ToolInstanceManager tim = toolbus.getToolInstanceManager();
		if(connected){ // If the tool is connected we only need to check in one collection.
			tim.remove(toolKey);
		}else{
			tim.remove(toolKey);
			tim.removePendingTool(toolKey);
			tim.removeDynamiclyConnectedTool(this);
		}
		
		if(streamHandler != null) streamHandler.destroy();
	}
	
	/**
	 * Deregisters the tool instance and enters the unreachable state.
	 * 
	 * @see IDataHandler#exceptionOccured()
	 */
	public void exceptionOccured(){
		goUnreachable();
		
		LoggerFactory.log("Tool crashed / disconnected: "+toolKey, ILogger.WARNING, IToolBusLoggerConstants.TOOLINSTANCE);
	}
	
	public boolean getValueFromTool(ATerm aTerm, Environment env){
		synchronized(valuesFromTool){
			Iterator<ATerm> valuesIterator = valuesFromTool.iterator();
			while(valuesIterator.hasNext()){
				boolean matches = tbfactory.matchPatternToValue(aTerm, env, valuesIterator.next());
				if(matches){
					valuesIterator.remove();
					return true;
				}
			}
		}
		return false;
	}
	
	public boolean getEventFromTool(ATerm aTerm, Environment env){
		synchronized(eventsFromTool){
			Iterator<ATerm> eventsIterator = eventsFromTool.iterator();
			while(eventsIterator.hasNext()){
				boolean matches = tbfactory.matchPatternToValue(aTerm, env, eventsIterator.next());
				if(matches){
					eventsIterator.remove();
					return true;
				}
			}
		}
		return false;
	}
	
	public boolean getPerformanceStats(ATerm aTerm, Environment env){
		synchronized(performanceStats){
			Iterator<ATerm> performanceStatsIterator = performanceStats.iterator();
			while(performanceStatsIterator.hasNext()){
				boolean matches = tbfactory.matchPatternToValue(aTerm, env, performanceStatsIterator.next());
				if(matches){
					performanceStatsIterator.remove();
					return true;
				}
			}
		}
		return false;
	}
	
	public ATerm getLastDebugPerformanceStats(){
		return lastDebugPerformanceStats;
	}
	
	private final static int UNCONNECTED = 0; // Start and end state.
	private final static int READY = 2; // Ready to send (DO or EVAL).
	private final static int BLOCKED = 3; // Waiting for response (ACKDO or VALUE).
	private final static int DISCONNECTED = 4; // Termination requested by tool.
	private final static int KILLED = 5; // User imposed error state.
	private final static int UNREACHABLE = 6; // Error state.
	private final static int TERMINATED = 7; // End state.
	
	private int state = UNCONNECTED;
	
	private final Object stateLock = new Object();
	
	private void goConnected(){
		synchronized(stateLock){
			state = READY;
		}
	}
	
	private void goReady(){
		synchronized(stateLock){
			if(state == BLOCKED) state = READY;
		}
	}
	
	private void goDisconnected(){
		synchronized(stateLock){
			if(isConnected()) state = DISCONNECTED;
		}
	}
	
	private void goTerminated(){
		synchronized(stateLock){
			state = TERMINATED;
		}
	}
	
	private void goUnreachable(){
		synchronized(stateLock){
			state = UNREACHABLE;
		}
	}
	
	private void goKilled(){
		synchronized(stateLock){
			state = KILLED;
		}
	}
	
	public boolean isConnected(){
		synchronized(stateLock){
			return ((state & (READY | BLOCKED)) != 0);
		}
	}
	
	public boolean isDisconnected(){
		synchronized(stateLock){
			return (state == DISCONNECTED);
		}
	}
	
	public boolean isUnreachable(){
		synchronized(stateLock){
			return (state == UNREACHABLE);
		}
	}
	
	public boolean isTerminated(){
		synchronized(stateLock){
			return (state == KILLED);
		}
	}
	
	public boolean isKilled(){
		synchronized(stateLock){
			return (state == KILLED);
		}
	}
	
	public boolean tryDoEval(){
		synchronized(stateLock){
			if(state == READY){
				state = BLOCKED;
				return true;
			}
		}
		return false;
	}
	
	public String showStatus(){
		String status;
		synchronized(stateLock){
			status = "tool " + toolKey.toString() + "(state = " + state + ")";
		}
		return status;
	}
	
	private static class StreamHandler implements Runnable{
		private final Process process;
		private final String toolID;
		
		public StreamHandler(Process process, String toolID){
			this.process = process;
			this.toolID = toolID;
		}
		
		public void run(){
			BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
			
			String line = null;
			try{
				while((line = reader.readLine()) != null){
					PrintStream ps = System.out;
					// This is to avoid the silent instantiation and usage of a StringBuffer,
					// without having to obtain and release the monitor to System.out several times.
					synchronized(ps){
						ps.print(toolID);
						ps.print(" >> ");
						ps.print(line);
						ps.println();
					}
				}
			}catch(IOException ioex){
				LoggerFactory.log("An IOException occured while handling the outputstream of tool: " + toolID, ioex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				LoggerFactory.log("Killing tool: " + toolID + ", because it cause an exception.", ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			}catch(RuntimeException rex){
				LoggerFactory.log("An RuntimeException occured during the execution of tool: " + toolID, rex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				LoggerFactory.log("Killing tool: " + toolID + ", because it cause an exception.", ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			}finally{
				// Kill the subprocess, even if it's already dead. We won't be handling the streams
				// anymore from this point on, it'll probably lock up eventually anyway if it's
				// still running (better kill it ourselfs). It will also close the stream from and
				// to the process, to make sure the associated file descriptor is removed
				// immediately and NOT whenever the JVM feels like it.
				destroy();
				
				// Close the reader.
				try{
					reader.close();
				}catch(IOException ioex){
					LoggerFactory.log("Unable to close the input stream from tool: " + toolID, ILogger.FATAL, IToolBusLoggerConstants.TOOLINSTANCE);
				}
			}
		}
		
		public void destroy(){
			process.destroy();
		}
	}
}
