package metastudio;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.util.*;
import java.util.List;

import javax.swing.*;
import javax.swing.event.*;
import javax.swing.tree.*;
import javax.swing.text.*;

import metastudio.graph.*;
import aterm.*;

public class MetaStudio extends JFrame implements UserInterfaceTif, Runnable, ModuleSelectionListener  {
    // TODO: move preference constants to Preferences class
  private static final String PREF_TREEPANE_BACKGROUND = "treepane.background";
  private static final String PREF_MSGPANE_BACKGROUND = "messagepane.background";
  private static final String PREF_MSGPANE_STATUS = "messagepane.status";
  private static final String PREF_GRAPHPANE_BACKGROUND = "graphpane.background";
  private static final String PREF_GRAPHPANE_SCALES = "graphpane.scales";
  private static final String PREF_STATUSPANE_BACKGROUND = "statuspane.background";

  private static final int NODE_BORDER_WIDTH = 5;
  private static final int NODE_BORDER_HEIGHT = 5;

  private static ATerm ACTION_MENUBAR;
  private static ATerm ACTION_TOOLBAR;
  private static ATerm ACTION_MODULE_POPUP;
  private static ATerm ACTION_NEW_MODULE_POPUP; // TODO: to be removed

  public static MetaGraphFactory factory;

  private UserInterfaceBridge bridge;

  private JMenuBar menuBar;
  private JToolBar toolBar;
  private Map menuMap;
  private JTree moduleTree;
  private JPopupMenu popupMenu;
  private JComponent component;

  private int mouseX;
  private int mouseY;

  private JScrollPane historyPane;

  private StyleContext historyStyles;
  private DefaultStyledDocument historyDoc;
  private JTextPane history;
  private Style styleError;
  private Style styleWarning;
  private Style styleMessage;
  private JLabel statusBar;
  private JCheckBox statusLog;
  private List statusMessages;

  private Action actionOpenModule;
  private Action actionOpenLibModule;
  private Action actionNewModule;
  private Action actionSaveAll;
  private Action actionClearAll;
  private Action actionRefreshButtons;
  private Action actionClearHistory;
  private Action actionQuit;

  private JTabbedPane graphPane;

  private GraphWrapper graph;
  private ImportGraphPanel importGraphPanel;
  private ParseTreePanel parseTreePanel;

  private Map graphPanels;

  private ModuleStatusPanel moduleStatus;

  private JCheckBox tideBox;
  private JComboBox scaleBox;

  private Frame topFrame;

  private String currentModule;
  private ModuleTreeModel moduleManager;

  private MessageList messageList; 
  private MessageWindow messageWindow;

  public static final void main(String[] args) throws IOException {
    MetaStudio studio = new MetaStudio(args);
    studio.bridge.run();
  }

  //{{{ private JMenuBar createMenuBar()

  private JMenuBar createMenuBar()
  {
    JMenuBar menuBar = new JMenuBar();
    bridge.postEvent(factory.make("get-buttons(<term>,<str>)",
				  ACTION_MENUBAR, "*"));

    return menuBar;
  }

  //}}}
  //{{{ private JPopupMenu createPopupMenu()

  private JPopupMenu createPopupMenu() {
    JPopupMenu popup = new JPopupMenu();

    popup.addPopupMenuListener(new PopupMenuListener() {
      public void popupMenuCanceled(PopupMenuEvent event) { }
      public void popupMenuWillBecomeVisible(PopupMenuEvent event) {
        importGraphPanel.setDragEnabled(false);
      }
      public void popupMenuWillBecomeInvisible(PopupMenuEvent event) {
	importGraphPanel.setDragEnabled(true);
      }
    });

    return popup;
  }

  //}}}
  //{{{ private JToolBar createToolBar()

  private JToolBar createToolBar()
  {
    JToolBar bar = new JToolBar();

    bridge.postEvent(factory.make("get-buttons(<term>,<str>)",
				  ACTION_TOOLBAR, "*"));

    return bar;
  }

  //}}}

  public MetaStudio(String[] args) throws IOException {
    Color color;

    topFrame = this;

    graphPanels = new HashMap();

    factory = new MetaGraphFactory();
    moduleManager = new ModuleTreeModel();
    statusMessages = new LinkedList();

    InputStream propertyStream = getClass().getResourceAsStream("/META-INF/default.properties");
    Properties properties = new Properties();
    properties.load(propertyStream);
    Preferences.initialize("MetaStudio Preferences", properties);
    try {
      File file = new File(System.getProperty("user.home"), ".metarc");
      propertyStream = new FileInputStream(file);
      Preferences.load(propertyStream);
    } catch (IOException e) {
      // do nothing
    }

    // TODO: apification
    ACTION_MENUBAR = factory.parse("studio-menubar");
    ACTION_TOOLBAR = factory.parse("studio-toolbar");
    ACTION_MODULE_POPUP = factory.parse("module-popup");
    ACTION_NEW_MODULE_POPUP = factory.parse("new-module-popup");

    // TODO: method extraction for every fold
    
    //{{{ Create ToolBus bridge

    bridge = new UserInterfaceBridge(factory, this);
    bridge.init(args);
    bridge.connect();
    bridge.setLockObject(getTreeLock());

    //}}}
    //{{{ Handle 'close' requests

    addWindowListener(new WindowAdapter() {
		      public void windowClosing(WindowEvent ev) {
		      bridge.sendEvent(factory.parse("quit"));
		      }
		      });

    //}}}
    //{{{ Create module list
    moduleTree = new JTree(moduleManager);
    moduleTree.setRootVisible(false);
    moduleTree.setShowsRootHandles(true);
    moduleTree.setExpandsSelectedPaths(true);
    moduleTree.setSelectionModel(new ModuleSelectionModel());

    TreeSelectionListener moduleTreeListener = new TreeSelectionListener() {
      public void valueChanged(TreeSelectionEvent event) {
	moduleManager.selectModule(moduleManager.getModule(getCurrentModule()));
      }
    };

    moduleTree.addTreeSelectionListener(moduleTreeListener);

    moduleTree.addMouseListener(new MouseAdapter() {
				public void mousePressed(MouseEvent e) {
				checkModulePopup(e);
				}
				public void mouseReleased(MouseEvent e) {
				checkModulePopup(e);
				}
				});

    JScrollPane listPane = new JScrollPane(moduleTree);

    color = Preferences.getColor(PREF_TREEPANE_BACKGROUND);
    moduleTree.setBackground(color);

    //}}}

    menuBar = createMenuBar();
    popupMenu = createPopupMenu();
    toolBar = createToolBar();

    graphPane = new JTabbedPane();

    //{{{ Create module graph

    graph = GraphWrapper.emptyGraph(factory);

    importGraphPanel = new ImportGraphPanel(moduleManager);
    addGraphPanel(importGraphPanel, "Import graph");

    importGraphPanel.addMouseListener(new MouseAdapter() {
				      public void mousePressed(MouseEvent e) {
				      checkModulePopup(e);
				      }
				      public void mouseReleased(MouseEvent e) {
				      checkModulePopup(e);
				      }
				      });

    color = Preferences.getColor(PREF_GRAPHPANE_BACKGROUND);
    importGraphPanel.setBackground(color);

    //graphPane.setViewportView(graphPanel);

    //}}}

    parseTreePanel = new ParseTreePanel(bridge, factory);
    addGraphPanel(parseTreePanel, "Parsetree graph");

    //{{{ Create message history

    historyStyles = new StyleContext();
    styleMessage = initStyle("messagepane.message");
    styleWarning = initStyle("messagepane.warning");
    styleError = initStyle("messagepane.error");

    historyDoc = new DefaultStyledDocument(historyStyles);
    history = new JTextPane(historyDoc);
    history.setEditable(false);

    color = Preferences.getColor(PREF_MSGPANE_BACKGROUND);
    history.setBackground(color);

    statusBar = new JLabel("idle");
    statusLog = new JCheckBox("Log Status");
    statusLog.setSelected(Preferences.getBoolean(PREF_MSGPANE_STATUS + ".log"));

    //}}}
    //{{{ Create module status panel

    moduleStatus = new ModuleStatusPanel(moduleManager);
    color = Preferences.getColor(PREF_STATUSPANE_BACKGROUND);
    moduleStatus.setBackground(color);

    //}}}

    //msgLabel = new JLabel("Welcome to MetaStudio!");
    moduleManager.addModuleSelectionListener(this);

    //{{{ Glue UI components

    JPanel treePanel = new JPanel();

    historyPane = new JScrollPane(history);

    JPanel historyPanel = new JPanel();
    historyPanel.setLayout(new BorderLayout());
    JPanel statusBarPanel = new JPanel();
    statusBarPanel.setLayout(new BorderLayout());

    color = Preferences.getColor(PREF_MSGPANE_STATUS + ".background");

    statusLog.setBackground(color);
    statusBarPanel.setBackground(color);
    color = Preferences.getColor(PREF_MSGPANE_STATUS + ".foreground");

    statusLog.setForeground(color);
    statusBarPanel.setForeground(color);
    Font font = Preferences.getFont(PREF_MSGPANE_STATUS + ".font");
    statusBar.setFont(font);
    statusLog.setFont(font);

    statusBarPanel.add(statusBar, BorderLayout.CENTER);
    statusBarPanel.add(statusLog, BorderLayout.EAST);
    historyPanel.add(historyPane, BorderLayout.CENTER);
    historyPanel.add(statusBarPanel, BorderLayout.SOUTH);

    Container content = getContentPane();

    treePanel.setLayout(new BorderLayout());
    treePanel.add(listPane, BorderLayout.CENTER);

    JSplitPane leftPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT, treePanel, moduleStatus);
    leftPanel.setResizeWeight(0.8);

    JSplitPane rightPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT, graphPane, historyPanel);
    rightPanel.setResizeWeight(0.8);

    JSplitPane mainPanel = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftPanel, rightPanel);

    setJMenuBar(menuBar);
    content.setLayout(new BorderLayout());
    content.add(toolBar, BorderLayout.NORTH);
    content.add(mainPanel, BorderLayout.CENTER);

    //}}}

    //{{{ Actually show this JFrame

    Dimension screenSize = getToolkit().getScreenSize();
    int width = 800;
    int height = 600;
    int x = (screenSize.width - width) / 2;
    int y = (screenSize.height - height) / 2;

    setTitle("Meta-Environment");
    setSize(width, height);
    setLocation(x, y);

    setVisible(true);

    mainPanel.setDividerLocation(0.3);
    leftPanel.setDividerLocation(0.65);
    rightPanel.setDividerLocation(0.8);

    // Message list

    messageList = new MessageList(bridge, factory);
    messageWindow = new MessageWindow(messageList);

    //}}}
  }

  //{{{ private Vector parseScales()

  private Vector parseScales()
  {
    String scaleList = Preferences.getString(PREF_GRAPHPANE_SCALES);
    Vector scales = new Vector();
    StringTokenizer t = new StringTokenizer(scaleList, ",");
    while (t.hasMoreTokens()) {
      String scale = t.nextToken();
      scales.add(scale);
    }
    return scales;
  }

  //}}}
  //{{{ private JComboBox createScaleBox()

  private JComboBox createScaleBox()
  {
    final JComboBox scaleBox = new JComboBox(parseScales()) {
      public Dimension getMaximumSize() {
	return getPreferredSize();
      }
    };

    scaleBox.setSelectedItem(Preferences.getString(PREF_GRAPHPANE_SCALES
						   + ".default"));

    ActionListener listener = new ActionListener() {
      public void actionPerformed(ActionEvent event) {
	String value = scaleBox.getSelectedItem().toString();
	// Strip off '%' sign
	if (value.charAt(value.length() - 1) == '%') {
	  value = value.substring(0, value.length() - 1);
	}
	int percentage = Integer.parseInt(value);
	importGraphPanel.setScale(percentage);
	parseTreePanel.setScale(percentage);
      }
    };

    scaleBox.addActionListener(listener);

    return scaleBox;
  }

  //}}}

  private void addGraphPanel(GraphPanel panel, String toolTip) {
    int index = graphPanels.size();
    panel.setIndex(index);
    graphPanels.put(panel.getId(), panel);
    graphPane.insertTab(panel.getId(), null, new JScrollPane(panel), toolTip, index);
  }

  private GraphPanel getGraphPanel(String id) {
    return (GraphPanel) graphPanels.get(id);
  }

  private Style initStyle(String prop) {
    Style style = historyStyles.addStyle(null, null);

    Font font = Preferences.getFont(prop + ".font");

    StyleConstants.setFontFamily(style, font.getFamily());
    StyleConstants.setFontSize(style, font.getSize());
    StyleConstants.setItalic(style, font.isItalic());
    StyleConstants.setBold(style, font.isBold());

    Color background = Preferences.getColor(prop + ".background");
    StyleConstants.setBackground(style, background);
    Color foreground = Preferences.getColor(prop + ".foreground");
    StyleConstants.setForeground(style, foreground);

    return style;
  }

  private void resetGraph() {
    graph.reset();
  }

  public void run() {
    layoutGraph(importGraphPanel, graph);
  }

  public void moduleInfo(String module, ATerm info) {
    ATermList pairs = (ATermList) info;
    List entries = new LinkedList();

    while (!pairs.isEmpty()) {
      ATermList pair = (ATermList) pairs.getFirst();

      String name = pair.getFirst().toString();

      String value;
      ATerm valueTerm = pair.getNext().getFirst();
      if (valueTerm.getType() == ATerm.APPL) {
	value = ((ATermAppl) valueTerm).getName();
      } else {
	value = valueTerm.toString();
      }
      String[] entry = { name, value };
      entries.add(entry);

      pairs = pairs.getNext();
    }

    moduleStatus.setModuleInfo(module, entries);
  }

  void addMessage(Style style, String id, String message) {
    Object lock = history.getTreeLock();
    synchronized (lock) {
      try {
	historyDoc.insertString(historyDoc.getLength(), message + "\n", style);
	int start = historyDoc.getLength();
	Rectangle rect = history.modelToView(start);
	if (rect != null) {
	  JViewport viewport = historyPane.getViewport();

	  // Make rectangle relative to viewport
	  rect.x -= viewport.getViewPosition().x;
	  rect.y -= viewport.getViewPosition().y;
	  viewport.scrollRectToVisible(rect);
	}
      } catch (BadLocationException e) {
	System.err.println("bad location: " + e.getMessage());
      }
    }
  }

  void clearStatus(String id) {
    ListIterator iter = statusMessages.listIterator();
    while (iter.hasNext()) {
      String[] pair = (String[]) iter.next();
      if (pair[0].equals(id)) {
	iter.remove();
      }
    }

    if (statusMessages.size() == 0) {
      statusBar.setText("idle");
    } else {
      statusBar.setText(((String[]) statusMessages.get(0))[1]);
    }
  }

  String formatString(String format, ATermList args) {
    int index;
    String prefix = "";
    String postfix = format;
    while ((index = postfix.indexOf("%")) != -1) {
      prefix += postfix.substring(0, index);
      switch (postfix.charAt(index + 1)) {
	case 't' :
	case 'd' :
	  prefix += args.getFirst().toString();
	  break;
	case 's' :
	  prefix += ((ATermAppl) args.getFirst()).getName();
	  break;
	default :
	  prefix += "%" + postfix.charAt(index + 1);
      }
      postfix = postfix.substring(index + 2);
      args = args.getNext();
    }
    return prefix + postfix;
  }

  public void addStatus(ATerm id, String message) {
    String ids = id.toString();
    if (statusLog.isSelected()) {
      addMessage(styleMessage, ids, message);
    }
    statusBar.setText(message);
    String[] pair = { ids, message };
    statusMessages.add(pair);
  }

  public void addStatusf(ATerm id, String format, ATerm args) {
    String message = formatString(format, (ATermList) args);
    addStatus(id, message);
  }

  public void endStatus(ATerm id) {
    clearStatus(id.toString());
  }

  public void errorf(String format, ATerm args) {
    String message = formatString(format, (ATermList) args);
    addMessage(styleError, null, message);
  }

  public void error(String message) {
    addMessage(styleError, null, message);
  }

  public void warning(String message) {
    addMessage(styleWarning, null, message);
  }

  public void initializeUi(String name) {
    setTitle(name);
    Preferences.setString("metastudio.name", name);
  }

  private Module addModule(String name) {
    Module module = moduleManager.getModule(name);
    if (module == null) {
      module = new Module(name);
      moduleManager.addModule(module);
    }

    return module;
  }

  private void setModules(ATermList importList) {
    moduleManager.clearModules();

    while (!importList.isEmpty()) {
      ATermList importPair = (ATermList) importList.getFirst();
      importList = importList.getNext();
      ATermAppl moduleTerm = (ATermAppl) importPair.getFirst();
      String name = moduleTerm.getName();
      addModule(name);
    }
  }

  private void setImports(ATermList importList) {

    while (!importList.isEmpty()) {
      ATermList importPair = (ATermList) importList.getFirst();
      importList = importList.getNext();

      ATermAppl fromTerm = (ATermAppl) importPair.getFirst();
      String from = fromTerm.getName();
      Module moduleFrom = moduleManager.getModule(from);
      if (moduleFrom == null) {
	moduleFrom = addModule(from);
	moduleFrom.setState(Module.STATE_NEW);
      }

      ATermList imports = (ATermList) importPair.elementAt(1);

      while (!imports.isEmpty()) {
	ATermAppl toTerm = (ATermAppl) imports.getFirst();
	imports = imports.getNext();

	String to = toTerm.getName();
	Module moduleTo = moduleManager.getModule(to);
	if (moduleTo == null) {
	  moduleTo = addModule(to);
	  moduleTo.setState(Module.STATE_NEW);
	}

	moduleFrom.addChild(to);
	moduleTo.addParent(from);
      }
    }
  }

  public void deleteModules(ATerm mods) {
    ATermList modules = (ATermList) mods;

    for (; !modules.isEmpty(); modules = modules.getNext()) {
      String name = ((ATermAppl) modules.getFirst()).getAFun().getName();
      Module module = moduleManager.getModule(name);
      if (module != null) {
	moduleManager.removeModule(name);
	graph.deleteNode(name);
      }
    }
    moduleManager.selectModule(currentModule);
    layoutGraph(importGraphPanel, graph);
  }

  public void newGraph(ATerm importRelations) {
    setModules((ATermList) importRelations);
    setImports((ATermList) importRelations);

    graph = GraphWrapper.fromImportList(factory, (ATermList) importRelations);
    layoutGraph(importGraphPanel, graph);
  }

  public void layoutGraph(GraphPanel graphPanel, GraphWrapper graph) {
    final FontMetrics metrics = graphPanel.getFontMetrics(Preferences.getFont(GraphPanel.PREF_NODE_FONT));

    NodeSizer sizer = new NodeSizer() {
      public int getWidth(Node node) {
	return metrics.stringWidth(node.getLabel()) + NODE_BORDER_WIDTH * 2;
      }
      public int getHeight(Node node) {
	return metrics.getHeight() + NODE_BORDER_HEIGHT * 2;
      }
    };

    graph.orderNodes();
    graph.sizeNodes(sizer);

    bridge.postEvent(factory.make("layout-graph(<str>,<term>)", graphPanel.getId(), graph.toTerm()));
  }

  public void displayGraph(String id, ATerm graphTerm) {
    GraphWrapper graph = GraphWrapper.fromTerm(graphTerm);
    GraphPanel panel = getGraphPanel(id);
    layoutGraph(panel, graph);
  }

  public void graphLayouted(String id, ATerm graphTerm) {
    GraphWrapper graph = GraphWrapper.fromTerm(graphTerm);
    if (id.equals(importGraphPanel.getId())) {
      this.graph = graph;
    }
    GraphPanel graphPanel = getGraphPanel(id);
    graphPanel.setGraph(graph);
    graphPanel.repaint();
    graphPane.setSelectedIndex(graphPanel.getIndex());
  }

  public void moduleSelected(Module module) {
    if (module == null) {
      moduleTree.clearSelection();
    } else {
      TreePath path = moduleManager.makeTreePath(module.getName());

      moduleTree.setSelectionPath(path);
      moduleTree.scrollPathToVisible(path);

      if (module.getState() == Module.STATE_NORMAL) {
	bridge.postEvent(factory.make("get-module-info(<str>)", module.getName()));
      }
    }
  }

  public void updateList(String moduleName, String actions) {
    ATerm data = factory.parse(actions);

    messageWindow.setVisible(true);

    if (data instanceof ATermAppl) {
      ATermAppl applData = (ATermAppl) data;
      data = (ATerm) applData.getArguments().getFirst();
      error("Deprecated use of list with function symbol "
			 + applData.getAFun());
    }

    if (data instanceof ATermList) {
      messageList.setContent(moduleName, (ATermList) data);
    } else {
      error("Can't show something in list view which is not a ATermList: "
	    + data);
    }
  }

  public void recAckEvent(ATerm event) {
  }

  public void recTerminate(ATerm t0) {
    System.exit(0);
  }

  void checkModulePopup(MouseEvent e) {
    boolean showPopup = false;

    showPopup |= e.isPopupTrigger();

    if (showPopup) {
      Module module;
      mouseX = e.getX();
      mouseY = e.getY();

      if (e.getSource() == moduleTree) {
	component = moduleTree;
	currentModule = getCurrentModule();
      } else if (e.getSource() == importGraphPanel) {
	component = importGraphPanel;
	Node node = importGraphPanel.getNodeAt(mouseX, mouseY);

	if (node != null) {
	  currentModule = node.getLabel();
	} else {
	  currentModule = null;
	}
      } else {
	component = null;
      }

      if (currentModule != null && component != null) {
	module = moduleManager.getModule(currentModule);
	moduleManager.selectModule(module);

	switch (module.getState()) {
	  case Module.STATE_NORMAL :
	    showModulePopup(ACTION_MODULE_POPUP);
	    break;
	  case Module.STATE_NEW :
	    showModulePopup(ACTION_NEW_MODULE_POPUP);
	    break;
	}
      }
    }
  }

  private void showModulePopup(ATerm buttonType) {
    bridge.postEvent(factory.make("get-buttons(<term>,<str>)",
				  buttonType, currentModule));

  }

  private void addToolBarAction(final ATermAppl action) {
    /* APIGEN */
    String label = ((ATermAppl)action.getArgument(0)).getName(); // TODO: apification
    String name = ((ATermAppl)action.getArgument(1)).getName();  // TODO: apification
    String path = "/images/" + name; // TODO: externalize string?
    URL url = path.getClass().getResource(path);
    if (url == null) {
      error("Unable to get icon: " + path);
    }
    else {
      Icon icon = new ImageIcon(url);
      Action it = new AbstractAction(label, icon) {
	public void actionPerformed(ActionEvent actionEvent) {
	  ATerm event = factory.make("button-selected(<term>,<term>)",
				     ACTION_TOOLBAR, action);
	  bridge.postEvent(event);
	}
      };
      JButton button = toolBar.add(it);
      button.setToolTipText(label);
    }
  }

  private void addToolBarActions(ATermList buttons) {
    while (!buttons.isEmpty()) {
      ATerm button = buttons.getFirst();
      addToolBarAction((ATermAppl)button);
      buttons = buttons.getNext();
    }

    toolBar.add(Box.createHorizontalGlue());
    toolBar.add(createScaleBox());
  }

  //{{{ public void buttonsFound(ATerm buttonType, String moduleName, ATerm buttons)

  public void buttonsFound(ATerm buttonType, String moduleName, ATerm buttons)
  {
    if (buttonType.equals(ACTION_MENUBAR)) {
      addMenu(buttonType, moduleName, (ATermList) buttons);
    }
    else if(buttonType.equals(ACTION_TOOLBAR)) {
      addToolBarActions((ATermList) buttons);
    }
    else {
      popupMenu.removeAll();
      addPopupMenuItems(popupMenu,
			buttonType,
			moduleName,
			(ATermList) buttons,
			factory.makeList());
      popupMenu.show(component, mouseX, mouseY);
    }
  }

  //}}}

  private JMenu getMenu(String name) {
    JMenu menu;

    if (menuMap == null) {
      menuMap = new HashMap();
    }

    menu = (JMenu) menuMap.get(name);

    if (menu == null) {
      menu = new JMenu(name);
      menuMap.put(name, menu);
      menuBar.add(menu);
    }

    validate();

    return menu;
  }

  private JMenu findMenuLocation(JMenu[] children, String name) {
    for (int i=0; i<children.length; i++) {
      if (name.equals(children[i].getText())) {
	return children[i];
      }
    }
    return null;
  }

  private JMenu addMenuName(JMenu menu, String name) {
    JMenu[] children = (JMenu[]) menu.getSubElements();	// TODO: this is illegal code, the cast is wrong
    JMenu location = findMenuLocation(children, name);

    if (location == null) {
      JMenu newItem = new JMenu(name);
      menu.add(newItem);
      return newItem;
    }

    return location;
  }

  private JMenu getMenuItem(JMenu menu, ATermList names) {
    JMenu cur = menu;

    while (!names.isEmpty()) {
      if (names.getLength() == 1) {
	break;
      }
      else {
	String name = ((ATermAppl)names.getFirst()).getName();
	cur = addMenuName(cur, name);
	names = names.getNext();
      }
    }

    return cur;
  }

  private String getMenuName(ATermList names) {
    return ((ATermAppl)names.getLast()).getName();
  }

  private void addMenu(ATerm type, String moduleName, ATermList buttons) {
    // TODO: use APIGEN on buttons.adt iso using ATermList et al. here
    while (!buttons.isEmpty()) {
      ATerm action = buttons.getFirst();
      ATermList menuItems = (ATermList) ((ATermAppl)action).getArgument(0);
      ATerm menuItem = menuItems.getFirst();
      String menuName = ((ATermAppl) menuItem).getName();
      JMenu menu = getMenuItem(getMenu(menuName), menuItems.getNext());
      menu.add(new ButtonAction(getMenuName(menuItems),
				type,
				action,
				moduleTree,
				bridge,
				factory));
      buttons = buttons.getNext();
    }
  }


  // TODO: change algorithm, do it in two parts: first find tree structure, then
  // build the menus
  
  // The next two methods (addPopupMenuItems, addMenuItems) are exactly the
  // same. The reason is that JPopupMenu and JMenu have the same methods,
  // but are in different hierarchies. Also, we did not succeed in making
  // the methods smaller.
  public void addPopupMenuItems(JPopupMenu menu,
				ATerm buttonType,
				String moduleName,
				ATermList buttons,
				ATermList prefixButtonName) {

    while (!buttons.isEmpty()) {
      ATerm action = buttons.getFirst();
      ATermList buttonList = (ATermList) ((ATermAppl)action).getArgument(0);
      ATermAppl buttonNamePrefix = (ATermAppl) (buttonList.getFirst());

      buttons = buttons.getNext();

      if (buttonList.getLength() == 1) {
	menu.add(new ButtonAction(buttonNamePrefix.getName(),
				  buttonType,
				  action,
				  moduleTree,
				  bridge,
				  factory));
      } else {
	ATermList buttonRunner = buttons;
	JMenu nextLevel = new JMenu(buttonNamePrefix.getName());
	ATerm apifyMe = factory.make("menu(<term>)", buttonList.getNext());
	ATermList subMenu = factory.makeList(apifyMe);

	// collect a list of buttons that are in the same 'menuNamePrefix'
	for (; !buttonRunner.isEmpty(); buttonRunner = buttonRunner.getNext()) {
	  ATerm cur = buttonRunner.getFirst();
	  ATermList curList = (ATermList) ((ATermAppl)cur).getArgument(0);
	  ATerm menuNamePrefix = curList.getFirst();

	  if (buttonNamePrefix.isEqual(menuNamePrefix)) {
	    apifyMe = factory.make("menu(<term>)",
					 curList.getNext()); // TODO: apification
	    subMenu = subMenu.insert(apifyMe);
	    buttons = buttons.remove(cur);
	  }
	}

	addMenuItems(nextLevel,
		     buttonType,
		     moduleName,
		     subMenu,
		     prefixButtonName.insertAt(buttonNamePrefix,
					       prefixButtonName.getLength()));
	menu.add(nextLevel);
      }
    }
  }

  public void addMenuItems(JMenu menu,
			   ATerm buttonType,
			   String moduleName,
			   ATermList buttons,
			   ATermList prefixButtonName) {

    buttons = buttons.reverse();

    while (!buttons.isEmpty()) {
      ATerm action = buttons.getFirst();
      ATermList buttonList = (ATermList) ((ATermAppl)action).getArgument(0);
      ATermAppl buttonNamePrefix = (ATermAppl) (buttonList.getFirst());

      buttons = buttons.getNext();

      if (buttonList.getLength() == 1) {
	ATerm apifyMe = factory.make("menu(<term>)",
				     prefixButtonName.concat(buttonList));
	menu.add(new ButtonAction(buttonNamePrefix.getName(),
				  buttonType,
				  apifyMe,
				  moduleTree,
				  bridge,
				  factory));
      } else {
	ATermList buttonRunner = buttons;
	JMenu nextLevel = new JMenu(buttonNamePrefix.getName());
	ATermList subMenu = factory.makeList((ATerm) buttonList.getNext());

	// collect a list of buttons that are in the same 'menuNamePrefix'
	while (!buttonRunner.isEmpty()) {
	  ATerm cur = buttonRunner.getFirst();
	  ATermList curList = (ATermList) ((ATermAppl)cur).getArgument(0);
	  ATerm menuNamePrefix = curList.getFirst();

	  if (buttonNamePrefix.isEqual(menuNamePrefix)) {
	    ATerm apifyMe = factory.make("menu(<term>)", curList.getNext()); // TODO: apification
	    subMenu = subMenu.insert(apifyMe);
	    buttons = buttons.remove(cur);
	  }

	  buttonRunner = buttonRunner.getNext();
	}

	addMenuItems(nextLevel,
		     buttonType,
		     moduleName,
		     subMenu,
		     prefixButtonName.insertAt(buttonNamePrefix,
					       prefixButtonName.getLength()));
	menu.add(nextLevel);
      }
    }
  }

  private File showFileBrowser(String label, String location, String extension, String desc) {
    JFileChooser chooser = new JFileChooser(location);
    String[] exts = { extension };
    ExtensionFilter filter = new ExtensionFilter(exts, desc);
    chooser.setFileFilter(filter);

    int option = chooser.showDialog(this, label);
    if (option == JFileChooser.APPROVE_OPTION) {
      return chooser.getSelectedFile();
    }

    return null;
  }

  public ATerm deconsFilename(String filename, String extension) {
    if (filename.endsWith(extension)) {
      filename = filename.substring(0, filename.length() - extension.length());
    } else {
      extension = "";
    }

    String path = filename;
    int lastIndex = path.lastIndexOf('/');

    if (lastIndex >= 0) {
      path = path.substring(0, lastIndex + 1);
      filename = filename.substring(lastIndex + 1, filename.length());
    }

    return factory.make("snd-value(file-name(<str>,<str>,<str>))", path, filename, extension);
  }

  public ATerm showFileDialog(String label, String loc, String extension) {

    String location;

    if (!loc.equals("")) {
      location = loc;
    } else {
      location = System.getProperty("user.dir");
    }

    File file = showFileBrowser(label, location, extension, "*" + extension);
    if (file != null) {
      return factory.make("snd-value(file-name(<str>))", file.getAbsolutePath());
    } else {
      return factory.make("snd-value(file-name(<str>))", "");
    }
  }

  public ATerm showQuestionDialog(String question) {
    String option;
    int choice = JOptionPane.showConfirmDialog(topFrame, question);

    if (choice == JOptionPane.YES_OPTION) {
      return factory.make("snd-value(answer(yes))");
    }
    if (choice == JOptionPane.NO_OPTION) {
      return factory.make("snd-value(answer(no))");
    }

    return factory.make("snd-value(answer(cancel))");
  }

  void doClearAll() {
    bridge.sendEvent(factory.parse("clear-all"));
    resetGraph();
    importGraphPanel.setGraph(graph);
    moduleManager.clearModules();
  }

  public void clearHistory() {
    try {
      historyDoc.remove(0, historyDoc.getLength());
    } catch (BadLocationException e) {
      System.err.println(e.getMessage());
    }
  }

  void toggleTide() {
    bridge.postEvent(factory.make("debugging(<id>)", tideBox.isSelected() ? "on" : "off"));
  }

  String getCurrentModule() {
    TreePath path = moduleTree.getSelectionPath();

    if (path != null) {
      TreeNode selectedModule = (TreeNode) path.getLastPathComponent();

      return selectedModule.getFullName();
    }

    return null;
  }
}
