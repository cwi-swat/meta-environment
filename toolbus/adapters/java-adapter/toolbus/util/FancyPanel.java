
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
