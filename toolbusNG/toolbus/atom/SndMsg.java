/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import toolbus.process.ProcessExpression;

import aterm.*;

public class SndMsg extends MsgAtom {

  public SndMsg(ATerm msg) {
    super(msg);
  }
  
  public ProcessExpression copy(){
    return new SndMsg(getMsg());
  }

}