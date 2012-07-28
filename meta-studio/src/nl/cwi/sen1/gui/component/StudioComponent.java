package nl.cwi.sen1.gui.component;

import javax.swing.Icon;
import javax.swing.JComponent;

import nl.cwi.sen1.gui.CloseAbortedException;

/** 
 * The (visual) interface to a tab (window) that is hosted in a MetaStudio.
 */
public interface StudioComponent {
  /**
   * The name is used to construct labels of tabs.
   * @return the label of a tab.
   */
  public String getName();

  /**
   * The name can be changed.
   * @param name new name for this component.
   */
  public void setName(String name);

  /**
   * The tooltip is used to show when hovering the mouse over tabs.
   * @return the tooltip of a tab.
   */
  public String getTooltip();

  /**
   * The tooltip can be changed.
   * @param tooltip new tooltip for this component.
   */
  public void setTooltip(String tooltip);
  
  /**
   * Tabs can be labelled with small icons too.
   * @return an icon to be used by the Studio
   */
  public Icon getIcon();

  /**
   * The bridge to Swing is made here. The returned JComponent
   * will fill exactly one tab. Any JComponent will do.
   */
  public JComponent getViewComponent();

  /** 
   * Register a listener (usually the plugin that this Component belongs
   * to, and the MetaStudio).
   * The studio and the plugin listen to important changes in the state 
   * of a component. This may be used to implement window management, by
   * the plugin, or by the Studio.
   * @param l the listener to register.
   */
  public void addStudioComponentListener(StudioComponentListener l);

  /**
   * Unregister a listener.
   */
  public void removeStudioComponentListener(StudioComponentListener l);

  /**
   * Request to close the window. The controls on a tab window are implemented
   * by the @see MetaStudio. If a user clicks the close icon on a tab, the
   * component will be notified using this method. This gives the component
   * the chance to save resources, or start save/cancel dialogs if necessary.
   * @throws CloseAbortedException if the component can not be closed (for example when the user chooses to cancel.
   */
  public void requestClose() throws CloseAbortedException;

  /**
   * Closes a component. This makes the component invisible immediately.
   */
  public void close();

  /**
   * Receive the focus. When a component receives the focus, there is
   * sometimes something to do, like reset or set the focus to a particular
   * part of the component.
   */
  public void receiveFocus();

  /**
   * The MetaStudio has a status bar at the bottom. When a component receives
   * the focus, the status bar will show the returned JComponents from
   * left to right in a certain part of the status bar.
   * @return an array of JComponents to show in the status bar.
   */ 
  public JComponent[] getStatusBarComponents();

  /**
   * Register a NameChangedListener. If a tab wants to change its name, it
   * should notify all NameChangedListeners. The MetaStudio itself uses it
   * to update the label on the tab.
   */
  public void addNameChangedListener(NameChangedListener l);

  /**
   * Unregister a NameChangedListener.
   */
  public void removeNameChangedListener(NameChangedListener l);
  
  /**
   * Register a TooltipChangedListener. If a tab wants to change its tooltip, it
   * should notify all TooltipChangedListeners. The MetaStudio itself uses it
   * to update the tooltip off the tab.
   */
  public void addTooltipChangedListener(TooltipChangedListener l);

  /**
   * Unregister a TooltipChangedListener.
   */
  public void removeTooltipChangedListener(TooltipChangedListener l);
  
}
