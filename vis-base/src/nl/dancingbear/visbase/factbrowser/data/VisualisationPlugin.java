package nl.dancingbear.visbase.factbrowser.data;


/**
 * This class represents the Visualisation Plugin. In this class the identifier
 * and name of the plugin are registered.
 *
 * @author Renze de Vries
 * @date 14-02-2007
 *
 */
public class VisualisationPlugin implements Comparable<VisualisationPlugin> {
    private String pluginName;

    private int pluginId;

    /**
     * This is the default constructor only present for failsafe purposes. The
     * following constructor should be used: VisualisationPluginNode(String
     * pluginName, int pluginId)
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public VisualisationPlugin() {
        pluginName = "";
        pluginId = 0;
    }

    /**
     * The constructor which makes it possible to create the representitive of
     * the plugin visualisation.
     *
     * @param pluginName
     *            The name of the plugin
     * @param pluginId
     *            The identifier of the plugin
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public VisualisationPlugin(String pluginName, int pluginId) {
        this.pluginName = pluginName;
        this.pluginId = pluginId;
    }

    /**
     * This method makes it possible to return the identifier of the plugin
     *
     * @return The identifier
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public int getPluginId() {
        return this.pluginId;
    }

    /**
     * This method return the name of the visualisation plugin so it can be
     * displayed in the Tree.
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public String toString() {
        return pluginName;
    }

    /**
     * This method makes it possible to sort the collection
     * of VisualisationPlugins. This is nessecary to have the same
     * order in the visible Tree every time. This is regardless in
     * which order the ToolBus send this.
     *
     * @autor Renze de Vries
     * @date 15-02-2007
     */
    public int compareTo(VisualisationPlugin arg0) {
        String localVisName = this.pluginName;
        String remoteVisName = arg0.pluginName;

        return localVisName.compareTo(remoteVisName);
    }


}
