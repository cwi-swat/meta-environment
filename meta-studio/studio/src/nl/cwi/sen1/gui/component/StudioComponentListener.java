package nl.cwi.sen1.gui.component;

import java.util.EventListener;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.StatusMessageEvent;

public interface StudioComponentListener extends EventListener {
    public void statusMessageChanged(StatusMessageEvent event);

    public void componentRequestClose() throws CloseAbortedException;
    
    public void componentClose();
    
    public void componentFocusReceived();
}
