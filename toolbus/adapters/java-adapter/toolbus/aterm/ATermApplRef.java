
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermApplRef extends ATermRef
{
  ATermAppl appl = null;

  //{ private void update(ATermAppl ap)

  /**
    * Update this reference to point to a term equal to {\tt ap}.
    */

  private void update(ATermAppl ap)
  {
    if(appl != null)
      appl.decreaseRef();
    appl = (ATermAppl)ap.unique();
    appl.increaseRef();
  }

  //}
  //{ protected ATerm getATerm()

  protected ATerm getATerm()
  {
    return appl;
  }

  //}
  //{ protected ATermAppl getATermAppl()

  protected ATermAppl getATermAppl()
  {
    return appl;
  }

  //}

  //{ public ATermApplRef(ATermAppl ap)

  public ATermApplRef(ATermAppl ap)
  {
    update(ap);
  }

  //}
  //{ public ATermApplRef(String fun, ATermsRef args)

  public ATermApplRef(String fun, ATermsRef args)
  {
    update(new ATermAppl(fun, args == null ? null : args.getATerms()));
  }

  //}
  //{ public ATermApplRef(String fun, ATermsRef args, boolean isquoted)

  public ATermApplRef(String fun, ATermsRef args, boolean isquoted)
  {
    update(new ATermAppl(fun, args == null ? null : args.getATerms(), isquoted));
  }

  //}
  //{ public ATermApplRef(String fun, ATermsRef args, ATermRef anno)

  /**
    * Construct a new ATermApplRef object which is annotated.
    */

  public ATermApplRef(String fun, ATermsRef args, ATermRef anno)
  {
    update(new ATermAppl(fun, args == null ? null : args.getATerms(),
			 anno == null ? null : anno.getATerm()));
  }

  //}
  //{ public ATermApplRef(String fun, ATermsRef args, boolean isquoted, ATermRef anno)

  public ATermApplRef(String fun, ATermsRef args, boolean isquoted, ATermRef anno)
  {
    update(new ATermAppl(fun, args == null ? null : args.getATerms(),
			 isquoted, anno == null ? null : anno.getATerm()));
  }

  //}
  //{ public void setAnno(ATermRef a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATermRef a)
  {
    ATermAppl val = (ATermAppl)appl.clone();
    val.setAnno(a == null ? null : a.getATerm());
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
  //{ public ATermsRef getArgs()

  public ATermsRef getArgs()
  {
    if(appl.getArgs() == null)
      return null;

    return new ATermsRef(appl.getArgs());
  }

  //}
  //{ public void setFun(String fun)

  public void setFun(String fun)
  {
    update(new ATermAppl(fun, appl.getArgs()));
  }

  //}
  //{ public void setFun(String fun, boolean isquoted)

  public void setFun(String fun, boolean isquoted)
  {
    update(new ATermAppl(fun, appl.getArgs(), isquoted));
  }

  //}
  //{ public void setArgs(ATermsRef args)

  public void setArgs(ATermsRef args)
  {
    update(new ATermAppl(appl.getFun(), args == null ? null : args.getATerms(), appl.isQuoted()));
  }

//}
}
