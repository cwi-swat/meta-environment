package nl.cwi.sen1.visplugin.table;

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
 * Test class for the TableVisualizationWindow.
 *
 * @author Arend van Beelen
 * @date 13-03-2007
 */
public class TableVisualizationWindowTest extends TestCase {

    private static String m_testFilename = "test_export_from_window.rstore";

    private Factory m_factory;
    private RTuple m_testRTuple;

    private TableVisualizationWindow m_window;

    /**
     * Set-up code for the unit tests.
     *
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

        m_window = new TableVisualizationWindow();
    }

    /**
     * Tests the exportToRStore() method.
     * Cannot be tested due to the studioComponent in exportToRstore.
     *
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void testExportToRStore() {
        m_window.render(m_testRTuple);

        m_window.exportToRStore(m_testFilename);

        String contents = readFile(m_testFilename);

        RStore rStore = m_factory.RStoreFromString(contents);
        assertEquals(m_testRTuple, rStore.getRtuples().getRTupleAt(0));
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
            
        } catch (IOException exception) {
        	System.err.println("Unable to read from file with name: "+filename);
        }finally{
        	if(in != null){
        		try{
        			in.close();
        		}catch(IOException ioex){
        			System.err.println("A fatal error occured: Unable to close reader.");
        		}
        	}
        }
        
        return stringBuilder.toString();
    }
}
