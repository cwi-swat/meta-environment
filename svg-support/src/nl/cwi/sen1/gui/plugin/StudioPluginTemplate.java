package nl.cwi.sen1.gui.plugin;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.gui.plugin.subclass.StudioPluginTemplatePanel;
import aterm.ATerm;

public class StudioPluginTemplate extends StudioPluginTemplate implements StudioPluginTemplateTif {
	private static final String TOOL_NAME = "studio-plugin-template";

	private StudioPluginTemplateBridge bridge;

	private StudioPluginTemplatePanel panel;

	public StudioPluginTemplate() {
	}

	public void initStudioPlugin(Studio studio) {
		panel = new StudioPluginTemplatePanel();

		bridge = new StudioPluginTemplateBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);

		StudioComponent comp = new StudioComponentImpl("StudioPluginTemplate", panel) {
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
