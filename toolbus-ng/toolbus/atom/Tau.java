package toolbus.atom;
/**
 * @author paulk, Jul 24, 2002
 */

import toolbus.ToolBusException;

public class Tau extends Atom {
	
	public Tau(){
		super();
	}
	
	public boolean execute() throws ToolBusException{
		if(isEnabled())
			return true;
		else
			return false;
	}
}
