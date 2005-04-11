/*
 * Created on Nov 10, 2004
 */
package sglr.mept;

import java.util.ArrayList;
import sglr.ptable.*;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTreeLeafs extends ArrayList {
	private Factory factory;
	
	public PTreeLeafs(Factory fac) {
		factory = fac;
	}
	
	public PTreeLeafs(Args trees, Factory fac) {
		factory = fac;
		super.ensureCapacity(trees.getLength());
		for (int i = 0; i < trees.getLength(); i++) {
			super.add(trees.getTreeAt(i));
		}
	}
	
	public Args toArgs() {
		Args trees = factory.makeArgs();
		for (int i = size() - 1; i >= 0; i--) {
			trees = trees.insert(fetch(i));
		}
		
		return trees;
	}
	
	public Tree fetch(int index) {
		return (Tree) super.get(index);
	}
	
	public void add(PTree tree) {
		super.add(tree.getTree());
	}
	
	public void append(Args trees) {
		ensureCapacity(size() + trees.getLength());
		while (trees.hasHead()) {
			add(trees.getHead());
			trees = trees.getTail();
		}
	}
	
	public void append(PTreeLeafs list) {
		ensureCapacity(size() + list.size());
		addAll(list);
	}
}
