package nl.cwi.sen1.visplugin.csvexport;

import java.awt.BorderLayout;
import java.io.IOException;

import javax.swing.JLabel;
import javax.swing.JPanel;

import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;

/**
 * This class represents the window of the CSV Export plugin in the meta environment
 * @author  Antoine Savelkoul
 * @author  Chris Woolderink
 * @date    14-03-2007
 */
public class CsvExportVisualizationWindow extends VisualizationPluginWindow {
    private RTuple m_fact; // used to store the RTuple that has to be exported
    private JLabel m_message; // used for the message that will be shown after the export is completed

    /**
     * Returns JPanel including JTable with Data.
     * @param fact the RStore to be exported
     * @return the content for the tab that will be shown in the Meta Environment
	 * @author Antoine Savelkoul
	 * @author Chris Woolderink
	 * @date   16-03-2007    
     */
    public JPanel render(RTuple fact) {
    	m_fact = fact;
    	
    	// Create and return the content for the tab that will be shown in the Meta Environment
    	JPanel controlArea = new JPanel(new BorderLayout());
    	m_message = new JLabel();
    	controlArea.add(m_message);
        return controlArea;
    }
    
    /**
     * Called when the plugin is loaded
     * @author Raymond Bergen
	 * @date   16-03-2007 
     */
	public void executeOnLoad() {
		exportToCsvClicked();
	}
	
	/**
	 * Exports the loaded RTuple to a CSV file
	 * @param fileName The name of the the CSV output will be written to
	 * @author Antoine Savelkoul
	 * @author Chris Woolderink
	 * @date   16-03-2007    
	 */
	protected void exportToCsv(String fileName){
        String message = "";
       	try {
       		Exporter.exportToFile( m_fact, fileName, Exporter.ExportSelection.DATA_ONLY);
       		message = "The RStore has been exported successfully. You can close this window.";
       	}
       	catch( IOException e ) {
           	message = "The RStore has not been succesfully exported. Error while writing file. You can close this window. ";
       	}
       	
    	m_message.setText(message);
	}
}

