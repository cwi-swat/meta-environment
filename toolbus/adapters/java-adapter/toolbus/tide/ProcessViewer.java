
package toolbus.tide;
import toolbus.tool.*;
import toolbus.aterm.*;
import java.util.*;
import java.awt.*;

//{ public class ProcessViewer extends Frame

/**
  * The ProcessViewer class represents a graphical view on all
  * the adapters and processes in the system. It offers
  * mouse interaction and a number of menus to perform
  * actions on the processes, and to start other tools.
  */
public class ProcessViewer extends Frame
{
  //{ constants

  static final protected int MAX_ADAPTERS = 128;
  static final public int TOOL = 1;
  static final public int PROCESS = 2;
  static final public int PROCESSES = 4;

  //}
  //{ UI components

  static public Font defaultFont;

  private Tool tool;
  private ProcessCanvas viewingArea;

  private ProcessPanel processPanel;
  private AdapterPanel adapterPanel;
  private SelectionPanel selectionPanel;

  private ProcessViewerMenuBar menuBar;
  private GridBagLayout layout;

  //}
  //{ processes and adapters

  private ProcessPicture currentProcess;
  private DapPicture currentAdapter;
  private int selectedProcesses = 0;

  int rows;
  int columns;
  ProcessPicture[][] processGrid;
  DapPicture[][] adapterGrid;
  DapPicture[] adapters = new DapPicture[MAX_ADAPTERS];
  Hashtable[] processes = new Hashtable[MAX_ADAPTERS];

  //}
  //{ Some term patterns

  ATermPattern patternShutdown;
  ATermPattern patternButton;

  //}

  //{ public ProcessViewer()

  /**
   * Construct a new ProcessViewer object.
   */

  public ProcessViewer(Tool tool)
  {
    super("Process Viewer");
    this.tool = tool;

    // Initialize some term patterns
    try {
      patternShutdown = new ATermPattern("snd-event(tide-shutdown)");
      patternButton = new ATermPattern("snd-event(button(<term>,<term>," +
				       "debug-adapter(<int>)))");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }

    // Change the default font
    defaultFont = new Font("Helvetica", Font.BOLD, 12);
    setFont(defaultFont);

    // Add a menu bar. This menu bar takes care
    // of the dynamic nature of the 'Tools' menu.
    menuBar = new ProcessViewerMenuBar();
    setMenuBar(menuBar);

    // Calculate the geometry of the process-viewer main window
    rows = 5;
    columns = 8;
    int width = columns*ProcessCanvas.CEL_WIDTH+156;
    int height = rows*ProcessCanvas.CEL_HEIGHT+50;

    adapterGrid = new DapPicture[columns][rows];
    processGrid = new ProcessPicture[columns][rows];

    layout = new GridBagLayout();
    setLayout(layout);

    processPanel = new ProcessPanel();
    adapterPanel = new AdapterPanel();
    selectionPanel = new SelectionPanel();
    viewingArea = new ProcessCanvas(this);
    FancyPanel dummy = new FancyPanel();

    add(processPanel);
    add(adapterPanel);
    add(selectionPanel);
    add(viewingArea);
    add(dummy);

    GridBagConstraints c = new GridBagConstraints();
    c.gridx = 0;
    c.gridy = 0;
    c.fill = GridBagConstraints.BOTH;
    layout.setConstraints(processPanel, c);
    c.gridy = 1;
    layout.setConstraints(adapterPanel, c);
    c.gridy = 2;
    layout.setConstraints(selectionPanel, c);
    c.gridy = 3;
    layout.setConstraints(dummy, c);

    c = new GridBagConstraints();
    c.fill = GridBagConstraints.BOTH;
    c.gridwidth = GridBagConstraints.REMAINDER;
    c.gridheight = GridBagConstraints.REMAINDER;
    c.weightx = 1;
    c.weighty = 1;
    layout.setConstraints(viewingArea, c);

    resize(width, height);
    show();

    updateInfo();
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

    DapPicture dap = new DapPicture(dapid, inf, tool);

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
    processes[dapid] = new Hashtable();
  }

  //}
  //{ public void addProcess(int dapid, int pid, String name)

  /**
   * A new process is added. Make sure it is visualized.
   */

  public void addProcess(int dapid, int pid, String name)
  {
    DapPicture dap = adapters[dapid];

    if(processes[dapid].get(new Integer(pid)) != null)
      return;

    ProcessPicture process = new ProcessPicture(pid, name, dap);
    System.out.println("adding process " + process.toString() + " to " + dapid);
    dap.addProcess(process);
    Rectangle r = dap.getGeometry();
    for(int i=0; i<r.width; i++) {
      for(int j=0; j<r.height; j++) {
	if(processGrid[r.x+i][r.y+j] == null) {
	  // Found a free grid point
	  processGrid[r.x+i][r.y+j] = process;
	  System.out.println("adding process to grid-point: " + (r.x+i) + ","
			     + (r.y+j));
	  viewingArea.repaint();
	  processes[dapid].put(new Integer(pid), process);
	  return;
	}
      }
    }
    throw new IllegalArgumentException("dap " + dapid + " ran out of space!");
  }

  //}
  //{ public void addTool(String name, ATermRef tool, ATermRef event, int flag)

  /**
    * Add a tool. Just add an item to the Tool menu.
    */
  
  public void addTool(String name, ATermRef tool, ATermRef event, int flags)
  {
    menuBar.addTool(name, tool, event, flags);
  }

  //}
  //{ public Rectangle searchGroupSpace(int w, int h)

  public Rectangle searchGroupSpace(int w, int h)
  {
    for(int i=0; i<columns-w+1; i++)
      for(int j=(w>1 ? 1 : 0); j<rows-h+1; j++) {
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
  //{ public ProcessPicture processAt(int x, int y)

  /**
    * Return the process at grid point (x,y).
    */

  public ProcessPicture processAt(int x, int y)
  {
    return processGrid[x][y];
  }

  //}
  //{ public DapPicture adapterAt(int x, int y)

  /**
    * Return the adapter at grid point (x,y).
    */

  public DapPicture adapterAt(int x, int y)
  {
    return adapterGrid[x][y];
  }

  //}
  //{ public int getRows()

  /**
    * Retrieve the number of grid rows in the viewer.
    */

  public int getRows()
  {
    return rows;
  }
  
  //}
  //{ public int getColumns()

  /**
    * Retrieve the number of grid columns in this adapter.
    */

  public int getColumns()
  {
    return columns;
  }

  //}
  //{ public void clearProcessSelection()

  /**
    * Mark all processes as 'not-selected'.
    * Note that the processes are not redrawn yet.
    */

  public void clearProcessSelection()
  {
    for(int i=0; i<columns; i++)
      for(int j=0; j<rows; j++)
	if(processGrid[i][j] != null)
	  processGrid[i][j].setSelected(false);
    updateInfo();
  }

  //}
  //{ public void selectProcess(int x, int y, boolean on)

  /**
    * Change the selection status of one process.
    */

  public void selectProcess(int x, int y, boolean on)
  {
    if(on != processGrid[x][y].isSelected()) {
      processGrid[x][y].setSelected(on);
      if(on)
	selectedProcesses++;
      else
	selectedProcesses--;
      updateInfo();
    }
  }

  //}
  //{ public void setCurrentProcess(int x, int y)

  /**
    * Change the current process.
    */

  public void setCurrentProcess(int x, int y)
  {
    if(currentProcess != null)
      currentProcess.setCurrent(false);
    currentProcess = processGrid[x][y];
    if(currentProcess != null)
      currentProcess.setCurrent(true);
    updateInfo();
  }

  //}
  //{ public void setCurrentAdapter(int x, int y)

  /**
    * Change the current adapter.
    */

  public void setCurrentAdapter(int x, int y)
  {
    if(currentAdapter != null)
      currentAdapter.setCurrent(false);

    currentAdapter = adapterGrid[x][y];

    if(currentAdapter != null)
      currentAdapter.setCurrent(true);

    updateInfo();
  }

  //}
  //{ public void clearCurrentProcess()

  /**
    * The current process is no longer considered current.
    */

  public void clearCurrentProcess()
  {
    if(currentProcess != null) {
      currentProcess.setCurrent(false);
      currentProcess = null;
    }
    updateInfo();
  }

  //}
  //{ public void clearCurrentAdapter()

  /**
    * The current adapter is no longer considered current.
    */

  public void clearCurrentAdapter()
  {
    if(currentAdapter != null) {
      currentAdapter.setCurrent(false);
      currentAdapter = null;
    }
    updateInfo();
  }

  //}
  //{ public void updateInfo()

  /**
    * Update the information windows.
    */

  public void updateInfo()
  {
    // Update the process panel
    processPanel.update(currentProcess);

    int procs = 0;
    int running = 0;

    if(currentAdapter == null)
      adapterPanel.update(null, 0, 0);
    else {
      // Calculate the number of (running) processes in the current adapter
      Rectangle rect = currentAdapter.getGeometry();
      for(int i=0; i<rect.width; i++) {
	for(int j=0; j<rect.height; j++) {
	  int col = i+rect.x;
	  int row = j+rect.y;
	  if(processGrid[col][row] != null) {
	    procs++;
	    if(processGrid[col][row].isRunning())
	      running++;
	  }
	}
      }
      // update the adapter panel
      adapterPanel.update(currentAdapter, procs, running);
    }

    procs = 0;
    running = 0;

    // Calculate the number of selected (running) processes.
    for(int i=0; i<columns; i++) {
      for(int j=0; j<rows; j++) {
	if(processGrid[i][j] != null && processGrid[i][j].isSelected()) {
	  procs++;
	  if(processGrid[i][j].isRunning())
	    running++;
	}
      }
    }
    // update the selection panel
    selectionPanel.update(procs, running);
  }

  //}
  //{ public ProcessPicture getCurrentProcess()

  /**
    * Retrieve the current process.
    */

  ProcessPicture getCurrentProcess()
  {
    return currentProcess;
  }

  //}
  //{ public DapPicture getCurrentAdapter()

  /**
    * Retrieve the current adapter.
    */

  DapPicture getCurrentAdapter()
  {
    return currentAdapter;
  }

  //}

  //{ public void changeExecState(int dapid, int pid, int es)

  /**
    * Change the execution state of a process.
    */

  public void changeExecState(int dapid, int pid, int es)
  {
    ProcessPicture proc = (ProcessPicture)processes[dapid].get(new Integer(pid));
    System.out.println("change exec-state: " + proc.toString() + " to: " + es);
  }

  //}

  //{ public boolean action(Event evt, Object what)

  /**
    * React on events like the pressing of a button, or the
    * selection of a menu item.
    */

  public boolean action(Event evt, Object what)
  {
    System.out.println("action: evt=" + evt.toString() + ", what=" + what.toString());
    if(what.equals("Quit")) {
      try {
	tool.send(patternShutdown.make());
      } catch (ToolException e) {
	System.err.println("cannot send to ToolBus, giving up!");
	System.exit(1);
      }
      return true;
    }
    if(evt.target instanceof ToolMenuItem) {
      ToolMenuItem item = (ToolMenuItem)evt.target;
      if(currentAdapter != null) {
	try {
	  tool.send(patternButton.make(item.getTool(), item.getEvent(),
				       new Integer(currentAdapter.getId())));
	} catch (ToolException e) {
	  System.err.println("cannot send to ToolBus, giving up!");
	  System.exit(1);
	}
      }
      return true;
    }

    return false;
  }

  //}
}

//}

//{ class ProcessCanvas

class ProcessCanvas extends Canvas
{
  public static final int CEL_WIDTH = 64;
  public static final int CEL_HEIGHT = 84;
  private static final int CEL_XOFF = 4;
  private static final int CEL_YOFF = 4;

  private ProcessViewer viewer;
  private ProcessPicture[][] processGrid;
  private DapPicture[][] adapterGrid;

  //{ public ProcessCanvas(ProcessViewer viewer)

  /**
   * Create a ProcessCanvas object.
   */

  public ProcessCanvas(ProcessViewer viewer)
  {
    this.viewer = viewer;

    // Change the default font
    setFont(new Font("Helvetica", Font.BOLD, 10));
  }

  //}
  //{ public void paint(Graphics g)

  /**
   * Paint all processes in a ProcessCanvas.
   */

  public void paint(Graphics g)
  {
    int x, y, w, h;

    // First, we draw the borders
    x=0;
    y=0;
    w = size().width-1;
    h = size().height-1;

    g.setColor(getBackground());
    for(int i=0; i<2; i++) {
      g.draw3DRect(x++, y++, w, h,true);
      w -= 2;
      h -= 2;
    }

    // We draw the processes and adapters.
    w = CEL_WIDTH;
    h = CEL_HEIGHT;
    for(int i=0; i<viewer.getColumns(); i++) {
      for(int j=0; j<viewer.getRows(); j++) {
	x = CEL_XOFF+i*w;
	y = CEL_YOFF+j*h;
	if(viewer.adapterAt(i,j) != null) {
	  DapPicture dap = viewer.adapterAt(i,j);
	  Rectangle geom = dap.getGeometry();
	  if(geom.x == i && geom.y == j)
	    viewer.adapterAt(i,j).paint(g,x,y,geom.width*w,geom.height*h);
	}
	if(viewer.processAt(i,j) != null)
	  viewer.processAt(i,j).paint(g, x+4, y+4, w-8, h-8);
      }
    }


  }

  //}
  //{ public boolean mouseDown(Event evt, int x, int y)

  /**
    * The user pushed a mouse button.
    */

  public boolean mouseDown(Event evt, int x, int y)
  {
    boolean selected;
    int cellx = (x-CEL_XOFF)/CEL_WIDTH;
    int celly = (y-CEL_YOFF)/CEL_HEIGHT;
    int xoff = (x - CEL_XOFF) - (cellx * CEL_WIDTH);
    int yoff = (y - CEL_YOFF) - (celly * CEL_HEIGHT);

    System.out.println("mouse down at " + cellx + "," + celly);
    System.out.println("xoff = " + xoff + ", yoff = " + yoff);

    if(cellx >= 0 && cellx < viewer.getColumns() &&
       celly >= 0 && celly < viewer.getRows()) {
      if(viewer.processAt(cellx,celly) != null && 
	 viewer.processAt(cellx,celly).hit(x, y)) {
	if(evt.shiftDown()) {
	  // Manipulate the selection
	  selected = viewer.processAt(cellx, celly).isSelected();
	  viewer.selectProcess(cellx, celly, !selected);
	} else {
	  if(viewer.getCurrentProcess() == viewer.processAt(cellx, celly))
	    viewer.clearCurrentProcess();
	  else
	    viewer.setCurrentProcess(cellx, celly);
	}
	repaint();
      } else {
	if(viewer.adapterAt(cellx,celly) != null) {
	   if(viewer.adapterAt(cellx,celly) == viewer.getCurrentAdapter())
	     viewer.clearCurrentAdapter();
	   else
	     viewer.setCurrentAdapter(cellx, celly);
	  repaint();
	}
      }
    }
    return true;
  }

  //}
}

//}
//{ class DapPicture

class DapPicture extends RemoteDebugAdapterInfo
{
  private Rectangle geometry;
  private boolean selected;
  private boolean current;
  
  //{ public DapPicture(int dapid, ATermsRef info, Tool tool)

  /**
   * Construct a new DapAppearance object.
   */

  public DapPicture(int dapid, ATermsRef info, Tool tool)
  {
    super(dapid, info, tool);
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
    g.fillRect(x+2, y+2, w-4, h-4);
    g.setColor(Color.black);

    //String name = getName() + " (" + getType() + ")";
    String name = getType();
    FontMetrics fm = g.getFontMetrics();
    g.drawString(name, x+2, y+2 + fm.getAscent());

    // When this object is selected, draw an orange rectangle around it.
    if(isSelected()) {
      g.setColor(Color.orange);
      g.drawRect(x+2, y+2, w-4, h-4);
    }

    // If it is the current object, we also draw a red rectangle around it.
    if(isCurrent()) {
      g.setColor(Color.red);
      g.drawRect(x, y, w, h);
    }
    
  }

  //}
  //{ public void setSelected(boolean on)

  /**
    * Change the selection status of this adapter.
    */

  public void setSelected(boolean on)
  {
    selected = on;
  }

  //}
  //{ public void setCurrent(boolean on)

  /**
    * Change the 'current' status of this adapter.
    */

  public void setCurrent(boolean on)
  {
    current = on;
  }

  //}
  //{ public boolean isSelected()

  /**
    * Retrieve the 'selected' status of this adapter.
    */

  public boolean isSelected()
  {
    return selected;
  }

  //}
  //{ public boolean isCurrent()

  /**
    * Retrive the 'current' status of this adapter.
    */

  public boolean isCurrent()
  {
    return current;
  }

  //}
  //{ public void start(String mode)

  /**
    * Start the remote process.
    */

  public void start(String mode)
  {
    ATermRef procs = new ATermApplRef("all", null);
    ATermsRef actions = new ATermsRef(new ATermApplRef(mode, null), null);

    sendExecuteActions(procs, new ATermListRef(actions));
  }

  //}
  //{ public void stop()

  /**
    * Stop the remote process.
    */

  public void stop()
  {
    ATermRef procs = new ATermApplRef("all", null);
    ATermsRef actions = new ATermsRef(new ATermApplRef("stop", null), null);

    sendExecuteActions(procs, new ATermListRef(actions));
  }

  //}
}

//}
//{ class ProcessPicture

class ProcessPicture extends DebugProcess
{
  private int centerX;
  private int centerY;
  private int radius;
  private boolean selected;
  private boolean current;
  private RemoteDebugAdapterInfo adapter;

  //{ public ProcessPicture(int pid, String name, RemoteDebugAdapterInfo dap)

  /**
   * Construct a new ProcessString.
   */

  public ProcessPicture(int pid, String name, RemoteDebugAdapterInfo dap)
  {
    super(pid, name);
    this.adapter = dap;
    System.out.println("creating new process picture: " + toString());
  }

  //}
  //{ public void paint(Graphics g, int x, int y, int w, int h)

  /**
   * Paint a process, by creating a green circle with a black name in it.
   */

  public void paint(Graphics g, int x, int y, int w, int h)
  {
    g.setColor(Color.green);

    w -= 4;
    int xoff = 2;
    int yoff = (h-w)/2;

    // First, fill the circle
    g.fillOval(x+xoff, y+yoff, w, w);

    // If this process is selected, draw an orange circle around it.
    if(isSelected()) {
      g.setColor(Color.orange);
      g.drawOval(x+xoff, y+yoff, w, w);
    }

    // The current process has an additional red circle around the orange
    // one.
    if(isCurrent()) {
      g.setColor(Color.red);
      g.drawOval(x+xoff-2, y+yoff-2, w+4, w+4);
    }

    // needed for 'hit' checking later on:
    radius = w/2;
    centerX = x + xoff + radius;
    centerY = y + yoff + radius;

    g.setColor(Color.black);
    FontMetrics fm = g.getFontMetrics();
    int width = fm.stringWidth(getName());
    g.drawString(getName(), (x+xoff+w/2)-width/2, y+yoff+w/2);
    String pid = "" + getPid();
    width = fm.stringWidth(pid);
    g.drawString(pid, (x+xoff+w/2)-width/2, y+yoff+w/2+fm.getAscent());
  }

  //}
  //{ public boolean hit(int x, int y)

  /**
    * Check if a certain point (relative to the cell origin)
    * is within the boundaries of this process.
    */

  public boolean hit(int x, int y)
  {
    int xdiff = x - centerX;
    int ydiff = y - centerY;
    
    if((xdiff*xdiff + ydiff*ydiff) < radius*radius)
      return true;
    return false;
  }

  //}
  //{ public void setSelected(boolean on)

  /**
    * Change the selection status of this process.
    */

  public void setSelected(boolean on)
  {
    selected = on;
  }

  //}
  //{ public void setCurrent(boolean on)

  /**
    * Change the 'current' status of this process.
    */

  public void setCurrent(boolean on)
  {
    current = on;
  }

  //}
  //{ public boolean isSelected()

  /**
    * Retrieve the 'selected' status of this process.
    */

  public boolean isSelected()
  {
    return selected;
  }

  //}
  //{ public boolean isCurrent()

  /**
    * Retrive the 'current' status of this process.
    */

  public boolean isCurrent()
  {
    return current;
  }

  //}
  //{ public void start(String mode)

  /**
    * Start the remote process.
    */

  public void start(String mode)
  {
    ATermsRef procs = new ATermsRef(new ATermIntRef(getPid()));
    ATermsRef actions = new ATermsRef(new ATermApplRef(mode, null), null);

    adapter.sendExecuteActions(new ATermListRef(procs), 
			       new ATermListRef(actions));
  }

  //}
  //{ public void stop()

  /**
    * Stop the remote process.
    */

  public void stop()
  {
    ATermsRef procs = new ATermsRef(new ATermIntRef(getPid()));
    ATermsRef actions = new ATermsRef(new ATermApplRef("stop", null), null);

    adapter.sendExecuteActions(new ATermListRef(procs),
			       new ATermListRef(actions));
  }

  //}
}

//}

//{ class FancyPanel

/**
  * A FancyPanel is a Panel with a nice 3D border.
  */

class FancyPanel extends Panel
{
  //{ public void paint(Graphics g)

  /**
    * Paint the 3D border around a FancyPanel.
    */

  public void paint(Graphics g)
  {
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
//{ class ProcessPanel

/**
  * The ProcessPanel displays information about the current process.
  */

class ProcessPanel extends FancyPanel
{
  private Label state;
  private Label process;
  private Choice mode;
  private Button start;
  private Button stop;
  private GridBagLayout layout;
  private ProcessPicture currentProcess;

  //{ public ProcessPanel()

  /**
    * Construct a new ProcessPanel object.
    */

  public ProcessPanel()
  {
    layout = new GridBagLayout();
    setLayout(layout);

    GridBagConstraints c = new GridBagConstraints();

    Panel titlePanel = new Panel();
    titlePanel.setLayout(new FlowLayout(FlowLayout.LEFT, 0, 0));
    Label titleLabel = new Label("Process:", Label.LEFT);
    titlePanel.add(titleLabel);
    process = new Label("<none>");
    titlePanel.add(process);
    add(titlePanel);
    c.gridx = 0;
    c.gridy = 0;
    c.fill = GridBagConstraints.HORIZONTAL;
    layout.setConstraints(titlePanel, c);
    

    Panel statePanel = new Panel();
    statePanel.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 0));
    Label stateLabel = new Label("state:");
    statePanel.add(stateLabel);
    state = new Label("unknown");
    statePanel.add(state);
    add(statePanel);
    c.gridy = 1;
    layout.setConstraints(statePanel, c);

    Panel choicePanel = new Panel();
    choicePanel.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 0));
    mode = new Choice();
    mode.addItem("single-step");
    mode.addItem("step-over");
    mode.addItem("run-until-parent");
    mode.addItem("run");
    choicePanel.add(mode);
    add(choicePanel);
    c.gridy = 2;
    layout.setConstraints(choicePanel, c);

    Panel buttonPanel = new Panel();
    buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 0));
    start = new Button("Start");
    stop = new Button("Stop");
    buttonPanel.add(start);
    buttonPanel.add(stop);
    c.gridy = 3;
    layout.setConstraints(buttonPanel, c);
    add(buttonPanel);
  }

//}
  //{ public update(ProcessPicture process)

  /**
    * Change the contents of this process panel to display information
    * about a process.
    */

  public void update(ProcessPicture proc)
  {
    currentProcess = proc;
    if(proc == null) {
      start.disable();
      stop.disable();
    } else {
      state.setText(proc.getExecStateString());
      process.setText(proc.toString());
      if(proc.isRunning()) {
	start.disable();
	stop.enable();
      } else {
	start.enable();
	stop.disable();
      }
    }
    invalidate();
    state.getParent().validate();
    process.getParent().validate();
  }

  //}
  //{ public boolean action(Event evt, Object what)

  /**
    * The user has probably pushed a button.
    */

  public boolean action(Event evt, Object what)
  {
    if(currentProcess != null) {
      if(what.equals("Start")) {
	currentProcess.start(mode.getSelectedItem());
	return true;
      }
      if(what.equals("Stop")) {
	currentProcess.stop();
	return true;
      }
    }
    return false;
  }

  //}
}

//}
//{ class AdapterPanel

class AdapterPanel extends FancyPanel
{
  private Label adapter;
  private Label state;
  private Choice mode;
  private Button start;
  private Button stop;
  private GridBagLayout layout;
  private DapPicture currentAdapter;

  //{ public AdapterPanel()

  /**
    * Construct a new AdapterPanel object.
    */

  public AdapterPanel()
  {
    layout = new GridBagLayout();
    setLayout(layout);

    GridBagConstraints c = new GridBagConstraints();

    Panel titlePanel = new Panel();
    titlePanel.setLayout(new FlowLayout(FlowLayout.LEFT, 0, 0));
    Label titleLabel = new Label("Adapter:", Label.LEFT);
    titlePanel.add(titleLabel);
    adapter = new Label("<none>");
    titlePanel.add(adapter);
    c.gridx = 0;
    c.gridy = 0;
    c.fill = GridBagConstraints.HORIZONTAL;
    add(titlePanel);
    layout.setConstraints(titlePanel, c);

    Panel statePanel = new Panel();
    statePanel.setLayout(new FlowLayout(FlowLayout.LEFT, 0, 0));
    state = new Label("0 procs, 0 running");
    statePanel.add(state);
    add(statePanel);
    c.gridy = 1;
    layout.setConstraints(statePanel, c);

    Panel modePanel = new Panel();
    modePanel.setLayout(new FlowLayout(FlowLayout.LEFT, 0, 0));
    mode = new Choice();
    mode.addItem("single-step");
    mode.addItem("step-over");
    mode.addItem("run-until-parent");
    mode.addItem("run");
    modePanel.add(mode);
    add(modePanel);
    c.gridy = 2;
    layout.setConstraints(modePanel, c);

    Panel buttonPanel = new Panel();
    buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 0));
    start = new Button("Start");
    stop = new Button("Stop");
    buttonPanel.add(start);
    buttonPanel.add(stop);
    add(buttonPanel);
    c.gridy = 3;
    layout.setConstraints(buttonPanel, c);
  }

  //}
  //{ public void update(DapPicture adapter, int procs, int running)

  /**
    * Update the AdapterPanel to display characteristics about an adapter.
    */

  public void update(DapPicture dap, int procs, int running)
  {
    currentAdapter = dap;
    if(dap == null) {
      adapter.setText("<none>");
      state.setText("0 procs, 0 running");
      start.disable();
      stop.disable();
    } else {
      adapter.setText(dap.getType());
      state.setText("" + procs + " procs, " + running + " running");
      start.enable();
      if(running == 0)
	stop.disable();
      else
	stop.enable();
    }
    invalidate();
    adapter.getParent().validate();
    state.getParent().validate();
  }

  //}
  //{ public boolean action(Event evt, Object what)

  /**
    * The user has probably pushed a button.
    */

  public boolean action(Event evt, Object what)
  {
    if(currentAdapter != null) {
      if(what.equals("Start")) {
	currentAdapter.start(mode.getSelectedItem());
	return true;
      }
      if(what.equals("Stop")) {
	currentAdapter.stop();
	return true;
      }
    }
    return false;
  }

  //}
}

//}
//{ class SelectionPanel

/**
  * The SelectionPanel displays information about the group of
  * currently selected processes.
  */

class SelectionPanel extends FancyPanel
{
  private Label state;
  private Choice mode;
  private Button start;
  private Button stop;
  private GridBagLayout layout;

  //{ public SelectionPanel()

  /**
    * Construct a new SelectionPanel object.
    */

  public SelectionPanel()
  {
    layout = new GridBagLayout();
    setLayout(layout);

    GridBagConstraints c = new GridBagConstraints();

    Label titleLabel = new Label("Selected processes:", Label.LEFT);
    add(titleLabel);
    c.gridx = 0;
    c.gridy = 0;
    c.fill = GridBagConstraints.HORIZONTAL;
    layout.setConstraints(titleLabel, c);

    Panel statePanel = new Panel();
    statePanel.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 0));
    state = new Label("0 procs, 0 running");
    statePanel.add(state);
    add(statePanel);
    c.gridy = 1;
    layout.setConstraints(statePanel, c);

    Panel modePanel = new Panel();
    modePanel.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 0));
    mode = new Choice();
    mode.addItem("single-step");
    mode.addItem("step-over");
    mode.addItem("run-until-parent");
    mode.addItem("run");
    modePanel.add(mode);
    add(modePanel);
    c.gridy = 2;
    layout.setConstraints(modePanel, c);

    Panel buttonPanel = new Panel();
    buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 0));
    start = new Button("Start");
    stop = new Button("Stop");
    buttonPanel.add(start);
    buttonPanel.add(stop);
    add(buttonPanel);
    c.gridy = 3;
    layout.setConstraints(buttonPanel, c);
  }

  //}
  //{ public void update(int procs, int running)

  /**
    * Update the SelectionPanel to change the total number of
    * selected processes, and the number of them that are running.
    */

  public void update(int procs, int running)
  {
    state.setText("" + procs + "procs, " + running + "running");
    if(procs == 0) {
      start.disable();
      stop.disable();
    } else {
      start.enable();
      if(running == 0)
	stop.disable();
      else
	stop.enable();
    }
  }

  //}
  //{ public boolean action(Event evt, Object what)

  /**
    * The user has probably pushed a button.
    */

  public boolean action(Event evt, Object what)
  {
    if(what.equals("Start")) {
      System.out.println("Start pushed on selection");
      return true;
    }
    if(what.equals("Stop")) {
      System.out.println("Stop pushed on selection");
      return true;
    }
    return false;
  }

  //}
}

//}

//{ class ProcessViewerMenuBar

class ProcessViewerMenuBar extends MenuBar
{
  private static final int MAX_TOOLS = 32;

  private Menu tideMenu;
  private Menu toolMenu;
  private ToolMenuItem tools[];
  private int nrTools = 0;

  //{ public ProcessViewerMenuBar()

  /**
    * Construct a new ProcessViewerMenuBar object.
    */

  public ProcessViewerMenuBar()
  {
    tools = new ToolMenuItem[MAX_TOOLS];
    tideMenu = new Menu("Tide");
    tideMenu.add("Quit");
    toolMenu = new Menu("Tools");
    add(tideMenu);
    add(toolMenu);
  }

  //}
  //{ public void addTool(String name, ATermRef tool, ATermRef event, int flags)

  /**
    * Add a new tool. Keep the list of tools sorted!
    * @arg flags These flags indicate what arguments are needed on
    *            activation, i.e. ProcessViewer.TOOL | ProcessViewer.PROCESSES
    */

  public void addTool(String name, ATermRef tool, ATermRef event, int flags)
  {
    int i;

    if(nrTools >= MAX_TOOLS)
      throw new IllegalArgumentException("too many tools");
    for(i=0; i<nrTools && name.compareTo(tools[i].getLabel()) == -1; i++)
      ;
    for(int j=nrTools; j>i; j--) {
      tools[j] = tools[j-1];
      toolMenu.remove(tools[j]);
    }
    tools[i] = new ToolMenuItem(name, tool, event, flags);
    nrTools++;
    for(; i<nrTools; i++)
      toolMenu.add(tools[i]);

    System.out.println("current list of tools:");
    for(i=0; i<nrTools; i++)
      System.out.println(tools[i].getLabel());
  }

  //}
}

//}
//{ class ToolMenuItem

class ToolMenuItem extends MenuItem
{
  private ATermRef tool;
  private ATermRef event;
  private int flags;

  ToolMenuItem(String name, ATermRef tool, ATermRef event, int flags)
  {
    super(name);
    this.tool = tool;
    this.event = event;
    this.flags = flags;
  }

  public ATermRef getTool() { return tool; }
  public ATermRef getEvent() { return event; }
  public int getFlags() { return flags; }
}

//}

