package toolbus.atom;

import toolbus.TBTerm;
import toolbus.process.ProcessExpression;

import aterm.*;

/**
 * @author paulk, Aug 3, 2002
 */

public class RecMsg extends CommAtom {

  public RecMsg(ATerm msg) {
    super(msg);
  }
  
  public ProcessExpression copy(){
    return new RecMsg(getMsg());
  }

  public boolean canCommunicate(CommAtom a) {
    return a instanceof SndMsg && TBTerm.mightMatch(getMsg(), a.getMsg());
  }
}
