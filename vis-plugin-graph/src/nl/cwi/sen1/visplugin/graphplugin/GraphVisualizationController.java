package nl.cwi.sen1.visplugin.graphplugin;

import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
import aterm.ATerm;

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

    private final String m_pluginName = "Graph";
    
    /**
     * @todo Needs better implementation needs to be resolved reflection, dynamic 
     * dispatch... in a the base or utility class for all plugins, remark by Anton G.
     */
    private final String m_relationGraph = "relation([str,str])";
    private final String m_relationGraphTuple = "relation([tuple([str,loc]),tuple([str,loc])])";
    private final String m_attributedGraphTuple = "relation([tuple([str,relation([str,str])]),str])";

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
        ATerm[] atermList = { makeATerm(m_relationGraph), makeATerm(m_relationGraphTuple), makeATerm(m_attributedGraphTuple) };
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
