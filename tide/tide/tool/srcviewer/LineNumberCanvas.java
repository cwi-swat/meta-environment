package tide.tool.srcviewer;

import java.util.*;
import java.awt.*;
import javax.swing.*;

import tide.tool.support.*;

class LineNumberCanvas
  extends JComponent
{
  private final static int BORDER = 2;
  JTextArea text;
  FontMetrics fontMetrics;
  FontMetrics sourceMetrics;
  int cpe;
  Polygon cpePoly;

  //{{{ public LineNumberCanvas(JTextArea text)

  public LineNumberCanvas(JTextArea text)
  {
    this.text = text;
  }

  //}}}

  //{{{ private void checkMetrics()

  private void checkMetrics()
  {
    if (fontMetrics != getFontMetrics(getFont())
	|| sourceMetrics != text.getFontMetrics(text.getFont())) {
      fontMetrics = getFontMetrics(getFont());
      sourceMetrics = text.getFontMetrics(text.getFont());

      cpePoly = new Polygon();
      cpePoly.addPoint(0, 0);
      cpePoly.addPoint(fontMetrics.stringWidth("1999"),
		       sourceMetrics.getHeight()/2);
      cpePoly.addPoint(0, sourceMetrics.getHeight());
    }
  }

  //}}}

  //{{{ public void paint(Graphics g)

  public void paint(Graphics g)
  {
    Dimension dim = getSize();
    Rectangle clip = g.getClipBounds();

    checkMetrics();

    g.setColor(getBackground());
    g.fillRect(clip.x, clip.y, clip.width, clip.height);

    int line = clip.y/sourceMetrics.getHeight();
    int y =  line * sourceMetrics.getHeight();
    line++;

    while (y < (clip.y + clip.height)) {
      if (line == cpe) {
	g.setColor(SourceFileViewer.COLOR_CPE);
	cpePoly.translate(0, y);
	g.fillPolygon(cpePoly);
	cpePoly.translate(0, -y);
      }

      g.setColor(getForeground());
      String label = String.valueOf(line++);
      g.drawString(label, dim.width-fontMetrics.stringWidth(label)-BORDER,
		   y+sourceMetrics.getMaxAscent());
      y += sourceMetrics.getHeight();
    }

  }

  //}}}
  //{{{ public Dimension getPreferredSize()

  public Dimension getPreferredSize()
  {
    checkMetrics();

    return new Dimension(fontMetrics.stringWidth("1999") + BORDER, 0);
  }

  //}}}
  //{{{ public Dimension getMinimumSize()

  public Dimension getMinimumSize()
  {
    return getPreferredSize();
  }

  //}}}

  //{{{ public void setCpe(int line)

  public void setCpe(int line)
  {
    cpe = line;
    repaint();
  }

  //}}}
  //{{{ public void clearCpe()

  public void clearCpe()
  {
    cpe = -1;
    repaint();
  }

  //}}}
}

