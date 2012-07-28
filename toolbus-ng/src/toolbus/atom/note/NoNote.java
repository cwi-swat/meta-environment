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
import aterm.ATerm;

public class NoNote extends Atom{
	private final ATerm msgpat;
	
	public NoNote(ATerm msgpat, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.msgpat = msgpat;
		setAtomArgs(new Ref[]{new Ref(msgpat)});
	}
	
	public ProcessExpression copy(){
		Atom a = new NoNote(msgpat, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		if(getProcess().noNoteInQueue(msgpat, getEnv())) return true;
		
		return false;
	}
}
