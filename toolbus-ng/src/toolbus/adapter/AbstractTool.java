package toolbus.adapter;

import java.net.InetAddress;
import toolbus.IOperations;
import toolbus.TBTermFactory;
import aterm.ATerm;
import aterm.pure.PureFactory;

/**
 * This class facilitates the functions a tool needs to be able to functions.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractTool implements IOperations{
	private final static PureFactory termFactory = TBTermFactory.getInstance();

	public final static String DIRECTTOOL = "direct";
	public final static String REMOTETOOL = "remote";

	protected ToolBridge toolBridge = null;

	/**
	 * Default constructor.
	 */
	public AbstractTool(){
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

		toolBridge = new ToolBridge(termFactory, type, this, toolName, toolID, host, port);
		toolBridge.run();
	}

	/**
	 * Returns a reference to the tool bridge that we're using.
	 * 
	 * @return A reference to the tool bridge that we're using.
	 */
	public ToolBridge getToolBridge(){
		return toolBridge;
	}

	/**
	 * Returns a reference to the aterm factory.
	 * 
	 * @return A reference to the aterm factory.
	 */
	public PureFactory getFactory(){
		return termFactory;
	}

	/**
	 * Posts an event to the ToolBus.
	 * 
	 * @param aTerm
	 *            The term that contains the data about the event.
	 */
	public void sendEvent(ATerm aTerm){
		toolBridge.send(EVENT, aTerm);
	}

	/**
	 * Sends a disconnect request to the ToolBus.
	 * 
	 * @param aTerm
	 *            The term that contains information about the event.
	 */
	public void disconnect(ATerm aTerm){
		toolBridge.send(DISCONNECT, aTerm);
	}

	/**
	 * Terminated this Tool.
	 */
	public void terminate(){
		toolBridge.terminate();
	}
	
	/**
	 * Receives an acknowledgement message.
	 * 
	 * @param aTerm
	 *            The term containing information about the acknowledgement.
	 */
	public abstract void receiveAckEvent(ATerm aTerm);

	/**
	 * Receives a termination message.
	 * 
	 * @param aTerm
	 *            The term containing information about the termination.
	 */
	public abstract void receiveTerminate(ATerm aTerm);
}
