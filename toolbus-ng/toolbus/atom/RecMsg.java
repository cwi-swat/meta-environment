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
  
  public ProcessExpression copy(){
    return new RecMsg(getMsg());
  }
 
}
