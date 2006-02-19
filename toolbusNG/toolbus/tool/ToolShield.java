package toolbus.tool;

import java.io.IOException;

import toolbus.TBTermFactory;
import toolbus.exceptions.ToolBusException;
import aterm.ATerm;
import aterm.ATermList;

/**
 * @author paulk, Jul 31, 2002
 * 
 * ToolShield is a general encapsulation of tool execution that is specialized for various
 * kinds of tools. The general picture (in case of a Java tool) is:
 * 		ToolInstance -> ToolShield -> JavaToolShield -> (JavaToolBridge + class implementing the tool)
 * For a classic ToolBus tool it is:
 *  	ToolInstance -> ToolShield --> ClassicToolShield -- TCP/IP connection --> external executable
 */

public abstract class ToolShield {
	
	protected ToolInstance toolInstance;		// Backward link to ToolInstance that created this ToolShield
	
	protected TBTermFactory tbfactory;			// The TBTerm factory that we are using
	
	public ToolShield(ToolInstance ti) {
		toolInstance = ti;
		tbfactory = ti.getTBTermFactory();
	}

	/**
	 * @return the tool instance that created this shield.
	 */
	public ToolInstance getToolInstance() {
		return toolInstance;
	}

	/**
	 * @return  the current TBTermfactory.
	 */
	public TBTermFactory getTBTermFactory() {
		return tbfactory;
	}
	
	/**
	 * Start the actual execution of the tool
	 * @throws ToolBusException TODO
	 */
	abstract public void executeTool() throws ToolBusException;
	
	/**
	 * Connect an executing tool
	 * @param connection, provides the information nedded to connect
	 * @throws IOException
	 */
	abstract public void connect(Object connection) throws IOException;
	
	/**
	 * sndRequestToTool sends a request to the tool
	 * @param operation to be performed
	 * @param call ATerm denoting the actual request
	 */
	
	abstract protected void sndRequestToTool(int operation, ATerm call);
	
	/**
	 * Send an arbitrary term to our ToolInstance (and hence to the ToolBus)
	 */	
	
	public void sndTermFromToolToToolBus(ATerm trm){
		toolInstance.handleTermFromTool(trm);
	}
	
	/**
	 * Terminate execution of this tool
	 * @param msg provides information to tool (which will probably display it)
	 */

	abstract public void terminate(ATerm msg) ;
}