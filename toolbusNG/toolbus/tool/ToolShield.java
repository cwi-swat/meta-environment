package toolbus.tool;

import java.io.IOException;
import java.nio.channels.SocketChannel;
import java.util.LinkedList;

import toolbus.TBTermFactory;
import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author paulk, Jul 31, 2002
 * 
 * ToolShield is a general encapsulation of tool execution that is specialized for various
 * kinds of tools. The general picture (in case of a Java tool) is:
 * 		ToolInstance -> ToolShield -> JavaToolShield -> class implementing the tool
 * For a classic ToolBus tool it is:
 *  	ToolInstance -> ToolShield --> ClassicToolShield -- TCP/IP connection --> external executable
 */

public abstract class ToolShield {
	
	private ToolInstance toolInstance;		// Backward link to ToolInstance that created this ToolShield
	
	public ToolShield(ToolInstance ti) {
		toolInstance = ti;
	}

	public ToolInstance getToolInstance() {
		return toolInstance;
	}

	/**
	 * Provide the current ATermfactory.
	 */
	public ATermFactory getFactory() {
		return TBTermFactory.getPureFactory();
	}
	
	abstract public void connect(SocketChannel channel) throws IOException;
	
	abstract protected void handleRequestToTool(Integer operation, ATerm call);
	
	/**
	 * sndRequestToTool sends a request to the tool
	 * @param operation to be performed
	 * @param call ATerm denoting the actual request
	 */
	
	public void sndRequestToTool(Integer operation, ATerm call) {
		//info("sndRequestToTool(" + operation + ", " + call + ")");
		handleRequestToTool(operation, call);
	}

	/**
	 * Send an event to our ToolInstance (and hence to the ToolBus)
	 */

	public void sndEventToToolBus(ATerm trm) {
		toolInstance.addEventFromTool(trm);
	}
	
	/**
	 * initRun gives subclasses a chance to do specific initialization
	 */
	public void initRun(){
	}
	
	/**
	 * Terminate execution of this tool
	 */

	abstract public void terminate(ATerm msg) ;
}