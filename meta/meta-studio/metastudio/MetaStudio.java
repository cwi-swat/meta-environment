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
import java.util.Properties;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSplitPane;
import javax.swing.JTabbedPane;

import metastudio.components.TideControl;
import metastudio.components.dialogtool.DialogTool;
import metastudio.components.errorlist.ErrorList;
import metastudio.components.graphnodesizer.GraphNodeSizer;
import metastudio.components.infolist.InfoList;
import metastudio.components.menubar.MenuBar;
import metastudio.components.modulebrowser.ModuleBrowser;
import metastudio.components.statusbar.StatusBar;
import metastudio.components.statushistory.StatusHistory;
import metastudio.components.toolbar.ToolBar;
import metastudio.components.treebrowser.TreeBrowser;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.utils.Preferences;
import tide.tool.support.DebugAdapter;
import tide.tool.support.DebugTool;
import tide.tool.support.DebugToolListener;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class MetaStudio extends JFrame implements UserInterfaceTif {
	private static final String PARSE_TREE = "Parse tree";
	private static final String MODULES = "Modules";
	private static final String DEBUGGING = "Debugging";
	
    private  PureFactory factory;
    private  MetaGraphFactory graphFactory;
    private UserInterfaceBridge bridge;
    
    private JTabbedPane tabs;
    private Thread tideControlThread;
    private JTabbedPane messageTabs;

    public static final void main(String[] args) throws IOException {
        new MetaStudio(args);
    }

    public MetaStudio(String[] args) throws IOException {
        factory = new PureFactory();
        graphFactory = new MetaGraphFactory(factory);
        
        initializeProperties();
        handleCloseRequests();

        createContentPane(args);
        
        DialogTool dialogTool = new DialogTool(this.getRootPane(), factory, args);
		spawn(dialogTool, "dialogtool");

        makeStudioVisible();
        
        bridge = new UserInterfaceBridge(factory, this);
        bridge.init(args);
        bridge.connect();
        bridge.setLockObject(getTreeLock());
        bridge.run();
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
    
    private void spawn(Runnable component, String name) {
    	Thread thread = new Thread(component);
    	thread.setName(name);
    	thread.start();
    }
    
    private void createContentPane(String[] args) {
        MenuBar menuBar = new MenuBar(factory, args, this);
		spawn(menuBar, "menu-bar");
		
		Container content = getContentPane();
        content.setLayout(new BorderLayout());
        
        GraphNodeSizer sizer = new GraphNodeSizer(graphFactory, args);
        spawn(sizer, "graph-node-sizer");

        ToolBar toolbar = new ToolBar(factory, args);
        spawn(toolbar, "tool-bar");

        content.add(toolbar, BorderLayout.NORTH);
        content.add(createMainPane(args), BorderLayout.CENTER);
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

    private JPanel createMessageStatusPanel(String[] args) {
        JPanel container = new JPanel();
        container.setLayout(new BorderLayout());

        messageTabs = createMessageTabs(args);
        container.add(messageTabs, BorderLayout.CENTER);

        StatusBar bar = new StatusBar(factory, args);
        spawn(bar, "status-bar");
        
        container.add(bar, BorderLayout.SOUTH);

        return container;
    }


    private JSplitPane createMainPane(String[] args) {
        JComponent tabs = createMainTabs(args);
        JPanel panel = createMessageStatusPanel(args);

        JSplitPane mainPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT, tabs, panel);
        mainPanel.setResizeWeight(0.8);
        mainPanel.setDividerLocation(0.8);
        mainPanel.setOneTouchExpandable(true);
        
        return mainPanel;
    }
    

    private void postQuitEvent() {
        bridge.sendEvent(factory.parse("quit"));
    }

    private void handleCloseRequests() {
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                postQuitEvent();
            }
        });
    }

    private JTabbedPane createMainTabs(String[] args) {
    	tabs = new JTabbedPane();
    	ModuleBrowser moduleBrowser = new ModuleBrowser(factory, graphFactory, args);
    	spawn(moduleBrowser, "module-browser");
    	addTab(tabs, MODULES, moduleBrowser);
    	
    	TreeBrowser parseTreeBrowser = new TreeBrowser(graphFactory, args);
    	spawn(parseTreeBrowser, "tree-browser");
    	addTab(tabs, PARSE_TREE, parseTreeBrowser);
    	
    	try {
    		TideControl tide = new TideControl(factory, args);
    		addTab(tabs, DEBUGGING, tide);
    		
    		tide.addDebugToolListener(new DebugToolListener() {
    			public void adapterConnected(DebugTool tool, DebugAdapter adapter) {
    				tabs.setSelectedIndex(tabs.indexOfTab(DEBUGGING));
    			}

    			public void adapterDisconnected(
    					DebugTool tool,
						DebugAdapter adapter) {
    				tabs.setSelectedIndex(tabs.indexOfTab(MODULES));
    			}
    		});
    	} catch (IOException e) {
    		// TODO: 
    		System.err.println("TODO: deal with this error properly");
    	}
    	
    	return tabs;
    }
    
    private JTabbedPane createMessageTabs(String[] args) {
    	JTabbedPane messageTabs = new JTabbedPane();

    	StatusHistory historyPanel = new StatusHistory(factory, args);
    	spawn(historyPanel, "history-list");
    	
    	ErrorList errorList = new ErrorList(factory, args);
    	spawn(errorList, "error-list");
    	
    	InfoList systemInfo = new InfoList(factory, args);
    	spawn(systemInfo, "info-list");
    	
    	messageTabs.insertTab("Errors", null, errorList, "Errors and warnings", 0);
    	messageTabs.insertTab("Info",null, systemInfo,"System information", 1);
    	messageTabs.insertTab("Log", null, historyPanel, "Status log", 2);
    	
    	return messageTabs;
    }
    
    private void addTab(JTabbedPane tabs, String title, JComponent tool) {
    	tabs.insertTab(title, null, tool, null, tabs.getTabCount());
    }
    public void initializeUi(String name) {
        setTitle(name);
        Preferences.setString("metastudio.name", name);
    }

	public void recTerminate(ATerm t0) {
		System.exit(0);
		
	}
}
