
package toolbus.aterm;
import java.util.*;
import java.io.*;

public class ATermInt extends ATerm
{
  ATermIntImpl value = null;

  //{ protected ATermInt(ATermIntImpl val)

  protected ATermInt(ATermIntImpl val)
  {
    super(val.getWorld());
    intern(val);
  }

  //}
  //{ protected ATermInt(World world)

  /**
    * Construct a new ATermInt object that is initially empty.
    */

  protected ATermInt(World world)
  {
    super(world);
  }

  //}
  //{ public ATermInt(World world, int i)

  public ATermInt(World world, int i)
  {
    super(world);
    intern(new ATermIntImpl(world, i));
  }

  //}
  //{ public ATermInt(World world, int i, ATerm anno)

  public ATermInt(World world, int i, ATerm anno)
  {
    super(world);
    intern(new ATermIntImpl(world, i, anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public void setAnno(ATermImpl a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    intern(new ATermIntImpl(world, value.getInt(), 
			    a == null ? null:a.getATermImpl()));
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

  //{ protected void intern(ATermIntImpl val)
  
  /**
    * Intern this reference to point to an integer term equal to {\tt val}.
    */

  protected void intern(ATermIntImpl val)
  {
    if(value != null)
      value.decreaseRef();
    value = (ATermIntImpl)world.intern(val);
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
    intern(new ATermIntImpl(world, i));
  }

  //}
}
