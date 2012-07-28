/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom.msg;

import java.util.List;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.exceptions.ToolBusException;
import toolbus.matching.MatchStore;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public class SndMsg extends MsgAtom{
	private int index;
	
	public SndMsg(ATerm msg, TBTermFactory tbfactory, PositionInformation posInfo){
		super(msg, tbfactory, posInfo);
		
		index = 0;
	}
	
	public ProcessExpression copy(){
		Atom a = new SndMsg(msg, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	private boolean matchesPartner(RecMsg recMsg){
		return tbfactory.match(recMsg.msg, recMsg.getEnv(), msg, getEnv());
	}
	
	public boolean execute() throws ToolBusException{
		if(isEnabled()){
			MatchStore matchStore = getToolBus().getMatchStore();
			List<RecMsg> msgPartners = matchStore.getPossibleMessagePartners(msg);
			
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
	
	public ProcessInstance[] debugExecute() throws ToolBusException{
		if(isEnabled()){
			MatchStore matchStore = getToolBus().getMatchStore();
			List<RecMsg> msgPartners = matchStore.getPossibleMessagePartners(msg);
			
			int size = msgPartners.size();
			
			if(size == 0) return null;
			
			for(int i = (index++ % size), left = size; left > 0; i = ((i + 1) % size), left--){
				RecMsg recMsg = msgPartners.get(i);
				ProcessInstance pb = recMsg.getProcess();
				
				if(pb.contains(recMsg) && recMsg.isEnabled() && matchesPartner(recMsg)){
					//LoggerFactory.log("unknown", "    " + this, IToolBusLoggerConstants.MESSAGES);
					//LoggerFactory.log("unknown", "<=> " + b, IToolBusLoggerConstants.MESSAGES);
					pb.gotoNextStateAndActivate(recMsg);
					return new ProcessInstance[]{pb};
				}
			}
		}
		return null;
	}
}
