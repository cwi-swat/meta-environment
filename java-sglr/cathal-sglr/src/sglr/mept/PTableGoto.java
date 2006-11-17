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
 */
public class PTableGoto {
	private int stateNumber;
	private PTableRangeList ranges;
	
	public PTableGoto(GotoAction gotoAct) {
		stateNumber = gotoAct.getStateNumber();
		ranges = new PTableRangeList(gotoAct.getRanges());
	}
	
	public boolean inRange(int number) {
		return ranges.inRange(number);
	}
	
	public int getStateNumber() {
		return stateNumber;
	}
}
