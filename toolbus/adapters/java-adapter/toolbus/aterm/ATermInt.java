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
import java.util.*;
import java.io.*;

public class ATermInt extends ATerm
{
  ATermIntImpl value = null;

  //{ protected ATermInt(ATermIntImpl val)

  protected ATermInt(ATermIntImpl val)
  {
    super(val.getWorld());
    intern(val);
  }

  //}
  //{ protected ATermInt(World world)

  /**
    * Construct a new ATermInt object that is initially empty.
    */

  protected ATermInt(World world)
  {
    super(world);
  }

  //}
  //{ public ATermInt(World world, int i)

  public ATermInt(World world, int i)
  {
    super(world);
    intern(new ATermIntImpl(world, i));
  }

  //}
  //{ public ATermInt(World world, int i, ATerm anno)

  public ATermInt(World world, int i, ATerm anno)
  {
    super(world);
    intern(new ATermIntImpl(world, i, anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public void setAnno(ATermImpl a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    intern(new ATermIntImpl(world, value.getInt(), 
			    a == null ? null:a.getATermImpl()));
  }

  //}
  //{ protected void finalize()

  protected void finalize()
    throws Throwable
  {
    value.decreaseRef();
    super.finalize();
  }

  //}

  //{ protected void intern(ATermIntImpl val)
  
  /**
    * Intern this reference to point to an integer term equal to {\tt val}.
    */

  protected void intern(ATermIntImpl val)
  {
    if(value != null)
      value.decreaseRef();
    value = (ATermIntImpl)world.intern(val);
    value.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return value;
  }

  //}
  //{ protected ATermIntImpl getATermIntImpl()

  protected ATermIntImpl getATermIntImpl()
  {
    return value;
  }

  //}

  //{ public int getInt()

  public int getInt()
  {
    return value.getInt();
  }

  //}
  //{ public int setInt()

  public void setInt(int i)
  {
    intern(new ATermIntImpl(world, i));
  }

  //}
}
