package toolbus.atom;

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
}
