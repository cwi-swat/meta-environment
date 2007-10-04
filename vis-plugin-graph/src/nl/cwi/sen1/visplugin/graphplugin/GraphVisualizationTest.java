package nl.cwi.sen1.visplugin.graphplugin;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;
import aterm.ATerm;

/**
 * Test class for the GraphChartVisualization Plugin. Parts of the code copied
 * and adapted from the PieCharVisualizationTest.
 * 
 * @author Anton Gerdessen
 * @date 09-3-2007
 */
public class GraphVisualizationTest extends TestCase {

    private GraphVisualizationController m_controller;
    private GraphVisualizationWindow m_window;
    private Factory m_factory;
    private RTuple m_relStrStr;
    private RTuple m_relIntInt;
    private RType m_typeRelStrStr;
    private RType m_typeRelIntInt;

    /**
     * Test setup.
     * 
     * @author Anton Gerdessen
     * @date 09-3-2007
     */
    protected void setUp() throws Exception {
        super.setUp();

        // Create the visualisation itself.
        m_factory = VisualizationFactorySingleton.getFactoryInstance();
        m_controller = new GraphVisualizationController();
        m_controller.initPluginController(VisualizationFactorySingleton
                .getPureFactoryInstance());
        m_window = (GraphVisualizationWindow) m_controller.createWindow();
        m_window.setFactory(m_factory);

        // Setup two Rtuples for the tests.
        String relStrStr =  "rtuple(\"OK_GRAPH\"," + 
                            "relation([str,str])," + 
                            "set([tuple([str(\"a\")," + 
                            "str(\"b\")])," + 
                            "tuple([str(\"b\")," + 
                            "str(\"b\")])," + 
                            "tuple([str(\"b\"),"+ 
                            "str(\"c\")])," + 
                            "tuple([str(\"c\")," + 
                            "str(\"a\")])]))";

        String relIntInt =  "rtuple(\"TEST_GRAPH\"," + 
                            "relation([int,int])," + 
                            "set([tuple([int(nat-con(10))," + 
                            "int(nat-con(10))])]))";

        // Setup the relation type and relation themselves for the preivoulsy
        // created RTuples.
        m_typeRelStrStr = m_factory.RTypeFromString("relation([str,str])");
        m_relStrStr = m_factory.RTupleFromString(relStrStr);
        m_typeRelIntInt = m_factory.RTypeFromString("relation([int,int])");
        m_relIntInt = m_factory.RTupleFromString(relIntInt);

    }

    /**
     * Test to see whether the control returns the correct type Window.
     * 
     * @author Anton Gerdessen
     * @date 09-3-2007
     */
    public void testPieChartVisualizationController() {
        GraphVisualizationController controller = new GraphVisualizationController();
        assertEquals(GraphVisualizationWindow.class, controller.createWindow()
                .getClass());
    }

    /**
     * Test to see if the supported types system works.
     * 
     * @author Anton Gerdessen
     * @date 09-3-2007
     */
    public void testTypeCheck() {
        assertTrue(m_window.isTypeSupported(m_relStrStr));
        assertFalse(m_window.isTypeSupported(m_relIntInt));
    }

    /**
     * Test to see if the name for the chart is correctly found.
     * 
     * @author Anton Gerdessen
     * @date 09-3-2007
     */
    public void testGetChartName() {
        assertEquals("OK_GRAPH", m_window.getRTupleName(m_relStrStr));
        assertEquals("TEST_GRAPH", m_window.getRTupleName(m_relIntInt));
    }

    /**
     * See if the controller correctly advertises a supported types.
     * 
     * @author Anton Gerdessen
     * @date 09-3-2007
     */
    public void testControllerSupportedTypes() {
        assertTrue(isRTypeInATermArray(m_controller.getSupportedTypes(),
                m_typeRelStrStr));
        assertFalse(isRTypeInATermArray(m_controller.getSupportedTypes(),
                m_typeRelIntInt));
    }

    /**
     * Test if a specific RType is part of an ATerm array.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @param arr
     *            Array of ATerms
     * @param type
     *            RType to find in ATerm array
     * @return true if it is in the array, false if it isn't
     * @date 09-3-2007
     */
    private boolean isRTypeInATermArray(ATerm[] arr, RType type) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].equals(type)) {
                return true;
            }
        }
        return false;
    }
}
