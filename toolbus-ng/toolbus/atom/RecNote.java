/*
 * Created on Jun 25, 2005
 * @author paulk
 *
 */
package toolbus.atom;

import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * 
 *
 */
public class RecNote extends Atom {
	private Ref msgpat;
	
	public RecNote(ATerm msgpat) {
		super();
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}
	
	public ProcessExpression copy() {
		Atom a = new RecNote(msgpat.value);
		a.copyAtomAttributes(this);
	    return a;
	}
	
	public boolean execute() throws ToolBusException {
		if (!isEnabled())
			return false;
		if (getProcess().getNoteFromQueue(this.msgpat.value, getEnv()))
			return true;
		else
			return false;
	}
}