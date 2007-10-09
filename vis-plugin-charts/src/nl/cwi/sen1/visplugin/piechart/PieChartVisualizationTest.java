package nl.cwi.sen1.visplugin.piechart;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;

import org.jfree.data.general.DefaultPieDataset;

import aterm.ATerm;

/**
 * Test class for the PieChartVisualization Plugin.
 * 
 * @author A. Belgraver
 * @author R. van Remortel
 * @author Aldert Boerhoop (reviewer)
 * @author Anton Gerdessen (reviewer)
 * @date 07-3-2007
 */
public class PieChartVisualizationTest extends TestCase {

    private PCVisualizationController m_controller;
    private PCVisualizationWindow m_window;
    private Factory m_factory;
    private RTuple m_relStrInt;
    private RTuple m_relIntStr;
    private RTuple m_relIntInt;
    private RType m_typeRelStrInt;
    private RType m_typeRelIntStr;
    private RType m_typeRelIntInt;

    
    /**
     * Test setup.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    protected void setUp() throws Exception {
        super.setUp();

        // Create the visualisation itself.
        m_factory = VisualizationFactorySingleton.getFactoryInstance();
        m_controller = new PCVisualizationController();
        m_controller.initPluginController(VisualizationFactorySingleton.getPureFactoryInstance());
        m_window = (PCVisualizationWindow) m_controller.createWindow();
        m_window.setFactory(m_factory);        
        
        // Setup three Rtuples for the tests.
        String relStrInt =  "rtuple(\"CYCLIC_GRAPH\"," +
                            "relation([str,int])," +
                            "set([tuple([str(\"a\")," +
                            "int(nat-con(10))])," +
                            "tuple([str(\"b\")," +
                            "int(nat-con(10))])," +
                            "tuple([str(\"c\")," +
                            "int(nat-con(20))])," +
                            "tuple([str(\"d\")," +
                            "int(nat-con(20))])]))";
        String relIntStr =  "rtuple(\"StatementHistogram\", " +
                            "relation([int,str])," +
                            "set([tuple([int(nat-con(7))," +
                            "str(\"Assignment\")]), "+
                            "tuple([int(nat-con(6)), " +
                            "str(\"Assignment2\")]), " +
                            "tuple([int(nat-con(5))," + 
                            "str(\"Assignment3\")]), " +
                            "tuple([int(nat-con(2))," +
                            "str(\"Assignment4\")])]))";
        String relIntInt =  "rtuple(\"TEST_GRAPH\"," +
                            "relation([int,int])," +
                            "set([tuple([int(nat-con(10))," +
                            "int(nat-con(10))])]))";
        

        // Setup the relation type and relation themselves for the preivoulsy
        // created RTuples.
        m_typeRelStrInt = m_factory.RTypeFromString("relation([str,int])");
        m_typeRelIntInt = m_factory.RTypeFromString("relation([int,int])");
        m_typeRelIntStr = m_factory.RTypeFromString("relation([int,str])");
        m_relStrInt = m_factory.RTupleFromString(relStrInt);
        m_relIntInt = m_factory.RTupleFromString(relIntInt);
        m_relIntStr = m_factory.RTupleFromString(relIntStr);
    }

    /**
     * Test to see whether the control returns the correct type Window.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public void testPieChartVisualizationController() {
        PCVisualizationController controller = new PCVisualizationController();
        assertEquals(PCVisualizationWindow.class, controller
                .createWindow().getClass());
    }

    /**
     * Test to see if the TypeCheck system works.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public void testTypeCheck() {
        assertTrue(m_window.isTypeSupported(m_relStrInt));
        assertTrue(m_window.isTypeSupported(m_relIntStr));
        assertFalse(m_window.isTypeSupported(m_relIntInt));
    }

    /**
     * Test to see if the name for the chart is correctly found.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public void testGetChartName() {
        assertEquals("CYCLIC_GRAPH", m_window.getRTupleName(m_relStrInt));
        assertEquals("StatementHistogram", m_window.getRTupleName(m_relIntStr));
        assertEquals("TEST_GRAPH", m_window.getRTupleName(m_relIntInt));
    }

    /**
     * Test to see if RTuples are correctly converted, rel<str,int>.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public void testConvertRTupleToDataset() {
        DefaultPieDataset dataset = m_window
                .convertRTupleToDataset(m_relStrInt);  
        assertEquals(4, dataset.getItemCount());
        assertTrue(dataset.getKeys().contains("a"));
        assertEquals(10, dataset.getValue(dataset.getIndex("a")).intValue());
    }

    /**
     * See if the controller correctly advertises a supported types.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public void testControllerSupportedTypes() {
        assertTrue(isRTypeInATermArray(m_controller.getSupportedTypes(),
                m_typeRelStrInt));
        assertTrue(isRTypeInATermArray(m_controller.getSupportedTypes(),
                m_typeRelIntStr));
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
     * @date 07-3-2007
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
