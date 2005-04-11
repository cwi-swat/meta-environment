/*
 * Created on Nov 4, 2004
 */
package sglr.mept;

import java.util.ArrayList;
import sglr.ptable.types.*;
/**
 * @author Cathal Boogerd
 */
public class PTableActionList extends ArrayList {
	public PTableActionList(Actions actions) {
		super.ensureCapacity(actions.getLength());
		for (int i = 0; i < actions.getLength(); i++) {
			add(actions.getActionAt(i));
		}
	}
	
	public void add(Action elem) {
		super.add(new PTableAction(elem));
	}
	
	public PTableAction fetch(int index) {
		return (PTableAction) super.get(index);
	}
}
