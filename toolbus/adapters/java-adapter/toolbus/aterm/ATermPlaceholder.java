
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermPlaceholder extends ATerm
{
  ATermPlaceholderImpl placeholder = null;

  //{ private void update(ATermPlaceholderImpl ph)

  /**	
    * Update this reference to point to a term equal to {\tt ph}.
    */

  private void update(ATermPlaceholderImpl ph)
  {
    if(placeholder != null)
      placeholder.decreaseRef();
    placeholder = (ATermPlaceholderImpl)ph.unique();
    placeholder.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return placeholder;
  }

  //}
  //{ protected ATermImpl getATermPlaceholderImpl()

  protected ATermImpl getATermPlaceholderImpl()
  {
    return placeholder;
  }

  //}

  //{ public ATermPlaceholder(ATermPlaceholderImpl ph)

  public ATermPlaceholder(ATermPlaceholderImpl ph)
  {
    update(ph);
  }

  //}
  //{ public ATermPlaceholder(ATerm type)

  public ATermPlaceholder(ATerm type)
  {
    update(new ATermPlaceholderImpl(type.getATermImpl()));
  }

  //}
  //{ public ATermPlaceholder(ATerm type, ATerm anno)

  public ATermPlaceholder(ATerm type, ATerm anno)
  {
    update(new ATermPlaceholderImpl(type.getATermImpl(), anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    ATermPlaceholderImpl val = (ATermPlaceholderImpl)placeholder.clone();
    val.setAnno(a == null ? null : a.getATermImpl());
    update(val);
  }

  //}
  //{ protected void finalize()

  protected void finalize()
  {
    placeholder.decreaseRef();
  }

  //}

  //{ public ATerm getPlaceholderType()

  public ATerm getPlaceholderType()
  {
    ATermImpl term = placeholder.getPlaceholderType();
    switch(term.getType()) {
      case ATermImpl.ATERMS:   	return new ATerms((ATermsImpl)term);
      case ATermImpl.APPL:	return new ATermAppl((ATermApplImpl)term);
      case ATermImpl.LIST:	return new ATermList((ATermListImpl)term);
      case ATermImpl.INT:	return new ATermInt((ATermIntImpl)term);
      case ATermImpl.REAL:	return new ATermReal((ATermRealImpl)term);
      case ATermImpl.PLACEHOLDER: return new ATermPlaceholder((ATermPlaceholderImpl)term);
    }
    throw new RuntimeException("illegal term type: " + term.getType());
  }

  //}
  //{ public void setPlaceholderType(ATerm type)

  public void setPlaceholderType(ATerm type)
  {
    update(new ATermPlaceholderImpl(type.getATermImpl()));
  }

  //}
}
