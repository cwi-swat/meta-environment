package toolbus.atom.msg;

import toolbus.AtomSet;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * @author paulk, Aug 3, 2002
 */
public class RecMsg extends MsgAtom{
	
	public RecMsg(ATerm msg, TBTermFactory tbfactory, ATerm posInfo){
		super(msg, tbfactory, posInfo);
	}
	
	public ProcessExpression copy(){
		Atom a = new RecMsg(getMsg(), tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean canCommunicate(SndMsg a){
		return tbfactory.mightMatch(getMsg(), a.getMsg());
	}
	
	public void addPartners(AtomSet atoms){
		for(Atom b : atoms.getSet()){
			if(b instanceof SndMsg){
				SndMsg cb = (SndMsg) b;
				if(canCommunicate(cb)){
					cb.addMsgPartner(this);
				}
			}
		}
	}
	
	public boolean execute(){
		// Communication is always initiated by the sender,
		// So for the receiver nothing needs to be done.
		return false;
	}
}
