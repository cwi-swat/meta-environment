package nl.cwi.sen1.visplugin.table.model;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RElemElements;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;

/**
 * JUnit Testcase used to test the TableVisualizationWindow class.
 *
 * @author Antoine Savelkoul
 * @date 09-03-2007
 */
public class SortableTableModelTest extends TestCase {

    private SortableTableModel m_model;
    private Factory m_factory;
    private RTuple m_testRTuple;

    /**
     * Set-up code for the tests.
     *
     * @author Antoine Savelkoul
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void setUp() {
        m_model = new SortableTableModel();
        m_factory = VisualizationFactorySingleton.getFactoryInstance();

        String relStrStr = "rtuple(\"STRING_TABLE\"," + "relation([str,str]),"
                + "set(["
                + "tuple([str(\"Row 1\"),str(\"abc\")]),"
                + "tuple([str(\"Row 2\"),str(\"bcd\")]),"
                + "tuple([str(\"Row 3\"),str(\"abd\")])"
                + "]))";
        m_testRTuple = m_factory.RTupleFromString(relStrStr);
    }

    /**
     * Tests the getColumnCount() method to see if it's initialized properly by
     * setRTupleData().
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testGetColumnCount() {
        m_model.setRTupleData(m_testRTuple);
        assertEquals(2, m_model.getColumnCount());
    }

    /**
     * Tests the getColumnName() method to see if it's initialized properly by
     * setRTupleData().
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testGetColumnName() {
        m_model.setRTupleData(m_testRTuple);
        assertEquals("str [0]", m_model.getColumnName(0));
    }

    /**
     * Tests the getValueAt() method.
     *
     * @author Antoine Savelkoul
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 09-03-2007
     */
    public void testGetValueAt() {
        m_model.setRTupleData(m_testRTuple);
        assertEquals("abd", m_model.getValueAt(2, 1));
    }

    /**
     * Tests the getRTupleVariable() method.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testGetRTupleVariable() {
        m_model.setRTupleData(m_testRTuple);
        assertEquals(m_testRTuple.getVariable(), m_model.getRTupleVariable());
    }

    /**
     * Tests the getRTupleRType() method.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testGetRTupleRType() {
        m_model.setRTupleData(m_testRTuple);
        assertEquals(m_testRTuple.getRtype(), m_model.getRTupleRType());
    }

    /**
     * Tests the getRElemForRow() method.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testGetRElemForRow() {
        m_model.setRTupleData(m_testRTuple);
        RElem value = m_testRTuple.getValue();
        RElemElements elements = value.getElements();
        assertEquals(elements.getRElemAt(2), m_model.getRElemForRow(2));
    }

    /**
     *  Tests the getRElemForRow() method after sorting on second column.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testGetRElemForRowWithSorting() {
        m_model.setRTupleData(m_testRTuple);
        m_model.sortByColumn(1, true);
        RElem value = m_testRTuple.getValue();
        RElemElements elements = value.getElements();
        assertEquals(elements.getRElemAt(2), m_model.getRElemForRow(1));
    }
}
