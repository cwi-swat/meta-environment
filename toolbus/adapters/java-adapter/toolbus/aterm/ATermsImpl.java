
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

/**
  * The class ATermsImpl is the binary list constructor for aterms.
  */

public class ATermsImpl extends ATermImpl
{
  private ATermImpl first;
  private ATermsImpl next;
  private int hashcode;

  //{ public ATermsImpl(World world, ATermImpl f, ATermsImpl n, ATermImpl anno)

  /**
    * Construct a new list from a first element and a tail.
    */

  public ATermsImpl(World world, ATermImpl f, ATermsImpl n, ATermImpl an)
  {
    super(world, an);
    first = f;
    next = n;
    updateHashCode();
    if(first != null) {
      first.increaseRef();
      next.increaseRef();
    }
  }

  //}
  //{ public ATermsImpl(World world, ATermImpl f, ATermsImpl n)
  
  /**
    * Construct a new list from a first element and a tail.
    */

  public ATermsImpl(World world, ATermImpl f, ATermsImpl n)
  {
    this(world, f, n, null);
  }

  //}
  //{ public ATermsImpl(World world, ATermImpl el)
  
  /**
    * Construct a new list consisting of one element.
    */

  public ATermsImpl(World world, ATermImpl el)
  {
    this(world, el, world.emptyImpl, null);
  }

  //}
  //{ public ATermsImpl(World world)

  /**
    * Construct the empty list.
    */

  public ATermsImpl(World world)
  {
    super(world, null);
  }

  //}
  //{ public Object clone()

/**
  * Cloning of ATerms amounts to making a SHALLOW copy.
  */

  public Object clone()
  {
    ATermsImpl terms = (ATermsImpl)super.clone();
    terms.first = first;
    terms.next = next;
    terms.hashcode = hashcode;
    if(first != null) {
      first.increaseRef();
      next.increaseRef();
    }
    return terms;
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    if(first != null) {
      first.decreaseRef();
      next.decreaseRef();
    }
    super.finalize();
  }

  //}

  //{ public boolean equals(Object obj)

/**
  * Implement equality on ATerms.
  */

  public boolean equals(Object obj)
  {
    if(obj instanceof ATermsImpl)
      return ((ATermsImpl)obj).first == first && ((ATermsImpl)obj).next == next &&
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
    hashcode = first == null ? 371 : (first.hashCode() + next.hashCode());
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
  //{ public boolean isEmpty()

  /**
    * Check if an object represents the empty list.
    */

  public boolean isEmpty()
  {
    return first == null && next == null;
  }

  //}
  //{ public ATermImpl getFirst()

  /**
    * Retrieve the first element of a list.
    */

  public ATermImpl getFirst()
  {
    return first;
  }

  //}
  //{ public ATermsImpl getNext()

  /**
    * Retrieve the tail of a list.
    */

  public ATermsImpl getNext()
  {
    return next;
  }

  //}
  //{ public void write(OutputStream o) 

  /**
    * Write a list to an OutputStream.
    */

  public void write(OutputStream o) 
    throws java.io.IOException
  { 
    if(first != null) {
      first.write(o);
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
    if(first != null) {
      first.print(w);
      if(!next.isEmpty()) {
	w.print(',');
	next.print(w);
      }
    }
    super.print(w);
  }

  //}
  //{ public int printSize()

  public int printSize()
  {
    int size = super.printSize();
    if(first != null) {
      size += first.printSize();
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
    int size = super.size() + 1;
    if(first != null)
      size += next.size() + first.size();
    return size;
  }

  //}
  //{ public int length()

  /**
    * Calculate the length of a list.
    */

  public int length()
  {
    if(first == null)
      return 0;

    int length = 1;
    ATermsImpl tail = next;
    while(!tail.isEmpty()) {
      tail = tail.next;
      length++;
    }
    return length;
  }

  //}
  //{ public ATermsImpl concat(ATermsImpl rhs)

  /** 
    * Concatenate two ATerms and return the result.
    */

  public ATermsImpl concat(ATermsImpl rhs)
  {
    if(first == null)
      return rhs;

    return (ATermsImpl)world.intern(new ATermsImpl(world, first, 
						   next.concat(rhs)));
  }

  //}

  //{ public boolean match(ATermImpl trm, Vector subterms)

  /**
    * Match against {\tt trm}, using {\tt this} as a placeholder term.
    */

  public boolean match(ATermImpl trm, Vector subterms)
  {
    if(trm.getType() == ATermImpl.ATERMS) {
      ATermsImpl trms = (ATermsImpl)trm;
      // Check for the empty list
      if(first == null || trms.first == null)
        return first == null && trms.first == null;

   
      // First we need to handle the special case where the pattern <term>
      // is used.
      if(first.getType() == ATermImpl.PLACEHOLDER) {
	ATermImpl ph = ((ATermPlaceholderImpl)first).getPlaceholderType();
	if(ph.getType() == ATermImpl.APPL) {
	  ATermApplImpl appl = (ATermApplImpl)ph;
	  if(appl.getFun().equals("terms") && appl.getArgs().isEmpty()) {
	    subterms.addElement(new ATerms(trms));
	    return true;
	  }
	}
      }
      
      if(this == trm)
	return true;

      // Just match the first element and the tail.
      if(!first.match(trms.first, subterms))
	return false;
      
      return next.match(trms.next, subterms);
    }
    return false;
  }

  //}
}


