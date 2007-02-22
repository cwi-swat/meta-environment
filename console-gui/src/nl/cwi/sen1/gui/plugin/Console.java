package nl.cwi.sen1.gui.plugin;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.gui.plugin.console.ConsolePanel;
import aterm.ATerm;

public class Console extends DefaultStudioPlugin implements ConsoleTif {
	private static final String TOOL_NAME = "console";

	private ConsoleBridge bridge;

	private ConsolePanel panel;

	public Console() {
	}

	public void initStudioPlugin(Studio studio) {
		panel = new ConsolePanel();

		bridge = new ConsoleBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);

		StudioComponent comp = new StudioComponentImpl("Console", panel) {
			public void requestClose() throws CloseAbortedException {
				throw new CloseAbortedException();
			}
		};
		studio.connect(getName(), bridge);
		((StudioWithPredefinedLayout) studio).addComponent(comp,
				StudioImplWithPredefinedLayout.BOTTOM_RIGHT);
	}

	public void addMessage(String message) {
		panel.addMessage(message);
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();
	}
}
