package nl.cwi.sen1.visplugin.barchart;

import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
import aterm.ATerm;

/**
 * BarChart Plugin Visualisation Controller. Controller for the Bar Chart
 * Window.
 * 
 * @author Srinivasan Tharmarajah
 * @date 14-03-2007
 */
public class BCVisualizationController extends VisualizationPluginController {

    /**
     * Constructor.
     * 
     * @author Srinivasan Tharmarajah
     * @date 14-03-2007
     */
    public BCVisualizationController() {
        super();
    }

    /**
     * Creates a BarChartVisualizationWindow.
     * 
     * @author Srinivasan Tharmarajah
     * @date 14-03-2007
     */
    public VisualizationPluginWindow createWindow() {
        return new BCVisualizationWindow();
    }

    /**
     * Creates a BarChartVisualizationWindow.
     * 
     * @return Name of this plugin.
     * @author Srinivasan Tharmajah
     * @date 14-03-2007
     */
    public String getPluginName() {
        return "Bar chart";
    }

    /**
     * Returns array holding the types supported by this plugin.
     * 
     * @return Array of supported ATerms
     * @author Srinivasan Tharmarajah
     * @date 07-3-2007
     */
    public ATerm[] getSupportedTypes() {
        ATerm[] atermList = { makeATerm("relation([int,str])"), makeATerm("relation([str,int])"),
        		makeATerm("relation([int,int])")};
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
