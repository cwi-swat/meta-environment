package nl.dancingbear.visplugin;

import java.util.ArrayList;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.Location;
import aterm.ATerm;
import aterm.pure.PureFactory;

/**
 * The VisualizationPluginController class represents the base class for the
 * different plugin controllers.
 *
 * @author Aldert Boerhoop
 * @date 20-2-2007
 */
public abstract class VisualizationPluginController extends DefaultStudioPlugin
        implements VisualizationPluginTif {

    public enum requestType {
        image, csv, rStore
    };

    private static final String TOOL_NAME = "visualizationPlugin";

    private PureFactory m_pureFactory;
    private Studio m_studio;
    private String m_pluginName;
    private ATerm[] m_supportedTypes;
    private ArrayList<WindowProperties> m_openWindows;
    private VisualizationPluginBridge m_bridge;

    protected Factory m_factory;

    /**
     * Returns the bridge of the visualization plugin controller.
     *
     * @return The bridge object.
     *
     * @author Arend van Beelen
     * @date 13-3-2007
     */
    public VisualizationPluginBridge getBridge() {
        return m_bridge;
    }

    /**
     * Initialize the plugin
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @param Studio studioArgument
     */
    public void initStudioPlugin(Studio studioArgument) {
        m_studio = studioArgument;
        m_bridge = new VisualizationPluginBridge(m_studio.getATermFactory(), this);

        initPluginController((aterm.pure.PureFactory) m_studio.getATermFactory());

        m_studio.connect(TOOL_NAME, m_bridge);
    }

    /**
     * Initialize the plugin controller
     *
     * @author Aldert Boerhoop
     * @date 21-2-2007
     * @param PureFactory pureFactory that should be used by the controller
     */
    public final void initPluginController(PureFactory pureFactory) {
        m_pureFactory = pureFactory;
        m_factory = Factory.getInstance(m_pureFactory);

        VisualizationFactorySingleton.initInstances(m_pureFactory, m_factory);

        m_openWindows = new ArrayList<WindowProperties>();
        m_pluginName = getPluginName();
        m_supportedTypes = getSupportedTypes();
    }

    /**
     * Visualize the fact (Incomming call from the toolbus)
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @param Rstore id, Fact id and the fact to visualize
     */
    public final void vpVisualizeFact(int storeId, int factId, ATerm fact) {

        WindowProperties newWindowProperties = new WindowProperties();
        VisualizationPluginWindow newWindow = createWindow();

        newWindow.initializeWindow(m_studio, storeId, factId, m_factory.RTupleFromTerm(fact), m_factory, m_pluginName, this, m_openWindows.size());

        newWindow.displayVisualization();

        newWindowProperties.window = newWindow;
        m_openWindows.add(newWindowProperties);

        newWindow.executeOnLoad();

    }

    /**
     * Had to be implemented (studioplugin.getName)
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @return The plugin name
     */
    public final String getName() {
        return getPluginName();
    }

    /**
     * Sends an out of date ack. to the asigned plugin window
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @param Store id and the Fact id
     */
    public final void vpFactOutOfDate(int storeId, int factId) {
        if (m_openWindows != null) {
            for (int i = 0; i < m_openWindows.size(); i++) {

                WindowProperties windowProperties = m_openWindows.get(i);
                VisualizationPluginWindow window = windowProperties.window;

                if (window.getFactId() == factId && window.getStoreId() == storeId) {
                    window.factOutOfDate();
                }
            }
        }
    }

    /**
     * The VPI will call this method when an rstore has been unloaded.
     * The VisualizationController will check which VisualizationPluginWindows
     * correspond with the specified rstoreId and these windows will be notified.
     *
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 14-03-2007
     *
     * @param rstoreId The rstoreId of the unloaded rstore.
     */
    public final void vpRstoreUnloaded(int rstoreId) {
        if (m_openWindows != null) {
            for (int i = 0; i < m_openWindows.size(); i++) {

                WindowProperties windowProperties = m_openWindows.get(i);
                VisualizationPluginWindow window = windowProperties.window;

                if (window.getStoreId() == rstoreId) {
                    window.rstoreUnloaded();
                }
            }
        }
    }

    /**
     * Get the name of the plugin (Incomming call from the toolbus)
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007 return The plugin name as an ATerm
     */
    public final ATerm vpGetName() {
        return m_pureFactory.make("snd-value(vp-name(<str>))", m_pluginName);
    }

    /**
     * Checks if the type is supported (Incomming call from the toolbus)
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007 return true if the type is supported else false
     */
    public final ATerm vpIsTypeSupported(ATerm type) {
        boolean typeSupported = isTypeSupported(type);
        return m_pureFactory.make("snd-value(vp-type-supported(<bool>))", typeSupported);
    }

    /**
     * Checks if a type is supported. Is overridable by children to support
     * alternative ways to check for a type. For instance checking for n-size
     * relations.
     *
     * @author Aldert Boerhoop
     * @author Anton Lycklama
     * @author Bas Basten
     * @date 09-03-2007
     */
    protected boolean isTypeSupported(ATerm type) {
        System.out.println("type:" + type.toString());
       
        if (m_supportedTypes != null) {
            for (int i = 0; i < m_supportedTypes.length; i++) {
        
            	System.out.println("check type:" + m_supportedTypes[i].toString());
                if (m_supportedTypes[i].toString().equals(type.toString())) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Close the plugin
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @param ATerm event
     */
    public void recTerminate(ATerm event) {
        fireStudioPluginClosed();
    }

    public void recAckEvent(ATerm t0) {
    }

    /**
     * Create a new instance of the plugin window
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @return The instance of the plugin window
     */
    public abstract VisualizationPluginWindow createWindow();

    /**
     * Get the name of the plugin
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @return The plugin name
     */
    public abstract String getPluginName();

    /**
     * Get the supported types of the plugin
     *
     * @author Aldert Boerhoop
     * @date 20-2-2007
     * @return The supported types
     */
    public abstract ATerm[] getSupportedTypes();

    /**
     * Opens a file dialog with the correct properties
     *
     * @author Aldert Boerhoop
     * @date 15-3-2007
     * @param requestType exportRequestType type of export, int windowId of the window who requested the export
     */
    public void exportToClicked(requestType exportRequestType, int windowId) {

        WindowProperties windowProperties = m_openWindows.get(windowId);
        windowProperties.exportRequestType = exportRequestType;

        String dialogTitle = "Export as";
        String paths = "[]";
        String extensions = "";

        System.out.println(exportRequestType);

        switch (exportRequestType) {

        case image:
            extensions = ".png";
            break;

        case csv:
            extensions = ".csv";
            break;

        case rStore:
            extensions = ".rstore";
            break;
        }

        ATerm term = m_studio.getATermFactory().make(
                "vp-open-file-dialog(<int>,<str>,<str>,<str>)", windowId,
                dialogTitle, paths, extensions);

        m_bridge.sendEvent(term);
    }

    /**
     * Calls the correct function to handle the export 
     *
     * @author Aldert Boerhoop
     * @date 15-3-2007
     * @param int windowId of the window who requested the export, String fileName thats entered in the file dialog
     */
    public void vpFileDialogResult(int windowId, String fileName) {

        VisualizationPluginWindow window = getWindowById(windowId);

        switch (getWindowExportRequestType(windowId)) {
        case image:
            window.exportToImage(fileName);
            break;

        case csv:
            window.exportToCsv(fileName);
            break;
            
        default:
        }
    }

    /**
     * Returns a plugin window given by its ID.
     *
     * @param windowId ID of the window to return.
     * @return The window object.
     *
     * @author Aldert Boerhoop
     * @author Arend van Beelen
     * @date 19-03-2007
     */
    public VisualizationPluginWindow getWindowById(int windowId) {
        return m_openWindows.get(windowId).window;
    }

    /**
     * Gets the export request type.
     *
     * @param windowId ID of the window to get the export request type of.
     * @return The export request type of the window.
     *
     * TODO: Should be handled through proper export handlers, but the current
     *       architecture doesn't allow this without extensive refactoring.
     *
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    protected requestType getWindowExportRequestType(int windowId) {
        WindowProperties windowProperties = m_openWindows.get(windowId);

        return windowProperties.exportRequestType;
    }
    
    /**
     * Calls the correct function to handle the user cancel of the file dialog 
     *
     * @author Aldert Boerhoop
     * @date 15-3-2007
     * @param int windowId of the window who requested the export
     */
    public void vpFileDialogCancel(int windowId) {
        System.out.println("User cancel!! windowId => " + windowId);
    }

    public void openLocationInEditor(Location loc) {
        ATerm event = m_studio.getATermFactory().make("vp-link-clicked(<term>)", loc.toTerm());
        m_bridge.sendEvent(event);
    }

    public class WindowProperties {
        public VisualizationPluginWindow window;
        public VisualizationPluginController.requestType exportRequestType;
    }
}
