package nl.dancingbear.visplugin.text;

import nl.dancingbear.visplugin.VisualizationPluginController;
import nl.dancingbear.visplugin.VisualizationPluginWindow;
import aterm.ATerm;

/**
 * The TableVisualizationController class
 *
 */
public class TextVisualizationController extends VisualizationPluginController {

    private TextVisualizationWindow m_window;

    /**
     * Default constructor.
     *
     */
    public TextVisualizationController() {
        super();

        m_window = null;
    }

    /**
     * Return Table visualization window
     *
     */
    public VisualizationPluginWindow createWindow() {
        m_window = new TextVisualizationWindow();
        return m_window;
    }

    /**
     * Gets the plugin name [Table Visualization Plugin]
     *
     */
    public String getPluginName() {
        return "Text Visualization Plugin";
    }

    /**
     * Define the supported types. Not implemented because we override the
     * isTypeSupported() function.
     *
     */
    public ATerm[] getSupportedTypes() {
        ATerm[] atermList = new ATerm[0];
        return atermList;
    }

    /**
     * Check if a type is supported
     *
     * @param type The type to check
     */
    protected boolean isTypeSupported(ATerm type) {
       return true;
    }
}
