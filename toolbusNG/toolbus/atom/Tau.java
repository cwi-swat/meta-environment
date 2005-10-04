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
    Atom a = new Tau();
    a.copyAtomAttributes(this);
    return a;
  }
  
  public boolean execute() throws ToolBusException{
  	if(isEnabled()){
  		return true;
  	}
  	return false;
  }
}
