package nl.dancingbear.visplugin.barchartplugin;

import aterm.ATerm;
import nl.dancingbear.visplugin.VisualizationPluginController;
import nl.dancingbear.visplugin.VisualizationPluginWindow;

/**
 * BarChart Plugin Visualisation Controller. Controller for the Bar Chart
 * Window.
 * 
 * @author Srinivasan Tharmarajah
 * @date 14-03-2007
 */
public class BarChartVisualizationController extends VisualizationPluginController {

    /**
     * Constructor.
     * 
     * @author Srinivasan Tharmarajah
     * @date 14-03-2007
     */
    public BarChartVisualizationController() {
        super();
    }

    /**
     * Creates a BarChartVisualizationWindow.
     * 
     * @author Srinivasan Tharmarajah
     * @date 14-03-2007
     */
    public VisualizationPluginWindow createWindow() {
        return new BarChartVisualizationWindow();
    }

    /**
     * Creates a BarChartVisualizationWindow.
     * 
     * @return Name of this plugin.
     * @author Srinivasan Tharmajah
     * @date 14-03-2007
     */
    public String getPluginName() {
        return "Bar Chart Visualisation Plugin";
    }

    /**
     * Returns array holding the types supported by this plugin.
     * 
     * @return Array of supported ATerms
     * @author Srinivasan Tharmarajah
     * @date 07-3-2007
     */
    public ATerm[] getSupportedTypes() {
        ATerm[] atermList = { makeATerm("relation([int,str])"), makeATerm("relation([str,int])") };
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
