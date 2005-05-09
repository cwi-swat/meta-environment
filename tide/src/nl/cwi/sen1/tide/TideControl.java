package nl.cwi.sen1.tide;

import java.awt.BorderLayout;
import java.awt.Color;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Properties;

import javax.swing.JDesktopPane;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponentAdapter;
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
	implements TideControlTif, Runnable {
	
	private static ATermFactory factory;

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

		Properties defaults;
		try {
			defaults = loadProperties();
			createTools(defaults);
			createProcessList();

			setLayout(new BorderLayout());
			
			studio.addComponent(new StudioComponentAdapter("Processes", new JScrollPane(processList)));

			studio.connect("tide-control", bridge);
			studio.connect("debug-tool", debugTool);

//			startChildThreads();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

//	private void startChildThreads() {
//		debugToolThread = new Thread(debugTool);
//		debugToolThread.setName("DebugTool");
//		debugToolThread.run();
//
//		tideControlThread = new Thread(bridge);
//		tideControlThread.setName("TideControlBridge");
//		tideControlThread.run();
//	}

	private void createProcessList() {
		processList = new ProcessList(manager);
		debugTool.addDebugToolListener(processList);
	}

	private Properties loadProperties() throws IOException {
		String resource = "/resources/tide-defaults.properties";
		InputStream stream =
			getClass().getResourceAsStream(resource);

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

	

	public void recTerminate(ATerm arg) {
		bridge.stopRunning();
		debugTool.stopRunning();
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

	public void run() {
		bridge.run();
	}	
}
