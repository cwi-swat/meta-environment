/*
 * Created on Sep 16, 2004
 */
package test;

import junit.framework.TestCase;
import aterm.pure.*;
import sglr.gss.ParseStack;
import sglr.gss.TraversalList;
import sglr.mept.PTree;
import sglr.mept.PTreeList;
import sglr.ptable.*;

/**
 * @author Cathal Boogerd
 */
public class TraversalListTest extends TestCase {
	public void testTraversalList() {
		PTree tree1, tree2;
		PTreeList list1, list2;
		ParseStack stack1, stack2;
		
		TraversalList trav = new TraversalList();
		PureFactory factory = new PureFactory();
		Factory ptFactory = new Factory(factory);
		
		tree1 = new PTree(1, ptFactory, PTree.FORMAT_ASFIX2);
		tree2 = new PTree(2, ptFactory, PTree.FORMAT_ASFIX2);
		list1 = new PTreeList();
		list2 = new PTreeList();
		list1.addFirst(tree1);
		list2.addFirst(tree2);
		stack1 = new ParseStack(1);
		stack2 = new ParseStack(2);
		
		trav.addFirst(stack1, list1);
		trav.addLast(stack2, list2);
		
		assertEquals(2, trav.size());
		assertEquals(stack1, trav.fetchStack(0));
		assertEquals(stack2, trav.fetchStack(1));
		assertEquals(list1, trav.fetchTrees(0));
		assertEquals(list2, trav.fetchTrees(1));
	}
}
