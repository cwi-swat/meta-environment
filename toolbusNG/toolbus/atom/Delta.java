package toolbus.atom;

import aterm.ATerm;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.process.ProcessExpression;

/**
 * @author paulk, Jul 24, 2002
 */

public class Delta extends Atom {
  
  public Delta(TBTermFactory tbfactory, ATerm posInfo){
    super(tbfactory, posInfo);
  }
  
  public ProcessExpression copy(){
    Atom a = new Delta(tbfactory, getPosInfo());
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
