
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

public class ATermInt extends ATerm
{
  private int val;

  public ATermInt(int v, ATerm anno)	{ super(anno); val = v;	}
  public ATermInt(int v)		{ this(v, null);	}
  public Object clone() {
    ATermInt i = (ATermInt)super.clone();
    i.val = val;
    return i;
  }

  public boolean equals(Object obj) {
    if(obj instanceof ATermInt)
      return val == ((ATermInt)obj).val && super.equals(obj);
    return false;
  }

  public int hashCode()			{ return val;	}
  public int getType()			{ return ATerm.INT; }
  public int getInt()			{ return val;	}
  public void setInt(int v)		{ val = v;	}

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
