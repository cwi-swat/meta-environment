
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

/**
  * ATermPlaceholder objects represent placeholder terms of the form <term>.
  */

public class ATermPlaceholder extends ATerm
{
  private ATerm type;

  //{ public ATermPlaceholder(ATerm t, ATerm anno)

  public ATermPlaceholder(ATerm t, ATerm anno)
  {
    super(anno);
    type = t;
    if(type != null)
      type.increaseRef();
  }

  //}
  //{ public ATermPlaceholder(ATerm t)
  
  public ATermPlaceholder(ATerm t)
  {
    this(t, null);
  }

  //}
  //{ public Object clone()

  public Object clone()
  {
    ATermPlaceholder place = (ATermPlaceholder)super.clone();
    place.type = type;
    if(type != null)
      type.increaseRef();
    return place;
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    if(type != null)
      type.decreaseRef();
    super.finalize();
  }

  //}
  //{ public boolean equals(Object obj)

  public boolean equals(Object obj)
  {
    if(obj instanceof ATermPlaceholder)
      return type == ((ATermPlaceholder)obj).type && super.equals(obj);
    return false;
  }

  //}
  //{ public int hashCode()

  public int hashCode()
  { 
    return type.hashCode() ^ 123;
  }

  //}
  //{ public int getType()

  public int getType()
  { 
    return ATerm.PLACEHOLDER;
  }

  //}
  //{ public ATerm getPlaceholderType()

  public ATerm getPlaceholderType()
  {
    return type;
  }

  //}
  //{ public void setPlaceholderType(ATerm t)

  public void setPlaceholderType(ATerm t)
  {
    if(type != null)
      type.decreaseRef();
    type = t;
    if(type != null)
      type.increaseRef();
  }

  //}
  //{ public void write(OutputStream o)

  public void write(OutputStream o)
    throws java.io.IOException
  {
    o.write('<');
    type.write(o);
    o.write('>');
    super.write(o);
  }

  //}
  //{ public void print(PrintWriter w)

  public void print(PrintWriter w)
  {
    w.print('<');
    type.print(w);
    w.print('>');
    super.print(w);
  }

  //}
  //{ public int printSize()

  public int printSize()
  {
    return super.printSize()+2+type.printSize();
  }

  //}
  //{ public int size()

  public int size()
  { 
    return 1 + super.size() + type.size();
  }

  //}
  //{ public boolean match(ATerm trm, Vector subterms)

  public boolean match(ATerm term, Vector subterms)
  {
    ATerm termargs;
    String termfun;

    switch(type.getType()) {
      case ATerm.APPL:	break;
      default:		return false;
    }
  
    String fun = ((ATermAppl)type).getFun();
    ATerms args = ((ATermAppl)type).getArgs();
    if(fun.equals("term")) {
      switch(term.getType()) {
	case ATerm.ATERMS:      
	  subterms.addElement(new ATermsRef((ATerms)term));
	  break;
	case ATerm.APPL:
	  subterms.addElement(new ATermApplRef((ATermAppl)term));
	  break;
	case ATerm.LIST:
	  subterms.addElement(new ATermListRef((ATermList)term));
	  break;
	case ATerm.INT:
	  subterms.addElement(new ATermIntRef((ATermInt)term));
	  break;
	case ATerm.REAL:
	  subterms.addElement(new ATermRealRef((ATermReal)term));
	  break;
	case ATerm.PLACEHOLDER: 
	  subterms.addElement(new ATermPlaceholderRef((ATermPlaceholder)term));
	  break;
      }
      return true;
    }
    switch(term.getType()) {
      //{ case ATerm.INT

      case ATerm.INT:
	if(fun.equals("int")) {
	  subterms.addElement(new Integer(((ATermInt)term).getInt()));
	  return true;
	}
	break;

	//}
      //{ case ATerm.REAL

      case ATerm.REAL:
	if(fun.equals("real")) {
	  subterms.addElement(new Double(((ATermReal)term).getReal()));
	  return true;
	}
	break;
	
	//}
      //{ case ATerm.LIST

      case ATerm.LIST:
	if(fun.equals("list")) {
	  subterms.addElement(new ATermListRef((ATermList)term));
	  return true;
	}
	break;

	//}
      //{ case ATerm.ATERMS

      case ATerm.ATERMS:
	if(fun.equals("terms")) {
	  subterms.addElement(new ATermsRef((ATerms)term));
	  return true;
	}
	break;

	//}
      //{ case ATerm.PLACEHOLDER

      case ATerm.PLACEHOLDER:
	if(fun.equals("placeholder")) {
	  subterms.addElement(new ATermPlaceholderRef((ATermPlaceholder)term));
	  return true;
	}
	break;

	//}
      //{ case ATerm.APPL

      case ATerm.APPL:
	termargs = ((ATermAppl)term).getArgs();
	termfun  = ((ATermAppl)term).getFun();
	if(fun.equals("appl")) {
	  subterms.addElement(new ATermApplRef((ATermAppl)term));
	  return true;
	}
	
	if(fun.equals("str")) {
	  if(!((ATermAppl)term).isQuoted())
	    return false;
	}
	
	if(fun.equals("fun") || fun.equals("str")) {
	  if(args != null) {
	    if(termargs == null)
	      return false;
	    subterms.addElement(termfun);
	    return args.match(termargs, subterms);
	  }
	  if(termargs != null)
	    return false;
	  subterms.addElement(termfun);
	  return true;
	}
	
	if(fun.equals("bool")) {
	  if(termargs == null) {
	    if(termfun.equals("true")) {
	      subterms.addElement(new Boolean(true));
	      return true;
	    } else if(termfun.equals("false")) {
	      subterms.addElement(new Boolean(false));
	      return true;
	    }
	  }
	  return false;
	}
	break;

	//}
    }
    return false;
  }

  //}
}
