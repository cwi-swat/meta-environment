/*
 * Created on Jun 25, 2005
 * @author paulk
 *
 */
package toolbus.atom.note;

import java.util.Vector;

import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

/**
 * 
 *
 */
public class SndNote extends Atom {
	private Ref note;

	private Vector<ProcessInstance> notePartners = new Vector<ProcessInstance>();

	public SndNote(ATerm note, TBTermFactory tbfactory) {
		super(tbfactory);
		this.note = new Ref(note);
		setAtomArgs(this.note);
	}

	public ProcessExpression copy() {
		Atom a = new SndNote(note.value, tbfactory);
		a.copyAtomAttributes(this);
		return a;
	}

	public void addPartners(State set) throws ToolBusException {
		for (StateElement b : set.getElementsAsVector()) {
			if (!(b instanceof Subscribe)) {
				continue;
			}
			Subscribe subs = (Subscribe) b;
			if (getProcess() != subs.getProcess()
					&& tbfactory.mightMatch(this.note.value, subs
							.getMatchPattern())) {
				notePartners.add(subs.getProcess());
			}
		}
	}

	public boolean execute() throws ToolBusException {
		if (isEnabled()) {
			ATerm theNote = tbfactory.substitute(this.note.value, getEnv());

			for (ProcessInstance pi : notePartners) {
				pi.putNoteInQueue(theNote);
			}
			return true;
		} else {
			return false;
		}
	}
}
