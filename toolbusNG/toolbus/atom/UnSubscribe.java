/*
 * Created on Jun 25, 2005
 * @author paulk
 *
 */
package toolbus.atom;

import toolbus.Environment;
import toolbus.State;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

/**
 * The unsubscribe atom
 */
public class UnSubscribe extends Atom {
	private Ref msgpat;
	
	public UnSubscribe(ATerm msgpat) {
		super();
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}
	
	public ProcessExpression copy() {
		return new UnSubscribe(msgpat.value);
	}
	
	public boolean execute() throws ToolBusException {
		if (!isEnabled())
			return false;
		System.err.println("UnSubscribe.execute");
		getProcess().unsubscribe(msgpat.value);
		return nextState();
	}
}