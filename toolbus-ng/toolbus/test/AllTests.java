package toolbus.test;

import junit.framework.*;

public class AllTests {

  public static Test suite() {
    TestSuite suite = new TestSuite();
    suite.addTestSuite(TBTermTest.class);
    suite.addTestSuite(EnvironmentTest.class);
    suite.addTestSuite(TscriptTest.class);
    return suite;
  }

  public static void main(String args[]) {
    junit.textui.TestRunner.run(suite());
 
  }

}
