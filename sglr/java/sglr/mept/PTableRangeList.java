/*
 * Created on Nov 4, 2004
 */
package sglr.mept;

import java.util.ArrayList;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTableRangeList extends ArrayList {
	public PTableRangeList() {
		super();
	}
	
	public PTableRangeList(CharRanges ranges) {
		super.ensureCapacity(ranges.getLength());
		for (int i = 0; i < ranges.getLength(); i++) {
			add(ranges.getCharRangeAt(i));
		}
	}
	
	public void add(CharRange range) {
		if (range.isRange()) {
			super.add(new PTableRange(range));
		} else {
			super.add(new PTableCharacter(range));
		}
	}
	
	public PTableCharRange fetch(int index) {
		return (PTableCharRange) super.get(index);
	}
	
	public boolean inRange(int number) {
		for (int i = 0; i < size(); i++) {
			if (fetch(i).inRange(number)) {
				return true;
			}
		}
		
		return false;
	}
}
