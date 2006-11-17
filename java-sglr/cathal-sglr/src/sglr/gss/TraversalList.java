/*
 * Created on Sep 15, 2004
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package sglr.gss;

import java.util.ArrayList;

import sglr.mept.PTreeList;

/**
 * @author duq
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class TraversalList extends ArrayList {
	public void add(int index, ParseStack st, PTreeList trees) {
		super.add(index * 2, st);
		super.add(index * 2 + 1, trees);
	}
	
	public void addFirst(ParseStack st, PTreeList trees) {
		add(0, st, trees);
	}
	
	public void addLast(ParseStack st, PTreeList trees) {
		add(size(), st, trees);
	}
	
	public void append(TraversalList trav) {
		for (int i = 0; i < trav.size(); i++) {
			addLast(trav.fetchStack(i), trav.fetchTrees(i));
		}
	}
	
	public ParseStack fetchStack(int index) {
		return (ParseStack) get(index * 2);
	}
	
	public PTreeList fetchTrees(int index) {
		return (PTreeList) get(index * 2 + 1);
	}

	public int size() {
		return super.size()/2;
	}
}
