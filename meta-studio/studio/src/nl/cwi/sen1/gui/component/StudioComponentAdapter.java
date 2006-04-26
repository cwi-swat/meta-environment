package nl.cwi.sen1.gui.component;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.StatusMessageEvent;

public abstract class StudioComponentAdapter implements StudioComponentListener {
    public StudioComponentAdapter() {
    }

    public void statusMessageChanged(StatusMessageEvent event) {
    }

    public void componentRequestClose() throws CloseAbortedException {
    }

    public void componentClose() {
    }
    
    public void componentFocusReceived() {
    }
}
