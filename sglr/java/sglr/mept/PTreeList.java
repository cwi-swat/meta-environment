/*
 * Created on Sep 16, 2004
 */
package sglr.mept;

import java.util.ArrayList;
import sglr.ptable.*;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTreeList extends ArrayList {
	public PTree fetch(int index) {
		return (PTree) get(index);
	}
	
	public PTree fetchFirst() {
		return fetch(0);
	}
	
	public PTree fetchLast() {
		return fetch(size() - 1);
	}
	
	public void addFirst(PTree tree) {
		super.add(0, tree);
	}
	
	public Args toArgs(Factory factory) {
		Args trees = factory.makeArgs();
		for (int i = size() - 1; i >= 0; i--) {
			trees = trees.insert(fetch(i).getTree());
		}
		
		return trees;
	}
}
