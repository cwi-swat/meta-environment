
package toolbus.tide;
import toolbus.aterm.*;
import java.util.*;
import java.awt.*;

public class ProcessViewer extends Frame
{
  static final protected int MAX_ADAPTERS = 128;

  private ProcessCanvas viewingArea;
  private Panel toolbar;
  private Panel info;
  private Panel adapterTools;
  private Panel processTools;

  int rows;
  int columns;
  ProcessPicture[][] processGrid;
  DapPicture[][] adapterGrid;
  DapPicture[] adapters = new DapPicture[MAX_ADAPTERS];

  //{ public ProcessViewer()

  /**
   * Construct a new ProcessViewer object.
   */

  public ProcessViewer()
  {
    super("Process Viewer");

    rows = 8;
    columns = 5;
    int width = columns*50+30;
    int height = rows*70+50;

    adapterGrid = new DapPicture[width][height];
    processGrid = new ProcessPicture[width][height];
    resize(width, height);

    //{ Create the toolbar
    toolbar = new Panel();
    toolbar.resize(width, height);
    add(toolbar);
    //}

    viewingArea = new ProcessCanvas(adapterGrid, processGrid);
        viewingArea.resize(width*50+50,height*50+50);
    add(viewingArea);
    show();
    viewingArea.show();

  }

  //}
  //{ public void addDebugAdapter(int dapid, ATermsRef inf)

  /**
   * Add a new debug adapter.
   */

  public void addDebugAdapter(int dapid, ATermsRef inf)
  {
    System.out.println("adding adapter " + dapid + ": " + inf.toString());

    if(dapid > MAX_ADAPTERS)
      throw new IllegalArgumentException("debug-adapter id to large: " + dapid);

    DapPicture dap = new DapPicture(dapid, inf);

    Rectangle geom;
    if(dap.getInfo("multi-process") == null)
      geom = searchGroupSpace(1,1);
    else if(dap.getType().equals("ToolBus"))
      geom = searchGroupSpace(8,2);
    else if(dap.getType().equals("Java"))
      geom = searchGroupSpace(2,2);
    else
      geom = searchGroupSpace(2,2);

    System.out.println("adding dap with geometry: " + geom.toString());
    dap.setGeometry(geom);
    for(int i=geom.x; i<geom.x+geom.width; i++)
      for(int j=geom.y; j<geom.y+geom.height; j++)
	adapterGrid[i][j] = dap;

    adapters[dapid] = dap;
  }

  //}
  //{ public void addProcess(int dapid, DebugProcess process)

  /**
   * A new process is added. Make sure it is visualized.
   */

  public void addProcess(int dapid, int pid, String name)
  {
    ProcessPicture process = new ProcessPicture(pid, name);
    System.out.println("adding process " + process.toString() + " to " + dapid);
    DapPicture dap = adapters[dapid];
    dap.addProcess(process);
    Rectangle r = dap.getGeometry();
    for(int i=0; i<r.width; i++) {
      for(int j=0; j<r.height; j++) {
	if(processGrid[r.y+j][r.x+i] == null) {
	  // Found a free grid point
	  processGrid[r.y+j][r.x+i] = process;
	  System.out.println("adding process to grid-point: " + (r.y+j) + ","
			     + (r.x+i));
	  viewingArea.repaint();
	  return;
	}
      }
    }
    throw new IllegalArgumentException("dap " + dapid + " ran out of space!");
  }

  //}
  //{ public Rectangle searchGroupSpace(int w, int h)

  public Rectangle searchGroupSpace(int w, int h)
  {
    int i = 0;
    if(w > 1)
      i = 1;
    for(; i<columns-w+1; i++)
      for(int j=0; j<rows-h+1; j++) {
	boolean tosmall = false;
	for(int k=0; !tosmall && k<w; k++) {
	  for(int l=0; !tosmall && l<h; l++) {
	    if(adapterGrid[i+k][j+l] != null)
	      tosmall = true;
	    if(processGrid[i+k][j+l] != null)
	      tosmall = true;
	  }
	}
	if(!tosmall)
	  return new Rectangle(i, j, w, h);
      }
    throw new IllegalArgumentException("no more room for processes/groups");
  }

  //}
}

class ProcessCanvas extends Canvas
{
  private ProcessPicture[][] processGrid;
  private DapPicture[][] adapterGrid;

  //{ public ProcessCanvas(DapPicture agrid[][], ProcessPicture[][] pgrid)

  /**
   * Create a ProcessCanvas object.
   */

  public ProcessCanvas(DapPicture[][] agrid, ProcessPicture[][] pgrid)
  {
    processGrid = pgrid;
    adapterGrid = agrid;
  }

  //}
  //{ public void paint(Graphics g)

  /**
   * Paint all processes in a ProcessCanvas.
   */

  public void paint(Graphics g)
  {
    int x, y, w, h;

    System.out.println("painting process-canvas...");
    w = 50;
    h = 74;
    for(int i=0; i<processGrid.length; i++)
      for(int j=0; j<processGrid[0].length; j++) {
	x = 20+i*w;
	y = 40+j*h;
	if(adapterGrid[i][j] != null) {
	  DapPicture dap = adapterGrid[i][j];
	  Rectangle geom = dap.getGeometry();
	  if(geom.x == i && geom.y == j)
	    adapterGrid[i][j].paint(g,x,y,geom.width*w,geom.height*h);
	}
	if(processGrid[i][j] != null)
	  processGrid[i][j].paint(g, x, y, w, h);
      }
  }

  //}
}

class DapPicture extends DebugAdapterInfo
{
  private Rectangle geometry;
  
  //{ public DapPicture(int dapid, ATermsRef info)

  /**
   * Construct a new DapAppearance object.
   */

  public DapPicture(int dapid, ATermsRef info)
  {
    super(dapid, info);
  }

  //}
  //{ public void setGeometry(Rectangle geom)

  /**
   * Change the geometry of this debug adapter picture.
   */

  public void setGeometry(Rectangle geom)
  {
    geometry = geom;
  }

  //}
  //{ public Rectangle getGeometry()

  /**
   * Retrieve the geometry of this debug adapter picture.
   */

  public Rectangle getGeometry()
  {
    return geometry;
  }

  //}
  //{ public void paint(Graphics g, int x, int y, int w, int h)

  /**
   * Paint this debug adapter.
   */

  public void paint(Graphics g, int x, int y, int w, int h)
  {
    g.setColor(Color.gray);
    g.fillRect(x, y, w, h);
    g.setColor(Color.black);
    //String name = getName() + " (" + getType() + ")";
    String name = getType();
    System.out.println("drawing dap name: " + name);
    FontMetrics fm = g.getFontMetrics();
    g.drawString(name, x, y + fm.getAscent());
  }

  //}
}

class ProcessPicture extends DebugProcess
{
  //{ public ProcessPicture(int pid, String name)

  /**
   * Construct a new ProcessString.
   */

  public ProcessPicture(int pid, String name)
  {
    super(pid, name);
    System.out.println("creating new process picture: " + toString());
  }


  //}
  //{ public void paint(Graphics g, int x, int y, int w, int h)

  /**
   * Paint a process, by creating a green circle with a black name in it.
   */

  public void paint(Graphics g, int x, int y, int w, int h)
  {
    System.out.println("painting process: " + toString());
    // y = y + h/12;
    // h = (h*6)/7;
    g.setColor(Color.green);

    int yoff = (h-w)/2;

    g.fillOval(x, y+yoff, w, w);
    g.setColor(Color.black);
    FontMetrics fm = g.getFontMetrics();
    int width = fm.stringWidth(getName());
    g.drawString(getName(), (x+w/2)-width/2, y+yoff+w/2);
    String pid = "" + getPid();
    width = fm.stringWidth(pid);
    g.drawString(pid, (x+w/2)-width/2, y+yoff+w/2+fm.getAscent());
  }

  //}
}




