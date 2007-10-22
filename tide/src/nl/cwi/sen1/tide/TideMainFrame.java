package nl.cwi.sen1.tide;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;

public class TideMainFrame extends DefaultStudioPlugin {
	
	public void initStudioPlugin(Studio studio) {
		new TideControl(studio, this);
	}

	public String getName() {
		return "TIDE";
	}

	public void closeTide() {
		fireStudioPluginClosed();
	}
}
