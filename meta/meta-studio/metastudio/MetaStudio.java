package metastudio;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
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
import metastudio.components.graphs.ImportGraphPanel;
import metastudio.components.graphs.ParseTreePanel;
import metastudio.components.graphs.ZoomableGraphPanel;
import metastudio.data.ModuleTreeModel;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.utils.Preferences;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class MetaStudio
    extends JFrame
    implements UserInterfaceTif, Runnable {

    private static PureFactory factory;
    private static MetaGraphFactory metaGraphFactory;

    private UserInterfaceBridge bridge;

    private ToolBar toolBar;

    private JTabbedPane mainTabs;

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
        mainTabs = createMainTabs();
        JPanel panel = createMessageStatusPanel();

        JSplitPane mainPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT, mainTabs, panel);
        mainPanel.setResizeWeight(0.8);
        mainPanel.setDividerLocation(0.8);
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

    private JTabbedPane createMainTabs() {
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

        importGraphPanel = new ImportGraphPanel(metaGraphFactory, bridge, moduleManager);

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
        addToolComponent(panel);
    }

    public void run() {
    }

    public void initializeUi(String name) {
        setTitle(name);
        Preferences.setString("metastudio.name", name);
    }

    public void newGraph(ATerm importRelations) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.newGraph(importRelations);
        }
    }


    public void displayGraph(String id, ATerm graphTerm) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.displayGraph(id, graphTerm);
        }
    }

    public void graphLayouted(String id, ATerm graphTerm) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.graphLayouted(id, graphTerm);
        }
    }
    
    public void buttonsFound(ATerm buttonType, String moduleName, ATerm buttons) {
        Iterator iter = getToolComponents().iterator();

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
