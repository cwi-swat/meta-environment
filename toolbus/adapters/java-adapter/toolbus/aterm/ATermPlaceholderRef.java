
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermPlaceholderRef extends ATermRef
{
  ATermPlaceholder placeholder = null;

  //{ private void update(ATermPlaceholder ph)

  /**	
    * Update this reference to point to a term equal to {\tt ph}.
    */

private void update(ATermPlaceholder ph)
{
  if(placeholder != null)
    placeholder.decreaseRef();
  placeholder = (ATermPlaceholder)ph.unique();
  placeholder.increaseRef();
}

  //}
  //{ protected ATerm getATerm()

  protected ATerm getATerm()
  {
    return placeholder;
  }

  //}
  //{ protected ATerm getATermPlaceholder()

  protected ATerm getATermPlaceholder()
  {
    return placeholder;
  }

  //}

  //{ public ATermPlaceholderRef(ATermPlaceholder ph)

  public ATermPlaceholderRef(ATermPlaceholder ph)
  {
    update(ph);
  }

  //}
  //{ public ATermPlaceholderRef(ATermRef type)

  public ATermPlaceholderRef(ATermRef type)
  {
    update(new ATermPlaceholder(type.getATerm()));
  }

  //}
  //{ protected void finalize()

  protected void finalize()
  {
    placeholder.decreaseRef();
  }

  //}

  //{ public ATermRef getPlaceholderType()

  public ATermRef getPlaceholderType()
  {
    ATerm term = placeholder.getPlaceholderType();
    switch(term.getType()) {
      case ATerm.ATERMS:       	return new ATermsRef((ATerms)term);
      case ATerm.APPL:		return new ATermApplRef((ATermAppl)term);
      case ATerm.LIST:		return new ATermListRef((ATermList)term);
      case ATerm.INT:		return new ATermIntRef((ATermInt)term);
      case ATerm.REAL:		return new ATermRealRef((ATermReal)term);
      case ATerm.PLACEHOLDER:	return new ATermPlaceholderRef((ATermPlaceholder)term);
    }
    return null;
  }

  //}
  //{ public void setPlaceholderType(ATermRef type)

  public void setPlaceholderType(ATermRef type)
  {
    update(new ATermPlaceholder(type.getATerm()));
  }

  //}
}
