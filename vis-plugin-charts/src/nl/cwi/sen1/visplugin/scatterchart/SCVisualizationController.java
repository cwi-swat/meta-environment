package nl.cwi.sen1.visplugin.scatterchart;

import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
import aterm.ATerm;

/**
 * scatterChart Plugin Visualisation Controller. Controller for the scatter Chart
 * Window.
 * 
 * @author Raymond Bergen
 * @date 14-03-2007
 */
public class SCVisualizationController extends
        VisualizationPluginController {

    /**
     * Constructor.
     * 
     * @author Raymond Bergen
     * @date 14-03-2007
     */
    public SCVisualizationController() {
        super();
    }

    /**
     * Creates a scatterChartVisualizationWindow.
     * 
     * @author Raymond Bergen
     * @date 14-03-2007
     */
    public VisualizationPluginWindow createWindow() {
        return new SCVisualizationWindow();
    }

    /**
     * Creates a scatterChartVisualizationWindow.
     * 
     * @return Name of this plugin.
     * @author Raymond Bergen
     * @date 14-03-2007
     */
    public String getPluginName() {
        return "Scatter plot";
    }

    /**
     * Returns array holding the types supported by this plugin.
     * 
     * @return Array of supported ATerms
     * @author Raymond Bergen
     * @date 07-3-2007
     */
    public ATerm[] getSupportedTypes() {
        ATerm[] atermList = { makeATerm("relation([int,int])") };
        return atermList;
    }

    /**
     * Creates an aterm based on a String.
     * 
     * @return ATerms created from String
     * @author A. Belgraver
     * @author R. van Remortel
     * @date 07-3-2007
     */
    private ATerm makeATerm(String type) {
        return m_factory.RTypeFromString(type);
    }

}
