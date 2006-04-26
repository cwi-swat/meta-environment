package nl.cwi.sen1.gui.component;

import nl.cwi.sen1.gui.CloseAbortedException;

public abstract class StudioComponentAdapter implements StudioComponentListener {
    public StudioComponentAdapter() {
    }

    public void componentRequestClose() throws CloseAbortedException {
    }

    public void componentClose() {
    }
    
    public void componentFocusReceived() {
    }
}
