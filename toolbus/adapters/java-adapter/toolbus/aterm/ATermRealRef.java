
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
