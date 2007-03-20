package nl.dancingbear.visplugin;

import java.util.ArrayList;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.Location;
import aterm.ATerm;
import aterm.pure.PureFactory;

public abstract class PluginController  extends DefaultStudioPlugin implements VisualizationPluginTif{

    private static final String TOOL_NAME = "visualizationPlugin";
    protected PureFactory m_pureFactory;
    protected Studio m_studio;
    protected String m_pluginName;
    private ATerm[] m_supportedTypes;
    protected VisualizationPluginBridge m_bridge;
    protected Factory m_factory;

  /**
   * Default constructor
   * @author  Aldert Boerhoop
   * @date    20-2-2007
   */
    public PluginController(){
        System.out.println("Class:"+this.getClass().toString()+" initiated");
    }

    /**
     * Initialize the plugin
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @param   Studio studioArgument
     */
    public final void initStudioPlugin(Studio studioArgument) {
        m_studio = studioArgument;
        m_bridge = new VisualizationPluginBridge(m_studio.getATermFactory(), this);

        initPluginController((aterm.pure.PureFactory) m_studio.getATermFactory());
        initController();

        m_studio.connect(TOOL_NAME, m_bridge);
    }

    public abstract void initController();
    
    /**
     * Initialize the plugin controller
     * @author  Aldert Boerhoop
     * @date    21-2-2007
     * @param   PureFactory pureFactory
     */
    public final void initPluginController(PureFactory pureFactory){
        m_pureFactory = pureFactory;
        m_factory = Factory.getInstance(m_pureFactory);
        m_pluginName = getPluginName();
        m_supportedTypes = getSupportedTypes();
    }


    /**
     * Visualize the fact (Incomming call from the toolbus)
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @param   Rstore id, Fact id and the fact to visualize
     */
    public abstract void vpVisualizeFact(int storeId, int factId, ATerm fact);

    /**
     * Had to be implemented (studioplugin.getName)
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @return  The plugin name
     */
    public final String getName(){
        return getPluginName();
    }

    /**
     * Sends an out of date ack. to the asigned plugin window
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @param   Store id and the Fact id
     */
    public void vpFactOutOfDate(int storeId, int factId){}

    /**
     * Get the name of the plugin (Incomming call from the toolbus)
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * return   The plugin name as an ATerm
     */
    public final ATerm vpGetName(){
        return m_pureFactory.make("snd-value(vp-name(<str>))",m_pluginName);
    }

    /**
     * Checks if the type is supported (Incomming call from the toolbus)
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * return   true if the type is supported else false
     */
    public final ATerm vpIsTypeSupported(ATerm type){       
        boolean typeSupported = isTypeSupported(type);
        return m_pureFactory.make("snd-value(vp-type-supported(<bool>))", typeSupported);
    }
    
    /**
     * Checks if a type is supported. Is overridable by children
     * to support alternative ways to check for a type. 
     * For instance checking for n-size relations. 
     * 
     * @author  Anton Lycklama  
     * @author  Bas Basten
     * @date    09-03-2007
     */
    protected boolean isTypeSupported(ATerm type) {
        System.out.println("type:"+type.toString());
        if(m_supportedTypes != null){
            for(int i=0; i < m_supportedTypes.length; i++){
                System.out.println("type:"+m_supportedTypes[i].toString());
                if(m_supportedTypes[i].toString().equals(type.toString())){
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Close the plugin
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @param   ATerm event
     */
    public final void recTerminate(ATerm event) {
        fireStudioPluginClosed();
        System.out.println("Terminate ("+event+")");
    }

    public final void recAckEvent(ATerm t0) {
    }
    
    /**
     * Get the name of the plugin
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @return  The plugin name
     */
    public abstract String getPluginName();

    /**
     * Get the supported types of the plugin
     * @author  Aldert Boerhoop
     * @date    20-2-2007
     * @return  The supported types
     */
    protected abstract ATerm[] getSupportedTypes();
        
    public abstract void vpFileDialogResult(int windowId, String fileName);

    public void vpFileDialogCancel(int windowId){
    	System.out.println("User cancel!! windowId => "+windowId);
    }
    
    public final void openLocationInEditor(Location loc) {
        ATerm event = m_studio.getATermFactory().make("vp-link-clicked(<term>)", loc.toTerm());       
        m_bridge.sendEvent(event);
    }
    
    protected final void openFileDialog(String dialogTitle, String paths, String extensions){
    	openFileDialog(0, dialogTitle, paths, extensions);
    }
    
    protected final void openFileDialog(int windowId, String dialogTitle, String paths, String extensions){
    	ATerm term = m_pureFactory.make("vp-open-file-dialog(<int>,<str>,<str>,<str>)",windowId, dialogTitle, paths, extensions);
    	
    	m_bridge.sendEvent(term);
    }
}