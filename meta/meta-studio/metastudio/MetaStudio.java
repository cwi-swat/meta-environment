package metastudio;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import java.util.List;

import javax.swing.*;
import javax.swing.event.*;
import javax.swing.text.*;

import metastudio.graph.*;
import aterm.*;

public class MetaStudio extends JFrame implements UserInterfaceTif, Runnable, ModuleSelectionListener {
  private static final String PREF_TREEPANE_BACKGROUND = "treepane.background";
  private static final String PREF_MSGPANE_BACKGROUND = "messagepane.background";
  private static final String PREF_MSGPANE_STATUS = "messagepane.status";
  private static final String PREF_GRAPHPANE_BACKGROUND = "graphpane.background";
  private static final String PREF_GRAPHPANE_SCALES = "graphpane.scales";
  private static final String PREF_STATUSPANE_BACKGROUND = "statuspane.background";

  private static final String PREF_TOOLBAR_OPEN_MODULE = "toolbar.open-module";
  private static final String PREF_TOOLBAR_OPEN_LIB_MODULE = "toolbar.open-lib-module";
  private static final String PREF_TOOLBAR_NEW_MODULE = "toolbar.new-module";
  private static final String PREF_TOOLBAR_SAVE_ALL = "toolbar.save-all";
  private static final String PREF_TOOLBAR_CLEAR_ALL = "toolbar.clear-all";
  private static final String PREF_TOOLBAR_REFRESH_BUTTONS = "toolbar.refresh-buttons";
  private static final String PREF_TOOLBAR_CLEAR_HISTORY = "toolbar.clear-history";
  private static final String PREF_TOOLBAR_QUIT = "toolbar.quit";

  private static final String PREF_TOOLBAR_TIDE = "toolbar.tide";

  private static final int NODE_BORDER_WIDTH = 5;
  private static final int NODE_BORDER_HEIGHT = 5;

  public static MetaGraphFactory factory;

  private UserInterfaceBridge bridge;

  private JMenuBar menuBar;
  private JMenu fileMenu;
  private JToolBar toolBar;
  private JList moduleList;
  private JPopupMenu modulePopup;
  private JPopupMenu newModulePopup;

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
  private ModuleManager moduleManager;

  private MessageList messageList;  // Message list
  private MessageWindow messageWindow;

  //{{{ public static final void main(String[] args)

  public static final void main(String[] args) throws IOException
  {     
    MetaStudio studio = new MetaStudio(args);
    studio.bridge.run();
  }

  //}}}

  //{{{ public MetaStudio(String[] args)

  public MetaStudio(String[] args) throws IOException {
    Color color;

    topFrame = this;
    
    graphPanels = new HashMap();
    
    factory = new MetaGraphFactory();
    moduleManager = new ModuleManager();
    statusMessages = new LinkedList();

    //{{{ Read preferences

    InputStream propertyStream = getClass().getResourceAsStream("/META-INF/default.properties");
    Properties properties = new Properties();
    properties.load(propertyStream);
    Preferences.initialize("MetaStudio Preferences", properties);
    try {
      File file = new File(System.getProperty("user.home"), ".metarc");
      propertyStream = new FileInputStream(file);
      Preferences.load(propertyStream);
    } catch (IOException e) {
      // No .metarc file
      //warning("No ~/.metarc found");
    }

    //}}}

    //{{{ Create ToolBus bridge

    bridge = new UserInterfaceBridge(factory, this);
    bridge.init(args);
    bridge.connect();
    bridge.setLockObject(getTreeLock());

    //}}}
    //{{{ Handle 'close' requests

    addWindowListener(new WindowAdapter() {
      public void windowClosing(WindowEvent ev) {
        doQuit();
      }
    });

    //}}}
    //{{{ Create actions

    actionNewModule =
      new AbstractAction(
        Preferences.getString(PREF_TOOLBAR_NEW_MODULE + ".text"),
        Preferences.getIcon(PREF_TOOLBAR_NEW_MODULE + ".icon")) {
      public void actionPerformed(ActionEvent event) {
        doNewModule();
      }
    };

    actionOpenModule =
      new AbstractAction(
        Preferences.getString(PREF_TOOLBAR_OPEN_MODULE + ".text"),
        Preferences.getIcon(PREF_TOOLBAR_OPEN_MODULE + ".icon")) {
      public void actionPerformed(ActionEvent event) {
        doOpenModule();
      }
    };

    actionOpenLibModule =
      new AbstractAction(
        Preferences.getString(PREF_TOOLBAR_OPEN_LIB_MODULE + ".text"),
        Preferences.getIcon(PREF_TOOLBAR_OPEN_LIB_MODULE + ".icon")) {
      public void actionPerformed(ActionEvent event) {
        doOpenLibModule();
      }
    };

    actionSaveAll =
      new AbstractAction(
        Preferences.getString(PREF_TOOLBAR_SAVE_ALL + ".text"),
        Preferences.getIcon(PREF_TOOLBAR_SAVE_ALL + ".icon")) {
      public void actionPerformed(ActionEvent event) {
        doSaveAll();
      }
    };

    actionClearAll =
      new AbstractAction(
        Preferences.getString(PREF_TOOLBAR_CLEAR_ALL + ".text"),
        Preferences.getIcon(PREF_TOOLBAR_CLEAR_ALL + ".icon")) {
      public void actionPerformed(ActionEvent event) {
        doClearAll();
      }
    };

    actionRefreshButtons =
      new AbstractAction(
        Preferences.getString(PREF_TOOLBAR_REFRESH_BUTTONS + ".text")) {
      public void actionPerformed(ActionEvent event) {
        doRefreshButtons();
      }
    };

    actionClearHistory =
      new AbstractAction(
        Preferences.getString(PREF_TOOLBAR_CLEAR_HISTORY + ".text")) {
      public void actionPerformed(ActionEvent event) {
        doClearHistory();
      }
    };

    actionQuit =
      new AbstractAction(
        Preferences.getString(PREF_TOOLBAR_QUIT + ".text"),
        Preferences.getIcon(PREF_TOOLBAR_QUIT + ".icon")) {
      public void actionPerformed(ActionEvent event) {
        doQuit();
      }
    };

    //}}}
    //{{{ Create module menu

    modulePopup = new JPopupMenu("Module Menu");

    modulePopup.addPopupMenuListener(new PopupMenuListener() {
      public void popupMenuCanceled(PopupMenuEvent event) {
      }

      public void popupMenuWillBecomeVisible(PopupMenuEvent event) {
        importGraphPanel.setDragEnabled(false);
      }

      public void popupMenuWillBecomeInvisible(PopupMenuEvent event) {
        importGraphPanel.setDragEnabled(true);
      }
    });

    modulePopup.add(new AbstractAction(Preferences.getString("text.edit-syntax")) {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("edit-module(<str>)", (String) values[i]));
        }
      }
    });

    modulePopup.add(new AbstractAction(Preferences.getString("text.edit-equations")) {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("edit-eqs-module(<str>)", (String) values[i]));
        }
      }
    });

    modulePopup.add(new AbstractAction(Preferences.getString("text.edit-term") + "...") {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          doEditTerm((String) values[i]);
        }
      }
    });

    modulePopup.addSeparator();

    modulePopup.add(new AbstractAction(Preferences.getString("text.save-module")) {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("save-module(<str>)", (String) values[i]));
        }
      }
    });

    modulePopup.add(new AbstractAction(Preferences.getString("text.revert-module")) {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("revert-module(<str>)", (String) values[i]));
        }
      }
    });

    modulePopup.add(new AbstractAction(Preferences.getString("text.close-module") + "...") {
      public void actionPerformed(ActionEvent event) {
        String option;
        int choice = JOptionPane.showConfirmDialog(topFrame, "Do you want to recursively close the imported modules?");

	if (choice != JOptionPane.CANCEL_OPTION) {
	  option = (choice == JOptionPane.YES_OPTION ? "recursive" : "top");
	  Object[] values = moduleList.getSelectedValues();
	  for (int i = 0; i < values.length; i++) {
	    bridge.postEvent(factory.make("close-module(<str>," + option + ")", (String) values[i]));
	  }
	}
      }
    });

    JMenu refactorMenu = new JMenu(Preferences.getString("text.refactor"));

    refactorMenu.add(new AbstractAction(Preferences.getString("text.copy-module") + "...") {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          doCopyModule((String) values[i]);
        }
      }
    });

    refactorMenu.add(new AbstractAction(Preferences.getString("text.delete-module") + "...") {
      public void actionPerformed(ActionEvent event) {
        int choice = JOptionPane.showConfirmDialog(topFrame, "Are you sure you want delete this module (from disk)?");

        if (choice == JOptionPane.YES_OPTION) {
          Object[] values = moduleList.getSelectedValues();
          for (int i = 0; i < values.length; i++) {
            bridge.postEvent(factory.make("delete-module(<str>)", (String) values[i]));
          }
        }
      }
    });

    refactorMenu.add(new AbstractAction(Preferences.getString("text.rename") + "...") {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          doRenameModule((String) values[i]);
        }
      }
    });

    refactorMenu.add(new AbstractAction(Preferences.getString("text.add-import") + "...") {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          doAddImport((String) values[i]);
        }
      }
    });

    refactorMenu.add(new AbstractAction(Preferences.getString("text.remove-import") + "...") {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          doRemoveImport((String) values[i]);
        }
      }
    });
    modulePopup.add(refactorMenu);

    modulePopup.addSeparator();

    modulePopup.add(new AbstractAction(Preferences.getString("text.compile-module")) {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("compile-module(<str>)", (String) values[i]));
        }
      }
    });

    modulePopup.add(new AbstractAction(Preferences.getString("text.dump-equations")) {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("dump-equations(<str>)", (String) values[i]));
        }
      }
    });

    modulePopup.add(new AbstractAction(Preferences.getString("text.dump-parsetable")) {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("dump-parse-table(<str>)", (String) values[i]));
        }
      }
    });

    modulePopup.addSeparator();

    modulePopup.add(new AbstractAction(Preferences.getString("text.print-module")) {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("print-module(<str>)", (String) values[i]));
        }
      }
    });

    //}}}

    //{{{ Create new module popup

    newModulePopup = new JPopupMenu("New Module Menu");

    newModulePopup.addPopupMenuListener(new PopupMenuListener() {
      public void popupMenuCanceled(PopupMenuEvent event) {
      }

      public void popupMenuWillBecomeVisible(PopupMenuEvent event) {
        importGraphPanel.setDragEnabled(false);
      }

      public void popupMenuWillBecomeInvisible(PopupMenuEvent event) {
        importGraphPanel.setDragEnabled(true);
      }
    });

    newModulePopup.add(new AbstractAction("Create this module") {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("new-module(<str>,<str>)", (String) values[i], (String) values[i]));
        }
      }
    });
    newModulePopup.add(new AbstractAction("Delete this module") {
      public void actionPerformed(ActionEvent event) {
        Object[] values = moduleList.getSelectedValues();
        for (int i = 0; i < values.length; i++) {
          bridge.postEvent(factory.make("delete-module(<str>)", (String) values[i]));
        }
      }
    });

    //}}}

    //{{{ Create menubar

    menuBar = new JMenuBar();

    fileMenu = new JMenu("File");
    fileMenu.add(actionOpenModule).setIcon(null);
    fileMenu.add(actionOpenLibModule).setIcon(null);
    fileMenu.add(actionNewModule).setIcon(null);
    fileMenu.addSeparator();
    fileMenu.add(actionSaveAll).setIcon(null);
    fileMenu.add(actionClearAll).setIcon(null);
    fileMenu.addSeparator();
    fileMenu.add(actionRefreshButtons).setIcon(null);
    fileMenu.add(actionClearHistory).setIcon(null);
    fileMenu.addSeparator();
    fileMenu.add(actionQuit).setIcon(null);

    menuBar.add(fileMenu);
    setJMenuBar(menuBar);

    //}}}
    //{{{ Create toolbar

    toolBar = new JToolBar();
    //MyToolbar.setClientProperty("JToolBar.isRollover", Boolean.TRUE);

    addTool(actionNewModule, PREF_TOOLBAR_NEW_MODULE);
    addTool(actionOpenModule, PREF_TOOLBAR_OPEN_MODULE);
    addTool(actionOpenLibModule, PREF_TOOLBAR_OPEN_LIB_MODULE);
    addTool(actionSaveAll, PREF_TOOLBAR_SAVE_ALL);
    toolBar.addSeparator();
    addTool(actionClearAll, PREF_TOOLBAR_CLEAR_ALL);
    //addTool(actionRefreshButtons, PREF_TOOLBAR_REFRESH_BUTTONS);
    toolBar.addSeparator();
    addTool(actionQuit, PREF_TOOLBAR_QUIT);

    toolBar.add(Box.createHorizontalGlue());

    tideBox = new JCheckBox(Preferences.getIcon(PREF_TOOLBAR_TIDE + ".off.icon"));
    tideBox.setSelectedIcon(Preferences.getIcon(PREF_TOOLBAR_TIDE + ".on.icon"));
    toolBar.add(tideBox);
    tideBox.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        toggleTide();
      }
    });

    /*
    if ("true".equals(System.getProperty("tide.enabled"))) {
      tideBox.setToolTipText("Toggle tide debugger when rewriting");
    } else {
      tideBox.setEnabled(false);
      tideBox.setToolTipText("Tide support disabled (configure with --with-tide=...)");
    }
    */

    String scaleList = Preferences.getString(PREF_GRAPHPANE_SCALES);
    Vector scales = new Vector();
    StringTokenizer t = new StringTokenizer(scaleList, ",");
    while (t.hasMoreTokens()) {
      String scale = t.nextToken();
      scales.add(scale);
    }

    scaleBox = new JComboBox(scales) {
      public Dimension getMaximumSize() {
        return getPreferredSize();
      }
    };
    scaleBox.setSelectedItem(Preferences.getString(PREF_GRAPHPANE_SCALES + ".default"));

    //scaleBox.setEditable(true);
    ActionListener listener = new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        String value = scaleBox.getSelectedItem().toString();
        // Strip off '%' sign
        if (value.charAt(value.length() - 1) == '%') {
          value = value.substring(0, value.length() - 1);
        }
        int percentage = Integer.parseInt(value);
        importGraphPanel.setScale(percentage);
      }
    };

    scaleBox.addActionListener(listener);

    toolBar.add(scaleBox);

    //}}}
    //{{{ Create module list

    moduleList = new JList();
    moduleList.setModel(moduleManager.getListModel());
    ListSelectionListener moduleListListener = new ListSelectionListener() {
      public void valueChanged(ListSelectionEvent event) {
        /*
        int index = event.getLastIndex();
        String selectedModule
          = (String)moduleList.getModel().getElementAt(index);
          */
        String selectedModule = (String) moduleList.getSelectedValue();
        moduleManager.selectModule(moduleManager.getModule(selectedModule));
      }
    };
    moduleList.addListSelectionListener(moduleListListener);

    moduleList.addMouseListener(new MouseAdapter() {
      public void mousePressed(MouseEvent e) {
        checkModulePopup(e);
      }
      public void mouseReleased(MouseEvent e) {
        checkModulePopup(e);
      }
    });

    JScrollPane listPane = new JScrollPane(moduleList);

    color = Preferences.getColor(PREF_TREEPANE_BACKGROUND);
    moduleList.setBackground(color);

    //}}}
    
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
    
    parseTreePanel = new ParseTreePanel();
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
    //statusBar.setBackground(color);
    statusLog.setBackground(color);
    statusBarPanel.setBackground(color);
    color = Preferences.getColor(PREF_MSGPANE_STATUS + ".foreground");
    //statusBar.setForeground(color);
    statusLog.setForeground(color);
    statusBarPanel.setForeground(color);
    Font font = Preferences.getFont(PREF_MSGPANE_STATUS + ".font");
    statusBar.setFont(font);
    statusLog.setFont(font);
    //statusBarPanel.setFont(font);

    statusBarPanel.add(statusBar, BorderLayout.CENTER);
    statusBarPanel.add(statusLog, BorderLayout.EAST);
    historyPanel.add(historyPane, BorderLayout.CENTER);
    historyPanel.add(statusBarPanel, BorderLayout.SOUTH);

    //historyPane.setMinimumSize(new Dimension(50, 100));

    Container content = getContentPane();

    treePanel.setLayout(new BorderLayout());
    treePanel.add(listPane, BorderLayout.CENTER);

    JSplitPane leftPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT, treePanel, moduleStatus);
    leftPanel.setResizeWeight(0.8);

    JSplitPane rightPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT, graphPane, historyPanel);
    rightPanel.setResizeWeight(0.8);

    JSplitPane mainPanel = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftPanel, rightPanel);

    content.setLayout(new BorderLayout());
    content.add(toolBar, BorderLayout.NORTH);
    content.add(mainPanel, BorderLayout.CENTER);

    //content.add(msgLabel, BorderLayout.SOUTH);

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

  //}}}
  
  //{{{ private void addGraphPanel(GraphPanel panel, String toolTip)

  private void addGraphPanel(GraphPanel panel, String toolTip)
  {
    int index = graphPanels.size();
    panel.setIndex(index);
    graphPanels.put(panel.getId(), panel);
    graphPane.insertTab(panel.getId(), null, new JScrollPane(panel), toolTip, index);
  }

  //}}}

  //{{{ private GraphPanel getGraphPanel(String id)

  private GraphPanel getGraphPanel(String id)
  {
    return (GraphPanel)graphPanels.get(id);
  }

  //}}}
  
  //{{{ private void initStyles()

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

  //}}}

  //{{{ private void addTool(Action action, String prefKey)

  private void addTool(Action action, String prefKey) {
    JButton button = toolBar.add(action);
    String tip = Preferences.getString(prefKey + ".text");
    button.setToolTipText(tip);
  }

  //}}}

  //{{{ private void resetGraph()

  private void resetGraph() {
    graph.reset();
  }

  //}}}
  //{{{ public void run()

  public void run() {
    layoutGraph(importGraphPanel, graph);
  }

  //}}}

  //{{{ public void finishedOpeningModules(ATerm module)

  public void finishedOpeningModules(ATerm module) {
    /* do nothing (this is for backward compatibility) */
  }

  //}}}
  //{{{ public void moduleInfo(String module, ATerm info)

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

  //}}}

  //{{{ void addMessage(Style style, String id, String message)

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
        System.out.println("bad location: " + e.getMessage());
      }
    }
  }

  //}}}
  //{{{ void clearStatus(String id)

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

  //}}}
  //{{{ String formatString(String format, ATermList args)

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

  //}}}

  //{{{ public void addStatus(ATerm id, String message)

  public void addStatus(ATerm id, String message) {
    String ids = id.toString();
    if (statusLog.isSelected()) {
      addMessage(styleMessage, ids, message);
    }
    statusBar.setText(message);
    String[] pair = { ids, message };
    statusMessages.add(pair);
  }

  //}}}
  //{{{ public void addStatusf(ATerm id, String format, ATerm args)

  public void addStatusf(ATerm id, String format, ATerm args) {
    String message = formatString(format, (ATermList) args);
    addStatus(id, message);
  }

  //}}}
  //{{{ public void endStatus(ATerm id)

  public void endStatus(ATerm id) {
    clearStatus(id.toString());
  }

  //}}}

  //{{{ public void errorf(String format, ATerm args)

  public void errorf(String format, ATerm args) {
    String message = formatString(format, (ATermList) args);
    addMessage(styleError, null, message);
  }

  //}}}
  //{{{ public void error(String message)

  public void error(String message) {
    addMessage(styleError, null, message);
  }

  //}}}
  //{{{ public void warning(String message)

  public void warning(String message) {
    addMessage(styleWarning, null, message);
  }

  //}}}

  //{{{ public void initialize_ui(String libloc, String syn_ext, String sem_ext,

  public void initializeUi(String name, String libloc, String syn_ext, String sem_ext, String trm_ext) {
    setTitle(name);
    Preferences.setString("metastudio.name", name);
    Preferences.setString("library.dir", libloc);
    Preferences.setString("module.extension", syn_ext);
    Preferences.setString("term.extension", trm_ext);
  }

  //}}}

  //{{{ private Module addModule(String name)

  private Module addModule(String name) {
    Module module = moduleManager.getModule(name);
    if (module == null) {
      module = new Module(name);
      moduleManager.addModule(module);
    }

    //moduleManager.selectModule(module);
    return module;
  }

  //}}}
  //{{{ private void setModules(ATermList moduleList)

  private void setModules(ATermList moduleList) {
    moduleManager.clearModules();

    while (!moduleList.isEmpty()) {
      ATermAppl moduleTerm = (ATermAppl) moduleList.getFirst();
      moduleList = moduleList.getNext();
      String name = moduleTerm.getName();
      addModule(name);
    }
  }

  //}}}
  //{{{ private void setImports(ATermList importList)

  private void setImports(ATermList importList) {
    while (!importList.isEmpty()) {
      ATermList edge = (ATermList) importList.getFirst();
      importList = importList.getNext();

      ATermAppl fromTerm = (ATermAppl) edge.getFirst();
      String from = fromTerm.getName();
      Module moduleFrom = moduleManager.getModule(from);
      if (moduleFrom == null) {
        moduleFrom = addModule(from);
        moduleFrom.setState(Module.STATE_NEW);
      }

      ATermAppl toTerm = (ATermAppl) edge.elementAt(1);
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

  //}}}
  //{{{ public void deleteModules(ATermList modules)

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

  //}}}
  //{{{ public void newGraph(ATerm moduleList, ATerm importRelations)

  public void newGraph(ATerm moduleList, ATerm importRelations) {
    setModules((ATermList) moduleList);
    setImports((ATermList) importRelations);

    graph = GraphWrapper.fromImportList(factory, (ATermList) moduleList, (ATermList) importRelations);
    layoutGraph(importGraphPanel, graph);
  }

  //}}}
  //{{{ public void layoutGraph()

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

  //}}}

  //{{{ public void displayGraph(String id, ATerm graphTerm)

  public void displayGraph(String id, ATerm graphTerm)
  {
    GraphWrapper graph = GraphWrapper.fromTerm(graphTerm);
    GraphPanel panel = getGraphPanel(id);
    layoutGraph(panel, graph);
  }

  //}}}
  //{{{ public void graphLayouted(String id, ATerm graphTerm)

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

  //}}}

  //{{{ public void moduleSelected(Module module)

  public void moduleSelected(Module module) {
    if (module == null) {
      moduleList.clearSelection();
    } else {
      moduleList.setSelectedValue(module.getName(), true);

      if (module.getState() == Module.STATE_NORMAL) {
        bridge.postEvent(factory.make("get-module-info(<str>)", module.getName()));
      }
    }

    //System.out.println("MetaStudio: moduleSelected " + module.getName());
  }

  //}}}
  //{{{ public void updateList(ATerm data) 

  public void updateList(ATerm data) {

      messageWindow.setVisible(true);

      if (data instanceof ATermList) {
	  messageList.setContent((ATermList)data);
      }
      else {
	  System.out.println(data.toString());	    
	  messageList.errMessage("Can't show something in list view which is not a ATermList");
      }
  }

  //}}}
  //{{{ public void recAckEvent(ATerm event)

  public void recAckEvent(ATerm event) {
  }

  //}}}
  //{{{ public void recTerminate(ATerm t0)

  public void recTerminate(ATerm t0) {
    System.exit(0);
  }

  //}}}

  //{{{ void checkModulePopup(MouseEvent e)

  void checkModulePopup(MouseEvent e) {
    boolean showPopup = false;

    showPopup |= e.isPopupTrigger();

    if (showPopup) {
      Module module;
      JComponent component;
      int x = e.getX();
      int y = e.getY();

      if (e.getSource() == moduleList) {
        component = moduleList;
        currentModule = (String) moduleList.getSelectedValue();
      } else if (e.getSource() == importGraphPanel) {
        component = importGraphPanel;
        Node node = importGraphPanel.getNodeAt(x, y);

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
            modulePopup.show(component, x, y);
            break;
          case Module.STATE_NEW :
            newModulePopup.show(component, x, y);
            break;
        }
      }
    }
  }

  //}}}

  //{{{ private File showFileBrowser(String label, String location, String extension, String desc)

  private File showFileBrowser(String label, String location, String extension, String desc)
  {
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

  //}}}
  //{{{ private File showModuleBrowser(String label, String location)

  private File showModuleBrowser(String label, String location)
  {
    String extension = Preferences.getString("module.extension");
    String description = Preferences.getString("module.extension.description");
    return showFileBrowser(label, location, extension, description);
  }

  //}}}
  //{{{ private File showTermBrowser()

  private File showTermBrowser(String label, String location)
  {
    String extension = Preferences.getString("term.extension");
    String description = Preferences.getString("term.extension.description");
    return showFileBrowser(label, location, extension, description);
  }

  //}}}

  //{{{ String getFileModule(File file)

  String getFileModule(File file, String extension) {
    String module = file.getName();
    if (module.endsWith(extension)) {
      module = module.substring(0, module.length() - extension.length());
    }

    return module;
  }

  //}}}
  //{{{ String getFilePath(File file, String extension)

  String getFilePath(File file, String extension) {
    String path = file.getPath();

    if (path.endsWith(extension)) {
      path = path.substring(0, path.length() - extension.length());
    }

    return path;
  }

  //}}}

  //{{{ void doNewModule()

  void doNewModule() {
    String label = Preferences.getString("text.new-module");
    String location = System.getProperty("user.dir");

    File file = showModuleBrowser(label, location);
    if (file != null) {
      String extension = Preferences.getString("module.extension");
      String module = getFileModule(file, extension);
      String path = getFilePath(file, extension);

      ATerm event = factory.make("new-module(<str>,<str>)", path, module);
      bridge.postEvent(event);
    }
  }

  //}}}
  //{{{ void doOpenModule()

  void doOpenModule() {
    String label = Preferences.getString("text.open-module");
    String location = System.getProperty("user.dir");

    File file = showModuleBrowser(label, location);
    if (file != null) {
      String extension = Preferences.getString("module.extension");
      String module = getFileModule(file, extension);
      String path = getFilePath(file, extension);

      ATerm event = factory.make("open-module(<str>,<str>)", path, module);
      bridge.postEvent(event);
    }
  }

  //}}}
  //{{{ void doOpenLibModule()

  void doOpenLibModule() {
    String label = Preferences.getString("text.open-lib-module");
    String location = Preferences.getString("library.dir");

    File file = showModuleBrowser(label, location);
    if (file != null) {
      String extension = Preferences.getString("module.extension");
      String module = getFileModule(file, extension);
      String path = getFilePath(file, extension);

      ATerm event = factory.make("open-module(<str>,<str>)", path, module);
      bridge.postEvent(event);
    }
  }

  //}}}
  //{{{ void doRenameModule(String oldModule)

  void doRenameModule(String oldModule) {
    String label = Preferences.getString("text.rename");
    String location = System.getProperty("user.dir");

    File file = showModuleBrowser(label, location);
    if (file != null) {
      String extension = Preferences.getString("module.extension");
      String module = getFileModule(file, extension);
      String path = getFilePath(file, extension);

      ATerm event = factory.make("rename-module(<str>,<str>,<str>)", oldModule, module, path);
      bridge.postEvent(event);
    }
  }

  //}}}
  //{{{ void doCopyModule(String oldModule)

  void doCopyModule(String oldModule) {
    String label = Preferences.getString("text.copy-module");
    String location = System.getProperty("user.dir");

    File file = showModuleBrowser(label, location);
    if (file != null) {
      String extension = Preferences.getString("module.extension");
      String module = getFileModule(file, extension);
      String path = getFilePath(file, extension);

      ATerm event = factory.make("copy-module(<str>,<str>,<str>)", oldModule, module, path);
      bridge.postEvent(event);
    }
  }

  //}}}

  //{{{ void doAddImport(String oldModule)

  void doAddImport(String oldModule)
  {
    String label = Preferences.getString("text.add-import");
    String location = System.getProperty("user.dir");

    File file = showModuleBrowser(label, location);
    if (file != null) {
      String extension = Preferences.getString("module.extension");
      String module = getFileModule(file, extension);
      String path = getFilePath(file, extension);

      ATerm event = factory.make("import-module(<str>,<str>,<str>)", oldModule, module, path);
      bridge.postEvent(event);
    }
  }

  //}}}
  //{{{ void doRemoveImport(String oldModule)

  void doRemoveImport(String oldModule)
  {
    String label = Preferences.getString("text.remove-import");
    String location = System.getProperty("user.dir");

    /*
    System.out.println("oldModule: " + oldModule);
    Module cur = moduleManager.getModule(oldModule);
    JComboBox imports = new JComboBox(cur.fetchChildrenArray());
    JFrame frame = new JFrame("Remove Import");
    frame.getContentPane().add(imports);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.pack();
    frame.setVisible(true);
    */

    File file = showModuleBrowser(label, location);
    if (file != null) {
      String extension = Preferences.getString("module.extension");
      String module = getFileModule(file, extension);
      String path = getFilePath(file, extension);

      ATerm event = factory.make("unimport-module(<str>,<str>,<str>)", oldModule, module, path);
      bridge.postEvent(event);
    }
  }

  //}}}

  //{{{ void doEditTerm(String module)

  void doEditTerm(String module) {
    String label = Preferences.getString("text.edit-term");
    String location = System.getProperty("user.dir");

    File file = showTermBrowser(label, location);
    if (file != null) {
      bridge.postEvent(factory.make("edit-term(<str>,<str>)", module, file.getAbsolutePath()));
    }
  }

  //}}}
  //{{{ void doSaveAll()

  void doSaveAll() {
    bridge.sendEvent(factory.parse("save-all"));
  }

  //}}}
  //{{{ void doClearAll()

  void doClearAll() {
    bridge.sendEvent(factory.parse("clear-all"));
    resetGraph();
    importGraphPanel.setGraph(graph);
    moduleManager.clearModules();
  }

  //}}}
  //{{{ void doRefreshButtons()

  void doRefreshButtons() {
    bridge.sendEvent(factory.parse("refresh-buttons"));
  }

  //}}}
  //{{{ void doClearHistory()

  void doClearHistory() {
    try {
      historyDoc.remove(0, historyDoc.getLength());
    } catch (BadLocationException e) {
      System.err.println(e.getMessage());
    }
  }

  //}}}
  //{{{ void doQuit()

  void doQuit() {
    bridge.sendEvent(factory.parse("quit"));
  }

  //}}}

  //{{{ void toggleTide()

  void toggleTide() {
    bridge.postEvent(factory.make("debugging(<id>)", tideBox.isSelected() ? "on" : "off"));
  }

  //}}}
}
