package nl.cwi.bus.server;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Contains the list of connected tool
 * 
 * @author Arnold Lankamp
 */
public class ToolManager{
	private List tools = null;

	/**
	 * Default constructor
	 */
	public ToolManager(){
		super();

		tools = new ArrayList();
	}

	/**
	 * Registers a toolinstance
	 * 
	 * @param toolInstance
	 *            The toolinstance that needs to be registered.
	 */
	public void register(ToolInstance toolInstance){
		synchronized(tools){
			tools.add(toolInstance);
		}
	}

	/**
	 * Deregisters a toolinstance.
	 * 
	 * @param toolInstance
	 *            The toolinstance that needs to be deregistered
	 */
	public void deregister(ToolInstance toolInstance){
		synchronized(tools){
			tools.remove(toolInstance);
		}
	}

	/**
	 * Returns the instance of the tool with the given id
	 * 
	 * @param toolID
	 *            The id of the tool
	 * @return null if there is no tool associated with the given id
	 */
	public ToolInstance getToolInstance(long toolID){
		ToolInstance toolInstance = null;

		Iterator toolIterator = tools.iterator();
		while(toolIterator.hasNext()){
			ToolInstance ti = (ToolInstance) toolIterator.next();
			if(ti.getID() == toolID){
				toolInstance = ti;
				break;
			}
		}

		return toolInstance;
	}

	/**
	 * Returns an iterator for this collection of tool instances.
	 * 
	 * @return An iterator for this collection of tool instances.
	 */
	public Iterator getIterator(){
		return tools.iterator();
	}
}
