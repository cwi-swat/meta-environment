
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

class TestFailedException extends Exception
{
  private String func;
  public TestFailedException(String function)	{ func = function; }
  public String explain() {
    return func;
  }
}

public class ATest
{
  //{ public static void main(String[] args)

  public static void main(String[] args)
    throws IOException, ParseError, TestFailedException
  {
    try {
      testATermImpl();
      testATerm();
      testATermParser();
      testATerms();
      testATermPatternMatch();
      testATermPatternMake();
      testAnno();
    } catch (TestFailedException e) {
      System.out.println("test failed: " + e.explain());
    }
    
/*
    for(int i=0; i<15; i++) {
      System.out.println("table size: " + ATermImpl.tableSize());
      System.out.println("garbage collect " + i);
      System.gc();
      System.out.println("finalization" + i);
      System.runFinalization();
    }
    
    if(ATermImpl.tableSize() != 0) {
      System.out.println("terms left:");
      Enumeration enum = ATermImpl.tableElements();
      while(enum.hasMoreElements()) {
	ATerm t = (ATerm)enum.nextElement();
	t.print(new PrintWriter(System.out));
	System.out.println(" (" + t.refCount() + ", " + t.getType() + ")");
      }
    }
*/
  }

//}

  //{ protected static void test(boolean cond, String id)

  protected static void test(boolean cond, String id)
    throws TestFailedException
  {
    if(cond)
      System.out.println("test " + id + " ok!");
    else
      throw new TestFailedException(id);
  }

  //}
  //{ protected static void testATermImpl() 

  protected static void testATermImpl() 
    throws IOException
  {
    ATermImpl[] T;
    T = new ATermImpl[10];
    
    System.out.println("testing ATermImpl classes");
    T[0] = new ATermIntImpl(5);
    T[1] = new ATermRealImpl(3.14);
    T[2] = new ATermApplImpl("abc", new ATermsImpl(), true);
    ATermsImpl terms = new ATermsImpl(T[0], new ATermsImpl(T[1], new ATermsImpl(T[2], new ATermsImpl())));
    T[3] = new ATermListImpl(terms);
    T[4] = new ATermApplImpl("abc", terms);
    T[5] = new ATermApplImpl("abc\002def", new ATermsImpl());
    
    PrintWriter w = new PrintWriter(System.out);
    for(int i=0; i<5; i++) {
      System.out.print("term " + i + ": ");
      T[i].print(w);
      w.flush();
      System.out.println("");
    }
  }

  //}
  //{ protected static void testATerm()

  protected static void testATerm()
    throws IOException
  {
    ATerm[] T;
    T = new ATerm[10];
    
    System.out.println("testing ATerm classes");
    T[0] = new ATermInt(5);
    T[1] = new ATermReal(3.14);
    T[2] = new ATermAppl("abc", new ATerms(), true);
    ATerms terms = new ATerms(T[0], new ATerms(T[1], new ATerms(T[2])));
    T[3] = new ATermList(terms);
    T[4] = new ATermAppl("abc", terms);
    T[5] = new ATermAppl("abc\002def", new ATerms());

    for(int i=0; i<3; i++) {
      System.out.print("term " + i + ": ");
      T[i].print(new PrintWriter(System.out));
      System.out.println("");
    }
  }

  //}
  //{ protected static void testATermParser()

  protected static void testATermParser()
    throws IOException, ParseError
  {
    ATerm[] T;
    T = new ATerm[10];
    
    System.out.println("testing ATermParser class");
    T[0] = ATermParser.makeSimple("g");
    T[1] = ATermParser.makeSimple("fgh(1,2,<3>)");
    T[2] = ATermParser.makeSimple("[1,3.5,4e6,123.21E-3,-12]");

    for(int i=0; i<3; i++) {
      System.out.print("term " + i + ": ");
      T[i].print(new PrintWriter(System.out));
      System.out.println("");
    }
  }

  //}
  //{ protected static void testATerms()

  protected static void testATerms()
    throws ParseError, TestFailedException 
  {
    ATerm[] T;
    ATerms[] Ts;
    T = new ATerm[10];
    Ts = new ATerms[10];

    System.out.println("testing ATerms class");
    T[0] = ATermParser.makeSimple("[0,1,2,3,4,5,4,3,2,1]");
    Ts[0] = ((ATermList)T[0]).getATerms();
    T[1] = ATermParser.makeSimple("[]");
    Ts[1] = new ATerms();
    T[2] = ATermParser.makeSimple("[1,2,3]");
    Ts[2] = ((ATermList)T[2]).getATerms();
    T[3] = ATermParser.makeSimple("[4,5,6]");
    Ts[3] = ((ATermList)T[3]).getATerms();
    T[4] = ATermParser.makeSimple("[1,2,3,4,5,6]");
    Ts[4] = ((ATermList)T[4]).getATerms();

    T[5] = ATermParser.makeSimple("[1,2,3,4,5,6,7]");
    Ts[5] = ((ATermList)T[5]).getATerms();

    //{ test length
    test(Ts[0].length() == 10, "length-1");
    //}
    //{ test search
    test(Ts[0].search(new ATermInt(2)) == 2, "search-1");
    test(Ts[0].search(new ATermInt(10)) == -1, "search-2");
    test(Ts[0].search(new ATermInt(0)) == 0, "search-3");
    test(Ts[0].search(new ATermInt(5)) == 5, "search-4");
    //}
    //{ test rsearch
    test(Ts[0].rsearch(new ATermInt(1)) == 9, "rsearch-1");
    test(Ts[0].rsearch(new ATermInt(0)) == 0, "rsearch-2");
    test(Ts[0].rsearch(new ATermInt(10)) == -1, "rsearch-3");
    //}
    //{ test concat
    test(Ts[2].concat(Ts[3]).equals(Ts[4]), "concat-1");
    test(Ts[0].concat(Ts[1]).equals(Ts[0]), "concat-2");
    //}
    //{ test append
    test(Ts[4].append(new ATermInt(7)).equals(Ts[5]), "append-1");
    //}
  }
  //}
  //{ protected static void testATermPatternMatch()

  protected static void testATermPatternMatch()
    throws ParseError, TestFailedException
  {
    ATerm[] T = new ATerm[10];
    ATermPattern[] P = new ATermPattern[10];
    
    T[0] = ATermParser.makeSimple("f(1,2,3)");
    T[1] = ATermParser.makeSimple("[1,2,3]");
    T[2] = ATermParser.makeSimple("f(a,\"abc\",2.3,<abc>)");
    
    P[0] = new ATermPattern(ATermParser.makeSimple("f(1,2,3)"));
    P[1] = new ATermPattern("f(1,<int>,3)");
    P[2] = new ATermPattern("f(<appl>,<str>,<real>,<placeholder>)");
    P[3] = new ATermPattern("<list>");
    P[4] = new ATermPattern("[<int>,<terms>]");
    P[5] = new ATermPattern("<fun(<int>,<terms>)>");
    P[6] = new ATermPattern("<f>");
    P[7] = new ATermPattern("<f(1,2,<int>)>");

    test(P[0].match(T[0]) && P[0].size() == 0, "match-1");
    test(!P[0].match(T[1]), "match-2");
    test(P[1].match(T[0]) && P[1].size() == 1 && 
	 P[1].elementAt(0).equals(new Integer(2)), "match-3");
    test(P[2].match(T[2]) && P[2].size() == 4, "match-4a");
    test(P[2].elementAt(0).equals(ATermParser.makeSimple("a")), "match-4b");
    test(P[2].elementAt(1).equals("abc"), "match-4c");
    test(P[2].elementAt(2).equals(new Double(2.3)), "match-4d");
    test(P[2].elementAt(3).equals(ATermParser.makeSimple("<abc>")), "match-4e");
    test(P[3].match(T[1]) && P[3].size()==1 && P[3].elementAt(0).equals(T[1]), "match-5");
    test(P[4].match(T[1]) && P[4].size()==2, "match-6a");
    test(P[4].elementAt(0).equals(new Integer(1)), "match-6b");
    test(P[4].elementAt(1).equals(
				  ((ATermList)ATermParser.makeSimple("[2,3]")).getATerms()), "match-6c");
    test(P[5].match(T[0]) && P[4].size()==2, "match-7a");
    test(P[5].elementAt(0).equals("f"), "match-7b");
    test(P[5].elementAt(1).equals(new Integer(1)), "match-7c");
    test(P[5].elementAt(2).equals(((ATermList)
          ATermParser.makeSimple("[2,3]")).getATerms()), "match-7d");
    test(P[6].match(T[0]) && P[6].size()==1, "match-8a");
    test(P[6].elementAt(0).equals(T[0]), "match-8b");
    test(P[7].match(T[0]) && P[7].size() == 2, "match-9a");
    test(P[7].elementAt(0).equals(T[0]) && P[7].elementAt(1).equals(new Integer(3)), "match-9b");
  }

  //}
  //{ protected static void testATermPatternMake()

  protected static void testATermPatternMake()
    throws ParseError, TestFailedException
  {
    ATerm[] T = new ATerm[10];
    ATermPattern[] P = new ATermPattern[10];

    T[0] = new ATermInt(1);
    T[1] = new ATermInt(2);
    T[2] = new ATermInt(3);
    T[3] = new ATermAppl("a", new ATerms());
    T[4] = new ATermAppl("b", new ATerms());
    T[5] = new ATermAppl("c", new ATerms());
    T[6] = ATermParser.makeSimple("f(a,b,c)");
    T[7] = ATermParser.makeSimple("[1,2,3]");
    T[8] = ATermParser.makeSimple("f(1,2,3)");

    P[0] = new ATermPattern("<int>");
    P[1] = new ATermPattern("<appl>");
    P[2] = new ATermPattern("<fun>");
    P[3] = new ATermPattern("<real>");
    P[4] = new ATermPattern("<placeholder>");
    P[5] = new ATermPattern("<list>");
    P[6] = new ATermPattern("f(<appl>,<fun>,<terms>)");
    P[7] = new ATermPattern("<fun(1,<int>,3)>");
    P[8] = new ATermPattern("[<terms>]");

    test(P[0].make(new Integer(1)).equals(T[0]), "make-1");
    test(P[1].make(T[3]).equals(T[3]), "make-2");
    test(P[2].make("b").equals(T[4]), "make-3");
    test(P[3].make(new Double(3.14)).equals(new ATermReal(3.14)), "make-4");
    test(P[4].make(new ATermAppl("real", new ATerms())).equals(P[3].getPattern()), "make-5");
    test(P[5].make(T[7]).equals(T[7]), "make-6");
    test(P[6].make(T[3], "b", new ATerms(T[5], new ATerms())).equals(T[6]), "make-7");
    test(P[7].make("f", new Integer(2)).equals(T[8]), "make-8");
    test(P[8].make(((ATermList)T[7]).getATerms()).equals(T[7]), "make-9");
  }

  //}
  //{ protected static void testAnno()

  /**
    * Test annotations.
    */

  protected static void testAnno()
    throws ParseError, TestFailedException
  {
    ATerm T[] = new ATerm[5];

    T[0] = ATermParser.makeSimple("f(1,2,3)");
    T[1] = ATermParser.makeSimple("color(red)");
    T[0].setAnno(T[1]);
    test(T[0].getAnno().equals(T[1]), "anno-1");
    test(T[1].getAnno() == null, "anno-2");
  }

  //}
}
