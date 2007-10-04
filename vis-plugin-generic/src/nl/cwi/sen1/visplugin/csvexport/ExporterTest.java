package nl.cwi.sen1.visplugin.csvexport;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.nio.charset.Charset;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;

import com.csvreader.CsvWriter;


/**
 * JUnit Testcase used to test the Exporter class
 * @author Chris Woolderink
 * @author Antoine Savelkoul
 * @date 12-03-2007
 */
public class ExporterTest extends TestCase {
	
    private Factory m_factory;
	
	/**
	 * This method is executed before the start of a test
	 * @author Chris Woolderink
	 * @author Antoine Savelkoul
	 * @date 12-03-2007
	 */
	protected void setUp() throws Exception {
		super.setUp();

        m_factory = VisualizationFactorySingleton.getFactoryInstance();
	}

	/**
	 * This method is executed after the end of a test
	 * @author Chris Woolderink
	 * @author Antoine Savelkoul
	 * @date 12-03-2007
	 */
	protected void tearDown() throws Exception {
		super.tearDown();
	}

	/**
	 * Export from a RTuple with "String String"-relation 
	 */
	public void testExportFromRTupleStrStr() {
        // Setup the relation type and relation themselves.
        String relStrStr =  "rtuple(\"STRING_TABLE\"," +
        "relation([str,str])," +
        "set([" +
        "tuple([str(\"Row 1, Column 1\"),str(\"Row 1, Column 2\")])," +
        "tuple([str(\"Row 2, Column 1\"),str(\"Row 2, Column 2\")])," +
        "tuple([str(\"Row 3, Column 1\"),str(\"Row 3, Column 2\")])" +
        "]))";
        RTuple tupleRelStrStr = m_factory.RTupleFromString(relStrStr);
        
        String csvExpected =
        	"\"Row 1, Column 1\",\"Row 1, Column 2\"\n" +
        	"\"Row 2, Column 1\",\"Row 2, Column 2\"\n" +
        	"\"Row 3, Column 1\",\"Row 3, Column 2\"\n";
        
        String result = rTupleToCsv(tupleRelStrStr, Exporter.ExportSelection.DATA_ONLY);
		
        assertEquals(csvExpected, result);
	}

	/**
	 * Export from a RTuple with "String Integer"-relation 
	 */
	public void testExportFromRTupleStrInt() {
        // Setup the relation type and relation themselves.
        String relStrInt =  "rtuple(\"STRING_TABLE\"," +
        "relation([str,int])," +
        "set([" +
        "tuple([str(\"Row 1, Column 1\"),int(nat-con(1))])," +
        "tuple([str(\"Row 2, Column 1\"),int(nat-con(2))])," +
        "tuple([str(\"Row 3, Column 1\"),int(nat-con(3))])" +
        "]))";
        RTuple tupleRelStrInt = m_factory.RTupleFromString(relStrInt);
        
        String csvExpectedWithoutHeader =
        	"\"Row 1, Column 1\",1\n" +
        	"\"Row 2, Column 1\",2\n" +
        	"\"Row 3, Column 1\",3\n";

        String result1 = rTupleToCsv(tupleRelStrInt, Exporter.ExportSelection.DATA_ONLY);
        assertEquals(csvExpectedWithoutHeader, result1);
        
        String csvExpectedWithHeader =
        	"str,int\n" +
        	"\"Row 1, Column 1\",1\n" +
        	"\"Row 2, Column 1\",2\n" +
        	"\"Row 3, Column 1\",3\n";
        
        String result2 = rTupleToCsv(tupleRelStrInt, Exporter.ExportSelection.DATA_WITH_HEADERS);
        assertEquals(csvExpectedWithHeader, result2);
	}

	/**
	 * Converts a RTuple to CSV formatted text by calling:
	 * Exporter.export(rTuple, csvWriter)
	 * @param rTuple  The RTuple to export
	 * @return  a String with the CSV formatted output
	 * @author Antoine Savelkoul
 	 * @author Chris Woolderink
  	 * @date 13-03-2007
	 */
	private String rTupleToCsv(RTuple rTuple, Exporter.ExportSelection selection) {
		ByteArrayOutputStream byteArrayOutputStreamSimple = new ByteArrayOutputStream();
		CsvWriter csvWriter = new CsvWriter(byteArrayOutputStreamSimple,',',Charset.forName("UTF-8"));
		String csvOutput = null;
		
		try {
			Exporter.export(rTuple, csvWriter, selection);
			csvWriter.close();
			byteArrayOutputStreamSimple.close();
			csvOutput = byteArrayOutputStreamSimple.toString();
		}
		catch( IOException e ) {
			fail();
		}
		
		return csvOutput;
	}

}
