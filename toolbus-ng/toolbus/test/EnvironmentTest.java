package toolbus.test;

import junit.framework.TestCase;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import aterm.ATerm;
import aterm.ATermList;

public class EnvironmentTest extends TestCase {
  private TBTermFactory tbfactory;

  public EnvironmentTest(String name) {
    super(name);
  
    tbfactory = TBTermFactory.getInstance();
  }

  /**
   * Declare and use two different variables
   */

  public void testEnv1() throws ToolBusException {
  	Environment env = new Environment(tbfactory);
    ATerm intType = tbfactory.make("int");
    ATerm strType = tbfactory.make("str");
    TBTermVar varX = tbfactory.makeTBTermVar("X", intType);
    TBTermVar varY = tbfactory.makeTBTermVar("Y", strType);

    ATerm intVal = tbfactory.make("123");
    ATerm strVal = tbfactory.make("abc");

    ATermList vars = tbfactory.makeList(varY);
    vars = tbfactory.makeList(varX, vars);

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
    Environment env = new Environment(tbfactory);
    
    ATerm intType = tbfactory.make("int");
    ATerm strType = tbfactory.make("str");
    TBTermVar varX1 = tbfactory.makeTBTermVar("X", intType);
    TBTermVar varX2 = tbfactory.makeTBTermVar("X", strType);

    ATermList vars = tbfactory.makeList(varX2);
    vars = tbfactory.makeList(varX1, vars);

    env.introduceVars(vars);

  }

  /**
   * Variables and bindings
   *      variable X
   *      formal Y -> actual X
   *
   */

  public void testEnv3() throws ToolBusException {
    Environment env = new Environment(tbfactory);
    ATerm intType = tbfactory.make("int");
    ATerm strType = tbfactory.make("str");
    
    TBTermVar varX = tbfactory.makeTBTermVar("X", intType);
    TBTermVar varY = tbfactory.makeTBTermVar("Y", intType); 
    
    ATerm int3 = tbfactory.make("3");
    ATerm int4 = tbfactory.make("4");

    ATermList declX = tbfactory.makeList(varX);

    env.introduceVars(declX);

    ATermList actuals = tbfactory.makeList(varX);
    ATermList formals = tbfactory.makeList(varY);

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
    Environment env = new Environment(tbfactory);
    
    ATerm intType = tbfactory.make("int");
    ATerm strType = tbfactory.make("str");
    
    TBTermVar varX = tbfactory.makeTBTermVar("X", intType);
    TBTermVar varY = tbfactory.makeTBTermVar("Y", intType);  
    TBTermVar varZ = tbfactory.makeTBTermVar("Z", intType);  
    
    assertTrue(tbfactory.isVar(varX));
    
    TBTermVar rvarX = tbfactory.makeTBTermResVar("X", intType);
    TBTermVar rvarY = tbfactory.makeTBTermResVar("Y", intType);  
    TBTermVar rvarZ = tbfactory.makeTBTermResVar("Z", intType);  
    
    assertTrue(tbfactory.isResultVar(rvarX));

    ATermList declX = tbfactory.makeList(varX);
    env.introduceVars(declX);
    System.err.println("env = " + env);

    ATermList formals1 = tbfactory.makeList(rvarY);
    ATermList actuals1 = tbfactory.makeList(rvarX);
    env.introduceBindings(formals1, actuals1, true);
    System.err.println("env = " + env);

    ATermList formals2 = tbfactory.makeList(rvarZ);
    ATermList actuals2 = tbfactory.makeList(rvarY);
    env.introduceBindings(formals2, actuals2, true);
    System.err.println("env = " + env);

    ATerm int3 = tbfactory.make("3");
    ATerm int4 = tbfactory.make("4");
    ATerm int5 = tbfactory.make("5");
    ATerm int6 = tbfactory.make("6");

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
