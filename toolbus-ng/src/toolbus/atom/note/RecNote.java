/*
 * Created on Jun 25, 2005 @author paulk
 */
package toolbus.atom.note;

import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public class RecNote extends Atom{
	public final ATerm notePattern;
	
	public RecNote(ATerm msgpat, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.notePattern = msgpat;
		setAtomArgs(new Ref[]{new Ref(msgpat)});
	}
	
	public ProcessExpression copy(){
		Atom a = new RecNote(notePattern, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		ProcessInstance pi = getProcess();
		if(!pi.hasNotes()) return false;
		if(isEnabled() && pi.getNoteFromQueue(notePattern, getEnv())) return true;
		
		return false;
	}
}
