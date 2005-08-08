package nl.cwi.sen1.tide.tool.support;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JComponent;

public class ProcessStatus
  extends JComponent
  implements ProcessStatusChangeListener
{
  private final static int SIZE = 12;
  private final static Color COLOR_GREEN      = Color.green;
  private final static Color COLOR_RED	      = Color.red;
  private final static Color COLOR_BORDER     = Color.black;
  private final static Color COLOR_BACKGROUND = Color.gray;
  private final static Color COLOR_OFF	      = Color.lightGray;

  private DebugProcess process;

  //{{{ public ProcessStatus(DebugProcess process)

  public ProcessStatus(DebugProcess proc)
  {
    this.process = proc;
    process.addProcessStatusChangeListener(this);
    MouseListener mouseListener =
      new MouseAdapter()
      {
	public void mouseClicked(MouseEvent evt)
	{
	  if (evt.getX() > getSize().width/2) {
	    if (!process.isRunning()) {
	      process.requestResume();
	    }
	  } else {
	    if (process.isRunning()) {
	      process.requestBreak();
	    }
	  }
	}
      };

    addMouseListener(mouseListener);
  }

  //}}}

  //{{{ public void processStatusChanged(DebugProcess process)

  public void processStatusChanged(DebugProcess process)
  {
    repaint();
  }

  //}}}

  //{{{ public Dimension getPreferredSize()

  public Dimension getPreferredSize()
  {
    return new Dimension(SIZE*2 + 3*2, SIZE+2*2);
  }

  //}}}
  //{{{ public Dimension getMinimumSize()

  public Dimension getMinimumSize()
  {
    return getPreferredSize();
  }

  //}}}
  //{{{ public Dimension getMaximumSize()

  public Dimension getMaximumSize()
  {
    return getPreferredSize();
  }

  //}}}

  //{{{ public void paint(Graphics g)

  public void paint(Graphics g)
  {
    Dimension dim = getSize();

    g.setColor(COLOR_BACKGROUND);
    g.fillRect(0, 0, dim.width, dim.height);

    g.setColor(COLOR_BORDER);
    g.drawRect(0, 0, dim.width, dim.height);

    if (!process.isRunning()) {
      g.setColor(COLOR_RED);
    }
    else {
      g.setColor(COLOR_OFF);
    }
    g.fillOval(dim.width/4 - SIZE/2, dim.height/2 - SIZE/2, SIZE, SIZE);

    if (process.isRunning()) {
      g.setColor(COLOR_GREEN);
    }
    else {
      g.setColor(COLOR_OFF);
    }
    g.fillOval((dim.width/4)*3 - SIZE/2, dim.height/2 - SIZE/2, SIZE, SIZE);
  }

  //}}}
}
