package nl.dancingbear.visbase.factbrowser.data;

import java.util.ArrayList;

/**
 * This class represent the RStore. Every RStore has a collection of facts which
 * will be contained in this class. It will offer methods to get the details of
 * the RStore and get the children Facts.
 *
 * @author Renze de Vries
 * @date 14-02-2007
 *
 */
public class RStore {
    private ArrayList<RStoreFact> factNodes;

    private String rstoreName;

    private int rstoreID;

    /**
     * This is the default constructor which will be used as a failsafe. The
     * normal constructor to use is the following: RStoreNode(String rstoreName,
     * int rstoreID)
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public RStore() {
        factNodes = new ArrayList<RStoreFact>();
    }

    /**
     * Constructor wich will set the name of the RStore and the RstoreID and
     * will initialise the children factNodes container
     *
     * @param rstoreName
     *            THis is the visual name of the RStore
     * @param rstoreID
     *            This is the identifier of the RStore
     *
     * @author Renze de Vries
     * @date 13-02-2007
     */
    public RStore(String rstoreName, int rstoreID) {
        this.rstoreName = rstoreName;
        this.rstoreID = rstoreID;
        factNodes = new ArrayList<RStoreFact>();
    }

    /**
     * This method will make it possible to add an Child factNode
     *
     * @param factNode
     *            This is to add a FactNode to the RStore
     *
     * @author Renze de Vries
     * @date 13-02-2007
     */
    public void addFactNode(RStoreFact factNode) {
        factNodes.add(factNode);
    }

    /**
     * This method will return the ArrayList which contains all the children
     * FactNodes
     *
     * @return the ArrayList for the factNodes
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public ArrayList<RStoreFact> getFactNodes() {
        return this.factNodes;
    }

    /**
     * Method will make it possible to display the name of the RStore in the
     * tree
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public String toString() {
        return rstoreName;
    }

    /**
     * This is the method which will the return the unique Identifier of the
     * RStore.
     *
     * @return THe unique identifier
     *
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public int getRstoreId() {
        return this.rstoreID;
    }
}
