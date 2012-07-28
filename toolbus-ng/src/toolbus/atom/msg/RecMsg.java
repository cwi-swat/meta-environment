package toolbus.atom.msg;

import java.util.Stack;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.exceptions.ToolBusException;
import toolbus.matching.MatchStore;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

/**
 * @author paulk, Aug 3, 2002
 */
public class RecMsg extends MsgAtom{
	
	public RecMsg(ATerm msg, TBTermFactory tbfactory, PositionInformation posInfo){
		super(msg, tbfactory, posInfo);
	}
	
	public ProcessExpression copy(){
		Atom a = new RecMsg(msg, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public void compile(ProcessInstance pi, Stack<String> calls, State follow) throws ToolBusException{
		super.compile(pi, calls, follow);
		
		registerPartners();
	}
	
	public void registerPartners(){
		MatchStore matchStore = getToolBus().getMatchStore();
		matchStore.registerReceiveMessage(this);
	}
	
	public void destroy(){
		MatchStore matchStore = getToolBus().getMatchStore();
		matchStore.deregisterReceiveMessage(this);
	}
	
	public boolean execute(){
		// Communication is always initiated by the sender,
		// So for the receiver nothing needs to be done.
		return false;
	}
}
