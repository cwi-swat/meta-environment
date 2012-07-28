package nl.cwi.sen1.visplugin.csvexport;

import java.io.IOException;
import java.nio.charset.Charset;

import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RElemElements;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.RTypeColumnTypes;

import com.csvreader.CsvWriter;

/**
 * CSV export functionality for RTuples
 * @author Chris Woolderink
 * @author Antoine Savelkoul
 */
public class Exporter {

	/**
	 * Enumeration used to indicate which part of a RTuple should be exported to CSV
	 * @author Antoine Savelkoul
 	 * @author Chris Woolderink
 	 * @date 14-03-2007
	 */
	public enum ExportSelection {
		DATA_ONLY,
		DATA_WITH_HEADERS
	}
	
	/**
	 * Writes the content of a RTuple to an CSV formatted file 
	 * @param rTuple the RTuple to be exported
	 * @param fileName the name of the output file
	 * @param selection indicates which information has to be exported
	 * @author Antoine Savelkoul
 	 * @author Chris Woolderink
 	 * @date 13-03-2007
	 */
	public static void exportToFile(RTuple rTuple, String fileName, ExportSelection selection) throws IOException {
		CsvWriter csvWriter = new CsvWriter(fileName,',',Charset.forName("UTF-8"));
		export(rTuple, csvWriter, selection);
		csvWriter.close();
	}
	
	/**
	 * Writes the content of a RTupe to a CSV writer 
	 * @param rTuple the RTuple to be exported
	 * @param csvWriter the CSV writer to produce the output
	 * @param selection indicates which information has to be exported
	 * @author Antoine Savelkoul
 	 * @author Chris Woolderink
 	 * @date 13-03-2007
	 */
	public static void export(RTuple rTuple, CsvWriter csvWriter, ExportSelection selection) throws IOException {
        RType rType = rTuple.getRtype();
        RTypeColumnTypes columnTypes = rType.getColumnTypes();

        if( selection == ExportSelection.DATA_WITH_HEADERS ) {
        	exportColumnTypes(columnTypes, csvWriter);
        }
        exportData(rTuple, csvWriter);
	}
	
	/**
	 * Writes the data of an rTuple to the CvsWriter
	 * @param rTuple the RTuple to be exported
	 * @param csvWriter the CSV writer to produce the output
	 * @author Antoine Savelkoul
 	 * @author Chris Woolderink
 	 * @date 13-03-2007
	 */
    private static void exportData( RTuple rTuple, CsvWriter csvWriter ) throws IOException {
        RElem value = rTuple.getValue();
        RElemElements valueElements = value.getElements();

        RType rType = rTuple.getRtype();
        RTypeColumnTypes columnTypes = rType.getColumnTypes();

        int columnCount = columnTypes.getLength();
        int rowCount = valueElements.getLength();
		String[] rowData = new String[columnCount];

        for(int row = 0; row < rowCount; row++) {

            RElem tuple = valueElements.getRElemAt(row);
            RElemElements tupleElements = tuple.getElements();

            for(int column = 0; column < columnCount; column++) {
				// Read all cells from the row
                RElem elem = tupleElements.getRElemAt(column);
				rowData[column] = RElemToString(elem);
            }
			// Write the row to the output stream
            csvWriter.writeRecord(rowData);
        }
    }

    /**
 	 * Writes the data types as headers to the CvsWriter
     * @param columnTypes column types information that will be used as headers
	 * @param writer The CSV writer to produce the output
	 * @author Antoine Savelkoul
 	 * @author Chris Woolderink
 	 * @date 13-03-2007
     */
    private static void exportColumnTypes( RTypeColumnTypes columnTypes, CsvWriter writer ) throws IOException {
        int numColumns = columnTypes.getLength();
        String[] columnNames = new String[numColumns];
        
        // Copies each of the type names to the array
        for(int columnNum = 0; columnNum < numColumns; columnNum++) {
            RType columnType = columnTypes.getRTypeAt(columnNum);
            columnNames[columnNum] = columnType.toString();
        }
        writer.writeRecord( columnNames );
    }
    
    /**
     * Converts the value of a simple RElem to a String
     * @param elem the RElem to be converted
     * @return the converted RElem
	 * @author Antoine Savelkoul
 	 * @author Chris Woolderink
 	 * @date 13-03-2007
     */
    private static String RElemToString(RElem elem) {
    	
    	if( elem.isStr() ) {
    		return elem.getStrCon();
    	}
    	
    	if( elem.isInt() ) {
    		return Integer.toString( elem.getInteger().getNatCon() );
    	}
    	
    	if( elem.isBool() ) {
    		return elem.getBoolCon().toString();
    	}
    		
    	if( elem.isLoc() ) {
    		return elem.getLocation().toString();
    	}
    	
    	return elem.toString();
    }
}
