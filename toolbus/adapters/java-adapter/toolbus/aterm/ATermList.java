
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermList extends ATerm
{
  ATermListImpl list = null;

  //{ public ATermList(ATermListImpl l)

  /**
    * Create a list from an {\tt ATermListImpl} object.
    */

  ATermList(ATermListImpl l)
  {
    update(l);
  }

  //}
  //{ public ATermList(ATerms terms)

  /**
    * Create a list reference from an ATerms reference.
    */

  public ATermList(ATerms terms)
  {
    update(new ATermListImpl(terms.getATermsImpl()));
  }

  //}
  //{ public ATermList(ATerms terms, ATerm anno)

  /**
    * Create a list reference from an ATerms reference.
    */

  public ATermList(ATerms terms, ATerm anno)
  {
    update(new ATermListImpl(terms.getATermsImpl(), 
			 anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    update(new ATermListImpl(list.getATermsImpl(), a == null ? null : a.getATermImpl()));
  }

  //}
  //{ protected void finalize()

  protected void finalize()
  {
    list.decreaseRef();
  }

  //}

  //{ private void update(ATermListImpl lst)

  /**
    * Update this reference to point to a term equal to {\tt lst}.
    */

  private void update(ATermListImpl lst)
  {
    if(list != null)
      list.decreaseRef();
    list = (ATermListImpl)lst.unique();
    list.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return list;
  }

  //}
  //{ private ATermsImpl getATermListImpl()

  private ATermListImpl getATermListImpl()
  {
    return list;
  }

  //}

  //{ public ATerms getATerms()

  public ATerms getATerms()
  {
    return new ATerms(list.getATermsImpl());
  }

  //}
  //{ public void setATerms(ATerms terms)

  public void setATerms(ATerms terms)
  {
    update(new ATermListImpl(terms.getATermsImpl()));
  }

  //}
  //{ public boolean isEmpty()

  /**
    * Check if this is the empty list.
    */

  public boolean isEmpty()
  {
    return list.isEmpty();
  }

  //}
}
