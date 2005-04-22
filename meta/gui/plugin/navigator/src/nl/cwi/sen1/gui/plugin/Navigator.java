package nl.cwi.sen1.gui.plugin;

import java.awt.event.MouseEvent;

import javax.swing.JComponent;
import javax.swing.JMenu;

import nl.cwi.sen1.data.Module;
import nl.cwi.sen1.data.ModuleSelectionListener;
import nl.cwi.sen1.data.ModuleTreeModel;
import nl.cwi.sen1.gui.AbstractStudioComponent;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioPlugin;
import nl.cwi.sen1.util.PopupHandler;
import nl.cwi.sen1.util.PopupMenu;
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

	private Studio studio;

	// TODO: use preferences
	private Preferences preferences;

	private boolean suspendSelectionNotification;

	private MouseEvent popupEvent;

	private AbstractStudioComponent navigatorComponent;

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

	public void postPopupRequest(MouseEvent e, Module module) {
		popupEvent = e;
		ATermFactory factory = studio.getFactory();
		String moduleId = module.getName();
		bridge.postEvent(factory.make("request-popup-event(<str>)", moduleId));
	}

	public void showPopup(final String id, ATerm menu) {
		PopupMenu popup = new PopupMenu((ATermList) menu);
		popup.setPopupHandler(new PopupHandler() {
			public void popupSelected(ATerm action) {
				bridge.postEvent(studio.getFactory().make(
						"popup-menu-event(<str>,<term>)", id, action));
			}

		});
		popup.show(popupEvent.getComponent(), popupEvent.getX(), popupEvent
				.getY());
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
	}

	private void createModel() {
		moduleModel = new ModuleTreeModel();
		moduleModel.addModuleSelectionListener(new ModuleSelectionListener() {
			public void moduleSelected(Module module) {
				if (!suspendSelectionNotification) {
					String name = module != null ? module.toString() : "";
					navigatorComponent.setStatusMessage(name);
					bridge.postEvent(studio.getFactory().make(
							"module-selected(<str>)", name));
				}
			}
		});
	}

	private void addNavigatorComponent() {
		final ModuleTree tree = new ModuleTree(studio.getFactory(), this,
				moduleModel);
		studio.addComponent(createNavigatorComponent(tree));
	}

	private AbstractStudioComponent createNavigatorComponent(final ModuleTree tree) {
		navigatorComponent = new AbstractStudioComponent() {
			public String getName() {
				return "Navigator";
			}

			public JComponent getViewComponent() {
				return tree;
			}

			public JMenu getMenu() {
				return null;
			}
		};
		return navigatorComponent;
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
				return "Import Hierarchy status";
			}

		});
	}

	public void selectModule(String moduleName) {
		suspendSelectionNotification = true;
		moduleModel.selectModule(moduleName);
		suspendSelectionNotification = false;
	}

}
