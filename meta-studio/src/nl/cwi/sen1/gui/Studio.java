package nl.cwi.sen1.gui;

import javax.swing.Action;
import javax.swing.JMenu;

import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.gui.component.StudioComponent;
import toolbus.AbstractTool;
import aterm.ATermFactory;

/**
 * The interface to the toplevel studio window.
 * The Studio interface provides StudioPlugins with functionality
 * for modifying properties of the toplevel window of a MetaStudio,
 * as well as some convenience methods (functionality that is needed
 * by virtually all StudioPlugins). 
 */
public interface Studio {
    /**
     * Get 'The' ATermFactory. For memory efficiency it is beneficial
     * to share a single ATermFactory between all StudioPlugins. If ATerms
     * are communicated between them, this is also a requirement.
     *
     * @return A reference to The ATerm Factory.
     */
    public ATermFactory getATermFactory();

    /**
     * Connect to the ToolBus. Many StudioPlugins will have their private
     * connection to the ToolBus. This is the method to start it up. Note
     * that a single plugin may use this method several times.
     *
     * @param toolName Name of the tool as it occurs in the ToolBus script.
     * @param tool     Java implementation of a ToolBus tool.
     */ 
    public void connect(String toolName, AbstractTool tool);

    /**
     * Register a StudioComponent. One StudioComponent corresponds to a
     * single 'tab' somewhere in the GUI framework of the MetaStudio. The
     * component will become immediately visible.
     *
     * @param component Component to add.
     */
    public void addComponent(StudioComponent component);

    /**
     * Unregister a StudioComponent. This is the inverse of addComponent.
     * The component will become invisible immediately.
     *
     * @param component Component to remove.
     */ 
    public void removeComponent(StudioComponent component);

    /**
     * Register a menu that is linked with a particular component. The
     * studio manages menus, such that the menus for a particular component
     * are visible if and only if that component has the focus.
     *
     * @param component Component to link a menu with.
     * @param menu      JMenu to link to a component.
     */
    public void addComponentMenu(StudioComponent component, JMenu menu);

    /**
     * Register a menu that is linked with a particular component. The
     * studio manages menus, such that the menus for a particular component
     * are visible if and only if that component has the focus. 
     */
    public void addComponentMenu(StudioComponent component, Event menu,
            Action action);

    /**
     * Make the Studio move the focus to a specific Component.
     * @param component Component to move the focus to.
     */
    public void requestFocus(StudioComponent component);
}
