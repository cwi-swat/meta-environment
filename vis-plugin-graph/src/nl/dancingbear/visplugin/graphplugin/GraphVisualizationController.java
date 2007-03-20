package nl.dancingbear.visplugin.graphplugin;

import aterm.ATerm;
import nl.dancingbear.visplugin.VisualizationPluginController;
import nl.dancingbear.visplugin.VisualizationPluginWindow;

/**
 * Graph Plugin Visualisation Controller. Controller for the graph
 * window.
 *
 * @author A. Belgraver
 * @author Anton Gerdessen (reviewer)
 * @date 07-3-2007 
 */
public class GraphVisualizationController extends
        VisualizationPluginController {

    private final String m_pluginName = "Graph Visualisation Plugin";
    
    /**
     * @todo Needs better implementation needs to be resolved reflection, dynamic 
     * dispatch... in a the base or utility class for all plugins, remark by Anton G.
     */
    private final String m_relationGraph = "relation([str,str])";
    private final String m_relationGraphTuple = "relation([tuple([str,loc]),tuple([str,loc])])";

    /**
     * Constructor.
     * 
     * @author R. van Remortel
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007 
     */
    public GraphVisualizationController() {
        super();
    }

    /**
     * Creates a VisualizationWindow.
     * 
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007 
     */
    public VisualizationPluginWindow createWindow() {
        return new GraphVisualizationWindow();
    }

    /**
     * Creates a VisualizationWindow.
     * 
     * @return Name of this plugin
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007 
     */
    public String getPluginName() {
        return m_pluginName;
    }

    /**
     * Returns array holding the types supported by this plugin.
     * 
     * @return Array of supported ATerms
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007 
     */
    public ATerm[] getSupportedTypes() {
        ATerm[] atermList = { makeATerm(m_relationGraph), makeATerm(m_relationGraphTuple) };
        System.out.println("[GRAPH] atermlist: " + atermList.toString());
        return atermList;
    }

    /**
     * Creates an Aterm based on a String.
     * 
     * @return ATerms created from String
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007 
     */
    private ATerm makeATerm(String type) {
        return m_factory.RTypeFromString(type);
    }

}
