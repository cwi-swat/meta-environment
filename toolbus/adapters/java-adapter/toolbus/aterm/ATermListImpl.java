
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

public class ATermListImpl extends ATermImpl
{
  private ATermsImpl aterms;
  private int hashcode;

  //{ public ATermListImpl(ATermsImpl terms, ATermImpl anno)

  public ATermListImpl(ATermsImpl terms, ATermImpl anno)
  { 
    super(anno);
    aterms = terms; 
    updateHashCode();
    aterms.increaseRef();
  }

  //}
  //{ public ATermListImpl(ATermsImpl terms)

  public ATermListImpl(ATermsImpl terms)
  {
    this(terms, null);
  }

  //}
  //{ public Object clone()

  public Object clone()
  {
    ATermListImpl list = (ATermListImpl)super.clone();
    list.aterms = aterms;
    list.hashcode = hashcode;
    aterms.increaseRef();
    return list;
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    aterms.decreaseRef();
    super.finalize();
  }

  //}
  //{ public boolean equals(Object obj)

  public boolean equals(Object obj)
  {
    if(obj instanceof ATermListImpl)
      return aterms == ((ATermListImpl)obj).aterms && super.equals(obj);
    return false;
  }

  //}
  //{ public void updateHashCode()

  public void updateHashCode()
  {
    hashcode = aterms.hashCode()+1;
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
    return ATermImpl.LIST;
  }

  //}
  //{ public ATermsImpl getATermsImpl()

  public ATermsImpl getATermsImpl()
  {
    return aterms;
  }

  //}
  //{ public void setATermsImpl(ATermsImpl terms)

  public void setATermsImpl(ATermsImpl terms)
  {
    aterms.decreaseRef();
    aterms = terms; 
    updateHashCode();
    aterms.increaseRef();
  }

  //}
  //{ public boolean isEmpty()

  /**
    * Check if this object represents the empty list.
    */

  public boolean isEmpty()
  {
    return aterms.isEmpty();
  }

  //}
  //{ public void write(OutputStream o)
  
  public void write(OutputStream o)
    throws java.io.IOException
  {
    o.write('[');
    aterms.write(o);
    o.write(']');
    super.write(o);
  }

  //}
  //{ public void print(PrintWriter w)

  public void print(PrintWriter w)
  {
    w.print('[');
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
    size += aterms.size();
    return size;
  }

  //}

  //{ public boolean match(ATermImpl trm, Vector subterms)

  /**
    * Match against {\tt trm}, using {\tt this} as a placeholder term.
    */

  public boolean match(ATermImpl trm, Vector subterms)
  {
    if(trm.getType() == ATermImpl.LIST)
      return aterms.match(((ATermListImpl)trm).aterms, subterms);
    return false;
  }

  //}
}
