package metastudio;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.UnknownHostException;
import java.util.Properties;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSplitPane;
import javax.swing.JTabbedPane;

import metastudio.components.FeedbackList;
import metastudio.components.FileDialog;
import metastudio.components.HistoryPanel;
import metastudio.components.MenuBar;
import metastudio.components.MessageList;
import metastudio.components.ModuleBrowser;
import metastudio.components.ModulePopupMenu;
import metastudio.components.QuestionDialog;
import metastudio.components.StatusBar;
import metastudio.components.ToolBar;
import metastudio.components.ToolComponent;
import metastudio.components.ParseTreeBrowser;
import metastudio.utils.Preferences;
import aterm.pure.PureFactory;

public class MetaStudio extends JFrame  {
    private static PureFactory factory;
    private MultiBridge bridge;

    private HistoryPanel historyPanel;

    public static final void main(String[] args) throws IOException {
        new MetaStudio(args);
    }

    private MenuBar createMenuBar() {
        MenuBar menuBar = new MenuBar(factory, getBridge(), this);

        return menuBar;
    }

    public MetaStudio(String[] args) throws IOException {
        factory = new PureFactory();
        createToolBusBridge(args);
        
        initializeProperties();
        handleCloseRequests();

        createContentPane();
        createPopupHandlers();

        makeStudioVisible();
        
        // should be done after construction of all components
        getBridge().run();
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
    
    private void createPopupHandlers() {
        getBridge().addToolComponent(new QuestionDialog(factory, getBridge(), this.getRootPane()));
        getBridge().addToolComponent(new FileDialog(factory, getBridge()));
        getBridge().addToolComponent(new ModulePopupMenu(factory, getBridge()));
    }
    
    private void createContentPane() {
        createMenuBar();

        Container content = getContentPane();
        content.setLayout(new BorderLayout());

        ToolComponent toolbar = new ToolBar(factory, getBridge());
        content.add(toolbar, BorderLayout.NORTH);

        content.add(createMainPane(), BorderLayout.CENTER);
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

    private JPanel createMessageStatusPanel() {
        JPanel container = new JPanel();
        container.setLayout(new BorderLayout());

        container.add(createMessageTabs(), BorderLayout.CENTER);

        if (historyPanel == null) {
            historyPanel = new HistoryPanel(factory, getBridge());
            getBridge().addToolComponent(historyPanel);
        }

        StatusBar bar = new StatusBar(factory, getBridge(), historyPanel);
        getBridge().addToolComponent(bar);
        container.add(bar, BorderLayout.SOUTH);

        return container;
    }


    private JSplitPane createMainPane() {
        JComponent tabs = createMainTabs();
        JPanel panel = createMessageStatusPanel();

        JSplitPane mainPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT, tabs, panel);
        mainPanel.setResizeWeight(0.8);
        mainPanel.setDividerLocation(0.8);
        mainPanel.setOneTouchExpandable(true);
        
        return mainPanel;
    }
    
    
    private JTabbedPane createMainTabs() {
        JTabbedPane tabs = new JTabbedPane();

        addTab(tabs, "Modules", new ModuleBrowser(factory, getBridge()));
        addTab(tabs, "Parse tree", new ParseTreeBrowser(factory, getBridge()));
        
        return tabs;
    }
    
    private void addTab(JTabbedPane tabs, String title, JComponent tool) {
        tabs.insertTab(title, null, tool, null, tabs.getTabCount());
    }

  
    private JTabbedPane createMessageTabs() {
        JTabbedPane messageTabs = new JTabbedPane();

        if (historyPanel == null) {
            historyPanel = new HistoryPanel(factory, getBridge());
        }
        
        ToolComponent feedbackList = new FeedbackList(factory, getBridge());
        messageTabs.insertTab("feedback", null, feedbackList, "feedback messages", 0);
       
        ToolComponent messageList = new MessageList(factory, getBridge());
        messageTabs.insertTab("messages", null, messageList, "old-style messages", 1);
        
        messageTabs.insertTab("history", null, historyPanel, "Execution history", 2);
      
        return messageTabs;
    }

    private void postQuitEvent() {
        getBridge().sendEvent(factory.parse("quit"));
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

        setBridge(new MultiBridge(factory));
        getBridge().init(args);
        getBridge().connect();
        getBridge().setLockObject(getTreeLock());
    }

    public void initializeUi(String name) {
        setTitle(name);
        Preferences.setString("metastudio.name", name);
    }

    private void setBridge(MultiBridge bridge) {
        this.bridge = bridge;
    }

    private MultiBridge getBridge() {
        return bridge;
    }

   
}
