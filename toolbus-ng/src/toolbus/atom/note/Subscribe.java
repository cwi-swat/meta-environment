/*
 * Created on Jun 25, 2005 @author paulk
 */
package toolbus.atom.note;

import java.util.Stack;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.matching.MatchStore;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public class Subscribe extends Atom{
	public final ATerm notePattern;
	
	public Subscribe(ATerm msgpat, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.notePattern = msgpat;
		setAtomArgs(new Ref[]{new Ref(msgpat)});
	}
	
	public ProcessExpression copy(){
		Atom a = new Subscribe(notePattern, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public void compile(ProcessInstance pi, Stack<String> calls, State follow) throws ToolBusException{
		super.compile(pi, calls, follow);
		
		registerPartners();
	}
	
	public void registerPartners(){
		MatchStore matchStore = getToolBus().getMatchStore();
		matchStore.registerSubscribeNote(this);
	}
	
	public void destroy(){
		MatchStore matchStore = getToolBus().getMatchStore();
		matchStore.deregisterSubscribeNote(this);
	}
	
	public ATerm getMatchPattern(){
		return notePattern;
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		ATerm subscribePattern = tbfactory.fullSubstitute(notePattern, getEnv());
		if(subscribePattern == null) throw new ToolBusException("Illegal subscription pattern: "+notePattern+".");
		
		getProcess().subscribe(subscribePattern);
		return true;
	}
}
