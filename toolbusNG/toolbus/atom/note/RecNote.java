/*
 * Created on Jun 25, 2005
 * @author paulk
 *
 */
package toolbus.atom.note;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.process.ProcessExpression;
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
		if (isEnabled()
				&& getProcess().getNoteFromQueue(this.msgpat.value, getEnv())) {
			return true;
		} else {
			return false;
		}
	}
}