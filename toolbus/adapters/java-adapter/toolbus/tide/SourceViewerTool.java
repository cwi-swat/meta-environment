
package toolbus.tide;
import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import toolbus.util.*;
import toolbus.aterm.*;
import toolbus.tool.*;

//{ class SourceViewerTool

class SourceViewerTool extends SourceViewerTif
{
  /**
   * Holds one vector of SourceViewer objects for every debug-adapter.
   */
  private Hashtable viewerTable;
  private Hashtable adapterTable;

  private World world;
  private ATermPattern patternSingleProcess;
  private ATerm termCpePort;
  private ATerm termTrue;
  private ATerm termWatchCpe;

  //{ static public void main(String[] args)

  /*
   * The 'main' method creates a source-viewer tool, connects
   * it to the ToolBus, and runs it.
   */

  static public void main(String[] args)
       throws java.io.IOException, java.net.UnknownHostException, ToolException
  {
    // Normal tool
    SourceViewerTool tool = new SourceViewerTool(args);
    if(args[0].equals("test0")) {
      tool.test0();
    } else {
      tool.connect();
      tool.run();
    }
  }

  //}
  //{ public SourceViewerTool(String[] args)

  /**
   * Construct a new SourceViewerTool.
   */

  public SourceViewerTool(String[] args)
       throws java.net.UnknownHostException
  {
    super(args);
    world = ATerm.the_world;
    viewerTable = new Hashtable();
    adapterTable = new Hashtable();
    // Miscellaneous patterns and terms
    try {
      patternSingleProcess = world.makePattern("[<int>]");
      termCpePort          = world.makeSimple("[exec-state,at,stop]");
      termTrue             = world.makeSimple("always");
      termWatchCpe         = world.makeSimple("[watch(cpe)]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
  }

  //}
  //{ public void test0()

  public void test0()
  {
    try {
      ATermAppl dap = (ATermAppl)world.makeSimple("debug-adapter(1)");
      ATermList info = (ATermList)world.makeSimple(
         "[[name,\"test.tcl-0\"],[type,\"Tcl\"]," +
	 "[search-paths,[[config,[\".\"]],[source,[\".\"]]]]," +
	 "[ports,[[exec-state,at],[always,before],[always,after]," +
	 "[location,before],[location,after],[exception,at]]]," +
	 "[exec-control,[single-step,step-over,run,stop]]]");
      ATerm procs = world.makeSimple("[[0,\"TEST\"," +
                        "[alias(toolbus(8999),TEST(0))]]]");
      dapConnected(dap, info, procs);
      ATerm proc = world.makeSimple("0");
      viewProcess(dap, proc);
      Vector viewers = (Vector)viewerTable.get(new Integer(1));
      SourceViewer viewer = (SourceViewer)viewers.elementAt(0);
      //viewer.loadFile("test.txt");
      viewer.cpe(0, new SourceArea("test.txt", 2, 4, 4, -1));
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error:" + e.toString());
    }
  }

  //}

  //{ void viewSource(ATermAppl dap)

  /**
   * Watch the source off all processes in an adapter.
   * @deprecated Use the viewProcess method instead.
   */

  void viewSource(ATermAppl dap)
  {
    System.out.println("viewSource : " + dap);
  }

  //}
  //{ void viewProcess(ATermAppl dap, ATerm procs)

  /**
   * Watch the source of a process or process-group.
   */

  void viewProcess(ATermAppl dap, ATerm procs)
  {
    //System.out.println("viewProcess: " + dap + ", procs=" + procs);
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    Vector viewers = (Vector)viewerTable.get(new Integer(dapid));
    RemoteDebugAdapterInfo dapInfo = 
      (RemoteDebugAdapterInfo)adapterTable.get(new Integer(dapid));

    DebugProcess[] processes;

    if(procs.getType() == ATerm.INT) {
      int pid = ((ATermInt)procs).getInt();
      DebugProcess process = dapInfo.getProcess(pid);
      SourceViewer viewer = new SourceViewer(dapInfo, process);
      viewers.addElement(viewer);
      dapInfo.sendCreateRule("cpe", patternSingleProcess.make(new Integer(pid)),
			     new ExecStatePort(DebugProcess.ES_STOP, DebugPort.WHEN_AT), 
			     termTrue, termWatchCpe, DebugRule.PERSISTENT);
    }
  }

  //}

  //{ void dapDisconnected(ATermAppl dap)

  /**
   * A debug adapter has disconnected. If we have viewers connected to
   * it, we need to destroy them.
   */

  void dapDisconnected(ATermAppl dap)
  {
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    adapterTable.remove(new Integer(dapid));
    Enumeration viewers = ((Vector)viewerTable.get(new Integer(dapid))).elements();
    while(viewers.hasMoreElements()) {
      SourceViewer viewer = (SourceViewer)viewers.nextElement();
      viewer.dispose();
    }
  }

  //}
  //{ void dapConnected(ATermAppl dap, ATermList info, ATerm procs)

  /**
   * A debug-adapter has connected to the system. We need to
   * maintain information about it (and its processes), so
   * the user can open viewers on it.
   */

  void dapConnected(ATermAppl dap, ATermList info, ATerm procs)
  {
    // No viewers yet for this adapter, so add an empty vector in the viewerTable
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    viewerTable.put(new Integer(dapid), new Vector());

    // Create a new RemoteDebugAdapterInfo object, and store it in the adapterTable
    RemoteDebugAdapterInfo dapInfo = 
      new RemoteDebugAdapterInfo(dapid, info.getATerms(), this);
    adapterTable.put(new Integer(dapid), dapInfo);

    // The processes are stored in the RemoteDebugAdapterInfo object.
    ATerms proclist = ((ATermList)procs).getATerms();
    ATermPattern patTriple = null;
    try {
      patTriple = world.makePattern("[<int>,<str>,<list>]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
    while(!proclist.isEmpty()) {
      ATermList triple = (ATermList)proclist.getFirst();
      proclist = proclist.getNext();
      if(!patTriple.match(triple))
	throw new IllegalArgumentException("malformed process def: " + triple);
      int pid = ((Integer)patTriple.elementAt(0)).intValue();
      String name = (String)patTriple.elementAt(1);
      DebugProcess process = new DebugProcess(dapid, pid, name);
      dapInfo.addProcess(process);
    }
  }

  //}
  //{ void processCreation(dap, proc, name, aliases)

  /**
   * A new process was created.
   */

  void processCreation(ATermAppl dap, ATerm proc, String name, 
		       ATermList aliases)
  {
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    if(!patternSingleProcess.match(proc))
      throw new IllegalArgumentException("illegal process spec: " + proc.toString());
    int pid = ((Integer)patternSingleProcess.elementAt(0)).intValue();
    DebugProcess process = new DebugProcess(dapid, pid, name);
    RemoteDebugAdapterInfo dapInfo = 
      (RemoteDebugAdapterInfo)adapterTable.get(new Integer(dapid));
    dapInfo.addProcess(process);
  }

  //}
  //{ void processDestruction(ATermAppl dap, ATerm proc)

  /**
   * A process was destroyed.
   */

  void processDestruction(ATermAppl dap, ATerm proc)
  {
    int dapid = DebugAdapterInfo.debugAdapterId(dap);
    if(!patternSingleProcess.match(proc))
      throw new IllegalArgumentException("illegal process spec: " + proc.toString());
    int pid = ((Integer)patternSingleProcess.elementAt(0)).intValue();
    RemoteDebugAdapterInfo dapInfo = 
      (RemoteDebugAdapterInfo)adapterTable.get(new Integer(dapid));
    dapInfo.removeProcess(pid);
  }

  //}

  //{ void currentPort(ATermAppl dap, ATerm procs, ATerm port)

  /**
   * The current port has changed. It might be a location port,
   * in which case, we have to update the selected line.
   */

  void currentPort(ATermAppl dap, ATerm procs, ATerm port)
  {
  }

  //}
  //{ void ruleCreated(dap, proc, rid, port, cond, acts, life)

  /**
   * A new rule was created. Add it to the right debug adapter and ighlight it.
   */

  void ruleCreated(ATermAppl dap, ATerm proc, int rid, ATerm port, 
		   ATerm cond, ATerm acts, ATerm life)
  {
    Integer dapid = new Integer(DebugAdapterInfo.debugAdapterId(dap));
    RemoteDebugAdapterInfo dapInfo = 
      (RemoteDebugAdapterInfo)adapterTable.get(dapid);
    DebugProcess[] procs = dapInfo.getProcessArray(proc);
    DebugPort dbgport = DebugPort.newPort(port);
    int lifetime = DebugRule.lifeTerm2Int(life);
    DebugRule rule = new DebugRule(rid, procs, dbgport, cond,
				   ((ATermList)acts).getATerms(), lifetime);
    dapInfo.addRule(rule);
    if(dbgport instanceof LocationPort) {
      boolean iswatch = rule.isWatchpoint();
      boolean isbreak = rule.isBreakpoint();
      if(iswatch || isbreak) {
	LocationPort loc = (LocationPort)dbgport;
	Enumeration viewers = ((Vector)viewerTable.get(dapid)).elements();
	while(viewers.hasMoreElements()) {
	  SourceViewer viewer = (SourceViewer)viewers.nextElement();
	  if(isbreak)
	    viewer.addBreakpoint(loc.getLocation(), rid);
	  if(iswatch)
	    viewer.addWatchpoint(loc.getLocation(), rid);
	}
      }
    }
  }

  //}
  //{ void ruleModified(dap, proc, rid, port, cond, acts, life)

  /**
   * A new rule was modified.
   */

  void ruleModified(ATermAppl dap, ATerm proc, int rid, ATerm port, 
		   ATerm cond, ATerm acts, ATerm life)
  {
    Integer dapid = new Integer(DebugAdapterInfo.debugAdapterId(dap));
    RemoteDebugAdapterInfo dapInfo = 
      (RemoteDebugAdapterInfo)adapterTable.get(dapid);
    DebugProcess[] procs = dapInfo.getProcessArray(proc);
    DebugPort dbgport = DebugPort.newPort(port);
    int lifetime = DebugRule.lifeTerm2Int(life);
    DebugRule rule = new DebugRule(rid, procs, dbgport, cond,
				   ((ATermList)acts).getATerms(), lifetime);

    // Remove the old break/watchpoint
    DebugRule oldrule = dapInfo.getRule(rid);
    boolean oldwatch = oldrule.isWatchpoint();
    boolean oldbreak = oldrule.isBreakpoint();
    Enumeration viewers = ((Vector)viewerTable.get(dapid)).elements();
    while(viewers.hasMoreElements()) {
      SourceViewer viewer = (SourceViewer)viewers.nextElement();
      if(oldbreak)
	viewer.removeBreakpoint(rid);
      if(oldwatch)
	viewer.removeWatchpoint(rid);
    }
    dapInfo.removeRule(rid);

    // Add the new break/watchpoint
    dapInfo.addRule(rule);
    if(dbgport instanceof LocationPort) {
      boolean iswatch = rule.isWatchpoint();
      boolean isbreak = rule.isBreakpoint();
      if(iswatch || isbreak) {
	LocationPort loc = (LocationPort)dbgport;
	viewers = ((Vector)viewerTable.get(dapid)).elements();
	while(viewers.hasMoreElements()) {
	  SourceViewer viewer = (SourceViewer)viewers.nextElement();
	  if(isbreak)
	    viewer.addBreakpoint(loc.getLocation(), rid);
	  if(iswatch)
	    viewer.addWatchpoint(loc.getLocation(), rid);
	}
      }
    }
  }

  //}
  //{ void ruleDestroyed(ATermAppl dap, ATerm pid, int rid)

  /**
   * A rule was destroyed. Remove any highlights.
   */

  void ruleDestroyed(ATermAppl dap, int rid)
  {
    Integer dapid = new Integer(DebugAdapterInfo.debugAdapterId(dap));
    RemoteDebugAdapterInfo dapInfo = 
      (RemoteDebugAdapterInfo)adapterTable.get(dapid);
    DebugRule rule = dapInfo.getRule(rid);
    Enumeration viewers = ((Vector)viewerTable.get(dapid)).elements();
    while(viewers.hasMoreElements()) {
      SourceViewer viewer = (SourceViewer)viewers.nextElement();
      if(rule.isWatchpoint())
	viewer.removeWatchpoint(rid);
      if(rule.isBreakpoint())
	viewer.removeBreakpoint(rid);
    }
    dapInfo.removeRule(rid);
  }

  //}

  //{ void execState(ATermAppl dap, ATerm proc, ATerm es)

  /**
   * The current state of execution of a process has changed.
   */

  void execState(ATermAppl dap, ATerm proc, ATerm es)
  {
  }

  //}
  //{ void cpe(ATermAppl dap, ATerm proc, ATerm cpe)

  /**
   * The current point of execution of a process has changed.
   */

  void cpe(ATermAppl dap, ATerm proc, ATerm cpe)
  {
    //System.out.println("cpe of " + proc + " = " + cpe);
    LocationPort port = (LocationPort)DebugPort.newPort(cpe);
    Integer dapid = new Integer(DebugAdapterInfo.debugAdapterId(dap));
    if(!patternSingleProcess.match(proc))
      throw new IllegalArgumentException("illegal process spec: " + proc.toString());
    int pid = ((Integer)patternSingleProcess.elementAt(0)).intValue();

    // Update the cpe of the DebugProcess
    RemoteDebugAdapterInfo D = (RemoteDebugAdapterInfo)adapterTable.get(dapid);
    DebugProcess P = D.getProcess(pid);
    P.setLocation(port.getLocation());

    // Update all viewers
    Vector viewers = (Vector)viewerTable.get(dapid);
    if(!viewers.isEmpty()) {
      Enumeration viewerList = viewers.elements();
      while(viewerList.hasMoreElements())
	((SourceViewer)viewerList.nextElement()).cpe(pid, port.getLocation());
    }
  }

  //}

  //{ void recAckEvent(ATerm event)

  /**
   * The source-viewer received an event acknowledgement.
   */

  void recAckEvent(ATerm event)
  {
  }

  //}
  //{ void recTerminate(ATerm arg)

  /**
   * The source-viewer received a termination request.
   */

  void recTerminate(ATerm arg)
  {
    System.exit(0);
  }

  //}
}

//}
//{ class SourceViewer

class SourceViewer extends Frame implements TextHandler
{
  // Some constants
  private static final int WATCHVAR = 0;
  private static final int WATCHEXPR = 1;

  // The world to use to build terms
  World world;

  // The debug adapter associated with this viewer
  private RemoteDebugAdapterInfo dap;

  // One of these two is valid at any one time:
  private DebugProcess curProcess;    
  private DebugProcessGroup curGroup;

  private TextBrowser sourceBrowser;
  private boolean tracking;
  private int nrGroups;

  private Label module;
  private Label location;
  private Label selection;
  private Button breakpoint;
  private Button watchVar;
  private Button watchExpr;
  private Choice processChoice;
  private GridBagLayout processChoiceLayout;
  private Container processChoiceContainer;
  private Choice processMode;
  private Button start;
  private Button stop;
  private Font font;
  private Hashtable cpeTags;
  private Hashtable cpeAreas;
  private Hashtable breakTags;
  private Hashtable watchTags;

  //{ public SourceViewer(RemoteDebugAdapterInfo mydap, DebugProcess cur)

  /**
   * Create a new SourceViewer object.
   */

  public SourceViewer(RemoteDebugAdapterInfo mydap, DebugProcess cur)
  {
    super("Source Viewer");
    curProcess = cur;
    curGroup = null;
    dap = mydap;
    init();
    decorateBrowser();
  }

  //}
  //{ public SourceViewer(RemoteDebugAdapterInfo mydap, ProcessGroup cur)

  /**
   * Create a new SourceViewer object.
   */

  public SourceViewer(RemoteDebugAdapterInfo mydap, DebugProcessGroup cur)
  {
    super("Source Viewer");
    curGroup = cur;
    curProcess = null;
    dap = mydap;
    init();
    decorateBrowser();
  }

  //}
  //{ private void init()

  /**
   * Initialize this SourceViewer object.
   */

  private void init()
  {
    world = ATerm.the_world;
    GridBagLayout layout;
    GridBagConstraints c;

    tracking = true;

    font = new Font("Helvetica", Font.BOLD, 12);
    setFont(font);
    cpeTags = new Hashtable(32);
    cpeAreas = new Hashtable(32);
    breakTags = new Hashtable(32);
    watchTags = new Hashtable(32);

    //{ Initialize menu bar
    
    MenuBar menuBar = new MenuBar();

    Menu viewerMenu = new Menu("Viewer");
    viewerMenu.add("Clone");
    viewerMenu.add("Close");

    Menu configMenu = new Menu("Configuration");
    configMenu.add("Source paths");
    configMenu.add("Breakpoint types");
    configMenu.add("Watchpoint types");
    configMenu.addSeparator();
    configMenu.add("Load config");
    configMenu.add("Save config");

    menuBar.add(viewerMenu);
    menuBar.add(configMenu);

    setMenuBar(menuBar);

    //}
    //{ Create action panel

    Panel actionPanel = new Panel();

    //{ process panel

    FancyPanel processPanel = new FancyPanel();
    Panel top = new Panel();
    Panel middle = new Panel();
    Panel bottom = new Panel();

    Label processLabel = new Label("Current process:");
    processChoice = new Choice();
    processChoice.addItem("NONE");
    processMode = new Choice();
    processMode.addItem("single-step");
    processMode.addItem("step-over");
    processMode.addItem("run-until-parent");
    processMode.addItem("run");
    Panel dummyMode = new Panel();
    dummyMode.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 5));
    dummyMode.add(processMode);

    start = new Button("Start");
    stop = new Button("Stop");

    top.add(processLabel);
    top.add(processChoice);
    processChoiceContainer = top;
    layout = new GridBagLayout();
    processChoiceLayout = layout;
    top.setLayout(layout);
    c = new GridBagConstraints();
    c.gridx = 0;
    c.gridy = 0;
    c.fill = GridBagConstraints.BOTH;
    layout.setConstraints(processLabel, c);
    c.gridy = 1;
    layout.setConstraints(processChoice, c);

    ///middle.add(processMode);
    middle.add(dummyMode);
    layout = new GridBagLayout();
    middle.setLayout(layout);
    c.gridx = 0;
    //layout.setConstraints(processMode, c);
    layout.setConstraints(dummyMode, c);

    bottom.add(start);
    bottom.add(stop);
    layout = new GridBagLayout();
    layout.setConstraints(start, c);
    c.gridx = 1;
    layout.setConstraints(stop, c);

    processPanel.add(top);
    processPanel.add(middle);
    processPanel.add(bottom);

    layout = new GridBagLayout();
    processPanel.setLayout(layout);
    c.gridx = 0;
    layout.setConstraints(top, c);
    c.gridy = 1;
    layout.setConstraints(middle, c);
    c.gridy = 2;
    layout.setConstraints(bottom, c);

    //}
    //{ location/selection panel 

    FancyPanel currentLoc = new FancyPanel();
    Label moduleLabel = new Label("Module:");
    module = new Label("<none>");
    Label locationLabel = new Label("Location:");
    location = new Label("-#-:-#-");
    Label selectionLabel = new Label("Selection:");
    selection = new Label("-#-:-#-");

    currentLoc.add(moduleLabel);
    currentLoc.add(module);
    currentLoc.add(locationLabel);
    currentLoc.add(location);
    currentLoc.add(selectionLabel);
    currentLoc.add(selection);
    layout = new GridBagLayout();
    currentLoc.setLayout(layout);
    c = new GridBagConstraints();
    c.gridx = 0;
    c.gridy = 0;
    c.fill = GridBagConstraints.BOTH;
    layout.setConstraints(moduleLabel, c);
    c.gridx = 1;
    layout.setConstraints(module, c);
    c.gridx = 0;
    c.gridy = 1;
    layout.setConstraints(locationLabel, c);
    c.gridy = 2;
    c.gridwidth = 2;
    layout.setConstraints(location, c);
    c.gridy = 3;
    c.gridwidth = 1;
    layout.setConstraints(selectionLabel, c);
    c.gridy = 4;
    c.gridwidth = 2;
    c.anchor = GridBagConstraints.EAST;
    layout.setConstraints(selection, c);
    
    actionPanel.add(currentLoc);

    //}
    //{ observation points

    FancyPanel obsPanel = new FancyPanel();
    breakpoint = new Button(" Break ");
    watchVar = new Button(" Watch variable ");
    watchExpr = new Button(" Watch expression ");

    obsPanel.setLayout(new GridLayout(0,1));
    obsPanel.add(breakpoint);
    obsPanel.add(watchVar);
    obsPanel.add(watchExpr);

    //}
    
    FancyPanel dummy = new FancyPanel();

    actionPanel.add(processPanel);
    actionPanel.add(currentLoc);
    actionPanel.add(obsPanel);
    actionPanel.add(dummy);

    layout = new GridBagLayout();
    actionPanel.setLayout(layout);

    c = new GridBagConstraints();
    c.gridx = 0;
    c.gridy = 0;
    c.fill = GridBagConstraints.BOTH;
    layout.setConstraints(processPanel, c);
    c.gridy = 1;
    layout.setConstraints(currentLoc, c);
    c.gridy = 2;
    layout.setConstraints(obsPanel, c);
    c.gridy = 3;
    c.weighty = 1;
    layout.setConstraints(dummy, c);

    //}
    //{ Create source browser

    sourceBrowser = new TextBrowser(this);

    //}
    //{ Layout the main window.

    layout = new GridBagLayout();
    setLayout(layout);
    add(actionPanel);
    add(sourceBrowser);
    
    c = new GridBagConstraints();
    c.gridx = 0;
    c.gridy = 0;
    c.fill = GridBagConstraints.BOTH;
    layout.setConstraints(actionPanel, c);
    
    c.gridx = 1;
    c.weightx = 1;
    c.weighty = 1;
    layout.setConstraints(sourceBrowser, c);

    //}

    updateProcessList();
    resize(500, 360);
    show();
  }

  //}
  //{ public void updateProcessList()

  /**
   * Update the list of processes in the process Choice component.
   */

  public void updateProcessList()
  {
    // jdk 1.02 doesn't support the removal of items from a choice component!
    GridBagConstraints c = processChoiceLayout.getConstraints(processChoice);
    processChoiceContainer.remove(processChoice);
    processChoice = new Choice();
    processChoiceContainer.add(processChoice);
    processChoiceLayout.setConstraints(processChoice, c);

    // jdk 1.1: the Choice component has the 'removeAll' method.
    // processChoice.removeAll();
    nrGroups = 0;
    /*Enumeration groups = dap.getGroups();
    while(groups.hasMoreElements()) {
      nrGroups++;
      DebugProcessGroup group = (DebugProcessGroup)groups.nextElement();
      processChoice.addItem(group.getName());
    }
    */
    Enumeration procs = dap.getProcesses();
    while(procs.hasMoreElements()) {
      String name = ((DebugProcess)procs.nextElement()).toString();
      processChoice.addItem(name);
    }

    if(curProcess != null)
      processChoice.select(curProcess.toString());
    /*else
      processChoice.select(curGroup.getName());
      */
  }

  //}
  //{ public void destroy()

  /**
   * Destroy this source viewer
   */

  public void destroy()
  {
  }

  //}
  //{ public void loadModule(String module)

  /**
   * Load a module in the browser.
   */

  public void loadModule(String module)
  {
    Enumeration paths = dap.getSourcePaths();
    //System.out.println("paths: " + paths);
    boolean found = false;

    while(!found && paths.hasMoreElements()) {
      String file = new File((String)paths.nextElement(), module).getPath();
      try {
	sourceBrowser.loadFile(file);
	System.err.println("file " + file + " succesfully loaded!");
	this.module.setText(module);
	found = true;
	decorateBrowser();
      } catch (IOException e) {
	System.err.println("tried file " + file + ", no success.");
      }
    }
    if(!found)
      System.err.println("couldn't open module: " + module);
  }

  //}
  //{ private void decorateBrowser()

  /**
    * Decorate the browser by highlighting the cpe and all break/watchpoints.
    */

  private void decorateBrowser()
  {
    SourceArea cpe = curProcess.getLocation();
    if(cpe != null)
      cpe(curProcess.getPid(), cpe);

    Enumeration locationRules = dap.getPortRules(DebugPort.LOCATION).elements();
    while(locationRules.hasMoreElements()) {
      DebugRule rule = (DebugRule)locationRules.nextElement();
      if(rule.isBreakpoint())
	addBreakpoint(((LocationPort)rule.getPort()).getLocation(), rule.getId());
      if(rule.isWatchpoint())
	addWatchpoint(((LocationPort)rule.getPort()).getLocation(), rule.getId());
    }
  }

  //}
  //{ public void cpe(int pid, SourceArea area)

  /**
   * Highlight the current point of execution of one of the
   * tracked processes.
   */

  public void cpe(int pid, SourceArea area)
  {
    if((curProcess != null && curProcess.getPid() == pid)
       || (curGroup != null && curGroup.contains(pid))) {

      // Check for the empty location.
      if(area.getStartLine() == 0 && area.getEndLine() == 0 &&
	 area.getStartColumn() == 0 && area.getEndColumn() == 0)
	return;

      Tag cpeTag;
      SourceArea cpeArea;
      Integer Pid = new Integer(pid);
      
      if(!module.getText().equals(area.getModule()))
	loadModule(area.getModule());
      cpeTag = (Tag)cpeTags.get(Pid);
      cpeArea = (SourceArea)cpeAreas.get(Pid);
      if(cpeArea == null) {
	cpeTag = new Tag(null, Color.blue, null);
	cpeTags.put(Pid, cpeTag);
      } else
	sourceBrowser.removeTag(cpeArea, cpeTag);
      sourceBrowser.addTag(area, cpeTag);
      cpeAreas.put(Pid, area);
      location.setText(area.toString());
      if(tracking)
	sourceBrowser.makeVisible(area);
      sourceBrowser.repaintCanvas();
    }
  }

  //}
  //{ public void addWatchpoint(SourceArea area, int rid)

  /**
    * Highlight a watchpoint.
    */

  public void addWatchpoint(SourceArea area, int rid)
  {
    if(module.getText() == area.getModule()) {
      Tag tag = new Tag(null, null, new Color(200, 255, 200));
      watchTags.put(new Integer(rid), tag);
      sourceBrowser.addTag(area, tag);
    } 
  }

  //}
  //{ public void addBreakpoint(SourceArea area, int rid)

  /**
    * Highlight a breakpoint.
    */

  public void addBreakpoint(SourceArea area, int rid)
  {
    if(module.getText() == area.getModule()) {
      Tag tag = new Tag(null, null, new Color(255, 200, 200));
      breakTags.put(new Integer(rid), tag);
      sourceBrowser.addTag(area, tag);
    } 
  }

  //}
  //{ public void removeWatchpoint(int rid)

  /**
    * Remove a watchpoint.
    */

  public void removeWatchpoint(int rid)
  {
    Tag tag = (Tag)watchTags.get(new Integer(rid));
    if(tag != null)
      sourceBrowser.removeTag(tag);
  }

  //}
  //{ public void removeBreakpoint(int rid)

  /**
    * Remove a breakpoint.
    */

  public void removeBreakpoint(int rid)
  {
    Tag tag = (Tag)breakTags.get(new Integer(rid));
    if(tag != null)
      sourceBrowser.removeTag(tag);
  }

  //}
  //{ public boolean action(Event evt, Object what)

  /**
    * Handle button presses etc.
    */

  public boolean action(Event evt, Object what)
  {
    //{ start button

    if(evt.target == start) {
      int pid = curProcess.getPid();
      ATerms procs = world.makeATerms(world.makeInt(pid));
      ATerms actions = world.makeATerms(world.makeAppl(processMode.getSelectedItem()));
      dap.sendExecuteActions(world.makeList(procs), world.makeList(actions));
      return true;
    }

    //}
    //{ stop button

    if(evt.target == stop) {
      int pid = curProcess.getPid();
      ATerms procs = world.makeATerms(world.makeInt(pid));
      ATerms actions = world.makeATerms(world.makeAppl("stop"));
      dap.sendExecuteActions(world.makeList(procs), world.makeList(actions));
      return true;
    }

    //}
    //{ break button

    if(evt.target == breakpoint) {
      // breakpoint button pressed
      SourceArea selection = sourceBrowser.getSelection();
      if(selection != null) {
	selection.setModule(module.getText());
	LocationPort port = new LocationPort(selection, DebugPort.WHEN_AT);
	int pid = curProcess.getPid();
	try {
	  dap.sendCreateRule("break", world.makeSimple("[" + pid + "]"), 
			   port, world.makeSimple("true"),
			   world.makeSimple("[break]"), DebugRule.PERSISTENT);
	} catch (ParseError e) {
	  throw new IllegalArgumentException("internal parse error");
	}
      }
      return true;
    }

    //}
    //{ watch var button

    if(evt.target == watchVar) {
      // watchpoint button pressed
      //System.out.println("Watch variable");
      SourceArea selection = sourceBrowser.getSelection();
      if(selection != null) {
	selection.setModule(module.getText());
	LocationPort port = new LocationPort(selection, DebugPort.WHEN_AT);
	try {
	  int pid = curProcess.getPid();
	  dap.askWatchpoint(world.makeSimple("[" + pid + "]"), port, true);
	} catch (ParseError e) {
	  throw new IllegalArgumentException("internal parse error");
	}
      }
      return true;
    }

    //}
    //{ watch expr button 

    if(evt.target == watchExpr) {
      // watchpoint button pressed
      //System.out.println("Watch expression");
      SourceArea selection = sourceBrowser.getSelection();
      if(selection != null) {
	selection.setModule(module.getText());
	LocationPort port = new LocationPort(selection, DebugPort.WHEN_AT);
	try {
	  int pid = curProcess.getPid();
	  dap.askWatchpoint(world.makeSimple("[" + pid + "]"), port, false);
	} catch (ParseError e) {
	  throw new IllegalArgumentException("internal parse error");
	}
      }
      return true;
    }

    //}
    //{ StringDialog response

    if(evt.target instanceof StringDialog) {
      if(what != null) {
	String act = null;

        switch(evt.id) {
	  case WATCHVAR: 
	    act = "watch(var(\"" + what + "\"))";
	    break;
	  case WATCHEXPR:
	    act = "watch(" + what + "))";
	    break;
	  default:
	    throw new IllegalArgumentException("illegal event id!");
	}
	LocationPort port = (LocationPort)evt.arg;
	int pid = curProcess.getPid();
	try {
	  dap.sendCreateRule("watch", world.makeSimple("[" + pid + "]"), 
			   port, world.makeSimple("true"),
			   world.makeSimple(act), DebugRule.PERSISTENT);
	} catch (ParseError e) {
	  throw new IllegalArgumentException("internal parse error");
	}	
      }
    }

    //}
    return false;
  }

  //}
  //{ public void handleSelection(SourceArea sel)

  /**
    * The selection has changed. Update the display.
    */

  public void handleSelection(SourceArea sel)
  {
    if(sel == null)
      selection.setText("-#-..-#-");
    else
      selection.setText(sel.toString());
  }

  //}
}

//}
//{ class TextBrowser

class TextBrowser extends Panel
{
  private String file;
  private TextBrowserCanvas text;
  private Scrollbar horizontal;
  private Scrollbar vertical;

  //{ public TextBrowser(TextHandler handler)

  /**
   * Create a new TextBrowser object.
   */

  public TextBrowser(TextHandler handler)
  {
    horizontal = new Scrollbar(Scrollbar.HORIZONTAL);
    vertical = new Scrollbar(Scrollbar.VERTICAL);
    text = new TextBrowserCanvas(horizontal, vertical, handler);
    text.setBackground(Color.white);

    add(text);
    add(horizontal);
    add(vertical);

    GridBagLayout layout = new GridBagLayout();
    GridBagConstraints c = new GridBagConstraints();
    setLayout(layout);
    c.fill = GridBagConstraints.BOTH;
    c.gridx = 0;
    c.gridy = 0;
    c.weightx = 1;
    c.weighty = 1;
    layout.setConstraints(text, c);
    c.weightx = 0;
    c.weighty = 0;
    c.gridx = 1;
    c.gridy = 0;
    layout.setConstraints(vertical, c);
    c.gridx = 0;
    c.gridy = 1;
    layout.setConstraints(horizontal, c);
  }

  //}
  //{ public void loadFile(String newFile)

  /**
   * Load a new file in the browser.
   */

  public void loadFile(String newFile)
       throws IOException
  {
    file = newFile;
    FileInputStream f = new FileInputStream(newFile);
    text.load(f);
  }

  //}
  //{ public String getFile()

  /**
   * Return the current file.
   */

  public String getFile()
  {
    return file;
  }

  //}
  //{ public void addTag(SourceArea area, Tag tag)

  /**
   * Tag a specific source area.
   */

  public void addTag(SourceArea area, Tag tag)
  {
    text.addTag(area, tag);
  }

  //}
  //{ public void removeTag(SourceArea area, Tag tag)

  /**
   * Remove a tag from a specific source area.
   */

  public void removeTag(SourceArea area, Tag tag)
  {
    text.removeTag(area, tag);
  }

  //}
  //{ public void removeTag(Tag tag)

  /**
   * Remove a tag.
   */

  public void removeTag(Tag tag)
  {
    text.removeTag(tag);
  }

  //}
  //{ public void removeAllTags()

  /**
    * Remove all tags present in this browser.
    */

  public void removeAllTags()
  {
    text.removeAllTags();
  }

  //}
  //{ public void makeVisible(SourceArea area)

  /**
    * Completely show a certain area (when possible)
    */

  public void makeVisible(SourceArea area)
  {
    text.makeVisible(area);
  }

  //}
  //{ public void repaintCanvas()

  /**
    * Repaint the text browser canvas.
    */

  public void repaintCanvas()
  {
    text.repaint();
  }

  //}
  //{ public SourceArea getSelection()

  /**
    * Retrieve the current selection (null when non-existent)
    */

  public SourceArea getSelection()
  {
    return text.getSelection();
  }

  //}
}

//}
//{ interface TextHandler

/**
  * The TextHandler interface makes it possible to callback
  * on special TextBrowser events.
  */

interface TextHandler
{
  public void handleSelection(SourceArea area);
}

//}
//{ class TextBrowserCanvas

/**
 * The class TextBrowserCanvas implements the canvas used
 * to draw the actual text and markings.
 */

class TextBrowserCanvas 
  extends Canvas
  implements AdjustmentListener, MouseListener, MouseMotionListener,
	     ComponentListener
{
  private TextHandler handler;
  private Vector lines;
  private int nrLines;
  private int nrColumns;
  private int charHeight;
  private int charWidth;
  private int startLine;
  private int startColumn;
  private int width;
  private int height;
  private Font font;
  private FontMetrics fontMetrics;
  private Scrollbar horizontal;
  private Scrollbar vertical;
  private Image bgImg;
  private Graphics bg;
  private Tag selectionTag;
  private SourceArea selection;
  private boolean needsClear;

  //{ public TextBrowserCanvas(Scrollbar hor, Scrollbar vert, TextHandler h)

  /**
   * Create a new TextBrowserCanvas object.
   */

  public TextBrowserCanvas(Scrollbar hor, Scrollbar vert, TextHandler h)
  {
    handler = h;
    horizontal = hor;
    vertical = vert;
    lines = new Vector();
    nrLines = 0;
    nrColumns = 0;
    charHeight = 14;
    charWidth = 12;
    startLine = 0;
    startColumn = 0;
    font = new Font("Courier", Font.PLAIN, 12);
    setFont(font);
    selectionTag = new Tag(font, null, new Color(200,200,255));
    horizontal.addAdjustmentListener(this);
    vertical.addAdjustmentListener(this);
    addMouseMotionListener(this);
    addMouseListener(this);
    addComponentListener(this);
  }

  //}
  //{ public void doLayout()

  /**
    * The size of the canvas changes, update the scrollbar values.
    */

  public void doLayout()
  {
    super.doLayout();

    width = size().width/charWidth;
    height = size().height/charHeight;

    horizontal.setValues(horizontal.getValue(), width, 0, nrColumns);
    vertical.setValues(vertical.getValue(), height, 0, nrLines);

    // We don't want to see the area outside the text.
    startColumn = -Math.max(0, Math.min(nrColumns-width, horizontal.getValue()));
    startLine = -Math.max(0, Math.min(nrLines-height, vertical.getValue()));
  }

  //}
  //{ public void update(Graphics g)

  /**
    * Repaint the canvas without clearing the background.
    */

  public void update(Graphics g)
  {
    paint(g);
  }

  //}
  //{ public void paint(Graphics g)

  /**
   * Paint the text and any special markings.
   */

  public void paint(Graphics g)
  {
    int w = size().width;
    int h = size().height;

    if(bg == null || bgImg.getWidth(null) != w || bgImg.getHeight(null) != h) {
      bgImg = createImage(w, h);
      bg = bgImg.getGraphics();
    }

    if(needsClear) {
      bg.clearRect(0, 0, w, h);
      needsClear = false;
    }

    if(fontMetrics == null)
      fontMetrics = g.getFontMetrics();

    charHeight = fontMetrics.getHeight();
    charWidth = fontMetrics.getMaxAdvance();

    int y = 0;
    for(int line=0; line<height && startLine+line < lines.size(); line++) {
      TextLine text = (TextLine)lines.elementAt(startLine+line);
      text.paint(bg, 0, y, startColumn);
      y += charHeight;
    }

    g.drawImage(bgImg, 0, 0, null);
  }

  //}
  //{ public void componentHidden(ComponentEvent e)

  /**
    * We are not interested in the hiding of components.
    */

  public void componentHidden(ComponentEvent e)
  {
  }

  //}
  //{ public void componentMoved(ComponentEvent e)

  /**
    * We are not interested in the movement of components.
    */

  public void componentMoved(ComponentEvent e)
  {
  }

  //}
  //{ public void componentResized(ComponentEvent e)

  /**
    * When the component is resized, we need to relayout it.
    */

  public void componentResized(ComponentEvent e)
  {
    doLayout();
  }

  //}
  //{ public void componentShown(ComponentEvent e)

  /**
    * We are not interested in the showing of components.
    */

  public void componentShown(ComponentEvent e)
  {
  }

  //}
  //{ public void mousePressed(MouseEvent evt)

  /**
    * The mouse has been pressed on the text area.
    */
  
  public void mousePressed(MouseEvent evt)
  {
    int line, col;

    if(selection == null)
      selection = new SourceArea("", 0,0,0,0);
    else
      removeTag(selection, selectionTag);
    line = whichLine(evt.getY());
    col = whichColumn(evt.getX());
    if(line > nrLines)
      line = nrLines;
    if(getLine(line).getLength() < col)
      col = -1;
    selection.setStartLine(line);
    selection.setEndLine(line);
    if(evt.getClickCount() > 1) {
      selection.setStartColumn(0);
	  selection.setEndColumn(-1);
    } else {
      selection.setStartColumn(col);
      selection.setEndColumn(col);
    }
    addTag(selection, selectionTag);
    repaint();
    handler.handleSelection(selection);
  }

  //}
  //{ public void mouseClicked(MouseEvent e)

  /**
    * We are not interested in mouse clicks.
    */

  public void mouseClicked(MouseEvent e)
  {
  }

  //}
  //{ public void mouseEntered(MouseEvent e)

  /**
    * We are not interested in mouse enterings
    */

  public void mouseEntered(MouseEvent e)
  {
  }

  //}
  //{ public void mouseExited(MouseEvent e)

  /**
    * We are not interested in mouse exits.
    */

  public void mouseExited(MouseEvent e)
  {
  }

  //}
  //{ public void mouseReleased(MouseEvent e)

  /**
    * We are not interested in mouse releases.
    */

  public void mouseReleased(MouseEvent e)
  {
  }

  //}
  //{ public void mouseDragged(MouseEvent evt)

  /**
    * React to mouse dragging.
    */
  
  public void mouseDragged(MouseEvent evt)
  {
    int line, col;

    removeTag(selection, selectionTag);
    line = whichLine(evt.getY());
    col = whichColumn(evt.getX());
    if(line > nrLines)
      line = nrLines;
    if(getLine(line).getLength() < col)
      col = -1;
    selection.setEndLine(line);
    selection.setEndColumn(col);
    addTag(selection, selectionTag);
    repaint();
    handler.handleSelection(selection);
  }

  //}
  //{ public void mouseMoved(MouseEvent e)

  /**
    * We are not interested in mouse movements.
    */

  public void mouseMoved(MouseEvent e)
  {
  }

  //}
  //{ public void scrollbarChanged()

  /**
   * Update the origins when the scrollbar has changed.
   */

  public void scrollbarChanged()
  {
    startLine = vertical.getValue();
    startColumn = horizontal.getValue();
    needsClear = true;
    repaint();
  }

  //}
  //{ public void adjustmentValueChanged(AdjustmentEvent e)

  /**
    * One of the scrollbars must have changed.
    */

  public void adjustmentValueChanged(AdjustmentEvent e)
  {
    scrollbarChanged();
  }

  //}
  //{ public void load(InputStream stream)

  /**
   * Load and display a text.
   */

  public void load(InputStream stream)
       throws IOException
  {
    int c;
    lines = new Vector();
    StringBuffer line = new StringBuffer();
    String eol = System.getProperty("line.separator");
    int eollen = eol.length();
    boolean eolfound;
    Tag defaultTag = new Tag(font, Color.black, Color.white);

    selection = null;
    nrColumns = 0;
    do {
      c = stream.read();
      if(c != -1) {
	line.append((char)c);
	eolfound = true;
	if(line.length() < eollen)
	  eolfound = false;
	for(int i=0; i<eollen && eolfound; i++) {
	  if(line.charAt(line.length()-eollen+i) != eol.charAt(i))
	    eolfound = false;
	}
	if(eolfound) {
	  line.setLength(line.length()-eollen);
	  TextLine txt = new TextLine(line.toString());
	  txt.setDefault(defaultTag);
	  lines.addElement(txt);
	  if(line.length() > nrColumns)
	    nrColumns = line.length();
	  line.setLength(0);
	}
      }
    } while(c != -1);
    nrLines = lines.size();

    doLayout();
    repaint();
  }

  //}
  //{ public void addTag(SourceArea area, Tag tag)

  /**
   * Add a specific tag to a source area.
   */

  public void addTag(SourceArea area, Tag tag)
  {
    int sl = area.getStartLine();
    int el = area.getEndLine();
    int sc = area.getStartColumn();
    int ec = area.getEndColumn();
    if(sl > el || (sl == el && ((sc >= ec && ec != -1) || sc == -1))) {
      // swap start and end coordinates
      int tmp = el;
      el = sl;
      sl = tmp;
      tmp = ec;
      ec = sc;
      sc = tmp;
    }
    for(int line = sl; line <= el; line++) {
      int start = 0;
      int end = -1;
      if(line == sl)
	start = sc;
      if(line == el)
	end = ec;
      getLine(line).addTag(start, end, tag);
    }
  }

  //}
  //{ public void removeTag(SourceArea area, Tag tag)

  /**
   * Remove a tag from a specific source area.
   */

  public void removeTag(SourceArea area, Tag tag)
  {
    int sl = area.getStartLine();
    int el = area.getEndLine();
    int sc = area.getStartColumn();
    int ec = area.getEndColumn();
    if(sl > el || (sl == el && ((sc >= ec && ec != -1)|| sc == -1))) {
      // swap start and end coordinates
      int tmp = el;
      el = sl;
      sl = tmp;
      tmp = ec;
      ec = sc;
      sc = tmp;
    }
    for(int line = sl; line <= el; line++) {
      int start = 0;
      int end = -1;
      if(line == sl)
	start = sc;
      if(line == el)
	end = ec;
      getLine(line).removeTag(start, end, tag);
    }
  }

  //}
  //{ public void removeTag(Tag tag)

  /**
   * Remove a specific tag from all source positions.
   */

  public void removeTag(Tag tag)
  {
    for(int i=0; i<lines.size(); i++)
      ((TextLine)lines.elementAt(i)).removeTag(tag);
  }

  //}
  //{ public void removeAllTags()

  /**
    * Remove all tags present in this browser.
    */

  public void removeAllTags()
  {
    for(int i=0; i<lines.size(); i++)
      ((TextLine)lines.elementAt(i)).removeAllTags();
  }

  //}
  //{ public void makeVisible(SourceArea area)

  /**
    * Completely show a certain area (when possible)
    */

  public void makeVisible(SourceArea area)
  {
    // Check if the area is already completely visible
    if(area.getStartLine() >= startLine && 
       area.getEndLine() < startLine+height)
      return;

    // Center the area so it becomes visible.
    int centerLine = (area.getStartLine()+area.getEndLine())/2;
    startLine = centerLine - height/2;
    if(startLine < 0)
      startLine = 0;
    needsClear = true;
  }

  //}
  //{ public int whichLine(int mousey)

  /**
    * Get the line number of a mouse coordinate.
    */

  public int whichLine(int mousey)
  {
    //mousey += insets().top;
    int line = (mousey/charHeight)+startLine;
    return line+1;
  }

  //}
  //{ public int whichColumn(int mousex)

  /**
    * Get the column number of a mouse coordinate.
    */

  public int whichColumn(int mousex)
  {
    //mousex += insets().left;
    return (mousex/charWidth)+startColumn;
  }

  //}
  //{ public TextLine getLine(int line)

  /**
    * Retrieve a line of text.
    */

  public TextLine getLine(int line)
  {
    return (TextLine)lines.elementAt(line-1);
  }
  
  //}
  //{ public SourceArea getSelection()

  /**
    * Retrieve the current selection (null when non-existent)
    */

  public SourceArea getSelection()
  {
    return selection;
  }

  //}
}

//}
//{ class TextLine

/**
 * TextLine objects represent lines of text.
 */

class TextLine
{
  private String text;
  private Vector[] tags;
  private Tag defaultTag;

  public TextLine(String txt)
  {
    text = txt;
    tags = new Vector[text.length()];
    defaultTag = new Tag(null, Color.black, Color.white);
  }

  public void paint(Graphics g, int x, int y, int firstChar)
  {
    int start, i = firstChar;
    int width, height;
    Tag tag;
    Color fg, bg;
    Font fn;

    while(i < text.length()) {
      for(start=i; i<text.length() && sameTags(tags[start], tags[i]); i++)
	;
      Vector current = tags[start];

      String sub = text.substring(start, i);
      fg = defaultTag.getForeground();
      bg = defaultTag.getBackground();
      fn = defaultTag.getFont();
      if(current != null) {
	Enumeration e = current.elements();
	while(e.hasMoreElements()) {
	  tag = (Tag)e.nextElement();
	  if(tag.getForeground() != null)
	    fg = tag.getForeground();
	  if(tag.getBackground() != null)
	    bg = tag.getBackground();
	  if(tag.getFont() != null)
	    fn = tag.getFont();
	}
      }
      g.setFont(fn);
      FontMetrics fm = g.getFontMetrics();
      width = fm.stringWidth(sub);
      height = fm.getHeight();
      g.setColor(bg);
      g.fillRect(x, y, width, height);
      g.setColor(fg);
      g.drawString(sub, x, y+fm.getAscent());
      x += width;
    }
  }

  public boolean sameTags(Vector tags1, Vector tags2)
  {
    Enumeration e1, e2;
    boolean done = false;

    if(tags1 == null)
      return tags2 == null;
    if(tags2 == null)
      return false;

    e1 = tags1.elements();
    e2 = tags2.elements();
    while(true) {
      if(!e1.hasMoreElements())
	return !e2.hasMoreElements();
      if(!e2.hasMoreElements())
	return false;
      if(e1.nextElement() != e2.nextElement())
	return false;
    }
  }

  public void addTag(int startCol, int endCol, Tag tag)
  {
    if(endCol == -1)
      endCol = text.length();
    if(startCol == -1)
      startCol = text.length();
    for(int i=startCol; i<endCol; i++) {
      if(tags[i] == null)
	tags[i] = new Vector();
      tags[i].addElement(tag);
    }
  }

  public void removeTag(int startCol, int endCol, Tag tag)
  {
    if(endCol == -1)
      endCol = text.length();
    if(startCol == -1)
      startCol = text.length();
    for(int i=startCol; i<endCol; i++) {
      if(tags[i] != null)
	tags[i].removeElement(tag);
    }
  }

  public void removeTag(Tag tag)
  {
    removeTag(0, -1, tag);
  }

  public void removeAllTags()
  {
    for(int i=0; i<text.length(); i++)
      tags[i] = null;
  }

  public void setDefault(Tag tag)
  {
    defaultTag = tag;
  }

  public String toString()
  {
    return text.toString();
  }

  public int getLength()
  {
    return text.length();
  }
}

//}
//{ class Tag

/**
 * Represents a text tag (and associated style).
 */

class Tag
{
  private Color foreground;
  private Color background;
  private Font font;

  public Tag(Font fnt, Color fg, Color bg)
  {
    font = fnt;
    foreground = fg;
    background = bg;
  }

  public Color getBackground()
  {
    return background;
  }

  public Color getForeground()
  {
    return foreground;
  }

  public Font getFont()
  {
    return font;
  }
}

//}







