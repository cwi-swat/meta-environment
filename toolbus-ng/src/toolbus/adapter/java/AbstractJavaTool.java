package toolbus.adapter.java;

import java.net.InetAddress;
import toolbus.TBTermFactory;
import toolbus.adapter.AbstractTool;
import toolbus.adapter.ToolBridge;
import aterm.pure.PureFactory;

/**
 * This class facilitates the functions a tool needs to be able to functions.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractJavaTool extends AbstractTool{
	private final static PureFactory termFactory = TBTermFactory.getInstance();

	protected ToolBridge toolBridge = null;

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
		String type = null;

		String toolName = null;
		int toolID = -1;

		InetAddress host = null;
		int port = -1;

		for(int i = 0; i < args.length; i++){
			String arg = args[i];
			if(arg.equals("-TYPE")){
				type = args[++i];
			}else if(arg.equals("-TB_TOOL_NAME")){
				toolName = args[++i];
			}else if(arg.equals("-TB_TOOL_ID")){
				toolID = Integer.parseInt(args[++i]);
			}else if(arg.equals("-TB_HOST")){
				host = InetAddress.getByName(args[++i]);
			}else if(arg.equals("-TB_PORT")){
				port = Integer.parseInt(args[++i]);
			}
		}

		if(type == null || toolName == null) throw new RuntimeException("Missing tool identification.");

		toolBridge = new JavaToolBridge(termFactory, type, this, toolName, toolID, host, port);
		setToolBridge(toolBridge);
		toolBridge.run();
	}
}
