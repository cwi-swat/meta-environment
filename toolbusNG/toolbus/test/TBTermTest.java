package toolbus.test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import toolbus.Functions;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import aterm.ATerm;
import aterm.ATermBlob;
import aterm.ATermList;

public class TBTermTest extends TestCase {
  private TBTermFactory tbfactory;

  public TBTermTest(String arg0) {
    super(arg0);
    tbfactory = TBTermFactory.getInstance();
  }

  public void testVars() {
	TBTermVar var = tbfactory.makeTBTermVar("X", tbfactory.make("int"));
    TBTermVar rvar = tbfactory.makeTBTermResVar("X", tbfactory.make("int"));
    assertTrue(tbfactory.isVar(var));
    assertTrue(!tbfactory.isResultVar(var));
    
    assertTrue(tbfactory.isResultVar(rvar));
    assertTrue(!tbfactory.isVar(rvar));
  }

  public void testBooleans() {
    assertTrue(tbfactory.isBoolean(tbfactory.True));
    assertTrue(tbfactory.isBoolean(tbfactory.False));
  }

  public void testConstants() {
    assertEquals(tbfactory.True, tbfactory.make("true"));
    assertEquals(tbfactory.False, tbfactory.make("false"));
    assertEquals(tbfactory.BoolType, tbfactory.make("bool"));
    assertEquals(tbfactory.IntType, tbfactory.make("int"));
    assertEquals(tbfactory.RealType, tbfactory.make("real"));
    assertEquals(tbfactory.StrType, tbfactory.make("str"));
    assertEquals(tbfactory.TermType, tbfactory.make("term"));
    assertEquals(tbfactory.ListType, tbfactory.make("list"));

    assertEquals(tbfactory.VoidType, tbfactory.make("void"));

    assertEquals(tbfactory.BoolPlaceholder, tbfactory.makePlaceholder(tbfactory.BoolType));
    assertEquals(tbfactory.IntPlaceholder, tbfactory.makePlaceholder(tbfactory.IntType));
    assertEquals(tbfactory.RealPlaceholder, tbfactory.makePlaceholder(tbfactory.RealType));

    assertEquals(tbfactory.StrPlaceholder, tbfactory.makePlaceholder(tbfactory.StrType));
    assertEquals(tbfactory.TermPlaceholder, tbfactory.makePlaceholder(tbfactory.TermType));
    assertEquals(tbfactory.ListPlaceholder, tbfactory.makePlaceholder(tbfactory.ListType));
    assertEquals(tbfactory.IntPlaceholder, tbfactory.make("<int>"));
   
  }

  boolean doMatch(String s1, String s2) {
    Environment e1 = new Environment(tbfactory);
    Environment e2 = new Environment(tbfactory);
    try {
      return tbfactory.match(tbfactory.make(s1), e1, tbfactory.make(s2), e2);
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
    
    assertTrue(!doMatch("f", "[1,2,3]"));
    assertTrue(!doMatch("[1,2,3]", "f"));

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
    
    assertTrue(doMatch("<list(int)>", "[1,2,3]"));
    assertTrue(doMatch("[1,2,3]", "<list(int)>"));
    
    assertTrue(!doMatch("<list(int)>", "[1.0,2.0,3.0]"));
    assertTrue(!doMatch("[1.0,2.0,3.0]", "<list(int)>"));
    
    assertTrue(doMatch("<list(int,str,real)>", "[1,\"two\",3.0]"));
    assertTrue(doMatch("[1,\"two\",3.0]", "<list(int,str,real)>"));
    
    assertTrue(!doMatch("<list(int,str,real)>", "[1,\"two\"]"));
    assertTrue(!doMatch("[1,\"two\"]", "<list(int,str,real)>"));
    
    assertTrue(!doMatch("<list(int,str,real)>", "[1,\"two\",3]"));
    assertTrue(!doMatch("[1,\"two\",3]", "<list(int,str,real)>"));
    
    assertTrue(doMatch("<list>", "[1,\"two\",3]"));
    assertTrue(doMatch("[1,\"two\",3]", "<list>"));
 
    assertTrue(!doMatch("<list>", "two"));
    assertTrue(!doMatch("one", "<list>"));
    
    assertTrue(!doMatch("<list>", "\"two\""));
    assertTrue(!doMatch("\"two\"", "<list>"));
  }
  
  boolean doMatch(String s1, Environment e1, String s2, Environment e2) {
    try {
      return tbfactory.match(tbfactory.make(s1), e1, tbfactory.make(s2), e2);
    } catch (ToolBusException e) {
      fail(e.getMessage());
    }
    return false;
  }
  boolean doMatch(ATerm t1, Environment e1, ATerm t2, Environment e2) {
	    try {
	      return tbfactory.match(t1, e1, t2, e2);
	    } catch (ToolBusException e) {
	      fail(e.getMessage());
	    }
	    return false;
	  }
  
  boolean doSubst(String s1, Environment e, String s2) throws ToolBusException{
  	return tbfactory.substitute(tbfactory.make(s1), e).isEqual(tbfactory.make(s2));
  }
  
  boolean doSubst(ATerm t1, Environment e, ATerm t2) throws ToolBusException{
	  	return tbfactory.substitute(t1, e).isEqual(t2);
	  }
  
  public void testSubstitute() throws ToolBusException {
 	Environment env1 = new Environment(tbfactory);
    TBTermVar varX = tbfactory.makeTBTermVar("X", tbfactory.make("int"));	
    TBTermVar rvarX = tbfactory.makeTBTermResVar("X", tbfactory.make("int"));	
    ATerm int3 = tbfactory.make("3");
    ATermList declX = tbfactory.makeList(varX);
    env1.introduceVars(declX);
    env1.assignVar(varX, int3);
    
    ATerm f3 = tbfactory.make("f(3)");
    ATerm fvarX = tbfactory.make("f(<term>)", varX);
    ATerm frvarX = tbfactory.make("f(<term>)", rvarX);
    
    assertTrue(doSubst("1", env1, "1"));
    assertTrue(doSubst(varX, env1, int3));
    assertTrue(doSubst(fvarX, env1, f3));
    assertTrue(doSubst(rvarX, env1, rvarX));
    assertTrue(doSubst(frvarX, env1, frvarX));  
  }
  
  public void testMatchVar() throws ToolBusException {
  	Environment env1 = new Environment(tbfactory);
  	Environment env2 = new Environment(tbfactory);
  	
    TBTermVar varX = tbfactory.makeTBTermVar("X", tbfactory.make("int"));	
    TBTermVar rvarX = tbfactory.makeTBTermResVar("X", tbfactory.make("int"));

    TBTermVar varXX = tbfactory.makeTBTermVar("XX", tbfactory.make("term"));	  
    TBTermVar rvarXX = tbfactory.makeTBTermResVar("XX", tbfactory.make("term"));
    
    TBTermVar varY = tbfactory.makeTBTermVar("Y", tbfactory.make("int"));
    TBTermVar rvarY = tbfactory.makeTBTermResVar("Y", tbfactory.make("int"));
    
    TBTermVar varYY = tbfactory.makeTBTermVar("YY", tbfactory.make("term"));   
    TBTermVar rvarYY = tbfactory.makeTBTermResVar("YY", tbfactory.make("term"));  
    
    TBTermVar varB = tbfactory.makeTBTermVar("B", tbfactory.make("str"));	
  
    ATerm int3 = tbfactory.make("3");
    ATerm int4 = tbfactory.make("4");
    ATerm int5 = tbfactory.make("5");
    ATerm int6 = tbfactory.make("6");
    
    ATermList declX = tbfactory.makeList(varX);
    env1.introduceVars(declX);
    env1.assignVar(varX, int3);
    
    ATermList declY = tbfactory.makeList(varY);
    env2.introduceVars(declY);
    env2.assignVar(varY, int4);
    
    assertTrue(doMatch(varX, env1, int3, env2));
    assertTrue(!doMatch(varX, env1, int4, env2));
    assertTrue(doMatch(int4, env1, varY, env2));
    assertTrue(!doMatch(int3, env1, varY, env2));
    
    ATerm f3 = tbfactory.make("f(3)");
    ATerm f4 = tbfactory.make("f(4)");
    ATerm f6 = tbfactory.make("f(6)");
    ATerm gf6 = tbfactory.make("g(f(6))");
    ATerm g5 = tbfactory.make("g(5)");
    ATerm fvarX = tbfactory.make("f(<term>)", varX);
    ATerm fvarY = tbfactory.make("f(<term>)", varY);
    ATerm frvarX = tbfactory.make("f(<term>)", rvarX);
    ATerm gvarX = tbfactory.make("g(<term>)", varX);
    
    assertTrue(doMatch(fvarX, env1, f3, env2));
    assertTrue(!doMatch(fvarX, env1, f4, env2));
    assertTrue(doMatch(f4, env1, fvarY, env2));
    assertTrue(!doMatch(f3, env1, fvarY, env2));
    
    assertTrue(doMatch(rvarX, env1, int5, env2)); 
    assertEquals(env1.getValue(varX), int5);
    assertTrue(doMatch(varX, env1, int5, env2)); 
    
    assertTrue(doMatch(int6, env1, rvarY, env2)); 
    assertEquals(env2.getValue(varY), int6);
    assertTrue(doMatch(int6, env1, varY, env2)); 
    
    assertTrue(doMatch(rvarXX, env1, fvarY, env2));
    assertEquals(env1.getValue(varXX), f6);
    
    assertTrue(!doMatch(rvarX, env1, fvarY, env2)); 
    
    assertTrue(!doMatch(gvarX, env1, rvarY, env2));
    
    assertTrue(doMatch(gvarX, env1, rvarYY, env2)); 
    assertEquals(env2.getValue(varYY), g5);
    
    ATermBlob b1 = tbfactory.makeBlob(new byte[]{'a', 'b', 'c'});
    ATermBlob b2 = tbfactory.makeBlob(new byte[]{'a', 'b', 'c'});
    
    ATermList declB = tbfactory.makeList(varB);
    env1.introduceVars(declB);
    env1.assignVar(varB, b1);  
    
    assertTrue(doMatch(b1.toString(), env1, b1.toString(), env2));
    assertTrue(doMatch(b1.toString(), env1, b2.toString(), env2));
    assertTrue(doMatch(b1.toString(), env1, "<str>", env2));
    assertTrue(doMatch("<str>", env1, b1.toString(), env2));
    
//    assertTrue(doMatch(varB, env1, b1.toString(), env2));
    
  }

  public ATerm check(String s) throws ToolBusException {
    Environment e = new Environment(tbfactory);
    return Functions.checkType(tbfactory.make(s), e, false);
  }

  public void testStaticCheck() throws ToolBusException {
    assertEquals(check("1"), tbfactory.IntType);
    assertEquals(check("1.5"), tbfactory.RealType);
    assertEquals(check("\"abc\""), tbfactory.StrType);
    assertEquals(check("true"), tbfactory.BoolType);
    assertEquals(check("false"), tbfactory.BoolType);

    assertEquals(check("add(1,2)"), tbfactory.IntType);
    assertEquals(check("greater(1,2)"), tbfactory.BoolType);
  }

  public boolean compatible(String s1, String s2) throws ToolBusException {
    return Functions.compatibleTypes(tbfactory.make(s1), tbfactory.make(s2));
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
  
  ATerm writeRead(ATerm term) {
	File f = new File("tmp");
	FileOutputStream os;
	try {
		os = new FileOutputStream(f);
		term.writeToTextFile(os);
		os.close();
		FileReader is = new FileReader(f);
		ATerm t = tbfactory.readFromTextFile(is);
		//System.err.println("writeRead: " + term + " => " + t);
		return t;
	} catch (FileNotFoundException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();
	} catch (Exception ex) {
		// TODO Auto-generated catch block
		ex.printStackTrace();
	}
	return null;
  }
  
  public void xxtestBlob() {
  	ATermBlob b = tbfactory.makeBlob(new byte[]{'a', 'b', 'c'});
  	/*
  	byte data[] = b.getBlobData();
  	assertTrue(data[0] == 'a');
  	assertTrue(data[1] == 'b');
  	assertTrue(data[2] == 'c');
 	System.err.println(b.toString());
  	ATermBlob c = (ATermBlob) factory.make(b.toString());
  	data = c.getBlobData();
 
 	assertTrue(data[0] == 'a');
  	assertTrue(data[1] == 'b');
  	assertTrue(data[2] == 'c'); 	
  	
	ATermBlob d = factory.makeBlob(new byte[]{'a', -128, -3});
  	data = d.getBlobData();
  	assertTrue(data[0] == 'a');
  	assertTrue(data[1] == -128);
  	assertTrue(data[2] == -3);
 	System.err.println(d.toString());
  	ATermBlob e = (ATermBlob) factory.make(d.toString());
  	data = e.getBlobData();
 
 	assertTrue(data[0] == 'a');
  	assertTrue(data[1] == -128);
  	assertTrue(data[2] == -3); 	
  	
  	assertTrue(b.isEqual(b));
  	*/
 //	ATermBlob b2 = factory.makeBlob(new byte[]{'a', 'b', 'c'});
 //	assertTrue(b.isEqual(b2));
 	//assertTrue(!b.isEqual(d));
 	
 //	System.err.println("b = " + b);
	System.err.println("writeRead(b) = " + writeRead(b));
	
//	assertTrue(writeRead(b).isEqual(b));
/*
	assertTrue(writeRead(d).isEqual(d));
	assertTrue(writeRead(d).isEqual(e));
	assertTrue(writeRead(e).isEqual(d));
	
	ATerm f1 = factory.make("f(<term>)", b);
	ATerm f2 = factory.make("f(<term>)", c);
	assertTrue(f1.isEqual(f1));
	assertTrue(f2.isEqual(f2));
	//assertTrue(f1.isEqual(f2));  // No equality on blobs yet!
	 */
  }
  
  public static Test suite() {
    return new TestSuite(TBTermTest.class);
  }

  public static void main(String args[]) {
    junit.textui.TestRunner.run(suite());
  }

}

