/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import toolbus.TBTermFactory;
import toolbus.process.ProcessExpression;

import aterm.*;

public class SndMsg extends MsgAtom {

  public SndMsg(ATerm msg) {
    super(msg);
  }
  
  public SndMsg(ATerm msg, ATerm qual) {
    super(msg, qual);
  }
  
  public ProcessExpression copy(){
    Atom a = new SndMsg(getMsg(), getId());
    a.copyAtomAttributes(this);
    return a;
  }
  public boolean canCommunicate(MsgAtom a) {
		return (a instanceof RecMsg
				 && TBTermFactory.mightMatch(getMsg(), a.getMsg()));
	}
}