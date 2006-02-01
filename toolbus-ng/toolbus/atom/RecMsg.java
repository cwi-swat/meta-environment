package toolbus.atom;

import toolbus.TBTermFactory;
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
    Atom a = new RecMsg(getMsg(), getId());
    a.copyAtomAttributes(this);
    return a;
  }
  
  public boolean canCommunicate(MsgAtom a) {
		return (a instanceof SndMsg
				 && TBTermFactory.mightMatch(getMsg(), a.getMsg()));
	}
 
}
