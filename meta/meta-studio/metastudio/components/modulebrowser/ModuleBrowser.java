package metastudio.components.modulebrowser;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;

import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JSplitPane;
import javax.swing.SwingUtilities;

import metastudio.components.graphs.ZoomableGraphPanel;
import metastudio.data.Module;
import metastudio.data.ModuleTreeModel;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import metastudio.utils.Preferences;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

public class ModuleBrowser extends JPanel implements ModuleBrowserTif, Runnable, ModuleSelectionListener {
	private ZoomableGraphPanel importGraphPanel;
	private ModuleInfoPanel moduleStatus;
	private ModuleTreeModel moduleManager;
	private MetaGraphFactory metaGraphFactory;
	private ATermFactory factory;
	private ModuleBrowserBridge bridge;
	private ModulePopupMenu popup;

	public ModuleBrowser(ATermFactory factory, MetaGraphFactory graphFactory, String []args ) {
		this.factory = factory;
		metaGraphFactory = graphFactory;
		
		setLayout(new BorderLayout());
		
		moduleManager = new ModuleTreeModel();

		JSplitPane left = createLeftPane();

		createModuleGraph();

		JSplitPane moduleBrowser = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,
				left, importGraphPanel);
		moduleBrowser.setDividerLocation(Preferences
				.getDouble("modulebrowser.info.divider.location"));
		moduleBrowser.setResizeWeight(Preferences
				.getDouble("modulebrowser.info.divider.resize"));
		moduleBrowser.setOneTouchExpandable(true);

		add(moduleBrowser);
		
		moduleManager.addModuleSelectionListener(this);
		importGraphPanel.addMouseListener(makeMouseListener(moduleManager));
		
		try {
			bridge = new ModuleBrowserBridge(factory, this);
			popup = new ModulePopupMenu(factory, bridge);
			
			bridge.init(args);
			bridge.setLockObject(this);
			bridge.connect("module-browser", null, -1);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void createModuleGraph() {
		importGraphPanel = new ZoomableGraphPanel(metaGraphFactory, "import-graph");
		Color color = Preferences.getColor("graphpane.background");
		importGraphPanel.setBackground(color);
	}

	private void createModuleStatusPanel() {
		moduleStatus = new ModuleInfoPanel(factory,moduleManager);
	}

	private MouseListener makeMouseListener(final ModuleTreeModel moduleManager) {
		MouseListener listener = new MouseAdapter() {
			public void mousePressed(MouseEvent event) {
				Node node = importGraphPanel.getNodeAt(event.getX(), event.getY());
				ModulePopupMenu.setPopupLocation(
						(JComponent) event.getSource(), event.getX(), event
						.getY());

				Module module;

				if (node == null) {
					module = null;
				} else {
					module = moduleManager.getModule(node.getId().getId());
					if (event.isPopupTrigger()
							|| SwingUtilities.isRightMouseButton(event)) {
						  postModuleMenuRequest(module);
					}

				}
				moduleManager.selectModule(module);

			}

			public void mouseReleased(MouseEvent e) {
				mousePressed(e);
			}
		};
		return listener;
	}

	public void moduleSelected(Module module) {
		if (module == null) {
			importGraphPanel.setSelectedNode(null);
		} else {
			importGraphPanel.setSelectedNode(importGraphPanel.getNode(module.getName()));
		}
	}

	private void setModules(ATermList importList) {
		moduleManager.clearModules();

		while (!importList.isEmpty()) {
			ATermList importPair = (ATermList) importList.getFirst();
			importList = importList.getNext();
			ATermAppl moduleTerm = (ATermAppl) importPair.getFirst();
			String name = moduleTerm.getName();
			addModule(name);
		}
	}

	private Module addModule(String name) {
		Module module = moduleManager.getModule(name);
		if (module == null) {
			module = new Module(name);
			moduleManager.addModule(module);
		}

		return module;
	}

	private void setImports(ATermList importList) {

		while (!importList.isEmpty()) {
			ATermList importPair = (ATermList) importList.getFirst();
			importList = importList.getNext();

			ATermAppl fromTerm = (ATermAppl) importPair.getFirst();
			String from = fromTerm.getName();
			Module moduleFrom = moduleManager.getModule(from);
			if (moduleFrom == null) {
				moduleFrom = addModule(from);
				moduleFrom.setState(Module.STATE_NEW);
			}

			ATermList imports = (ATermList) importPair.elementAt(1);

			while (!imports.isEmpty()) {
				ATermAppl toTerm = (ATermAppl) imports.getFirst();
				imports = imports.getNext();

				String to = toTerm.getName();
				Module moduleTo = moduleManager.getModule(to);
				if (moduleTo == null) {
					moduleTo = addModule(to);
					moduleTo.setState(Module.STATE_NEW);
				}

				moduleFrom.addChild(to);
				moduleTo.addParent(from);
			}
		}
	}

	public void displayTreelist(String id, ATerm termList) {
		ATermList modules = (ATermList) termList;
		setModules(modules);
		setImports(modules);
	}

	public void displayGraph(String id, ATerm graphTerm) {
		Graph graph = metaGraphFactory.GraphFromTerm(graphTerm);
		importGraphPanel.setGraph(graph);
		setVisible(true);
		importGraphPanel.repaint();
	}
	
	private JSplitPane createLeftPane() {
		ModuleTree moduleTree = new ModuleTree(factory, this, moduleManager);

		createModuleStatusPanel();

		JSplitPane leftPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT,
				moduleTree, moduleStatus);
		leftPanel.setOneTouchExpandable(true);
		leftPanel.setDividerLocation(Preferences
				.getDouble("modulebrowser.graph.divider.location"));
		leftPanel.setResizeWeight(Preferences
				.getDouble("modulebrowser.graph.divider.resize"));
		return leftPanel;
	}

	public void postModuleMenuRequest(Module current) {

		ATerm popup = factory.parse("module-popup");

		if (current.getState() == Module.STATE_NEW) {
			popup = factory.parse("new-module-popup");
		}

		bridge.postEvent(factory.make("get-events(<term>,<str>)", popup,
				current.getName()));
	}

	public void addEvents(ATerm t0, String s1, ATerm t2) {
		popup.addEvents(t0, s1, t2);
	}

	public void recAckEvent(ATerm t0) {
		
	}

	public void recTerminate(ATerm t0) {
	}

	public void run() {
		bridge.run();
	}
}