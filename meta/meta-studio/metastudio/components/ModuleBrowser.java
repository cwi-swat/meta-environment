package metastudio.components;

import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JComponent;
import javax.swing.JSplitPane;
import javax.swing.SwingUtilities;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
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
import aterm.pure.PureFactory;

public class ModuleBrowser extends UserInterfacePanel implements ModuleSelectionListener {
	private ZoomableGraphPanel importGraphPanel;
	private ModuleInfoPanel moduleStatus;
	private ModuleTreeModel moduleManager;
	private MetaGraphFactory metaGraphFactory;

	public ModuleBrowser(ATermFactory factory, MultiBridge bridge, String []args ) {
		super(factory, bridge);

		metaGraphFactory = new MetaGraphFactory((PureFactory) factory);
	
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
		
	}

	private void createModuleGraph() {
		importGraphPanel = new ZoomableGraphPanel(metaGraphFactory, "import-graph");
		Color color = Preferences.getColor("graphpane.background");
		importGraphPanel.setBackground(color);
	}

	private void createModuleStatusPanel() {
		moduleStatus = new ModuleInfoPanel(getFactory(), getBridge(),
				moduleManager);
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
						ModuleBrowser.postModuleMenuRequest(getFactory(),
								getBridge(), module);
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
		UserInterfacePanel moduleTree = new ModuleTree(getFactory(),
				getBridge(), moduleManager);

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

	static public void postModuleMenuRequest(ATermFactory factory,
			MultiBridge bridge, Module current) {

		ATerm popup = factory.parse("module-popup");

		if (current.getState() == Module.STATE_NEW) {
			popup = factory.parse("new-module-popup");
		}

		bridge.postEvent(factory.make("get-events(<term>,<str>)", popup,
				current.getName()));
	}
}