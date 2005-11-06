package toolbus.test;
import toolbus.*;

import aterm.*;
import aterm.ATerm;

import junit.framework.*;
import junit.framework.TestCase;

public class TBTermTest extends TestCase {
  private ATermFactory factory;

  public TBTermTest(String arg0) {
    super(arg0);
    TBTerm.init();
    factory = TBTerm.factory;
  }

  public void testVars() {
    ATerm var = factory.make("var(int,X)");
    ATerm rvar = factory.make("rvar(int,Y)");
    assertTrue(TBTerm.isVar(var));
    assertTrue(TBTerm.isResVar(rvar));
  }

  public void testBooleans() {
    assertTrue(TBTerm.isBoolean(TBTerm.True));
    assertTrue(TBTerm.isBoolean(TBTerm.False));
  }

  public void testConstants() {
    assertEquals(TBTerm.True.getFactory(), factory);
    assertEquals(TBTerm.True, factory.make("true"));
    assertEquals(TBTerm.False, factory.make("false"));
    assertEquals(TBTerm.BoolType, factory.make("bool"));
    assertEquals(TBTerm.IntType, factory.make("int"));
    assertEquals(TBTerm.RealType, factory.make("real"));
    assertEquals(TBTerm.StrType, factory.make("str"));
    assertEquals(TBTerm.TermType, factory.make("term"));
    assertEquals(TBTerm.ListType, factory.make("list"));

    assertEquals(TBTerm.VoidType, factory.make("void"));

    assertEquals(TBTerm.BoolPlaceholder, factory.makePlaceholder(TBTerm.BoolType));
    assertEquals(TBTerm.IntPlaceholder, factory.makePlaceholder(TBTerm.IntType));
    assertEquals(TBTerm.RealPlaceholder, factory.makePlaceholder(TBTerm.RealType));

    assertEquals(TBTerm.StrPlaceholder, factory.makePlaceholder(TBTerm.StrType));
    assertEquals(TBTerm.TermPlaceholder, factory.makePlaceholder(TBTerm.TermType));
    assertEquals(TBTerm.ListPlaceholder, factory.makePlaceholder(TBTerm.ListType));
  }

  boolean doMatch(String s1, String s2) {
    Environment e1 = new Environment();
    Environment e2 = new Environment();
    try {
      return TBTerm.match(factory.make(s1), e1, factory.make(s2), e2);
    } catch (ToolBusException e) {
      fail(e.getMessage());
    }
    return false;
  }

  public void testMatch() {

    assertTrue(doMatch("1", "1"));
    assertTrue(!doMatch("1", "2"));

    assertTrue(doMatch("1.5", "1.5"));
    assertTrue(!doMatch("1.5", "2.5"));

    assertTrue(doMatch("\"\"", "\"\""));
    assertTrue(doMatch("\"abc\"", "\"abc\""));
    assertTrue(!doMatch("\"\"", "\"def\""));
    assertTrue(!doMatch("\"abc\"", "\"\""));
    assertTrue(!doMatch("\"abc\"", "\"def\""));

    assertTrue(doMatch("[]", "[]"));
    assertTrue(doMatch("[1]", "[1]"));
    assertTrue(doMatch("[1, 2]", "[1, 2]"));
    assertTrue(!doMatch("[]", "[1, 2]"));
    assertTrue(!doMatch("[1, 2]", "[]"));
    assertTrue(!doMatch("[1]", "[1, 2]"));
    assertTrue(!doMatch("[1, 2]", "[1]"));

    assertTrue(doMatch("f", "f"));
    assertTrue(!doMatch("f", "g"));
    assertTrue(doMatch("f(1)", "f(1)"));
    assertTrue(doMatch("f(1,2)", "f(1,2)"));
    assertTrue(!doMatch("f(1)", "f(1,2)"));
    assertTrue(!doMatch("f(1,2)", "f(1)"));

    assertTrue(doMatch("<int>", "1"));
    assertTrue(doMatch("1", "<int>"));
    assertTrue(!doMatch("<int>", "1.5"));
    assertTrue(!doMatch("1.5", "<int>"));
    assertTrue(!doMatch("1.5", "<int>"));

    assertTrue(doMatch("<real>", "1.5"));
    assertTrue(doMatch("1.5", "<real>"));

    assertTrue(doMatch("<str>", "\"abc\""));
    assertTrue(doMatch("\"abc\"", "<str>"));

    assertTrue(doMatch("<term>", "f(1,2,3)"));
    assertTrue(doMatch("f(1,2,3)", "<term>"));

    assertTrue(doMatch("<list>", "[1,2,3]"));
    assertTrue(doMatch("[1,2,3]", "<list>"));

    assertTrue(!doMatch("<list>", "f(1,2,3)"));
    assertTrue(!doMatch("f(1,2,3)", "<list>"));

  }
  
  boolean doMatch(String s1, Environment e1, String s2, Environment e2) {
    try {
      return TBTerm.match(factory.make(s1), e1, factory.make(s2), e2);
    } catch (ToolBusException e) {
      fail(e.getMessage());
    }
    return false;
  }
  
  public void testMatchVar() throws ToolBusException {
  	Environment env1 = new Environment();
  	Environment env2 = new Environment();
  	
    ATerm varX = factory.make("var(int,X)");
    ATerm varY = factory.make("var(int,Y)");
    ATerm int3 = factory.make("3");
    ATerm int4 = factory.make("4");
    ATerm int5 = factory.make("5");
    ATerm int6 = factory.make("6");
    
    ATermList declX = factory.makeList(varX);
    env1.introduceVars(declX);
    env1.assignVar(varX, int3);
    
    ATermList declY = factory.makeList(varY);
    env2.introduceVars(declY);
    env2.assignVar(varY, int4);
    
    assertTrue(doMatch("var(int,X)", env1, "3", env2));
    assertTrue(!doMatch("var(int,X)", env1, "4", env2));
    assertTrue(doMatch("4", env1, "var(int,Y)", env2));
    assertTrue(!doMatch("3", env1, "var(int,Y)", env2));
    
    assertTrue(doMatch("f(var(int,X))", env1, "f(3)", env2));
    assertTrue(!doMatch("f(var(int,X))", env1, "f(4)", env2));
    assertTrue(doMatch("f(4)", env1, "f(var(int,Y))", env2));
    assertTrue(!doMatch("f(3)", env1, "f(var(int,Y))", env2));
    
    assertTrue(doMatch("rvar(int,X)", env1, "5", env2)); 
    assertEquals(env1.getValue(varX), int5);
    assertTrue(doMatch("var(int,X)", env1, "5", env2)); 
    
    assertTrue(doMatch("6", env1, "rvar(int,Y)", env2)); 
    assertEquals(env2.getValue(varY), int6);
    assertTrue(doMatch("6", env1, "var(int,Y)", env2));  
  }

  public ATerm check(String s) throws ToolBusException {
    Environment e = new Environment();
    return Functions.checkType(factory.make(s), e, false);
  }

  public void testStaticCheck() throws ToolBusException {
    assertEquals(check("1"), TBTerm.IntType);
    assertEquals(check("1.5"), TBTerm.RealType);
    assertEquals(check("\"abc\""), TBTerm.StrType);
    assertEquals(check("true"), TBTerm.BoolType);
    assertEquals(check("false"), TBTerm.BoolType);

    assertEquals(check("add(1,2)"), TBTerm.IntType);
    assertEquals(check("greater(1,2)"), TBTerm.BoolType);
  }

  public boolean compatible(String s1, String s2) throws ToolBusException {
    return Functions.compatibleTypes(factory.make(s1), factory.make(s2));
  }

  public void testCompatible() throws ToolBusException {
    assertTrue(compatible("int", "int"));
    assertTrue(!compatible("int", "real"));

    assertTrue(compatible("term", "int"));
    assertTrue(compatible("int", "term"));

    assertTrue(compatible("f", "f"));
    assertTrue(!compatible("f", "g"));
    assertTrue(compatible("f(int)", "f(int)"));
    assertTrue(compatible("f", "f(int)"));
    assertTrue(compatible("f(int)", "f()"));

    assertTrue(compatible("[]", "[]"));
    assertTrue(compatible("[int]", "[int]"));
    assertTrue(!compatible("[int]", "[]"));
    assertTrue(!compatible("[int,int]", "[int]"));
    assertTrue(!compatible("[int]", "[int,int]"));

    assertTrue(compatible("list", "[int,int]"));
    assertTrue(!compatible("list", "int"));

    assertTrue(compatible("list(int)", "[int, int, int]"));
    assertTrue(!compatible("list(int)", "[int, real, int]"));
 
    assertTrue(compatible("<int>", "13"));
    assertTrue(compatible("f(<int>)", "f(13)"));
    assertTrue(compatible("f(<int>,14)", "f(13,<int>)"));
    assertTrue(compatible("[<int>,14]", "[13,<int>]"));
    
    assertTrue(compatible("13", "<int>"));
    assertTrue(compatible( "f(13)", "f(<int>)"));
    assertTrue(compatible("f(13,<int>)", "f(<int>,14)"));
    assertTrue(compatible("[13,<int>]", "[<int>,14]"));
    
    assertTrue(compatible("<real>", "13.5"));
    assertTrue(compatible("f(<real>)", "f(13.5)"));
    assertTrue(compatible("f(<real>,14.5)", "f(13.5,<real>)"));
    assertTrue(compatible("[<real>,14.5]", "[1.5,<real>]"));
    
    assertTrue(compatible("13.5", "<real>"));
    assertTrue(compatible("f(13.5)", "f(<real>)"));
    assertTrue(compatible("f(13.5,<real>)", "f(<real>,14.5)"));
    assertTrue(compatible("[1.5,<real>]", "[<real>,14.5]"));
    
    assertTrue(compatible("<str>", "\"abc\""));
    assertTrue(!compatible("<str>", "f(1)"));
    assertTrue(!compatible("<str>", "f"));
    
    assertTrue(compatible("\"abc\"", "<str>"));
    assertTrue(!compatible("f(1)", "<str>"));
    assertTrue(!compatible("f", "<str>"));
    
  }
  
  public static Test suite() {
    return new TestSuite(TBTermTest.class);
  }

  public static void main(String args[]) {
    junit.textui.TestRunner.run(suite());
  }

}
