
package toolbus.aterm;
import java.util.*;
import java.io.*;

public class ATermIntRef extends ATermRef
{
  ATermInt value = null;

  //{ public ATermIntRef(ATermInt val)

  public ATermIntRef(ATermInt val)
  {
    update(val);
  }

  //}
  //{ public ATermIntRef(int i, ATermRef anno)

  public ATermIntRef(int i, ATermRef anno)
  {
    update(new ATermInt(i, anno == null ? null : anno.getATerm()));
  }

  //}
  //{ public ATermIntRef(int i)

  public ATermIntRef(int i)
  {
    update(new ATermInt(i));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATermRef a)
  {
    ATermInt val = new ATermInt(value.getInt(), a == null ? null:a.getATerm());
    update(val);
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    value.decreaseRef();
    super.finalize();
  }

  //}

  //{ private void update(ATermInt val)
  
  /**
    * Update this reference to point to an integer term equal to {\tt val}.
    */

  private void update(ATermInt val)
  {
    if(value != null)
      value.decreaseRef();
    value = (ATermInt)val.unique();
    value.increaseRef();
  }

  //}
  //{ protected ATerm getATerm()

  protected ATerm getATerm()
  {
    return value;
  }

  //}
  //{ protected ATermInt getATermInt()

  protected ATermInt getATermInt()
  {
    return value;
  }

  //}

  //{ public int getInt()

  public int getInt()
  {
    return value.getInt();
  }

  //}
  //{ public int setInt()

  public void setInt(int i)
  {
    update(new ATermInt(i));
  }

  //}
}
