/*
 * Created on Jun 25, 2005 @author paulk
 */
package toolbus.atom.note;

import java.util.ArrayList;
import java.util.List;

import toolbus.AtomSet;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public class SndNote extends Atom{
	private final Ref note;
	
	private List<ProcessInstance> notePartners = new ArrayList<ProcessInstance>();
	
	public SndNote(ATerm note, TBTermFactory tbfactory, ATerm posInfo){
		super(tbfactory, posInfo);
		this.note = new Ref(note);
		setAtomArgs(this.note);
	}
	
	public ProcessExpression copy(){
		Atom a = new SndNote(note.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	void addPartnerIfMatch(Subscribe subs){
		ATerm subscribeValue = tbfactory.substitute(subs.getMatchPattern(), subs.getEnv());
		if(tbfactory.mightMatch(subscribeValue, note.value)){
			ProcessInstance pi = subs.getProcess();
			if(!notePartners.contains(pi)) notePartners.add(pi);
		}
	}
	
	public void addPartners(AtomSet atoms){
		for(Atom b : atoms.getSet()){
			if(b instanceof Subscribe){
				Subscribe subs = (Subscribe) b;
				addPartnerIfMatch(subs);
			}
		}
	}
	
	public boolean execute() throws ToolBusException{
		if(isEnabled()){
			ATerm theNote = tbfactory.substitute(note.value, getEnv());
			
			for(ProcessInstance pi : notePartners){
				pi.putNoteInQueue(theNote);
			}
			return true;
		}
		return false;
	}
}
