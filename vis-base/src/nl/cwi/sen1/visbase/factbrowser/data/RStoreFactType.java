package nl.cwi.sen1.visbase.factbrowser.data;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Observable;

/**
 * This class represents the FactTypes which are used within facts. It will be
 * used to couple FactTypes to visualisation plugins. This class acts as a
 * container in which the visualisation plugins are added. When a new
 * visualisation is added all the member Facts are notified so they can update
 * there view.
 *
 * @author Renze de Vries
 * @date 14-02-2007
 *
 */
public class RStoreFactType extends Observable {
    private String factType;

    private ArrayList<VisualisationPlugin> visualisationPlugins;

    /**
     * This is the default constructor and is mainly used as a failsafe. The
     * constructor to use is the following: RStoreFactType(String factType)
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public RStoreFactType() {
        factType = "";
        visualisationPlugins = new ArrayList<VisualisationPlugin>();
    }

    /**
     * The constructor with the factType which looks for example like this:
     * <str, str> or something similar.
     *
     * @param factType
     *            The FactType
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public RStoreFactType(String factType) {
        this.factType = factType;
        visualisationPlugins = new ArrayList<VisualisationPlugin>();
    }

    /**
     * Return the FactType string for comparison elsewhere
     *
     * @return The String FactType
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public String getFactType() {
        return factType;
    }

    /**
     * This method makes it possible to add a visualisation plugin to the
     * container. When a plugin is added notify all the observing Facts.
     * When the new VisalisationPlugin is added to the container we need to
     * resort the container. This is so the VisualisationPlguins are always
     * displayed in the same order.
     *
     * @param visPlugin
     *            The plugin to add to the container.
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public void addVisualisationPlugin(VisualisationPlugin visPlugin) {
        
        //check if the visualisationPlugin is not already present
        if(!visualisationPlugins.contains(visPlugin))
        {
            visualisationPlugins.add(visPlugin);
        }

        Collections.sort(visualisationPlugins);

        this.setChanged();
        this.notifyObservers();
    }

    /**
     * This method returns the list with all the visualisation plugins
     *
     * @return The List with visualisation plugins
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public ArrayList<VisualisationPlugin> getVisualisationPlugins() {
        return visualisationPlugins;
    }

}
