package toolbus.atom;

import toolbus.ToolBusException;

/**
 * @author paulk, Jul 26, 2002
 */
public class ShutDown extends Atom {
	
	
	public ShutDown(){
		super();
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled())
			return false;
		System.exit(0);
		return true;
	}
}
