/*
 * Created on Nov 24, 2004
 */
package sglr.mept;

import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTableLookAhead {
	private PTableRangeList looks;
	
	public PTableLookAhead(LookAheads las) {
		looks = new PTableRangeList();
		PTableRangeList tmp;
		
		for (int i = 0; i < las.getLength(); i++) {
			tmp = new PTableRangeList(las.getLookAheadAt(i).getCharClass().getRanges());
			looks.addAll(tmp);
		}
	}
	
	public boolean inRange(int number) {
		return looks.inRange(number);
	}
	
	public boolean inRange(int index, int number) {
		return looks.fetch(index).inRange(number);
	}
	
	public int size() {
		return looks.size();
	}
}
