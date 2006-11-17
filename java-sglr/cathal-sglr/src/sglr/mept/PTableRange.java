/*
 * Created on Nov 4, 2004
 */
package sglr.mept;

import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTableRange extends PTableCharRange {
	private int from;
	private int to;
	
	public PTableRange(CharRange range) {
		if (range.isRange()) {
			from = range.getStart();
			to = range.getEnd();
		} else {
			throw new UnsupportedOperationException("CharacterRange is not of type Range");
		}
	}
	
	public PTableRange(int start, int end) {
		from = start;
		to = end;
	}
	
	public boolean inRange(int number) {
		return (from <= number && number <= to);
	}
	
	public boolean isRange() {
		return true;
	}
}
