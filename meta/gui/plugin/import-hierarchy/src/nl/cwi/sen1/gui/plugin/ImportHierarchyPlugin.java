package nl.cwi.sen1.gui.plugin;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioPlugin;
import nl.cwi.sen1.util.Preferences;
import aterm.ATerm;

public class ImportHierarchyPlugin implements StudioPlugin, ImportHierarchyTif {
	private static final String TOOL_NAME = "import-hierarchy";

	private static final String RESOURCE_DIR = "/resources";

	private Studio studio;

	private ImportHierarchyBridge bridge;

	private Preferences preferences;

	private ImportHierarchyPanel panel;

	public ImportHierarchyPlugin() {
		String propertyPath = new String(RESOURCE_DIR + '/' + TOOL_NAME
				+ ".properties");
		this.preferences = new Preferences(getClass().getResourceAsStream(
				propertyPath));
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		bridge = new ImportHierarchyBridge(studio.getFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
		addGUI(studio);
	}

	private void addGUI(Studio studio) {
		panel = new ImportHierarchyPanel(preferences);
		panel.setName("Import Hierarchy");
		studio.addComponent(panel);
	}

	public void setHierarchy(String module, ATerm importList,
			ATerm importedByList) {
//		panel.setHierarchy(module);
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
	}

}
