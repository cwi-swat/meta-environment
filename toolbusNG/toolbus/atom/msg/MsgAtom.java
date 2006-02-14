/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom.msg;

import java.util.Collections;
import java.util.LinkedList;
import java.util.Stack;

import toolbus.Environment;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public abstract class MsgAtom extends Atom {

	private LinkedList<MsgAtom> msgPartners = new LinkedList<MsgAtom>();
	// The communication partners in other processes

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

	// public MsgAtom(ATerm msg, ATerm id, TBTermFactory tbfactory) {
	// super(tbfactory);
	// this.msg = new Ref(msg);
	// this.id = new Ref(id);
	// setAtomArgs(this.msg);
	// }

	public ATerm getMsg() {
		return msg.value;
	}

	public ATerm getMatchPattern() {
		return matchPattern;
	}

	abstract public boolean canCommunicate(MsgAtom a);

	public void addPartners(State set) {
		// System.err.println("MsgAtom.addMsgPartner: " + set);
		for (StateElement b : set.getElementsAsVector()) {
			if (b instanceof MsgAtom) {
				MsgAtom cb = (MsgAtom) b;
				if (this.canCommunicate(cb)) {
					addMsgPartner(cb);
					cb.addMsgPartner(this);
					// System.err.println(" -- " + ca);
					// System.err.println(" " + cb);
				}
			}
		}
	}

	public void addMsgPartner(MsgAtom a) {
		msgPartners.add(a);
	}

	public void delMsgPartner(StateElement a) {
		msgPartners.remove(a);
	}

	public boolean matchesPartner(MsgAtom b) throws ToolBusException {
		return tbfactory.match(matchPattern, this.getEnv(),
				b.getMatchPattern(), b.getEnv());
	}

	public void compile(ProcessInstance processInstance, Stack<String> calls,
			Environment env, State follow) throws ToolBusException {
		super.compile(processInstance, calls, env, follow);
		// matchPattern = tbfactory.makeList(getMsg(),
		// tbfactory.makeList(getId()));
		matchPattern = getMsg();
	}

	public boolean execute() throws ToolBusException {
		if (isEnabled()) {
			Collections.rotate(msgPartners, 1);
			ProcessInstance pa = getProcess();
			for (MsgAtom b : msgPartners) {
				ProcessInstance pb = b.getProcess();

				if (pa != pb && pb.contains(b) && b.isEnabled()
						&& matchesPartner(b)) {
					pb.nextState(b);
					return true;
				}
			}
		}
		return false;
	}
}
