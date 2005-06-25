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
public class Subscribe extends Atom {
	private Ref msgpat;
	
	public Subscribe(ATerm msgpat) {
		super();
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}
	
	public ProcessExpression copy() {
		return new Subscribe(msgpat.value);
	}
	
	public boolean execute() throws ToolBusException {
		if (!isEnabled())
			return false;
		System.err.println("Subscribe.execute");
		getProcess().subscribe(msgpat.value);
		return nextState();
	}
}