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

public class ATermIntImpl extends ATermImpl
{
  private int val;

  public ATermIntImpl(World world, int v, ATermImpl anno)
  { 
    super(world, anno);
    val = v;
  }

  public ATermIntImpl(World world, int v)
  { 
    this(world, v, null);
  }

  public Object clone() 
  {
    ATermIntImpl i = (ATermIntImpl)super.clone();
    i.val = val;
    return i;
  }

  public boolean equals(Object obj) 
  {
    if(obj instanceof ATermIntImpl)
	return val == ((ATermIntImpl)obj).val && super.equals(obj);
    return false;
  }

  public int hashCode()			{ return val;	}
  public int getType()			{ return ATermImpl.INT; }
  public int getInt()			{ return val;	}

  public void print(PrintWriter w) {
    w.print(val);
    super.print(w);
  }

  public void write(OutputStream o) throws java.io.IOException {
    String str = "" + val;
    for(int i=0; i<str.length(); i++)
      o.write(str.charAt(i));
    super.write(o);
  }

  public int printSize() {
   String tmp = new String(Integer.toString(val));
    return super.printSize() + tmp.length();
  }

  public int size()		{ return 1 + super.size(); }
}
