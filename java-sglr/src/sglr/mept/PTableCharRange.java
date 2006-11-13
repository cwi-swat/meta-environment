/*
 * Created on 20-feb-2005
 */
package sglr.mept;

/**
 * @author Cathal Boogerd
 */
public abstract class PTableCharRange {
	public boolean isCharacter() {
		return false;
	}
	
	public boolean isRange() {
		return false;
	}
	
	public boolean inRange(int number) {
		return false;
	}
}
