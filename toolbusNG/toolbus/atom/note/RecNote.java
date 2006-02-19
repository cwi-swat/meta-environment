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
import toolbus.process.ProcessInstance;
import aterm.ATerm;

/**
 * 
 *
 */
public class RecNote extends Atom {
	private Ref msgpat;

	public RecNote(ATerm msgpat, TBTermFactory tbfactory) {
		super(tbfactory);
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}

	public ProcessExpression copy() {
		Atom a = new RecNote(msgpat.value, tbfactory);
		a.copyAtomAttributes(this);
		return a;
	}

	public boolean execute() throws ToolBusException {
		ProcessInstance pi = getProcess();
		if(!pi.hasNotes()){
			return false;
		}
		if (isEnabled() && pi.getNoteFromQueue(this.msgpat.value, getEnv())) {
			return true;
		} else {
			return false;
		}
	}
}