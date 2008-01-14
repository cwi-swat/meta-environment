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

/**
 * Provides the interface to a tool instance.
 * 
 * @author Arnold Lankamp
 */
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
	 * Constructor.
	 * 
	 * @param toolDef
	 *            The definition of the tool.
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
	
	/**
	 * Executes the tool that will be associated with this tool instance.
	 * 
	 * @throws ToolBusException
	 *            Thrown when the tool could not be started.
	 */
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
	
	/**
	 * Returns the key that is associated with this tool instance.
	 * 
	 * @return The key that is associated with this tool instance.
	 */
	public ATermAppl getToolKey(){
		return toolKey;
	}
	
	/**
	 * Returns the name of the tool that is associated with this tool instance.
	 * 
	 * @return The name of the tool that is associated with this tool instance.
	 */
	public String getToolName(){
		return toolKey.getName();
	}
	
	/**
	 * Returns the signature of the tool that is associated with this tool instance.
	 * 
	 * @return The signature of the tool that is associated with this tool instance.
	 */
	public ATerm getSignature(){
		return toolDef.getSignature();
	}
	
	/**
	 * @see toolbus.communication.IDataHandler#setIOHandler(IIOHandler)
	 */
	public void setIOHandler(IIOHandler ioHandler){
		this.ioHandler = ioHandler;
	}
	
	/**
	 * @see toolbus.communication.IDataHandler#receive(byte, ATerm)
	 */
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
				lastDebugPerformanceStats = aTerm;
				break;
			default:
				LoggerFactory.log("Message with unknown operation received from Tool: " + operation, ILogger.WARNING, IToolBusLoggerConstants.TOOLINSTANCE);
		}
		
		// Notify the ToolBus of the arrival of a message.
		toolbus.workArrived(this, operation);
	}
	
	/**
	 * Sends an ack event to the with this tool instance associated tool.
	 * 
	 * @param aTerm
	 *            The ack event.
	 */
	public void sendAckEvent(ATerm aTerm){
		send(ACKEVENT, aTerm);
	}
	
	/**
	 * Sends a do request to the with this tool instance associated tool.
	 * 
	 * @param aTerm
	 *            The do request.
	 */
	public void sendDo(ATerm aTerm){
		send(DO, aTerm);
	}
	
	/**
	 * Sends an evaluation request to the with this tool instance associated tool.
	 * 
	 * @param aTerm
	 *            The evaluation request.
	 */
	public void sendEval(ATerm aTerm){
		send(EVAL, aTerm);
	}
	
	/**
	 * Sends a termination request to the with this tool instance associated tool.
	 * 
	 * @param aTerm
	 *            The termination request.
	 */
	public void sendTerminate(ATerm aTerm){
		send(TERMINATE, aTerm);
	}
	
	/**
	 * Sends a performance statistics request to the with this tool instance associated tool.
	 * 
	 * @param aTerm
	 *            The performance statistics request.
	 */
	public void sendPerformanceStatsRequest(ATerm aTerm){
		send(PERFORMANCESTATS, aTerm);
	}
	
	/**
	 * Sends a debug performance statistics request to the with this tool instance associated tool.
	 */
	public void sendDebugPerformanceStatsRequest(){
		send(DEBUGPERFORMANCESTATS, toolbus.getTBTermFactory().makeList());
	}
	
	/**
	 * @see toolbus.communication.IDataHandler#send(byte, ATerm)
	 */
	public void send(byte operation, ATerm aTerm){
		ioHandler.send(operation, aTerm);
	}
	
	/**
	 * @see toolbus.communication.IDataHandler#terminate()
	 */
	public void terminate(){
		ioHandler.terminate();
	}
	
	/**
	 * @see toolbus.communication.IDataHandler#shutDown()
	 */
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
	
	/**
	 * Checks if the tool that is associated with this tool instance was executed or connected on it's own initiative.
	 * 
	 * @return True if the tool was executed; false otherwise.
	 */
	public boolean isExecutedTool(){
		return (streamHandler != null);
	}
	
	/**
	 * Forcefully terminates the with this tool instance associated tool.
	 * NOTE: This only works for executed tools. Tools that connected on their own initiative won't
	 * be killed by the invocation of this method; however they will become unreachable and their
	 * state will be set to 'killed'.
	 */
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
		
		if(streamHandler != null) streamHandler.destroy(); // Forcefully kills the tool.
	}
	
	/**
	 * @see IDataHandler#exceptionOccured()
	 */
	public void exceptionOccured(){
		goUnreachable();
		
		LoggerFactory.log("Tool crashed / disconnected: "+toolKey, ILogger.WARNING, IToolBusLoggerConstants.TOOLINSTANCE);
	}
	
	/**
	 * Attempts to find a value that matches the given signature. If this is the case the
	 * environment will be updated.
	 * 
	 * @param aTerm
	 *            The signature we need to match on.
	 * @param env
	 *            The enviroment in which we need to make updates, when a match have been made.
	 * @return Indicates if the matches was successful.
	 */
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
	
	/**
	 * Attempts to find a event that matches the given signature. If one is found the environment
	 * will be updated.
	 * 
	 * @param aTerm
	 *            The signature we need to match on.
	 * @param env
	 *            The enviroment in which we need to make updates, when a match have been made.
	 * @return Indicates if the matches was successful.
	 */
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
	
	/**
	 * Attempts to find performance statistics that match the given signature. If one is found the
	 * environment will be updated.
	 * 
	 * @param aTerm
	 *            The signature we need to match on.
	 * @param env
	 *            The enviroment in which we need to make updates, when a match have been made.
	 * @return Indicates if the matches was successful.
	 */
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
	
	/**
	 * Returns the last received batch of debug performance statistics.
	 * NOTE: This method will only be used in debug mode, by the debug ToolBus.
	 * 
	 * @return The last received batch of debug performance statistics.
	 */
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
	
	/**
	 * Notifies this tool instance that the tool connected.
	 */
	private void goConnected(){
		synchronized(stateLock){
			state = READY;
		}
	}
	
	/**
	 * Notifies this tool instance that the tool is ready to receive a new DO or EVAL request.
	 */
	private void goReady(){
		synchronized(stateLock){
			if(state == BLOCKED) state = READY;
		}
	}
	
	/**
	 * Notifies this tool instance that the tool has disconnected.
	 */
	private void goDisconnected(){
		synchronized(stateLock){
			if(isConnected()) state = DISCONNECTED;
		}
	}
	
	/**
	 * Notifies this tool instance that the tool has terminated.
	 */
	private void goTerminated(){
		synchronized(stateLock){
			state = TERMINATED;
		}
	}
	
	/**
	 * Notifies this tool instance that the tool has become unreachable.
	 */
	private void goUnreachable(){
		synchronized(stateLock){
			state = UNREACHABLE;
		}
	}
	
	/**
	 * Notifies this tool instance that the tool has been killed.
	 */
	private void goKilled(){
		synchronized(stateLock){
			state = KILLED;
		}
	}
	
	/**
	 * Checks if the tool is connected.
	 * 
	 * @return True if the tool is connected; false otherwise.
	 */
	public boolean isConnected(){
		synchronized(stateLock){
			return ((state & (READY | BLOCKED)) != 0);
		}
	}
	
	/**
	 * Checks if the tool has disconnected.
	 * 
	 * @return True if the tool has disconnected; false otherwise.
	 */
	public boolean isDisconnected(){
		synchronized(stateLock){
			return (state == DISCONNECTED);
		}
	}
	
	/**
	 * Checks if the tool has become unreachable.
	 * 
	 * @return True if the tool has become unreachable.
	 */
	public boolean isUnreachable(){
		synchronized(stateLock){
			return (state == UNREACHABLE);
		}
	}
	
	/**
	 * Checks if the tool has been terminated.
	 * 
	 * @return True if the tool has been terminated.
	 */
	public boolean isTerminated(){
		synchronized(stateLock){
			return (state == KILLED);
		}
	}
	
	/**
	 * Checks if the tool has been killed.
	 * 
	 * @return True if the tool has been killed; false otherwise.
	 */
	public boolean isKilled(){
		synchronized(stateLock){
			return (state == KILLED);
		}
	}
	
	/**
	 * Notifies the tool instance that you want to send a DO or EVAL request to the tool and checks
	 * if this is possible.
	 * 
	 * @return True if it is possible to send a DO or EVAL request; false otherwise.
	 */
	public boolean tryDoEval(){
		synchronized(stateLock){
			if(state == READY){
				state = BLOCKED;
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Returns the status of this tool instance in string format.
	 * 
	 * @return The status of this tool instance in string format.
	 */
	public String showStatus(){
		synchronized(stateLock){
			return "tool " + toolKey.toString() + "(state = " + state + ")";
		}
	}
	
	/**
	 * Handles the output and error streams of a tool process.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class StreamHandler implements Runnable{
		private final Process process;
		private final String toolID;
		
		/**
		 * Constructor.
		 * 
		 * @param process
		 *            The tool process.
		 * @param toolID
		 *            The tool identifier.
		 */
		public StreamHandler(Process process, String toolID){
			this.process = process;
			this.toolID = toolID;
		}
		
		/**
		 * @see java.lang.Runnable#run()
		 */
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
		
		/**
		 * Forcefully terminates the associated tool process.
		 */
		public void destroy(){
			process.destroy();
		}
	}
}
