/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

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
  private World world;

  //{ public static void main(String[] args)

  public static void main(String[] args)
    throws IOException, ParseError, TestFailedException
  {
    ATest test = new ATest();

    try {
      test.testATermImpl();
      test.testATerm();
      test.testATermParser();
      test.testATerms();
      test.testATermPatternMatch();
      test.testATermPatternMake();
      test.testAnno();
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

  //{ public ATest()

  /**
    * Execute tests.
    */

  public ATest()
  {
    world = new World(299);
  }

  //}
  //{ protected  void test(boolean cond, String id)

  protected  void test(boolean cond, String id)
    throws TestFailedException
  {
    if(cond)
      System.out.println("test " + id + " ok!");
    else
      throw new TestFailedException(id);
  }

  //}
  //{ protected  void testATermImpl() 

  protected  void testATermImpl() 
    throws IOException
  {
    ATermImpl[] T;
    T = new ATermImpl[10];
    
    System.out.println("testing ATermImpl classes");
    T[0] = new ATermIntImpl(world, 5);
    T[1] = new ATermRealImpl(world, 3.14);
    T[2] = new ATermApplImpl(world, "abc", new ATermsImpl(world), null, true);
    ATermsImpl terms = new ATermsImpl(world, T[0], 
	  new ATermsImpl(world, T[1], 
			 new ATermsImpl(world, T[2], new ATermsImpl(world))));
    T[3] = new ATermListImpl(world, terms);
    T[4] = new ATermApplImpl(world, "abc", terms);
    T[5] = new ATermApplImpl(world, "abc\002def", new ATermsImpl(world));
    
    PrintWriter w = new PrintWriter(System.out);
    for(int i=0; i<5; i++) {
      System.out.print("term " + i + ": ");
      T[i].print(w);
      w.flush();
      System.out.println("");
    }
  }

  //}
  //{ protected  void testATerm()

  protected  void testATerm()
    throws IOException
  {
    ATerm[] T;
    T = new ATerm[10];
    
    System.out.println("testing ATerm classes");
    T[0] = world.makeInt(5);
    T[1] = world.makeReal(3.14);
    T[2] = world.makeAppl("abc", world.empty, null, true);
    ATerms terms = world.makeATerms(T[0], world.makeATerms(T[1], world.makeATerms(T[2])));
    T[3] = world.makeList(terms);
    T[4] = world.makeAppl("abc", terms);
    T[5] = world.makeAppl("abc\002def", world.empty);

    for(int i=0; i<3; i++) {
      System.out.print("term " + i + ": ");
      T[i].print(new PrintWriter(System.out));
      System.out.println("");
    }
  }

  //}
  //{ protected  void testATermParser()

  protected  void testATermParser()
    throws IOException, ParseError
  {
    ATerm[] T = new ATerm[10];
    
    System.out.println("testing world class");
    T[0] = world.makeSimple("g");
    T[1] = world.makeSimple("fgh(1,2,<3>)");
    T[2] = world.makeSimple("[1,3.5,4e6,123.21E-3,-12]");
    T[3] = world.makeSimple("hh(\"-/-\")");

    for(int i=0; i<4; i++) {
      System.out.print("term " + i + ": ");
      T[i].print(new PrintWriter(System.out));
      System.out.println("");
    }
  }

  //}
  //{ protected  void testATerms()

  protected  void testATerms()
    throws ParseError, TestFailedException 
  {
    ATerm[] T = new ATerm[10];
    ATerms[] Ts = new ATerms[10];

    System.out.println("testing ATerms class");
    T[0] = world.makeSimple("[0,1,2,3,4,5,4,3,2,1]");
    Ts[0] = ((ATermList)T[0]).getATerms();
    T[1] = world.makeSimple("[]");
    Ts[1] = world.empty;
    T[2] = world.makeSimple("[1,2,3]");
    Ts[2] = ((ATermList)T[2]).getATerms();
    T[3] = world.makeSimple("[4,5,6]");
    Ts[3] = ((ATermList)T[3]).getATerms();
    T[4] = world.makeSimple("[1,2,3,4,5,6]");
    Ts[4] = ((ATermList)T[4]).getATerms();

    T[5] = world.makeSimple("[1,2,3,4,5,6,7]");
    Ts[5] = ((ATermList)T[5]).getATerms();

    //{ test length
    test(Ts[0].length() == 10, "length-1");
    //}
    //{ test search
    test(Ts[0].search(world.makeInt(2)) == 2, "search-1");
    test(Ts[0].search(world.makeInt(10)) == -1, "search-2");
    test(Ts[0].search(world.makeInt(0)) == 0, "search-3");
    test(Ts[0].search(world.makeInt(5)) == 5, "search-4");
    //}
    //{ test rsearch
    test(Ts[0].rsearch(world.makeInt(1)) == 9, "rsearch-1");
    test(Ts[0].rsearch(world.makeInt(0)) == 0, "rsearch-2");
    test(Ts[0].rsearch(world.makeInt(10)) == -1, "rsearch-3");
    //}
    //{ test concat
    test(Ts[2].concat(Ts[3]).equals(Ts[4]), "concat-1");
    test(Ts[0].concat(Ts[1]).equals(Ts[0]), "concat-2");
    //}
    //{ test append
    test(Ts[4].append(world.makeInt(7)).equals(Ts[5]), "append-1");
    //}
  }

  //}
  //{ protected  void testATermPatternMatch()

  protected  void testATermPatternMatch()
    throws ParseError, TestFailedException
  {
    ATerm[] T = new ATerm[10];
    ATermPattern[] P = new ATermPattern[10];
    
    T[0] = world.makeSimple("f(1,2,3)");
    T[1] = world.makeSimple("[1,2,3]");
    T[2] = world.makeSimple("f(a,\"abc\",2.3,<abc>)");
    
    P[0] = world.makePattern("f(1,2,3)");
    P[1] = world.makePattern("f(1,<int>,3)");
    P[2] = world.makePattern("f(<appl>,<str>,<real>,<placeholder>)");
    P[3] = world.makePattern("<list>");
    P[4] = world.makePattern("[<int>,<terms>]");
    P[5] = world.makePattern("<fun(<int>,<terms>)>");
    P[6] = world.makePattern("<f>");
    P[7] = world.makePattern("<f(1,2,<int>)>");

    test(P[0].match(T[0]) && P[0].size() == 0, "match-1");
    test(!P[0].match(T[1]), "match-2");
    test(P[1].match(T[0]) && P[1].size() == 1 && 
	 P[1].elementAt(0).equals(new Integer(2)), "match-3");
    test(P[2].match(T[2]) && P[2].size() == 4, "match-4a");
    test(P[2].elementAt(0).equals(world.makeSimple("a")), "match-4b");
    test(P[2].elementAt(1).equals("abc"), "match-4c");
    test(P[2].elementAt(2).equals(new Double(2.3)), "match-4d");
    test(P[2].elementAt(3).equals(world.makeSimple("<abc>")), "match-4e");
    test(P[3].match(T[1]) && P[3].size()==1 && P[3].elementAt(0).equals(T[1]), "match-5");
    test(P[4].match(T[1]) && P[4].size()==2, "match-6a");
    test(P[4].elementAt(0).equals(new Integer(1)), "match-6b");
    test(P[4].elementAt(1).equals(
				  ((ATermList)world.makeSimple("[2,3]")).getATerms()), "match-6c");
    test(P[5].match(T[0]) && P[4].size()==2, "match-7a");
    test(P[5].elementAt(0).equals("f"), "match-7b");
    test(P[5].elementAt(1).equals(new Integer(1)), "match-7c");
    test(P[5].elementAt(2).equals(((ATermList)
          world.makeSimple("[2,3]")).getATerms()), "match-7d");
    test(P[6].match(T[0]) && P[6].size()==1, "match-8a");
    test(P[6].elementAt(0).equals(T[0]), "match-8b");
    test(P[7].match(T[0]) && P[7].size() == 2, "match-9a");
    test(P[7].elementAt(0).equals(T[0]) && P[7].elementAt(1).equals(new Integer(3)), "match-9b");
  }

  //}
  //{ protected  void testATermPatternMake()

  protected  void testATermPatternMake()
    throws ParseError, TestFailedException
  {
    ATerm[] T = new ATerm[10];
    ATermPattern[] P = new ATermPattern[10];

    T[0] = world.makeInt(1);
    T[1] = world.makeInt(2);
    T[2] = world.makeInt(3);
    T[3] = world.makeAppl("a", world.empty);
    T[4] = world.makeAppl("b", world.empty);
    T[5] = world.makeAppl("c", world.empty);
    T[6] = world.makeSimple("f(a,b,c)");
    T[7] = world.makeSimple("[1,2,3]");
    T[8] = world.makeSimple("f(1,2,3)");

    P[0] = world.makePattern("<int>");
    P[1] = world.makePattern("<appl>");
    P[2] = world.makePattern("<fun>");
    P[3] = world.makePattern("<real>");
    P[4] = world.makePattern("<placeholder>");
    P[5] = world.makePattern("<list>");
    P[6] = world.makePattern("f(<appl>,<fun>,<terms>)");
    P[7] = world.makePattern("<fun(1,<int>,3)>");
    P[8] = world.makePattern("[<terms>]");

    test(P[0].make(new Integer(1)).equals(T[0]), "make-1");
    test(P[1].make(T[3]).equals(T[3]), "make-2");
    test(P[2].make("b").equals(T[4]), "make-3");
    test(P[3].make(new Double(3.14)).equals(world.makeReal(3.14)), "make-4");
    test(P[4].make(world.makeAppl("real", world.empty)).equals(P[3].getPattern()), "make-5");
    test(P[5].make(T[7]).equals(T[7]), "make-6");
    test(P[6].make(T[3], "b", world.makeATerms(T[5], world.empty)).equals(T[6]), "make-7");
    test(P[7].make("f", new Integer(2)).equals(T[8]), "make-8");
    test(P[8].make(((ATermList)T[7]).getATerms()).equals(T[7]), "make-9");
  }

  //}
  //{ protected  void testAnno()

  /**
    * Test annotations.
    */

  protected  void testAnno()
    throws ParseError, TestFailedException
  {
    ATerm T[] = new ATerm[5];

    T[0] = world.makeSimple("f(1,2,3)");
    T[1] = world.makeSimple("color(red)");
    T[0].setAnno(T[1]);
    test(T[0].getAnno().equals(T[1]), "anno-1");
    test(T[1].getAnno() == null, "anno-2");
  }

  //}
}
