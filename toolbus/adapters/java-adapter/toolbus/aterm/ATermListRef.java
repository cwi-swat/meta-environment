
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
  //{ public ATermListRef(ATermRef first, ATermListRef next)

  /**
    * Create a list reference from an ATerms reference.
    */

  public ATermListRef(ATermsRef terms)
  {
    update(new ATermList(terms == null ? null : terms.getATerms()));
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
    return list == null ? null : new ATermsRef(list.getATerms());
  }

  //}
  //{ public void setATerms(ATermsRef terms)

  public void setATerms(ATermsRef terms)
  {
    update(terms == null ? null : new ATermList(terms.getATerms()));
  }

  //}
}
