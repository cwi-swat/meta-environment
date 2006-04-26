package nl.cwi.sen1.gui;

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
