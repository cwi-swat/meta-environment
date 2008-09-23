package argusviewer.gui;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Observable;
import java.util.Observer;

import javax.help.CSH;
import javax.help.HelpBroker;
import javax.help.HelpSet;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.WindowConstants;

import net.infonode.docking.RootWindow;
import net.infonode.docking.SplitWindow;
import net.infonode.docking.TabWindow;
import net.infonode.docking.View;
import net.infonode.docking.theme.DockingWindowsTheme;
import net.infonode.docking.theme.ShapedGradientDockingTheme;
import net.infonode.docking.util.DockingUtil;
import net.infonode.docking.util.ViewMap;
import net.infonode.gui.laf.InfoNodeLookAndFeel;
import net.infonode.util.Direction;
import argusviewer.ExceptionReporter;
import argusviewer.toolbus.DataComm;
import argusviewer.util.ArgusSettings;
import argusviewer.view.IView;

/**
 * Represents the main GUI window that organizes the other views and controllers using a BorderLayout.
 *
 * The GUI window consists of three areas:
 * 1. The center area that holds an InfoNode docking area containing all the views.
 * 2. The bottom area that contains a control panel to control the execution of the viewer.
 * 3. A typical GUI menu at the top.
 * 
 * @author J. van den Bos
 * @author R. Schuddeboom
 * @author S. Preeker
 * @author M. van Beest
 *
 */
public final class ArgusViewerGUI extends JFrame implements Observer {
	private final static long serialVersionUID = -3759014389298557476L;

	private final static String WINDOW_TITLE = "Argus Viewer";

	// Multiplier for the default width and height of the window with respect to the screen resolution.
	private final static float DEFAULT_SIZE_MULTIPLIER = 0.9f;

	// Split window relative sizes.
	// The left pane takes up 27% of the initial window size.
	private final static float SIZE_LEFT = 0.27f;
	
	// The top pane of the right side of the vertical split window takes up 70%.
	private final static float SIZE_RIGHT_VERTICAL = 0.7f;
	
	// The top pane of the right side of the vertical split window takes up 40%.
	private final static float SIZE_LEFT_VERTICAL = 0.4f;

	private final ArrayList<ViewContainer> m_viewContainers;
	private final TabWindow[] m_tabWindows;
	private final DataComm m_dataComm;
	
	private RootWindow m_rootWindow;
	private JMenuBar m_menuBar;

	/**
	 * Enumeration to store window position indices and names.
	 */
	private enum WindowPosition {
		TOP_LEFT(0, "TopLeft"),
		TOP_RIGHT(1, "TopRight"),
		CENTER_LEFT(2, "CenterLeft"),
		DOWN_LEFT(3, "DownLeft"),
		DOWN_RIGHT(4, "DownRight");

		private int m_index;
		private String m_name;

		public int getIndex() { return m_index; }
		public String getName() { return m_name; }

		private WindowPosition(int index, String name) {
			m_index = index;
			m_name = name;
		}
	}
	
	/**
	 * Constructs a new ArgusViewerGUI to control the application flow.
	 * 
	 * @param dataComm the DataComm object that is being debugged
	 * @param views the views encapsulating a specific visualization for the debugger
	 */
	public ArgusViewerGUI(DataComm dataComm, IView[] views) {
		m_dataComm = dataComm;

		m_viewContainers = new ArrayList<ViewContainer>();
		m_tabWindows = new TabWindow[WindowPosition.values().length];

		initializeGUI();
		populate(views);
		
		this.setVisible(true);
	}

	private void initializeGUI() {
		this.setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
		
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				shutdown();				
			}			
		});
		
		try {
			UIManager.setLookAndFeel(new InfoNodeLookAndFeel());
		} catch (UnsupportedLookAndFeelException ex) {
			ExceptionReporter.process(ex, ExceptionReporter.ExceptionState.IGNORED);
		}

		int defaultWidth = (int) (Toolkit.getDefaultToolkit().getScreenSize().width * DEFAULT_SIZE_MULTIPLIER);
		int defaultHeight = (int) (Toolkit.getDefaultToolkit().getScreenSize().height * DEFAULT_SIZE_MULTIPLIER);
		ArgusSettings settings = ArgusSettings.getInstance();
		int width = Integer.parseInt(settings.getAttribute("application.width", String.valueOf(defaultWidth)));
		int height = Integer.parseInt(settings.getAttribute("application.height", String.valueOf(defaultHeight)));
		this.setSize(new Dimension(width, height));
		this.getContentPane().setLayout(new BorderLayout());
		
		m_rootWindow = DockingUtil.createRootWindow(new ViewMap(), true);
		this.getContentPane().add(m_rootWindow, BorderLayout.CENTER);
		
		m_rootWindow.getWindowBar(Direction.DOWN).setEnabled(true);

		DockingWindowsTheme themeSetting = new ShapedGradientDockingTheme();
		m_rootWindow.getRootWindowProperties().addSuperObject(themeSetting.getRootWindowProperties());
		
		this.setTitle(WINDOW_TITLE);
	}

	/**
	 * Populate the GUI with the provided views, the controller based on the DataComm and a generated menu.
	 * 
	 * The views are placed in the center docking area. The control panel is placed in the bottom docking window.
	 *
	 * @param views the views to place in the GUI.
	 */
	public void populate(IView[] views) {
		for (IView view : views) {
			Map<String, Container> visualComponents = view.getVisualComponents();
			for (String name : visualComponents.keySet()){
				synchronized(m_viewContainers){
					m_viewContainers.add(new ViewContainer(view.getPreferredPosition(), name, visualComponents.get(name)));
				}
			}
			if (view instanceof Observable) {
				((Observable) view).addObserver(this);
			}
		}

		for (WindowPosition position : WindowPosition.values()) {
			m_tabWindows[position.getIndex()] = new TabWindow(ViewContainer.getViewsForLocation(m_viewContainers, position.getName()));
		}
		createSplitWindows();

		this.getContentPane().add(new ControlPanel(m_dataComm, this), BorderLayout.PAGE_END);

		createMenuBar();

		SwingUtilities.updateComponentTreeUI(this);
	}

	private void createSplitWindows() {
		m_rootWindow.setWindow(
				new SplitWindow(true, SIZE_LEFT,
						new SplitWindow(false, SIZE_LEFT_VERTICAL,
								m_tabWindows[WindowPosition.TOP_LEFT.getIndex()],
								new SplitWindow(false, 1 - SIZE_LEFT_VERTICAL, m_tabWindows[WindowPosition.CENTER_LEFT.getIndex()], m_tabWindows[WindowPosition.DOWN_LEFT.getIndex()])),
						new SplitWindow(false, SIZE_RIGHT_VERTICAL, m_tabWindows[WindowPosition.TOP_RIGHT.getIndex()], m_tabWindows[WindowPosition.DOWN_RIGHT.getIndex()])
				)
		);				
	}

	private void createMenuBar() {
		m_menuBar = new JMenuBar();

		JMenu applicationMenu = createApplicationMenu();
		m_menuBar.add(applicationMenu);

		JMenu viewMenu = createViewMenu();
		m_menuBar.add(viewMenu);

		JMenu helpMenu = createHelpMenu();
		m_menuBar.add(helpMenu);

		this.setJMenuBar(m_menuBar);
	}

	private JMenu createApplicationMenu() {
		JMenu applicationMenu = new JMenu("Application");
		
		// Application -> Settings menu item
		JMenuItem settingsItem = new JMenuItem("Settings");
		SettingsDialog.setParent(this);
		settingsItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SettingsDialog.open();
			}
		});
		applicationMenu.add(settingsItem);

		applicationMenu.addSeparator();

		// Application -> Exit menu item
		JMenuItem exitItem = new JMenuItem("Exit");
		exitItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				shutdown();
			}
		});
		applicationMenu.add(exitItem);
		return applicationMenu;
	}

	private JMenu createViewMenu() {
		JMenu viewMenu = new JMenu("Views");

		// Application -> $viewName and Application -> Source -> $sourceName
		JMenu sourceMenu = new JMenu("Source");
		viewMenu.add(sourceMenu);
		synchronized(m_viewContainers){
			for (ViewContainer container : m_viewContainers) {
				JMenuItem viewItem = new JMenuItem(container.getName());
				viewItem.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						synchronized(m_viewContainers){
							for (ViewContainer container : m_viewContainers) {
								if (container.getName().equals(e.getActionCommand())) {
									View view = container.getView();
									if (!view.isShowing()) {
										createSplitWindows();
										container.getParent(m_tabWindows).addTab(view);
									}
									view.restoreFocus();
									return;
								}
							}
						}
					}
				});
				if (isSourceView(container)) {
					sourceMenu.add(viewItem);
				} else {
					viewMenu.add(viewItem);
					
				}
			}
		}
		return viewMenu;
	}

	/**
	 * Checks whether a view represents a source view by checking whether it corresponds to the (last part of) the active
	 * script files as reported by the DataComm.
	 * 
	 * @param container the view to determine of whether it represents a source view
	 * @return whether the provided view represents a source view
	 */
	private boolean isSourceView(ViewContainer container) {
		for (String source : m_dataComm.getScriptfiles()) {
			if (source.endsWith(container.getName())) {
				return true;
			}
		}
		return false;
	}

	private JMenu createHelpMenu() {
		JMenu helpMenu = new JMenu("Help");

		// Help -> Manual
		JMenuItem manualItem = null;
		try {
			java.io.File temp = new java.io.File("");
			String path = temp.getAbsolutePath();
			path += "/man/helpset.hs";
			URL url = new URL("file:" + path);
			HelpSet helpSet = new HelpSet(null, url);
			HelpBroker helpBroker = helpSet.createHelpBroker();
			manualItem = new JMenuItem("Manual");
			manualItem.addActionListener(new CSH.DisplayHelpFromSource(helpBroker));
			helpMenu.add(manualItem);
		} catch (Exception e) { // TODO You should catch individual exceptions.
			e.printStackTrace();
		}
		return helpMenu;
	}

	/**
	 * Shutdown the ArgusViewer and save the settings to the file.
	 */
	public void shutdown() {
		//storeWindowLocations();	
		ArgusSettings settings = ArgusSettings.getInstance();
		settings.setAttribute("application.height", String.valueOf(this.getHeight()));
		settings.setAttribute("application.width", String.valueOf(this.getWidth()));
		settings.save();
		
		dispose();
		m_dataComm.shutdown();
	}
	
	/*private void storeWindowLocations() {
		for (WindowPosition position : WindowPosition.values()) {
			int windowCount = m_tabWindows[position.getIndex()].getChildWindowCount();
			for (int i = 0; i < windowCount; i++) {
				String tabName = m_tabWindows[position.getIndex()].getChildWindow(i).toString();
				if (tabName != null) {
					ArgusSettings.getInstance().setAttribute("WindowLocations", tabName, position.getName());
				}
			}
		}
	}*/

	/**
	 * The only thing that observable views are currently capable of communicating is a request to receive the application
	 * focus. Since there is nothing else anticipated, this is the hardcoded behaviour (and we didn't create a complex
	 * event object based data exchange).
	 * 
	 * @param o the observed view requesting the focus
	 * @param arg a String with the name of the actual view to focus to
	 */
	public void update(Observable o, Object arg) {
		View theView;
		synchronized(m_viewContainers){
			theView = ViewContainer.getViewFromName(m_viewContainers, (String) arg);
		}
		
		if (!theView.isDisplayable()) {	
			for (ViewContainer container : m_viewContainers) {
				if (container.getName().equals(arg)) {					
					createSplitWindows();
					container.getParent(m_tabWindows).addTab(theView);					
					break;
				}
			}
		}
		
		theView.restoreFocus();
	}

	/**
	 * Container class to store all view-related information, such as preferred location, name, container control and (InfoNode) view.
	 * 
	 * @author J. van den Bos
	 */
	static class ViewContainer {
		private String m_location;
		private String m_name;
		private Container m_container;
		private View m_view;
		
		public String getLocation() { return m_location; }
		public String getName() { return m_name; }
		public Container getContainer() { return m_container; }
		public View getView() { return m_view; }

		public ViewContainer(String location, String name, Container container) {
			m_location = location; //ArgusSettings.getInstance().getAttributeValue("WindowLocations", name, location);			
			m_name = name;
			m_container = container;
			m_view = new View(name, null, container);
		}
		
		public TabWindow getParent(TabWindow[] tabWindows) {
			for (WindowPosition position : WindowPosition.values()) {
				if (position.getName().equals(m_location)) {
					return tabWindows[position.getIndex()];
				}
			}
			return null;
		}
		
		public static View[] getViewsForLocation(List<ViewContainer> containers, String location) {
			ArrayList<View> views = new ArrayList<View>();
			for (ViewContainer container : containers) {
				if (container.m_location.equals(location)) {
					views.add(container.getView());
				}
			}
			return views.toArray(new View[views.size()]);
		}
		
		public static View getViewFromName(List<ViewContainer> containers, String name) {
			for (ViewContainer container : containers) {
				if (container.getName().equals(name)) {
					return container.getView();
				}
			}
			return null;
		}
	}
}
