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

package toolbus.util;
import java.awt.*;

//{ class FancyPanel

/**
  * A FancyPanel is a Panel with a nice 3D border.
  */

public class FancyPanel extends Panel
{
  //{ public void paint(Graphics g)

  /**
    * Paint the 3D border around a FancyPanel.
    */

  public void paint(Graphics g)
  {
    super.paint(g);
    Insets insets = this.insets();
    int x=0, y=0;
    int w = size().width-1;
    int h = size().height-1;

    g.setColor(getBackground());
    for(int i=0; i<2; i++) {
      g.draw3DRect(x++, y++, w, h,true);
      w -= 2;
      h -= 2;
    }
  }

  //}
  //{ public Insets insets()

  /**
    * Allocate space for the fancy borders.
    */

  public Insets insets()
  {
    Insets insets = super.insets();
    insets.bottom += 2;
    insets.left += 2;
    insets.top += 2;
    insets.right += 2;
    return insets;
  }

  //}
}

//}
