package nl.cwi.sen1.gui;

import javax.swing.Icon;
import javax.swing.JComponent;

public interface StudioComponent {
	public String getName();

	public Icon getIcon();
	
	public JComponent getViewComponent();

	public String getStatusMessage();

	public void addStudioComponentListener(StudioComponentListener l);

	public void removeStudioComponentListener(StudioComponentListener l);
    
    public void requestClose() throws CloseAbortedException;
    
    public void close();
}
