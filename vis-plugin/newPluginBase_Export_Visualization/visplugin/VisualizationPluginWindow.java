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
 * The VisualizationPluginWindow class represents the base class for the different plugin windows.
 * @author  Aldert Boerhoop
 * @date    20-2-2007
 */
public abstract class VisualizationPluginWindow{	
    private Studio m_studio;
    private int m_storeId;
    private int m_factId;
    private RTuple m_fact;
    protected Factory m_factory;
    private String m_title;
    private VisualizationPluginController m_controller;
    private int m_windowId;
    private JPanel m_contentPanel;
    private ExportProvider[] m_exportProviders;
    
    private ExportProvider m_currentExportProvider;
 

  /**
   * Default constructor
   * @author  Aldert Boerhoop
   * @date    20-2-2007
   */
    public VisualizationPluginWindow(){}

    /**
     * Initialize the window properties
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @param   Studio studio, int storeId, int factId, RTuple fact
     */
    public final void initializeWindow(Studio studio, int storeId, int factId, RTuple fact, Factory factory, String pluginName, VisualizationPluginController controller, int windowId, ExportProvider[] exportProviders) {
        m_studio = studio;
        m_storeId = storeId;
        m_factId = factId;
        m_fact = fact;
        m_factory = factory;
        m_title = pluginName + "=>" + fact.getRtype().toString();
        m_controller = controller;
        m_windowId = windowId;
        m_exportProviders = exportProviders;
    }
    
    /**
     * Display the plugin window
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     */
    public final void displayVisualization() {
        // Create a content panel on the right with menu bar
        m_contentPanel = render(m_fact);
        JMenu extensionMenu = createExtensionMenu();

        connectPanelWithMenu(extensionMenu, m_contentPanel, m_title, StudioImplWithPredefinedLayout.TOP_RIGHT);
    }

    /**
     * Create a menu
     * @author  Arjen van Schie & Michel Rijnders
     * @date    20-2-2007
     * @return  The JMenu
     */
    private final JMenu createExtensionMenu() {
        JMenu extensionMenu = new JMenu("Visualization");

        for(int i=0; i < m_exportProviders.length; i++){
        
        	m_currentExportProvider = m_exportProviders[i];
        	
        	JMenuItem tempItem = new JMenuItem(m_currentExportProvider.getMenuOptionName());
        	
        	tempItem.addActionListener(
                    
        			new AbstractAction() {
                    	
                        public void actionPerformed(ActionEvent e) {
                      
                          	m_controller.exportToClicked(m_contentPanel, m_currentExportProvider, m_windowId);
                        }
                        
                        private final static long serialVersionUID = 1;
                    });
            
            extensionMenu.add(tempItem);
        }

        return extensionMenu;
    }


    /**
     * Show a popup
     * @author  Arjen van Schie & Michel Rijnders
     * @date    20-2-2007
     * @param   Message to display
     */
    public final void showPopUp(String msg) {
        JOptionPane.showMessageDialog( null,msg);
    }

    /**
     * connects a given JPanel and JMenu to the meta-environment
     * @author  Arjen van Schie & Michel Rijnders
     * @date    20-2-2007
     * @param   JMenu menu,JPanel panel,String title,String orientation
     */
    private final void connectPanelWithMenu(JMenu menu,JPanel panel,String title,String orientation) {
        if (panel != null) {
            // generate the meta-studio component from the default implementation
            StudioComponent component = new StudioComponentImpl(title, panel) {};

            // add the component to the studio
            ((StudioWithPredefinedLayout) m_studio).addComponent(component, orientation);

            // add the menu (if there is any)
            if ( menu != null ) {
                m_studio.addComponentMenu(component, menu);
            }
        }
    }

    /**
     * Show out of date message
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     */
    public final void factOutOfDate(){
        showPopUp("Fact is out of date!");
    }

    /**
     * get the Store id
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @return  The Store id
     */
    public final int getStoreId(){
        return m_storeId;
    }

    /**
     * get the Fact id
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @return  The Fact id
     */
    public final int getFactId(){
        return m_factId;
    }

    /**
     * Render the plugin window
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @param    Fact to display
     * @return  The JPanel
     */
    public abstract JPanel render(RTuple fact);   
    
    /**
     * Functionality that's triggered by the export menu
     * @author  Aldert Boerhoop
     * @date    9-3-2007
     */
    public void exportToImage(String fileName){
    	ScreenshotMaker screenshotMaker = new ScreenshotMaker();
    	screenshotMaker.saveScreenshot(m_contentPanel, fileName, screenshotMaker.DEFAULT_EXTENSION);
    }
    
    public void openLocationInEditor(Location loc) {
        m_controller.openLocationInEditor(loc);
    }
}
