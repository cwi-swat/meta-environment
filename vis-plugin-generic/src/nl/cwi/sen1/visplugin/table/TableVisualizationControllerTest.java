package nl.cwi.sen1.visplugin.table;

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
public class TableVisualizationControllerTest extends TestCase {

    private TableVisualizationController m_tableVisualizationController;

    static final String m_fileName = "graph.rstore";

    /**
     * Fixture setup.
     * @author  Srinivasan Tharmarajah
     * @author  Wasim Alsaqaf
     * @date    20-2-2007
     */
    protected void setUp() throws Exception {
        super.setUp();

        m_tableVisualizationController = new TableVisualizationController();
        PureFactory pureFactory = VisualizationFactorySingleton.getPureFactoryInstance();
        m_tableVisualizationController.initPluginController(pureFactory);
    }

    /**
     * Tests if the TableVisualizationController can be created succesfully
     *
     * @author Antoine Savelkoul
     * @author Srinivasan Tharmarajah
     * @author Wasim Alsaqaf
     * @date   07-03-2007
     */
    public void testTableVisualizationController() {
        TableVisualizationController tableVisualizationController = new TableVisualizationController();
        assertNotNull(tableVisualizationController);
    }

    /**
     * Tests if a visualization window can be created.
     *
     * @author Antoine Savelkoul
     * @author Srinivasan Tharmarajah
     * @author Wasim Alsaqaf
     * @date 07-03-2007
     */
    public void testCreateWindow() {
        VisualizationPluginWindow visualizationPluginWindow;
        visualizationPluginWindow = m_tableVisualizationController.createWindow();
        // Tests if the window can be created
        assertNotNull(visualizationPluginWindow);
        // Tests if the window is of the right type
        assertEquals(TableVisualizationWindow.class, visualizationPluginWindow.getClass());
    }

    /**
     * Tests if the right plugin name is given when requested.
     *
     * @author Antoine Savelkoul
     * @date 07-03-2007
     */
    public void testGetPluginName() {
        assertEquals( m_tableVisualizationController.getPluginName(), "Table Visualization Plugin" );
    }

    /**
     * Test for the supported types.
     *
     * @author  Anton Lycklama
     * @author  Bas Basten
     * @date    9-3-2007
     */
    public void testIsTypeSupported() {
        PureFactory pureFactory = VisualizationFactorySingleton.getPureFactoryInstance();
        ATerm resultTrue = pureFactory.make("snd-value(vp-type-supported(<bool>))", new Boolean(true));
        ATerm resultFalse = pureFactory.make("snd-value(vp-type-supported(<bool>))", new Boolean(false));

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

    private ATerm makeATerm(String type) {
        PureFactory factory = VisualizationFactorySingleton.getPureFactoryInstance();
        return factory.make(type);
        // return m_factory.RTypeFromString(type);
    }
}


