package nl.cwi.sen1.gui.plugin;

import nl.cwi.sen1.gui.Studio;

/**
 * A plugin for the MetaStudio. A plugin is a program that is dynamically
 * loaded into the MetaStudio, and runs in its own thread. The thread is
 * started with a call to @see #initStudioPlugin(Studio studio). 
 */
public interface StudioPlugin {
  /** 
   * Get the name of a plugin. This is used to construct proper names
   * of threads and to construct meaningfull error messages. Pick a unique
   * name.
   * @return The name of a plugin.
   */
  public String getName();

  /**
   * The main method of a plugin. This method is provided a reference to
   * the toplevel window, and the ToolBus, via the @see Studio interface.
   * @param studio Reference to functionality of the toplevel window.
   */
  public void initStudioPlugin(Studio studio);

  /**
   * Register a listener. The Studio listens to important events from all
   * plugins. The functionality of the whole Studio may break if the
   * observer pattern is not implemented correctly here. 
   * @see DefaultStudioPlugin provides a default implementation.
   * @param l An implementation of a listener (usually the studio itself).
   */ 
  public void addStudioPluginListener(StudioPluginListener l);

  /**
   * Unregister a listener.
   * @param l Listener to be unregistered.
   */
  public void removeStudioPluginListener(StudioPluginListener l);
}
