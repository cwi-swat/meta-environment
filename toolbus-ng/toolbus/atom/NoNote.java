/*
 * Created on Jun 25, 2005
 * @author paulk
 *
 */
package toolbus.atom;

import aterm.ATerm;
import toolbus.Environment;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;

/**
 * 
 *
 */
public class NoNote extends Atom {
	private Ref msgpat;
	
	public NoNote(ATerm msgpat, TBTermFactory tbfactory){
		super(tbfactory);
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}

	public ProcessExpression copy() {
		Atom a = new NoNote(msgpat.value, tbfactory);
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
