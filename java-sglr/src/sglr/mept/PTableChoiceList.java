/*
 * Created on Sep 15, 2004
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package sglr.mept;

import java.util.ArrayList;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class PTableChoiceList extends ArrayList {
	public PTableChoiceList() {
		super();
	}
	
	public PTableChoiceList(PTableChoice act) {
		super();
		add(act);
	}
	
	public PTableChoiceList(Choices chs) {
		super();
		super.ensureCapacity(chs.getLength());
		for (int i = 0; i < chs.getLength(); i++) {
			add(new PTableChoice(chs.getChoiceAt(i)));
		}
	}
	
	public PTableChoice fetch(int index) {
		return (PTableChoice) get(index);
	}
	
	public PTableChoice fetchFirst() {
		return fetch(0);
	}
	
	public PTableChoice fetchLast() {
		return fetch(size() - 1);
	}
	
	public PTableChoice pop() {
		return (PTableChoice) super.remove(0);
	}
}
