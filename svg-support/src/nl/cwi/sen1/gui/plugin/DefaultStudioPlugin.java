package nl.cwi.sen1.gui.plugin;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.gui.plugin.subclass.DefaultStudioPluginPanel;
import aterm.ATerm;

public class DefaultStudioPlugin extends DefaultStudioPlugin implements DefaultStudioPluginTif {
	private static final String TOOL_NAME = "default-studio-plugin";

	private DefaultStudioPluginBridge bridge;

	private DefaultStudioPluginPanel panel;

	public DefaultStudioPlugin() {
	}

	public void initStudioPlugin(Studio studio) {
		panel = new DefaultStudioPluginPanel();

		bridge = new DefaultStudioPluginBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);

		StudioComponent comp = new StudioComponentImpl("DefaultStudioPlugin", panel) {
			public void requestClose() throws CloseAbortedException {
				throw new CloseAbortedException();
			}
		};
		studio.connect(getName(), bridge);
		((StudioWithPredefinedLayout) studio).addComponent(comp,
				StudioImplWithPredefinedLayout.BOTTOM_RIGHT);
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();
	}
}
