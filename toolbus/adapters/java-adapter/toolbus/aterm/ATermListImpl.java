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
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;
import java.util.*;
import java.io.*;

public class ATermListImpl extends ATermImpl
{
  private ATermsImpl aterms;
  private int hashcode;

  //{ public ATermListImpl(World world, ATermsImpl terms, ATermImpl anno)

  public ATermListImpl(World world, ATermsImpl terms, ATermImpl anno)
  { 
    super(world, anno);
    aterms = terms; 
    updateHashCode();
    aterms.increaseRef();
  }

  //}
  //{ public ATermListImpl(World world, ATermsImpl terms)

  public ATermListImpl(World world, ATermsImpl terms)
  {
    this(world, terms, null);
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
