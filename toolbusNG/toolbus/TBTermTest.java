package toolbus;
import aterm.ATerm;
import aterm.pure.PureFactory;

import junit.framework.*;
import junit.framework.TestCase;

public class TBTermTest extends TestCase {
  private PureFactory factory;

  public TBTermTest(String arg0) {
    super(arg0);
    factory = new PureFactory();
    TBTerm.init(factory);
  }

  public void testVars() {
    ATerm var = factory.make("var(3,int,X)");
    ATerm rvar = factory.make("rvar(3,int,Y)");
    assertTrue(TBTerm.isVar(var));
    assertTrue(TBTerm.isResVar(rvar));
  }

  public void testBooleans() {

    assertTrue(TBTerm.isBoolean(TBTerm.True));
    assertTrue(TBTerm.isBoolean(TBTerm.False));
  }

  public void testMatch() {
    Environment e1 = new Environment();
    Environment e2 = new Environment();
    MatchResult mr;

    try {
      mr = TBTerm.match(factory.make("1"), e1, factory.make("1"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("1"), e1, factory.make("2"), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("1.5"), e1, factory.make("1.5"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("1.5"), e1, factory.make("2.5"), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("\"abc\""), e1, factory.make("\"abc\""), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("\"abc\""), e1, factory.make("\"def\""), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("[1]"), e1, factory.make("[1]"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("[1,2]"), e1, factory.make("[1,2]"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("[1]"), e1, factory.make("[1,2]"), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("[1, 2]"), e1, factory.make("[1]"), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("f"), e1, factory.make("f"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("f"), e1, factory.make("g"), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("f(1)"), e1, factory.make("f(1)"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("f(1,2)"), e1, factory.make("f(1,2)"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("f(1)"), e1, factory.make("f(1,2)"), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("f(1,2)"), e1, factory.make("f(1)"), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("<int>"), e1, factory.make("1"), e2);
      assertTrue(mr.matches());
     mr = TBTerm.match(factory.make("<int>"), e1, factory.make("1.5"), e2);
      assertTrue(!mr.matches());     
      
      mr = TBTerm.match(factory.make("1"), e1, factory.make("<int>"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("1.5"), e1, factory.make("<int>"), e2);
      assertTrue(!mr.matches());
      mr = TBTerm.match(factory.make("<real>"), e1, factory.make("1.5"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("1.5"), e1, factory.make("<real>"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("\"abc\""), e1, factory.make("<str>"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("<str>"), e1, factory.make("\"abc\""), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("<term>"), e1, factory.make("f(1,2,3)"), e2);
      assertTrue(mr.matches());
      mr = TBTerm.match(factory.make("f(1,2,3)"), e1, factory.make("<term>"), e2);
      assertTrue(mr.matches());
            mr = TBTerm.match(factory.make("<list>"), e1, factory.make("[1,2,3]"), e2);
      assertTrue(mr.matches());
     mr = TBTerm.match(factory.make("[1,2,3]"), e1, factory.make("<list>"), e2);
      assertTrue(mr.matches());
            mr = TBTerm.match(factory.make("<list>"), e1, factory.make("f(1,2,3)"), e2);
      assertTrue(!mr.matches());
              mr = TBTerm.match(factory.make("f(1,2,3)"), e1, factory.make("<list>"), e2);
      assertTrue(!mr.matches());
    

    } catch (ToolBusException e) {
      fail(e.getMessage());
    }
  }

  public static Test suite() {
    return new TestSuite(TBTermTest.class);
  }

  public static void main(String args[]) {
    junit.textui.TestRunner.run(suite());
  }

}
