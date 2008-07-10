package toolbus.adapter.java;

import java.net.InetAddress;

import toolbus.ToolBus;
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
	 * NOTE: For thread-safety reasons this method must NOT be called before the constructor of the
	 * AbstractJavaTool completes. This means that implementing classes should not put the connect
	 * call in their constructor.
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

		toolBridge = new JavaToolBridge(termFactory, this, toolName, toolID, host, port);
		toolBridge.run();
	}
	
	/**
	 * Connects to the ToolBus directly (instead of through TCP/IP).
	 * 
	 * @param toolbus
	 *            The toolbus to connect to.
	 * @param toolClassLoader
	 *            The class loader that will be used for the tool's classes. When in doubt, use the
	 *            default class loader (ClassLoader.getSystemClassLoader()) or the context
	 *            class loader on the current thread.
	 * @param toolName
	 *            The name of the tool.
	 * @param toolID
	 *            The ID of the tool.
	 * @throws Exception
	 *            When connecting to the toolbus directly failed.
	 */
	public void connectDirectly(ToolBus toolbus, ClassLoader toolClassLoader, String toolName, int toolID) throws Exception{
		if(toolName == null) throw new RuntimeException("Missing tool identification.");
		
		toolBridge = new JavaToolBridge(termFactory, this, toolName, toolID, toolClassLoader, toolbus);
		toolBridge.run();
	}
}
