package nl.cwi.sen1.gui;

import javax.swing.Icon;
import javax.swing.JComponent;
import javax.swing.JMenu;

public interface StudioComponent {
	public String getName();

	public JComponent getViewComponent();

	public JMenu[] getMenus();

	public String getStatusMessage();

	public void addStudioComponentListener(StudioComponentListener l);

	public void removeStudioComponentListener(StudioComponentListener l);

	public Icon getIcon();
}
