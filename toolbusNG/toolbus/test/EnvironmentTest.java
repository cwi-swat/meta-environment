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
  
  
//  public void testEnv3() throws ToolBusException {
//    Environment env = new Environment();
//    ATerm varX = factory.make("var(-1,int,X)");
//    ATerm varX2 = factory.make("rvar(-1,str,Y)");
//
//    ATermList vars = factory.makeList(varX2);
//    vars = factory.makeList(varX1, vars);
//    
    
    
    
    
    

}
