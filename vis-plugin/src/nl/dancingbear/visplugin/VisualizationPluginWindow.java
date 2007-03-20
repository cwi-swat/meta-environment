package nl.dancingbear.visplugin;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.Location;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.dancingbear.visplugin.screenshotmaker.ScreenshotMaker;

/**
 * The VisualizationPluginWindow class represents the base class for the
 * different plugin windows.
 *
 * @author Aldert Boerhoop
 * @date 20-2-2007
 */
public abstract class VisualizationPluginWindow {

    protected Factory m_factory;

    private Studio m_studio;
    private int m_storeId;
    private int m_factId;
    private RTuple m_fact;
    private String m_title;
    private VisualizationPluginController m_controller;
    private int m_windowId;
    private ContainerPanel m_containerPanel=null;


    /**
     * Default constructor
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     */
    public VisualizationPluginWindow() {
    }

    /**
     * Initialize the window properties
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @param Studio studio, int storeId, int factId, RTuple fact
     */
    public final void initializeWindow(Studio studio, int storeId, int factId,
            RTuple fact, Factory factory, String pluginName,
            VisualizationPluginController controller, int windowId) {
        m_studio = studio;
        m_storeId = storeId;
        m_factId = factId;
        m_fact = fact;
        m_factory = factory;
        m_title = pluginName + "=>" + fact.getRtype().toString();
        m_controller = controller;
        m_windowId = windowId;
    }

    /**
     * Returns the studio of the visualization plugin window.
     *
     * @return The studio object.
     *
     * @author Arend van Beelen
     * @date 13-3-2007
     */
    public Studio getStudio() {
        return m_studio;
    }

    /**
     * method is called on load of the window overridable 
     *
     * @author Aldert Boerhoop
     * @date 16-3-2007
     * @param the filename to store the export in
     */
    public void executeOnLoad() {

    }


    /**
     * Returns the controller of the visualization plugin window.
     *
     * @return The controller object.
     * @author Arend van Beelen
     * @date 13-3-2007
     */
    public VisualizationPluginController getController() {
        return m_controller;
    }

    /**
     * Returns the window ID of the visualization plugin window.
     *
     * @return The window ID.
     * @author Arend van Beelen
     * @date 13-3-2007
     */
    public int getWindowId() {
        return m_windowId;
    }

    /**
     * Display the plugin window
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     */
    public final void displayVisualization() {
        // create a content panel on the right with menu bar
        JPanel contentPanel = render(m_fact);
        JMenu extensionMenu = createExtensionMenu();

        connectPanelWithMenu(extensionMenu, contentPanel, m_title,
                StudioImplWithPredefinedLayout.TOP_RIGHT);
    }

    /**
     * Create a menu
     *
     * @author Arjen van Schie & Michel Rijnders
     * @date 20-2-2007
     * @return The JMenu
     */
    protected JMenu createExtensionMenu() {
        // create the menu item
        JMenu extensionMenu = new JMenu("Visualization");

        // create the sub-item Export
        JMenuItem export = new JMenuItem("Export to image");
        export.addActionListener(new AbstractAction() {
            public void actionPerformed(ActionEvent e) {
                m_controller.exportToClicked(
                        VisualizationPluginController.requestType.image,
                        m_windowId);
            }

            private final static long serialVersionUID = 1;
        });
        extensionMenu.add(export);

        return extensionMenu;
    }


    /**
     * calls the exportToClicked method on the controller 
     *
     * @author Aldert Boerhoop
     * @date 16-3-2007
     */
    public final void exportToCsvClicked(){

        m_controller.exportToClicked(VisualizationPluginController.requestType.csv, m_windowId);
    }

    /**
     * method is called from the toolbus
     *
     * @author Aldert Boerhoop
     * @date 16-3-2007
     * @param the filename to store the export in
     */
    protected void exportToCsv(String fileName){}

    /**
     * Show a popup
     *
     * @author Arjen van Schie & Michel Rijnders
     * @date 20-2-2007
     * @param Message
     *            to display
     */
    public final void showPopUp(String msg) {
        JOptionPane.showMessageDialog(m_containerPanel, msg);
    }

    /**
     * connects a given JPanel and JMenu to the meta-environment
     *
     * @author Arjen van Schie & Michel Rijnders
     * @date 20-2-2007
     * @param JMenu menu,JPanel contentPanel,String title,String orientation
     */
    private final void connectPanelWithMenu(JMenu menu, JPanel contentPanel,
            String title, String orientation) {
        if (contentPanel != null) {
            // generate a container panel ( this is a panel with a
            // hidden warningpanel and the given content panel)
            m_containerPanel = new ContainerPanel(contentPanel);

            // generate the meta-studio component from the default
            // implementation
            StudioComponent component = new StudioComponentImpl(title, m_containerPanel);

            VisualizationWindowListener tempListener = new VisualizationWindowListener(this, component);
            component.addStudioComponentListener(tempListener);

            // add the component to the studio
            ((StudioWithPredefinedLayout) m_studio).addComponent(component,
                    orientation);

            // add the menu (if there is any)
            if (menu != null) {
                m_studio.addComponentMenu(component, menu);
            }
        }
    }
    
    /**
     * Removes a component from the Meta-Environment so it is removed from the
     * views menu as well.
     * 
     * @param component The component to remove.
     * 
     * @author Arend van Beelen
     * @author Anton Gerdesse
     * @date 19-03-2007
     */
    public void disconnectComponent(StudioComponent component) {
        m_studio.removeComponent(component);
    }

    /**
     * Show out of date message
     *
     * @author Aldert Boerhoop
     * @author Arjen van Schie
     * @date 20-2-2007
     */
    public final void factOutOfDate() {
        m_containerPanel.showRstoreChangedWarning();
    }

    /**
     * The rstore of this fact has been unloaded.
     *
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @author Arjen van Schie
     * @date 14-03-2007
     */
    public final void rstoreUnloaded() {
        m_containerPanel.showRstoreUnloadedWarning();
    }

    /**
     * get the Store id
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @return The Store id
     */
    public final int getStoreId() {
        return m_storeId;
    }

    /**
     * get the Fact id
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @return The Fact id
     */
    public final int getFactId() {
        return m_factId;
    }

    /**
     * Render the plugin window
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @param Fact
     *            to display
     * @return The JPanel
     */
    public abstract JPanel render(RTuple fact);

    /**
     * Functionality that's triggered by the export menu
     *
     * @author Aldert Boerhoop
     * @date 9-3-2007
     */
    public void exportToImage(String fileName) {
        ScreenshotMaker.saveScreenshot(m_containerPanel.getContentPanel(), fileName,
                ScreenshotMaker.DEFAULT_EXTENSION);
    }

    public void openLocationInEditor(Location loc) {
        m_controller.openLocationInEditor(loc);
    }
}
