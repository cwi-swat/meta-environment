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

import toolbus.aterm.*;
import toolbus.tool.*;
import java.io.*;
import java.net.*;

class HelloTool extends Hello
{
  public HelloTool(String[] args) 
    throws UnknownHostException
  {
    super(args);
  }

  protected ATermRef getText() 
	throws ToolException
  {
    ATermPattern pattern = null;
    ATermRef result = null;

    try {
      pattern = new ATermPattern("snd-value(<str>)");
      result = pattern.make("Hello world in Java!\n"); 
    } catch (Exception e) {
      System.err.println("exception: " + e.toString());
      throw new ToolException(this, "parse and/or placeholder error");
    }
    return result;
  }

  protected void recTerminate(ATermRef arg)
  {
    System.out.print("rec-terminate received: ");
    arg.println(System.out);
  }

  public static void main(String[] args)
    throws IOException, UnknownHostException, ToolException
  {
    HelloTool T = new HelloTool(args);
    T.connect();
    T.run();
  }
}
