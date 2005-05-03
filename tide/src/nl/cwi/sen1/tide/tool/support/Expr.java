package nl.cwi.sen1.tide.tool.support;

//{{{ imports

import java.util.*;
import aterm.*;


//}}}

public class Expr
{
  //{{{ Patterns

  private static final String PATTERN_LOC_LC =
    "location(lc(<str>,<int>,<int>))";
  private static final String PATTERN_LOC_LINE =
    "location(line(<str>,<int>))";
  private static final String PATTERN_LOC_AREA =
    "location(area-in-file(<str>,area(<int>,<int>,<int>,<int>,<int>,<int>)))";
  private static final String PAT_SOURCE_VAR =
    "source-var(<str>,<int>,<int>,<int>,<str>)";
  private static final String PAT_VARIABLE =
    "variable(<str>,<term>)";
  private static final String PAT_VAR =
    "var(<str>,<term>,<int>,<int>,<int>,<int>)";
  private static final String PAT_VAR_UNKNOWN =
    "var-unknown(<str>)";
  private static final String PAT_ERROR =
    "error(<str>,<term>)";
  private static final String PAT_SOURCE_PATH =
    "source-path(<str>)";
  private static final String PAT_SOURCE_LIST =
    "source-list([<list>])";
  private static final String PAT_STACK_TRACE =
    "stack([<list>])";
  private static final String PAT_STACK_FRAME =
    "frame(<int>,<str>,<term>,<term>)";

  //}}}

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
  //{{{ public static Expr makeListSources()

  public static Expr makeListSources()
  {
    return make("list-sources");
  }

  //}}}
  //{{{ public static Expr makeStackTrace()

  public static Expr makeStackTrace()
  {
    return make("stack-trace");
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

  //{{{ public static Expr makeSourceVar(file, pos, linenr, col, line)

  public static Expr makeSourceVar(String file, int pos,
				   int linenr, int col, String line)
  {
    return Expr.make(Expr.factory.make(PAT_SOURCE_VAR,
				       file,
				       new Integer(pos),
				       new Integer(linenr),
				       new Integer(col), line));
  }

  //}}}

  //{{{ Expr(ATerm term)

  Expr(ATerm term)
  {
    this.term = term;
  }

  //}}}

  //{{{ public boolean isError()

  public boolean isError()
  {
    return term.match(PAT_ERROR) != null;
  }

  //}}}
  //{{{ public String getErrorMessage()

  public String getErrorMessage()
  {
    List result = term.match(PAT_ERROR);

    if (result != null) {
      return (String)result.get(0);
    }
    
    throw new RuntimeException("not an error: " + term);
  }

  //}}}
  //{{{ public Expr getErrorData()

  public Expr getErrorData()
  {
    List result = term.match(PAT_ERROR);

    if (result != null) {
      return Expr.make((ATerm)result.get(1));
    }
    
    throw new RuntimeException("not an error: " + term);
  }

  public boolean isLocation()
  {
    return term.match("location(<list>)") != null;
  }

  public boolean isLocationUnknown()
  {
    return term.match("location(unknown)") != null;
  }

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

    args = term.match(PATTERN_LOC_AREA);
    if (args != null) {
      return (String)args.get(0);
    }

    throw new RuntimeException("illegal location: " + term);
  }

  //}}}
  //{{{ public String getLocationShortFile()

  public String getLocationShortFile()
  {
    String file = getLocationFileName();
    int index = file.lastIndexOf('/');
    return file.substring(index+1);
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

    args = term.match(PATTERN_LOC_AREA);
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

    args = term.match(PATTERN_LOC_AREA);
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

    args = term.match(PATTERN_LOC_AREA);
    if (args != null) {
      return ((Integer)args.get(3)).intValue();
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

    args = term.match(PATTERN_LOC_AREA);
    if (args != null) {
      return ((Integer)args.get(4)).intValue();
    }

    throw new RuntimeException("illegal location: " + term);
  }

  //}}}

  //{{{ public boolean isVariable()

  public boolean isVariable()
  {
    List result = term.match(PAT_VARIABLE);
    return result != null;
  }

  //}}}
  //{{{ public String getVariableName()

  public String getVariableName()
  {
    List result = term.match(PAT_VARIABLE);
    if (result != null) {
      return (String)result.get(0);
    }

    throw new RuntimeException("not a variable: " + term);
  }

  //}}}
  //{{{ public Expr getVariableValue()

  public Expr getVariableValue()
  {
    List result = term.match(PAT_VARIABLE);
    if (result != null) {
      return Expr.make((ATerm)result.get(1));
    }

    throw new RuntimeException("not a variable: " + term);
  }

  //}}}

  //{{{ public boolean isVar()

  public boolean isVar()
  {
    List result = term.match(PAT_VAR);
    return result != null;
  }

  //}}}
  //{{{ public String getVarName()

  public String getVarName()
  {
    List result = term.match(PAT_VAR);
    if (result != null) {
      return (String)result.get(0);
    }

    throw new RuntimeException("not a variable spec: " + term);
  }

  //}}}
  //{{{ public Expr getVarValue()

  public Expr getVarValue()
  {
    List result = term.match(PAT_VAR);
    if (result != null) {
      return Expr.make((ATerm)result.get(1));
    }

    throw new RuntimeException("not a variable spec: " + term);
  }

  //}}}
  //{{{ public int getVarSourceStart()

  public int getVarSourceStart()
  {
    List result = term.match(PAT_VAR);
    if (result != null) {
      return ((Integer)result.get(2)).intValue();
    }

    throw new RuntimeException("not a variable spec: " + term);
  }

  //}}}
  //{{{ public int getVarSourceLineNr()

  public int getVarSourceLineNr()
  {
    List result = term.match(PAT_VAR);
    if (result != null) {
      return ((Integer)result.get(3)).intValue();
    }

    throw new RuntimeException("not a variable spec: " + term);
  }

  //}}}
  //{{{ public int getVarSourceStartColumn()

  public int getVarSourceStartColumn()
  {
    List result = term.match(PAT_VAR);
    if (result != null) {
      return ((Integer)result.get(4)).intValue();
    }

    throw new RuntimeException("not a variable spec: " + term);
  }

  //}}}
  //{{{ public int getVarSourceLength()

  public int getVarSourceLength()
  {
    List result = term.match(PAT_VAR);
    if (result != null) {
      return ((Integer)result.get(5)).intValue();
    }

    throw new RuntimeException("not a variable spec: " + term);
  }

  //}}}

  //{{{ public boolean isVarUnknown()

  public boolean isVarUnknown()
  {
    List result = term.match(PAT_VAR_UNKNOWN);
    return result != null;
  }

  //}}}
  //{{{ public String getVarUnknownMessage()

  public String getVarUnknownMessage()
  {
    List result = term.match(PAT_VAR_UNKNOWN);
    if (result != null) {
      return (String)result.get(0);
    }
    throw new RuntimeException("not a var-unknown spec: " + term);
  }

  //}}}

  //{{{ public boolean isBreak()

  public boolean isBreak()
  {
    return term.isEqual(factory.parse("break"));
  }

  //}}}

  //{{{ public boolean isSourcePath()

  public boolean isSourcePath()
  {
    List result = term.match(PAT_SOURCE_PATH);
    return result != null;
  }

  //}}}
  //{{{ public String getSourcePath()

  public String getSourcePath()
  {
    List result = term.match(PAT_SOURCE_PATH);
    if (result != null) {
      return (String)result.get(0);
    }

    throw new RuntimeException("not a source path: " + term);
  }

  //}}}

  //{{{ public boolean isSourceList()

  public boolean isSourceList()
  {
    List result = term.match(PAT_SOURCE_LIST);
    return result != null;
  }

  //}}}
  //{{{ public Iterator sourceIterator()

  public Iterator sourceIterator()
  {
    List result = term.match(PAT_SOURCE_LIST);
    if (result != null) {
      return new StringIterator((ATermList)result.get(0));
    }

    throw new RuntimeException("not a source-list: " + term);
  }

  //}}}

  //{{{ public boolean isStackTrace()

  public boolean isStackTrace()
  {
    return term.match(PAT_STACK_TRACE) != null;
  }

  //}}}
  //{{{ public Iterator frameIterator()

  public Iterator frameIterator()
  {
    List result = term.match(PAT_STACK_TRACE);
    if (result != null) {
      return new ExprIterator((ATermList)result.get(0));
    }

    throw new RuntimeException("not a stacktrace: " + term);
  }

  //}}}
  //{{{ public boolean isStackFrame()

  public boolean isStackFrame()
  {
    return term.match(PAT_STACK_FRAME) != null;
  }

  //}}}
  //{{{ public int getFrameDepth()

  public int getFrameDepth()
  {
    List result = term.match(PAT_STACK_FRAME);
    if (result != null) {
      return ((Integer)result.get(0)).intValue();
    }
    throw new RuntimeException("not a stackframe: " + term);
  }

  //}}}
  //{{{ public String getFrameName()

  public String getFrameName()
  {
    List result = term.match(PAT_STACK_FRAME);
    if (result != null) {
      return (String)result.get(1);
    }
    throw new RuntimeException("not a stackframe: " + term);
  }

  //}}}
  //{{{ public Expr getFrameLocation()

  public Expr getFrameLocation()
  {
    List result = term.match(PAT_STACK_FRAME);
    if (result != null) {
      return new Expr((ATerm)result.get(2));
    }
    throw new RuntimeException("not a stackframe: " + term);
  }

  //}}}
  //{{{ public Expr getFrameVariables()

  public Expr getFrameVariables()
  {
    List result = term.match(PAT_STACK_FRAME);
    if (result != null) {
      return new Expr((ATerm)result.get(3));
    }
    throw new RuntimeException("not a stackframe: " + term);
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
    if (isVariable()) {
      return getVariableName() + " = " + getVariableValue();
    } else if (isLocation() && !isLocationUnknown()) {
      return getLocationShortFile() + " "
	+ getLocationStartLine() + "," + getLocationStartColumn()
	+ "-"
	+ getLocationEndLine() + "," + getLocationEndColumn();
    }
      
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

class StringIterator
  implements Iterator
{
  private ATermList list;

  //{{{ public StringIterator(ATermList list)

  public StringIterator(ATermList list)
  {
    this.list = list;
  }

  //}}}
  //{{{ public boolean hasNext()

  public boolean hasNext()
  {
    if (list.isEmpty()) {
      return false;
    }

    return true;
  }

  //}}}
  //{{{ public Object next()

  public Object next()
  {
    ATerm result;

    result = list.getFirst();
    list   = list.getNext();

    return ((ATermAppl)result).getAFun().getName();
  }

  //}}}
  //{{{ public void remove()

  public void remove()
  {
    throw new UnsupportedOperationException();
  }

  //}}}
}
  
