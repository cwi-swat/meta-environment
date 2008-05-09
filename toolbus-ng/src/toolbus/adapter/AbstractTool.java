package toolbus.adapter;

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
	protected final static PureFactory termFactory = TBTermFactory.getInstance();

	public final static String DIRECTTOOL = "direct";
	public final static String REMOTETOOL = "remote";

	/**
	 * This variable MUST be set before tool interaction can take place.
	 */
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
	public abstract void connect(String[] args) throws Exception;
	
	/**
	 * Sets the reference ot the tool bridge we're using.
	 * 
	 * @param toolBridge
	 *            The reference ot the tool bridge we're using.
	 */
	public void setToolBridge(ToolBridge toolBridge){
		this.toolBridge = toolBridge;
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
		toolBridge.postEvent(aTerm);
	}
	
	/**
	 * Posts a request to the ToolBus.
	 * 
	 * @param aTerm
	 *            The term that contains the data about the request.
	 * @return The response.
	 */
	public ATerm sendRequest(ATerm aTerm){
		return toolBridge.postRequest(aTerm);
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
