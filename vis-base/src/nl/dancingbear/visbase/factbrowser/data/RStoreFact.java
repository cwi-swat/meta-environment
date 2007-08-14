package nl.dancingbear.visbase.factbrowser.data;

import java.util.Iterator;
import java.util.Observable;
import java.util.Observer;

import javax.swing.tree.DefaultMutableTreeNode;

import nl.cwi.sen1.relationstores.types.RType;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/**
 * This class is the in memory representation of a Fact coupled to a specific
 * FactType. This FactType is like <str, str> or similar. The class extends the
 * DefaultMutableTreeNode so we can directly add new Visualisations which can
 * represent the Fact.
 *
 * @author Renze de Vries
 * @date 14-02-2007
 *
 */
public class RStoreFact extends DefaultMutableTreeNode implements Observer {
    private static final long serialVersionUID = 4010260633083415595L;
    private static final Log log = LogFactory.getLog(RStoreFact.class);
    private String factName;
    private RType rType;

    private int factId;

    private RStoreFactType factType;

    /**
     * This is the default constructor only present for failsafe situations.
     * Normally the overloaded constructor: FactNode(String factName, int
     * factId, RStoreFactType factType) should be used.
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public RStoreFact() {
        factName = "";
        factId = 0;
        factType = new RStoreFactType("");

        //By default all FactNodes have no available visualisations
        DefaultMutableTreeNode noVisNode = new DefaultMutableTreeNode(
                "no visualisations");
        this.add(noVisNode);
    }

    /**
     * The constructor with all the parameters to create a new Fact
     *
     * @param factName
     *            The Name of the Fact
     * @param factId
     *            The unique identifier of the Fact
     * @param factType
     *            The Type the fact is composed of
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public RStoreFact(String factName, int factId, RStoreFactType factType) {
        this.factName = factName;
        this.factId = factId;
        this.factType = factType;

        factType.addObserver(this);
        
        update(factType, null);

        //By default all FactNodes have no available visualisations
        //DefaultMutableTreeNode noVisNode = new DefaultMutableTreeNode(
        //        "no visualisations");
        //this.add(noVisNode);
    }

    /**
     * toString method so in the tree it will be visible what the name of the
     * fact is and which FactType it is.
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public String toString() {
        return factName + "(" + factType.getFactType() + ")";
    }

    /**
     * getFactName method so we can determine the name without the FactType
     *
     * @author Renze de Vries
     * @date 20-02-2007
     */
    public String getFactName() {
        return this.factName;
    }

    /**
     * get the FactType this fact is composed of.
     *
     * @return The factType
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public RStoreFactType getFactType() {
        return this.factType;
    }

    /**
     * This method is there to contain the RType.
     *
     * @return The RType itself
     *
     * @author Renze de Vries
     * @date 23-02-2007
     */
    public RType getRType() {
        return rType;
    }

    /**
     * This method sets the RType of the FactNode
     *
     * @param type This is the actual RType
     *
     * @author Renze de Vries
     * @date 23-02-2007
     */
    public void setRType(RType type) {
        rType = type;
    }

    /**
     * get the FactId so we can identify it's uniqueness
     *
     * @return The factId
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public int getFactId() {
        return this.factId;
    }

    /**
     * Whenever a new visualisation plugin is added for the specific FactType
     * this method is called as an update caller. This method will update the in
     * memory tree so it will display the current available visualisations
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public void update(Observable arg0, Object arg1) {
        log.debug("New visualisation plugin for this fact: "
                + factName);

        //Cast the update from the model to a RStoreFactType
        RStoreFactType factType = (RStoreFactType) arg0;

        //Remove all the children so we can rebuild the tree
        this.removeAllChildren();

        Iterator<VisualisationPlugin> iterator = factType.getVisualisationPlugins().iterator();

        //While there are visualisations continue
        while (iterator.hasNext()) {
            VisualisationPlugin visPlugin = iterator.next();
            // Display the visualisationPlugin in the visible Tree
            DefaultMutableTreeNode visTreeNode = new DefaultMutableTreeNode(
                    visPlugin);

            log.debug("Adding the visualisation to FactNode");

            //add the visualisatoinPlugin to the Tree
            this.add(visTreeNode);
        }
    }

	public String getType() {
		return getRType().toTerm().toString();
	}
}
