package tide;

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

import tide.tool.ToolManager;
import tide.tool.prefeditor.PreferencesEditorFactory;
import tide.tool.proclist.ProcessList;
import tide.tool.ruleinspector.RuleInspectorFactory;
import tide.tool.srcviewer.SourceViewerFactory;
import tide.tool.stackviewer.StackViewerFactory;
import tide.tool.support.DebugTool;
import tide.tool.support.Expr;
import tide.tool.support.Port;
import aterm.ATerm;
import aterm.ATermFactory;

public class TideControl
	extends JPanel
	implements TideControlTif  {
	
	public static ATermFactory factory;

	private TideControlBridge bridge;
	private DebugTool tool;

	private JDesktopPane desktop;
	private ProcessList processList;

	private ToolManager manager;

	public TideControl(ATermFactory factory, String[] args)
		throws IOException {
		
		Port.initialize(factory);
		Expr.initialize(factory);

		TideControl.factory = factory;

		setBackground(Color.white);

		bridge = new TideControlBridge(factory, this);
		tool = new DebugTool(factory);

		desktop = new JDesktopPane();
		desktop.setPreferredSize(new Dimension(1000, 700));

		Properties defaults = loadProperties();

		createTools(defaults);
		createProcessList();

		setLayout(new BorderLayout());
		add("Center", desktop);
		add("West", new JScrollPane(processList));

		connectTideControl(args);
		connectDebugTool(args);

		Thread thread = new Thread(tool);
		thread.start();

		thread = new Thread(bridge);
		thread.start();
	}

	private void createProcessList() {
		processList = new ProcessList(manager);
		tool.addDebugToolListener(processList);
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
		manager = new ToolManager(desktop, defaults);

		manager.registerProcessTool(new RuleInspectorFactory(manager));
		manager.registerProcessTool(new SourceViewerFactory(manager));
		manager.registerProcessTool(new StackViewerFactory(manager));
		
		manager.registerTool(new PreferencesEditorFactory(manager));
	}

	

	protected void connectDebugTool(String[] args) throws UnknownHostException, IOException {
		tool.init(args);
		tool.setLockObject(this);
		tool.connect("debug-tool", null, -1);
	}

	protected void connectTideControl(String[] args) throws UnknownHostException, IOException {
		bridge.init(args);
		bridge.setLockObject(this);
		bridge.connect();
	}

	public void recTerminate(ATerm arg) {
		System.exit(0);
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
}
