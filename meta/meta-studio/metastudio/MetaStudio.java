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

import metastudio.components.dialogtool.DialogTool;
import metastudio.components.graphnodesizer.GraphNodeSizer;
import metastudio.components.menubar.MenuBar;
import metastudio.components.statusbar.StatusBar;
import metastudio.components.toolbar.ToolBar;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.utils.Preferences;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class MetaStudio extends JFrame implements UserInterfaceTif {
    private static PureFactory factory;
    private UserInterfaceBridge bridge;

    public static final void main(String[] args) throws IOException {
        new MetaStudio(args);
    }

    private MenuBar createMenuBar(String []args) {
        MenuBar menuBar = new MenuBar(factory, args, this);
        Thread mThread = new Thread(menuBar);
        mThread.setName("menu-bar");
        mThread.start();

        return menuBar;
    }

    public MetaStudio(String[] args) throws IOException {
        factory = new PureFactory();
        
        initializeProperties();
        handleCloseRequests();

        createContentPane(args);
        createPopupHandlers(args);

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
    
    private void createPopupHandlers(String []args) {
        DialogTool dialogTool = new DialogTool(this.getRootPane(), factory, args);
        spawn(dialogTool, "dialogtool");
        
        
    }
    
    private void createContentPane(String[] args) {
        createMenuBar(args);

        Container content = getContentPane();
        content.setLayout(new BorderLayout());
        
        GraphNodeSizer sizer = new GraphNodeSizer(new MetaGraphFactory(factory), args);
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

        container.add(new MessageTabs(factory, args), BorderLayout.CENTER);

        StatusBar bar = new StatusBar(factory, args);
        spawn(bar, "status-bar");
        
        container.add(bar, BorderLayout.SOUTH);

        return container;
    }


    private JSplitPane createMainPane(String[] args) {
        JComponent tabs = new MainTabs(factory,  args);
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

    public void initializeUi(String name) {
        setTitle(name);
        Preferences.setString("metastudio.name", name);
    }

	public void recTerminate(ATerm t0) {
		System.exit(0);
	}
}
