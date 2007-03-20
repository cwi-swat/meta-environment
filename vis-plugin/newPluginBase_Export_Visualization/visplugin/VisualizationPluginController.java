package nl.dancingbear.visplugin;

import java.util.ArrayList;

import javax.swing.JOptionPane;
import javax.swing.JPanel;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.Location;
import aterm.ATerm;
import aterm.pure.PureFactory;

/**
 * The VisualizationPluginController class represents the base class for the different plugin controllers.
 * @author  Aldert Boerhoop
 * @date    20-2-2007
 */
public abstract class VisualizationPluginController extends PluginController {

	private ArrayList m_openWindows; 
	private ExportProvider[] m_exportProviders;
	private JPanel m_contentPanel;

  /**
   * Default constructor
   * @author  Aldert Boerhoop
   * @date    20-2-2007
   */
    public VisualizationPluginController(){}


    public final void initController(){
        m_openWindows = new ArrayList();
        m_exportProviders = getExportProviderInstances();
    }

    protected abstract ExportProvider[] getExportProviderInstances();

    /**
     * Visualize the fact (Incomming call from the toolbus)
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @param   Rstore id, Fact id and the fact to visualize
     */
    public void vpVisualizeFact(int storeId, int factId, ATerm fact){
    	
    	WindowProperties newWindowProperties = new WindowProperties();
    	VisualizationPluginWindow newWindow = createWindow();
        
        newWindow.initializeWindow(m_studio, storeId, factId, m_factory.RTupleFromTerm(fact), m_factory, m_pluginName, this, m_openWindows.size(), m_exportProviders);
        newWindow.displayVisualization();

        newWindowProperties.window = newWindow;
        m_openWindows.add(newWindowProperties);
    }


    /**
     * Sends an out of date ack. to the asigned plugin window
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @param   Store id and the Fact id
     */
    public final void vpFactOutOfDate(int storeId, int factId){
        if(m_openWindows != null){
            for(int i=0; i < m_openWindows.size(); i++){
                
            	WindowProperties tempWindowProperties = (WindowProperties) m_openWindows.get(i);
            	VisualizationPluginWindow tempWindow = (VisualizationPluginWindow)tempWindowProperties.window;

                if(tempWindow.getFactId() == factId && tempWindow.getStoreId() == storeId){
                	tempWindow.factOutOfDate();
                    break;
                }
            }
        }
    }

    /**
     * Create a new instance of the plugin window
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @return  The instance of the plugin window
     */
    public abstract VisualizationPluginWindow createWindow();
   
     
    public void exportToClicked(JPanel contentPanel, ExportProvider requestExportProvider, int windowId){
    	m_contentPanel = contentPanel;
    	
    	WindowProperties tempWindowProperties = (WindowProperties) m_openWindows.get(windowId);
    	tempWindowProperties.requestExportProviderInstance = requestExportProvider;
    	
    	openFileDialog(windowId, requestExportProvider.getDialogTitle(), requestExportProvider.getPaths(), requestExportProvider.getExtensions());
    }
    
    public void vpFileDialogResult(int windowId, String fileName){
    	WindowProperties tempWindowProperties = (WindowProperties) m_openWindows.get(windowId);
    	
    	tempWindowProperties.requestExportProviderInstance.export(m_contentPanel, fileName, ""); 	
    }
    
	class WindowProperties{
    	public VisualizationPluginWindow window;
    	public ExportProvider requestExportProviderInstance;
    }
}
