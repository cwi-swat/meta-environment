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
  
  public static Test suite(){
    return new TestSuite(TBTermTest.class);
  }
  
  public static void main(String args[]){
    junit.textui.TestRunner.run(suite());
  }

}
