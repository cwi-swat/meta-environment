
package toolbus.aterm;
import java.io.*;
import java.util.Stack;

public class ATermParser
{
  //{ public static ATermRef parse(InputStream i)

  /**
    * Parse a term from an input stream.
    */

  public static ATermRef parse(InputStream i)
    throws IOException, ParseError
  {
    InputChannel channel = new InputChannel(i);
    
    channel.reset();
    channel.read();
    return parseATerm(channel);
  }

  //}

  //{ public static ATermRef parseATerm(ATermChannel channel)

  public static ATermRef parseATerm(ATermChannel channel)
    throws IOException, ParseError
  {
    ATermRef result, type;
    ATermsRef terms;
    String fun;

    switch(channel.last()) {
      case '[':	
	if(channel.readNext() == ']') {
	  channel.readNext();
	  result = new ATermListRef((ATermsRef)null);
	} else {
	  terms = parseATerms(channel);
	  if(channel.last() != ']')
	    throw new ParseError(channel, channel.last(), "']' expected");
	  channel.readNext();
	  result = new ATermListRef(terms);
	}
	break;
      case '<':
	channel.readNext();
	type = parseATerm(channel);
	if(channel.last() != '>')
	  throw new ParseError(channel, channel.last(), "'>' expected");
	result = new ATermPlaceholderRef(type);
	channel.readNext();
	break;
      case '"':
	fun = parseQuotedId(channel);
	if(channel.last() == '(') {
	  channel.readNext();
	  terms = parseATerms(channel);
	  if(channel.last() != ')')
	    throw new ParseError(channel, channel.last(), "')' expected");
	  result = new ATermApplRef(fun, terms, true);
	  channel.readNext();
	} else
	  result = new ATermApplRef(fun, null, true);
	break;
      case '-':
      case '0':	case '1':	case '2': 	case '3': 	case '4':
      case '5':	case '6':	case '7':	case '8':	case '9':
	result = parseNumber(channel);
	break;
      default:
	if(Character.isLetter((char)channel.last()) ||
	   channel.last() == '_') {
	  fun = parseId(channel);
	  if(channel.last() == '(') {
	    channel.readNext();
	    terms = parseATerms(channel);
	    if(channel.last() != ')')
	      throw new ParseError(channel, channel.last(), "')' expected");
	    result = new ATermApplRef(fun, terms, false);
	    channel.readNext();
	  } else
	    result = new ATermApplRef(fun, null, false);
	} else {
	  throw new ParseError(channel, channel.last(), "illegal character");
	}
    }
    return result;
  }

  //}
  //{ private static ATermsRef parseATerms(ATermChannel channel)

  private static ATermsRef parseATerms(ATermChannel channel)
    throws IOException, ParseError
  {
    Stack stack = new Stack();
    
    stack.push(parseATerm(channel));
    while(channel.last() == ',') {
      channel.readNext();
      stack.push(parseATerm(channel));
    }
    ATermsRef result = null;
    while(!stack.empty())
      result = new ATermsRef((ATermRef)stack.pop(), result);
    return result;
  }

  //}
  //{ static String parseId(ATermChannel channel)

  private static String parseId(ATermChannel channel)
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
  //{ static String parseQuotedId(ATermChannel channel)
  
  private static String parseQuotedId(ATermChannel channel)
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
  //{ static ATermRef parseNumber(ATermChannel channel)

/**
  * Parse a number. This function can eiter return an ATermInt,
  * or an ATermReal.
  */

  private static ATermRef parseNumber(ATermChannel channel)
    throws ParseError, IOException
  {
    StringBuffer str = new StringBuffer();
    ATermRef result;

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
      result = new ATermIntRef(val);
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
      result = new ATermRealRef(val);    
    }
    return result;
  }

  //}

  //{ static ATermRef makeSimple(String s)

  static public ATermRef makeSimple(String s)
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
