package nl.cwi.sen1.visplugin.piechart;

import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
import aterm.ATerm;

/**
 * PieChart Plugin Visualisation Controller. Controller for the Pie Chart
 * Window.
 * 
 * @author A. Belgraver
 * @author R. van Remortel
 * @author Aldert Boerhoop (reviewer)
 * @author Anton Gerdessen (reviewer)
 * @date 07-3-2007
 */
public class PCVisualizationController extends
        VisualizationPluginController {

    /**
     * Constructor.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public PCVisualizationController() {
        super();
    }

    /**
     * Creates a PieChartVisualizationWindow.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public VisualizationPluginWindow createWindow() {
        return new PCVisualizationWindow();
    }

    /**
     * Creates a PieChartVisualizationWindow.
     * 
     * @return Name of this plugin.
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public String getPluginName() {
        return "Pie chart";
    }

    /**
     * Returns array holding the types supported by this plugin.
     * 
     * @return Array of supported ATerms
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public ATerm[] getSupportedTypes() {
        ATerm[] atermList = { makeATerm("relation([str,int])"),
                makeATerm("relation([int,str])"),
                makeATerm("relation([int])")
                };
        return atermList;
    }

    /**
     * Creates an aterm based on a String.
     * 
     * @return ATerms created from String
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    private ATerm makeATerm(String type) {
        return m_factory.RTypeFromString(type);
    }

}
