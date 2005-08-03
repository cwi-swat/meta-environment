package nl.cwi.sen1.gui;

import javax.swing.Icon;
import javax.swing.JComponent;
import javax.swing.event.EventListenerList;

public class StudioComponentImpl implements StudioComponent {
    private Icon icon;

    private String statusMessage;

    private EventListenerList listenerList = new EventListenerList();

    private String name;

    private JComponent viewComponent;

    public StudioComponentImpl(String name, JComponent viewComponent) {
        this.name = name;
        this.viewComponent = viewComponent;
    }

    public String getName() {
        return name;
    }

    public JComponent getViewComponent() {
        return viewComponent;
    }

    public void addStudioComponentListener(StudioComponentListener l) {
        listenerList.add(StudioComponentListener.class, l);
    }

    public void removeStudioComponentListener(StudioComponentListener l) {
        listenerList.remove(StudioComponentListener.class, l);
    }

    // Take from javax.swing.event.EventListenerList example
    protected void fireStatusMessageChanged(String oldMessage, String newMessage) {
        StatusMessageEvent event = new StatusMessageEvent(this, oldMessage,
                newMessage);
        Object[] listeners = listenerList.getListenerList();
        for (int i = listeners.length - 2; i >= 0; i -= 2) {
            if (listeners[i] == StudioComponentListener.class) {
                ((StudioComponentListener) listeners[i + 1])
                        .statusMessageChanged(event);
            }
        }
    }

    protected void fireComponentRequestClose() throws CloseAbortedException {
        Object[] listeners = listenerList.getListenerList();
        for (int i = listeners.length - 2; i >= 0; i -= 2) {
            if (listeners[i] == StudioComponentListener.class) {
                ((StudioComponentListener) listeners[i + 1])
                        .componentRequestClose();
            }
        }
    }

    protected void fireComponentClose() {
        Object[] listeners = listenerList.getListenerList();
        for (int i = listeners.length - 2; i >= 0; i -= 2) {
            if (listeners[i] == StudioComponentListener.class) {
                ((StudioComponentListener) listeners[i + 1])
                        .componentClose();
            }
        }
    }
    
    public String getStatusMessage() {
        return statusMessage;
    }

    public void setStatusMessage(String newMessage) {
        String oldMessage = statusMessage;
        statusMessage = newMessage;
        if (newMessage == null || !newMessage.equals(oldMessage)) {
            fireStatusMessageChanged(oldMessage, newMessage);
        }
    }

    public Icon getIcon() {
        return icon;
    }

    public void setIcon(Icon icon) {
        this.icon = icon;
    }

    public void requestClose() throws CloseAbortedException {
        fireComponentRequestClose();
    }
    
    public void close() {
        fireComponentClose();
    }
}