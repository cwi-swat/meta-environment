/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import toolbus.TBTerm;
import toolbus.process.ProcessExpression;

import aterm.*;

public class SndMsg extends CommAtom {

  public SndMsg(ATerm msg) {
    super(msg);
  }
  
  public ProcessExpression copy(){
    return new SndMsg(getMsg());
  }

  public boolean canCommunicate(CommAtom a) {
    return a instanceof RecMsg && TBTerm.mightMatch(getMsg(), a.getMsg());
  }
}