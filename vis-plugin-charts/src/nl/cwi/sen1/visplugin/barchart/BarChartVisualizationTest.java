package nl.cwi.sen1.visplugin.barchart;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;

import org.jfree.data.category.CategoryDataset;

import aterm.ATerm;

/**
 * Test class for the PieChartVisualization Plugin.
 * Original code : PieChart plugin ( A. Belgraver, R. van Remortel )
 * @author Srinivasan Tharmarajah
 * @date 12-03-2007
 */
public class BarChartVisualizationTest extends TestCase {

    private BCVisualizationController m_controller;
    private BCVisualizationWindow m_window;
    private Factory m_factory;
    private RTuple m_relStrInt;
    private RTuple m_relIntStr;
    private RTuple m_relWrong;
    private RType m_typeRelStrInt;
    private RType m_typeRelIntStr;
    private RType m_typeRelWrong;

    /**
     * Test setup.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah
     * @date 12-03-2007
     */
    protected void setUp() throws Exception {
        super.setUp();

        // Create the visualisation itself.
        m_factory = VisualizationFactorySingleton.getFactoryInstance();
        m_controller = new BCVisualizationController();
        m_controller.initPluginController(VisualizationFactorySingleton.getPureFactoryInstance());
        m_window = (BCVisualizationWindow) m_controller.createWindow();
        m_window.setFactory(m_factory);        
        
        // Setup three Rtuples for the tests.
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
        String relStrInt =  "rtuple(\"TEST_BAR\"," +
                            "relation([str,int])," +
                            "set([tuple([str(\"a\")," +
                            "int(nat-con(10))])]))";
        String relWrong =   "rtuple(\"WRONG_BAR\"," +
                            "relation([int,int,str])," +
                            "set([tuple([str(\"a\")," +
                            "int(nat-con(10))])]))";

        // Setup the relation type and relation themselves for the preivoulsy
        // created RTuples.
        m_typeRelIntStr = m_factory.RTypeFromString("relation([int,str])");
        m_typeRelStrInt = m_factory.RTypeFromString("relation([str,int])");
        m_typeRelWrong = m_factory.RTypeFromString("relation([int,int,str])");
        m_relIntStr = m_factory.RTupleFromString(relIntStr);
        m_relStrInt = m_factory.RTupleFromString(relStrInt);
        m_relWrong = m_factory.RTupleFromString(relWrong);
        
    }

    /**
     * Test to see whether the control returns the correct type Window.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 12-03-2007
     */
    public void testBarChartVisualizationController() {
        
        BCVisualizationController controller = new BCVisualizationController();
        assertEquals(BCVisualizationWindow.class, controller
                .createWindow().getClass());
    }

    /**
     * Test to see if the TypeCheck system works.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public void testTypeCheck() {
        assertTrue(m_window.isTypeSupported(m_relStrInt));
        assertTrue(m_window.isTypeSupported(m_relIntStr));
        assertFalse(m_window.isTypeSupported(m_relWrong));
    }

    /**
     * Test to see if the name for the chart is correctly found.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 12-03-2007
     */
    public void testGetChartName() {
        assertEquals("StatementHistogram", m_window.getRTupleName(m_relIntStr));
        assertEquals("TEST_BAR", m_window.getRTupleName(m_relStrInt));
    }
    
    /**
     * Test to see if RTuples are correctly converted, rel<str,int> & rel<int,str>.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 12-03-2007
     */
    public void testConvertRTupleToDataset() {
        CategoryDataset datasetIntStr = m_window.convertRTupleToDataset(m_relIntStr);
        assertEquals(4, datasetIntStr.getRowCount());
        assertTrue(datasetIntStr.getRowKeys().contains("Assignment4"));
        assertEquals(new Double(7.0), datasetIntStr.getValue(0,0));
        CategoryDataset datasetStrInt = m_window.convertRTupleToDataset(m_relStrInt);
        assertEquals(1, datasetStrInt.getRowCount());
        assertTrue(datasetStrInt.getRowKeys().contains("a"));
    }

    /**
     * See if the controller correctly advertises a supported types.
     * 
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 12-03-2007
     */
    public void testControllerSupportedTypes() {
        assertTrue(isRTypeInATermArray(m_controller.getSupportedTypes(),
                m_typeRelStrInt));
        assertTrue(isRTypeInATermArray(m_controller.getSupportedTypes(),
                m_typeRelIntStr));
        assertFalse(isRTypeInATermArray(m_controller.getSupportedTypes(),
                m_typeRelWrong));
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
     * @date 12-03-2007
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
