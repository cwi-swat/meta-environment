package nl.cwi.sen1.gui.component;

import java.util.EventListener;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.StatusMessageEvent;

/** 
 * Events from a StudioComponent for the MetaStudio to react to.
 */
public interface StudioComponentListener extends EventListener {
    /**
     * The Status bar contains a tab for a status string. With this
     * event a component may set the status string to a new string.
     */  
    public void statusMessageChanged(StatusMessageEvent event);

    public void componentRequestClose() throws CloseAbortedException;
    
    public void componentClose();
    
    public void componentFocusReceived();
}
