
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermAppl extends ATerm
{
  ATermApplImpl appl = null;

  //{ private void update(ATermApplImpl ap)

  /**
    * Update this reference to point to a term equal to {\tt ap}.
    */

  private void update(ATermApplImpl ap)
  {
    if(appl != null)
      appl.decreaseRef();
    appl = (ATermApplImpl)ap.unique();
    appl.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return appl;
  }

  //}
  //{ protected ATermApplImpl getATermApplImpl()

  protected ATermApplImpl getATermApplImpl()
  {
    return appl;
  }

  //}

  //{ public ATermAppl(ATermApplImpl ap)

  public ATermAppl(ATermApplImpl ap)
  {
    update(ap);
  }

  //}
  //{ public ATermAppl(String fun)

  /**
   *
   */ 

  public ATermAppl(String fun)
  {
    this(fun, new ATerms());
  }
  
  //{ public ATermAppl(String fun, ATerms args)

  public ATermAppl(String fun, ATerms args)
  {
    update(new ATermApplImpl(fun, args.getATermsImpl()));
  }

  //}
  //{ public ATermAppl(String fun, ATerms args, boolean isquoted)

  public ATermAppl(String fun, ATerms args, boolean isquoted)
  {
    update(new ATermApplImpl(fun, args.getATermsImpl(), isquoted));
  }

  //}
  //{ public ATermAppl(String fun, ATerms args, ATerm anno)

  /**
    * Construct a new ATermAppl object which is annotated.
    */

  public ATermAppl(String fun, ATerms args, ATerm anno)
  {
    update(new ATermApplImpl(fun, args.getATermsImpl(), 
			anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public ATermAppl(String fun, ATerms args, boolean isquoted, ATerm anno)

  public ATermAppl(String fun, ATerms args, boolean isquoted, ATerm anno)
  {
    update(new ATermApplImpl(fun, args.getATermsImpl(),
			 isquoted, anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    ATermApplImpl val = (ATermApplImpl)appl.clone();
    val.setAnno(a == null ? null : a.getATermImpl());
    update(val);
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    appl.decreaseRef();
  }

  //}

  //{ public String getFun()

  public String getFun()
  {
    return appl.getFun();
  }

  //}
  //{ public ATerms getArgs()

  public ATerms getArgs()
  {
    return new ATerms(appl.getArgs());
  }

  //}
  //{ public void setFun(String fun)

  public void setFun(String fun)
  {
    update(new ATermApplImpl(fun, appl.getArgs()));
  }

  //}
  //{ public void setFun(String fun, boolean isquoted)

  public void setFun(String fun, boolean isquoted)
  {
    update(new ATermApplImpl(fun, appl.getArgs(), isquoted));
  }

  //}
  //{ public void setArgs(ATerms args)

  public void setArgs(ATerms args)
  {
    update(new ATermApplImpl(appl.getFun(), args.getATermsImpl(), 
		appl.isQuoted(), this.getAnno() == null ? null : 
                              this.getAnno().getATermImpl()));
  }

  //}
}
