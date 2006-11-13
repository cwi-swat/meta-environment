/*
 * PTable.java - created at 2:16:09 PM Jul 8, 2004
 */
package sglr.mept;

import java.io.*;
import aterm.*;
import sglr.ptable.Factory;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTable {
	public static final int TOKEN_NONE = -1;
	public static final int TOKEN_EOF = 256;
	public static final int STATE_NONE = -1;
	
	private int version;
	private int initialState;
	private LabelHash labels;
	private StateHash states;
	private ParseTable pt;
	
	public PTable(ATerm trm, Factory fac) {
		pt = fac.ParseTableFromTerm(trm);
		labels = new LabelHash(pt.getLabels());
		states = new StateHash(pt.getStates());
	}
	
	public PTable(String str, Factory fac) {
		pt = fac.ParseTableFromString(str);
		labels = new LabelHash(pt.getLabels());
		states = new StateHash(pt.getStates());
	}
	
	public PTable(InputStream in, Factory fac) throws IOException {
		pt = fac.ParseTableFromFile(in);
		labels = new LabelHash(pt.getLabels());
		states = new StateHash(pt.getStates());
	}
	
	/**
	 * Returns the contents of the action table indexed by
	 * the current state number and input token.
	 * 
	 * @param number
	 * @param token
	 * @return see getActionByToken()
	 */
	public PTableChoiceList getCurrentChoices(int number, int token) {
		PTableAction act = getStateByNumber(number).getActionByToken(token);
		if (act != null) {
			return (PTableChoiceList) act.getChoices().clone();
		}
		return new PTableChoiceList();
	}
	/**
	 * Returns the next state number from the goto table indexed by
	 * the state number and goto label.
	 * @param number
	 * @param label
	 * @return state number on success, -1 if not found.
	 */
	public int getNextStateNumber(int number, int label) {
		PTableGoto gotoAction = getStateByNumber(number).getGotoByToken(label);
		if (gotoAction != null) {
			return gotoAction.getStateNumber();
		}
		
		return STATE_NONE;
	}

	public int getInitialStateNumber() {
		return pt.getInitialState();
	}
	
	public PTableLabel getLabelByNumber(int number) {
		return new PTableLabel(labels.fetch(number));
	}
	
	public String toString() {
		return pt.toString();
	}
	
	/**
	 * Returns the State object with the specified state number
	 * @param number
	 * @return State object or null if not found
	 */
	private PTableState getStateByNumber(int number) {
		return states.fetch(number);
	}
}
