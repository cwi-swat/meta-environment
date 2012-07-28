package nl.cwi.sen1.visplugin.csvexport;

import junit.framework.TestCase;

/**
 * JUnit Testcase used to test the TableVisualizationWindow class
 * 
 * @author Antoine Savelkoul
 * @date 09-03-2007
 */
public class CsvExportVisualizationWindowTest extends TestCase {

    private CsvExportVisualizationWindow m_csvExportVisualizationWindow;
    
    /**
     * Fixture setup.
     * @author  Antoine Savelkoul
     * @date    08-03-2007
     */
    protected void setUp() throws Exception { 
    	m_csvExportVisualizationWindow = new CsvExportVisualizationWindow();
    }
    
    /**
     * Tests if the window is created.
     * @author  Antoine Savelkoul
     * @date    08-03-2007
     */
    public void testCsvExportVisualizationWindow() {
    	assertNotNull(m_csvExportVisualizationWindow);
    }
}
