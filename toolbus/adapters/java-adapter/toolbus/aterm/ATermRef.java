
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.io.*;

abstract public class ATermRef
{
  abstract protected ATerm getATerm();


  //{ public boolean equals(Object obj)

  /**
    * Two ATerm references are considered equal when they
    * refer to the same term.
    */

  public boolean equals(Object obj)
  {
    if(obj instanceof ATermRef)
      return getATerm() == ((ATermRef)obj).getATerm();
    return false;
  }

  //}
  //{ public int getType()

  public int getType()
  {
    return getATerm().getType();
  }

  //}
  //{ public ATerm getAnno()

  /**
    * Retrieve the annotation of a term.
    */

  public ATerm getAnno()
  {
    return getATerm().getAnno();
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    getATerm().setAnno(a);
  }

  //}
  //{ public int size()

  /**
    * Determine the size (number of nodes) of a term.
    */

  public int size()
  {
    return getATerm().size();
  }

  //}
  //{ public void write(OutputStream o)

  /**
    * Write a term to an output stream..
    */

  public void write(OutputStream o)
    throws java.io.IOException
  { 
    getATerm().write(o);
  }

  //}
  //{ public void print(OutputStream o)

  /**
    * Pretty-print a term to an OutputStream.
    */

  public void print(OutputStream o)
  {
    print(new PrintWriter(o));
  }

  //}
  //{ public void println(OutputStream o)

  /**
    * Pretty-print a term to an OutputStream, followed by a newline.
    */

  public void println(OutputStream o)
  {
    println(new PrintWriter(o));
  }

  //}
  //{ public void print(PrintWriter o)

  /**
    * Pretty-print a term to a PrintWriter stream.
    */

  public void print(PrintWriter w)
  {
    getATerm().print(w);
    w.flush();
  }

  //}
  //{ public void println(PrintWriter o)

  /**
    * Pretty-print a term to a PrintWriter stream, followed by a newline.
    */

  public void println(PrintWriter w)
  { 
    getATerm().print(w);
    w.println("");
    w.flush();
  }

  //}
  //{ public void print(Writer o)

  public void print(Writer w)
  { 
    getATerm().print(w);
    try { w.flush(); } catch (IOException e) { }
  }

  //}
  //{ public void println(Writer o)

  public void println(Writer w)
  { 
    getATerm().print(w);
    try {
      w.write((int)'\n');
      w.flush();
    } catch (IOException e) { }
  }

  //}
  //{ public int printSize()

  /**
    * Determine the size of a term when printed.
    */

  public int printSize()
  {
    return getATerm().printSize();
  }

  //}
  //{ public String toString()

  public String toString()
  {
    return getATerm().toString();
  }

  //}
  //{ public int hashCode()

  public int hashCode()
  {
    return getATerm().hashCode();
  }

//}
}
