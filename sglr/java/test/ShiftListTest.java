/*
 * Created on Sep 16, 2004
 */
package test;

import junit.framework.TestCase;
import sglr.gss.ParseStack;
import sglr.gss.ShiftList;

/**
 * @author Cathal Boogerd
 */
public class ShiftListTest extends TestCase {
	public void testShiftList() {
		ParseStack stack1, stack2;
		int target1, target2;
		ShiftList list = new ShiftList();
		
		stack1 = new ParseStack(1);
		stack2 = new ParseStack(2);
		target1 = 1;
		target2 = 2;
		list.addFirst(stack1, target1);
		list.addLast(stack2, target2);
		
		assertEquals(2, list.size());
		assertEquals(stack1, list.getStackAt(0));
		assertEquals(stack2, list.getStackAt(1));
		assertEquals(target1, list.getShiftTargetAt(0));
		assertEquals(target2, list.getShiftTargetAt(1));
	}
}
