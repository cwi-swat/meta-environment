
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATerms extends ATerm
{
  ATermsImpl t;

  //{ public ATerms(ATermsImpl term)

  public ATerms(ATermsImpl term)
  {
    if(term == null)
      throw new NullPointerException();
    update(term);
  }

  //}
  //{ public ATerms()

  /*
   * Construct the empty list.
   */

  public ATerms()
  {
    update(new ATermsImpl());
  }
  
  //{ public ATerms(ATerm f, ATerms n)

  public ATerms(ATerm f, ATerms n)
  {
    update(new ATermsImpl(f.getATermImpl(), (ATermsImpl)n.getATermImpl()));
  }

  //}
  //{ public ATerms(ATerm f, ATerms n, ATerm anno)

  public ATerms(ATerm first, ATerms next, ATerm anno)
  {
    update(new ATermsImpl(first.getATermImpl(),(ATermsImpl)next.getATermImpl(),
		      anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public ATerms(ATerm f)

  public ATerms(ATerm f)
  {
    this(f, new ATerms());
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    update(new ATermsImpl(t.getFirst(), t.getNext(), 
	a == null ? null : a.getATermImpl()));
  }

  //}
  //{ protected void finalize()

  protected void finalize()
  {
    t.decreaseRef();
  }

  //}

  //{ private void update(ATermsImpl val)

  private void update(ATermsImpl val)
  {
    if(t != null)
      t.decreaseRef();
    t = (ATermsImpl)val.unique();
    t.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return t;
  }

  //}
  //{ protected ATermsImpl getATermsImpl()

  protected ATermsImpl getATermsImpl()
  {
    return t;
  }

  //}

  //{ public ATerm getFirst()

  public ATerm getFirst()
  {
    ATermImpl term = t.getFirst();
    switch(term.getType()) {
      case ATermImpl.ATERMS:	return new ATerms((ATermsImpl)term);
      case ATermImpl.APPL:	return new ATermAppl((ATermApplImpl)term);
      case ATermImpl.LIST:	return new ATermList((ATermListImpl)term);
      case ATermImpl.INT:	return new ATermInt((ATermIntImpl)term);
      case ATermImpl.REAL:	return new ATermReal((ATermRealImpl)term);
      case ATermImpl.PLACEHOLDER: return new ATermPlaceholder((ATermPlaceholderImpl)term);
    }
    throw new RuntimeException("Illegal term type: " + term.getType());
  }

  //}
  //{ public ATerms getNext()

  public ATerms getNext()
  {
    return new ATerms(t.getNext());
  }

  //}
  //{ public boolean isEmpty() 

  /**
    * Check if this list is empty.
    */

  public boolean isEmpty() 
  {
    return t.isEmpty();
  }

  //}

  //{ public void setFirst(ATerm first)

  public void setFirst(ATerm first)
  {
    update(new ATermsImpl(first.getATermImpl(), t.getNext()));
  }

  //}
  //{ public void setNext(ATerms next)

  public void setNext(ATerms next)
  {
    update(new ATermsImpl(t.getFirst(), next.getATermsImpl()));
  }

  //}
  //{ public void makeEmpty()

  public void makeEmpty()
  {
    update(new ATermsImpl());
  }

  //}
  //{ public int length()

  /**
    * Determine the length of a list.
    */

  public int length()
  {
    return t.length();
  }

  //}
  //{ public int search(ATerm el)

  /**
    * Search for the first element in a list.
    */

  public int search(ATerm el)
  {
    ATermsImpl cur = t;
    int index = 0;
    while(!cur.isEmpty()) {
      if(cur.getFirst() == el.getATermImpl())
	return index;
       
      index++;
      cur = cur.getNext();
    }

    return -1;
  }

  //}
  //{ public int rsearch(ATerm el)

  /**
    * Search for the last element in a list.
    */

  public int rsearch(ATerm el)
  {
    int index = 0, last = -1;
    for(ATermsImpl cur = t; !cur.isEmpty(); cur = cur.getNext()) {
      if(cur.getFirst() == el.getATermImpl())
	last = index;
      index++;
    }
    return last;
  }

  //}
  //{ public ATerms concat(ATerms rhs)

  /**
    * Concatenate two lists. Returns a new object that contains the
    * concatenation of the two lists.
    */

  public ATerms concat(ATerms rhs)
  {
    return new ATerms(getATermsImpl().concat(rhs.getATermsImpl()));
  }

  //}
  //{ public ATerms append(ATerm el)

  /**
    * Add one element to a list.
    */

  public ATerms append(ATerm el)
  {
    return concat(new ATerms(el));  
  }

  //}

/* ToDo:
   insert, remove, delete, deleteOnce, replace, index, slice, reverse,
   pairGetKey, pairGetValue, dictGet, dictPut, dictRemove
*/

}
