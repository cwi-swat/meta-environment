
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermPlaceholder extends ATerm
{
  ATermPlaceholderImpl placeholder = null;

  //{ protected ATermPlaceholder(ATermPlaceholderImpl ph)

  protected ATermPlaceholder(ATermPlaceholderImpl ph)
  {
    super(ph.getWorld());
    intern(ph);
  }

  //}
  //{ protected ATermPlaceholder(World world)

  /**
    * Construct a new ATermPlaceholder object.
    */

  protected ATermPlaceholder(World world)
  {
    super(world);
  }

  //}
  //{ public ATermPlaceholder(World world, ATerm type)

  /**
    * Construct a new placeholder type.
    * @deprecated Use World.makePlaceholder(ATerm type) instead.
    */

  public ATermPlaceholder(World world, ATerm type)
  {
    super(world);
    intern(new ATermPlaceholderImpl(world, type.getATermImpl(), null));
  }

  //}
  //{ public ATermPlaceholder(World world, ATerm type, ATerm anno)

  /**
    * Create a new placeholder object.
    * @deprecated Use World.makePlaceholder(ATerm type, ATerm anno) instead.
    */

  public ATermPlaceholder(World world, ATerm type, ATerm anno)
  {
    super(world);
    intern(new ATermPlaceholderImpl(world, type.getATermImpl(), 
				    anno == null ? null : anno.getATermImpl()));
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

  //{ protected void intern(ATermPlaceholderImpl ph)

  /**	
    * Intern this reference to point to a term equal to {\tt ph}.
    */

  protected void intern(ATermPlaceholderImpl ph)
  {
    if(placeholder != null)
      placeholder.decreaseRef();
    placeholder = (ATermPlaceholderImpl)world.intern(ph);
    placeholder.increaseRef();
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    intern(new ATermPlaceholderImpl(world, placeholder.getPlaceholderType(),
				    a ==  null ? null : a.getATermImpl()));
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
    intern(new ATermPlaceholderImpl(world, type.getATermImpl()));
  }

  //}
}
