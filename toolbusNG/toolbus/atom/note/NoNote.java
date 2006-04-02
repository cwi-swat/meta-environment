/*
 * Created on Jun 25, 2005
 * @author paulk
 *
 */
package toolbus.atom.note;

import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * 
 *
 */
public class NoNote extends Atom {
	private Ref msgpat;
	
	public NoNote(ATerm msgpat, TBTermFactory tbfactory, ATerm posInfo){
		super(tbfactory, posInfo);
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}

	public ProcessExpression copy() {
		Atom a = new NoNote(msgpat.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	 public boolean execute() throws ToolBusException {
	    if (!isEnabled())
	      return false;
		if (getProcess().noNoteInQueue(this.msgpat.value, getEnv()))
			return true;
		else
			return false;
	 }
}
