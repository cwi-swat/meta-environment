package toolbus.aterm;

import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.CharArrayWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

/**
  * The class ATermImpl is the base class for all ATerm implementation classes.
  * A term implementation class represents unique term objects.
  *
  * @author Pieter Olivier
  * @version 0.2, 11-Dec-1997
  */

abstract class ATermImpl 
  implements SimpleHashtableEntry, Cloneable
{
  public static final int ATERMS	= 1;
  public static final int APPL		= 2;
  public static final int LIST		= 3;
  public static final int INT		= 4;
  public static final int REAL		= 5;
  public static final int PLACEHOLDER	= 6;
  
  protected World world;
  private ATermImpl anno;
  private int refcount;
  private SimpleHashtableEntry hnext;

  abstract public int getType();

  //{ ATermImpl(World world, ATermImpl an)

  /**
    *Construct a term given an annotation.
    */

  ATermImpl(World w, ATermImpl an)
  {
    world = w;
    anno = an;
    if(anno != null)
      anno.increaseRef();
  }

  //}
  //{ public World getWorld()

  /**
    * Retrieve this terms world.
    */

  public World getWorld()
  {
    return world;
  }

  //}
  //{ protected Object clone()

  /** 
    * Clone this object.
    */

  protected Object clone()
  {
    try {
      ATermImpl term = (ATermImpl)super.clone();
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
    return (ATermImpl)anno == ((ATermImpl)obj).anno;
  }

  //}
  //{ public ATermImpl getAnno()

  /**
    * Retrieve the annotation of this term.
    */

  public ATermImpl getAnno()
  {
    return anno;
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
    if(refcount == 0)
      world.remove(this);
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

  //{ public void print(Writer w)

  public void print(Writer w)
  { 
    print(new PrintWriter(w)); 
  }

  //}
  //{ public void print(PrintWriter w)

  public void print(PrintWriter w)
  { 
    if(anno != null) { 
      w.print(':'); 
      anno.print(w);
    }
  }

  //}
  //{ public void write(OutputStream o) throws java.io.IOException {

  public void write(OutputStream o) throws java.io.IOException {
    if(anno != null) {
      o.write(':');
      anno.write(o);
    }
  }

  //}
  //{ public boolean match(ATermImpl trm, Vector subterms) 

  public boolean match(ATermImpl trm, Vector subterms) 
  { 
    return equals(trm); 
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

