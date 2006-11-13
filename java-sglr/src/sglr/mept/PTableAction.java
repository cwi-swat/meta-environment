/*
 * Created on Nov 4, 2004
 */
package sglr.mept;

import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTableAction {
	private PTableRangeList ranges;
	private PTableChoiceList choices;
	
	public PTableAction(Action action) {
		choices = new PTableChoiceList(action.getChoices());
		ranges = new PTableRangeList(action.getRanges());
	}
	
	public boolean inRange(int number) {
		return ranges.inRange(number);
	}
	
	public PTableChoiceList getChoices() {
		return choices;
	}
}
