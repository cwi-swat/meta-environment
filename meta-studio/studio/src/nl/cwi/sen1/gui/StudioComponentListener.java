package nl.cwi.sen1.gui;

import java.util.EventListener;

public interface StudioComponentListener extends EventListener {
	public void statusMessageChanged(StatusMessageEvent event);
    
    public void componentRequestClose() throws CloseAbortedException;
    
    public void componentClose();
}
