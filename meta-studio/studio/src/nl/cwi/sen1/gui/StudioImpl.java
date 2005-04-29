package nl.cwi.sen1.gui;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

import javax.swing.AbstractAction;
import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.Icon;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;
import javax.swing.border.EtchedBorder;

import net.infonode.docking.DockingWindowAdapter;
import net.infonode.docking.RootWindow;
import net.infonode.docking.View;
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
import nl.cwi.sen1.util.StudioMenuBar;
import toolbus.AbstractTool;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class StudioImpl implements Studio, GuiTif, StudioComponentListener {
	private static int nextUniqueComponentID = 0;

	private PureFactory factory;

	private GuiBridge bridge;

	private ViewMap viewsById;

	private Map idsByComponent;

	private Map componentsByView;

	private RootWindow rootWindow;

	private RootWindowProperties properties;

	private JFrame frame;

	private ATermList menuList;

	private DockingWindowsTheme currentTheme;

	private View activeView;

	private JLabel statusBar;

	public static final void main(String args[]) throws Exception {
		new StudioImpl(args);
	}

	public StudioImpl(String[] args) {
		properties = new RootWindowProperties();
		currentTheme = new ShapedGradientDockingTheme();
		idsByComponent = new HashMap();
		componentsByView = new HashMap();
		viewsById = new ViewMap();
		factory = new PureFactory();
		menuList = factory.getEmpty();

		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				createFrame();
			}
		});

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

	synchronized private static int nextComponentID() {
		return nextUniqueComponentID++;
	}

	private RootWindow createRootWindow() {
		RootWindow root = DockingUtil.createRootWindow(viewsById, true);

		root.setPreferredSize(new Dimension(800, 600));

		// Set gradient theme. The theme properties object is the super object
		// of our properties object, which
		// means our property value settings will override the theme values
		properties.addSuperObject(currentTheme.getRootWindowProperties());

		// Our properties object is the super object of the root window
		// properties object, so all property values of the
		// theme and in our property object will be used by the root window
		root.getRootWindowProperties().addSuperObject(properties);

		root.getWindowBar(Direction.DOWN).setEnabled(true);

		root.addListener(new DockingWindowAdapter() {
			public void viewFocusChanged(View oldView, View newView) {
				if (newView != null) {
					activeView = newView;
					setupMenuBar();
					updateStatusBar();
				}
			}
		});

		return root;
	}

	protected void updateStatusBar() {
		if (activeView != null) {
			StudioComponent component = getComponent(activeView);
			String message = component.getStatusMessage();
			statusBar.setText(message == null ? " " : message);
		}
	}

	public ATermFactory getATermFactory() {
		return factory;
	}

	private View createView(StudioComponent component, int id) {
		String name = component.getName();
		Icon icon = component.getIcon();
		JComponent viewComponent = component.getViewComponent();
		View view = new View(name, icon, viewComponent);
		componentsByView.put(view, component);
		viewsById.addView(id, view);
		return view;
	}

	private int registerComponent(StudioComponent component) {
		component.addStudioComponentListener(this);
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
		int id = unregisterComponent(component);
		final View view = deleteView(id);
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				view.close();
			}
		});
	}

	private View deleteView(int id) {
		View view = viewsById.getView(id);
		viewsById.removeView(id);
		return view;
	}

	private int unregisterComponent(StudioComponent component) {
		component.removeStudioComponentListener(this);
		int id = ((Integer) idsByComponent.get(component)).intValue();
		idsByComponent.remove(component);
		return id;
	}

	public void loadJar(String jarName) {
		loadJar(createURL(jarName), new URL[] {});
	}

	public void loadJar(String jarName, String classPath) {
		List urlList = new LinkedList();
		StringTokenizer tok = new StringTokenizer(classPath, ":");
		while (tok.hasMoreTokens()) {
			String url = tok.nextToken();
			try {
				urlList.add(new URL("file:" + url));
			} catch (MalformedURLException e) {
				System.err.println("Ignoring malformed url: " + url);
			}
		}
		// use urlList.toArray() in 1.5
		URL[] urls = new URL[urlList.size()];
		int index = 0;
		Iterator iter = urlList.iterator();
		while (iter.hasNext()) {
			urls[index++] = (URL) urlList.get(index);
		}
		loadJar(createURL(jarName), urls);
	}

	public void loadJar(String jarName, ATerm classPathTerm) {
		ATermList classPathEntries = (ATermList) classPathTerm;
		URL[] classPath = new URL[(classPathEntries).getLength()];
		for (int i = 0; !classPathEntries.isEmpty(); i++) {
			String entry = ((ATermAppl) classPathEntries.getFirst()).getName();
			classPath[i] = createURL(entry);
			classPathEntries = classPathEntries.getNext();
		}
		loadJar(createURL(jarName), classPath);
	}

	private void loadJar(URL jarURL, URL[] classPath) {
		System.err.println("loadJar: " + jarURL);
		for (int i = 0; i < classPath.length; i++) {
			System.err.println("\t" + classPath[i]);
		}
		JarClassLoader loader = new JarClassLoader(jarURL, classPath);
		String name = null;
		try {
			name = loader.getMainClassName();
		} catch (IOException e) {
			System.err.println("I/O error while loading JAR file:");
			e.printStackTrace();
		}
		if (name == null) {
			System.err
					.println("Specified jar file does not contain a 'Main-Class' manifest attribute");
		}
		try {
			Class cl = loader.loadClass(name);
			spawn((StudioPlugin) cl.newInstance());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private URL createURL(String jarName) {
		URL url = null;
		try {
			url = new URL(jarName);
		} catch (MalformedURLException e) {
			System.err.println("Invalid URL: " + jarName);
		}
		return url;
	}

	public void loadClass(String urlName, String className) {
		try {
			URLClassLoader loader = new URLClassLoader(new URL[] { new URL(
					urlName) });
			Class cl = loader.loadClass(className);
			spawn((StudioPlugin) cl.newInstance());
		} catch (Exception e) {
			System.err.println("Failed to create instance: " + e);
		}
	}

	private void spawn(final StudioPlugin component) {
		Thread thread = new Thread(new Runnable() {
			public void run() {
				component.initStudioPlugin(StudioImpl.this);
			}
		});
		thread.setName(component.getName() + "-starter");
		thread.start();
	}

	private void createFrame() {
		frame = new JFrame();
		frame.getContentPane().add(createToolBar(), BorderLayout.NORTH);
		frame.add(createStatusBar(), BorderLayout.SOUTH);
		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				bridge.postEvent(factory.make("window-closing-event"));
			}
		});
		setupMenuBar();
		frame.setSize(800, 600);
		frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		frame.setVisible(true);
	}

	private Component createStatusBar() {
		this.statusBar = new JLabel(" ");
		statusBar.setBorder(BorderFactory
				.createEtchedBorder(EtchedBorder.RAISED));
		return statusBar;
	}

	private StudioMenuBar createMenuBar() {
		StudioMenuBar menuBar = new StudioMenuBar();
		menuBar.add(createEmptyFileMenu());
		menuBar.add(createThemesMenu());

		ATermList menuPaths = menuList;
		while (!menuPaths.isEmpty()) {
			final ATerm menuPath = menuPaths.getFirst();
			menuBar.addMenuPath(menuPath, new AbstractAction(menuPath
					.toString()) {
				public void actionPerformed(ActionEvent e) {
					ATerm event = factory.make("menu-event(<term>)", menuPath);
					bridge.postEvent(event);
				}
			});
			menuPaths = menuPaths.getNext();
		}

		if (activeView != null) {
			StudioComponent component = getComponent(activeView);
			JMenu[] menus = component.getMenus();
			if (menus != null) {
				for (int i = 0; i < menus.length; i++) {
					menuBar.add(menus[i]);
				}
			}
		}

		return menuBar;
	}

	private JMenu createEmptyFileMenu() {
		return new JMenu("File");
	}

	private JToolBar createToolBar() {
		JToolBar toolBar = new JToolBar();
		JLabel label = new JLabel("Sample action");
		toolBar.add(label);
		return toolBar;
	}

	private void showView(View view) {
		if (rootWindow == null) {
			rootWindow = createRootWindow();
			frame.add(rootWindow, BorderLayout.CENTER);
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

		for (int i = 0; i < themes.length; i++) {
			final DockingWindowsTheme theme = themes[i];

			JRadioButtonMenuItem item = new JRadioButtonMenuItem(theme
					.getName());
			item.setSelected(i == 4);
			group.add(item);

			themesMenu.add(item).addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					// Clear the modified properties values
					properties.getMap().clear(true);

					setTheme(theme);
				}
			});
		}

		return themesMenu;
	}

	private void setTheme(DockingWindowsTheme theme) {
		properties.replaceSuperObject(currentTheme.getRootWindowProperties(),
				theme.getRootWindowProperties());
		currentTheme = theme;

	}

	public void addMenuEvents(ATerm menus) {
		menuList = menuList.concat((ATermList) menus);
		setupMenuBar();
	}

	private void setupMenuBar() {
		frame.setJMenuBar(createMenuBar());
	}

	public void setTitle(String title) {
		frame.setTitle(title);
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t) {
		System.exit(0);
	}

	public void connect(String toolName, final AbstractTool tool) {
		try {
			tool.connect(toolName, bridge.getAddress(), bridge.getPort());
		} catch (IOException e) {
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

	public void menuChanged(StudioEvent event) {
	}

	public void statusMessageChanged(StatusMessageEvent event) {
		StudioComponent activeComponent = (StudioComponent) componentsByView
				.get(activeView);
		if (event.getSource() == activeComponent) {
			String message = event.getNewMessage();
			statusBar.setText(message == null ? " " : message);
		}
	}

	private StudioComponent getComponent(View view) {
		return (StudioComponent) componentsByView.get(view);
	}
}
