package metastudio;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Frame;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.UnknownHostException;
import java.util.Calendar;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Map;
import java.util.Properties;
import java.util.StringTokenizer;
import java.util.Vector;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.Box;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTabbedPane;
import javax.swing.JTextPane;
import javax.swing.JToolBar;
import javax.swing.JTree;
import javax.swing.JViewport;
import javax.swing.KeyStroke;
import javax.swing.event.PopupMenuEvent;
import javax.swing.event.PopupMenuListener;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultStyledDocument;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyleContext;
import javax.swing.tree.TreePath;

import metastudio.graph.AttributeList;
import metastudio.graph.EdgeList;
import metastudio.graph.Graph;
import metastudio.graph.MetaGraphFactory;
import metastudio.graph.Node;
import metastudio.graph.NodeList;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Summary;

public class MetaStudio
    extends JFrame
    implements UserInterfaceTif, Runnable, ModuleSelectionListener {
    // TODO: move preference constants to Preferences class
    private static final double RIGHTPANEL_DIVIDER_LOCATION = 0.8;
    private static final double LEFTPANEL_DIVIDER_LOCATION = 0.65;
    private static final double MAINPANEL_DIVIDER_LOCATION = 0.3;

    private static ATerm ACTION_MENUBAR;
    private static ATerm ACTION_TOOLBAR;
    private static ATerm ACTION_MODULE_POPUP;
    private static ATerm ACTION_NEW_MODULE_POPUP;

    public static PureFactory factory;
    public static MetaGraphFactory metaGraphFactory;

    private UserInterfaceBridge bridge;

    private JMenuBar menuBar;
    private JToolBar toolBar;
    private Map menuMap;
    private JTree moduleTree;
    //	private JPopupMenu popupMenu;
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

    private JTabbedPane graphTabs;

    private Graph graph;
    private ImportGraphPanel importGraphPanel;
    private ParseTreePanel parseTreePanel;
    private FeedbackList feedbackList;

    private Map graphPanels;

    private ModuleStatusPanel moduleStatus;

    private JCheckBox tideBox;

    private Frame topFrame;

    private String currentModule;
    private ModuleTreeModel moduleManager;

    private MessageList messageWindow;

    public static final void main(String[] args) throws IOException {
        MetaStudio studio = new MetaStudio(args);
        studio.bridge.run();
    }

    private JMenuBar createMenuBar() {
        JMenuBar menuBar = new JMenuBar();
        bridge.postEvent(factory.make("get-buttons(<term>,<str>)", ACTION_MENUBAR, "*"));

        return menuBar;
    }

    private JPopupMenu createPopupMenu() {
        JPopupMenu popup = new JPopupMenu();

        popup.addPopupMenuListener(new PopupMenuListener() {
            public void popupMenuCanceled(PopupMenuEvent event) {
            }
            public void popupMenuWillBecomeVisible(PopupMenuEvent event) {
                importGraphPanel.setDragEnabled(false);
            }
            public void popupMenuWillBecomeInvisible(PopupMenuEvent event) {
                importGraphPanel.setDragEnabled(true);
            }
        });

        return popup;
    }

    private JToolBar createToolBar() {
        JToolBar bar = new JToolBar();

        bridge.postEvent(factory.make("get-buttons(<term>,<str>)", ACTION_TOOLBAR, "*"));

        return bar;
    }

    public MetaStudio(String[] args) throws IOException {
        topFrame = this;
        graphPanels = new HashMap();

        factory = new PureFactory();
        metaGraphFactory = new MetaGraphFactory(factory);
        moduleManager = new ModuleTreeModel();
        statusMessages = new LinkedList();

        initializeProperties();
        initializeATermPatterns(); // TODO: apification

        createToolBusBridge(args);
        handleCloseRequests();

        moduleManager.addModuleSelectionListener(this);
        //		popupMenu = createPopupMenu();
        createContentPane();
//        messageWindow = createMessageWindow();

        makeStudioVisible();
    }

    private void initializeATermPatterns() {
        ACTION_MENUBAR = factory.parse("studio-menubar");
        ACTION_TOOLBAR = factory.parse("studio-toolbar");
        ACTION_MODULE_POPUP = factory.parse("module-popup");
        ACTION_NEW_MODULE_POPUP = factory.parse("new-module-popup");
    }

    private void initializeProperties() throws IOException {
        InputStream propertyStream =
            getClass().getResourceAsStream("/META-INF/default.properties");
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
    }

    private void makeStudioVisible() {
        Dimension screenSize = getToolkit().getScreenSize();
        int width = 800;
        int height = 600;
        int x = (screenSize.width - width) / 2;
        int y = (screenSize.height - height) / 2;

        setTitle("Meta-Environment");
        setSize(width, height);
        setLocation(x, y);

        setVisible(true);
    }

    private MessageList createMessageWindow() throws IOException {
        return new MessageList(factory, bridge);
    }

    private void createParsetreePanel() {
        parseTreePanel = new ParseTreePanel(bridge, metaGraphFactory);
    }

    private JSplitPane createMainPanel() {
        JSplitPane leftPanel = createLeftPane();
        JSplitPane rightPanel = createRightPane();
        JSplitPane mainPanel =
            new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftPanel, rightPanel);
        mainPanel.setDividerLocation(MAINPANEL_DIVIDER_LOCATION);

        return mainPanel;
    }

    private JPanel createMessageStatusPanel()
    {
        JPanel container = new JPanel();
        container.setLayout(new BorderLayout());
        container.add(createMessageTabs(), BorderLayout.CENTER);
        container.add(createStatusBarPanel(), BorderLayout.SOUTH);
        
        return container;
    }
    
    private JSplitPane createRightPane() {
        graphTabs = createGraphTabs();
        
        JSplitPane rightPanel =
            new JSplitPane(JSplitPane.VERTICAL_SPLIT, graphTabs, createMessageStatusPanel());
        rightPanel.setResizeWeight(RIGHTPANEL_DIVIDER_LOCATION);
        rightPanel.setDividerLocation(RIGHTPANEL_DIVIDER_LOCATION);
        return rightPanel;
    }

    private JSplitPane createLeftPane() {
        JScrollPane moduleTreePane = createModuleTreePane();
        JPanel treePanel = new JPanel();
        treePanel.setLayout(new BorderLayout());
        treePanel.add(moduleTreePane, BorderLayout.CENTER);

        createModuleStatusPanel();

        JSplitPane leftPanel =
            new JSplitPane(JSplitPane.VERTICAL_SPLIT, treePanel, moduleStatus);
        leftPanel.setResizeWeight(RIGHTPANEL_DIVIDER_LOCATION);
        leftPanel.setDividerLocation(LEFTPANEL_DIVIDER_LOCATION);
        return leftPanel;
    }

    private JTabbedPane createGraphTabs() {
        JTabbedPane tabs = new JTabbedPane();

        graphTabs = tabs;
        
        createModuleGraph();
        addGraphPanel(importGraphPanel, "Import graph");

        createParsetreePanel();
        addGraphPanel(parseTreePanel, "Parsetree graph");
        
        return tabs;
    }

    private void createContentPane() {
        menuBar = createMenuBar();
        setJMenuBar(menuBar);

        Container content = getContentPane();
        content.setLayout(new BorderLayout());

        toolBar = createToolBar();
        content.add(toolBar, BorderLayout.NORTH);

        JSplitPane mainPanel = createMainPanel();
        content.add(mainPanel, BorderLayout.CENTER);
    }

    private JTabbedPane createMessageTabs() {
        JTabbedPane messageTabs = new JTabbedPane();
        MessageList messageList;
        feedbackList = new FeedbackList(factory, bridge);
        
        try {
            messageList = createMessageWindow();
            messageTabs.insertTab("history",null,createHistoryPanel(),"Execution history and error messages",0);
            messageTabs.insertTab("messages",null,messageList,"Message list",1);
            messageTabs.insertTab("errors",null,feedbackList,"Clickable error messages",2);
        } catch (IOException e) {
            e.printStackTrace();
            postQuitEvent();
        }
        
        return messageTabs;
    }
    
    private void postQuitEvent() {
        bridge.sendEvent(factory.parse("quit"));
    }

    private JPanel createHistoryPanel() {
        createHistoryDocument();
        JPanel historyPanel = new JPanel();
        historyPanel.setLayout(new BorderLayout());
        historyPane = new JScrollPane(history);
        historyPanel.add(historyPane);
        return historyPanel;
    }

    private JPanel createStatusBarPanel() {
        Color bgColor =
            Preferences.getColor(Preferences.PREF_MSGPANE_STATUS + ".background");
        Color fgColor =
            Preferences.getColor(Preferences.PREF_MSGPANE_STATUS + ".foreground");
        Font font = Preferences.getFont(Preferences.PREF_MSGPANE_STATUS + ".font");

        JPanel statusBarPanel = new JPanel();
        statusBarPanel.setBackground(bgColor);
        statusBarPanel.setForeground(fgColor);
        statusBarPanel.setLayout(new BorderLayout());

        statusLog = new JCheckBox("Log Status");
        statusLog.setSelected(
            Preferences.getBoolean(Preferences.PREF_MSGPANE_STATUS + ".log"));
        statusLog.setBackground(bgColor);
        statusLog.setForeground(fgColor);
        statusLog.setFont(font);
        statusBarPanel.add(statusLog, BorderLayout.EAST);

        statusBar = new JLabel("idle");
        statusBar.setFont(font);
        statusBarPanel.add(statusBar, BorderLayout.CENTER);

        return statusBarPanel;
    }

    private void createModuleStatusPanel() {
        Color color;
        moduleStatus = new ModuleStatusPanel(moduleManager);
        color = Preferences.getColor(Preferences.PREF_STATUSPANE_BACKGROUND);
        moduleStatus.setBackground(color);
    }

    private void createHistoryDocument() {
        Color color;

        historyStyles = new StyleContext();
        styleMessage = initStyle("messagepane.message");
        styleWarning = initStyle("messagepane.warning");
        styleError = initStyle("messagepane.error");

        historyDoc = new DefaultStyledDocument(historyStyles);
        history = new JTextPane(historyDoc);
        history.setEditable(false);

        color = Preferences.getColor(Preferences.PREF_MSGPANE_BACKGROUND);
        history.setBackground(color);
    }

    private void createModuleGraph() {
        Color color;

        NodeList nodes = metaGraphFactory.makeNodeList_Empty();
        EdgeList edges = metaGraphFactory.makeEdgeList_Empty();
        AttributeList attrs = metaGraphFactory.makeAttributeList_Empty();

        graph = metaGraphFactory.makeGraph_Default(nodes, edges, attrs);

        importGraphPanel = new ImportGraphPanel(moduleManager);

        importGraphPanel.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                checkModulePopup(e);
            }
            public void mouseReleased(MouseEvent e) {
                checkModulePopup(e);
            }
        });

        color = Preferences.getColor(Preferences.PREF_GRAPHPANE_BACKGROUND);
        importGraphPanel.setBackground(color);
    }

    private JScrollPane createModuleTreePane() {
        Color color;
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

        Action a = new AbstractAction("popupmenu mnemonic") {
            public void actionPerformed(ActionEvent e) {
                if (moduleTree.getSelectionPath() != null) {
                    TreePath p = moduleTree.getSelectionPath();
                    Rectangle r = moduleTree.getPathBounds(p);
                    MouseEvent me =
                        new MouseEvent(
                            moduleTree,
                            0,
                            Calendar.getInstance().getTimeInMillis(),
                            0,
                            r.x + r.width / 2,
                            r.y + r.height,
                            1,
                            true,
                            MouseEvent.BUTTON3);
                    checkModulePopup(me);
                }
            }
        };
        String key = new String("popupmenu mnemonic");
        KeyStroke ks = KeyStroke.getKeyStroke(KeyEvent.VK_F1, 0);
        moduleTree.getInputMap(JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT).put(
            ks,
            key);
        moduleTree.getActionMap().put(key, a);

        JScrollPane listPane = new JScrollPane(moduleTree);

        color = Preferences.getColor(Preferences.PREF_TREEPANE_BACKGROUND);
        moduleTree.setBackground(color);
        return listPane;
    }

    private void handleCloseRequests() {

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                postQuitEvent();
            }
        });
    }

    private void createToolBusBridge(String[] args)
        throws UnknownHostException, IOException {

        bridge = new UserInterfaceBridge(factory, this);
        bridge.init(args);
        bridge.connect();
        bridge.setLockObject(getTreeLock());
    }

    //{{{ private Vector parseScales()

    private Vector parseScales() {
        String scaleList = Preferences.getString(Preferences.PREF_GRAPHPANE_SCALES);
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

    private JComboBox createScaleBox() {
        final JComboBox scaleBox = new JComboBox(parseScales()) {
            public Dimension getMaximumSize() {
                return getPreferredSize();
            }
        };

        scaleBox.setSelectedItem(
            Preferences.getString(Preferences.PREF_GRAPHPANE_SCALES + ".default"));

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
        graphTabs.insertTab(panel.getId(), null, new JScrollPane(panel), toolTip, index);
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

    public void run() {
        layoutGraph(importGraphPanel, graph);
    }

    public void moduleInfo(String module, ATerm info) {
        ATermList pairs = (ATermList) info;
        List entries = new LinkedList();

        while (!pairs.isEmpty()) {
            ATermList pair = (ATermList) pairs.getFirst();

            String name = pair.getFirst().toString();

            // The rest of the information is ignored for the moment.
            if (name.equals("path")) {

                String value;
                ATerm valueTerm = pair.getNext().getFirst();
                if (valueTerm.getType() == ATerm.APPL) {
                    value = ((ATermAppl) valueTerm).getName();
                } else {
                    value = valueTerm.toString();
                }
                String[] entry = { name, value };
                entries.add(entry);
            }

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

    public void messagef(String format, ATerm args) {
        String message = formatString(format, (ATermList) args);
        addMessage(styleMessage, null, message);
    }

    public void message(String message) {
        addMessage(styleMessage, null, message);
    }

    public void warningf(String format, ATerm args) {
        String message = formatString(format, (ATermList) args);
        addMessage(styleWarning, null, message);
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

    public void newGraph(ATerm importRelations) {
        setModules((ATermList) importRelations);
        setImports((ATermList) importRelations);

        graph = Graph.fromImportList(metaGraphFactory, (ATermList) importRelations);
        layoutGraph(importGraphPanel, graph);
    }

    public void layoutGraph(GraphPanel graphPanel, Graph graph) {
        final FontMetrics metrics =
            graphPanel.getFontMetrics(Preferences.getFont(GraphPanel.PREF_NODE_FONT));

        NodeSizer sizer = new NodeSizer() {
            public int getWidth(Node node) {
                return metrics.stringWidth(node.getLabel())
                    + Preferences.getInteger(Preferences.PREF_NODE_BORDER_WIDTH) * 2;
            }
            public int getHeight(Node node) {
                return metrics.getHeight()
                    + Preferences.getInteger(Preferences.PREF_NODE_BORDER_HEIGHT) * 2;
            }
        };

        graph = graph.orderNodes();
        graph = graph.sizeNodes(sizer);

        bridge.postEvent(
            factory.make(
                "layout-graph(<str>,<term>)",
                graphPanel.getId(),
                graph.toTerm()));
    }

    public void displayGraph(String id, ATerm graphTerm) {
        Graph graph = metaGraphFactory.GraphFromTerm(graphTerm);
        GraphPanel panel = getGraphPanel(id);
        layoutGraph(panel, graph);
    }

    public void graphLayouted(String id, ATerm graphTerm) {
        Graph graph = metaGraphFactory.GraphFromTerm(graphTerm);
        if (id.equals(importGraphPanel.getId())) {
            this.graph = graph;
        }
        GraphPanel graphPanel = getGraphPanel(id);
        graphPanel.setGraph(graph);
        graphPanel.repaint();
        graphTabs.setSelectedIndex(graphPanel.getIndex());
    }

    public void moduleSelected(Module module) {
        if (module == null) {
            moduleTree.clearSelection();
        } else {
            TreePath path = moduleManager.makeTreePath(module.getName());

            moduleTree.setSelectionPath(path);
            moduleTree.scrollPathToVisible(path);

            if (module.getState() == Module.STATE_NORMAL) {
                bridge.postEvent(
                    factory.make("get-module-info(<str>)", module.getName()));
            }
        }
    }

    public void updateList(String moduleName, String actions) {
        ATerm data = factory.parse(actions);

        if (data instanceof ATermAppl) {
            ATermAppl applData = (ATermAppl) data;
            data = (ATerm) applData.getArguments().getFirst();
            error("Deprecated use of list with function symbol " + applData.getAFun());
        }

        if (data instanceof ATermList) {
            messageWindow.setContent(moduleName, (ATermList) data);
        } else {
            error("Can't show something in list view which is not a ATermList: " + data);
        }
    }

    public void recAckEvent(ATerm event) {
    }

    public void recTerminate(ATerm t0) {
        System.exit(0);
    }

    void checkModulePopup(MouseEvent e) {
        if (e.isPopupTrigger()) {
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
        bridge.postEvent(
            factory.make("get-buttons(<term>,<str>)", buttonType, currentModule));

    }

    private void addToolBarAction(final ATermAppl action) {
        /* APIGEN */
        String label = ((ATermAppl) action.getArgument(0)).getName();
        // TODO: apification
        String name = ((ATermAppl) action.getArgument(1)).getName(); // TODO:
																	 // apification
        String path = "/images/" + name; // TODO: externalize string?
        URL url = path.getClass().getResource(path);
        if (url == null) {
            error("Unable to get icon: " + path);
        } else {
            Icon icon = new ImageIcon(url);
            Action it = new AbstractAction(label, icon) {
                public void actionPerformed(ActionEvent actionEvent) {
                    ATerm event =
                        factory.make(
                            "button-selected(<term>,<term>)",
                            ACTION_TOOLBAR,
                            action);
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
            addToolBarAction((ATermAppl) button);
            buttons = buttons.getNext();
        }

        toolBar.add(Box.createHorizontalGlue());
        toolBar.add(createScaleBox());
    }

    //{{{ public void buttonsFound(ATerm buttonType, String moduleName, ATerm
	// buttons)

    public void buttonsFound(ATerm buttonType, String moduleName, ATerm buttons) {
        if (buttonType.equals(ACTION_MENUBAR)) {
            addMenu(buttonType, moduleName, (ATermList) buttons);
        } else if (buttonType.equals(ACTION_TOOLBAR)) {
            addToolBarActions((ATermList) buttons);
        } else {
            JPopupMenu popupMenu = createPopupMenu();
            addPopupMenuItems(
                popupMenu,
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
        // TODO: use buttons.adt
        for (int i = 0; i < children.length; i++) {
            if (name.equals(children[i].getText())) {
                return children[i];
            }
        }
        return null;
    }

    private JMenu addMenuName(JMenu menu, String name) {
        JMenu[] children = (JMenu[]) menu.getSubElements();
        // TODO: this is illegal code, the cast is wrong
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
            } else {
                String name = ((ATermAppl) names.getFirst()).getName();
                cur = addMenuName(cur, name);
                names = names.getNext();
            }
        }

        return cur;
    }

    private String getMenuName(ATermList names) {
        return ((ATermAppl) names.getLast()).getName();
    }

    private void addMenu(ATerm type, String moduleName, ATermList buttons) {
        // TODO: use APIGEN on buttons.adt iso using ATermList et al. here
        while (!buttons.isEmpty()) {
            ATerm action = buttons.getFirst();
            ATermList menuItems = (ATermList) ((ATermAppl) action).getArgument(0);
            ATerm menuItem = menuItems.getFirst();
            String menuName = ((ATermAppl) menuItem).getName();
            JMenu menu = getMenuItem(getMenu(menuName), menuItems.getNext());
            menu.add(
                new ButtonAction(
                    getMenuName(menuItems),
                    type,
                    action,
                    moduleTree,
                    bridge,
                    metaGraphFactory));
            buttons = buttons.getNext();
        }
    }

    // TODO: change algorithm, do it in two parts: first find tree structure,
	// then
    // build the menus

    // The next two methods (addPopupMenuItems, addMenuItems) are exactly the
    // same. The reason is that JPopupMenu and JMenu have the same methods,
    // but are in different hierarchies. Also, we did not succeed in making
    // the methods smaller.
    public void addPopupMenuItems(
        JPopupMenu menu,
        ATerm buttonType,
        String moduleName,
        ATermList buttons,
        ATermList prefixButtonName) {

        while (!buttons.isEmpty()) {
            ATerm action = buttons.getFirst();
            ATermList buttonList = (ATermList) ((ATermAppl) action).getArgument(0);
            ATermAppl buttonNamePrefix = (ATermAppl) (buttonList.getFirst());

            buttons = buttons.getNext();

            if (buttonList.getLength() == 1) {
                menu.add(
                    new ButtonAction(
                        buttonNamePrefix.getName(),
                        buttonType,
                        action,
                        moduleTree,
                        bridge,
                        metaGraphFactory));
            } else {
                ATermList buttonRunner = buttons;
                JMenu nextLevel = new JMenu(buttonNamePrefix.getName());
                ATerm apifyMe = factory.make("menu(<term>)", buttonList.getNext());
                ATermList subMenu = factory.makeList(apifyMe);

                // collect a list of buttons that are in the same
				// 'menuNamePrefix'
                for (; !buttonRunner.isEmpty(); buttonRunner = buttonRunner.getNext()) {
                    ATerm cur = buttonRunner.getFirst();
                    ATermList curList = (ATermList) ((ATermAppl) cur).getArgument(0);
                    ATerm menuNamePrefix = curList.getFirst();

                    if (buttonNamePrefix.isEqual(menuNamePrefix)) {
                        apifyMe = factory.make("menu(<term>)", curList.getNext());
                        // TODO: apification
                        subMenu = subMenu.insert(apifyMe);
                        buttons = buttons.remove(cur);
                    }
                }

                addMenuItems(
                    nextLevel,
                    buttonType,
                    moduleName,
                    subMenu,
                    prefixButtonName.insertAt(
                        buttonNamePrefix,
                        prefixButtonName.getLength()));
                menu.add(nextLevel);
            }
        }
    }

    public void addMenuItems(
        JMenu menu,
        ATerm buttonType,
        String moduleName,
        ATermList buttons,
        ATermList prefixButtonName) {

        buttons = buttons.reverse();

        while (!buttons.isEmpty()) {
            ATerm action = buttons.getFirst();
            ATermList buttonList = (ATermList) ((ATermAppl) action).getArgument(0);
            ATermAppl buttonNamePrefix = (ATermAppl) (buttonList.getFirst());

            buttons = buttons.getNext();

            if (buttonList.getLength() == 1) {
                ATerm apifyMe =
                    factory.make("menu(<term>)", prefixButtonName.concat(buttonList));
                menu.add(
                    new ButtonAction(
                        buttonNamePrefix.getName(),
                        buttonType,
                        apifyMe,
                        moduleTree,
                        bridge,
                        metaGraphFactory));
            } else {
                ATermList buttonRunner = buttons;
                JMenu nextLevel = new JMenu(buttonNamePrefix.getName());
                ATermList subMenu = factory.makeList((ATerm) buttonList.getNext());

                // collect a list of buttons that are in the same
				// 'menuNamePrefix'
                while (!buttonRunner.isEmpty()) {
                    ATerm cur = buttonRunner.getFirst();
                    ATermList curList = (ATermList) ((ATermAppl) cur).getArgument(0);
                    ATerm menuNamePrefix = curList.getFirst();

                    if (buttonNamePrefix.isEqual(menuNamePrefix)) {
                        ATerm apifyMe = factory.make("menu(<term>)", curList.getNext());
                        // TODO: apification
                        subMenu = subMenu.insert(apifyMe);
                        buttons = buttons.remove(cur);
                    }

                    buttonRunner = buttonRunner.getNext();
                }

                addMenuItems(
                    nextLevel,
                    buttonType,
                    moduleName,
                    subMenu,
                    prefixButtonName.insertAt(
                        buttonNamePrefix,
                        prefixButtonName.getLength()));
                menu.add(nextLevel);
            }
        }
    }

    private File showFileBrowser(
        String label,
        String location,
        String extension,
        String desc) {
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

        return factory.make(
            "snd-value(file-name(<str>,<str>,<str>))",
            path,
            filename,
            extension);
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
        int choice = JOptionPane.showConfirmDialog(topFrame, question);

        if (choice == JOptionPane.YES_OPTION) {
            return factory.make("snd-value(answer(yes))");
        }
        if (choice == JOptionPane.NO_OPTION) {
            return factory.make("snd-value(answer(no))");
        }

        return factory.make("snd-value(answer(cancel))");
    }

    public void clearHistory() {
        try {
            historyDoc.remove(0, historyDoc.getLength());
        } catch (BadLocationException e) {
            System.err.println(e.getMessage());
        }
    }

    void toggleTide() {
        bridge.postEvent(
            factory.make("debugging(<id>)", tideBox.isSelected() ? "on" : "off"));
    }

    String getCurrentModule() {
        TreePath path = moduleTree.getSelectionPath();

        if (path != null) {
            TreeNode selectedModule = (TreeNode) path.getLastPathComponent();

            return selectedModule.getFullName();
        }

        return null;
    }

    public void displayFeedbackSummary(ATerm t0) {
        Summary summary = new Factory(factory).SummaryFromTerm(t0);
        feedbackList.setFeedbackList(summary);
    }
}
