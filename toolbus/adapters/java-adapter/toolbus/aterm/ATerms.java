
package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATerms extends ATerm
{
  ATermsImpl t;

  //{ protected ATerms(ATermsImpl term)

  protected ATerms(ATermsImpl term)
  {
    super(term.getWorld());
    if(term == null)
      throw new NullPointerException();
    intern(term);
  }

  //}
  //{ protected ATerms(World world, int dummy)

  protected ATerms(World world, int dummy)
  {
    super(world);
  }

  //}
  //{ public ATerms(World world)

  /*
   * Construct the empty list.
   * @deprecated Use World.empty instead.
   */

  public ATerms(World world)
  {
    super(world);
    intern(new ATermsImpl(world));
  }
  //}  
  //{ public ATerms(World world, ATerm f, ATerms n)

  public ATerms(World world, ATerm f, ATerms n)
  {
    super(world);
    intern(new ATermsImpl(world, f.getATermImpl(), (ATermsImpl)n.getATermImpl()));
  }

  //}
  //{ public ATerms(World world, ATerm f, ATerms n, ATerm anno)

  public ATerms(World world, ATerm first, ATerms next, ATerm anno)
  {
    intern(new ATermsImpl(world, first.getATermImpl(),
			  (ATermsImpl)next.getATermImpl(),
			  anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public ATerms(World world, ATerm f)

  public ATerms(World world, ATerm f)
  {
    this(world, f, new ATerms(world));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    intern(new ATermsImpl(world, t.getFirst(), t.getNext(), 
			  a == null ? null : a.getATermImpl()));
  }

  //}
  //{ protected void finalize()

  protected void finalize()
  {
    t.decreaseRef();
  }

  //}

  //{ protected void intern(ATermsImpl val)

  protected void intern(ATermsImpl val)
  {
    if(t != null)
      t.decreaseRef();
    t = (ATermsImpl)world.intern(val);
    t.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return t;
  }

  //}
  //{ protected ATermsImpl getATermsImpl()

  protected ATermsImpl getATermsImpl()
  {
    return t;
  }

  //}

  //{ public ATerm getFirst()

  public ATerm getFirst()
  {
    ATermImpl term = t.getFirst();
    switch(term.getType()) {
      case ATermImpl.ATERMS:	return new ATerms((ATermsImpl)term);
      case ATermImpl.APPL:	return new ATermAppl((ATermApplImpl)term);
      case ATermImpl.LIST:	return new ATermList((ATermListImpl)term);
      case ATermImpl.INT:	return new ATermInt((ATermIntImpl)term);
      case ATermImpl.REAL:	return new ATermReal((ATermRealImpl)term);
      case ATermImpl.PLACEHOLDER: return new ATermPlaceholder((ATermPlaceholderImpl)term);
    }
    throw new RuntimeException("Illegal term type: " + term.getType());
  }

  //}
  //{ public ATerms getNext()

  public ATerms getNext()
  {
    return new ATerms(t.getNext());
  }

  //}
  //{ public boolean isEmpty() 

  /**
    * Check if this list is empty.
    */

  public boolean isEmpty() 
  {
    return t.isEmpty();
  }

  //}

  //{ public void setFirst(ATerm first)

  public void setFirst(ATerm first)
  {
    intern(new ATermsImpl(world, first.getATermImpl(), t.getNext()));
  }

  //}
  //{ public void setNext(ATerms next)

  public void setNext(ATerms next)
  {
    intern(new ATermsImpl(world, t.getFirst(), next.getATermsImpl()));
  }

  //}
  //{ public void makeEmpty()

  public void makeEmpty()
  {
    intern(new ATermsImpl(world));
  }

  //}
  //{ public int length()

  /**
    * Determine the length of a list.
    */

  public int length()
  {
    return t.length();
  }

  //}
  //{ public int search(ATerm el)

  /**
    * Search for the first element in a list.
    */

  public int search(ATerm el)
  {
    ATermsImpl cur = t;
    int index = 0;
    while(!cur.isEmpty()) {
      if(cur.getFirst() == el.getATermImpl())
	return index;
       
      index++;
      cur = cur.getNext();
    }

    return -1;
  }

  //}
  //{ public int rsearch(ATerm el)

  /**
    * Search for the last element in a list.
    */

  public int rsearch(ATerm el)
  {
    int index = 0, last = -1;
    for(ATermsImpl cur = t; !cur.isEmpty(); cur = cur.getNext()) {
      if(cur.getFirst() == el.getATermImpl())
	last = index;
      index++;
    }
    return last;
  }

  //}
  //{ public ATerms concat(ATerms rhs)

  /**
    * Concatenate two lists. Returns a new object that contains the
    * concatenation of the two lists.
    */

  public ATerms concat(ATerms rhs)
  {
    return new ATerms(getATermsImpl().concat(rhs.getATermsImpl()));
  }

  //}
  //{ public ATerms append(ATerm el)

  /**
    * Add one element to a list.
    */

  public ATerms append(ATerm el)
  {
    return concat(new ATerms(world, el));  
  }

  //}

    public static ATerms dictCreate() {
	return new ATerms(ATerm.the_world);
    }

    public ATerms dictPut(ATerm key, ATerm value) {
	ATerms tmp = this, result = null;
	ATermList pair, newpair;
	ATerms done = new ATerms(world);
	boolean put_in = false;
	newpair = new ATermList(world, new ATerms(world, key, new ATerms(world, value)));
	// Look for key
	while (! (tmp.isEmpty() || put_in)) {
	    pair = (ATermList)tmp.getFirst();
	    tmp = tmp.getNext();
	    if (pair.getATerms().getFirst().equals(key)) {
		result = done.append(newpair).concat(tmp);
		put_in = true;
	    } else {
		done = done.append(pair);
	    }
	}
	if (! put_in) {
	    result = done.append(newpair);
	}
	return result;
    }

    public ATerm dictGet(ATerm key) {
	ATerms tmp = this;
	ATerm result = null;
	ATermList pair;
	ATerms done = new ATerms(world);
	boolean found = false;
	// Look for key
	while (!(tmp.isEmpty() || found)) {
	    pair = (ATermList)tmp.getFirst();
	    tmp = tmp.getNext();
	    if (pair.getATerms().getFirst().equals(key)) {
		result = pair.getATerms().getNext().getFirst();
		found = true;
	    }
	}
	return result;
    }
    
    public ATerms dictRemove(ATerm key) {
	ATerms tmp = this, result = null;
	ATermList pair;
	ATerms done = new ATerms(world);
	boolean removed = false;
	// Look for key
	while (! (tmp.isEmpty() || removed)) {
	    pair = (ATermList)tmp.getFirst();
	    tmp = tmp.getNext();
	    if (pair.getATerms().getFirst().equals(key)) {
		result = done.concat(tmp);
		removed = true;
	    } else {
		done = done.append(pair);
	    }
	}
	return result;
    }




/* ToDo:
   insert, remove, delete, deleteOnce, replace, index, slice, reverse,
   pairGetKey, pairGetValue
*/

}
