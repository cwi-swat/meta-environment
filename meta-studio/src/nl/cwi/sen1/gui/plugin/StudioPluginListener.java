package nl.cwi.sen1.gui.plugin;

import java.util.EventListener;


public interface StudioPluginListener extends EventListener {
	public void studioPluginClosed(StudioPlugin plugin);
}
