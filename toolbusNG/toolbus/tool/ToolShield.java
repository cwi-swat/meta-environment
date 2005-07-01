package toolbus.tool;

import java.lang.reflect.Method;
import java.util.LinkedList;

import toolbus.TBTerm;
import aterm.ATerm;
import aterm.ATermAppl;
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

public abstract class ToolShield extends Thread {
	
	private ToolInstance toolInstance;		// Backward link to ToolInstance that created this ToolShield
	private LinkedList requestsForTool;		// Requests to be executed by the tool

	public ToolShield(ToolInstance ti) {
		requestsForTool = new LinkedList();
		toolInstance = ti;
	}

	protected ToolInstance getToolInstance() {
		return toolInstance;
	}

	/**
	 * Provide the current ATermfactory.
	 */

	public ATermFactory getFactory() {
		return TBTerm.factory;
	}

	protected Object[] getNextRequestForTool() {
		Object request[] = (Object[]) requestsForTool.getFirst();
		requestsForTool.removeFirst();
		return request;
	}

	abstract protected void handleRequestForTool();

	/**
	 * Add a request from JavaTool to the internal request list
	 */

	public synchronized void addRequestForTool(/* ATerm id, */Integer operation,
			Method m, Object[] actuals) {
		requestsForTool.add(new Object[] { /* id, */operation, m, actuals });
	}
	
	/**
	 * sndRequestToTool sends a request to the tool
	 * @param operation to be performed
	 * @param call ATerm denoting the actual request
	 */

	abstract public void sndRequestToTool(/* ATerm id, */Integer operation,
			ATermAppl call);

	/**
	 * Send an event to our ToolInstance (and hence to the ToolBus)
	 */

	public ATerm sndEventToToolBus(ATerm trm) {
		return toolInstance.addEventFromTool(trm);
	}

	/**
	 * The run method for this thread
	 */

	public void run() {
		System.err.println("run of ToolShield called");
		while (true) {
			while (!requestsForTool.isEmpty())
				handleRequestForTool();
			Thread.yield();
		}
	}
	
	/**
	 * Terminate execution of this tool
	 */

	public void terminate(String msg) {
		System.err.println("ToolShield.terminate(" + msg + ")");
		try {
			join();
		} catch (InterruptedException e) {
		}
	}

}