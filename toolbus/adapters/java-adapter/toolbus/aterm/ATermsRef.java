
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermsRef extends ATermRef
{
  ATerms t;

  //{ public ATermsRef(ATermRef f, ATermsRef n)

  public ATermsRef(ATermRef first, ATermsRef next)
  {
    if(first == null)
      throw new NullPointerException();

    update(first.getATerm(), next == null ? null : next.getATerms());
  }

  //}
  //{ public ATermsRef(ATerms term)

  public ATermsRef(ATerms term)
  {
    t = term;
    t.increaseRef();
  }

  //}
  //{ public ATermsRef(ATermRef f)

  public ATermsRef(ATermRef f)
  {
    this(f, null);
  }

  //}
  //{ protected void finalize()

  protected void finalize()
  {
    t.decreaseRef();
  }

  //}

  //{ private void update(ATerm first, ATerms next)

  private void update(ATerm first, ATerms next)
  {
    if(t != null)
      t.decreaseRef();
    ATerms newT = new ATerms(first, next);
    t = (ATerms)newT.unique();
    t.increaseRef();
  }

  //}
  //{ protected ATerm getATerm()

  protected ATerm getATerm()
  {
    return t;
  }

  //}
  //{ protected ATerm getATerms()

  protected ATerms getATerms()
  {
    return t;
  }

  //}

  //{ public ATermRef getFirst()

  public ATermRef getFirst()
  {
    ATerm term = t.getFirst();
    switch(term.getType()) {
      case ATerm.ATERMS:	return new ATermsRef((ATerms)term);
      case ATerm.APPL:		return new ATermApplRef((ATermAppl)term);
      case ATerm.LIST:		return new ATermListRef((ATermList)term);
      case ATerm.INT:		return new ATermIntRef((ATermInt)term);
      case ATerm.REAL:		return new ATermRealRef((ATermReal)term);
      case ATerm.PLACEHOLDER:	return new ATermPlaceholderRef((ATermPlaceholder)term);
    }
    return null;
  }

  //}
  //{ public ATermsRef getNext()

  public ATermsRef getNext()
  {
    if(t.getNext() == null)
      return null;
    
    return new ATermsRef(t.getNext());
  }

  //}

  //{ public void setFirst(ATermRef first)

  public void setFirst(ATermRef first)
  {
    update(first.getATerm(), t.getNext());
  }

  //}
  //{ public void setNext(ATermsRef next)

  public void setNext(ATermsRef next)
  {
    update(t.getFirst(), next == null ? null : next.getATerms());
  }

  //}

  //{ public int length()

  /**
    * Determine the length of a list.
    */

  public int length()
  {
    if(t == null)
      return 0;

    return t.length();
  }

  //}
  //{ public int search(ATermRef el)

  /**
    * Search for the first element in a list.
    */

  public int search(ATermRef el)
  {
    ATerms cur = t;
    int index = 0;
    do {
      if(cur.getFirst() == el.getATerm())
	return index;
       
      index++;
      cur = cur.getNext();
    } while(cur != null);

    return -1;
  }

  //}
  //{ public int rsearch(ATermRef el)

  /**
    * Search for the last element in a list.
    */

  public int rsearch(ATermRef el)
  {
    int index = 0, last = -1;
    for(ATerms cur = t; cur != null; cur = cur.getNext()) {
      if(cur.getFirst() == el.getATerm())
	last = index;
      index++;
    }
    return last;
  }

  //}
  //{ public ATermsRef concat(ATermsRef rhs)

  /**
    * Concatenate two lists. Returns a new object that contains the
    * concatenation of the two lists.
    */

  public ATermsRef concat(ATermsRef rhs)
  {
    if(rhs == null)
      return (ATermsRef)clone();

    return new ATermsRef(getATerms().concat(rhs.getATerms()));
  }

  //}
  //{ public ATermsRef append(ATermRef el)

  /**
    * Add one element to a list.
    */

  public ATermsRef append(ATermRef el)
  {
    return concat(new ATermsRef(el));  
  }

  //}

/* ToDo:
   insert, remove, delete, deleteOnce, replace, index, slice, reverse,
   pairGetKey, pairGetValue, dictGet, dictPut, dictRemove
*/

}
