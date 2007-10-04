package nl.cwi.sen1.visplugin.csvexport;

import junit.framework.TestCase;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
import aterm.ATerm;
import aterm.pure.PureFactory;

/**
 * Test class for the TableVisualization Plugin.
 * @author  Srinivasan Tharmarajah
 * @author  Wasim Alsaqaf
 * @author  Antoine Savelkoul
 * @date    07-03-2007
 */
public class CsvExportControllerTest extends TestCase {

	private CsvExportController m_tableVisualizationController;
	private PureFactory m_factory;
	
	/**
	 * Fixture setup.
	 * @author  Antoine Savelkoul
	 * @author  Chris Woolderink
	 * @date    14-03-2007
	 */
	protected void setUp() throws Exception {
		super.setUp();
			
		m_factory = VisualizationFactorySingleton.getPureFactoryInstance();
        m_tableVisualizationController = new CsvExportController();
        m_tableVisualizationController.initPluginController(m_factory);
	}

    /**
     * Tests if the TableVisualizationController has been created succesfully
     * @author  Antoine Savelkoul
	 * @author  Chris Woolderink
	 * @date    14-03-2007
     */
    public void testTableVisualizationController() {
        assertNotNull(m_tableVisualizationController);
    }        

    /**
     * Tests if a visualization window can be created.
     * @author  Antoine Savelkoul
	 * @author  Chris Woolderink
     * @date    07-03-2007
     */
    public void testCreateWindow() {
    	// Create the window
    	VisualizationPluginWindow visualizationPluginWindow;
        visualizationPluginWindow = m_tableVisualizationController.createWindow();

        // Test if the window has been created
        assertNotNull(visualizationPluginWindow);

        // Test if the window is of the right type
        assertEquals(CsvExportVisualizationWindow.class, visualizationPluginWindow.getClass());
    }

    /**
     * Tests if the right plugin name is given when requested.
     * @author Antoine Savelkoul
     * @date   07-03-2007
     */
    public void testGetPluginName() {
        assertEquals( m_tableVisualizationController.getPluginName(), "CSV Export Visualization Plugin" );
    }

    /**
     * Tests if there will no list of supported types will be given when asked. This because
     * the isTypeSupported method will be used instead.
     * @author Antoine Savelkoul
     * @date   14-03-2007
     */
	public void testGetSupportedTypes() {
        ATerm[] atermList = m_tableVisualizationController.getSupportedTypes();
        assertTrue(atermList.length == 0);
	}

    /**
     * Test for the supported types.
     * @author  Anton Lycklama
     * @author  Bas Basten
     * @date    9-3-2007
     */
    public void testIsTypeSupported() {
        ATerm resultTrue = m_factory.make("snd-value(vp-type-supported(<bool>))", new Boolean(true));
        ATerm resultFalse = m_factory.make("snd-value(vp-type-supported(<bool>))", new Boolean(false));
        
        // Should succeed
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([str])")), resultTrue);               
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([int])")), resultTrue);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([loc])")), resultTrue);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([str,str])")), resultTrue);           
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([str,int])")), resultTrue);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([loc,int])")), resultTrue);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([str,str,str])")), resultTrue);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([str,int,str])")), resultTrue);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([int,str,loc])")), resultTrue);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("set(int)")), resultTrue);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("bag(int)")), resultTrue);

        // Should fail
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("str")), resultFalse);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("loc")), resultFalse);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("int")), resultFalse);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("bool")), resultFalse);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("relation([str,relation([str])])")), resultFalse);
        assertEquals(m_tableVisualizationController.vpIsTypeSupported(makeATerm("set(relation([int,str]))")), resultFalse);
    }

    /**
     * Creates an ATerm 
     * @param type the type of ATerm to be created
     * @return the created ATerm
     */
    private ATerm makeATerm(String type) {
        return m_factory.make(type);
    }    
}


