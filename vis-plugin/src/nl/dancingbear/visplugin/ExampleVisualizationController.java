package nl.dancingbear.visplugin;

import aterm.ATerm;
import nl.dancingbear.visplugin.VisualizationPluginController;
import nl.dancingbear.visplugin.VisualizationPluginWindow;

/**
 * The ExampleVisualizationController class represents an example implementation for a plugin controller.
 * @author  Aldert Boerhoop
 * @date    20-2-2007
 */
public class ExampleVisualizationController extends VisualizationPluginController {

    public VisualizationPluginWindow createWindow() {
        return new ExampleVisualizationWindow();
    }

    public String getPluginName(){
        return "Visualisatie Test Plugin";
    }

    public ATerm[] getSupportedTypes() {
        ATerm[] exampleTypes = new ATerm[1];

        exampleTypes[0] = m_factory.RTypeFromString("relation([str,str])");

        return exampleTypes;
    }

    public void recAckEvent(ATerm t0) {

    }
}
