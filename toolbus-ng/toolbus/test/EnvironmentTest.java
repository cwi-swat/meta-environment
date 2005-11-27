package toolbus.test;

import toolbus.*;
import toolbus.TBTerm;

import aterm.*;
import aterm.ATermFactory;

import junit.framework.TestCase;

public class EnvironmentTest extends TestCase {
  private ATermFactory factory;

  public EnvironmentTest(String name) {
    super(name);
    TBTerm.init();
    factory = TBTerm.factory;
  }

  /**
   * Declare and use two different variables
   */

  public void testEnv1() throws ToolBusException {
  	Environment env = new Environment();
    ATerm varX = factory.make("var(int,X)");
    ATerm varY = factory.make("var(str,Y)");

    ATerm intVal = factory.make("123");
    ATerm strVal = factory.make("abc");

    ATermList vars = factory.makeList(varY);
    vars = factory.makeList(varX, vars);

    env.introduceVars(vars);
/*
    try {
      assertEquals(env.getValue(varX), varX);
      assertEquals(env.getValue(varY), varY);
      fail();
    } catch (ToolBusException e) {
    }
    */

    env.assignVar(varX, intVal);
    System.err.println("value = " + env.getValue(varX));
    assertEquals(env.getValue(varX), intVal);
    /*
    try {
      assertEquals(env.getValue(varY), null);
      fail();
    } catch (ToolBusException e) {
    }
    */

    env.assignVar(varY, strVal);
    assertEquals(env.getValue(varX), intVal);
    assertEquals(env.getValue(varY), strVal);

  }

  /**
   * Declare and use variable with the same name
   */

  public void testEnv2() throws ToolBusException {
    Environment env = new Environment();
    ATerm varX1 = factory.make("var(int,X)");
    ATerm varX2 = factory.make("var(str,X)");

    ATermList vars = factory.makeList(varX2);
    vars = factory.makeList(varX1, vars);

    env.introduceVars(vars);

  }

  /**
   * Variables and bindings
   *      variable X
   *      formal Y -> actual X
   *
   */

  public void testEnv3() throws ToolBusException {
    Environment env = new Environment();
    ATerm varX = factory.make("var(int,X)");
    ATerm varY = factory.make("var(int,Y)");
    ATerm int3 = factory.make("3");
    ATerm int4 = factory.make("4");

    ATermList declX = factory.makeList(varX);

    env.introduceVars(declX);

    ATermList actuals = factory.makeList(varX);
    ATermList formals = factory.makeList(varY);

    env.introduceBindings(formals, actuals, true);

    env.assignVar(varX, int3);
    env.assignVar(varY, int4);

    assertEquals(env.getValue(varX), int3);
    assertEquals(env.getValue(varY), int4);
  }

  /**
  * Result variables and bindings
  *      variable X
  *      formal Y? -> actual X?
  *      formal Z? -> actual Y?
  * 
  * (X, Y, and are thus aliases for a single variable)
  *
  */

  public void testEnv4() throws ToolBusException {
    Environment env = new Environment();
    ATerm varX = factory.make("var(int,X)");
    ATerm varY = factory.make("var(int,Y)");
    ATerm varZ = factory.make("var(int,Z)");

    ATerm rvarX = factory.make("rvar(int,X)");
    ATerm rvarY = factory.make("rvar(int,Y)");
    ATerm rvarZ = factory.make("rvar(int,Z)");

    ATermList declX = factory.makeList(varX);
    env.introduceVars(declX);

    ATermList formals1 = factory.makeList(rvarY);
    ATermList actuals1 = factory.makeList(rvarX);
    env.introduceBindings(formals1, actuals1, true);

    ATermList formals2 = factory.makeList(rvarZ);
    ATermList actuals2 = factory.makeList(rvarY);
    env.introduceBindings(formals2, actuals2, true);

    ATerm int3 = factory.make("3");
    ATerm int4 = factory.make("4");
    ATerm int5 = factory.make("5");
    ATerm int6 = factory.make("6");

    env.assignVar(varX, int3);

    assertEquals(env.getValue(varX), int3);
    assertEquals(env.getValue(varY), int3);
    assertEquals(env.getValue(varZ), int3);

    env.assignVar(varX, int4);

    assertEquals(env.getValue(varY), int4);
    assertEquals(env.getValue(varZ), int4);

    env.assignVar(rvarY, int5);
    assertEquals(env.getValue(varX), int5);
    assertEquals(env.getValue(varY), int5);
    assertEquals(env.getValue(varZ), int5);

    env.assignVar(rvarZ, int6);
    assertEquals(env.getValue(varX), int6);
    assertEquals(env.getValue(varY), int6);
    assertEquals(env.getValue(varZ), int6);
  }

}
