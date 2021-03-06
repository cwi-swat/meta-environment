package nl.cwi.sen1.gui.component;

import javax.swing.Icon;
import javax.swing.JComponent;
import javax.swing.event.EventListenerList;

import nl.cwi.sen1.gui.CloseAbortedException;

/**
 * A default implementation of a StudioComponent. This is the starting
 * point for any StudioComponent. This convience class wraps a JComponent,
 * and implements the default behavior for the StudioComponent interface.
 */
public class StudioComponentImpl implements StudioComponent {
    private Icon icon;

    private EventListenerList listenerList = new EventListenerList();

    private String name;

    private String tooltip;
    
    private JComponent viewComponent;

    /**
     * Construct a new component.
     * @param name the name of the component (for a tab label).
     * @param viewComponent the Swing component to show in the tab.
     */
    public StudioComponentImpl(String name, JComponent viewComponent) {
        this.name = name;
        this.viewComponent = viewComponent;
    }
    
    public StudioComponentImpl(String name, JComponent viewComonent, String tooltip) {
    	this.name = name;
    	this.viewComponent = viewComonent;
    	this.tooltip = tooltip;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
        fireNameChangedEvent();
    }
    
    public String getTooltip() {
    	return tooltip;
    }
    
    public void setTooltip(String tooltip) {
    	this.tooltip = tooltip;
    	fireTooltipChangedEvent();
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

	public void addTooltipChangedListener(TooltipChangedListener l) {
        listenerList.add(TooltipChangedListener.class, l);
	}

	public void removeTooltipChangedListener(TooltipChangedListener l) {
        listenerList.remove(TooltipChangedListener.class, l);
	}

	public void fireTooltipChangedEvent() {
        Object[] listeners = listenerList.getListenerList();
        for (int i = listeners.length - 2; i >= 0; i -= 2) {
            if (listeners[i] == TooltipChangedListener.class) {
                ((TooltipChangedListener) listeners[i + 1])
                        .componentTooltipChanged();
            }
        }
    }

}
