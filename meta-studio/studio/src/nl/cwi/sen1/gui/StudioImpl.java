package nl.cwi.sen1.gui;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ButtonGroup;
import javax.swing.Icon;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JProgressBar;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

import net.infonode.docking.DockingWindow;
import net.infonode.docking.DockingWindowAdapter;
import net.infonode.docking.OperationAbortedException;
import net.infonode.docking.RootWindow;
import net.infonode.docking.View;
import net.infonode.docking.ViewSerializer;
import net.infonode.docking.properties.RootWindowProperties;
import net.infonode.docking.theme.BlueHighlightDockingTheme;
import net.infonode.docking.theme.ClassicDockingTheme;
import net.infonode.docking.theme.DefaultDockingTheme;
import net.infonode.docking.theme.DockingWindowsTheme;
import net.infonode.docking.theme.GradientDockingTheme;
import net.infonode.docking.theme.ShapedGradientDockingTheme;
import net.infonode.docking.theme.SlimFlatDockingTheme;
import net.infonode.docking.theme.SoftBlueIceDockingTheme;
import net.infonode.docking.util.DockingUtil;
import net.infonode.docking.util.ViewMap;
import net.infonode.util.Direction;
import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.util.StudioMenuBar;
import nl.cwi.sen1.util.StudioStatusBar;
import nl.cwi.sen1.util.StudioStatusBarConstraints;
import toolbus.AbstractTool;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class StudioImpl implements Studio, GuiTif {
    private static int nextUniqueComponentID = 0;

    private PureFactory factory;

    private Factory configFactory;

    private GuiBridge bridge;

    private ViewMap viewsById;

    private Map<StudioComponent, Integer> idsByComponent;

    protected Map<View, StudioComponent> componentsByView;

    private Map<StudioComponent, List<JMenuItem>> componentMenus;

    protected RootWindow rootWindow;

    private RootWindowProperties properties;

    private JFrame frame;

    private JLabel systemLabel;

    JProgressBar progressBar;

    private ATermList menuList;

    private DockingWindowsTheme currentTheme;

    private View activeView;

    private StudioStatusBar statusBar;

    private boolean menuBarUpdatePending;

    private List<StudioPlugin> plugins;

    private List<String> jobQueue;

    protected boolean studioShuttingDown;

    public static void main(String args[]) throws Exception {
        new StudioImpl(args);
    }

    public StudioImpl(String[] args) {
        initialize();

        rootWindow = createRootWindow();

        statusBar = createStatusBar();

        startFrameThread();

        startBridgeThread(args);
    }

    private void startBridgeThread(String[] args) {
        bridge = new GuiBridge(factory, this);
        try {
            bridge.init(args);
            bridge.connect();
            bridge.setLockObject(this);
        } catch (IOException e) {
            System.err.println("Could not establish connection to ToolBus: "
                    + e);
            System.exit(1);
        }

        Thread thread = new Thread(new Runnable() {
            public void run() {
                bridge.run();
            }
        });
        thread.setName("BasicStudio");
        thread.start();
    }

    private void startFrameThread() {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createFrame();
            }
        });
    }

    private void initialize() {
        factory = new PureFactory();
        configFactory = Factory.getInstance(factory);
        menuList = factory.getEmpty();
        properties = new RootWindowProperties();
        currentTheme = new ShapedGradientDockingTheme();
        idsByComponent = new HashMap<StudioComponent, Integer>();
        componentsByView = new HashMap<View, StudioComponent>();
        componentMenus = new HashMap<StudioComponent, List<JMenuItem>>();
        viewsById = new ViewMap();
        plugins = new LinkedList<StudioPlugin>();
        studioShuttingDown = false;
        progressBar = new JProgressBar();
        systemLabel = new JLabel();
        jobQueue = new LinkedList<String>();
    }

    synchronized private static int nextComponentID() {
        return nextUniqueComponentID++;
    }

    protected RootWindow createRootWindow() {
        ViewSerializer viewSerializer = new ViewSerializer() {
            public void writeView(View arg0, ObjectOutputStream arg1) {
            }

            public View readView(ObjectInputStream arg0) {
                return null;
            }
        };

        RootWindow root = new RootWindow(viewSerializer);

        // Set gradient theme. The theme properties object is the super object
        // of our properties object, which
        // means our property value settings will override the theme values
        properties.addSuperObject(currentTheme.getRootWindowProperties());

        // Our properties object is the super object of the root window
        // properties object, so all property values of the
        // theme and in our property object will be used by the root window
        root.getRootWindowProperties().addSuperObject(properties);
        // root.getRootWindowProperties().getTabWindowProperties().getTabbedPanelProperties().getTabAreaProperties().setTabAreaVisiblePolicy(TabAreaVisiblePolicy.MORE_THAN_ONE_TAB);

        root.getWindowBar(Direction.DOWN).setEnabled(true);

        root.addListener(new DockingWindowAdapter() {
            public void viewFocusChanged(View oldView, View newView) {
                if (newView != null) {
                    activeView = newView;
                    updateMenuBar();
                    updateStatusBar();
                    StudioComponent component = getComponent(activeView);
                    if (component != null) {
                        component.receiveFocus();
                    } else {
                        System.err
                                .println("Internal error: no active component found");
                    }
                }
            }

            public void windowClosing(DockingWindow window)
                    throws OperationAbortedException {
                if (window instanceof View) {
                    StudioComponent component = componentsByView.get(window);

                    try {
                        component.requestClose();
                    } catch (CloseAbortedException e) {
                        throw new OperationAbortedException(e.getMessage(), e
                                .getCause());
                    }
                }
            }

            public void windowClosed(DockingWindow window) {
                if (window instanceof View) {
                    StudioComponent component = componentsByView.get(window);

                    // StatusBar statusBar = (StatusBar)
                    // componentStatusBar.get(component);

                    // statusPanel.remove(statusBar);
                    componentsByView.remove(window);
                    componentMenus.remove(component);

                    component.close();
                }
            }

            public void windowHidden(DockingWindow arg0) {
                updateMenuBar();
                updateStatusBar();
            }
        });

        return root;
    }

    private void updateStatusBar() {
        if (activeView != null) {
            StudioComponent active = getComponent(activeView);

            if (active != null) {
                JComponent[] components = active.getStatusBarComponents();

                for (int i = statusBar.getComponentCount(); i > 5; i--) {
                    statusBar.remove(i - 1);
                }
                
                if (components != null) {
                    for (JComponent cur : components) {
                        statusBar.addSeparator();
                        statusBar.add(cur);
                    }
                }
                statusBar.repaint();
            } else {
                System.err.println("Internal error: no active component found");
            }
        }
    }

    private void updateMenuBar() {
        if (!menuBarUpdatePending) {
            menuBarUpdatePending = true;
            SwingUtilities.invokeLater(new Runnable() {
                public void run() {
                    if (frame != null) {
                        frame.setJMenuBar(createMenuBar());
                    }
                    if (rootWindow != null) {
                        rootWindow.revalidate();
                    }
                    menuBarUpdatePending = false;
                }
            });
        }
    }

    public ATermFactory getATermFactory() {
        return factory;
    }

    protected View createView(StudioComponent component, int id) {
        final String name = component.getName();
        Icon icon = component.getIcon();
        JComponent viewComponent = component.getViewComponent();
        View view = new View(name, icon, viewComponent);
        componentsByView.put(view, component);
        viewsById.addView(id, view);

        return view;
    }

    protected int registerComponent(final StudioComponent component) {
        int id = nextComponentID();
        idsByComponent.put(component, new Integer(id));
        return id;
    }

    public void addComponent(StudioComponent component) {
        int id = registerComponent(component);
        final View view = createView(component, id);
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                showView(view);
            }
        });
    }

    public void removeComponent(StudioComponent component) {
        if (component != null) {
            int id = getComponentId(component);

            if (id != -1) {
                final View view = deleteView(id);
                SwingUtilities.invokeLater(new Runnable() {
                    public void run() {
                        view.close();
                    }
                });
                idsByComponent.remove(component);
            } else {
                System.err.println("Can not remove non-registered component: "
                        + component.getName());
            }
        } else {
            System.err.println("Can not remove non-registered component");
        }
    }

    private int getComponentId(StudioComponent component) {
        Integer componentId = idsByComponent.get(component);

        if (componentId != null) {
            return componentId.intValue();
        }
        return -1;
    }

    private View deleteView(int id) {
        View view = viewsById.getView(id);
        viewsById.removeView(id);
        return view;
    }

    private void createFrame() {
        frame = new JFrame();
        frame.setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
        // frame.getContentPane().add(createToolBar(), BorderLayout.NORTH);
        frame.getContentPane().add(statusBar, BorderLayout.SOUTH);
        frame.getContentPane().add(rootWindow, BorderLayout.CENTER);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                bridge.postEvent(factory.make("window-closing-event"));
            }
        });
        frame.pack();
        frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        frame.setVisible(true);
    }

    private StudioStatusBar createStatusBar() {
        StudioStatusBar statusPanel = new StudioStatusBar();

        systemLabel.setPreferredSize(new Dimension(300, 18));
        statusPanel.add(systemLabel);
        statusPanel.addSeparator();

        statusPanel.add(progressBar);
        statusPanel.addSeparator();

        JLabel filler = new JLabel();
        statusPanel.add(filler, new StudioStatusBarConstraints(1.0));

        // JButton cancel = new JButton("Cancel");
        // statusPanel.add(cancel);

        return statusPanel;
    }

    private StudioMenuBar createMenuBar() {
        StudioMenuBar menuBar = new StudioMenuBar();
        menuBar.add(createEmptyFileMenu());
        menuBar.add(createViewsMenu());
        menuBar.add(createThemesMenu());

        ATermList menuPaths = menuList;
        while (!menuPaths.isEmpty()) {
            final Event menuPath = configFactory.EventFromTerm(menuPaths
                    .getFirst());
            menuBar.addMenuPath(menuPath, new AbstractAction(menuPath.toTerm()
                    .toString()) {
                public void actionPerformed(ActionEvent e) {
                    ATerm event = factory.make("menu-event(<term>)", menuPath
                            .toTerm());
                    bridge.postEvent(event);
                }
            });
            menuPaths = menuPaths.getNext();
        }

        if (activeView != null && activeView.getRootWindow() != null) {
            StudioComponent activeComponent = getComponent(activeView);
            List menus = getComponentMenus(activeComponent);
            if (menus != null) {
                Iterator iter = menus.iterator();
                while (iter.hasNext()) {
                    Object menu = iter.next();

                    if (menu instanceof MenuItem) {
                        MenuItem menuItem = (MenuItem) menu;
                        menuBar.addMenuPath(menuItem.getEvent(), menuItem
                                .getAction());
                    } else {
                        menuBar.add((JMenu) menu);
                    }
                }
            }
        }

        return menuBar;
    }

    private JMenu createViewsMenu() {
        JMenu menu = new JMenu("Views");
        int count = viewsById.getViewCount();

        for (--count; count >= 0; count--) {
            final View view = viewsById.getViewAtIndex(count);
            JMenuItem item = new JMenuItem(view.getTitle());
            item.setEnabled(view.getRootWindow() == null);
            item.addActionListener(new AbstractAction() {
                public void actionPerformed(ActionEvent e) {
                    showView(view);
                    view.restoreFocus();
                }
            });

            menu.add(item);
        }

        return menu;
    }

    private List getComponentMenus(StudioComponent component) {
        if (componentMenus == null) {
            return null;
        }

        return componentMenus.get(component);
    }

    private JMenu createEmptyFileMenu() {
        return new JMenu("File");
    }

    protected void showView(View view) {
        if (rootWindow == null) {
            rootWindow = createRootWindow();
            frame.getContentPane().add(rootWindow, BorderLayout.CENTER);
        }
        DockingUtil.addWindow(view, rootWindow);
        rootWindow.revalidate();
    }

    private JMenu createThemesMenu() {
        JMenu themesMenu = new JMenu("Themes");

        DockingWindowsTheme[] themes = { new DefaultDockingTheme(),
                new BlueHighlightDockingTheme(), new SlimFlatDockingTheme(),
                new GradientDockingTheme(), new ShapedGradientDockingTheme(),
                new SoftBlueIceDockingTheme(), new ClassicDockingTheme() };

        ButtonGroup group = new ButtonGroup();

        for (final DockingWindowsTheme theme : themes) {
            JMenuItem item = new JRadioButtonMenuItem(theme.getName());
            item.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    // Clear the modified properties values
                    properties.getMap().clear(true);
                    setTheme(theme);
                }
            });
            group.add(item);
            themesMenu.add(item);
        }

        return themesMenu;
    }

    private void setTheme(DockingWindowsTheme theme) {
        properties.replaceSuperObject(currentTheme.getRootWindowProperties(),
                theme.getRootWindowProperties());
        currentTheme = theme;
    }

    public void setTitle(String title) {
        frame.setTitle(title);
    }

    public void recAckEvent(ATerm t0) {
    }

    public void recTerminate(ATerm t) {
        studioShuttingDown = true;
        tryShutDown();
    }

    public void connect(String toolName, final AbstractTool tool) {
        try {
            tool.connect(toolName, bridge.getAddress(), bridge.getPort());
            tool.setLockObject(this);
        } catch (IOException e) {
            System.err.println("Failed to connect '" + toolName
                    + "' to ToolBus");
            e.printStackTrace();
        }
        Thread thread = new Thread(new Runnable() {
            public void run() {
                tool.run();
            }
        });
        thread.setName(toolName + "-runner");
        thread.start();
    }

    private StudioComponent getComponent(View view) {
        return componentsByView.get(view);
    }

    private void startPlugin(PluginLoader loader) {
        final StudioPlugin plugin = loader.instantiatePlugin();
        registerPlugin(plugin);
        Thread thread = new Thread(new Runnable() {
            public void run() {
                plugin.initStudioPlugin(StudioImpl.this);
            }
        });
        thread.setName(plugin.getName() + "-starter");
        thread.start();
    }

    private void registerPlugin(StudioPlugin plugin) {
        plugins.add(plugin);
        plugin.addStudioPluginListener(new StudioPluginListener() {
            public void studioPluginClosed(StudioPlugin plugin) {
                plugins.remove(plugin);

                tryShutDown();
            }
        });
    }

    public void loadJar(String pluginJar) {
        startPlugin(new PluginLoader(pluginJar));
    }

    public void loadJarUrls(String pluginJar, ATerm classPath) {
        startPlugin(new PluginLoader(pluginJar, (ATermList) classPath));
    }

    public void loadJarClasspath(String pluginJar, String classPath) {
        startPlugin(new PluginLoader(pluginJar, classPath));
    }

    public void addMenuEvents(ATerm menus) {
        menuList = menuList.concat((ATermList) menus);
        updateMenuBar();
    }

    public void addComponentMenu(StudioComponent component, JMenu menu) {
        if (componentMenus == null) {
            componentMenus = new HashMap<StudioComponent, List<JMenuItem>>();
        }

        List<JMenuItem> menus = componentMenus.get(component);
        if (menus == null) {
            menus = new LinkedList<JMenuItem>();
        }
        menus.add(menu);

        componentMenus.put(component, menus);
        updateMenuBar();
    }

    public void addComponentMenu(StudioComponent component, Event menuPath,
            Action action) {
        MenuItem item = new MenuItem(menuPath, action);
        List<JMenuItem> menus = getMenus(component);
        menus.add(item);

        componentMenus.put(component, menus);
        updateMenuBar();
    }

    private List<JMenuItem> getMenus(StudioComponent component) {
        List<JMenuItem> menus = componentMenus.get(component);
        if (menus == null) {
            menus = new LinkedList<JMenuItem>();
        }
        return menus;
    }

    public void requestFocus(StudioComponent component) {
        Integer id = idsByComponent.get(component);

        if (id != null) {
            View view = viewsById.getView(id.intValue());

            if (view != null) {
                view.restoreFocus();
            } else {
                System.err.println("No view found for: " + component.getName());
            }
        } else {
            System.err.println("This component does not have a view: "
                    + component.getName());
        }
    }

    private void tryShutDown() {
        if (studioShuttingDown && plugins.isEmpty()) {
            System.exit(0);
        }
    }

    public void setStatus(String message) {
        systemLabel.setText(message);
    }

    public void jobDone(String message) {
        jobQueue.remove(message);
        if (jobQueue.isEmpty()) {
            progressBar.setIndeterminate(false);
            setStatus("Idle");
        } else {
            setStatus(jobQueue.get(0));
        }

    }

    public void addJob(String message) {
        jobQueue.add(message);
        setStatus(message);
        progressBar.setIndeterminate(true);
    }
}
