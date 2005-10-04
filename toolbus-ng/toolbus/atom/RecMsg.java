package toolbus.atom;

import toolbus.process.ProcessExpression;

import aterm.*;

/**
 * @author paulk, Aug 3, 2002
 */

public class RecMsg extends MsgAtom {

  public RecMsg(ATerm msg) {
    super(msg);
  }
  
   public RecMsg(ATerm msg, ATerm qual) {
    super(msg, qual);
  }
  
  public ProcessExpression copy(){
    atom a = new RecMsg(getMsg(), getId());
    a.copyAtomAttributes(this);
    return a;
  }
 
}
