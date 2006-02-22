/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom.msg;

import java.util.Stack;

import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public abstract class MsgAtom extends Atom {

	private Ref msg;

	// private Ref id;

	private ATerm matchPattern;

	public MsgAtom(ATerm msg, TBTermFactory tbfactory) {
		super(tbfactory);
		this.msg = new Ref(msg);
		// this.id = new Ref(this instanceof RecMsg ?
		// tbfactory.TransactionIdResVar
		// : tbfactory.TransactionIdVar);
		setAtomArgs(this.msg);
	}

	public ATerm getMsg() {
		return msg.value;
	}

	public ATerm getMatchPattern() {
		return matchPattern;
	}

//	abstract public boolean canCommunicate(MsgAtom a) throws ToolBusException;
	
	public void addPartners(State set) throws ToolBusException {
	}

	public boolean matchesPartner(MsgAtom b) throws ToolBusException {
		return tbfactory.match(matchPattern, this.getEnv(),
				b.getMatchPattern(), b.getEnv());
	}

	public void compile(ProcessInstance processInstance, Stack<String> calls,
			State follow) throws ToolBusException {
		super.compile(processInstance, calls, follow);
		// matchPattern = tbfactory.makeList(getMsg(),
		// tbfactory.makeList(getId()));
		matchPattern = getMsg();
	}

	abstract public boolean execute() throws ToolBusException;
}
