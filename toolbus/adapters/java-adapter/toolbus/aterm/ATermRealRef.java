
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermRealRef extends ATermRef
{
  ATermReal value = null;

  //{ public ATermRealRef(ATermReal val)

  public ATermRealRef(ATermReal val)
  {
    update(val);
  }

  //}
  //{ public ATermRealRef(double r)

  public ATermRealRef(double r)
  {
    update(new ATermReal(r));
  }

  //}
  //{ public ATermRealRef(double r, ATermRef anno)

  public ATermRealRef(double r, ATermRef anno)
  {
    update(new ATermReal(r, anno == null ? null : anno.getATerm()));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATermRef a)
  {
    ATermReal val = new ATermReal(value.getReal(), a == null ? null : a.getATerm());
    update(val);
  }

  //}
  //{ protected void finalize()

  protected void finalize() throws Throwable
  {
    value.decreaseRef();
  }

  //}

  //{ private void update(ATermReal r)

  /**
    * Update this reference to point to an real term equal to {\tt val}.
    */

  private void update(ATermReal val)
  {
    if(value != null)
      value.decreaseRef();
    value = (ATermReal)val.unique();
    value.increaseRef();
  }

  //}
  //{ protected ATerm getATerm()

  protected ATerm getATerm()
  {
    return value;
  }

  //}
  //{ protected ATermReal getATermReal()

  protected ATermReal getATermReal()
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
    update(new ATermReal(r));
  }

  //}
}
