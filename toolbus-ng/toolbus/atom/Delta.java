package toolbus.atom;

import toolbus.State;
import toolbus.process.ProcessExpression;

/**
 * @author paulk, Jul 24, 2002
 */

public class Delta extends Atom {
  
  public Delta(){
    super();
  }
  
  public ProcessExpression copy(){
    Atom a = new Delta();
    a.copyAtomAttributes(this);
    return a;
  }
  
  public State getFirst() {
    return new State(); // replace by single copy
  }
  
  public boolean execute(){
  	return false;
  }

}
