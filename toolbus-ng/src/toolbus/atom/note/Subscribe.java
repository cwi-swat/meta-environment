/*
 * Created on Jun 25, 2005 @author paulk
 */
package toolbus.atom.note;

import toolbus.AtomSet;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

public class Subscribe extends Atom{
	private final Ref msgpat;
	
	public Subscribe(ATerm msgpat, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}
	
	public void addPartners(AtomSet atoms){
		for(Atom b : atoms.getSet()){
			if(b instanceof SndNote){
				SndNote note = (SndNote) b;
				note.addPartnerIfMatch(this);
			}
		}
	}
	
	public ProcessExpression copy(){
		Atom a = new Subscribe(msgpat.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public ATerm getMatchPattern(){
		return msgpat.value;
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		ATerm subscribePattern = tbfactory.fullSubstitute(msgpat.value, getEnv());
		if(subscribePattern == null) throw new ToolBusException("Illegal subscription pattern: "+msgpat.value+".");
		
		getProcess().subscribe(subscribePattern);
		return true;
	}
}
