/*
 * Created on Jun 25, 2005
 * @author paulk
 *
 */
package toolbus.atom;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * The unsubscribe atom
 */
public class UnSubscribe extends Atom {
	private Ref msgpat;
	
	public UnSubscribe(ATerm msgpat, TBTermFactory tbfactory) {
		super(tbfactory);
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}
	
	public ProcessExpression copy() {
		Atom a = new UnSubscribe(msgpat.value, tbfactory);
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean execute() throws ToolBusException {
		if (!isEnabled())
			return false;
		System.err.println("UnSubscribe.execute");
		getProcess().unsubscribe(msgpat.value);
		return true;
	}
}