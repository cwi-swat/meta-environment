package toolbus.tool;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import toolbus.IOperations;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.ToolInstanceManager;
import toolbus.communication.IDataHandler;
import toolbus.communication.IIOHandler;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.tool.execution.IToolExecutor;
import toolbus.tool.execution.IToolExecutorFactory;
import toolbus.tool.execution.StreamHandler;
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
	private final List<ATerm> requestsFromTool;
	
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
		requestsFromTool = new LinkedList<ATerm>();
		
		performanceStats = new LinkedList<ATerm>();
	}
	
	/**
	 * Executes the tool that should be associated with this tool instance.
	 * 
	 * @throws ToolBusException
	 *            Thrown when the tool could not be executed.
	 */
	public void executeTool() throws ToolBusException{
		IToolExecutorFactory toolExecutorFactory = toolbus.getToolExecutorFactory();
		
		IToolExecutor toolExecutor = toolExecutorFactory.getToolExecutor(this, toolDef, toolbus);
		toolExecutor.execute();
	}
	
	/**
	 * Returns the key of the tool that is associated with this tool instance.
	 * 
	 * @return The key of the tool that is associated with this tool instance.
	 */
	public ATermAppl getToolKey(){
		return toolKey;
	}
	
	/**
	 * Returns the id of the tool that is associated with this tool instance.
	 * 
	 * @return The id of the tool that is associated with this tool instance.
	 */
	public int getToolID(){
		return toolID;
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
	 * Sets the stream handler for this tool instance.
	 * 
	 * @param streamHandler
	 *            The stream handler to use.
	 */
	public void setStreamHandler(StreamHandler streamHandler){
		this.streamHandler = streamHandler;
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
			case REQUEST:
				synchronized(requestsFromTool){
					requestsFromTool.add(aTerm);
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
	 * Sends an response to the with this tool instance associated tool.
	 * 
	 * @param aTerm
	 *            The response.
	 */
	public void sendResponse(ATerm aTerm){
		send(RESPONSE, aTerm);
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
	 * Attempts to find a request that matches the given signature. If one is found the environment
	 * will be updated.
	 * 
	 * @param aTerm
	 *            The signature we need to match on.
	 * @param env
	 *            The enviroment in which we need to make updates, when a match have been made.
	 * @return Indicates if the matches was successful.
	 */
	public boolean getRequestFromTool(ATerm aTerm, Environment env){
		synchronized(requestsFromTool){
			Iterator<ATerm> requestsIterator = requestsFromTool.iterator();
			while(requestsIterator.hasNext()){
				boolean matches = tbfactory.matchPatternToValue(aTerm, env, requestsIterator.next());
				if(matches){
					requestsIterator.remove();
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
	
	private volatile int state = UNCONNECTED;
	
	private final Object stateLock = new Object();
	
	/**
	 * Notifies this tool instance that the tool connected.
	 */
	private void goConnected(){
		state = READY;
	}
	
	/**
	 * Notifies this tool instance that the tool is ready to receive a new DO or EVAL request.
	 */
	public void goReady(){
		synchronized(stateLock){
			if(state == BLOCKED) state = READY; // Only go back to ready when we're still reachable (i.e. not killed/terminated/disconnected).
		}
	}
	
	/**
	 * Notifies this tool instance that the tool has disconnected.
	 */
	private void goDisconnected(){
		synchronized(stateLock){
			if(isConnected()) state = DISCONNECTED; // Only go back to disconnected when we're still reachable (i.e. not killed/terminated).
		}
	}
	
	/**
	 * Notifies this tool instance that the tool has terminated.
	 */
	private void goTerminated(){
		state = TERMINATED;
	}
	
	/**
	 * Notifies this tool instance that the tool has been killed.
	 */
	private void goKilled(){
		state = KILLED;
	}
	
	/**
	 * Notifies this tool instance that the tool has become unreachable.
	 */
	private void goUnreachable(){
		state = UNREACHABLE;
	}
	
	/**
	 * Checks if the tool is connected.
	 * 
	 * @return True if the tool is connected; false otherwise.
	 */
	public boolean isConnected(){
		return ((state & (READY | BLOCKED)) != 0); // We can do something smart here (0x2 indicates that we're connected since the ready and blocked states are the only two states for which this bit is set).
	}
	
	/**
	 * Checks if the tool is ready.
	 * 
	 * @return True if the tool is ready; false otherwise.
	 */
	public boolean isReady(){
		return (state == READY);
	}
	
	/**
	 * Checks if the tool has disconnected.
	 * 
	 * @return True if the tool has disconnected; false otherwise.
	 */
	public boolean isDisconnected(){
		return (state == DISCONNECTED);
	}
	
	/**
	 * Checks if the tool has been terminated.
	 * 
	 * @return True if the tool has been terminated.
	 */
	public boolean isTerminated(){
		return (state == TERMINATED);
	}
	
	/**
	 * Checks if the tool has been killed.
	 * 
	 * @return True if the tool has been killed; false otherwise.
	 */
	public boolean isKilled(){
		return (state == KILLED);
	}
	
	/**
	 * Checks if the tool has become unreachable.
	 * 
	 * @return True if the tool has become unreachable.
	 */
	public boolean isUnreachable(){
		return (state == UNREACHABLE);
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
	 * Returns an array of all queued rec-value terms for this tool instance.
	 * 
	 * @return An array of all queued rec-value terms for this tool instance.
	 */
	public ATerm[] getQueuedValues(){
		synchronized(valuesFromTool){
			ATerm[] queuedValues = new ATerm[valuesFromTool.size()];
			valuesFromTool.toArray(queuedValues);
			return queuedValues;
		}
	}
	
	/**
	 * Returns an array of all queued rec-event terms for this tool instance.
	 * 
	 * @return An array of all queued rec-event terms for this tool instance.
	 */
	public ATerm[] getQueuedEvents(){
		synchronized(eventsFromTool){
			ATerm[] queuedEvents = new ATerm[eventsFromTool.size()];
			eventsFromTool.toArray(queuedEvents);
			return queuedEvents;
		}
	}
	
	/**
	 * Returns an array of all queued rec-request terms for this tool instance.
	 * 
	 * @return An array of all queued rec-request terms for this tool instance.
	 */
	public ATerm[] getQueuedRequests(){
		synchronized(requestsFromTool){
			ATerm[] queuedRequests = new ATerm[requestsFromTool.size()];
			requestsFromTool.toArray(queuedRequests);
			return queuedRequests;
		}
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
}
