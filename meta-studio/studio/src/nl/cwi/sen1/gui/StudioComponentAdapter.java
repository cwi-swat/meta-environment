package nl.cwi.sen1.gui;

public abstract class StudioComponentAdapter implements StudioComponentListener {
    public StudioComponentAdapter() {
    }

    public void statusMessageChanged(StatusMessageEvent event) {
    }

    public void componentRequestClose() throws CloseAbortedException {
    }

    public void componentClose() {
    }
    
    
}
