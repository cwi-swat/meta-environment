
package toolbus.tide;
import toolbus.util.*;
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
  static final public int ANON_DAPID = MAX_ADAPTERS-1;
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
  private Label msg;

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
  Hashtable aliasTable = new Hashtable();
  DapPicture anon_dap;
  static int anon_pid = 0;

  //}
  //{ Some term patterns

  ATermPattern patternShutdown;
  ATermPattern patternToolCmdProcess;
  ATermPattern patternToolCmdAdapter;
  ATermPattern patternToolCmdNone;

  //}

  //{ public ProcessViewer()

  /**
   * Construct a new ProcessViewer object.
   */

  public ProcessViewer(Tool tool)
  {
    super("Process Viewer");
    this.tool = tool;

    //{ Initialize term patterns 

    try {
      patternShutdown = new ATermPattern("snd-event(tide-shutdown)");
      patternToolCmdNone = 
	new ATermPattern("snd-event(tool-cmd(<term>,<str>,[]))");
      patternToolCmdProcess = 
	new ATermPattern("snd-event(tool-cmd(<term>,<str>," +
			 "[proc(debug-adapter(<int>),<int>)]))");
      patternToolCmdAdapter =
	new ATermPattern("snd-event(tool-cmd(<term>,<str>," +
			 "[debug-adapter(<int>)]))");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }

    //}

    // Change the default font
    defaultFont = new Font("Helvetica", Font.BOLD, 12);
    setFont(defaultFont);

    // Add a menu bar. This menu bar takes care
    // of the dynamic nature of the 'Tools' menu.
    menuBar = new ProcessViewerMenuBar();
    setMenuBar(menuBar);

    // Calculate the geometry of the process-viewer main window
    rows = 7;
    columns = 8;
    int width = columns*ProcessCanvas.CEL_WIDTH+180;
    int height = 4*ProcessCanvas.CEL_HEIGHT+140;

    adapterGrid = new DapPicture[columns][rows];
    processGrid = new ProcessPicture[columns][rows];

    // Instantiate anonymous debug adapter
    anon_dap = new DapPicture(ANON_DAPID, null, null);
    anon_dap.setGeometry(new Rectangle(0, 0, columns, rows));
    processes[ANON_DAPID] = new Hashtable();
    adapters[ANON_DAPID] = anon_dap;


    layout = new GridBagLayout();
    setLayout(layout);

    processPanel = new ProcessPanel();
    adapterPanel = new AdapterPanel();
    selectionPanel = new SelectionPanel();
    Scrollbar horizontal = new Scrollbar(Scrollbar.HORIZONTAL);
    Scrollbar vertical = new Scrollbar(Scrollbar.VERTICAL);
    viewingArea = new ProcessCanvas(this, horizontal, vertical);
    FancyPanel dummy = new FancyPanel();
    msg = new Label("");
    Color msgcol = new Color(220,220,220);
    msg.setBackground(msgcol);

    Panel dummy2 = new Panel();
    dummy2.setLayout(new GridLayout(3,1));
    dummy2.add(horizontal);
    dummy2.add(msg);

    add(processPanel);
    add(adapterPanel);
    add(selectionPanel);
    add(viewingArea);
    add(dummy);
    add(dummy2);
    add(vertical);
    
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
    c.gridheight = GridBagConstraints.REMAINDER;
    layout.setConstraints(dummy, c);

    c.gridx = 1;
    c.gridy = 4;
    c.gridheight = 1;
    c.gridwidth = GridBagConstraints.REMAINDER;
    layout.setConstraints(dummy2, c);

    c.gridx = 2;
    c.gridy = 0;
    c.gridheight = GridBagConstraints.RELATIVE;
    c.gridwidth = 1;
    layout.setConstraints(vertical, c);

    c = new GridBagConstraints();
    c.fill = GridBagConstraints.BOTH;
    c.gridheight = GridBagConstraints.RELATIVE;
    c.gridwidth = GridBagConstraints.RELATIVE;
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

    dap.setGeometry(geom);
    for(int i=geom.x; i<geom.x+geom.width; i++)
      for(int j=geom.y; j<geom.y+geom.height; j++)
	adapterGrid[i][j] = dap;

    adapters[dapid] = dap;
    processes[dapid] = new Hashtable();
    viewingArea.paintDap(geom.x, geom.y);
    viewingArea.repaint();
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

    ProcessPicture process = new ProcessPicture(dapid, pid, name, dap);
    dap.addProcess(process);
    Rectangle r = dap.getGeometry();
    boolean found = false;

    int j = 1;
    // The top line is reserved for anonymous processes
    if(dapid == ANON_DAPID)
      j = 0;

    for(; j<r.height && !found; j++) {
      for(int i=0; i<r.width && !found; i++) {
	if(processGrid[r.x+i][r.y+j] == null && 
	   (adapterGrid[r.x+i][r.y+j] == dap || 
	    (dapid == ANON_DAPID && adapterGrid[r.x+i][r.y+j] == null))) {
	  // Found a free grid point
	  processGrid[r.x+i][r.y+j] = process;
	  process.move(r.x+i, r.y+j);
	  viewingArea.repaint();
	  processes[dapid].put(new Integer(pid), process);
	  found = true;
	}
      }
    }
    if(!found)
      throw new IllegalArgumentException("dap " + dapid + " ran out of space!");
  }

  //}
  //{ public void addProcess(ATermRef alias)

  /**
   * Add a process which is only known by one of its aliases.
   */

  public void addProcess(ATermRef alias)
  {
    if(getProcess(alias) == null) {
      int pid = anon_pid++;

      ATermRef name = ((ATermApplRef)alias).getArgs().getNext().getFirst();

      addProcess(ANON_DAPID, pid, name.toString());
      addAlias(ANON_DAPID, pid, alias);
    }
  }

  //}
  //{ public void addToolCmd(String name, ATermRef tool, String item, arg)

  /**
    * Add a tool. Just add an item to the Tool menu.
    */
  
  public void addToolCmd(String name, ATermRef tool, String item, String argtp)
  {
    menuBar.addToolItem(name, new ToolMenuItem(item, tool, argtp));
  }

  //}
  //{ public void addAlias(int dapid, int pid, ATermRef alias)

  /**
    * Add a new alias to a process.
    */

  public void addAlias(int dapid, int pid, ATermRef alias)
  {
    System.out.println("add alias " + alias + " to pid " + pid);
    ProcessPicture proc;
    proc = getProcess(alias);
    if(proc != null && proc.getDap() == ANON_DAPID && 
       (proc.getPid() != pid || proc.getDap() != dapid)) {
      // This process was anonymous, and is now replaced by
      // a respectable (debugged) process.
      processDestroyed(proc.getDap(), proc.getPid());
    }

    proc = getProcess(dapid, pid);
    proc.addAlias(alias);
    aliasTable.put(alias, proc);
  }

  //}
  //{ public void send(int dapid, int pid, ATermRef dest, ATermRef msg)

  /**
    * Visualize the sending of a message from one process to another.
    */

  public void send(int dapid, int pid, ATermRef dest, ATermRef msg)
  {
    ProcessPicture from = getProcess(dapid, pid);
    ProcessPicture to = getProcess(dest);
    if(from != null && to != null) {
      MsgPicture message = new MsgPicture(from, to, msg);
      from.setSending(message);
      viewingArea.repaint();
      if(from == currentProcess || to == currentProcess)
	updateMsgInfo();
    }
  }

  //}
  //{ public void receive(int dapid, int pid, ATermRef source, ATermRef msg)

  /**
    * Visualize the receiving of a message by a process.
    */

  public void receive(int dapid, int pid, ATermRef source, ATermRef msg)
  {
    ProcessPicture from = getProcess(source);
    ProcessPicture to = getProcess(dapid, pid);

    if(from != null && to != null) {
      MsgPicture message = new MsgPicture(from, to, msg);
      to.setReceiving(message);
      viewingArea.repaint();
      if(from == currentProcess || to == currentProcess)
	updateMsgInfo();
    }
  }

  //}

  //{ public void removeAdapter(int dapid)

  /**
    * Remove all traces of a debug adapter.
    */

  public void removeAdapter(int dapid)
  {
    DapPicture dap = adapters[dapid];
    Rectangle rect = dap.getGeometry();
    for(int i=rect.x; i<rect.x+rect.width; i++) {
      for(int j=rect.y; j<rect.y+rect.height; j++) {
	if(currentProcess == processGrid[i][j])
	  currentProcess = null;
	processGrid[i][j] = null;
	adapterGrid[i][j] = null;
      }
    }
    adapters[dapid] = null;
    if(currentAdapter == dap)
      currentAdapter = null;
    updateInfo();
    viewingArea.repaint();
  }

  //}
  //{ public void processDestroyed(int dapid, int pid)

  /**
    * A process was destroyed. Clean up all traces of it.
    */

  public void processDestroyed(int dapid, int pid)
  {
    System.out.println("process " + pid + " destroyed in dap " + dapid);
    ProcessPicture proc = getProcess(dapid, pid);
    processGrid[proc.getColumn()][proc.getRow()] = null;
    processes[dapid].remove(new Integer(pid));
    Enumeration aliases = proc.getAliases();
    while(aliases.hasMoreElements())
      aliasTable.remove(aliases.nextElement());
    viewingArea.repaint();
  }

  //}
  //{ public Rectangle searchGroupSpace(int w, int h)

  public Rectangle searchGroupSpace(int w, int h)
  {
    for(int j=(w>1 ? 1 : 0); j<rows-h+1; j++) {
      for(int i=0; i<columns-w+1; i++) {
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
    * Update the information windows and the menu items.
    */

  public void updateInfo()
  {
    // Update the process panel
    processPanel.update(currentProcess);

    int procs = 0;
    int running = 0;

    //{ Update current adapter statistics. 

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

    //}
    //{ Update selected process statistics

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

    //}
    updateMsgInfo();
    menuBar.updateStatus(currentProcess != null, 
			 currentAdapter != null, procs != 0);
  }

  //}
  //{ public void updateMsgInfo()

  /**
   * Update the information about messages.
   */
  public void updateMsgInfo()
  {
    // display message info
    String msg = null;
    if(currentProcess != null) {
      MsgPicture m = currentProcess.getSending();
      if(m != null)
	msg = m.getMsg().toString();
      else {
	m = currentProcess.getReceiving();
	if(m != null)
	  msg = m.getMsg().toString();
      }
    }
    setMsg(null);
  }

  //}
  //{ public void setMsg(String msg)

  /**
   * Display a message at the bottom of the screen.
   */

  public void setMsg(String message)
  {
    msg.setText(message == null ? "" : message);
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
  //{ public DapPicture getAdapter(int dapid)

  /**
    * Retrieve a specific debugging adapter.
    */

  public DapPicture getAdapter(int dapid)
  {
    return adapters[dapid];
  }

  //}
  //{ public ProcessPicture getProcess(int dapid, int pid)

  /**
    * Retrieve a specific process.
    */

  public ProcessPicture getProcess(int dapid, int pid)
  {
    return (ProcessPicture)processes[dapid].get(new Integer(pid));
  }

  //}
  //{ public ProcessPicture getProcess(ATermRef alias)

  /**
    * Retrieve a process id given one of its aliases.
    */

  public ProcessPicture getProcess(ATermRef alias)
  {
    return (ProcessPicture)aliasTable.get(alias);
  }

  //}
  //{ public void execStateChanged(int dapid, int pid, int es)

  /**
    * Change the execution state of a process.
    */

  public void execStateChanged(int dapid, int pid, int es)
  {
    ProcessPicture proc = (ProcessPicture)processes[dapid].get(new Integer(pid));
    proc.setExecState(es);
    updateInfo();
    viewingArea.paintProcess(proc.getColumn(), proc.getRow());
    viewingArea.repaint();
  }

  //}

  //{ public boolean action(Event evt, Object what)

  /**
    * React on events like the pressing of a button, or the
    * selection of a menu item.
    */

  public boolean action(Event evt, Object what)
  {
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
      try {
	ToolMenuItem item = (ToolMenuItem)evt.target;
	if(item.getArgType().equals("process") && currentProcess != null) {
	  // generate process event
	  ProcessPicture p = currentProcess;
	  tool.send(patternToolCmdProcess.make(item.getTool(), item.getName(),
		 new Integer(adapterGrid[p.getColumn()][p.getRow()].getId()), 
					       new Integer(p.getPid())));
	} else if(item.getArgType().equals("adapter") && currentAdapter != null){
	  // generate adapter event
	} else if(item.getArgType().equals("processes")) {
	  // generate selected processes event
	} else if(item.getArgType().equals("none")) {
	  // generate event
	  tool.send(patternToolCmdNone.make(item.getTool(), item.getName()));
	} else if(item.getArgType().equals("adapter-processes") &&
		  currentAdapter != null) {
	  // generate current adapter & selected processes event.
	}
      } catch (ToolException e) {
	System.err.println("cannot send to ToolBus, giving up!");
	System.exit(1);
      }
      return true;
    }
    return false;
  }

  //}
  //{ public boolean handleEvent(Event evt)

  /**
    * Catch scrollbar events.
    */

  public boolean handleEvent(Event evt)
  {
    if(evt.target instanceof Scrollbar) {
      viewingArea.scrollbarChanged();
      return true;
    }
    return super.handleEvent(evt);
  }

  //}
  //{ public void layout()

  public void layout()
  {
    super.layout();
    viewingArea.layout();
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
  private static final int NORTH = 0;
  private static final int SOUTH = 1;
  private static final int EAST = 0;
  private static final int WEST = 1;

  // Some colors
  public static Color backgroundColor = Color.white; // new Color(200,200,255);
  public static Color foregroundColor = Color.lightGray;
  public static Color adapterColor = Color.lightGray;
  public static Color runningProcessColor = new Color(50,230,50);
  public static Color stoppedProcessColor = new Color(40,180,40);
  public static Color anonProcessColor = new Color(30, 130, 30);;
  public static Color outlineColor = Color.black;
  public static Color currentOutlineColor = Color.red;
  public static Color selectedProcessColor = Color.gray;
  public static Color textColor = Color.black;

  private ProcessViewer viewer;
  private Scrollbar horizontal;
  private Scrollbar vertical;
  private ProcessPicture[][] processGrid;
  private DapPicture[][] adapterGrid;
  private Image backgroundImage;
  private Graphics background;
  private int orgX = 0;
  private int orgY = 0;

  //{ public ProcessCanvas(ProcessViewer viewer, Scrollbar hor, Scrollbar vert)

  /**
   * Create a ProcessCanvas object.
   */

  public ProcessCanvas(ProcessViewer viewer, Scrollbar hor, Scrollbar vert)
  {
    this.viewer = viewer;
    this.vertical = vert;
    this.horizontal = hor;

    // Change the default font
    setFont(new Font("Helvetica", Font.BOLD, 10));

    setBackground(backgroundColor);
    setForeground(foregroundColor);

    vertical.setLineIncrement(1);
    vertical.setPageIncrement(2);
    horizontal.setLineIncrement(1);
    horizontal.setPageIncrement(2);
  }

  //}
  //{ public void layout()

  /**
    * The size of the canvas changes, update the scrollbar values.
    */

  public void layout()
  {
    super.layout();
    int cellw = size().width/CEL_WIDTH;
    int cellh = size().height/CEL_HEIGHT;
    int rows = viewer.getRows();
    int cols = viewer.getColumns();

    vertical.setValues(vertical.getValue(), cellh, 0, rows-cellh);
    horizontal.setValues(horizontal.getValue(), cellw, 0, cols-cellw);

    // We dont want to see the area outside the grid.
    orgX = -Math.max(0, Math.min(cols-cellw, horizontal.getValue()));
    orgY = -Math.max(0, Math.min(rows-cellh, vertical.getValue()));
  }

  //}
  //{ public void update(Graphics g)

  /**
    * Paint this canvas (use double buffering)
    */

  public void update(Graphics g)
  {
    paint(g);
  }

  //}
  //{ public void paint(Graphics g)

  /**
    * Copy the background image to the canvas.
    */

  public void paint(Graphics g)
  {

    int w, h;

    w = CEL_XOFF+CEL_WIDTH*viewer.getColumns();
    h = CEL_YOFF+CEL_HEIGHT*viewer.getRows();

    if(backgroundImage == null || backgroundImage.getWidth(null) != w || 
       backgroundImage.getHeight(null) != h) {
      backgroundImage = createImage(w+CEL_WIDTH, h+CEL_HEIGHT);
      background = backgroundImage.getGraphics();
    }
    paintAll();
    paintMessages();
    g.drawImage(backgroundImage, orgX*CEL_WIDTH, orgY*CEL_HEIGHT, null);

    /*    w = size().width-1;
    h = size().height-1;
    int x=0;
    int y=0;
    g.setColor(Color.gray);
    for(int i=0; i<2; i++) {
      g.draw3DRect(x++, y++, w, h, false);
      w -= 2;
      h -= 2;
    }
    */
  }

  //}
  //{ public void paintAll()

  /**
   * Paint all processes, adapters, and messages in a ProcessCanvas.
   */

  public void paintAll()
  {
    int x, y, w, h;

    // First, we draw the borders
    x=0;
    y=0;
    w = size().width-1;
    h = size().height-1;

    background.setColor(getBackground());
    background.fillRect(0, 0, size().width, size().height);

    // Now draw the processes and the adapters
    for(int i=0; i<viewer.getColumns(); i++) {
      for(int j=0; j<viewer.getRows(); j++) {
	if(viewer.adapterAt(i,j) != null) {
	  DapPicture dap = viewer.adapterAt(i,j);
	  Rectangle geom = dap.getGeometry();
	  if(geom.x == i && geom.y == j)
	    paintDap(i, j);
	}
	if(viewer.processAt(i,j) != null)
	  paintProcess(i,j);
      }
    }
  }

  //}
  //{ public void paintMessages()

  /**
    * Only paint the messages.
    */

  public void paintMessages()
  {
    paintMessages(background);
  }

  //}
  //{ public void paintMessages(Graphics g)

  /**
    * Only paint the messages.
    */

  public void paintMessages(Graphics g)
  {
    for(int i=0; i<viewer.getColumns(); i++) {
      for(int j=0; j<viewer.getRows(); j++) {
	if(viewer.processAt(i,j) != null) {
	  MsgPicture msg = viewer.processAt(i,j).getSending();
	  if(msg != null)
	    paintMsg(g, msg);
	  msg = viewer.processAt(i,j).getReceiving();
	  if(msg != null)
	    paintMsg(g, msg);
	}
      }
    }
  }

  //}
  //{ public void scrollbarChanged()

  /**
    * Handle scrollbar changes.
    */

  public void scrollbarChanged()
  {
    orgX = -horizontal.getValue();
    orgY = -vertical.getValue();
    repaint();
  }

  //}
  //{ public boolean mouseDown(Event evt, int x, int y)

  /**
    * The user pushed a mouse button.
    */

  public boolean mouseDown(Event evt, int x, int y)
  {
    boolean selected;

    // First we calculate in which cell the user pressed the mouse button
    int cellx = (x-CEL_XOFF)/CEL_WIDTH;
    int celly = (y-CEL_YOFF)/CEL_HEIGHT;
    int xoff = (x - CEL_XOFF) - (cellx * CEL_WIDTH);
    int yoff = (y - CEL_YOFF) - (celly * CEL_HEIGHT);

    if(cellx >= 0 && cellx < viewer.getColumns() &&
       celly >= 0 && celly < viewer.getRows()) {
      // Now check if the cel is occupied.
      if(viewer.processAt(cellx,celly) != null && 
	 viewer.processAt(cellx,celly).hit(x, y)) {
	if(evt.shiftDown()) {
	  // Manipulate the selection
	  selected = viewer.processAt(cellx, celly).isSelected();
	  viewer.selectProcess(cellx, celly, !selected);
	} else if(!evt.controlDown()) {
	  ProcessPicture old = viewer.getCurrentProcess();
	  if(old != null && old == viewer.processAt(cellx, celly))
	    viewer.clearCurrentProcess();
	  else
	    viewer.setCurrentProcess(cellx, celly);
	  //if(old != null)
	  //paintProcess(old);
	}
	// paintProcess(cellx, celly);
	repaint();
      } else {
	if(viewer.adapterAt(cellx,celly) != null) {
	  if(viewer.adapterAt(cellx,celly) == viewer.getCurrentAdapter())
	    viewer.clearCurrentAdapter();
	  else
	    viewer.setCurrentAdapter(cellx, celly);
	  //Rectangle rect = viewer.adapterAt(cellx, celly).getGeometry();
	  //paintDap(rect.x, rect.y);
	  repaint();
	}
      }
    }
    return true;
  }

  //}
  //{ public void paintProcess(ProcessPicture process)

  /**
    * (re-)paint a process.
    */

  public void paintProcess(ProcessPicture process)
  {
    paintProcess(process.getColumn(), process.getRow());
  }

  //}
  //{ public void paintProcess(int celx, int cely)

  /**
    * (re-)Paint a single process.
    */

  public void paintProcess(int celx, int cely)
  {
    int x = CEL_XOFF+celx*CEL_WIDTH+4;
    int y = CEL_YOFF+cely*CEL_HEIGHT+(CEL_HEIGHT-CEL_WIDTH)/2 + 8;
    int w = CEL_WIDTH - 8;
    int h = w;
    if(viewer.processAt(celx,cely) != null) {
      viewer.processAt(celx,cely).paint(background, x, y, h, w);
    } else {
      // Cleanup?
    }
  }

  //}
  //{ public void paintDap(int celx, int cely)

  /**
    * (re-)Paint a single adapter, and all the processes withing.
    */
  
  public void paintDap(int celx, int cely)
  {
    DapPicture dap = viewer.adapterAt(celx, cely);
    int x = CEL_XOFF+celx*CEL_WIDTH;
    int y = CEL_YOFF+cely*CEL_HEIGHT;
    if(dap != null) {
      Rectangle geom = dap.getGeometry();
      celx = geom.x;
      cely = geom.y;
      dap.paint(background,x,y,geom.width*CEL_WIDTH,geom.height*CEL_HEIGHT);
      for(int i=celx; i<celx+geom.width; i++)
	for(int j=cely; j<cely+geom.height; j++)
	  paintProcess(i, j);
    }
  }

  //}
  //{ private void paintMsg(MsgPicture msg)

  /**
    * Paint a message on the canvas.
    */

  private void paintMsg(Graphics g, MsgPicture msg)
  {
    ProcessPicture from = msg.getSender();
    ProcessPicture to = msg.getReceiver();

    int gx1 = to.getColumn();
    int gy1 = to.getRow();
    int gx2 = from.getColumn();
    int gy2 = from.getRow();

    int x, y, x1, y1, x2, y2;

    int src_anchor = NORTH;
    int dest_anchor = EAST;

    // Calculate the starting and ending x coordinates
    if(gx2 > gx1) {
      x1 = (gx1+1)*CEL_WIDTH + CEL_XOFF;
      x2 = gx2*CEL_WIDTH + CEL_XOFF;
    } else if(gx1 > gx2) {
      x1 = gx1*CEL_WIDTH + CEL_XOFF;
      x2 = (gx2+1)*CEL_WIDTH + CEL_XOFF;
      dest_anchor = WEST;
    } else {
      x1 = (gx1+1)*CEL_WIDTH + CEL_XOFF;
      x2 = (gx2+1)*CEL_WIDTH + CEL_XOFF;
    }

    // Calculate the starting and ending y coordinates
    if(gy2 > gy1) {
      y1 = (gy1+1)*CEL_HEIGHT + CEL_YOFF;
      y2 = gy2*CEL_HEIGHT + CEL_YOFF;
    } else if(gy1 > gy2) {
      y1 = gy1*CEL_HEIGHT + CEL_YOFF;
      y2 = (gy2+1)*CEL_HEIGHT + CEL_YOFF;
    } else {
      y1 = (gy1+1)*CEL_HEIGHT + CEL_YOFF;
      y2 = (gy2+1)*CEL_HEIGHT + CEL_YOFF;
    }

    int pw = CEL_WIDTH - 8;
    int ph = pw;

    // Source anchor
    int px = CEL_XOFF+gx1*CEL_WIDTH+4;
    int py = CEL_YOFF+gy1*CEL_HEIGHT+(CEL_HEIGHT-CEL_WIDTH)/2 + 8;
    if(gy2 >= gy1) {
      // Anchor south
      y1 -= 6;
      y2 -= 6;
      x = px+pw/2;
      y = py+ph;
      g.drawLine(x-3, y+2, x, y-1);
      g.drawLine(x-4, y+2, x-1, y-1);
      g.drawLine(x+4, y+2, x+1, y-1);
      g.drawLine(x+5, y+2, x+2, y-1);
      g.drawLine(x, y, x, y1);
      g.drawLine(x+1, y, x+1, y1);
      g.drawLine(x, y1, x1, y1);
      g.drawLine(x, y1+1, x1, y1+1);
    } else {
      // Anchor north
      y1 += 6;
      y2 -= 6;
      x = px+pw/2;
      y = py;
      g.drawLine(x-3, y-3, x, y);
      g.drawLine(x-4, y-3, x-1, y);
      g.drawLine(x+4, y-3, x+1, y);
      g.drawLine(x+5, y-3, x+2, y);
      g.drawLine(px+pw/2, py, px+pw/2, y1);
      g.drawLine(px+pw/2+1, py, px+pw/2+1, y1);
      g.drawLine(px+pw/2, y1, x1, y1);
      g.drawLine(px+pw/2, y1+1, x1, y1+1);
    }

    // Destination anchor
    px = CEL_XOFF+gx2*CEL_WIDTH+4;
    py = CEL_YOFF+gy2*CEL_HEIGHT+(CEL_HEIGHT-CEL_WIDTH)/2 + 8;
    if(gx2 > gx1) {
      // Anchor west
      g.drawLine(px, py+ph/2, x2, py+ph/2);
      g.drawLine(px, py+ph/2+1, x2, py+ph/2+1);
      g.drawLine(x2, py+ph/2, x2, y2);
      g.drawLine(x2+1, py+ph/2, x2+1, y2);
    } else {
      // Anchor east
      g.drawLine(px+pw-1, py+ph/2, x2, py+ph/2);
      g.drawLine(px+pw-1, py+ph/2+1, x2, py+ph/2+1);
      g.drawLine(x2, py+ph/2, x2, y2);
      g.drawLine(x2+1, py+ph/2, x2+1, y2);
    }

    g.drawLine(x1, y1, x2, y1);
    g.drawLine(x1, y1+1, x2, y1+1);
    g.drawLine(x2, y1, x2, y2);
    g.drawLine(x2+1, y1, x2+1, y2);
  }

  //}
  //{ public void addCommunication(ProcessPicture from, ProcessPicture to, ATermRef msg)

  /**
    * Visualize the communication between two processes.
    */

  public void addCommunication(ProcessPicture from, ProcessPicture to, ATermRef msg)
  {
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
    g.setColor(ProcessCanvas.adapterColor);

    g.fillRect(x, y, w, h);

    g.setColor(ProcessCanvas.textColor);

    //String name = getName() + " (" + getType() + ")";
    String name = getType();
    FontMetrics fm = g.getFontMetrics();
    g.drawString(name, x+2, y + 2 + fm.getAscent());

    // If this process is current, draw a circle around it
    if(isCurrent())
      g.setColor(ProcessCanvas.currentOutlineColor);
    else
      g.setColor(ProcessCanvas.outlineColor);
    g.drawRect(x, y, w-1, h-1);
    g.drawRect(x+1, y+1, w-3, h-3);
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
  private int column;        // cell column of this process
  private int row;           // cell row of this process
  private int centerX;
  private int centerY;
  private int radius;
  private boolean selected;
  private boolean current;
  private RemoteDebugAdapterInfo adapter;
  private MsgPicture sending;
  private MsgPicture receiving;

  //{ public ProcessPicture(int dapid, int pid, String name, RemoteDebugAdapterInfo dap)

  /**
   * Construct a new ProcessString.
   */

  public ProcessPicture(int dapid, int pid, String name, RemoteDebugAdapterInfo dap)
  {
    super(dapid, pid, name);
    this.adapter = dap;
  }

  //}
  //{ public void move(int col, int row)

  /**
    * Change the cell coordinates of this process.
    */

  public void move(int col, int row)
  {
    this.column = col;
    this.row = row;
  }

  //}
  //{ public int getColumn()

  /**
    * Get the cell column of this process.
    */

  public int getColumn()
  {
    return column;
  }

  //}
  //{ public int getRow()

  /**
    * Get the cell row of this process.
    */

  public int getRow()
  {
    return row;
  }

  //}
  //{ public void paint(Graphics g, int x, int y, int w, int h)

  /**
   * Paint a process, by creating a colored circle with a black name in it.
   * When a process is running, its color is a brightened.
   */

  public void paint(Graphics g, int x, int y, int w, int h)
  {
    if(isSelected())
      g.setColor(ProcessCanvas.selectedProcessColor);
    else
      if(getDap() == ProcessViewer.ANON_DAPID)
	g.setColor(ProcessCanvas.backgroundColor);
      else
	g.setColor(ProcessCanvas.adapterColor);

    g.fillRect(x, y, w, h);

    if(getPid() == ProcessViewer.ANON_DAPID)
      g.setColor(ProcessCanvas.anonProcessColor);
    else
      if(isRunning())
	g.setColor(ProcessCanvas.runningProcessColor);
      else
	g.setColor(ProcessCanvas.stoppedProcessColor);

    // First, fill the circle
    g.fillOval(x+1, y+1, w-3, h-3);

    // Draw an outline circle around the process
    if(isCurrent())
      g.setColor(ProcessCanvas.currentOutlineColor);
    else
      g.setColor(ProcessCanvas.outlineColor);
    g.drawOval(x+1, y+1, w-3, w-3);
    g.drawOval(x+2, y+2, w-5, w-5);

    // needed for 'hit' checking later on:
    radius = w/2;
    centerX = x + radius;
    centerY = y + radius;

    g.setColor(ProcessCanvas.textColor);
    FontMetrics fm = g.getFontMetrics();
    int width = fm.stringWidth(getName());
    g.drawString(getName(), (x+w/2)-width/2, y+w/2);
    String pid = "" + getPid();
    width = fm.stringWidth(pid);
    g.drawString(pid, (x+w/2)-width/2, y+w/2+fm.getAscent());
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
  //{ public void setSending(MsgPicture msg)

  /**
    * This process is sending a message.
    */

  public void setSending(MsgPicture msg)
  {
    if(sending != null && sending.getReceiver() != msg.getReceiver())
      sending.getReceiver().receiving = null;
    if(receiving != null) {
      receiving.getSender().sending = null;
      receiving = null;
    }
    sending = msg;
  }

  //}
  //{ public void setReceiving(MsgPicture msg)

  /**
    * This process is receiving a message.
    */

  public void setReceiving(MsgPicture msg)
  {
    if(receiving != null && receiving.getSender() != msg.getSender())
      receiving.getSender().sending = null;
    if(sending != null) {
      sending.getReceiver().receiving = null;
      sending = null;
    }
    receiving = msg;
  }

  //}
  //{ public MsgPicture getSending()

  /**
    * Get a list of all messages this process is currently sending.
    */

  public MsgPicture getSending()
  {
    return sending;
  }

  //}
  //{ public MsgPicture getReceiving()

  /**
    * Get a list of all messages this process is currently receiving.
    */

  public MsgPicture getReceiving()
  {
    return receiving;
  }

  //}
  //{ public void clearCommunication()

  /**
    * Remove all communication information of this process.
    */

  public void clearCommunication()
  {
    if(sending != null) {
      sending.getReceiver().receiving = null;
      sending = null;
    } else if(receiving != null) {
      receiving.getSender().sending = null; 
      receiving = null;
    }
  }

  //}
}

//}
//{ class MsgPicture

class MsgPicture
{
  private ATermRef msg;
  private ProcessPicture from;
  private ProcessPicture to;

  public MsgPicture(ProcessPicture from, ProcessPicture to, ATermRef msg)
  {
    this.msg = msg;
    this.from = from;
    this.to = to;
  }

  public ProcessPicture getSender() {
    return from;
  }

  public ProcessPicture getReceiver() {
    return to;
  }

  public ATermRef getMsg() {
    return msg;
  }

  public String toString() {
    return "msg from " + from + " to " + to + " = " + msg;
  }
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
    choicePanel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 0));
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
    modePanel.setLayout(new FlowLayout(FlowLayout.LEFT, 5, 0));
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
    statePanel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 0));
    state = new Label("0 procs, 0 running");
    statePanel.add(state);
    add(statePanel);
    c.gridy = 1;
    layout.setConstraints(statePanel, c);

    Panel modePanel = new Panel();
    modePanel.setLayout(new FlowLayout(FlowLayout.CENTER, 3, 3));
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
    state.setText("" + procs + " procs, " + running + " running");
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
    if(what.equals("Start"))
      return true;

    if(what.equals("Stop"))
      return true;

    return false;
  }

  //}
}

//}

//{ class ProcessViewerMenuBar

class ProcessViewerMenuBar extends MenuBar
{
  private static final int MAX_TOOLS = 32;

  private Hashtable toolTable;
  private Menu tideMenu;
  private Menu tools[];
  private int nrTools = 0;

  //{ public ProcessViewerMenuBar()

  /**
    * Construct a new ProcessViewerMenuBar object.
    */

  public ProcessViewerMenuBar()
  {
    // Change the default font, only needed under Linux,
    // because it should be inherited from ProcessViewer.
    setFont(new Font("Helvetica", Font.BOLD, 12));

    tools = new Menu[MAX_TOOLS];
    toolTable = new Hashtable(24);
    tideMenu = new Menu("Tide");
    tideMenu.add("Quit");
    add(tideMenu);
  }

  //}
  //{ public void addToolItem(String name, ToolMenuItem item)

  /**
    * Add a new tool. Keep the list of tools sorted!
    * @arg flags These flags indicate what arguments are needed on
    *            activation, i.e. ProcessViewer.TOOL | ProcessViewer.PROCESSES
    */

  public void addToolItem(String name, ToolMenuItem item)
  {
    int i;

    Menu menu = (Menu)toolTable.get(name);

    if(menu == null) {
      if(nrTools >= MAX_TOOLS)
	throw new IllegalArgumentException("too many tools");
      for(i=0; i<nrTools && name.compareTo(tools[i].getLabel()) > 0; i++)
	;
      for(int j=nrTools; j>i; j--) {
	tools[j] = tools[j-1];
	remove(tools[j]);
      }
      menu = new Menu(name);
      tools[i] = menu;
      nrTools++;
      for(; i<nrTools; i++)
	add(tools[i]);
      toolTable.put(name, menu);
    }
    menu.add(item);
  }

  //}
  //{ public void updateStatus(boolean process, boolean adapter, boolean selection)

  /**
   * Update the status of the tool menu items depending
   * on whether a current process, adapter, and/or process selection exists.
   */

  public void updateStatus(boolean process, boolean adapter, boolean selection)
  {
    for(int i=0; i<nrTools; i++) {
      Menu menu = tools[i];
      for(int j=0; j<menu.countItems(); j++) {
	((ToolMenuItem)menu.getItem(j)).updateStatus(process, adapter, selection);
      }
    }
  }

  //}
}

//}
//{ class ToolMenuItem

class ToolMenuItem extends MenuItem
{
  private ATermRef tool;
  private String name;
  private String argtype;

  public ToolMenuItem(String name, ATermRef tool, String argtype)
  {
    super(name);
    this.name = name;
    this.tool = tool;
    this.argtype = argtype;
    Vector argtypes;
  }

  public ATermRef getTool() { return tool; }
  public String getName() { return name; }
  public String getArgType() { return argtype; }

  public void updateStatus(boolean process, boolean adapter, boolean selection)
  {
    if(argtype.equals("process"))
      enable(process);
    else if(argtype.equals("adapter"))
      enable(adapter);
    else if(argtype.equals("processes"))
      enable(selection);
    else if(argtype.equals("adapter-processes"))
      enable(adapter && selection);
    else if(argtype.equals("none"))
      ;
  }
}

//}


