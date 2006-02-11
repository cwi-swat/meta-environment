package toolbus.tool;

import java.io.IOException;

import toolbus.TBTermFactory;
import aterm.ATerm;

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
	
	protected ToolInstance toolInstance;		// Backward link to ToolInstance that created this ToolShield
	protected TBTermFactory tbfactory;
	
	public ToolShield(ToolInstance ti) {
		toolInstance = ti;
		tbfactory = ti.getTBTermFactory();
	}

	public ToolInstance getToolInstance() {
		return toolInstance;
	}
	
	abstract public void executeTool();

	/**
	 * Provide the current TBTermfactory.
	 */
	public TBTermFactory getTBTermFactory() {
		return tbfactory;
	}
	
	abstract public void connect(Object connection) throws IOException;
	
	/**
	 * sndRequestToTool sends a request to the tool
	 * @param operation to be performed
	 * @param call ATerm denoting the actual request
	 */
	
	abstract protected void sndRequestToTool(Integer operation, ATerm call);


	/**
	 * Send an event to our ToolInstance (and hence to the ToolBus)
	 */

	public void sndEventFromToolToToolBus(ATerm trm) {
		toolInstance.addEventFromTool(trm);
	}
	
	public void sndValueFromToolToToolBus(ATerm trm){
		toolInstance.handleTermFromTool(trm);
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