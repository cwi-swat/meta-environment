/*
 * Created on 5-sep-2004
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package sglr.mept;

import sglr.ptable.types.*;

/**
 * @author Cathal
 *
 * Wrapper class for the generated ptable.types.Choice
 */
public class PTableChoice {
	private Choice act;
	
	public PTableChoice (Choice ch) {
		act = ch;
	}
	
	public boolean isLookaheadReduce() {
		return act.isLookaheadReduce();
	}
	
	public boolean isReduce() {
		return act.isReduce();
	}
	
	public boolean isShift() {
		return act.isShift();
	}
	
	public boolean isAccept() {
		return act.isAccept();
	}
	
	public int getLabel() {
		return act.getLabel();
	}
	
	public int getLength() {
		return act.getLength();
	}
	
	public int getStateNumber() {
		return act.getStateNumber();
	}
	
	public PTableLookAhead getLookaheads() {
		return new PTableLookAhead(act.getLookaheads());
	}
	
	public String toString() {
		return act.toString();
	}
}
