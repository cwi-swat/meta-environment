package toolbus.atom;

import aterm.ATerm;
import toolbus.TBTermFactory;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;

/**
 * @author paulk, Jul 24, 2002
 */

public class Tau extends Atom {
  
  public Tau(TBTermFactory tbfactory, ATerm posInfo){
    super(tbfactory, posInfo);
  }

  public ProcessExpression copy() {
    Atom a = new Tau(tbfactory, getPosInfo());
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
