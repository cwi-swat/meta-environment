/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;
import toolbus.TBTermFactory;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

public class SndMsg extends MsgAtom {

  public SndMsg(ATerm msg, TBTermFactory tbfactory) {
    super(msg, tbfactory);
  }
  
 // public SndMsg(ATerm msg, ATerm qual, TBTermFactory tbfactory) {
 //   super(msg, qual, tbfactory);
 // }
  
  public ProcessExpression copy(){
    Atom a = new SndMsg(getMsg(), tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }
  public boolean canCommunicate(MsgAtom a) {
		return (getProcess() != a.getProcess() &&
				a instanceof RecMsg
				 && tbfactory.mightMatch(getMsg(), a.getMsg()));
	}
}