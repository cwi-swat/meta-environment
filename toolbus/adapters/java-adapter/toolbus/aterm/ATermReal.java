
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermReal extends ATerm
{
  ATermRealImpl value = null;

  //{ public ATermReal(ATermRealImpl val)

  public ATermReal(ATermRealImpl val)
  {
    update(val);
  }

  //}
  //{ public ATermReal(double r)

  public ATermReal(double r)
  {
    update(new ATermRealImpl(r));
  }

  //}
  //{ public ATermReal(double r, ATerm anno)

  public ATermReal(double r, ATerm anno)
  {
    update(new ATermRealImpl(r, anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    update(new ATermRealImpl(value.getReal(), a == null ? null : a.getATermImpl()));
  }

  //}
  //{ protected void finalize()

  protected void finalize() throws Throwable
  {
    value.decreaseRef();
  }

  //}

  //{ private void update(ATermRealImpl r)

  /**
    * Update this reference to point to an real term equal to {\tt val}.
    */

  private void update(ATermRealImpl val)
  {
    if(value != null)
      value.decreaseRef();
    value = (ATermRealImpl)val.unique();
    value.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return value;
  }

  //}
  //{ protected ATermRealImpl getATermRealImpl()

  protected ATermRealImpl getATermRealImpl()
  {
    return value;
  }

  //}

  //{ double getReal()

  double getReal()
  {
    return value.getReal();
  }

  //}
  //{ void setReal()

  void setReal(double r)
  {
    update(new ATermRealImpl(r));
  }

  //}
}
