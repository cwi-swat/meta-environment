package toolbus;

import java.util.ArrayList;
import java.util.List;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.tool.ToolInstance;
import toolbus.util.collections.ConcurrentHashMap;
import toolbus.util.collections.ConcurrentHashSet;
import toolbus.util.collections.EntryHandlerConstants;
import toolbus.util.collections.ConcurrentHashMap.HashMapEntryHandler;
import toolbus.util.collections.ConcurrentHashMap.ReadOnlyHashMapEntryHandler;
import toolbus.util.collections.ConcurrentHashSet.HashSetEntryHandler;
import toolbus.util.collections.ConcurrentHashSet.ReadOnlyHashSetEntryHandler;
import aterm.ATerm;

/**
 * This class manages all the tool instances.
 * 
 * @author Arnold Lankamp
 */
public class ToolInstanceManager{
	private final ConcurrentHashMap<ATerm, ToolInstance> activeTools;
	private final ConcurrentHashMap<ATerm, ToolInstance> pendingTools;
	private final ConcurrentHashSet<ToolInstance> dynamiclyConnectedTools;
	
	/**
	 * Default constructor.
	 */
	public ToolInstanceManager(){
		super();

		activeTools = new ConcurrentHashMap<ATerm, ToolInstance>();
		pendingTools = new ConcurrentHashMap<ATerm, ToolInstance>();
		dynamiclyConnectedTools = new ConcurrentHashSet<ToolInstance>();
	}
	
	/**
	 * Returns the tool with the given id, if it's present in the collection.
	 * 
	 * @param toolKey
	 *            The key of the tool we want to retrieve.
	 * @return The tool instance associated with the given id.
	 */
	public ToolInstance get(ATerm toolKey){
		return activeTools.get(toolKey);
	}
	
	/**
	 * Removes the tool instance that is associated with the given id from the collection.
	 * 
	 * @param toolKey
	 *            The key of the tool instance that we want to remove.
	 */
	public void remove(ATerm toolKey){
		activeTools.remove(toolKey);
	}
	
	/**
	 * Adds a connect tool instance to the collection. Connected tools are tools that are connected
	 * but are not being used by any process yet.
	 * 
	 * @param toolInstance
	 *            The pending tool instance we want to add.
	 */
	public void addDynamiclyConnectedTool(ToolInstance toolInstance){
		dynamiclyConnectedTools.put(toolInstance);
	}
	
	/**
	 * Activates and returns a tool instance of the given type. This method moves the found tool
	 * instance from the dynamicly connected collection to the active collection.
	 * 
	 * @param toolName
	 *            The name identifying the type of the tool instance.
	 * @return The tool instance that was activated; if none is found NULL will be returned.
	 */
	public ToolInstance activateDynamiclyConnectedTool(String toolName){
		// Find a dynamicly connected tool that's ready for use.
		ToolInstance toolInstance = getReadyDynamiclyConnectedTool(toolName);
		
		// Move the tool to the active tool collection (if the correct dyncamicly connected tool
		// was found).
		if(toolInstance != null){
			activeTools.put(toolInstance.getToolKey(), toolInstance);
		}
		
		return toolInstance;
	}
	
	/**
	 * Attempts to locate a dynamicly connected tool instance that is ready to be processed by the
	 * 'connect atom'.
	 * 
	 * @param toolName
	 *            The name of the tool.
	 * @return The located tool instance (if present); if none is found NULL will be returned.
	 */
	private ToolInstance getReadyDynamiclyConnectedTool(final String toolName){
		class DynamicToolsIterationHandler extends HashSetEntryHandler<ToolInstance>{
			public ToolInstance toolInstance = null;
			
			public int handle(ToolInstance ti){
				if(ti.isConnected() && ti.getToolKey().getAFun().getName().equals(toolName)){
					toolInstance = ti;
					return EntryHandlerConstants.BREAK | EntryHandlerConstants.REMOVE;
				}
				
				return EntryHandlerConstants.CONTINUE;
			}
		}
		DynamicToolsIterationHandler dynamicToolsIterationHandler = new DynamicToolsIterationHandler();
		dynamiclyConnectedTools.iterate(dynamicToolsIterationHandler);
		
		return dynamicToolsIterationHandler.toolInstance;
	}
	
	/**
	 * Removes the given tool instance from the dynamicly connected tools list (if present).
	 * 
	 * @param toolInstance
	 *            The tool instance that needs to be removed.
	 */
	public void removeDynamiclyConnectedTool(ToolInstance toolInstance){
		dynamiclyConnectedTools.remove(toolInstance);
	}
	
	/**
	 * Adds a tool instance to the list of which the tool application is currently being started.
	 * 
	 * @param toolInstance
	 *            The tool instance we want to add.
	 */
	public void addPendingTool(ToolInstance toolInstance){
		pendingTools.put(toolInstance.getToolKey(), toolInstance);
	}
	
	/**
	 * Returns the tool with the given key, if it's present in the pending tool collection.
	 * 
	 * @param toolKey
	 *            The key of the tool we want to retrieve.
	 * @return The tool instance associated with the given id.
	 */
	public ToolInstance getPendingTool(ATerm toolKey){
		return pendingTools.get(toolKey);
	}
	
	/**
	 * Attempts to activate the tool instance associated with the given key. If the tool instance
	 * associated with the given key is ready / connected, it will moved it to the activated
	 * collection.
	 * 
	 * @param toolKey
	 *            The key of the tool that has connected.
	 * @return The tool instance that was activated; if the tool instance associated with the given
	 *         key is not connected / ready, NULL will be returned.
	 */
	public ToolInstance activatePendingTool(ATerm toolKey){
		ToolInstance toolInstance = pendingTools.get(toolKey);
		
		if(toolInstance == null){
			LoggerFactory.log("Unable to locate pending tool with id: "+toolKey+".", ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			return null;
		}
		
		if(!toolInstance.isConnected()) return null;
		
		toolInstance = pendingTools.remove(toolKey);
		if(toolInstance == null){
			LoggerFactory.log("Pending tool with id: "+toolKey+" disappeared; huh where did it go, it was here a moment ago....", ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			return null;
		}
		
		activeTools.put(toolKey, toolInstance);
		
		return toolInstance;
	}
	
	/**
	 * Removes the given tool instance from the pending tools list (if present).
	 * 
	 * @param toolKey
	 *            The key that is associated with the tool instance that needs to be removed.
	 */
	public void removePendingTool(ATerm toolKey){
		pendingTools.remove(toolKey);
	}
	
	/**
	 * Notifies all tools that the ToolBus was shut down, by sending a terminate(\<term\>) message.
	 * 
	 * @param message
	 *            The message that will be encapsulated in the terminate message.
	 */
	public void shutDown(final ATerm message){
		// Shut down the active tools.
		HashMapEntryHandler<ATerm, ToolInstance> activeToolsIterationHandler = new ReadOnlyHashMapEntryHandler<ATerm, ToolInstance>(){
			public int handle(ATerm toolKey, ToolInstance toolInstance){
				toolInstance.sendTerminate(message);
				
				return EntryHandlerConstants.CONTINUE;
			}
		};
		activeTools.iterate(activeToolsIterationHandler);
		
		// Don't attempt to terminate the pending tools, since they are not connected.
		
		// Shut down the dynamicly connected tools.
		HashSetEntryHandler<ToolInstance> dynamicToolsIterationHandler = new ReadOnlyHashSetEntryHandler<ToolInstance>(){
			public int handle(ToolInstance toolInstance){
				toolInstance.sendTerminate(message);
				
				return EntryHandlerConstants.CONTINUE;
			}
		};
		dynamiclyConnectedTools.iterate(dynamicToolsIterationHandler);
	}
	
	/**
	 * Kills all known executed tools immidiately.
	 */
	public void killExecutedToolsNow(){
		HashMapEntryHandler<ATerm, ToolInstance> toolsIterationHandler = new ReadOnlyHashMapEntryHandler<ATerm, ToolInstance>(){
			public int handle(ATerm toolKey, ToolInstance toolInstance){
				toolInstance.kill();
				
				return EntryHandlerConstants.CONTINUE;
			}
		};
		
		// Kill the active tools.
		activeTools.iterate(toolsIterationHandler);
		
		// Kill the pending tools.
		pendingTools.iterate(toolsIterationHandler);
		
		// We can't kill dynamicly connected tools.
		// The ToolBus adapter will terminate the tool as soon as it finds out the connection with the ToolBus is lost.
	}
	
	/**
	 * Counts the number of connected tools that are registered with this tool instance manager.
	 * 
	 * @return The number of connected tools that are registered with this tool instance manager.
	 */
	public int numberOfConnectedTools(){
		return (activeTools.size() + dynamiclyConnectedTools.size());
	}
	
	public void showStatus(){
		// Show the active tools.
		HashMapEntryHandler<ATerm, ToolInstance> activeToolsIterationHandler = new ReadOnlyHashMapEntryHandler<ATerm, ToolInstance>(){
			public int handle(ATerm toolKey, ToolInstance toolInstance){
				System.err.println("A: " + toolInstance.showStatus());
				
				return EntryHandlerConstants.CONTINUE;
			}
		};
		activeTools.iterate(activeToolsIterationHandler);
		
		// Show the pending tools.
		HashMapEntryHandler<ATerm, ToolInstance> pendingToolsIterationHandler = new ReadOnlyHashMapEntryHandler<ATerm, ToolInstance>(){
			public int handle(ATerm toolKey, ToolInstance toolInstance){
				System.err.println("P: " + toolInstance.showStatus());
				
				return EntryHandlerConstants.CONTINUE;
			}
		};
		pendingTools.iterate(pendingToolsIterationHandler);
		
		// Show the dynamicly connected tools.
		HashSetEntryHandler<ToolInstance> dynamicToolsIterationHandler = new ReadOnlyHashSetEntryHandler<ToolInstance>(){
			public int handle(ToolInstance toolInstance){
				System.err.println("D: " + toolInstance.showStatus());
				
				return EntryHandlerConstants.CONTINUE;
			}
		};
		dynamiclyConnectedTools.iterate(dynamicToolsIterationHandler);
	}
	
	/**
	 * Returns an array, containing referencable tool instances.
	 * 
	 * @return An array, containing referencable tool instances.
	 */
	public ToolInstance[] getAllTools(){
		final List<ToolInstance> referencableTools = new ArrayList<ToolInstance>();
		
		// Active tools.
		HashMapEntryHandler<ATerm, ToolInstance> activeToolsIterationHandler = new ReadOnlyHashMapEntryHandler<ATerm, ToolInstance>(){
			public int handle(ATerm toolKey, ToolInstance toolInstance){
				referencableTools.add(toolInstance);
				return EntryHandlerConstants.CONTINUE;
			}
		};
		activeTools.iterate(activeToolsIterationHandler);
		
		// Pending tools.
		HashMapEntryHandler<ATerm, ToolInstance> pendingToolsIterationHandler = new ReadOnlyHashMapEntryHandler<ATerm, ToolInstance>(){
			public int handle(ATerm toolKey, ToolInstance toolInstance){
				referencableTools.add(toolInstance);
				return EntryHandlerConstants.CONTINUE;
			}
		};
		pendingTools.iterate(pendingToolsIterationHandler);
		
		// Dynamicly connected tools.
		HashSetEntryHandler<ToolInstance> dynamicToolsIterationHandler = new ReadOnlyHashSetEntryHandler<ToolInstance>(){
			public int handle(ToolInstance toolInstance){
				referencableTools.add(toolInstance);
				return EntryHandlerConstants.CONTINUE;
			}
		};
		dynamiclyConnectedTools.iterate(dynamicToolsIterationHandler);
		
		return referencableTools.toArray(new ToolInstance[referencableTools.size()]);
	}
}
