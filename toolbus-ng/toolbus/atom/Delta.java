package toolbus.atom;

import toolbus.process.ProcessExpression;

/**
 * @author paulk, Jul 24, 2002
 */

public class Delta extends Atom {
  
  public ProcessExpression copy(){
    return new Delta();
  }
  
  public AtomSet getFirst() {
    return new AtomSet(); // replace by single copy
  }

  public boolean isEnabled() {
    return false;
  }
}
