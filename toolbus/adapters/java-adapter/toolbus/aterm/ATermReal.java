package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.io.*;

public class ATermReal extends ATerm
{
  private Double val;

  public ATermReal(double v, ATerm an)	{ super(an); val = new Double(v); }
  public ATermReal(double v)		{ this(v, null);		}
  public Object clone() {
    ATermReal r = (ATermReal)super.clone();
    r.val = val;
    return r;
  }

  public boolean equals(Object obj) {
    if(obj instanceof ATermReal)
      return val.equals(((ATermReal)obj).val) && super.equals(obj);
    return false;
  }

  public int hashCode()			{ return val.hashCode();	}
  public int getType()			{ return ATerm.REAL;		}
  public double getReal()		{ return val.doubleValue();	}
  public void setReal(double v)		{ val = new Double(v);		}

  public void print(PrintWriter w) {
    w.print(val);
    super.print(w);
  }

  public void write(OutputStream o) throws java.io.IOException {
    String str = val.toString();
    for(int i=0; i<str.length(); i++)
      o.write(str.charAt(i));
    super.write(o);
  }

  public int printSize() {
    return super.printSize() + val.toString().length();
  }

  public int size()	{ return 1 + super.size(); }
}

