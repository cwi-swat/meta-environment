
package toolbus.aterm;
import java.util.*;
import java.io.*;

public class ATermInt extends ATerm
{
  ATermIntImpl value = null;

  //{ public ATermInt(ATermIntImpl val)

  public ATermInt(ATermIntImpl val)
  {
    update(val);
  }

  //}
  //{ public ATermInt(int i, ATerm anno)

  public ATermInt(int i, ATerm anno)
  {
    update(new ATermIntImpl(i, anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public ATermInt(int i)

  public ATermInt(int i)
  {
    update(new ATermIntImpl(i));
  }

  //}
  //{ public void setAnno(ATermImpl a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    ATermIntImpl val = new ATermIntImpl(value.getInt(), a == null ? 
		null:a.getATermImpl());
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

  //{ private void update(ATermIntImpl val)
  
  /**
    * Update this reference to point to an integer term equal to {\tt val}.
    */

  private void update(ATermIntImpl val)
  {
    if(value != null)
      value.decreaseRef();
    value = (ATermIntImpl)val.unique();
    value.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return value;
  }

  //}
  //{ protected ATermIntImpl getATermIntImpl()

  protected ATermIntImpl getATermIntImpl()
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
    update(new ATermIntImpl(i));
  }

  //}
}
