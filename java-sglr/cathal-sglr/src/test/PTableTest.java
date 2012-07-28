/*
 * Created on Sep 10, 2004
 */
package test;

import java.io.*;
import junit.framework.TestCase;

import aterm.pure.*;
import sglr.mept.PTable;
import sglr.ptable.*;

/**
 * @author Cathal Boogerd
 */
public class PTableTest extends TestCase {
	private PTable pt;
	private PureFactory factory;
	private Factory ptableFactory;
	
	public PTableTest(String name) throws IOException, FileNotFoundException {
		super(name);
		factory = new PureFactory();
		Factory ptableFactory = new Factory(factory); 
		pt = new PTable(new FileInputStream("test-data/Booleans.tbl"), ptableFactory);
	}

	public void testGetInitialNumber() {
		assertEquals("getStateByNumber", 0, pt.getInitialStateNumber());
	}

	public void testGetNextStateNumber() {
		int state, label;
		state = 4;
		label = 80;
		
		assertEquals("getNextStateNumber", 25, pt.getNextStateNumber(state, label));
	}
	/*
	public void testGetCurrentAction() {
		PTableActionList actions = new PTableActionList();
		actions.add(new PTableAction(ptableFactory.makeChoice_Shift(8)));
		assertEquals("getCurrentAction()", actions, pt.getCurrentActions(0, 32));
		
		actions = new PTableActionList();
		actions.add(new PTableAction(ptableFactory.makeChoice_Reduce(1, 295, ptableFactory.makeSpecialAttr_None())));
		assertEquals("getCurrentAction()", actions, pt.getCurrentActions(8, 256));
		
		actions = new PTableActionList();
		actions.add(new PTableAction(ptableFactory.makeChoice_Shift(8)));
		actions.add(new PTableAction(ptableFactory.makeChoice_Reduce(5, 292, ptableFactory.makeSpecialAttr_None())));
		assertEquals("getCurrentAction()", actions, pt.getCurrentActions(64, 10));
	}*/
}
