package nl.dancingbear.visplugin.linechartplugin;

import aterm.ATerm;
import nl.dancingbear.visplugin.VisualizationPluginController;
import nl.dancingbear.visplugin.VisualizationPluginWindow;

/**
 * LineChart Plugin Visualisation Controller. Controller for the Line Chart
 * Window.
 * 
 * @author Raymond Bergen
 * @date 14-03-2007
 */
public class LineChartVisualizationController extends
        VisualizationPluginController {

    /**
     * Constructor.
     * 
     * @author Raymond Bergen
     * @date 14-03-2007
     */
    public LineChartVisualizationController() {
        super();
    }

    /**
     * Creates a LineChartVisualizationWindow.
     * 
     * @author Raymond Bergen
     * @date 14-03-2007
     */
    public VisualizationPluginWindow createWindow() {
        return new LineChartVisualizationWindow();
    }

    /**
     * Creates a LineChartVisualizationWindow.
     * 
     * @return Name of this plugin.
     * @author Raymond Bergen
     * @date 14-03-2007
     */
    public String getPluginName() {
        return "Line Chart Visualisation Plugin";
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
