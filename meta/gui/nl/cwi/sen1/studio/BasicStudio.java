package nl.cwi.sen1.studio;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;

import javax.swing.ButtonGroup;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
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
import aterm.ATerm;
import aterm.pure.PureFactory;

public class BasicStudio implements Studio, GuiTif {
	private static int nextUniqueViewId = 0;

	private PureFactory factory;

	private GuiBridge bridge;

	private ViewMap viewMap;

	private RootWindow rootWindow;

	private RootWindowProperties properties = new RootWindowProperties();

	private JFrame frame;

	/**
	 * The currently applied docking windows theme
	 */
	private DockingWindowsTheme currentTheme = new ShapedGradientDockingTheme();

	public static final void main(String args[]) throws Exception {
		// UIManager.setLookAndFeel(new MetalLookAndFeel());

		new BasicStudio(args);
	}

	public BasicStudio(String[] args) {
		// Docking windwos should be run in the Swing thread
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
			// bridge.setLockObject(getTreeLock());
			bridge.run();
		} catch (IOException e) {
			System.err.println("Could not establish connection to ToolBus: "
					+ e);
			System.exit(1);
		}
	}

	synchronized private static int nextViewId() {
		return nextUniqueViewId++;
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

	public int getPort() {
		return bridge.getPort();
	}

	public InetAddress getAddress() {
		return bridge.getAddress();
	}

	public void setTitle(String title) {
		frame.setTitle(title);
	}

	public int addComponent(final JComponent component) {
		System.err.println("addComponent: " + component.getName());
		final View view = new View(component.getName(), null, component);
		int id = addView(view);
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				showView(view);
			}
		});
		return id;
	}

	public void removeComponent(int id) {
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
			spawn((StudioComponent) cl.newInstance());
		} catch (Exception e) {
			System.err.println("Failed to create instance: " + e);
		}
	}

	private void spawn(final StudioComponent component) {
		Thread thread = new Thread(new Runnable() {
			public void run() {
				component.initStudioComponent(BasicStudio.this);
			}
		});
		thread.setName(component.getName());
		thread.start();
	}

	public void loadClass(String urlName, String className) {
		System.err.println("loadClass: " + className);
		try {
			URLClassLoader loader = new URLClassLoader(new URL[] { new URL(
					urlName) });
			JComponent instance;
			instance = (JComponent) loader.loadClass(className).newInstance();
		} catch (Exception e) {
			System.err.println("loadClass: exception: " + e);
		}
	}

	public void recTerminate(ATerm t) {
		System.exit(0);
	}

	/**
	 * Initializes the frame and shows it.
	 */
	private void createFrame() {
		frame = new JFrame();
		frame.getContentPane().add(createToolBar(), BorderLayout.NORTH);
		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				postQuitEvent();
			}
		});
		frame.setJMenuBar(createMenuBar());
		frame.setSize(800, 600);
		frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		frame.setVisible(true);
	}

	/**
	 * Creates the frame menu bar.
	 * 
	 * @return the menu bar
	 */
	private JMenuBar createMenuBar() {
		JMenuBar menuBar = new JMenuBar();
		JMenu menu = new JMenu("File");
		JMenuItem item = new JMenuItem("Exit");
		menu.add(item).addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				postQuitEvent();
			}
		});
		menuBar.add(menu);
		menuBar.add(createThemesMenu());
		return menuBar;
	}

	private void postQuitEvent() {
		bridge.postEvent(factory.make("quit"));
		// System.exit(0);
	}

	/**
	 * Creates the frame tool bar.
	 * 
	 * @return the frame tool bar
	 */
	private JToolBar createToolBar() {
		JToolBar toolBar = new JToolBar();
		JLabel label = new JLabel("Sample action");
		toolBar.add(label);
		return toolBar;
	}

	private int addView(View view) {
		if (viewMap == null) {
			viewMap = new ViewMap();
		}
		int id = nextViewId();
		viewMap.addView(id, view);
		return id;
	}

	private void showView(View view) {
		if (rootWindow == null) {
			createRootWindow();
		}
		DockingUtil.addWindow(view, rootWindow);
	}

	/**
	 * Creates the menu where the theme can be changed.
	 * 
	 * @return the theme menu
	 */
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

	/**
	 * Sets the docking windows theme.
	 * 
	 * @param theme
	 *            the docking windows theme
	 */
	private void setTheme(DockingWindowsTheme theme) {
		properties.replaceSuperObject(currentTheme.getRootWindowProperties(),
				theme.getRootWindowProperties());
		currentTheme = theme;
	}

}
