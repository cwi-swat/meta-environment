package toolbus.atom.msg;

import toolbus.AtomSet;
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

  public RecMsg(ATerm msg, TBTermFactory tbfactory, ATerm posInfo) {
    super(msg, tbfactory, posInfo);
  }
  
  public ProcessExpression copy(){
    Atom a = new RecMsg(getMsg(), tbfactory, getPosInfo());
    a.copyAtomAttributes(this);
    return a;
  }
  
  public boolean canCommunicate(SndMsg a) throws ToolBusException {
		return tbfactory.mightMatch(getMsg(), a.getMsg());
	}
  
  public void addPartners(AtomSet atoms) throws ToolBusException {
	//System.err.println(this + " addPartners: " + atoms);
	for (Atom b : atoms.getSet()) {
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
