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

/**
  * ATermAppl objects represent function application terms.
  *
  */

public class ATermApplImpl extends ATermImpl
{
  protected int hashcode;
  private String fun;
  private ATermsImpl args;
  private boolean quoted;

  //{ public ATermApplImpl(World world, String fn)

  public ATermApplImpl(World world, String fn)
  {
    this(world, fn, world.emptyImpl, null);
  }

  //}
  //{ public ATermApplImpl(World world, String fn, ATermsImpl as)

  public ATermApplImpl(World world, String fn, ATermsImpl as)
  {
    this(world, fn, as, null);
  }

  //}

    /** ATermApplImpl can have a quoted function symbol
     */
    public ATermApplImpl(World world, String fn, ATermsImpl as, boolean iq) {
	this(world,fn,as,null,iq);
    }
  //{ public ATermApplImpl(World world, String fn, ATermsImpl as, ATermImpl an)

  public ATermApplImpl(World world, String fn, ATermsImpl as, ATermImpl an)
  {
    super(world, an);
    fun = fn.intern();
    args = as;  
    quoted = needsQuotes(fn);
    updateHashCode();
    args.increaseRef();
  }

  //}
  //{ public ATermApplImpl(World world, String fn, ATermsImpl as, ATermImpl an, boolean iq)

 public ATermApplImpl(World world, String fn, ATermsImpl as, 
		      ATermImpl an, boolean isquoted)
  {
    super(world, an);
    fun = fn.intern();
    args = as;
    quoted = isquoted;
    updateHashCode();
    args.increaseRef();
  }

  //}

  //{ public Object clone()

  /**
    * Make a SHALLOW copy of an ATermAppl.
    */

  public Object clone()
  {
    ATermApplImpl appl = (ATermApplImpl)super.clone();
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
    args.decreaseRef();
    super.finalize();
  }

  //}

  //{ public boolean equals(Object obj)

  public boolean equals(Object obj)
  {
    if(obj instanceof ATermApplImpl)
      return fun == ((ATermApplImpl)obj).fun && args == ((ATermApplImpl)obj).args &&
	quoted == ((ATermApplImpl)obj).quoted && super.equals(obj);
    return false;
  }

  //}
  //{ public int getType()

  public int getType()
  {
    return ATermImpl.APPL;
  }

  //}
  //{ private int updateHashCode()

  private void updateHashCode()
  {
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
  //{ public ATermsImpl getArgs()

  public ATermsImpl getArgs()
  {
    return args;
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
    return 1 + super.size() + args.size();
  }

  //}
  //{ public void write(OutputStream o) 

  public void write(OutputStream o) 
    throws java.io.IOException
  {
    writeFun(o);
    if(!args.isEmpty()) {
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
    if(!args.isEmpty()) {
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
    if(!args.isEmpty())
      size += args.printSize()+2;  // Don't forget the '(' and ')' characters.
    return size;
  }

  //}

  //{ public boolean match(ATermImpl trm, Vector subterms)

  public boolean match(ATermImpl trm, Vector subterms)
  {
    if(trm.getType() == ATermImpl.APPL) {
      ATermApplImpl ap = (ATermApplImpl)trm;
      if(ap.getFun() == getFun())
	 return getArgs().match(ap.getArgs(), subterms);
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
    //Added fn.length() == 0 test. If the string is the empty string,
    //it definitely needs quotes --Tobias
    if(fn.length() == 0 || Character.isLetter(fn.charAt(0)) || fn.charAt(0) == '_') {
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


