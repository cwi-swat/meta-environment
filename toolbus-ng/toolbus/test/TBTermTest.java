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
    ATerm var = factory.make("var(3,int,X)");
    ATerm rvar = factory.make("rvar(3,int,Y)");
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
    MatchResult mr;
    try {
      mr = TBTerm.match(factory.make(s1), e1, factory.make(s2), e2);
      return mr.matches();
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

  public ATerm check(String s) throws ToolBusException {
    Environment e = new Environment();
    return FunctionDescriptors.checkType(factory.make(s), e);
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
    return TBTerm.assignCompatible(factory.make(s1), factory.make(s2));
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
    assertTrue(!compatible("f(int)", "f()"));

    assertTrue(compatible("[]", "[]"));
    assertTrue(compatible("[int]", "[int]"));
    assertTrue(!compatible("[int]", "[]"));
    assertTrue(!compatible("[int,int]", "[int]"));
    assertTrue(!compatible("[int]", "[int,int]"));

    assertTrue(compatible("list", "[int,int]"));
    assertTrue(!compatible("list", "int"));

    assertTrue(compatible("list(int)", "[int, int, int]"));
    assertTrue(!compatible("list(int)", "[int, real, int]"));
  }

  public static Test suite() {
    return new TestSuite(TBTermTest.class);
  }

  public static void main(String args[]) {
    junit.textui.TestRunner.run(suite());
  }

}
