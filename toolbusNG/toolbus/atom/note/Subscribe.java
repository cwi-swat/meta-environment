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
public class Subscribe extends Atom {
	private Ref msgpat;
	
	public Subscribe(ATerm msgpat, TBTermFactory tbfactory, ATerm posInfo) {
		super(tbfactory, posInfo);
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}
	
	public ProcessExpression copy() {
		Atom a = new Subscribe(msgpat.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public ATerm getMatchPattern(){
		return msgpat.value;
	}
	
	public boolean execute() throws ToolBusException {
		if (!isEnabled())
			return false;
		getProcess().subscribe(msgpat.value);
		return true;
	}
}