package nl.cwi.sen1.gui.plugin;

import javax.swing.JComponent;
import javax.swing.JMenu;

import nl.cwi.sen1.data.Module;
import nl.cwi.sen1.data.ModuleSelectionListener;
import nl.cwi.sen1.data.ModuleTreeModel;
import nl.cwi.sen1.gui.AbstractStudioComponent;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioPlugin;
import nl.cwi.sen1.util.Preferences;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

public class Navigator implements StudioPlugin, NavigatorTif {
	private static final String TOOL_NAME = "navigator";

	private static final String RESOURCE_DIR = "/resources";

	private NavigatorBridge bridge;

	private ModuleTreeModel moduleModel;

	private ModulePopupMenu popup;

	private Studio studio;

	// TODO: use preferences
	private Preferences preferences;

	private boolean suspendSelectionNotification;

	public Navigator() {
		String propertyPath = new String(RESOURCE_DIR + '/' + TOOL_NAME
				+ ".properties");
		this.preferences = new Preferences(getClass().getResourceAsStream(
				propertyPath));
	}

	private void setModules(ATermList importList) {
		moduleModel.clearModules();

		while (!importList.isEmpty()) {
			ATermList importPair = (ATermList) importList.getFirst();
			importList = importList.getNext();
			ATermAppl moduleTerm = (ATermAppl) importPair.getFirst();
			String name = moduleTerm.getName();
			addModule(name);
		}
	}

	private Module addModule(String name) {
		Module module = moduleModel.getModule(name);
		if (module == null) {
			module = new Module(name);
			moduleModel.addModule(module);
		}

		return module;
	}

	private void setImports(ATermList importList) {

		while (!importList.isEmpty()) {
			ATermList importPair = (ATermList) importList.getFirst();
			importList = importList.getNext();

			ATermAppl fromTerm = (ATermAppl) importPair.getFirst();
			String from = fromTerm.getName();
			Module moduleFrom = moduleModel.getModule(from);
			if (moduleFrom == null) {
				moduleFrom = addModule(from);
				moduleFrom.setState(Module.STATE_NEW);
			}

			ATermList imports = (ATermList) importPair.elementAt(1);

			while (!imports.isEmpty()) {
				ATermAppl toTerm = (ATermAppl) imports.getFirst();
				imports = imports.getNext();

				String to = toTerm.getName();
				Module moduleTo = moduleModel.getModule(to);
				if (moduleTo == null) {
					moduleTo = addModule(to);
					moduleTo.setState(Module.STATE_NEW);
				}

				moduleFrom.addChild(to);
				moduleTo.addParent(from);
			}
		}
	}

	public void setModules(ATerm termList) {
		ATermList modules = (ATermList) termList;
		setModules(modules);
		setImports(modules);
	}

	public void postPopupRequest(Module module) {
		ATermFactory factory = studio.getFactory();
		ATerm popup = factory.parse("module-popup");

		if (module.getState() == Module.STATE_NEW) {
			popup = factory.parse("new-module-popup");
		}

		bridge.postEvent(factory.make("request-popup-event(<term>,<str>)",
				popup, module.getName()));
	}

	public void addEvents(ATerm t0, String s1, ATerm t2) {
		popup.addEvents(t0, s1, t2);
	}

	public void recAckEvent(ATerm t0) {

	}

	public void recTerminate(ATerm t0) {
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		bridge = new NavigatorBridge(studio.getFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);

		createModel();
		addNavigatorComponent();
		addImportHierarchyComponent();
		
		popup = new ModulePopupMenu(studio.getFactory(), bridge);
	}

	private void createModel() {
		moduleModel = new ModuleTreeModel();
		moduleModel.addModuleSelectionListener(new ModuleSelectionListener() {
			public void moduleSelected(Module module) {
				if (!suspendSelectionNotification) {
					String name = module != null ? module.toString() : "";
					bridge.postEvent(studio.getFactory().make(
							"module-selected(<str>)", name));
				}
			}
		});
	}

	private void addNavigatorComponent() {
		final ModuleTree tree = new ModuleTree(studio.getFactory(), this,
				moduleModel);
		studio.addComponent(new AbstractStudioComponent() {
			public String getName() {
				return "Navigator";
			}

			public JComponent getViewComponent() {
				return tree;
			}

			public JMenu getMenu() {
				return null;
			}

			public String getStatusMessage() {
				return null;
			}

		});
	}

	private void addImportHierarchyComponent() {
		final ImportHierarchyPanel panel = new ImportHierarchyPanel(
				moduleModel, preferences);
		moduleModel.addModuleSelectionListener(new ModuleSelectionListener() {
			public void moduleSelected(Module module) {
				panel.setHierarchy(module);
			}
		});
		studio.addComponent(new AbstractStudioComponent() {
			public String getName() {
				return "Import Hierarchy";
			}

			public JComponent getViewComponent() {
				return panel;
			}

			public JMenu getMenu() {
				return null;
			}

			public String getStatusMessage() {
				return null;
			}

		});
	}

	public void selectModule(String moduleName) {
		suspendSelectionNotification = true;
		moduleModel.selectModule(moduleName);
		suspendSelectionNotification = false;
	}

}
