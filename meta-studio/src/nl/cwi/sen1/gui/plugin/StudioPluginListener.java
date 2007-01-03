package nl.cwi.sen1.gui.plugin;

import java.util.EventListener;

/**
 * Observer design for the Studio listening to events from plugins.
 */
public interface StudioPluginListener extends EventListener {
  /**
   * When a plugin decides to exit/quit/stop running, the Studio
   * must be notified.
   */
  public void studioPluginClosed(StudioPlugin plugin);
}
