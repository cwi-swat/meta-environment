package toolbus.viewer;

import toolbus.IOperations;
import toolbus.tool.ToolInstance;
import toolbus.util.collections.ConcurrentHashMap;
import toolbus.util.collections.ConcurrentHashSet;
import toolbus.util.collections.EntryHandlerConstants;
import toolbus.util.collections.ConcurrentHashMap.HashMapEntryHandler;
import aterm.ATerm;

/**
 * Handles performance information dispatch and retrieval.
 * 
 * @author Arnold Lankamp
 */
public class PerformanceInformationHandler{
	private final IPerformanceMonitor performanceMonitor;
	
	private final ConcurrentHashSet<ATerm> toolInstancesToMonitor;
	private final ConcurrentHashSet<String> toolTypesToMonitor;
	
	private final ConcurrentHashMap<ToolInstance, ATerm> arrivedPerformanceStats;
	private final PerformanceStatsEntryHandler performanceStatsEntryHandler;
	
	/**
	 * Constructor.
	 * 
	 * @param performanceMonitor
	 *            The tool performance monitor to use.
	 */
	public PerformanceInformationHandler(IPerformanceMonitor performanceMonitor){
		super();
		
		this.performanceMonitor = performanceMonitor;
		
		toolInstancesToMonitor = new ConcurrentHashSet<ATerm>();
		toolTypesToMonitor = new ConcurrentHashSet<String>();
		
		arrivedPerformanceStats = new ConcurrentHashMap<ToolInstance, ATerm>();
		performanceStatsEntryHandler = new PerformanceStatsEntryHandler(performanceMonitor);
	}

	/**
	 * Initiates the monitoring of the tool associated with the given tool key.
	 * 
	 * @param toolKey
	 *            The tool key associated with the tool we want to monitor.
	 */
	public void startMonitoringTool(ATerm toolKey){
		toolInstancesToMonitor.put(toolKey);
	}
	
	/**
	 * Stops monitoring the tool associated with the given tool key.
	 * 
	 * @param toolKey
	 *            The tool key associated with the tool which we want to stop monitoring.
	 */
	public void stopMonitoringTool(ATerm toolKey){
		toolInstancesToMonitor.remove(toolKey);
	}
	
	/**
	 * Initiates the monitoring of the given tool type.
	 * 
	 * @param toolName
	 *            The tool type of tool we want to monitor.
	 */
	public void startMonitorToolType(String toolName){
		toolTypesToMonitor.put(toolName);
	}
	
	/**
	 * Stops monitoring tools of the given type.
	 * 
	 * @param toolName
	 *            The type of tool which we want to stop monitoring.
	 */
	public void stopMonitoringToolType(String toolName){
		toolTypesToMonitor.remove(toolName);
	}
	
	/**
	 * Invoked by the debug toolbus when communication with a tool instance occured.
	 * @param toolInstance
	 *            The tool instance that received the data.
	 * @param operation
	 *            The operation associated with the received data.
	 */
	public void toolCommunicationTriggered(ToolInstance toolInstance, int operation){
		if(operation == IOperations.DEBUGPERFORMANCESTATS){
			arrivedPerformanceStats.put(toolInstance, toolInstance.getLastDebugPerformanceStats());
		}else if(operation == IOperations.CONNECT){
			performanceMonitor.toolConnected(toolInstance);
		}else if(operation == IOperations.END){
			performanceMonitor.toolConnectionClosed(toolInstance);
		}else if(toolInstance.isConnected()){
			if(toolInstancesToMonitor.contains(toolInstance.getToolKey()) || toolTypesToMonitor.contains(toolInstance.getToolName())){
				toolInstance.sendDebugPerformanceStatsRequest();
			}
		}
	}
	
	/**
	 * Invoked by the debug toolbus when it wishes to process all currently received performance
	 * data.
	 */
	public void handleRetrievedData(){
		arrivedPerformanceStats.iterate(performanceStatsEntryHandler);
	}

	/**
	 * Entry handler used for iterating over the arrived performance statistics.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class PerformanceStatsEntryHandler extends HashMapEntryHandler<ToolInstance, ATerm>{
		private final IPerformanceMonitor performanceMonitor;
	
		/**
		 * Costructor.
		 * 
		 * @param performanceMonitor
		 *            The performance monitor that handles the data.
		 */
		public PerformanceStatsEntryHandler(IPerformanceMonitor performanceMonitor){
			super();
			
			this.performanceMonitor = performanceMonitor;
		}
		
		/**
		 * @see toolbus.util.collections.ConcurrentHashMap.HashMapEntryHandler#handle(Object, Object)
		 */
		public int handle(ToolInstance toolInstance, ATerm performanceStats){
			performanceMonitor.performanceStatsArrived(toolInstance, performanceStats);
			
			return EntryHandlerConstants.REMOVE;
		}
	}
}
