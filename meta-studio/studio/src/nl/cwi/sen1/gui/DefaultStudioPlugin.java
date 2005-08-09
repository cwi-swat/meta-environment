package nl.cwi.sen1.gui;

import javax.swing.event.EventListenerList;

public abstract class DefaultStudioPlugin implements StudioPlugin {
	private EventListenerList listenerList = new EventListenerList();
	
	public void addStudioPluginListener(StudioPluginListener l) {
        listenerList.add(StudioPluginListener.class, l);
    }

    public void removeStudioPluginListener(StudioPluginListener l) {
        listenerList.remove(StudioPluginListener.class, l);
    }
    
    protected void fireStudioPluginClosed() {
        Object[] listeners = listenerList.getListenerList();
        for (int i = listeners.length - 2; i >= 0; i -= 2) {
            if (listeners[i] == StudioPluginListener.class) {
                ((StudioPluginListener) listeners[i + 1])
                        .studioPluginClosed(this);
            }
        }
    }
}
