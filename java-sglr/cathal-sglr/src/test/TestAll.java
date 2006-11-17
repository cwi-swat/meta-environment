/*
 * Created on Sep 10, 2004
 */
package test;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * @author Cathal Boogerd
 */
public class TestAll extends TestCase {
	public TestAll(String test) {
    	super(test);
	}

    public static Test suite() {
    	TestSuite suite = new TestSuite();
    	suite.addTest(new TestSuite(PTableTest.class));
    	//suite.addTest(new TestSuite(ParserCoreTest.class));
    	suite.addTest(new TestSuite(ParseLinkTest.class));
    	suite.addTest(new TestSuite(ShiftListTest.class));
    	suite.addTest(new TestSuite(TraversalListTest.class));
    	suite.addTest(new TestSuite(LabelHashTest.class));

    	return suite;
    }
    
    public static void main(String argv[]) {
    	junit.textui.TestRunner.run(suite());
    }
}
