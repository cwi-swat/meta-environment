package toolbus.aterm;

import toolbus.util.SimpleHashtable;
import toolbus.util.SimpleHashtableEntry;
import java.util.*;
import java.io.*;

public class World
{
  private int table_size;
  private SimpleHashtable table;
  public ATermsImpl emptyImpl;
  public ATerms empty;

  //{ public World(int table_size)

  /**
    * Build a new term world.
    */

  public World(int table_size)
  {
    this.table_size = table_size;
    table = new SimpleHashtable(43117);
    emptyImpl = (ATermsImpl)intern(new ATermsImpl(this));
    empty = new ATerms(emptyImpl);
  }

  //}
  //{ synchronized ATermImpl intern(ATermImpl term)

  /**
    * Return a unique representation of a term.
    */

  synchronized public ATermImpl intern(ATermImpl term)
  {
    ATermImpl result = (ATermImpl)table.get(term);
    if(result == null) {
      table.put(term);
      return term;
    }
    return result;
  }

  //}
  //{ public void remove(ATermImpl term)

  /**
    * Remove a term.
    */

  public void remove(ATermImpl term)
  {
    table.remove(term);
  }

  //}  

  //{ public ATermAppl makeAppl(String fun)

  /**
    * Create a new ATermAppl.
    */

  public ATermAppl makeAppl(String fun)
  {
    ATermAppl appl = new ATermAppl(this);
    appl.intern(new ATermApplImpl(this, fun));
    return appl;
  }

  //}
  //{ public ATermAppl makeAppl(String fun, ATerms args)

  /**
    * Create a new ATermAppl.
    */

  public ATermAppl makeAppl(String fun, ATerms args)
  {
    ATermAppl appl = new ATermAppl(this);
    appl.intern(new ATermApplImpl(this, fun, args.getATermsImpl()));
    return appl;
  }

  //}
  //{ public ATermAppl makeAppl(String fun, ATerms args, ATerm anno)

  /**
    * Create a new ATermAppl.
    */

  public ATermAppl makeAppl(String fun, ATerms args, ATerm anno)
  {
    ATermAppl appl = new ATermAppl(this);
    appl.intern(new ATermApplImpl(this, fun, args.getATermsImpl(), 
				  anno == null ? null : anno.getATermImpl()));
    return appl;
  }

  //}
  //{ public ATermAppl makeAppl(String fun, ATerms args, ATerm anno, isquoted)

  /**
    * Create a new ATermAppl.
    */

  public ATermAppl makeAppl(String fun, ATerms args, ATerm anno, boolean iq)
  {
    ATermAppl appl = new ATermAppl(this);
    appl.intern(new ATermApplImpl(this, fun, args.getATermsImpl(), 
				  anno == null ? null : anno.getATermImpl(),
				  iq));
    return appl;
  }

  //}

  //{ public ATermList makeList(ATerms terms)

  /**
    * Build a ATermList object.
    */

  public ATermList makeList(ATerms terms)
  {
    ATermList list = new ATermList(this);
    list.intern(new ATermListImpl(this, terms.getATermsImpl()));
    return list;
  }

  //}
  //{ public ATermList makeList(ATerms terms, ATerm anno)

  /**
    * Build a ATermList object.
    */

  public ATermList makeList(ATerms terms, ATerm anno)
  {
    ATermList list = new ATermList(this);
    list.intern(new ATermListImpl(this, terms.getATermsImpl(), 
				  anno == null ? null : anno.getATermImpl()));
    return list;
  }

  //}

  //{ public ATerms makeATerms()

  /**
    * Retrieve the empty list.
    */

  public ATerms makeATerms()
  {
    return empty;
  }

  //}
  //{ public ATerms makeATerms(ATerm el)

  /**
    * Build a list consisting of one element.
    */

  public ATerms makeATerms(ATerm el)
  {
    ATerms terms = new ATerms(this);
    terms.intern(new ATermsImpl(this, el.getATermImpl()));
    return terms;
  }

  //}
  //{ public ATerms makeATerms(ATerm first, ATerms next)

  /**
    * Build a list consisting of a head and a tail.
    */

  public ATerms makeATerms(ATerm first, ATerms next)
  {
    ATerms terms = new ATerms(this);
    terms.intern(new ATermsImpl(this, first.getATermImpl(), next.getATermsImpl()));
    return terms;
  }

  //}
  //{ public ATerms makeATerms(ATerm first, ATerms next, ATerm anno)

  /**
    * Build a list consisting of a head and a tail.
    */

  public ATerms makeATerms(ATerm first, ATerms next, ATerm anno)
  {
    ATerms terms = new ATerms(this);
    terms.intern(new ATermsImpl(this, first.getATermImpl(), 
				next.getATermsImpl(), 
				anno == null ? null : anno.getATermImpl()));
    return terms;
  }

  //}

  //{ public ATermInt makeInt(int i)

  public ATermInt makeInt(int i)
  {
    ATermInt term = new ATermInt(this);
    term.intern(new ATermIntImpl(this, i));
    return term;
  }

  //}
  //{ public ATermInt makeInt(int i, ATerm anno)

  public ATermInt makeInt(int i, ATerm anno)
  {
    ATermInt term = new ATermInt(this);
    term.intern(new ATermIntImpl(this, i, anno == null ? null : anno.getATermImpl()));
    return term;
  }

  //}

  //{ public ATermReal makeReal(double d)

  public ATermReal makeReal(double d)
  {
    ATermReal term = new ATermReal(this);
    term.intern(new ATermRealImpl(this, d));
    return term;
  }

  //}
  //{ public ATermReal makeReal(double d, ATerm anno)

  public ATermReal makeReal(double d, ATerm anno)
  {
    ATermReal term = new ATermReal(this);
    term.intern(new ATermRealImpl(this, d, anno == null ? null : anno.getATermImpl()));
    return term;
  }

  //}

  //{ public ATermPlaceholder makePlaceholder(ATerm type)

  public ATermPlaceholder makePlaceholder(ATerm type)
  {
    ATermPlaceholder placeholder = new ATermPlaceholder(this);
    placeholder.intern(new ATermPlaceholderImpl(this, type.getATermImpl()));
    return placeholder;
  }

  //}
  //{ public ATermPlaceholder makePlaceholder(ATerm type, ATerm anno)

  public ATermPlaceholder makePlaceholder(ATerm type, ATerm anno)
  {
    ATermPlaceholder placeholder = new ATermPlaceholder(this);
    placeholder.intern(new ATermPlaceholderImpl(this, type.getATermImpl(),
						anno == null ? null : anno.getATermImpl()));
    return placeholder;
  }

  //}

  //{ public ATerm makeSimple(String s)

  public ATerm makeSimple(String s)
    throws ParseError
  {
    byte[] array = new byte[s.length()]; // jdk 1.02
    s.getBytes(0, s.length(), array, 0);

    // byte[] array = s.getBytes(); // jdk 1.1

    ByteArrayInputStream stream = new ByteArrayInputStream(array);
    try {
      return parse(stream);
    } catch (IOException e) {
      throw new ParseError(null, -1, "unexpected end of string");
    }
  }

  //}
  //{ public ATermPattern makePattern(String s)

  public ATermPattern makePattern(String s)
    throws ParseError
  {
    return new ATermPattern(makeSimple(s));
  }

  //}

  //{ public ATerm parse(InputStream i)

  /**
    * Parse an ATerm coming from an InputStream.
    * @exception IOException When a read error is encountered 
    * @exception ParseError When the input read from inputstream
    *            does not constitute a valid term.
    */

  public ATerm parse(InputStream i)
    throws IOException, ParseError
  {
    InputChannel channel = new InputChannel(i);
    
    channel.reset();
    channel.read();
    return parseATerm(channel);
  }


  //}
  //{ public ATerm parseATerm(ATermChannel channel)

  public ATerm parseATerm(ATermChannel channel)
    throws IOException, ParseError
  {
    ATerm result, type;
    ATerms terms;
    String fun;

    switch(channel.last()) {
      case '[':	
	//{ Read a list

	if(channel.readNext() == ']') {
	  channel.readNext();
	  result = makeList(empty);
	} else {
	  terms = parseATerms(channel);
	  if(channel.last() != ']')
	    throw new ParseError(channel, channel.last(), "']' expected");
	  channel.readNext();
	  result = makeList(terms);
	}

	//}
	break;
      case '<':
	//{ Read a placeholder

	channel.readNext();
	type = parseATerm(channel);
	if(channel.last() != '>')
	  throw new ParseError(channel, channel.last(), "'>' expected");
	result = makePlaceholder(type);
	channel.readNext();

	//}
	break;
      case '"':
	//{ Read a quoted function

	fun = parseQuotedId(channel);
	if(channel.last() == '(') {
	  channel.readNext();
	  terms = parseATerms(channel);
	  if(channel.last() != ')')
	    throw new ParseError(channel, channel.last(), "')' expected");
	  result = makeAppl(fun, terms, null, true);
	  channel.readNext();
	} else
	  result = makeAppl(fun, empty, null, true);

	//}
	break;
      case '-':
      case '0':	case '1':	case '2': 	case '3': 	case '4':
      case '5':	case '6':	case '7':	case '8':	case '9':
	result = parseNumber(channel);
	break;
      default:
	if(Character.isLetter((char)channel.last()) ||
	   //{ Parse an unquoted function

	   channel.last() == '_') {
	  fun = parseId(channel);
	  if(channel.last() == '(') {
	    channel.readNext();
	    terms = parseATerms(channel);
	    if(channel.last() != ')')
	      throw new ParseError(channel, channel.last(), "')' expected");
	    result = makeAppl(fun, terms, null, false);
	    channel.readNext();

	  } else
	    result = makeAppl(fun, empty, null, false);
	  //}
	} else {
	  throw new ParseError(channel, channel.last(), "illegal character");
	}
    }
    return result;
  }

  //}
  //{ private ATerms parseATerms(ATermChannel channel)

  private ATerms parseATerms(ATermChannel channel)
    throws IOException, ParseError
  {
    Stack stack = new Stack();
    
    stack.push(parseATerm(channel));
    while(channel.last() == ',') {
      channel.readNext();
      stack.push(parseATerm(channel));
    }
    ATerms result = empty;
    while(!stack.empty())
      result = makeATerms((ATerm)stack.pop(), result);
    return result;
  }

  //}
  //{ private String parseId(ATermChannel channel)

  private String parseId(ATermChannel channel)
    throws IOException
  {
    StringBuffer str = new StringBuffer();
    
    do {
      str.append((char)channel.last());
      channel.read();    
    } while(Character.isLetterOrDigit((char)channel.last()) || 
	    channel.last() == '-' || channel.last() == '_');
    channel.skipWhitespace();
    return str.toString();
  }

  //}
  //{ private String parseQuotedId(ATermChannel channel)
  
  private String parseQuotedId(ATermChannel channel)
    throws IOException, ParseError
  {
    boolean escaped;
    StringBuffer str = new StringBuffer();
    
    do {
      escaped = false;
      if(channel.read() == '\\') {
	channel.read();
	escaped = true;
      }

      if(escaped) {
	switch(channel.last()) {
	  case 'n':	str.append('\n');	break;
	  case 't':	str.append('\t');	break;
	  case 'b':	str.append('\b');	break;
	  case 'r':	str.append('\r');	break;
	  case 'f':	str.append('\f');	break;
	  case '\\':	str.append('\\');	break;
	  case '\'':	str.append('\'');	break;
	  case '\"':	str.append('\"');	break;
	  case '0':	case '1':	case '2':	case '3':
	  case '4':	case '5':	case '6':	case '7':
	    str.append(channel.readOct());
	    break;
	  default:	str.append('\\').append(channel.last());
	} 
      } else if(channel.last() != '\"')
	str.append(channel.last());
    } while(escaped || channel.last() != '"');
    channel.readNext();
    return str.toString();
  }

  //}
  //{ private ATerm parseNumber(ATermChannel channel)

/**
  * Parse a number. This function can eiter return an ATermInt,
  * or an ATermReal.
  */

  private ATerm parseNumber(ATermChannel channel)
    throws ParseError, IOException
  {
    StringBuffer str = new StringBuffer();
    ATerm result;

    do {
      str.append(channel.last());
    } while(Character.isDigit((char)channel.read()));
    if(channel.last() != '.' && 
       channel.last() != 'e' && channel.last() != 'E') {
      int val;
      try {
	val = Integer.parseInt(str.toString());
      } catch (NumberFormatException e) {
	throw new ParseError(channel, channel.last(), "malformed int");
      }
      result = makeInt(val);
    } else {
      if(channel.last() == '.') {
	str.append('.');
	channel.read();
	if(!Character.isDigit((char)channel.last()))
	  throw new ParseError(channel, channel.last(), "digit expected");
	do {
	  str.append(channel.last());
	} while(Character.isDigit((char)channel.read()));
      }
      if(channel.last() == 'e' || channel.last() == 'E') {
	str.append(channel.last());
	channel.read();
	if(channel.last() == '-') {
	  str.append('-');
	  channel.read();
	}
	if(!Character.isDigit((char)channel.last()))
	  throw new ParseError(channel, channel.last(), "digit expected!");
	do {
	  str.append(channel.last());
	} while(Character.isDigit((char)channel.read()));
      }
      double val;
      try {
	val = Double.valueOf(str.toString()).doubleValue();
      } catch (NumberFormatException e) {
	throw new ParseError(channel, channel.last(), "malformed real");
      }
      result = makeReal(val);    
    }
    return result;
  }

  //}
}

//{ class InputChannel

class InputChannel extends ATermChannel
{
  private InputStream Stream;
  
  public InputChannel(java.io.InputStream strm)	{ Stream = strm; }
  public InputStream stream()	{ return Stream; }
  
  public int read()
    throws IOException
  {
    lastChar = (char)Stream.read();
    return lastChar;
  }  
}

//}
