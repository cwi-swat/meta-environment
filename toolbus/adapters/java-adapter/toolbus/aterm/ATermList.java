/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

package toolbus.aterm;
import toolbus.util.*;
import java.io.*;

public class ATermList extends ATerm
{
  ATermListImpl list = null;

  //{ protected ATermList(ATermListImpl l)

  /**
    * Create a list from an {\tt ATermListImpl} object.
    */

  protected ATermList(ATermListImpl l)
  {
    super(l.getWorld());
    intern(l);
  }

  //}
  //{ protected ATermList(World world)

  /**
    * Create a new ATermList object.
    */

  protected ATermList(World world)
  {
    super(world);
  }

  //}
  //{ public ATermList(World world, ATerms terms)

  /**
    * Create a list reference from an ATerms reference.
    */

  public ATermList(World world, ATerms terms)
  {
    super(world);
    intern(new ATermListImpl(world, terms.getATermsImpl()));
  }

    public ATermList(ATerms ts) {
	this(the_world,ts);
    }

  //}
  //{ public ATermList(World world, ATerms terms, ATerm anno)

  /**
    * Create a list reference from an ATerms reference.
    */

  public ATermList(World world, ATerms terms, ATerm anno)
  {
    super(world);
    intern(new ATermListImpl(world, terms.getATermsImpl(), 
			 anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    intern(new ATermListImpl(world, list.getATermsImpl(),
			     a == null ? null : a.getATermImpl()));
  }

  //}
  //{ protected void finalize()

  protected void finalize()
  {
    list.decreaseRef();
  }

  //}

  //{ protected void intern(ATermListImpl lst)

  /**
    * Intern this reference to point to a term equal to {\tt lst}.
    */

  protected void intern(ATermListImpl lst)
  {
    if(list != null)
      list.decreaseRef();
    list = (ATermListImpl)world.intern(lst);
    list.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return list;
  }

  //}
  //{ private ATermsImpl getATermListImpl()

  private ATermListImpl getATermListImpl()
  {
    return list;
  }

  //}

  //{ public ATerms getATerms()

  public ATerms getATerms()
  {
    return new ATerms(list.getATermsImpl());
  }

  //}
  //{ public void setATerms(ATerms terms)

  public void setATerms(ATerms terms)
  {
    intern(new ATermListImpl(world, terms.getATermsImpl()));
  }

  //}
  //{ public boolean isEmpty()

  /**
    * Check if this is the empty list.
    */

  public boolean isEmpty()
  {
    return list.isEmpty();
  }

  //}
}
