
package toolbus.aterm;
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.CharArrayWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

/**
  * The class ATerm is the base class for all Term implementation classes.
  * A term implementation class represents unique term objects.
  *
  * @author Pieter Olivier
  * @version 0.1, 4-Apr-1997
  */

abstract public class ATerm implements SimpleHashtableEntry, Cloneable
{
  private static SimpleHashtable table = new SimpleHashtable(43117);
  private static SimpleHashtableEntry dummy = new DummyEntry();

  public static final int ATERMS	= 1;
  public static final int APPL		= 2;
  public static final int LIST		= 3;
  public static final int INT		= 4;
  public static final int REAL		= 5;
  public static final int PLACEHOLDER	= 6;
  
  private ATerm anno;
  private int refcount = 0;
  private SimpleHashtableEntry hnext = dummy;

  public void print(Writer w)	   { print(new PrintWriter(w)); }
  public void print(PrintWriter w)
  { 
    if(anno != null) { 
      w.print(':'); 
      anno.print(w);
    }
  }
  public void write(OutputStream o) throws java.io.IOException {
    if(anno != null) {
      o.write(':');
      anno.write(o);
    }
  }
  abstract public int getType();
  public boolean match(ATerm trm, Vector subterms) { return equals(trm); }

  //{ ATerm(ATerm an)

  /**
    *Construct a term given an annotation.
    */

  ATerm(ATerm an)
  {
    anno = an;
    if(anno != null)
      anno.increaseRef();
  }

  //}
  //{ protected Object clone()

  /** 
    * Clone this object.
    */

  protected Object clone()
  {
    try {
      ATerm term = (ATerm)super.clone();
      term.anno = anno;
      if(term.anno != null)
	term.anno.increaseRef();
      return term;
    } catch (CloneNotSupportedException e) {
      throw new InternalError();
    }
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    if(anno != null)
      anno.decreaseRef();
    super.finalize();
  }

  //}
  //{ public boolean equals(Object obj)

  /**
    * Equality test on terms.
    */

  public boolean equals(Object obj)
  { 
    return (ATerm)anno == ((ATerm)obj).anno;
  }

  //}
  //{ public ATerm getAnno()

  /**
    * Retrieve the annotation of this term.
    */

  public ATerm getAnno()
  {
    return anno;
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of this object.
    */

  public void setAnno(ATerm a)
  { 
    if(anno != null)
      anno.decreaseRef();
    anno = a;
    if(anno != null)
      anno.increaseRef();
  }

  //}
  //{ public int size()

  /**
    * Calculate the number of nodes added by this object.
    */

  public int size()
  {
    if(anno != null)
      return anno.size();
    return 0;
  }

  //}
  //{ public int printSize()

  public int printSize()
  {
    if(anno == null)
      return 0; 
    return anno.printSize()+2; // annotation + '{' and '}'
  }

  //}
  //{ public static int tableSize()

  static int tableSize()
  {
    return table.size();
  }

  //}
  //{ public static Enumeration tableElements()

  public static Enumeration tableElements()
  {
    return table.elements();
  }

  //}
  //{ public synchronized void increaseRef()

  /**
    * Increase the reference count of this object.
    */

  public synchronized void increaseRef()
  {
    refcount++;
  }

  //}
  //{ public synchronized void decreaseRef()

  /**
    * Decrease the reference count of this object.
    * When the reference count goes to zero, and this
    * object in the hash table, we remove
    * the object from the hash table.
    */

public synchronized void decreaseRef()
{ 
  refcount--; 
  if(refcount == 0 && hnext != dummy && table != null)
    table.remove(this);
}

  //}
  //{ public int refCount()

  /**
    * Retrieve the reference count of this object.
    */

  public int refCount()
  {
    return refcount;
  }
  
  //}
  //{ public SimpleHashtableEntry getNextHashEntry()

  /**
    * Retrieve the next hash bucket.
    */

  public SimpleHashtableEntry getNextHashEntry()
  {
    return hnext;
  }

  //}
  //{ public synchronized void setNextHashEntry(SimpleHashtableEntry next)

  /**
    * Change the next hash bucket.
    */

  public synchronized void setNextHashEntry(SimpleHashtableEntry next)
  {
    hnext = next;
  }
  
  //}

  //{ public ATerm unique()

  /**
    * Return the unique representation of this term,
    * by looking it up in the hash table. If it is not
    * present in the hash table, this term will become
    * its own unique representation, and we add it to
    * the hash table.
    */

  public ATerm unique()
  {
    ATerm trm = (ATerm)table.get(this);
    if(trm == null) {
      table.put(this);
      return this;
    }
    return trm;
  }

  //}
  //{ public String toString()

  public String toString()
  {
    CharArrayWriter buf = new CharArrayWriter();
    
    print(buf);
    return buf.toString();
  }

  //}
}

//{ class DummyEntry

class DummyEntry implements SimpleHashtableEntry
{
  public SimpleHashtableEntry getNextHashEntry() { return null; }
  public void setNextHashEntry(SimpleHashtableEntry e) { }
}

//}
