
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

/**
  * The class ATerms is the binary list constructor for aterms.
  */

public class ATerms extends ATerm
{
  private ATerm first;
  private ATerms next;
  private int hashcode;

  //{ public ATerms(ATerm f, ATerms n, ATerm anno)

  /**
    * Construct a new list from a first element and a tail.
    */

  public ATerms(ATerm f, ATerms n, ATerm an)
  {
    super(an);
    first = f;
    next = n;
    updateHashCode();
    first.increaseRef();
    if(next != null)
      next.increaseRef();
  }

  //}
  //{ public ATerms(ATerm f, ATerms n)
  
  /**
    * Construct a new list from a first element and a tail.
    */

  public ATerms(ATerm f, ATerms n)
  {
    this(f, n, null);
  }

  //}
  //{ public Object clone()

/**
  * Cloning of ATerms amounts to making a SHALLOW copy.
  */

  public Object clone()
  {
    ATerms terms = (ATerms)super.clone();
    terms.first = first;
    terms.next = next;
    terms.hashcode = hashcode;
    first.increaseRef();
    if(next != null)
      next.increaseRef();
    return terms;
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    first.decreaseRef();
    if(next != null)
      next.decreaseRef();
    super.finalize();
  }

  //}

  //{ public boolean equals(Object obj)

/**
  * Implement equality on ATerms.
  */

  public boolean equals(Object obj)
  {
    if(obj instanceof ATerms)
      return ((ATerms)obj).first == first && ((ATerms)obj).next == next &&
	super.equals(obj);
    return false;
  }

  //}
  //{ protected void updateHashCode()

  /**
    * Calculate the hash-code of this term.
    */
  protected void updateHashCode()
  {
    hashcode = first.hashCode() + (next == null ? 371 : next.hashCode());
  }

  //}
  //{ public int hashCode()
  
  public int hashCode()
  {
    return hashcode;
  }

  //}
  //{ public int getType()

  public int getType()
  {
    return ATERMS;
  }

  //}
  //{ public ATerm getFirst()

  /**
    * Retrieve the first element of a list.
    */

  public ATerm getFirst()
  {
    return first;
  }

  //}
  //{ public ATerms getNext()

  /**
    * Retrieve the tail of a list.
    */

  public ATerms getNext()
  {
    return next;
  }

  //}
  //{ public void setFirst(ATerm frst)

  /**
    * Change the first element of a list.
    */

  public void setFirst(ATerm frst)
  {
    first.decreaseRef();
    first = frst;
    first.increaseRef();
    updateHashCode();
  }

  //}
  //{ public void setNext(ATerms nxt)

  /**
    * Change the tail of a list.
    */

  public void setNext(ATerms nxt)
  {
    if(next != null)
      next.decreaseRef();
    next = nxt;
    if(next != null)
      next.increaseRef();
    updateHashCode();
  }

  //}
  //{ public void write(OutputStream o) 

  /**
    * Write a list to an OutputStream.
    */

  public void write(OutputStream o) 
    throws java.io.IOException
  { 
    first.write(o);
    if(next != null) {
      o.write(',');
      next.write(o);
    }
    super.write(o);
  }

  //}
  //{ public void print(PrintWriter w) 

  /**
    * Print a list.
    */

  public void print(PrintWriter w) 
  { 
    first.print(w);
    if(next != null) {
      w.print(',');
      next.print(w);
    }
    super.print(w);
  }

  //}
  //{ public int printSize()

  public int printSize()
  {
    int size = super.printSize();
    size += first.printSize();
    if(next != null) {
      size++;	// The ',' separating first from next
      size += next.printSize();
    }
    return size;
  }

  //}
  //{ public int size()

  /**
    * Calculate the size of a list (total number of nodes in the
    * list and all of its subterms).
    */

  public int size()
  {
    int size = super.size() + first.size() + 1;
    if(next != null)
      size += next.size();
    return size;
  }

  //}
  //{ public int length()

  /**
    * Calculate the length of a list.
    */

  public int length()
  {
    int length = 1;
    ATerms tail = next;
    while(tail != null) {
      tail = tail.next;
      length++;
    }
    return length;
  }

  //}
  //{ public ATerms concat(ATerms rhs)

  /** 
    * Concatenate two ATerms and return the result.
    */

  public ATerms concat(ATerms rhs)
  {
    if(next == null)
      return (ATerms)(new ATerms(first, rhs)).unique();
    return (ATerms)(new ATerms(first, next.concat(rhs))).unique();
  }

  //}

  //{ public boolean match(ATerm trm, Vector subterms)

  /**
    * Match against {\tt trm}, using {\tt this} as a placeholder term.
    */

  public boolean match(ATerm trm, Vector subterms)
  {
    if(trm.getType() == ATerm.ATERMS) {
      // First we need to handle the special case where the pattern <term>
      // is used.
      if(first.getType() == ATerm.PLACEHOLDER) {
	ATerm ph = ((ATermPlaceholder)first).getPlaceholderType();
	if(ph.getType() == ATerm.APPL) {
	  ATermAppl appl = (ATermAppl)ph;
	  if(appl.getFun().equals("terms") && appl.getArgs() == null) {
	    subterms.addElement(new ATermsRef((ATerms)trm));
	    return true;
	  }
	}
      }
      
      // Just match the first element and the tail.
      if(!first.match(((ATerms)trm).first, subterms))
	return false;
      
      if(next != null) {
	if(((ATerms)trm).next != null)
	  return next.match(((ATerms)trm).next, subterms);
	return false;
      }
      return ((ATerms)trm).next == null;
    }
    return false;
  }

//}
}


