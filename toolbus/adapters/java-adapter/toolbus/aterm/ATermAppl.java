
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

/**
  * ATermAppl objects represent function application terms.
  *
  */

public class ATermAppl extends ATerm
{
  static Hashtable symbols = new Hashtable(1003);
  protected int hashcode;
  private String fun;
  private ATerms args;
  private boolean quoted;

  //{ public ATermAppl(String fn, ATerms as, ATerm an)

  public ATermAppl(String fn, ATerms as, ATerm an)
  {
    super(an);
    fun = (String)symbols.get(fn);
    if(fun == null) {
      fun = fn;
      symbols.put(fn, fn);
    }
    args = as;  
    quoted = needsQuotes(fn);
    updateHashCode();
    if(args != null)
      args.increaseRef();
  }

  //}
  //{ public ATermAppl(String fn, ATerms as)

  public ATermAppl(String fn, ATerms as)
  {
    this(fn, as, null);
  }

  //}
  //{ public ATermAppl(String fn, ATerms as, boolean isquoted, ATerm an)

  public ATermAppl(String fn, ATerms as, boolean isquoted, ATerm an)
  {
    super(an);
    fun = (String)symbols.get(fn);
    if(fun == null) {
      fun = fn;
      symbols.put(fn, fn);
    }
    args = as;
    quoted = isquoted;
    updateHashCode();
    if(args != null)
      args.increaseRef();
  }

  //}
  //{ public ATermAppl(String fn, ATerms as, boolean isquoted)

  public ATermAppl(String fn, ATerms as, boolean isquoted)
  {
    this(fn, as, isquoted, null);
  }

  //}

  //{ public Object clone()

  /**
    * Make a SHALLOW copy of an ATermAppl.
    */

  public Object clone()
  {
    ATermAppl appl = (ATermAppl)super.clone();
    appl.hashcode = hashcode;
    appl.fun = fun;
    appl.args = args;
    appl.quoted = quoted;
    args.increaseRef();

    return appl;    
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    if(args != null)
      args.decreaseRef();
    super.finalize();
  }
  //}

  //{ public boolean equals(Object obj)

  public boolean equals(Object obj)
  {
    if(obj instanceof ATermAppl)
      return fun == ((ATermAppl)obj).fun && args == ((ATermAppl)obj).args &&
	quoted == ((ATermAppl)obj).quoted && super.equals(obj);
    return false;
  }

  //}
  //{ public int getType()

  public int getType()
  {
    return ATerm.APPL;
  }

  //}
  //{ private int updateHashCode()

  private void updateHashCode()
  {
    if(args == null)
      hashcode = fun.hashCode() ^ 321;
    else
      hashcode = fun.hashCode() + args.hashCode();
  }

  //}
  //{ public int hashCode()

  public int hashCode()
  {
    return hashcode;
  }

  //}

  //{ public String getFun()

  public String getFun() {
    return fun;
  }

  //}
  //{ public ATerms getArgs()

  public ATerms getArgs()
  {
    return args;
  }

  //}
  //{ public void setFun(String fn)

  public void setFun(String fn)
  {
    fun = (String)symbols.get(fn);
    if(fun == null) {
      fun = fn;
      symbols.put(fn, fn);
    }
    updateHashCode();
  }

  //}
  //{ public void setArgs(ATerms as)

  public void setArgs(ATerms as)
  {
    if(args != null)
      args.decreaseRef();
    args = as;
    updateHashCode();
    if(args != null)
      args.increaseRef();
  }

  //}
  //{ public boolean isQuoted()

  public boolean isQuoted()
  {
    return quoted;
  }

  //}

  //{ public int size()

  public int size()
  {
    if(args == null)
      return 1 + super.size();
    else
      return 1 + super.size() + args.size();
  }

  //}
  //{ public void write(OutputStream o) 

  public void write(OutputStream o) 
    throws java.io.IOException
  {
    writeFun(o);
    if(args != null) {
      o.write('(');
      args.write(o);
      o.write(')');
    }
    super.write(o);
  }

  //}
  //{ public void print(PrintWriter w)

  public void print(PrintWriter w) 
  {
    printFun(w);
    if(args != null) {
      w.print('(');
      args.print(w);
      w.print(')');
    }
    super.print(w);
  }

  //}
  //{ public int printSize()

  public int printSize()
  {
    int size = super.printSize();
    size += printSizeFun();
    if(args != null)
      size += args.printSize()+2;  // Don't forget the '(' and ')' characters.
    return size;
  }

  //}

  //{ public boolean match(ATerm trm, Vector subterms)

  public boolean match(ATerm trm, Vector subterms)
  {
    if(trm.getType() == ATerm.APPL) {
      ATermAppl ap = (ATermAppl)trm;
      if(ap.getFun() == getFun()) {
	if(getArgs() == null)
	  return ap.getArgs() == null;
	if(ap.getArgs() != null)
	  return getArgs().match(ap.getArgs(), subterms);
      }
    }
    return false;
  }

  //}

  //{ private void writeFun(OutputStream o)

  private void writeFun(OutputStream o) 
    throws java.io.IOException
  {
    if(!quoted) {
      for(int i=0; i<fun.length(); i++)
	o.write(fun.charAt(i));
    } else {
      boolean escaped = false;
      o.write('"');
      for(int i=0; i<fun.length(); i++) {
	char c = fun.charAt(i);
	switch(c) {
	  case '\n':	o.write('\\');	o.write('n');	break;
	  case '\t':	o.write('\\');	o.write('t');	break;
	  case '\b':	o.write('\\');	o.write('b');	break;
	  case '\r':	o.write('\\');	o.write('r');	break;
	  case '\f':	o.write('\\');	o.write('f');	break;
	  case '\\':	o.write('\\');	o.write('\\');	break;
	  case '\'':	o.write('\\');	o.write('\'');	break;
	  case '\"':	o.write('\\');	o.write('\"');	break;
	  case '!':	case '@':	case '#':	case '$':
	  case '%':	case '^':	case '&':	case '*':
	  case '(':	case ')':	case '-':	case '_':
	  case '+':	case '=':	case '|':	case '~':
	  case '{':	case '}':	case '[':	case ']':
	  case ';':	case ':':	case '<':	case '>':
	  case ',':	case '.':	case '?':       case ' ':
	    o.write(c);
	    break;
	  default:    
	    if(Character.isLetterOrDigit(c)) {
	      o.write(c);
	    } else {
	      o.write('\\');
	      o.write((char)((int)'0' + (int)c/64));
	      c = (char)(c % 64);
	      o.write((char)((int)'0' + (int)c/8));
	      c = (char)(c % 8);
	      o.write((char)((int)'0' + (int)c));
	    }
	}
      }
      o.write('"');
    }
  }

  //}
  //{ private void printFun(PrintWriter w)

  /**
    * Print a function symbol.
    */

  private void printFun(PrintWriter o) 
  {
    if(!quoted) {
      for(int i=0; i<fun.length(); i++)
	o.print(fun.charAt(i));
    } else {
      boolean escaped = false;
      o.print('"');
      for(int i=0; i<fun.length(); i++) {
	char c = fun.charAt(i);
	switch(c) {
	  case '\n':	o.print('\\');	o.print('n');	break;
	  case '\t':	o.print('\\');	o.print('t');	break;
	  case '\b':	o.print('\\');	o.print('b');	break;
	  case '\r':	o.print('\\');	o.print('r');	break;
	  case '\f':	o.print('\\');	o.print('f');	break;
	  case '\\':	o.print('\\');	o.print('\\');	break;
	  case '\'':	o.print('\\');	o.print('\'');	break;
	  case '\"':	o.print('\\');	o.print('\"');	break;
	  case '!':	case '@':	case '#':	case '$':
	  case '%':	case '^':	case '&':	case '*':
	  case '(':	case ')':	case '-':	case '_':
	  case '+':	case '=':	case '|':	case '~':
	  case '{':	case '}':	case '[':	case ']':
	  case ';':	case ':':	case '<':	case '>':
	  case ',':	case '.':	case '?':       case ' ':
	    o.print(c);
	    break;
	  default:    
	    if(Character.isLetterOrDigit(c)) {
	      o.print(c);
	    } else {
	      o.print('\\');
	      o.print((char)((int)'0' + (int)c/64));
	      c = (char)(c % 64);
	      o.print((char)((int)'0' + (int)c/8));
	      c = (char)(c % 8);
	      o.print((char)((int)'0' + (int)c));
	    }
	}
      }
      o.print('"');
    }
  }

  //}
  //{ private int printSizeFun()

  private int printSizeFun() 
  {
    int size = 0;
    
    if(!quoted)
      size = fun.length();
    else {
      boolean escaped = false;
      size++;
      for(int i=0; i<fun.length(); i++) {
	char c = fun.charAt(i);
	switch(c) {
	  case '\n':
	  case '\t':
	  case '\b':
	  case '\r':
	  case '\f':
	  case '\\':
	  case '\'':
	  case '\"':	size += 2;
	    break;
	    
	  case '!':	case '@':	case '#':	case '$':
	  case '%':	case '^':	case '&':	case '*':
	  case '(':	case ')':	case '-':	case '_':
	  case '+':	case '=':	case '|':	case '~':
	  case '{':	case '}':	case '[':	case ']':
	  case ';':	case ':':	case '<':	case '>':
	  case ',':	case '.':	case '?':       case ' ':
	    size++;
	    break;
	  default:	
	    if(Character.isLetterOrDigit(c))
	      size++;	// A simple letter or digit
	    else
	      size += 4;	// An octal number
	}
      }
      size++;
    }
    return size;
  }

  //}
  //{ static boolean needsQuotes(String fn)

  static boolean needsQuotes(String fn)
  {
    if(Character.isLetter(fn.charAt(0)) || fn.charAt(0) == '_') {
      for(int i=1; i<fn.length(); i++) {
	char c = fn.charAt(i);
	if(!Character.isLetterOrDigit(c) && c != '_' && c != '-')
	  return true;
      }
      return false;
    }
    return true;
  }

  //}
}


