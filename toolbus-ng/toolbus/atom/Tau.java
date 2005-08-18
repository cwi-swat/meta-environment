package toolbus.atom;

import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;

/**
 * @author paulk, Jul 24, 2002
 */

public class Tau extends Atom {
  
  public Tau(){
    super();
  }

  public ProcessExpression copy() {
    return new Tau();
  }
  
  public boolean execute() throws ToolBusException{
  	if(isEnabled()){
  		return true;
  	}
  	return false;
  }
}
