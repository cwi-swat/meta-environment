/*
 * Created on Jun 25, 2005 @author paulk
 */
package toolbus.atom.note;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.ToolBusExecutionException;
import toolbus.matching.MatchStore;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public class SndNote extends Atom{
	public final ATerm notePattern;
	
	public SndNote(ATerm note, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.notePattern = note;
		setAtomArgs(new Ref[]{new Ref(note)});
	}
	
	public ProcessExpression copy(){
		Atom a = new SndNote(notePattern, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		if(isEnabled()){
			MatchStore matchStore = getToolBus().getMatchStore();
			Set<ProcessInstance> notePartners = matchStore.getPossibleNotePartners(notePattern);
			
			if(notePartners.size() == 0) return true;
			
			ATerm theNote = tbfactory.fullSubstitute(notePattern, getEnv());
			if(theNote == null) throw new ToolBusExecutionException("Illegal note pattern: "+theNote+".", getPosInfo());
			
			Iterator<ProcessInstance> notePartnersIterator = notePartners.iterator();
			while(notePartnersIterator.hasNext()){
				ProcessInstance pi = notePartnersIterator.next();
				
				pi.putNoteInQueue(theNote);
			}
			return true;
		}
		return false;
	}
	
	public ProcessInstance[] debugExecute() throws ToolBusException{
		if(isEnabled()){
			MatchStore matchStore = getToolBus().getMatchStore();
			Set<ProcessInstance> notePartners = matchStore.getPossibleNotePartners(notePattern);
			
			if(notePartners.size() == 0) return new ProcessInstance[0];
			
			ATerm theNote = tbfactory.fullSubstitute(notePattern, getEnv());
			if(theNote == null) throw new ToolBusExecutionException("Illegal note pattern: "+theNote+".", getPosInfo());
			
			List<ProcessInstance> subscribedPartners = new ArrayList<ProcessInstance>();
			Iterator<ProcessInstance> notePartnersIterator = notePartners.iterator();
			while(notePartnersIterator.hasNext()){
				ProcessInstance pi = notePartnersIterator.next();
				
				pi.putNoteInQueue(theNote);
				subscribedPartners.add(pi);
			}
			
			ProcessInstance[] partners = new ProcessInstance[subscribedPartners.size()];
			return subscribedPartners.toArray(partners);
		}
		return null;
	}
}
