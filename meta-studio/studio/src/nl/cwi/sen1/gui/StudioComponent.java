package nl.cwi.sen1.gui;

import javax.swing.Icon;
import javax.swing.JComponent;

public interface StudioComponent {
	public String getName();

    public void setName(String name);
    
	public Icon getIcon();
	
	public JComponent getViewComponent();

	public void addStudioComponentListener(StudioComponentListener l);

	public void removeStudioComponentListener(StudioComponentListener l);
    
    public void requestClose() throws CloseAbortedException;
    
    public void close();
    
    public void receiveFocus();

    public JComponent[] getStatusBarComponents();

    public void addNameChangedListener(NameChangedListener l);

    public void removeNameChangedListener(NameChangedListener l);
}
