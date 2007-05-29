package nl.dancingbear.visbase.factbrowser.data;

import java.util.ArrayList;
import java.util.Iterator;

import javax.swing.tree.DefaultMutableTreeNode;

import nl.cwi.sen1.relationstores.types.RType;

/**
 * This class is the dataManager for the different visualizationPlugins and the
 * RStoreFactTypes (like <str,str>) which are registered. It also caches the
 * different visualisationPlugins and RStoreFactTypes.
 * 
 * <b>Relational representation of in memory data structure</b> This
 * dataManager holds an in memory representation of the RStore with it's
 * children facts.
 * 
 * Also it tracks all different types of RStoreFactTypes which are sent. Every
 * visualisationPlugin which is sent should be coupled with a RStoreFactType.
 * When a visualisationPlugin registers itself to a cached or new RStoreFactType
 * a signal is sent to all children facts of the RStores which are
 * RStoreFactType compatible.
 * 
 * @author Renze de Vries
 * @date 14-02-2007
 * 
 */

public class FactBrowserDataManager {
    private static FactBrowserDataManager dataManagerInstance;

    private ArrayList<RStoreFactType> factTypes;

    private ArrayList<VisualisationPlugin> visPlugins;

    /**
     * Default constructor where the caching containers for the FactTypes and
     * the Plugins are initialized. This is also private so it can only be
     * instantiated from within this class.
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    private FactBrowserDataManager() {
        factTypes = new ArrayList<RStoreFactType>();
        visPlugins = new ArrayList<VisualisationPlugin>();
    }

    /**
     * This method makes it possible to centrally access the dataManager and
     * only create it once. This is the method which enforces the singleton
     * pattern.
     * 
     * @author Renze de Vries
     * @date 22-02-2007
     * 
     * @return The instance of the DataManager
     */
    public static FactBrowserDataManager getInstance() {
        if (dataManagerInstance == null) {
            dataManagerInstance = new FactBrowserDataManager();
        }

        return dataManagerInstance;
    }

    /**
     * This method makes it possible to reset all the elements so we can if
     * nessecary start with a clean in memory list.
     * 
     * @author Renze de Vries
     * @date 22-02-2007
     */
    public void resetDataManager() {
        factTypes.clear();
        visPlugins.clear();
    }

    /**
     * This method is a method which directs the creation of a new Visualisation
     * plugin and couples it to the different FactTypes
     * 
     * @param visNewPlugin
     *            This is the new Visualisation Plugin to be created
     * @param visFactType
     *            This is the FactType this plugin can display
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public void createVisualisation(VisualisationPlugin visNewPlugin, RStoreFactType visFactType) {
        // This method call is to get create the plugin in cache
        // or if not already present get the cached version
    	VisualisationPlugin newVisPlugin = addVisualisation(visNewPlugin);

        // Now we must couple the plugin to the FactType so call the method
        // which will do this.
        coupleVisualisation(newVisPlugin, visFactType);
    }

    /**
     * This method is to add the Visualisation Plugin to the cache or if already
     * present give the already present VisualisationPlugin instance back
     * 
     * @param visNewPlugin
     *            This is the Visualisation Plugin we want to add
     * @return the instance of the Visualisation plugin which is or newly
     *         created or from the cache
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    private VisualisationPlugin addVisualisation(
            VisualisationPlugin visNewPlugin) {
        Iterator<VisualisationPlugin> iterator = visPlugins.iterator();
        while (iterator.hasNext()) {
            VisualisationPlugin visPlugin = iterator.next();
            if (visPlugin.getPluginId() == visNewPlugin.getPluginId()) {
                return visPlugin;
            }
        }

        visPlugins.add(visNewPlugin);

        return visNewPlugin;
    }

    /**
     * This method couples the visualisationPlugin to the nessecary
     * RStoreFactTypes. When this happens the facts which are a member of the
     * RStoreFactType will be notified.
     * 
     * @param visPlugin
     *            The VisualisationPlugin to add to the specific FactType
     * @param visFactType
     *            The FactType this visualisationPlugin applies to
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    private void coupleVisualisation(VisualisationPlugin visPlugin,
            RStoreFactType visFactType) {

        // Go through all the RStoreFactTypes
        for (RStoreFactType factType : factTypes) {
            // If the RStoreFactType of the VisualisationPlugin matches that of
            // the cached RStoreFactType add the VisualisationPlugin tot it.
            if (factType == visFactType) {
                factType.addVisualisationPlugin(visPlugin);
            }
        }
    }

    /**
     * This method is to register an RStoreFactType. It will check if the
     * RStoreFactType was already in the cache and if so return that instance.
     * If not present create such an RStoreFactType and register it in the cache
     * and return the created instance.
     * 
     * @param newType
     *            The FactType we want to add
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public RStoreFactType addFactType(String newType) {

        // Use the Java foreach iterator to look at all already cached
        // RStoreFactTypes
        for (RStoreFactType factType : factTypes) {

            // If the RStoreFactType is already present return that instance.
            if (factType.getFactType().equalsIgnoreCase(newType)) {
                return factType;
            }
        }

        // If the FactType was not already in the container we can now add it
        RStoreFactType newFactType = new RStoreFactType(newType);
        factTypes.add(newFactType);

        return newFactType;
    }

    /**
     * This method checks if the given selectedNode from the visual
     * factBrowser tree was really a visualisationPlugin.
     * 
     * @param selectedNode The selectedNode from the visual tree
     * @return true if it was a visualisation plugin else false
     * 
     * @author Renze de Vries
     * @date 12-03-2007
     */
    public boolean checkValidVisualisationPlugin(DefaultMutableTreeNode selectedNode) {
        return (selectedNode.getUserObject() instanceof VisualisationPlugin);
    }

    /**
     * This method checks if the given selectedNode from the visual
     * factBrowser tree was a RStoreFact.
     * 
     * @param selectedNode The selectedNode from the visual Tree
     * @return true if it was a RStoreFact plugin else false
     * 
     * @author Renze de Vries
     * @date 12-03-2007
     */
    public boolean checkValidRStoreFact(DefaultMutableTreeNode selectedNode) {
        return (selectedNode instanceof RStoreFact);
    }

    public boolean checkValidRStore(DefaultMutableTreeNode selectedNode) {
        return (selectedNode.getUserObject() instanceof RStore);           
    }
    
    /**
     * This method gets the Fact Identifier of a RStoreFact. It does this
     * by a given selected visualisationPlugin and gathers from the in memory
     * tree the identifier.
     * 
     * @param selectedNode The selectedNode from the visualTree
     * @return The RStoreFact Identifier
     * 
     * @author Renze de Vries
     * @date 12-03-2007
     */
    public int getFactID(DefaultMutableTreeNode selectedNode) {
        //check if the given selected node is really a visualisation Plugin
        if (checkValidVisualisationPlugin(selectedNode)) {
            RStoreFact rstoreFact = (RStoreFact) selectedNode.getParent();

            return rstoreFact.getFactId();
        }
        
        //if the selectednode was not a visualisationPlugin return -1
        return -1;
    }

    /**
     * This method gets the RStore Identifier based on a selected VisualisationPlugin
     * from the visual tree. It gathers the identifiers from the in memory tree.
     * 
     * @param selectedNode The selectedNode from the visualTree
     * @return The RStore identifier
     * 
     * @author Renze de Vries
     * @date 12-03-2007
     * 
     * TODO: This method needs refactoring. The comments do not match the intended
     * purpose of this method. 
     */
    public int getRStoreID(DefaultMutableTreeNode selectedNode) {
        //for this to work it must be a visualisationPlugin
        if (checkValidVisualisationPlugin(selectedNode)) {
            
            //get from the visual tree the parent of the selectedNode (VisualisationPlugin)
            //this parent (RStoreFact) get the parent which is a RStore.
            DefaultMutableTreeNode rstoreNode = (DefaultMutableTreeNode) selectedNode
                    .getParent().getParent();

            RStore rstore = (RStore) rstoreNode.getUserObject();
            return rstore.getRstoreId();
        }
        else if (checkValidRStore(selectedNode)) {
            RStore rstore = (RStore) selectedNode.getUserObject();
            return rstore.getRstoreId();
        }
        
        //if the selectednode was not a visualisationPlugin return -1
        return -1;
    }

    /**
     * This method returns the identifier of the visualisationPlugin.
     * 
     * @param selectedNode The given selectedNode from the visual tree
     * @return The identifier of the visualisationPlugin
     * 
     * @author Renze de Vries
     * @date 12-03-2007
     */
    public int getVisPluginID(DefaultMutableTreeNode selectedNode) {
        //check if the selectedNode was realy a visualisationPlugin
        if (checkValidVisualisationPlugin(selectedNode)) {
            VisualisationPlugin visPlugin = (VisualisationPlugin) selectedNode
                    .getUserObject();

            return visPlugin.getPluginId();
        }
        
        //if the selectednode was not a visualisationPlugin return -1
        return -1;
    }

    /**
     * This method returns the RType of a selectedNode from the visualtree.
     * For this to work it must be a selected RStoreFact.
     * 
     * @param selectedNode The selectedNode from the visual tree
     * @return The RType of the RStoreFact
     */
    public RType getFactRType(DefaultMutableTreeNode selectedNode) {
        //check if the given selectedNode is really a RStoreFact
        if(checkValidRStoreFact(selectedNode))
        {
            RStoreFact rstoreFact = (RStoreFact) selectedNode;
            
            return rstoreFact.getRType();
        }
        
        //if the given selectedNode was not a RStoreFact return null
        return null;
    }
}
