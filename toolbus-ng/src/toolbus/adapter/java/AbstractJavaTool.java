package toolbus.adapter.java;

import java.net.InetAddress;

import toolbus.ToolBus;
import toolbus.DirectConnectionHandler;
import toolbus.adapter.AbstractTool;

/**
 * This class facilitates the functions a tool needs to be able to functions.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractJavaTool extends AbstractTool{
	
	/**
	 * Default constructor.
	 */
	public AbstractJavaTool(){
		super();
	}

	/**
	 * Connects to the ToolBus.
	 * 
	 * @param args
	 *            The arguments that contain the required information for running a tool (name + id
	 *            and additionally the host + port of the ToolBus, depending on how this tool is
	 *            connected to the ToolBus).
	 * @throws Exception
	 *             Thrown when something goes wrong during the parsing of the arguments or the
	 *             establishing of the connection.
	 */
	public void connect(String[] args) throws Exception{
		if(toolBridge != null) throw new RuntimeException("Already connected.");
		
		String toolName = null;
		int toolID = -1;

		InetAddress host = null;
		int port = -1;

		for(int i = 0; i < args.length; i++){
			String arg = args[i];
			if(arg.equals("-TB_TOOL_NAME")){
				toolName = args[++i];
			}else if(arg.equals("-TB_TOOL_ID")){
				toolID = Integer.parseInt(args[++i]);
			}else if(arg.equals("-TB_HOST")){
				host = InetAddress.getByName(args[++i]);
			}else if(arg.equals("-TB_PORT")){
				port = Integer.parseInt(args[++i]);
			}
		}

		if(toolName == null) throw new RuntimeException("Missing tool identification.");

		toolBridge = new JavaToolBridge(termFactory, REMOTETOOL, this, toolName, toolID, host, port);
		toolBridge.run();
	}
	
	/**
	 * Connects to the ToolBus directly (instead of through TCP/IP).
	 * 
	 * @param toolbus
	 *            The toolbus to connect to.
	 * @param toolClassLoader
	 *            The classloader that will be used for the tool's classes.
	 * @param toolName
	 *            The name of the tool.
	 * @param toolID
	 *            The ID of the tool.
	 * @throws Exception
	 *            When connecting to the toolbus directly failed.
	 */
	public void connectDirectly(ToolBus toolbus, ClassLoader toolClassLoader, String toolName, int toolID) throws Exception{
		if(toolName == null || toolID == -1) throw new RuntimeException("Missing tool identification.");

		toolBridge = new JavaToolBridge(termFactory, DIRECTTOOL, this, toolName, toolID, null, -1);
		
		// Establish the connection.
		DirectConnectionHandler directConnectionHandler = toolbus.getDirectConnectionHandler();
		directConnectionHandler.dock(toolBridge, toolClassLoader);

		toolBridge.run();
	}
}
