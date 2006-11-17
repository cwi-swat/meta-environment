/*
 * Created on Nov 4, 2004
 */
package sglr.mept;

import java.util.ArrayList;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTableGotoList extends ArrayList {
	public PTableGotoList(Gotos gotoList) {
		super.ensureCapacity(gotoList.getLength());
		for (int i = 0; i < gotoList.getLength(); i++) {
			add(gotoList.getGotoActionAt(i));
		}
	}
	
	public void add(GotoAction elem) {
		super.add(new PTableGoto(elem));
	}
	
	public PTableGoto fetch(int index) {
		return (PTableGoto) super.get(index);
	}
}
