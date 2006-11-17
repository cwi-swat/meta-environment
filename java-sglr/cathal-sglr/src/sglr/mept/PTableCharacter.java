/*
 * Created on 20-feb-2005
 */
package sglr.mept;

import sglr.ptable.types.CharRange;

/**
 * @author Cathal Boogerd
 */
public class PTableCharacter extends PTableCharRange {
	private int single;
	
	public PTableCharacter(CharRange range) {
		if (range.isCharacter()) {
			single = range.getInteger();
		} else {
			throw new UnsupportedOperationException("CharacterRange is not of type Character");
		}
	}
	
	public PTableCharacter(int single) {
		this.single = single;
	}
	
	public boolean inRange(int number) {
		return single == number;
	}	
}
