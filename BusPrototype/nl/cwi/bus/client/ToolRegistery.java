package nl.cwi.bus.client;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import nl.cwi.bus.client.communication.MultiplexingClient;
import nl.cwi.bus.client.communication.MultiplexingClientServer;
import nl.cwi.bus.communication.DirectIOHandler;
import nl.cwi.bus.communication.IIOHandler;
import nl.cwi.bus.communication.SelectorCreator;
import nl.cwi.bus.server.ToolInstance;
import nl.cwi.bus.variable.RequestedVariableHandler;
import nl.cwi.bus.variable.VariableConstantPool;
import nl.cwi.bus.variable.VariableHandler;

/**
 * Manages all the tools that are running on the same VM.
 * 
 * @author Arnold Lankamp
 */
public class ToolRegistery{
	private VariableHandler variableHandler = null;
	private RequestedVariableHandler requestedVariableHandler = null;
	private VariableConstantPool variableConstantPool = null;
	private SelectorCreator selectorCreator = null;

	private MultiplexingClientServer multiplexingClientServer = null;

	private List tools = null;

	/**
	 * Default constructor.
	 */
	public ToolRegistery(){
		super();

		variableHandler = new VariableHandler();
		requestedVariableHandler = new RequestedVariableHandler();
		variableConstantPool = new VariableConstantPool();
		selectorCreator = new SelectorCreator();

		tools = new ArrayList();

		init();
	}

	/**
	 * Initializes the inter tool communication channels
	 */
	public void init(){
		multiplexingClientServer = new MultiplexingClientServer(selectorCreator);
	}

	/**
	 * Creates and registers a toolbridge.
	 * 
	 * @param tool
	 *            The tool that requested the toolbridge.
	 * @return The for the tool created toolbridge.
	 */
	public ToolBridge createBridge(ITool tool){
		ToolBridge toolBridge = new ToolBridge(tool);

		MultiplexingClient multiplexingClient = new MultiplexingClient(toolBridge);
		IIOHandler ioHandler = multiplexingClient.getIOHandler();
		toolBridge.setIOHandler(ioHandler);

		return toolBridge;
	}

	/**
	 * Creates and registers a toolbridge, also a direct link with the bus is
	 * created. The tool and the bus must however be running at the same
	 * machine.
	 * 
	 * @param tool
	 *            The tool that requested the toolbridge.
	 * @return The for the tool created toolbridge
	 */
	public ToolBridge createDirectBridge(ITool tool){
		DirectIOHandler toolBridgeIOHandler = new DirectIOHandler();
		DirectIOHandler busIOHandler = new DirectIOHandler();
		
		toolBridgeIOHandler.setIOHandler(busIOHandler);
		busIOHandler.setIOHandler(toolBridgeIOHandler);

		ToolBridge toolBridge = new ToolBridge(tool);
		toolBridge.setIOHandler(toolBridgeIOHandler);
		toolBridgeIOHandler.setDataHandler(toolBridge);
		
		ToolInstance toolInstance = new ToolInstance(busIOHandler);
		busIOHandler.setDataHandler(toolInstance);

		return toolBridge;
	}
	
	/**
	 * Registers a toolbridge.
	 * 
	 * @param toolBridge
	 *            The toolbridge that needs to be registered
	 */
	public void register(ToolBridge toolBridge){
		tools.add(toolBridge);
	}
	
	/**
	 * Deregisters a toolbridge.
	 * 
	 * @param toolBridge
	 *            The toolbridge that needs to be deregistered
	 */
	public void deregister(ToolBridge toolBridge){
		tools.remove(toolBridge);
	}

	/**
	 * Returns the toolbridge with the given id
	 * 
	 * @param toolID
	 *            The id of the tool
	 * @return null if there is no tool associated with the given id
	 */
	public ToolBridge getToolBridge(long toolID){
		ToolBridge toolBridge = null;

		Iterator toolIterator = tools.iterator();
		while(toolIterator.hasNext()){
			ToolBridge tb = (ToolBridge) toolIterator.next();
			if(tb.getToolID() == toolID){
				toolBridge = tb;
				break;
			}
		}

		return toolBridge;
	}

	/**
	 * Returns the variablehandler.
	 * 
	 * @return The variablehandler.
	 */
	public VariableHandler getVariableHandler(){
		return variableHandler;
	}

	/**
	 * Returns the handler for requested variables.
	 * 
	 * @return The handler for requested variables.
	 */
	public RequestedVariableHandler getRequestedVariableHandler(){
		return requestedVariableHandler;
	}
	
	/**
	 * Returns the variable contant pool.
	 * 
	 * @return The variable contant pool.
	 */
	public VariableConstantPool getVariableConstantPool(){
		return variableConstantPool;
	}

	/**
	 * Returns the selectorCreator.
	 * 
	 * @return The selectorCreator.
	 */
	public SelectorCreator getSelectorCreator(){
		return selectorCreator;
	}

	/**
	 * Shuts down all the toolbridges and this registery.
	 */
	public void destroy(){
		Iterator toolIterator = tools.iterator();
		while(toolIterator.hasNext()){
			ToolBridge tb = (ToolBridge) toolIterator.next();
			tb.terminate();
		}

		multiplexingClientServer.stopRunning();
	}

	/**
	 * Nested class for initializing this singleton (needed to ensure
	 * non-synchronized lazy initialization).
	 * 
	 * @author Arnold Lankamp
	 */
	private static class InstanceKeeper{
		public final static ToolRegistery instance = new ToolRegistery();
	}

	/**
	 * Returns a reference to this singleton.
	 * 
	 * @return A reference to this singleton.
	 */
	public static ToolRegistery getInstance(){
		return InstanceKeeper.instance;
	}
}
