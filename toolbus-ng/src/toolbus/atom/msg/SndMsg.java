/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom.msg;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import toolbus.AtomSet;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public class SndMsg extends MsgAtom{
	// The RecMsgs in other processes with this SndMsg can communicate
	private final List<RecMsg> msgPartners;
	private int index;
	
	public SndMsg(ATerm msg, TBTermFactory tbfactory, PositionInformation posInfo){
		super(msg, tbfactory, posInfo);
		
		msgPartners = new ArrayList<RecMsg>();
		index = 0;
	}
	
	public ProcessExpression copy(){
		Atom a = new SndMsg(getMsg(), tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean canCommunicate(RecMsg recMsg){
		return tbfactory.mightMatch(recMsg.getMsg(), getMsg());
	}

	public boolean matchesPartner(RecMsg recMsg){
		return tbfactory.match(recMsg.getMatchPattern(), recMsg.getEnv(), matchPattern, getEnv());
	}
	
	public void addMsgPartner(RecMsg a){
		if(msgPartners.contains(a)) return; // This is to prevent the same rec-msg from being added multiple times.
		
		msgPartners.add(a);
		//LoggerFactory.log(this.getProcess().getProcessName(), "add partner " + a, IToolBusLoggerConstants.MESSAGES);
	}
	
	public void delMsgPartner(StateElement a){
		msgPartners.remove(a);
	}
	
	public void addPartners(AtomSet atoms){
		Iterator<Atom> atomSetIterator = atoms.iterator();
		while(atomSetIterator.hasNext()){
			Atom b = atomSetIterator.next();
			
			if(b instanceof RecMsg){
				RecMsg cb = (RecMsg) b;
				if(canCommunicate(cb)){
					addMsgPartner(cb);
				}
			}
		}
	}
	
	public boolean execute() throws ToolBusException{
		if(isEnabled()){
			int size = msgPartners.size();
			
			if(size == 0) return false;
			
			for(int i = (index++ % size), left = size; left > 0; i = ((i + 1) % size), left--){
				RecMsg recMsg = msgPartners.get(i);
				ProcessInstance pb = recMsg.getProcess();
				
				if(pb.contains(recMsg) && recMsg.isEnabled() && matchesPartner(recMsg)){
					//LoggerFactory.log("unknown", "    " + this, IToolBusLoggerConstants.MESSAGES);
					//LoggerFactory.log("unknown", "<=> " + b, IToolBusLoggerConstants.MESSAGES);
					pb.gotoNextStateAndActivate(recMsg);
					return true;
				}
			}
		}
		return false;
	}
}
