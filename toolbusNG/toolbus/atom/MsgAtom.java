/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom;

import java.util.Stack;
import java.util.Vector;

import toolbus.*;
import toolbus.process.*;

import aterm.*;

public abstract class MsgAtom extends Atom {

	private State msgPartners = new State();  // communication partners in other processes
	
	private Ref msg;

//	private Ref id;

	private ATerm matchPattern;

	public MsgAtom(ATerm msg, TBTermFactory tbfactory) {
		super(tbfactory);
		this.msg = new Ref(msg);
//		this.id = new Ref(this instanceof RecMsg ? tbfactory.TransactionIdResVar
//				: tbfactory.TransactionIdVar);
		setAtomArgs(this.msg);
	}

//	public MsgAtom(ATerm msg, ATerm id, TBTermFactory tbfactory) {
//		super(tbfactory);
//		this.msg = new Ref(msg);
//		this.id = new Ref(id);
//		setAtomArgs(this.msg);
//	}

	public ATerm getMsg() {
		return msg.value;
	}

//	public ATerm getId() {
//		return id.value;
//	}

	public ATerm getMatchPattern() {
		return matchPattern;
	}

	abstract public boolean canCommunicate(MsgAtom a);

	public void addMsgPartner(State set) {
	    for (StateElement b : set.getElementsAsVector()) {
			if (!(b instanceof MsgAtom)) {
				continue;
			}
			MsgAtom cb = (MsgAtom) b;
			if (this.canCommunicate(cb)) {
				this.addElement(cb);
				cb.addMsgPartner(this);
				// System.err.println(" -- " + ca);
				// System.err.println(" " + cb);
			}
		}

		msgPartners.addElement(this);
	}
	
	public void delMsgPartner(StateElement a) {
		msgPartners.delElement(a);
	}

	public State getMsgPartners() {
		return msgPartners;
	}

	public boolean hasMsgPartners() {
		return msgPartners.size() > 0;
	}

	public boolean matchPartner(MsgAtom b) throws ToolBusException {
		return tbfactory.match(matchPattern, this.getEnv(), b.getMatchPattern(), b
				.getEnv());
	}

	public void compile(ProcessInstance processInstance, Stack calls,
			Environment env, State follow) throws ToolBusException {
		super.compile(processInstance, calls, env, follow);
		//matchPattern = tbfactory.makeList(getMsg(), tbfactory.makeList(getId()));
		matchPattern = getMsg();

		//System.err.println("MsgAtom.compile: " + matchPattern);
	}

	public boolean execute() throws ToolBusException {
		if (!isEnabled()) {
			return false;
		}
		Vector partnervec = msgPartners.getElementsAsVector();
		int psize = partnervec.size();
		// if(psize > 65){
		// System.err.println(this + ": " + psize + " partners");
		// }

		if (psize > 0) {
			ProcessInstance pa = getProcess();
			for (int pindex = ToolBus.nextInt(psize), pleft = psize; pleft > 0; pindex = (pindex + 1)
					% psize, pleft--) {
				MsgAtom b = (MsgAtom) partnervec.elementAt(pindex);
				ProcessInstance pb = b.getProcess();

				if (pa != pb && pb.contains(b) && b.isEnabled()) {
					// System.err.println("MsgAtom.execute: " + this + ";" + b);
					// System.err.println("--- enva = " + this.getEnv());
					// System.err.println("--- envb = " + b.getEnv());

					if (matchPartner(b)) {
						// System.err.println(
						// "--- " + pa.getProcessId() + "/" + pb.getProcessId()
						// + ": " + this +" communicates with " + b);
						// System.err.println(
						// "--- enva = " + this.getEnv());
						// System.err.println(
						// "--- envb = " + b.getEnv());
						pb.nextState(b);
						return true;
					} else {
						// System.err.println("-- " + pa.getProcessId() + " " +
						// this);
						// System.err.println(" " + pb.getProcessId() + " " +
						// b);
					}
				}
			}
		}
		return false;
	}
}
