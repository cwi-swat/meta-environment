package nl.cwi.sen1.tide;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.UnknownHostException;
import java.util.Properties;

import javax.swing.JDesktopPane;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.tide.tool.ToolManager;
import nl.cwi.sen1.tide.tool.prefeditor.PreferencesEditorFactory;
import nl.cwi.sen1.tide.tool.proclist.ProcessList;
import nl.cwi.sen1.tide.tool.ruleinspector.RuleInspectorFactory;
import nl.cwi.sen1.tide.tool.srcviewer.SourceViewerFactory;
import nl.cwi.sen1.tide.tool.stackviewer.StackViewerFactory;
import nl.cwi.sen1.tide.tool.support.DebugTool;
import nl.cwi.sen1.tide.tool.support.DebugToolListener;
import aterm.ATerm;
import aterm.ATermFactory;

public class TideControl
	extends JPanel
	implements TideControlTif {
	
	public static ATermFactory factory;

	private TideControlBridge bridge;
	private DebugTool debugTool;
	private Studio studio;

	private JDesktopPane desktop;
	private ProcessList processList;

	private ToolManager manager;

	protected Thread debugToolThread;
	protected Thread tideControlThread;

	public TideControl(Studio studio) {
		this.studio = studio;
		nl.cwi.sen1.tide.tool.support.Port.initialize(studio.getATermFactory());
		nl.cwi.sen1.tide.tool.support.Expr.initialize(studio.getATermFactory());

		TideControl.factory = studio.getATermFactory();

		setBackground(Color.white);

		bridge = new TideControlBridge(factory, this);
		debugTool = new DebugTool(factory);

		desktop = new JDesktopPane();
		desktop.setPreferredSize(new Dimension(750, 500));

		
		Properties defaults;
		try {
			defaults = loadProperties();
			createTools(defaults);
			createProcessList();

			setLayout(new BorderLayout());
			add("Center", desktop);
			add("West", new JScrollPane(processList));

			connectTideControl(studio);
			connectDebugTool(studio);

			startChildThreads();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void startChildThreads() {
		debugToolThread = new Thread(debugTool);
		debugToolThread.setName("DebugTool");
		debugToolThread.start();

		tideControlThread = new Thread(bridge);
		tideControlThread.setName("TideControlBridge");
		tideControlThread.start();
	}

	private void createProcessList() {
		processList = new ProcessList(manager);
		debugTool.addDebugToolListener(processList);
	}

	private Properties loadProperties() throws IOException {
		String resource = "META-INF/tide-defaults.properties";
		InputStream stream =
			getClass().getClassLoader().getResourceAsStream(resource);

		Properties defaults = new Properties();
		defaults.load(stream);
		return defaults;
	}

	private void createTools(Properties defaults) {
		manager = new ToolManager(studio, defaults);

		manager.registerProcessTool(new RuleInspectorFactory(manager));
		manager.registerProcessTool(new SourceViewerFactory(manager));
		manager.registerProcessTool(new StackViewerFactory(manager));
		
		manager.registerTool(new PreferencesEditorFactory(manager));
	}

	

	protected void connectDebugTool(Studio studio) throws UnknownHostException, IOException {
		studio.connect("debug-tool", debugTool);
	}

	protected void connectTideControl(Studio studio) throws UnknownHostException, IOException {
		studio.connect("tide-control", bridge);
	}

	public void recTerminate(ATerm arg) {
		stopChildThreads();
		
		System.exit(0);
	}

	protected void stopChildThreads() {
		debugTool.stopRunning();
		debugToolThread.interrupt();
		
		bridge.stopRunning();
		tideControlThread.interrupt();
		
		try {
			debugToolThread.join();
		} catch (InterruptedException e) {
			System.err.println("Ignoring interrupt during shutdown: debugToolThread");
		}
		
		try {
			tideControlThread.join();
		} catch (InterruptedException e1) {
			System.err.println("Ignoring interrupt during shutdown: tideControlThread");
		}
	}

	public void loadPreferences() {
		JFileChooser chooser = new JFileChooser();
		chooser.setSelectedFile(new File(PreferenceSet.PREFS_FILE));
		int option = chooser.showOpenDialog(this);
		if (option == JFileChooser.APPROVE_OPTION) {
			File file = chooser.getSelectedFile();
			if (file != null) {
				try {
					InputStream stream = new FileInputStream(file);
					manager.getPreferences().loadPreferences(stream);
				} catch (IOException e) {
					JOptionPane.showInternalMessageDialog(
						desktop,
						"Could not load preferences: " + e.getMessage(),
						"Preferences Load Error",
						JOptionPane.ERROR_MESSAGE);
				}
			}
		}
	}

	public void savePreferences() {
		JFileChooser chooser = new JFileChooser();
		chooser.setSelectedFile(new File(PreferenceSet.PREFS_FILE));
		int option = chooser.showSaveDialog(this);
		if (option == JFileChooser.APPROVE_OPTION) {
			File file = chooser.getSelectedFile();
			if (file != null) {
				try {
					OutputStream stream = new FileOutputStream(file);
					manager.getPreferences().savePreferences(stream);
				} catch (IOException e) {
					JOptionPane.showInternalMessageDialog(
						desktop,
						"Could not save preferences: " + e.getMessage(),
						"Preferences Save Error",
						JOptionPane.ERROR_MESSAGE);
				}
			}
		}
	}

	public static ATermFactory getFactory() {
		return factory;
	}
	
	public TideControlBridge getBridge() {
		return bridge;
	}
	
	public ToolManager getManager() {
		return manager;
	}
	
	public void postEvent(ATerm term) {
		getBridge().postEvent(term);
	}
	
	public void addDebugToolListener(DebugToolListener l) {
		debugTool.addDebugToolListener(l);
	}	
}
