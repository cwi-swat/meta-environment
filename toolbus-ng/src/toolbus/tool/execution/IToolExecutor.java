package toolbus.tool.execution;

import toolbus.exceptions.ToolBusException;

/**
 * Interface all tool executors must implement.
 * 
 * @author Arnold Lankamp
 */
public interface IToolExecutor{
	
	/**
	 * Executes the tool that will be associated with the tool instance.
	 * 
	 * @throws ToolBusException
	 *            Thrown when the tool could not be started.
	 */
	public void execute() throws ToolBusException;
}
