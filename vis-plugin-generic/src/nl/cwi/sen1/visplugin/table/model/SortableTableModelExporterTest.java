package nl.cwi.sen1.visplugin.table.model;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RStore;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;

/**
 * Tests the SortableTableModelExporter class.
 *
 * @author Anton Gerdessen
 * @author Arend van Beelen
 * @date 13-03-2007
 */
public class SortableTableModelExporterTest extends TestCase {

    private static String m_testFilename = "test_export.rstore";

    private Factory m_factory;
    private RTuple m_testRTuple;
    private RTuple m_testRTupleSelection;

    private SortableTableModel m_model;
    private SortableTableModelExporter m_exporter;

    /**
     * Set-up code for the unit tests.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void setUp() {
        // clean up any previous occurences of the test file
        (new File(m_testFilename)).delete();

        m_factory = VisualizationFactorySingleton.getFactoryInstance();

        String relStrStr = "rtuple(\"STRING_TABLE\"," + "relation([str,str]),"
                + "set(["
                + "tuple([str(\"Row 1\"),str(\"abc\")]),"
                + "tuple([str(\"Row 2\"),str(\"bcd\")]),"
                + "tuple([str(\"Row 3\"),str(\"abd\")])"
                + "]))";
        m_testRTuple = m_factory.RTupleFromString(relStrStr);

        relStrStr = "rtuple(\"STRING_TABLE\"," + "relation([str,str]),"
                + "set(["
                + "tuple([str(\"Row 1\"),str(\"abc\")]),"
                + "tuple([str(\"Row 3\"),str(\"abd\")])"
                + "]))";
        m_testRTupleSelection = m_factory.RTupleFromString(relStrStr);

        m_model = new SortableTableModel();
        m_model.setRTupleData(m_testRTuple);
        m_exporter = new SortableTableModelExporter(m_model);
    }

    /**
     * Tests the exportToRStore() function while exporting the entire table.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testExportToRStoreEntireTable() {
        int[] selectedRows = {};
        m_exporter.exportToRStore(m_testFilename, selectedRows);

        String contents = readFile(m_testFilename);

        RStore rStore = m_factory.RStoreFromString(contents);
        assertEquals(m_testRTuple, rStore.getRtuples().getRTupleAt(0));
    }

    /**
     * Tests the exportToRStore() function while exporting only the first and
     * third row.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testExportToRStoreTableSelection() {
        int[] selectedRows = {0, 2};
        m_exporter.exportToRStore(m_testFilename, selectedRows);

        String contents = readFile(m_testFilename);

        RStore rStore = m_factory.RStoreFromString(contents);
        assertEquals(m_testRTupleSelection, rStore.getRtuples().getRTupleAt(0));
    }

    /**
     * Reads an entire file and returns the contents as a string.
     *
     * @param filename Filename of the file to read.
     * @return A string containing the file contents.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    private String readFile(String filename) {
        StringBuilder stringBuilder = new StringBuilder();
        BufferedReader in = null;
        try {
            in = new BufferedReader(new FileReader(filename));
            String line;
            while ((line = in.readLine()) != null) {
                stringBuilder.append(line);
            }
            in.close();
        } catch (IOException exception) {
        	System.err.println("Unable to read from file with name: "+filename);
        }finally{
        	if(in != null){
        		try{
        			in.close();
        		}catch(IOException ioex){
        			System.err.println("A fatal error occured: Unable to close stream.");
        		}
        	}
        }
        return stringBuilder.toString();
    }
}
