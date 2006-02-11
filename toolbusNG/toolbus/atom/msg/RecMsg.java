package toolbus.atom.msg;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * @author paulk, Aug 3, 2002
 */

public class RecMsg extends MsgAtom {

  public RecMsg(ATerm msg, TBTermFactory tbfactory) {
    super(msg, tbfactory);
  }
  
 //  public RecMsg(ATerm msg, ATerm qual, TBTermFactory tbfactory) {
 //   super(msg, qual, tbfactory);
 // }
  
  public ProcessExpression copy(){
    Atom a = new RecMsg(getMsg(), tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }
  
  public boolean canCommunicate(MsgAtom a) {
		return (getProcess() != a.getProcess() &&
				a instanceof SndMsg
				 && tbfactory.mightMatch(getMsg(), a.getMsg()));
	}
	
  public boolean execute() throws ToolBusException {
	  // Communication is always initiated by the sender,
	  // So for the receiver nothing needs to be done.
	  return false;
  }
}
