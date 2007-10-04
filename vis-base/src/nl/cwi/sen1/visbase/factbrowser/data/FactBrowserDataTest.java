package nl.dancingbear.visbase.factbrowser.data;

import junit.framework.TestCase;

/**
 * This is the class for JUnit testing of the FactBrowser system. It tests the
 * in memory data structure and also tests the creation of the visualisation
 * component;
 * 
 * @author Renze de Vries
 * @date 14-02-2007
 * 
 */
public class FactBrowserDataTest extends TestCase {
    private FactBrowserDataManager dataManager;

    public FactBrowserDataTest() {
        dataManager = FactBrowserDataManager.getInstance();
    }

    /**
     * For the FactBrowser testing it is very important to test if the
     * datamanger which manages the in memory data tree is present and will
     * initialize.
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public void testDataManager() {
        assertNotNull("DataManager is NULL", dataManager);
    }

    /**
     * This method is here pure for testing of the RStore creation
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public void testCreateRStore() {
        RStore rstoreNode1 = new RStore("Rstore1", 1);

        assertNotNull("The created RStoreNode1 is NULL", rstoreNode1);
        assertEquals("The RStoreId should be 1", 1, rstoreNode1.getRstoreId());
        assertEquals("The RStoreName should be Rstore1", "Rstore1", rstoreNode1
                .toString());
        assertEquals("The FactNode ArrayList should be empty", 0, rstoreNode1
                .getFactNodes().size());

        RStore rstoreNode2 = new RStore("Rstore2", 2);
        assertNotNull("This Rstore should not be null", rstoreNode2);
    }

    /**
     * This method will test if the RStoreFactType registration is working and
     * it will test for different type of scenarios from nullpointers to string
     * equality and testing the size of the initial plugin container
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public void testFactTypes() {
        RStoreFactType factType1 = dataManager.addFactType("<str, str>");
        RStoreFactType factType2 = dataManager.addFactType("<str, bool>");
        RStoreFactType factType3 = dataManager.addFactType("<str, str, int>");
        RStoreFactType factType4 = dataManager.addFactType("<int, int>");

        assertNotNull("The created FactType is NULL", factType1);
        assertEquals("The FactType should be <str, str>", "<str, str>",
                factType1.getFactType());
        assertEquals("The number of visualisations should be 0", 0, factType1
                .getVisualisationPlugins().size());

        assertNotSame("FactTypes should be different object instants",
                factType1, factType4);

        RStoreFactType factType5 = dataManager.addFactType("<str, str>");
        assertEquals(
                "The factTypes <str, str> and <str, str> should provide the same object",
                factType1, factType5);
        assertNotSame(
                "The factTypes <str, str, int> should give a different object than <str, str>",
                factType1, factType3);
        assertSame(
                "The factType <str, bool> should be the same as <str, bool>",
                factType2, dataManager.addFactType("<str, bool>"));
        
        RStoreFactType emptyFactType = new RStoreFactType();
        assertNotNull("This instance should not be null", emptyFactType);
    }

    /**
     * This method tests the creation of a fact node and the coupling of this
     * fact node to the RStore parent. It will test the basic properties of the
     * FactNode and if the RStore registers the FactNode properly.
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public void testFactNode() {
        RStore rstoreNode1 = new RStore("Rstore1", 1);

        RStoreFactType rstoreFactType = dataManager.addFactType("<str, str>");

        RStoreFact factNode1 = new RStoreFact("Fact1", 1, rstoreFactType);
        assertNotNull("The created Fact1 is NULL", factNode1);
        assertEquals("The FactId should be 1", 1, factNode1.getFactId());
        assertEquals("The FactName should be Fact1(<str, str>)",
                "Fact1(<str, str>)", factNode1.toString());

        rstoreNode1.addFactNode(factNode1);

        assertEquals("The FactNode ArrayList should be 1", 1, rstoreNode1
                .getFactNodes().size());

        assertEquals("These factTypes should be the same instance",
                rstoreFactType, factNode1.getFactType());
    }

    /**
     * This tests the constructor checking if the factname and factype are
     * correctly initialized
     * 
     * @author Raymond Bergen
     * @date 21-02-2007
     */
    public void testFactNodeConstructor() {
        RStoreFact factnode = new RStoreFact();
        assertEquals("The factname should be empty ", factnode.getFactName(),
                "");
    }

    /**
     * This node tests the registration of the VisualisationPlugins. It is
     * basicly a test of all combined tests in this class. If this works all the
     * tests should work in this class.
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    public void testVisualisations() {
        RStoreFactType factType1 = dataManager.addFactType("<str, str>");
        RStoreFactType factType2 = dataManager.addFactType("<str, bool>");
        RStoreFactType factType3 = dataManager.addFactType("<str, str, int>");
        RStoreFactType factType4 = dataManager.addFactType("<int, int>");

        RStore rstoreNode1 = new RStore("Rstore1", 1);

        RStoreFact factNode1 = new RStoreFact("Fact1", 1, factType1);
        RStoreFact factNode2 = new RStoreFact("Fact2", 2, factType2);
        rstoreNode1.addFactNode(factNode1);
        rstoreNode1.addFactNode(factNode2);

        RStore rstoreNode2 = new RStore("Rstore2", 2);
        RStoreFact factNode3 = new RStoreFact("Fact3", 3, factType3);
        RStoreFact factNode4 = new RStoreFact("Fact4", 4, factType4);
        rstoreNode2.addFactNode(factNode3);
        rstoreNode2.addFactNode(factNode4);

        VisualisationPlugin visPlugin1 = new VisualisationPlugin("BarChart", 1);
        VisualisationPlugin visPlugin2 = new VisualisationPlugin("GraphChart",
                2);
        VisualisationPlugin visPlugin3 = new VisualisationPlugin("TreeView", 3);
        VisualisationPlugin visPlugin4 = new VisualisationPlugin("BarChart", 1);

        assertNotNull("The created visPlugin1 is NULL", visPlugin1);
        assertEquals("The name of the visPlugin1 should be BarChart",
                "BarChart", visPlugin1.toString());
        assertEquals("The Id of the visPlugin1 should be 1", 1, visPlugin1
                .getPluginId());

        assertEquals("The FactType should be the same according to cache",
                factType1, dataManager.addFactType("<str, str>"));
        assertEquals("The FactType should be the same according to cache",
                factType2, dataManager.addFactType("<str, bool>"));
        assertEquals("The FactType should be the same according to cache",
                factType3, dataManager.addFactType("<str, str, int>"));
        assertEquals("The FactType should be the same according to cache",
                factType4, dataManager.addFactType("<int, int>"));

        assertEquals("The number of visualisations of factType1 should be 0",
                0, factType1.getVisualisationPlugins().size());
        assertEquals("The number of visualisations of factType2 should be 0",
                0, factType2.getVisualisationPlugins().size());
        assertEquals("The number of visualisations of factType3 should be 0",
                0, factType3.getVisualisationPlugins().size());
        assertEquals("The number of visualisations of factType4 should be 0",
                0, factType4.getVisualisationPlugins().size());

        dataManager.createVisualisation(visPlugin1, factType1);

        assertEquals("The number of visualisations of factType1 should be 1",
                1, factType1.getVisualisationPlugins().size());

        dataManager.createVisualisation(visPlugin2, dataManager
                .addFactType("<str, str, int>"));

        assertEquals("The number of visualisations of factType3 should be 1",
                1, factType3.getVisualisationPlugins().size());

        dataManager.createVisualisation(visPlugin3, dataManager
                .addFactType("<str, bool>"));

        assertEquals("The number of visualisations of factType2 should be 1",
                1, factType2.getVisualisationPlugins().size());

        dataManager.createVisualisation(visPlugin4, dataManager
                .addFactType("<str, bool>"));

        assertEquals("The number of visualisations of factType2 should be 2",
                2, factType2.getVisualisationPlugins().size());
        
        VisualisationPlugin emptyVisPlugin = new VisualisationPlugin();
        assertNotNull("The visualisationPlugin should not be null", emptyVisPlugin);

    }

    /**
     * This test checks if the reset of the dataManager works and checks it
     * 
     * @author Renze de Vries
     * @date 12-03-2007
     */
    public void testResetDataManager() {
        RStoreFactType rstoreFactType = dataManager
                .addFactType("<str, str, int>");

        dataManager.resetDataManager();

        RStoreFactType rstoreFactType2 = dataManager
                .addFactType("<str, str, int>");

        assertNotSame("These instances should be different", rstoreFactType,
                rstoreFactType2);
    }
}
