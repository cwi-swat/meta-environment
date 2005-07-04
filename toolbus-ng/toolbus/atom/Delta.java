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
    return new Delta();
  }
  
  public State getFirst() {
    return new State(); // replace by single copy
  }

}
