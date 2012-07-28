/*
 * Created on Sep 15, 2004
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package sglr.gss;

import java.util.ArrayList;

/**
 * @author duq
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class ShiftList extends ArrayList {
	public void add(int index, ParseStack st, int shiftTarget) {
		add(index * 2, st);
		add(index * 2 + 1, new Integer(shiftTarget));
	}
	
	public void addFirst(ParseStack st, int shiftTarget) {
		add(0, st, shiftTarget);
	}
	
	public void addLast(ParseStack st, int shiftTarget) {
		add(size(), st, shiftTarget);
	}
	
	public ParseStack getStackAt(int index) {
		return (ParseStack) get(2 * index);
	}
	
	public int getShiftTargetAt(int index) {
		return ((Integer) get(2* index + 1)).intValue();
	}
	
	public int size() {
		return super.size()/2;
	}
}
