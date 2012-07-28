package nl.cwi.sen1.gui.plugin;

import javax.swing.event.EventListenerList;

/**
 * A default implementation of a StudioPlugin for your convenience.
 * This class simply provides the implementation of the Observer
 * design pattern already. The other methods of StudioPlugin need
 * still to be implemented.
 */
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
