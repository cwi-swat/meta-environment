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
    ATerm varX = factory.make("var(-1,int,X)");
    ATerm varY = factory.make("var(-1,str,Y)");

    ATerm intVal = factory.make("123");
    ATerm strVal = factory.make("abc");

    ATermList vars = factory.makeList(varY);
    vars = factory.makeList(varX, vars);

    env.introduceVars(vars);

    assertEquals(env.getVarIndex(varX), 0);
    assertEquals(env.getVarIndex(varY), 1);

    assertEquals(env.getVarType(varX), TBTerm.IntType);
    assertEquals(env.getVarType(varY), TBTerm.StrType);

    varX = TBTerm.resolveVars(varX, env);
    assertEquals(TBTerm.getVarIndex(varX), 0);

    varY = TBTerm.resolveVars(varY, env);
    assertEquals(TBTerm.getVarIndex(varY), 1);

    env.setExecuting();

    try {
      assertEquals(env.getValue(varX), null);
      assertEquals(env.getValue(varY), null);
      fail();
    } catch (ToolBusException e) {
    }

    env.assignVar(varX, intVal);
    assertEquals(env.getValue(varX), intVal);
    try {
      assertEquals(env.getValue(varY), null);
      fail();
    } catch (ToolBusException e) {
    }

    env.assignVar(varY, strVal);
    assertEquals(env.getValue(varX), intVal);
    assertEquals(env.getValue(varY), strVal);

  }

  /**
   * Declare and use variable with the same name
   */

  public void testEnv2() throws ToolBusException {
    Environment env = new Environment();
    ATerm varX1 = factory.make("var(-1,int,X)");
    ATerm varX2 = factory.make("var(-1,str,X)");

    ATermList vars = factory.makeList(varX2);
    vars = factory.makeList(varX1, vars);

    env.introduceVars(vars);

    assertEquals(env.getVarIndex(varX1), 1);
    assertEquals(env.getVarIndex(varX2), 1);

    assertEquals(env.getVarType(varX1), TBTerm.StrType);
    assertEquals(env.getVarType(varX2), TBTerm.StrType);
  }

  /**
   * Variables and bindings
   *      variable X
   *      formal Y -> actual X
   *
   */

  public void testEnv3() throws ToolBusException {
    Environment env = new Environment();
    ATerm varX = factory.make("var(-1,int,X)");
    ATerm varY = factory.make("var(-1,int,Y)");
    ATerm int3 = factory.make("3");
    ATerm int4 = factory.make("4");

    ATermList declX = factory.makeList(varX);

    env.introduceVars(declX);

    ATermList actuals = factory.makeList(varX);
    ATermList formals = factory.makeList(varY);

    env.introduceBindings(formals, actuals);

    varX = TBTerm.resolveVars(varX, env);
    assertEquals(TBTerm.getVarIndex(varX), 0);

    varY = TBTerm.resolveVars(varY, env);
    assertEquals(TBTerm.getVarIndex(varY), 1);

    env.setExecuting();

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
    ATerm varX = factory.make("var(-1,int,X)");
    ATerm varY = factory.make("var(-1,int,Y)");
    ATerm varZ = factory.make("var(-1,int,Z)");

    ATerm rvarX = factory.make("rvar(-1,int,X)");
    ATerm rvarY = factory.make("rvar(-1,int,Y)");
    ATerm rvarZ = factory.make("rvar(-1,int,Z)");

    ATermList declX = factory.makeList(varX);
    env.introduceVars(declX);

    ATermList formals1 = factory.makeList(rvarY);
    ATermList actuals1 = factory.makeList(rvarX);
    env.introduceBindings(formals1, actuals1);

    ATermList formals2 = factory.makeList(rvarZ);
    ATermList actuals2 = factory.makeList(rvarY);
    env.introduceBindings(formals2, actuals2);

    ATerm int3 = factory.make("3");
    ATerm int4 = factory.make("4");
    ATerm int5 = factory.make("5");
    ATerm int6 = factory.make("6");

    varX = TBTerm.resolveVars(varX, env);
    varY = TBTerm.resolveVars(varY, env);
    varZ = TBTerm.resolveVars(varZ, env);
    rvarX = TBTerm.resolveVars(rvarX, env);
    rvarY = TBTerm.resolveVars(rvarY, env);
    rvarZ = TBTerm.resolveVars(rvarZ, env);

    assertEquals(env.getVarIndex(varX), 0);
    assertEquals(env.getVarIndex(varY), 0);
    assertEquals(env.getVarIndex(varZ), 0);

    assertEquals(env.getVarIndex(rvarX), 0);
    assertEquals(env.getVarIndex(rvarY), 0);
    assertEquals(env.getVarIndex(rvarZ), 0);

    env.setExecuting();

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
