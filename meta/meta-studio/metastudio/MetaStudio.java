package metastudio;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FontMetrics;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.UnknownHostException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Properties;

import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSplitPane;
import javax.swing.JTabbedPane;
import metastudio.components.FeedbackList;
import metastudio.components.FileDialog;
import metastudio.components.HistoryPanel;
import metastudio.components.MenuBar;
import metastudio.components.MessageList;
import metastudio.components.ModulePopupMenu;
import metastudio.components.ModuleStatusPanel;
import metastudio.components.ModuleTree;
import metastudio.components.QuestionDialog;
import metastudio.components.StatusBar;
import metastudio.components.ToolBar;
import metastudio.components.ToolComponent;
import metastudio.components.graphs.GraphPanel;
import metastudio.components.graphs.ImportGraphPanel;
import metastudio.components.graphs.NodeSizer;
import metastudio.components.graphs.ParseTreePanel;
import metastudio.components.graphs.ZoomableGraphPanel;
import metastudio.data.Module;
import metastudio.data.ModuleTreeModel;
import metastudio.data.graph.AttributeList;
import metastudio.data.graph.EdgeList;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import metastudio.data.graph.NodeList;
import metastudio.utils.Preferences;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.pure.PureFactory;

//TODO: extract ToolBar, MenuBar and Trees from the monolith

public class MetaStudio
    extends JFrame
    implements UserInterfaceTif, Runnable {

    private static final double RIGHTPANEL_DIVIDER_LOCATION = 0.8;

    public static PureFactory factory;
    public static MetaGraphFactory metaGraphFactory;

    private UserInterfaceBridge bridge;

    private ToolBar toolBar;

    private JTabbedPane mainTabs;

    private Graph graph;
    private ImportGraphPanel importGraphPanel;
    private ParseTreePanel parseTreePanel;
    private FeedbackList feedbackList;

    private Map graphPanels;

    private ModuleStatusPanel moduleStatus;

    private HistoryPanel historyPanel;
    private MessageList messageList;

    private ModuleTreeModel moduleManager;

    private LinkedList toolComponents;

    public static final void main(String[] args) throws IOException {
        MetaStudio studio = new MetaStudio(args);
        studio.bridge.run();
    }

    private MenuBar createMenuBar() {
        MenuBar menuBar = new MenuBar(factory, bridge, this);
        addToolComponent(menuBar);
        return menuBar;
    }

    private ToolBar createToolBar() {
        ToolBar toolBar = new ToolBar(factory, bridge);
        addToolComponent(toolBar);
        return toolBar;
    }

    public MetaStudio(String[] args) throws IOException {
        graphPanels = new HashMap();

        factory = new PureFactory();

        toolComponents = new LinkedList();

        metaGraphFactory = new MetaGraphFactory(factory);
        moduleManager = new ModuleTreeModel();

        initializeProperties();

        createToolBusBridge(args);
        handleCloseRequests();

        createContentPane();

        createPopupHandlers();

        makeStudioVisible();

    }

    private void createPopupHandlers() {
        addToolComponent(new QuestionDialog(factory, bridge, this.getRootPane()));
        addToolComponent(new FileDialog(factory, bridge));
        addToolComponent(new ModulePopupMenu(factory, bridge));
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

    private void createParsetreePanel() {
        parseTreePanel = new ParseTreePanel(metaGraphFactory, bridge);
    }

    private JPanel createMessageStatusPanel() {
        JPanel container = new JPanel();
        container.setLayout(new BorderLayout());
        container.add(createMessageTabs(), BorderLayout.CENTER);

        if (historyPanel == null) {
            historyPanel = new HistoryPanel(factory, bridge);
            addToolComponent(historyPanel);
        }

        StatusBar bar = new StatusBar(factory, bridge, historyPanel);
        addToolComponent(bar);
        container.add(bar, BorderLayout.SOUTH);

        return container;
    }

    private JSplitPane createMainPane() {
        mainTabs = createGraphTabs();
        JPanel panel = createMessageStatusPanel();

        JSplitPane mainPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT, mainTabs, panel);
        mainPanel.setResizeWeight(RIGHTPANEL_DIVIDER_LOCATION);
        mainPanel.setDividerLocation(RIGHTPANEL_DIVIDER_LOCATION);
        return mainPanel;
    }

    private JPanel createLeftPane() {
        JPanel leftPanel = new JPanel();
        leftPanel.setLayout(new BoxLayout(leftPanel, BoxLayout.Y_AXIS));

        ToolComponent moduleTree = new ModuleTree(factory, bridge, moduleManager);
        leftPanel.add(moduleTree);

        createModuleStatusPanel();
        leftPanel.add(moduleStatus);
        
        return leftPanel;
    }

    private JTabbedPane createGraphTabs() {
        JTabbedPane tabs = new JTabbedPane();

        mainTabs = tabs;

        JSplitPane moduleBrowser = createModuleBrowser();

        mainTabs.insertTab(
            "Modules",
            null,
            moduleBrowser,
            "Modules",
            mainTabs.getTabCount());

        createParsetreePanel();
        addGraphPanel(parseTreePanel, "parsetree");
        mainTabs.insertTab(
            "Parse tree",
            null,
            parseTreePanel,
            "Parse tree",
            mainTabs.getTabCount());

        return tabs;
    }

    private void createContentPane() {
        createMenuBar();

        Container content = getContentPane();
        content.setLayout(new BorderLayout());

        toolBar = createToolBar();
        content.add(toolBar, BorderLayout.NORTH);

        content.add(createMainPane(), BorderLayout.CENTER);
    }

    private JTabbedPane createMessageTabs() {
        JTabbedPane messageTabs = new JTabbedPane();

        if (historyPanel == null) {
            historyPanel = new HistoryPanel(factory, bridge);
            addToolComponent(historyPanel);
        }
        messageTabs.insertTab("history", null, historyPanel, "Execution history", 0);

        messageList = new MessageList(factory, bridge);
        getToolComponents().add(messageList);
        messageTabs.insertTab("messages", null, messageList, "Message list", 1);

        feedbackList = new FeedbackList(factory, bridge);
        getToolComponents().add(feedbackList);
        messageTabs.insertTab("errors", null, feedbackList, "Clickable messages", 2);

        return messageTabs;
    }

    private void postQuitEvent() {
        bridge.sendEvent(factory.parse("quit"));
    }

    private void createModuleStatusPanel() {
        moduleStatus = new ModuleStatusPanel(factory, bridge, moduleManager);
    }

    private JSplitPane createModuleBrowser() {
        JPanel left = createLeftPane();

        createModuleGraph();
        addGraphPanel(importGraphPanel, "import");

        JSplitPane moduleBrowser =
            new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, left, importGraphPanel);
        moduleBrowser.setDividerLocation(-1);
        return moduleBrowser;
    }

    private void createModuleGraph() {
        Color color;

        NodeList nodes = metaGraphFactory.makeNodeList_Empty();
        EdgeList edges = metaGraphFactory.makeEdgeList_Empty();
        AttributeList attrs = metaGraphFactory.makeAttributeList_Empty();

        graph = metaGraphFactory.makeGraph_Default(nodes, edges, attrs);

        importGraphPanel = new ImportGraphPanel(factory, bridge, moduleManager);

        color = Preferences.getColor(Preferences.PREF_GRAPHPANE_BACKGROUND);
        importGraphPanel.setBackground(color);
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

    private void addGraphPanel(ZoomableGraphPanel panel, String id) {
        graphPanels.put(id, panel);
    }

    private ZoomableGraphPanel getGraphPanel(String id) {
        return (ZoomableGraphPanel) graphPanels.get(id);
    }

    public void run() {
        layoutGraph(importGraphPanel, graph);
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

    public void layoutGraph(ZoomableGraphPanel graphPanel, Graph graph) {
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
        ZoomableGraphPanel panel = getGraphPanel(id);
        layoutGraph(panel, graph);
    }

    public void graphLayouted(String id, ATerm graphTerm) {
        Graph graph = metaGraphFactory.GraphFromTerm(graphTerm);
        if (id.equals(importGraphPanel.getId())) {
            this.graph = graph;
        }
        ZoomableGraphPanel graphPanel = getGraphPanel(id);
        graphPanel.setGraph(graph);
        graphPanel.repaint();
        mainTabs.setSelectedIndex(graphPanel.getIndex());
    }
    
//    private void showModulePopup(ATerm buttonType) {
//        bridge.postEvent(
//            factory.make("get-buttons(<term>,<str>)", buttonType, currentModule));
//
//    }

    public void buttonsFound(ATerm buttonType, String moduleName, ATerm buttons) {
        Iterator iter = getToolComponents().iterator();
        System.err.println("buttonsFound for " + buttonType);
        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.buttonsFound(buttonType, moduleName, buttons);
        }
    }

    public void addStatus(ATerm id, String message) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.addStatus(id, message);
        }
    }

    public void addStatusf(ATerm id, String format, ATerm args) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.addStatusf(id, format, args);
        }
    }

    public void endStatus(ATerm id) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.endStatus(id);
        }
    }

    public void displayFeedbackSummary(ATerm t0) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.displayFeedbackSummary(t0);
        }
    }

    public void updateList(String moduleName, String actions) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.updateList(moduleName, actions);
        }
    }

    public void errorf(String format, ATerm args) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.errorf(format, args);
        }
    }

    public void error(String message) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.error(message);
        }
    }

    public void messagef(String format, ATerm args) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.messagef(format, args);
        }
    }

    public void message(String message) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.message(message);
        }
    }

    public void warningf(String format, ATerm args) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.warningf(format, args);
        }
    }

    public void warning(String message) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.warning(message);
        }
    }

    public void clearHistory() {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.clearHistory();
        }
    }

    public ATerm showQuestionDialog(String question) {
        ATerm result = null;
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            result = tif.showQuestionDialog(question);

            if (result != null) {
                return factory.make("snd-value(<term>)", result);
            }
        }

        throw new UnsupportedOperationException("not implemented");
    }

    public ATerm showFileDialog(String label, String loc, String extension) {
        ATerm result = null;
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            result = tif.showFileDialog(label, loc, extension);

            if (result != null) {
                return factory.make("snd-value(<term>)", result);
            }
        }

        throw new UnsupportedOperationException("not implemented");
    }

    public void recAckEvent(ATerm event) {
    }

    public void recTerminate(ATerm t0) {
        System.exit(0);
    }

    private LinkedList getToolComponents() {
        return toolComponents;
    }

    private void addToolComponent(UserInterfaceTif tool) {
        getToolComponents().add(new UserInterfaceBridge(factory, tool));
    }
}
