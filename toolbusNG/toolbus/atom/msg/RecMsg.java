package toolbus.atom.msg;

import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * @author paulk, Aug 3, 2002
 */

public class RecMsg extends MsgAtom {

  public RecMsg(ATerm msg, TBTermFactory tbfactory) {
    super(msg, tbfactory);
  }
  
  public ProcessExpression copy(){
    Atom a = new RecMsg(getMsg(), tbfactory);
    a.copyAtomAttributes(this);
    return a;
  }
  
  public boolean canCommunicate(SndMsg a) throws ToolBusException {
		return tbfactory.mightMatch(getMsg(), a.getMsg());
	}
  
  public void addPartners(State set) throws ToolBusException {
	for (StateElement b : set.getElementsAsVector()) {
		if (b instanceof SndMsg) {
			SndMsg cb = (SndMsg) b;
			if (this.canCommunicate(cb)) {
				cb.addMsgPartner(this);
			}
		}
	}
  }
	
  public boolean execute() throws ToolBusException {
	  // Communication is always initiated by the sender,
	  // So for the receiver nothing needs to be done.
	  return false;
  }
}
