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

public class ATermReal extends ATerm
{
  ATermRealImpl value = null;

  //{ protected ATermReal(ATermRealImpl val)

  protected ATermReal(ATermRealImpl val)
  {
    super(val.getWorld());
    intern(val);
  }

  //}
  //{ protected ATermReal(World world)

  protected ATermReal(World world)
  {
    super(world);
  }

  //}
  //{ public ATermReal(World world, double r)

  public ATermReal(World world, double r)
  {
    super(world);
    intern(new ATermRealImpl(world, r));
  }

  //}
  //{ public ATermReal(World world, double r, ATerm anno)

  public ATermReal(World world, double r, ATerm anno)
  {
    super(world);
    intern(new ATermRealImpl(world, r, anno == null ? null : anno.getATermImpl()));
  }

  //}
  //{ public void setAnno(ATerm a)

  /**
    * Change the annotation of a term.
    */

  public void setAnno(ATerm a)
  {
    intern(new ATermRealImpl(world, value.getReal(), 
			     a == null ? null : a.getATermImpl()));
  }

  //}
  //{ protected void finalize()

  protected void finalize() throws Throwable
  {
    value.decreaseRef();
  }

  //}

  //{ protected void intern(ATermRealImpl r)

  /**
    * Intern this reference to point to an real term equal to {\tt val}.
    */

  protected void intern(ATermRealImpl val)
  {
    if(value != null)
      value.decreaseRef();
    value = (ATermRealImpl)world.intern(val);
    value.increaseRef();
  }

  //}
  //{ protected ATermImpl getATermImpl()

  protected ATermImpl getATermImpl()
  {
    return value;
  }

  //}
  //{ protected ATermRealImpl getATermRealImpl()

  protected ATermRealImpl getATermRealImpl()
  {
    return value;
  }

  //}

  //{ double getReal()

  double getReal()
  {
    return value.getReal();
  }

  //}
  //{ void setReal()

  void setReal(double r)
  {
    intern(new ATermRealImpl(world, r));
  }

  //}
}
