
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

public class ATermList extends ATerm
{
  private ATerms aterms;
  private int hashcode;

  //{ public ATermList(ATerms terms, ATerm anno)

  public ATermList(ATerms terms, ATerm anno)
  { 
    super(anno);
    aterms = terms; 
    updateHashCode();
    if(aterms != null)
      aterms.increaseRef();
  }

  //}
  //{ public ATermList(ATerms terms)

  public ATermList(ATerms terms)
  {
    this(terms, null);
  }

  //}
  //{ public Object clone()

  public Object clone()
  {
    ATermList list = (ATermList)super.clone();
    list.aterms = aterms;
    list.hashcode = hashcode;
    if(aterms != null)
      aterms.increaseRef();
    return list;
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    if(aterms != null)
      aterms.decreaseRef();
    super.finalize();
  }

  //}
  //{ public boolean equals(Object obj)

  public boolean equals(Object obj)
  {
    if(obj instanceof ATermList)
      return aterms == ((ATermList)obj).aterms && super.equals(obj);
    return false;
  }

  //}
  //{ public void updateHashCode()

  public void updateHashCode()
  {
    hashcode = aterms == null ? 0 : aterms.hashCode()+1;
  }

  //}
  //{ public int hashCode()

  public int hashCode()
  {
    return hashcode;
  }

  //}
  //{ public int getType()

  public int getType()
  {
    return ATerm.LIST;
  }

  //}
  //{ public ATerms getATerms()

  public ATerms getATerms()
  {
    return aterms;
  }

  //}
  //{ public void setATerms(ATerms terms)

  public void setATerms(ATerms terms)
  {
    if(aterms != null)
      aterms.decreaseRef();
    aterms = terms; 
    updateHashCode();
    if(aterms != null)
      aterms.increaseRef();
  }

  //}
  //{ public void write(OutputStream o)
  
  public void print(OutputStream o)
    throws java.io.IOException
  {
    o.write('[');
    if(aterms != null)
      aterms.write(o);
    o.write(']');
    super.write(o);
  }

  //}
  //{ public void print(PrintWriter w)

  public void print(PrintWriter w)
  {
    w.print('[');
    if(aterms != null)
      aterms.print(w);
    w.print(']');
    super.print(w);
  }

  //}
  //{ public int printSize()

  public int printSize()
  {
    int size = super.printSize();
    size += 2;	// The '[' and ']' characters.
    size += aterms.printSize();
    return size;
  }

  //}
  //{ public int size() 

  public int size() 
  { 
    int size = 1 + super.size();
    if(aterms != null)
      size += aterms.size();
    return size;
  }

  //}

  //{ public boolean match(ATerm trm, Vector subterms)

  /**
    * Match against {\tt trm}, using {\tt this} as a placeholder term.
    */

  public boolean match(ATerm trm, Vector subterms)
  {
    if(trm.getType() == ATerm.LIST)
      return aterms.match(((ATermList)trm).aterms, subterms);
    return false;
  }

  //}
}
