
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

public class ATermIntImpl extends ATermImpl
{
  private int val;

  public ATermIntImpl(World world, int v, ATermImpl anno)
  { 
    super(world, anno);
    val = v;
  }

  public ATermIntImpl(World world, int v)
  { 
    this(world, v, null);
  }

  public Object clone() 
  {
    ATermIntImpl i = (ATermIntImpl)super.clone();
    i.val = val;
    return i;
  }

  public boolean equals(Object obj) 
  {
    if(obj instanceof ATermIntImpl)
      return val == ((ATermIntImpl)obj).val && super.equals(obj);
    return false;
  }

  public int hashCode()			{ return val;	}
  public int getType()			{ return ATermImpl.INT; }
  public int getInt()			{ return val;	}

  public void print(PrintWriter w) {
    w.print(val);
    super.print(w);
  }

  public void write(OutputStream o) throws java.io.IOException {
    String str = "" + val;
    for(int i=0; i<str.length(); i++)
      o.write(str.charAt(i));
    super.write(o);
  }

  public int printSize() {
    return super.printSize() + (""+val).length();
  }

  public int size()		{ return 1 + super.size(); }
}
