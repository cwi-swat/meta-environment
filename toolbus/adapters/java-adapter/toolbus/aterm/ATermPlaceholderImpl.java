
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

/**
  * ATermPlaceholderImpl objects represent placeholder terms of the form <term>.
  */

public class ATermPlaceholderImpl extends ATermImpl
{
  private ATermImpl type;

  //{ public ATermPlaceholderImpl(ATermImpl t, ATermImpl anno)

  public ATermPlaceholderImpl(ATermImpl t, ATermImpl anno)
  {
    super(anno);
    type = t;
    type.increaseRef();
  }

  //}
  //{ public ATermPlaceholderImpl(ATermImpl t)
  
  public ATermPlaceholderImpl(ATermImpl t)
  {
    this(t, null);
  }

  //}
  //{ public Object clone()

  public Object clone()
  {
    ATermPlaceholderImpl place = (ATermPlaceholderImpl)super.clone();
    place.type = type;
    type.increaseRef();
    return place;
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    type.decreaseRef();
    super.finalize();
  }

  //}
  //{ public boolean equals(Object obj)

  public boolean equals(Object obj)
  {
    if(obj instanceof ATermPlaceholderImpl)
      return type == ((ATermPlaceholderImpl)obj).type && super.equals(obj);
    return false;
  }

  //}
  //{ public int hashCode()

  public int hashCode()
  { 
    return type.hashCode() + 123;
  }

  //}
  //{ public int getType()

  public int getType()
  { 
    return ATermImpl.PLACEHOLDER;
  }

  //}
  //{ public ATermImpl getPlaceholderType()

  public ATermImpl getPlaceholderType()
  {
    return type;
  }

  //}
  //{ public void setPlaceholderType(ATermImpl t)

  public void setPlaceholderType(ATermImpl t)
  {
    type.decreaseRef();
    type = t;
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
  //{ public boolean match(ATermImpl trm, Vector subterms)

  public boolean match(ATermImpl term, Vector subterms)
  {
    ATermsImpl termargs;
    String termfun;

    if(type.getType() != ATermImpl.APPL)
      return false;
  
    String fun = ((ATermApplImpl)type).getFun();
    ATermsImpl args = ((ATermApplImpl)type).getArgs();
    if(fun.equals("term")) {
      switch(term.getType()) {
	case ATermImpl.ATERMS:      
	  subterms.addElement(new ATerms((ATermsImpl)term));
	  break;
	case ATermImpl.APPL:
	  subterms.addElement(new ATermAppl((ATermApplImpl)term));
	  break;
	case ATermImpl.LIST:
	  subterms.addElement(new ATermList((ATermListImpl)term));
	  break;
	case ATermImpl.INT:
	  subterms.addElement(new ATermInt((ATermIntImpl)term));
	  break;
	case ATermImpl.REAL:
	  subterms.addElement(new ATermReal((ATermRealImpl)term));
	  break;
	case ATermImpl.PLACEHOLDER: 
	  subterms.addElement(new ATermPlaceholder((ATermPlaceholderImpl)term));
	  break;
      }
      return true;
    }
    switch(term.getType()) {
      //{ case ATermImpl.INT

      case ATermImpl.INT:
	if(fun.equals("int")) {
	  subterms.addElement(new Integer(((ATermIntImpl)term).getInt()));
	  return true;
	}
	break;

	//}
      //{ case ATerm.REAL

      case ATermImpl.REAL:
	if(fun.equals("real")) {
	  subterms.addElement(new Double(((ATermRealImpl)term).getReal()));
	  return true;
	}
	break;
	
	//}
      //{ case ATerm.LIST

      case ATermImpl.LIST:
	if(fun.equals("list")) {
	  subterms.addElement(new ATermList((ATermListImpl)term));
	  return true;
	}
	break;

	//}
      //{ case ATerm.ATERMS

      case ATermImpl.ATERMS:
	if(fun.equals("terms")) {
	  subterms.addElement(new ATerms((ATermsImpl)term));
	  return true;
	}
	break;

	//}
      //{ case ATerm.PLACEHOLDER

      case ATermImpl.PLACEHOLDER:
	if(fun.equals("placeholder")) {
	  subterms.addElement(new ATermPlaceholder((ATermPlaceholderImpl)term));
	  return true;
	}
	break;

	//}
      //{ case ATerm.APPL

      case ATermImpl.APPL:
	termargs = ((ATermApplImpl)term).getArgs();
	termfun  = ((ATermApplImpl)term).getFun();
	if(fun.equals("appl")) {
	  subterms.addElement(new ATermAppl((ATermApplImpl)term));
	  return true;
	}
	
	if(fun.equals("str")) {
	  if(!((ATermApplImpl)term).isQuoted())
	    return false;
	}
	
	if(fun.equals("fun") || fun.equals("str")) {
	  if(!args.isEmpty()) {
	    if(termargs.isEmpty())
	      return false;
	    subterms.addElement(termfun);
	    return args.match(termargs, subterms);
	  }
	  if(!termargs.isEmpty())
	    return false;
	  subterms.addElement(termfun);
	  return true;
	}
	
	if(fun.equals("bool")) {
	  if(termargs.isEmpty()) {
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

	// Another application, make sure it matches with the
	// function symbol we are looking for.
	if(fun.equals(termfun)) {
	  subterms.addElement(new ATermAppl((ATermApplImpl)term));
	  if(args.isEmpty())
	    return true;
	  return args.match(termargs, subterms);
	}
	break;

	//}
    }
    return false;
  }

  //}
}
