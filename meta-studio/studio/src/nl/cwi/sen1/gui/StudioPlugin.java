package nl.cwi.sen1.gui;

public interface StudioPlugin {
	public String getName();
	public void initStudioPlugin(Studio studio);
	public void addStudioPluginListener(StudioPluginListener l);
	public void removeStudioPluginListener(StudioPluginListener l);
}
