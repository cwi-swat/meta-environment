
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermListRef extends ATermRef
{
  ATermList list = null;

  //{ public ATermListRef(ATermList l)

  /**
    * Create a list refrence from an {\tt ATermList} object.
    */

  ATermListRef(ATermList l)
  {
    update(l);
  }

  //}
  //{ public ATermListRef(ATermsRef terms)

  /**
    * Create a list reference from an ATerms reference.
    */

  public ATermListRef(ATermsRef terms)
  {
    update(new ATermList(terms == null ? null : terms.getATerms()));
  }

  //}
  //{ public ATermListRef(ATermsRef terms, ATermRef anno)

  /**
    * Create a list reference from an ATerms reference.
    */

  public ATermListRef(ATermsRef terms, ATermRef anno)
  {
    update(new ATermList(terms == null ? null : terms.getATerms(), 
			 anno == null ? null : anno.getATerm()));
  }

  //}
  //{ public void setAnno(ATermRef a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATermRef a)
  {
    ATermList val = new ATermList(list.getATerms(), a == null ? null : a.getATerm());
    update(val);
  }

  //}
  //{ protected void finalize()

  protected void finalize()
  {
    if(list != null)
      list.decreaseRef();
  }

  //}

  //{ private void update(ATerms trms)

  /**
    * Update this reference to point to a term equal to {\tt lst}.
    */

  private void update(ATermList lst)
  {
    if(list != null)
      list.decreaseRef();
    if(lst == null)
      list = null;
    else {
      list = (ATermList)lst.unique();
      list.increaseRef();
    }
  }

  //}
  //{ protected ATerm getATerm()

  protected ATerm getATerm()
  {
    return list;
  }

  //}
  //{ private ATerms getATermList()

  private ATermList getATermList()
  {
    return list;
  }

  //}

  //{ public ATermsRef getATerms()

  public ATermsRef getATerms()
  {
    if(list == null || list.getATerms() == null)
      return null;
    return new ATermsRef(list.getATerms());
  }

  //}
  //{ public void setATerms(ATermsRef terms)

  public void setATerms(ATermsRef terms)
  {
    update(terms == null ? null : new ATermList(terms.getATerms()));
  }

  //}
}
