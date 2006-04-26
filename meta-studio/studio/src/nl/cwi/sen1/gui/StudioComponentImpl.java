package nl.cwi.sen1.gui;

import javax.swing.Icon;
import javax.swing.JComponent;
import javax.swing.event.EventListenerList;

public class StudioComponentImpl implements StudioComponent {
    private Icon icon;

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

    public void setName(String name) {
        this.name = name;
        fireNameChangedEvent();
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
                ((StudioComponentListener) listeners[i + 1]).componentClose();
            }
        }
    }

    protected void fireComponentFocusReceived() {
        Object[] listeners = listenerList.getListenerList();
        for (int i = listeners.length - 2; i >= 0; i -= 2) {
            if (listeners[i] == StudioComponentListener.class) {
                ((StudioComponentListener) listeners[i + 1])
                        .componentFocusReceived();
            }
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

    public void receiveFocus() {
        fireComponentFocusReceived();
    }

    public JComponent[] getStatusBarComponents() {
        return new JComponent[] {};
    }

    public void addNameChangedListener(NameChangedListener l) {
        listenerList.add(NameChangedListener.class, l);
    }

    public void removeNameChangedListener(NameChangedListener l) {
        listenerList.remove(NameChangedListener.class, l);
    }

    public void fireNameChangedEvent() {
        Object[] listeners = listenerList.getListenerList();
        for (int i = listeners.length - 2; i >= 0; i -= 2) {
            if (listeners[i] == NameChangedListener.class) {
                ((NameChangedListener) listeners[i + 1])
                        .componentNameChanged();
            }
        }
    }

}