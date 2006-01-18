package nl.cwi.sen1.gui.plugin;

import java.awt.event.MouseEvent;

public interface GraphPanelListener {
	public void nodeSelected(String nodeId);
	public void popupRequested(String nodeId, MouseEvent e);
}
