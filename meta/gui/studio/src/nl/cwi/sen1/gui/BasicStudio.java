package nl.cwi.sen1.gui;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

import javax.swing.AbstractAction;
import javax.swing.ButtonGroup;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;

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
import nl.cwi.sen1.util.Preferences;
import toolbus.AbstractTool;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class BasicStudio implements Studio, GuiTif {
	private static int nextUniqueComponentID = 0;

	private PureFactory factory;

	private GuiBridge bridge;

	private ViewMap viewMap;

	private RootWindow rootWindow;

	private RootWindowProperties properties = new RootWindowProperties();

	private JFrame frame;

	private Map components;

	private Map menuMap;

	private DockingWindowsTheme currentTheme;

	public static final void main(String args[]) throws Exception {
		new BasicStudio(args);
	}

	public BasicStudio(String[] args) {
		currentTheme = new ShapedGradientDockingTheme();
		components = new HashMap();
		menuMap = new HashMap();

		initializeProperties();

		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				createFrame();
			}
		});

		factory = new PureFactory();
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

	private void initializeProperties() {
		InputStream propertyStream;
		// propertyStream = getClass().getResourceAsStream(
		// "/META-INF/default.properties");
		Properties properties = new Properties();
		// properties.load(propertyStream);
		Preferences.initialize("MetaStudio Preferences", properties);
		try {
			File file = new File(System.getProperty("user.home"), ".metarc");
			propertyStream = new FileInputStream(file);
			Preferences.load(propertyStream);
		} catch (IOException e) {
			// do nothing
		}
	}

	private void createRootWindow() {
		rootWindow = DockingUtil.createRootWindow(viewMap, true);

		rootWindow.setPreferredSize(new Dimension(800, 600));

		// Set gradient theme. The theme properties object is the super object
		// of our properties object, which
		// means our property value settings will override the theme values
		properties.addSuperObject(currentTheme.getRootWindowProperties());

		// Our properties object is the super object of the root window
		// properties object, so all property values of the
		// theme and in our property object will be used by the root window
		rootWindow.getRootWindowProperties().addSuperObject(properties);

		rootWindow.getWindowBar(Direction.DOWN).setEnabled(true);

		frame.getContentPane().add(rootWindow, BorderLayout.CENTER);
		frame.validate();
	}

	public ATermFactory getFactory() {
		return factory;
	}

	public void addComponent(final JComponent component) {
		String name = component.getName();
		int id = nextComponentID();
		components.put(component, new Integer(id));
		final View view = new View(name, null, component);
		addView(id, view);
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				showView(view);
			}
		});
	}

	public void removeComponent(JComponent component) {
		int id = ((Integer) components.get(component)).intValue();
		final View view = viewMap.getView(id);
		viewMap.removeView(id);
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				view.close();
			}
		});
	}

	public void loadJar(String jarName) {
		System.err.println("loadJar: " + jarName);
		URL url = null;
		try {
			url = new URL(jarName);
		} catch (MalformedURLException e) {
			System.err.println("Invalid URL: " + jarName);
			System.exit(1);
		}

		JarClassLoader loader = new JarClassLoader(url);
		String name = null;
		try {
			name = loader.getMainClassName();
		} catch (IOException e) {
			System.err.println("I/O error while loading JAR file:");
			e.printStackTrace();
			System.exit(1);
		}
		if (name == null) {
			System.err
					.println("Specified jar file does not contain a 'Main-Class'"
							+ " manifest attribute");
			System.exit(1);
		}

		try {
			Class cl = loader.loadClass(name);
			spawn((StudioPlugin) cl.newInstance());
		} catch (Exception e) {
			e.printStackTrace();
		}
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
				component.initStudioPlugin(BasicStudio.this);
			}
		});
		thread.setName(component.getName() + "-starter");
		thread.start();
	}

	/**
	 * Initializes the frame and shows it.
	 */
	private void createFrame() {
		frame = new JFrame();
		frame.getContentPane().add(createToolBar(), BorderLayout.NORTH);
		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				bridge.postEvent(factory.make("window-closing-event"));
			}
		});
		frame.setJMenuBar(createMenuBar());
		frame.setSize(800, 600);
		frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		frame.setVisible(true);
	}

	private JMenuBar createMenuBar() {
		JMenuBar menuBar = new JMenuBar();
		menuBar.add(createEmptyFileMenu());
		menuBar.add(createThemesMenu());
		return menuBar;
	}

	private JMenu createEmptyFileMenu() {
		JMenu menu = new JMenu("File");
		menuMap.put("File", menu);
		return menu;
	}

	private JToolBar createToolBar() {
		JToolBar toolBar = new JToolBar();
		JLabel label = new JLabel("Sample action");
		toolBar.add(label);
		return toolBar;
	}

	private void addView(int id, View view) {
		if (viewMap == null) {
			viewMap = new ViewMap();
		}
		viewMap.addView(id, view);
	}

	private void showView(View view) {
		if (rootWindow == null) {
			createRootWindow();
		}
		DockingUtil.addWindow(view, rootWindow);
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

	private JMenu getMenu(String name) {
		JMenu menu = (JMenu) menuMap.get(name);

		if (menu == null) {
			menu = new JMenu(name);
			menuMap.put(name, menu);
			frame.getJMenuBar().add(menu);
		}

		return menu;
	}

	private JMenu getMenuItem(JMenu menu, ATermList names) {
		JMenu cur = menu;

		while (!names.isEmpty()) {
			if (names.getLength() == 1) {
				break;
			}
			String name = ((ATermAppl) names.getFirst()).getName();
			cur = addMenuName(cur, name);
			names = names.getNext();
		}

		return cur;
	}

	private JMenu findMenuLocation(JMenu[] children, String name) {
		for (int i = 0; i < children.length; i++) {
			if (name.equals(children[i].getText())) {
				return children[i];
			}
		}
		return null;
	}

	private JMenu addMenuName(JMenu menu, String name) {
		JMenu[] children = (JMenu[]) menu.getSubElements();
		JMenu location = findMenuLocation(children, name);

		if (location == null) {
			JMenu newItem = new JMenu(name);
			menu.add(newItem);
			return newItem;
		}

		return location;
	}

	private String getMenuLabel(ATermList list) {
		return ((ATermAppl) list.getFirst()).getName();
	}

	private void addMenu(ATermList buttons) {
		while (!buttons.isEmpty()) {
			final ATerm action = buttons.getFirst();
			ATermList menuItems = (ATermList) ((ATermAppl) action)
					.getArgument(0);
			ATerm menuItem = menuItems.getFirst();
			final String menuName = ((ATermAppl) menuItem).getName();
			JMenu menu = getMenuItem(getMenu(menuName), menuItems.getNext());
			String label = getMenuLabel(menuItems.getNext());
			menu.add(new AbstractAction(label) {
				public void actionPerformed(ActionEvent e) {
					ATerm event = factory.make("menu-event(<term>)", action);
					bridge.postEvent(event);
				}
			});
			buttons = buttons.getNext();
		}
	}

	public InetAddress getAddress() {
		return bridge.getAddress();
	}

	public int getPort() {
		return bridge.getPort();
	}

	public void setTitle(String title) {
		frame.setTitle(title);
	}

	public void addMenuEvents(ATerm events) {
		addMenu((ATermList) events);
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t) {
		System.exit(0);
	}

	public void connect(String toolName, final AbstractTool tool) {
		try {
			tool.connect(toolName, getAddress(), getPort());
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
}
