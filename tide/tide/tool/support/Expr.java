package tide.tool.support;

//{{{ imports

import java.util.*;
import aterm.*;


//}}}

public class Expr
{
  private static final String PATTERN_LOC_LC =
    "location(lc(<str>,<int>,<int>))";
  private static final String PATTERN_LOC_LINE =
    "location(line(<str>,<int>))";

  public static ATermFactory factory;

  private ATerm term;

  //{{{ public static void initialize(ATermFactory factory)

  public static void initialize(ATermFactory factory)
  {
    Expr.factory = factory;
  }

  //}}}

  //{{{ public static Expr parse(String spec)

  public static Expr parse(String spec)
  {
    try {
      return fromTerm(factory.parse(spec));
    } catch (Exception e) {
      return null;
    }
  }

  //}}}

  //{{{ public static Expr makeTrue()

  public static Expr makeTrue()
  {
    return make("true");
  }

  //}}}
  //{{{ public static Expr makeFalse()

  public static Expr makeFalse()
  {
    return make("false");
  }

  //}}}
  //{{{ public static Expr makeCpe()

  public static Expr makeCpe()
  {
    return make("cpe");
  }

  //}}}
  //{{{ public static Expr makeBreak()

  public static Expr makeBreak()
  {
    return make("break");
  }

  //}}}
  //{{{ public static Expr makeResume()

  public static Expr makeResume()
  {
    return make("resume");
  }

  //}}}
  //{{{ public static Expr makeLocation(String file, int line, int col)

  public static Expr makeLocation(String file, int line, int column)
  {
    return make(factory.make(PATTERN_LOC_LC, file, new Integer(line),
			     new Integer(column)));
  }

  //}}}
  //{{{ public static Expr make(String expr)

  public static Expr make(String expr)
  {
    return make(factory.parse(expr));
  }

  //}}}
  //{{{ public static Expr make(ATerm expr)

  public static Expr make(ATerm expr)
  {
    return new Expr(expr);
  }

  //}}}
  //{{{ public static Expr fromTerm(ATerm expr)

  public static Expr fromTerm(ATerm expr)
  {
    return make(expr);
  }

  //}}}

  //{{{ Expr(ATerm term)

  Expr(ATerm term)
  {
    this.term = term;
  }

  //}}}

  //{{{ public boolean isLocation()

  public boolean isLocation()
  {
    return term.match("location(<list>)") != null;
  }

  //}}}
  //{{{ public String getLocationFileName()

  public String getLocationFileName()
  {
    List args = term.match(PATTERN_LOC_LINE);
    if (args != null) {
      return (String)args.get(0);
    }

    args = term.match(PATTERN_LOC_LC);
    if (args != null) {
      return (String)args.get(0);
    }


    throw new RuntimeException("illegal location: " + term);
  }

  //}}}
  //{{{ public int getLocationStartLine()

  public int getLocationStartLine()
  {
    List args = term.match(PATTERN_LOC_LINE);
    if (args != null) {
      return ((Integer)args.get(1)).intValue();
    }

    args = term.match(PATTERN_LOC_LC);
    if (args != null) {
      return ((Integer)args.get(1)).intValue();
    }

    throw new RuntimeException("illegal location: " + term);
  }

  //}}}
  //{{{ public int getLocationStartColumn()

  public int getLocationStartColumn()
  {
    List args = term.match(PATTERN_LOC_LINE);
    if (args != null) {
      return 0;
    }

    args = term.match(PATTERN_LOC_LC);
    if (args != null) {
      return ((Integer)args.get(2)).intValue();
    }

    throw new RuntimeException("illegal location: " + term);
  }

  //}}}
  //{{{ public int getLocationEndLine()

  public int getLocationEndLine()
  {
    List args = term.match(PATTERN_LOC_LINE);
    if (args != null) {
      return ((Integer)args.get(1)).intValue();
    }

    args = term.match(PATTERN_LOC_LC);
    if (args != null) {
      return ((Integer)args.get(1)).intValue();
    }

    throw new RuntimeException("illegal location: " + term);
  }

  //}}}
  //{{{ public int getLocationEndColumn()

  public int getLocationEndColumn()
  {
    List args = term.match(PATTERN_LOC_LINE);
    if (args != null) {
      return -1;
    }

    args = term.match(PATTERN_LOC_LC);
    if (args != null) {
      return ((Integer)args.get(2)).intValue();
    }

    throw new RuntimeException("illegal location: " + term);
  }

  //}}}

  //{{{ public boolean isBreak()

  public boolean isBreak()
  {
    return term.isEqual(factory.parse("break"));
  }

  //}}}

  //{{{ public Iterator iterator()

  public Iterator iterator()
  {
    return new ExprIterator(term);
  }

  //}}}

  //{{{ public ATerm  toTerm()

  public ATerm  toTerm()
  {
    return term;
  }

  //}}}
  //{{{ public String toString()

  public String toString()
  {
    return term.toString();
  }

  //}}}
}

class ExprIterator
  implements Iterator
{
  private ATerm term;

  //{{{ public ExprIterator(ATerm term)

  public ExprIterator(ATerm term)
  {
    this.term = term;
  }

  //}}}

  //{{{ public boolean hasNext()

  public boolean hasNext()
  {
    if (term == null || (term.getType() == ATerm.LIST && 
			 ((ATermList)term).isEmpty())) {
      return false;
    }

    return true;
  }

  //}}}
  //{{{ public Object next()

  public Object next()
  {
    ATerm result;

    if (term.getType() == ATerm.LIST) {
      result = ((ATermList)term).getFirst();
      term = ((ATermList)term).getNext();
    } else {
      result = term;
      term = null;
    }

    return new Expr(result);
  }

  //}}}
  //{{{ public void remove()

  public void remove()
  {
    throw new UnsupportedOperationException();
  }

  //}}}
}

